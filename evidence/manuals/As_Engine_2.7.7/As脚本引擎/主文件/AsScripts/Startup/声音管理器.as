/**
音频管理器

不要删除此文件
**/

class ChatVoiceInfo{
    string trackName;
    int charId;
    string chatText;
    string filename;
} 

class BindingSoundInfo{
    string objectType;
    int objectId = -1;

    bool IsValid(){
        return objectId >= 0;
    }
}

bool IsWaveValid(int waveId){
    return waveId > 0;
}

class SoundTrack{
    int waveId;
    bool is3D;
    BindingSoundInfo bindingInfo;

    void Init(){
        waveId = WaveNew(is3D);
    }

    void Deinit(){
        if (!IsWaveValid(waveId)){
            return;
        }
        WaveDelete(waveId);
    }
}

class SoundMgr{
    private SoundTrack[] _tracks;
    private ChatVoiceInfo[] _chatVoiceInfoList;
    private int _numGlobalTracks;
    private int _num3DTracks;

    SoundMgr(int numGlobalTracks, int num3DTracks){
        _numGlobalTracks = Max(0, numGlobalTracks);
        _num3DTracks = Max(0, num3DTracks);
        int totalTracks = _numGlobalTracks + _num3DTracks;
        // create tracks
        _tracks = SoundTrack[](totalTracks);
        int iTrack = 0;
        for (;iTrack < _numGlobalTracks; iTrack++){
            bool is3D = false;
            auto@ track = _tracks[iTrack];
            track.is3D = is3D;
        }
        for (;iTrack < totalTracks; iTrack++){
            bool is3D = true;
            auto@ track = _tracks[iTrack];
            track.is3D = is3D;
        }
        for (iTrack = 0; iTrack < int(_tracks.GetSize()); iTrack++){
            _tracks[iTrack].Init();
        }
    }

    bool Load(string trackName, string filename){
        int trackId = GetTrackId(trackName);
        if (!CheckTrackId(trackId)){
            return false;
        }
        int waveId = _tracks[trackId].waveId;
        if (!IsWaveValid(waveId)){
            return false;
        }
        WaveStop(waveId);
        bool result = WaveLoad(waveId, filename);
        if (!result){
            PrintSystemText("无法读取文件 " + filename);
            Print("无法读取文件 " + filename);
        }
        return result;
    }

    void Play(string trackName, bool isLoop = false){
        int trackId = GetTrackId(trackName);
        if (!CheckTrackId(trackId)){
            return;
        }
        int waveId = _tracks[trackId].waveId;
        if (!IsWaveValid(waveId)){
            return;
        }
        WavePlay(waveId, isLoop);

    }

    void PlayOnChat(string trackName, int charId, string chatText, string filename){
        int trackId = GetTrackId(trackName);
        if (!CheckTrackId(trackId)){
            return;
        }
        int waveId = _tracks[trackId].waveId;
        if (!IsWaveValid(waveId)){
            return;
        }

        ChatVoiceInfo info;
        info.trackName = trackName;
        info.charId = charId;
        info.chatText = chatText;
        info.filename = filename;
        _chatVoiceInfoList.Push(info);
    }

    void Stop(string trackName){
        int trackId = GetTrackId(trackName);
        if (!CheckTrackId(trackId)){
            return;
        }
        int waveId = _tracks[trackId].waveId;
        if (!IsWaveValid(waveId)){
            return;
        }
        WaveStop(waveId);
    }

    void SetPosition(string trackName, Vector3 position){
        int trackId = GetTrackId(trackName);
        if (!CheckTrackId(trackId)){
            return;
        }
        auto@ track = _tracks[trackId];
        if (!track.is3D){
            return;
        }
        int waveId = _tracks[trackId].waveId;
        if (!IsWaveValid(waveId)){
            return;
        }

        WaveSetPosition(waveId, position);
    }

    bool BindObject(string trackName, const string&in objectType, int objectId){
        int trackId = GetTrackId(trackName);
        if (!CheckTrackId(trackId)){
            return false;
        }
        auto@ track = _tracks[trackId];
        if (!track.is3D){
            return false;
        }
        BindingSoundInfo@ binding = track.bindingInfo;
        binding.objectType = objectType;
        binding.objectId = objectId;
        return true;
    }

    void UnBindObject(string trackName){
        int trackId = GetTrackId(trackName);
        if (!CheckTrackId(trackId)){
            return;
        }
        auto@ track = _tracks[trackId];
        track.bindingInfo = BindingSoundInfo();
    }

    void Update(){
        // 刷新频道位置
        for (uint iTrack = 0; iTrack < _tracks.GetSize(); iTrack++){
            auto@ track = _tracks[iTrack];
            BindingSoundInfo@ binding = track.bindingInfo;
            if (@binding == null){
                continue;
            }

            if (SetTarget(1, binding.objectType, binding.objectId)){
                Vector3 position = GetPosition(1);
                WaveSetPosition(track.waveId, position);
            }
            else{
                // reset
                track.bindingInfo = BindingSoundInfo();
            }
        }
    }

    // 根据轨道名称获得轨道ID
    private int GetTrackId(string trackName){
        if (trackName.Length() < 2){
            PrintSystemText("无效的音轨名称 " + trackName);
            return -1;
        }
        if (trackName[0] == 'a'){
            return trackName.Substring(1).ToInt();
        }
        else if (trackName[0] == 'b'){
            return _numGlobalTracks + trackName.Substring(1).ToInt();
        }
        else{
            return -1;
        }
    }
 
    void Close(){
        for (uint iTrack = 0; iTrack < _tracks.GetSize(); iTrack++){
            _tracks[iTrack].Deinit();
        }
        _tracks.Clear();
        _chatVoiceInfoList.Clear();
    }

    private bool CheckTrackId(int trackId){
        if ((trackId < 0) || (uint(trackId) >= _tracks.GetSize())){
            Print("invalid trackId " + trackId);
            return false;
        }
        return true;
    }

    // 处理聊天信息，如果出现匹配的语句，就播放相应的语音文件
    void HandleChat(const string&in text, bool isTeam){
        int nameEnd = text.Find(" :");
        string name = text.Substring(0, nameEnd);
        string chatText = text.Substring(nameEnd+2);
        int charId = GetAnyChar(name);
        if (charId == -1){
            charId = GetChar("player");
        }
        
        // 倒序搜索
        int iInfo = _chatVoiceInfoList.GetSize()-1;
        for (; iInfo >= 0; iInfo--){
            ChatVoiceInfo@ info = _chatVoiceInfoList[iInfo];
            if (info.charId != charId){
                continue;
            }
            if (info.chatText != chatText){
                continue;
            }
            break;
        }

        if (iInfo < 0){
            return;
        }
        ChatVoiceInfo@ infoFound = _chatVoiceInfoList[iInfo];
        Load(infoFound.trackName, infoFound.filename);
        Play(infoFound.trackName, false);
        // 清除
        _chatVoiceInfoList.Erase(iInfo);
    }

    
}


/*********************************/
// 全局变量
SoundMgr@ g_soundMgr;
int[] g_cachedWaveList;

void GlobalHandleChat(const string&in text, bool isTeam){
    if (@g_soundMgr != null){
        g_soundMgr.HandleChat(text, isTeam);
    }
}

void OnStart(){
    AddChatCallback(GlobalHandleChat);
}

void Level_OnStart(){
    int numGlobalTracks = 100;
    int num3DTracks = 100;
    @g_soundMgr = SoundMgr(numGlobalTracks, num3DTracks);
} 

void Level_OnStop(){
    g_soundMgr.Close();
    @g_soundMgr = null;
    // 清理声音缓存
    ClearSoundCache(); 
}

void Level_OnUpdate(){
    if (@g_soundMgr == null) return;
    g_soundMgr.Update();
}

bool SoundLoad(string trackName, string filename){
    if (@g_soundMgr == null) return false;
    return g_soundMgr.Load(trackName, filename);
}

void SoundPlay(string trackName, int isLoop){
    if (@g_soundMgr == null) return;
    g_soundMgr.Play(trackName, bool(isLoop));

}

void SoundPlayOnChat(string trackName, int charId, string chatText, string filename){
    if (@g_soundMgr == null) return;
    g_soundMgr.PlayOnChat(trackName, charId, chatText, filename);
}

void SoundStop(string trackName){
    if (@g_soundMgr == null) return;
    g_soundMgr.Stop(trackName);
}

void SoundSetPosition(string trackName, int x, int y, int z){
    if (@g_soundMgr == null) return;
    g_soundMgr.SetPosition(trackName, Vector3(x/100.0f,y/100.0f,z/100.0f));
}

void SoundBindObject(string trackName, string objectType, int objectId){
    if (@g_soundMgr == null) return;
    if (!g_soundMgr.BindObject(trackName, objectType, objectId)){
        PrintSystemText("绑定音轨到 " + trackName + " " + objectType + " " + objectId + " 失败");
    }
}

void SoundUnBindObject(string trackName){
    if (@g_soundMgr == null) return;
    g_soundMgr.UnBindObject(trackName);
}

void SoundCacheFolder(string folderName){
    string[]@ filenameList = ScanDir(folderName, "*.wav", SCAN_FILES, true);
    for (uint i = 0; i < filenameList.GetSize(); i++){
        string filename = filenameList[i];
        bool is3D = false;
        int waveId = WaveNew(is3D);
        auto fullName = folderName + "/" + filename;
        if (!WaveLoad(waveId, fullName)){
            Print("无法缓存 "+ fullName);
        }
        else{
            g_cachedWaveList.Push(waveId);
        }
    }
}

void ClearSoundCache(){
    for (uint iWave = 0; iWave <  g_cachedWaveList.GetSize(); iWave++){
        WaveDelete(g_cachedWaveList[iWave]);
    }
    g_cachedWaveList.Clear();
}
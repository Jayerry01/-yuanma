#include "ActionQueue.as"
#include "AsSprite.as"

const int g_AsMagicNumberForSave = 10001;
const uint g_AsMaxNumSaveStates = 1000;

ActionQueue[] g_actionQueueList(200);
uint g_currentRunningActionQueueId = uint(-1);

dictionary g_cacheImageDict;

class _AttackInfo{
    int charId;
    string keySeries;
    void Do(){
        CharAttackImm(charId, keySeries);
    }
}

class _JumpInfo{
    int charId;
    void Do(){
        CharJumpImm(charId);
    }
}

/*
判断是否按下一次某个按键
参数:
    keyCode: 键位字符，可以在AsScripts/Api.h里找到标识符，ImGuiKey开头的都是
用法： 
    if (AsIsKeyPressed(ImGuiKey_5) || AsIsKeyPressed(ImGuiKey_Keypad5)){ // 判断是否按下了大键盘数字5或小键盘数字5
        // 在这里填写要做的操作
    }
    if (AsIsKeyPressed(ImGuiKey_F9)){ // 判断是否按下了F9
        // 在这里填写要做的操作
    }
*/
bool AsIsKeyPressed(int keyCode){
    return ImGui_IsKeyPressed(keyCode, false);
}

/*
判断是否一直按住某个按键
*/
bool AsIsKeyDown(int keyCode){
    return ImGui_IsKeyDown(keyCode);
}

/*
判断是否按下一次鼠标键
0 左键
1 右键
2 中建
*/
bool AsIsMouseClicked(int key){
    return ImGui_IsMouseClicked(key, false);
}

/*
判断是否一直按住鼠标键
0 左键
1 右键
2 中建
*/
bool AsIsMouseDown(int key){
    return ImGui_IsMouseDown(key);
}

/*
切换武器
参数：
    weaponId: 武器ID
用法：
将当前武器切换到武器8
AsSwitchWeapon(8);
*/
void AsSwitchWeapon(int weaponId){
    // 先后切换武器三次，使得正常显示武器小图标
    Command("switch");
    // 执行weapon命令
    Command("weapon", weaponId);
    // 再切换两次武器
    Command("switch");
    Command("switch");
}

/*
玩家做出指定Pose
参数：
    poseId: Pose ID
用法：
AsPlayerPose(300)
*/
void AsPlayerPose(int poseId){
    Command("pose", poseId);
}

/*
玩家瞬移到指定位置
参数：
    x: 坐标X
    y: 坐标Y
    z: 坐标Z
用法：
将玩家移动到 500 600 400
AsMoveTo(500, 600, 400);
*/
void AsMoveTo(float x, float y, float z){
    Command("moveto", x, y, z);
}

bool AsMoveToChar(int charId){
    int targetCharId = charId;
    int targetIndex = 0;
    if (SetTarget(targetIndex, "char", targetCharId)){
        auto pos = GetPosition(targetIndex);
        Command("moveto", pos.x, pos.y, pos.z);
        return true;
    }
    else{
        return false;
    }
}

/*
玩家瞬移到指定路点
*/
bool AsMoveToWayPoint(int waypointId){
    int targetIndex = 0;
    if (SetTarget(targetIndex, "waypoint", waypointId)){
        auto pos = GetPosition(targetIndex);
        Command("moveto", pos.x, pos.y, pos.z);
        return true;
    }
    else{
        return false;
    }
}

/*
玩家瞬移到指定镖物
*/
bool AsMoveToFlag(int flagId){
    int targetIndex = 0;
    if (SetTarget(targetIndex, "flag", flagId)){
        auto pos = GetPosition(targetIndex);
        Command("moveto", pos.x, pos.y, pos.z);
        return true;
    }
    else{
        return false;
    }
}

/*
玩家瞬移到指定门
*/
bool AsMoveToDoor(int doorId){
    int targetIndex = 0;
    if (SetTarget(targetIndex, "door", doorId)){
        auto pos = GetPosition(targetIndex);
        Command("moveto", pos.x, pos.y, pos.z);
        return true;
    }
    else{
        return false;
    }
}

/*
玩家瞬移到指定出口
*/
bool AsMoveToSafe(int safeId){
    int targetIndex = 0;
    if (SetTarget(targetIndex, "safe", safeId)){
        auto pos = GetPosition(targetIndex);
        Command("moveto", pos.x, pos.y, pos.z);
        return true;
    }
    else{
        return false;
    }
}

/*
切换玩家皮肤
用法 SwitchPlayerSkin("p12");
*/
void AsSwitchPlayerSkin(string skinName){
    // 因为loadmych这个命令会使得角色归位，
    // 所以这里先记下当前位置，在切换皮肤之后瞬移到之前的位置
    int targetIndex = 0;
    int playerId = GetChar("player");
    Vector3 pos;
    if (SetTarget(targetIndex, "char", playerId)){
        pos = GetPosition(targetIndex);
    }
    Command("loadmych", skinName, playerId);
    // 瞬移到之前的位置
    Command("moveto", pos.x, pos.y, pos.z);
    // 重新选择相同的武器，使得正确显示手上的武器
    int weaponId = GetWeapon(playerId);
    Command("weapon", weaponId);
}


/*
存档
参数：
    name: 文件名
    stats: 要保存的状态
    encrypt: 是否加密
用法：
将 支线id、通关时间 这2个状态保存到文件 UserData/Saves/关卡6.sav
int pathId = 5; // 支线ID
int finishTime = GetGameTime(); // 通关时间
int numStats = 500; // 最大状态数量
int[] stats(numStats);
stats[0] = pathId;
stats[1] = finishTime;
string name = "关卡6";
bool encrypt = false; // 不加密，如果要加密则改成 true
if (AsSaveStats(name, stats, encrypt)){
    Say(1, "保存成功, 文件路径为 UserData/Saves/关卡6.sav");
}
else{
    Say(1, "保存失败");
}

*/
bool AsSaveStats(string name, int[] stats, bool encrypt = false) {
    string filename = "UserData/Saves/" + name + ".sav";
    File file;
    uint numStatesToWrite = Min(stats.GetSize(), g_AsMaxNumSaveStates);
    if (file.Open(filename, FILE_WRITE)){
        if (!encrypt){
            for (uint i = 0; i < numStatesToWrite; i++){
                file.WriteLine(stats[i]);
            }
        }
        else{
            file.WriteUInt(g_AsMagicNumberForSave);
            file.WriteUInt(numStatesToWrite);
            for (uint i = 0; i < numStatesToWrite; i++){
                int transform = (~stats[i]) + i + g_AsMagicNumberForSave;
                file.WriteInt(transform);
            }
        }
        return true;
    }
    else{
        return false;
    }
}

/*
存档
参数：
    name: 文件名
    encrypt: 该文件是否被加密
    stats: 从文件读取出来的状态
用法：
将 支线id、通关时间 这2个状态从文件 UserData/Saves/关卡6.sav 里 读取出来

int[] stats;
string name = "关卡6";
bool encrypt = false; // 指示该存档是否被加密，如果被加密，则改成 true
if (AsLoadStats(name, encrypt, stats)){
    int pathId = stats[0]; // 支线ID
    int finishTime = stats[1]; // 通关时间
    Say(1, "读取成功 " + pathId + " " + finishTime);
}
else{
    Say(1, "读取失败");
}

*/
bool AsLoadStats(string name, bool encrypt, int[]&inout outStats){
    outStats.Clear();
    outStats.Resize(g_AsMaxNumSaveStates);
    string filename = "UserData/Saves/" + name + ".sav";
    File file;
    if (!file.Open(filename, FILE_READ)) {
        return false;
    }
    
    uint numStats = 0;
    if (encrypt){
        int tag = file.ReadInt();
        if (tag != g_AsMagicNumberForSave) {
            return false;
        }
        numStats = file.ReadUInt();
        numStats = Min(numStats, g_AsMaxNumSaveStates);
    }
   
    int i = 0;
    while(!file.eof) {
        if (encrypt){
            if (numStats > 0){
                int number = file.ReadInt();
                int transform = ~(number - i - g_AsMagicNumberForSave);
                int stat = transform;
                outStats[i] = stat;
                numStats -= 1;
            }
        }
        else{
            int number = file.ReadLine().ToInt();
            outStats[i] = number;
        }
        i += 1;
    }

    return true;
}


/*
NPC模拟搓招
存档
参数：
    charId: Npc Id
    dirKeySequence: 按键序列
用法：
f 前
b 后
l 左
r 右
n 单A
. 停顿0.5秒
如果2号NPC拿着长枪，就做出长枪三连
if (GetWeaponType(2) == 7){
    ChangeBehavior(2, "idle");
    // 前A，停顿1秒，前前A，停顿1.5秒，后后前A
    AsNpcAttack(2, "f..ff...bbf");
}

*/
void AsNpcAttack(int charId, string dirKeySequence){
    string[] groups;
    string temp;
    for (uint i = 0; i < dirKeySequence.Length(); i++){
        uint8 c = dirKeySequence[i];
        if (c == '.'){
            if (temp.Length() > 0){
                groups.Push(temp);
                temp = "";
            }
            groups.Push(".");
        }
        else{
            temp += " ";
            temp.ReplaceUTF8(temp.Length()-1, c);
        }
    }
    if (temp.Length() > 0){
        groups.Push(temp);
        temp = "";
    }
    for (int i = groups.GetSize()-1; i >= 0; i--){
        string group = groups[i];
        if (group == "."){
            Perform(charId);
        }
        else{
            for (uint j = 0; j < group.Length(); j++){
                if (group.Contains('n')){
                    group = "";
                    break;
                }
            }
            CharAttack(charId, group);
        }
    }
}

/*
角色模拟搓招
存档
参数：
    charId: Npc Id
    dirKeySequence: 按键序列
用法：
f 前
b 后
l 左
r 右
n 单A
j 跳
, 停顿0.2秒
. 停顿0.5秒
如果2号NPC拿着长枪，就做出长枪三连
if (GetWeaponType(2) == 7){
    ChangeBehavior(2, "idle");
    // 前A，停顿1秒，前前A，停顿1.5秒，后后前A
    AsCharAttack(2, "f..ff...bbf");
}

*/
void AsCharAttack(int charId, string dirKeySequence){
    int scriptId = GetLevelScriptId();
    ExecuteFunction(scriptId, "AsCharAttack_Internal", charId, dirKeySequence);
}

void AsCharAttack_Internal(int charId, string dirKeySequence){
    string[] groups;
    string temp;
    for (uint i = 0; i < dirKeySequence.Length(); i++){
        uint8 c = dirKeySequence[i];
        if (c == '.'){
            if (temp.Length() > 0){
                groups.Push(temp);
                temp = "";
            }
            groups.Push(".");
        }
        else if (c == ','){
            if (temp.Length() > 0){
                groups.Push(temp);
                temp = "";
            }
            groups.Push(",");
        }
        else if (c == 'j'){
            if (temp.Length() > 0){
                groups.Push(temp);
                temp = "";
            }
            groups.Push("j");
        }
        else{
            temp += " ";
            temp.ReplaceUTF8(temp.Length()-1, c);
        }
    }
    if (temp.Length() > 0){
        groups.Push(temp);
        temp = "";
    }
    uint groups_size = groups.GetSize();
    for (uint i = 0; i < groups_size; i++){
        string group = groups[i];
        if (group == "."){
            AsActionQueuePushWait(charId, 0.5);
        }
        else if (group == ","){
            AsActionQueuePushWait(charId, 0.2);
        }
        else if (group == "j"){
            // 由于匿名函数无法使用闭包，所以这里用委托代替
            _JumpInfo info;
            info.charId = charId;
            AsActionQueuePushFunc(charId, ActionFunc(info.Do), M_EPSILON);
        }
        else{
            for (uint j = 0; j < group.Length(); j++){
                if (group.Contains('n')){
                    group = "";
                    break;
                }
            }
            // 由于匿名函数无法使用闭包，所以这里用委托代替
            _AttackInfo info;
            info.charId = charId;
            info.keySeries = group;
            AsActionQueuePushFunc(charId, ActionFunc(info.Do), M_EPSILON);
        }
    }
}

/************************/
// 音频管理器 相关
string g_soundStartupScriptName = "声音管理器";

// 将wav文件载入到指定音轨
void AsSoundLoad(string trackName, string filename){
    ExecuteFunction(g_soundStartupScriptName, "SoundLoad", trackName, filename);
}

// 播放指定音轨，还可以设定是否循环播放
void AsSoundPlay(string trackName, bool isLoop = false){
    ExecuteFunction(g_soundStartupScriptName, "SoundPlay", trackName, isLoop?1:0);
}

// 将wav文件载入到指定音轨，并播放指定音轨，还可以设定是否循环播放
void AsSoundPlay(string trackName, string filename, bool isLoop = false){
    ExecuteFunction(g_soundStartupScriptName, "SoundLoad", trackName, filename);
    ExecuteFunction(g_soundStartupScriptName, "SoundPlay", trackName, isLoop?1:0);
}

void AsSoundPlayOnChat(string trackName, int charId, string chatText, string filename){
    ExecuteFunction(g_soundStartupScriptName, "SoundPlayOnChat", trackName, charId, chatText, filename);
}

// 停止播放指定音轨
void AsSoundStop(string trackName){
    ExecuteFunction(g_soundStartupScriptName, "SoundStop", trackName);
}

// 将音轨放置到特定位置XYZ
void AsSoundSetPosition(string trackName, float x, float y, float z){
    ExecuteFunction(g_soundStartupScriptName, "SoundSetPosition", int(x*100), int(y*100), int(z*100));
}

// 将音轨绑定到特定对象，并跟随对象
void AsSoundBindObject(string trackName, const string&in objectType, int objectId){
    ExecuteFunction(g_soundStartupScriptName, "SoundBindObject", trackName, objectType, objectId);
}

// 解绑音轨
void AsSoundUnBindObject(string trackName){
    ExecuteFunction(g_soundStartupScriptName, "SoundUnBindObject", trackName);
}

// 将指定文件夹内的所有wav文件缓存到内存，可以避免之后由于临时读取而导致卡顿的现象
void AsSoundCacheFolder(string folerName){
    ExecuteFunction(g_soundStartupScriptName, "SoundCacheFolder", folerName);
}

/******************/
// Perform, PlayerPeform, Say 的替代函数

// 设定对话语音文件夹
void AsSetChatVoiceFolder(string folderName){
    string key = "chatVoiceFolder";
    SetSharedVarString(key, folderName);
}

// 获得对话语音完整文件名
string _AsBuildVoiceFilename(string charName, string chatText){
    string chatVoiceFolder = GetSharedVarString("chatVoiceFolder");
	return chatVoiceFolder + "/" + charName + "/" + chatText + ".wav";
}

// 代替 Perform
void AsPerform(int charId, string action){
	Perform(charId, action);
}

// 代替 Perform
void AsPerform(int charId, string action, int arg){
	Perform(charId, action, arg);
}

// 代替 Perform
// 如果action为say，则根据提供的对话查找对应的语音文件，并在对话显示出屏幕的时候播放语音。
// 如果arg2为文件名，则用此文件名取代自动搜索的文件名
void AsPerform(int charId, string action, string arg1, string arg2 = ""){
	if (action != "say"){
		AsPerform(charId, action, arg1);
	}
	else {
		string chatText = arg1;
		bool usePerform = true;
        string filenameSpecified = arg2;
		AsSayInternal(charId, chatText, usePerform, arg2);
	}
}

// 代替 PlayerPerform
void AsPlayerPerform(string action){
	PlayerPerform(action);
}

// 代替 PlayerPerform
void AsPlayerPerform(string action, int arg){
	PlayerPerform(action, arg);
}

// 代替 PlayerPerform
// 如果action为say，则根据提供的对话查找对应的语音文件，并在对话显示出屏幕的时候播放语音。
// 如果arg2为文件名，则用此文件名取代自动搜索的文件名
void AsPlayerPerform(string action, string arg1, string arg2 = ""){
	if (action != "say"){
		AsPlayerPerform(action, arg1);
	}
	else {
		string chatText = arg1;
		bool usePerform = true;
		int charId = GetAnyChar("player");
        string filenameSpecified = arg2;
		AsSayInternal(charId, chatText, usePerform, filenameSpecified);
	}
}

void AsSayInternal(int charId, string chatText, bool usePerform, string filenameSpecified = ""){
	string charName = GetCharName(charId);
    if (charName.length > 0){
        string trackName = "a" + charId;
        string filename;
        if (filenameSpecified.length > 0){
            filename = filenameSpecified;
        }
        else{
            filename = _AsBuildVoiceFilename(charName, chatText);
        }
        AsSoundPlayOnChat(trackName, charId, chatText, filename);
    }
	if (usePerform){
        if (charId == GetAnyChar("player")){
		    PlayerPerform("say", chatText);
        }
        else{
            Perform(charId, "say", chatText);
        }
	}
	else{
		Say(charId, chatText);
	}
}

// 代替 Say
// 根据提供的对话查找对应的语音文件，并在对话显示出屏幕的时候播放语音。
// 如果arg2为文件名，则用此文件名取代自动搜索的文件名
void AsSay(int charId, string chatText, string arg2 = ""){
	bool usePerform = false;
    string filenameSpecified = arg2;
	AsSayInternal(charId, chatText, usePerform, filenameSpecified);
}

/******************/
// 获取游戏窗口尺寸
Vector2 AsGetGameWindowSize(){
    return GetGameWindowSize();
}

/******************/
/*
将代码块传入到指定队列里，然后顺序执行
id: 序列ID， 可填0~200
func: 代码块
duration: 执行时长，如果填0，表示执行1次，如果填3，则表示每帧执行一次，共执行3秒
*/
void AsActionQueuePushFunc(uint id, ActionFunc@ func, float duration = 0){
    if (id >= g_actionQueueList.GetSize()) {
        Print("id 过大");
        return;
    }
    g_actionQueueList[id].Push(func, duration);
}

/*
将等待行为传入到指定队列里，然后顺序执行
id: 序列ID， 可填0~200
duration: 等待时长
*/
void AsActionQueuePushWait(uint id, float duration){
    if (id >= g_actionQueueList.GetSize()) {
        Print("id 过大");
        return;
    }
    g_actionQueueList[id].Wait(duration);
}

/*
在指定队列中，跳过正在执行的行为
id: 序列ID
*/
void AsActionQueueSkip(uint id){
    if (id >= g_actionQueueList.GetSize()) {
        Print("id 过大");
        return;
    }
    g_actionQueueList[id].Skip();
}

/*
在当前队列中，跳过正在执行的行为
*/
void AsActionQueueSkip(){
    uint id = g_currentRunningActionQueueId;
    if (id >= g_actionQueueList.GetSize()) {
        return;
    }
    g_actionQueueList[id].Skip();
}

/******************/
// 规划化文件名
string GetNormalizedFilename(string filename){
    filename.Replace('\\', '/');
    /* 删除所有 // */
    while (filename.Find("//") != NPOS) {
        filename.Replace("//", "/");
    }
    return filename;
}
/******************/
// 缓存指定文件夹内的图片，默认缓存jpg和png的图片
void AsImageCacheFolder(const string&in folderName, const string&in filters = ".jpg|.png"){
    string[] filterList = filters.Split('|');
    for (uint iFilter = 0; iFilter < filterList.GetSize(); iFilter++){
        filterList[iFilter] = filterList[iFilter].ToLower();
    }
    string[]@ filenameList = ScanDir(folderName, "*.*", SCAN_FILES, true);
    uint count = 0;
    for (uint i = 0; i < filenameList.GetSize(); i++){
        string filename = filenameList[i];
        string ext = GetExtension(filename).ToLower();
        if (-1 == filterList.Find(ext)){
            continue;
        }
        auto fullName = folderName + "/" + filename;
        fullName = GetNormalizedFilename(fullName);
        string key = fullName.ToLower();
        Image@ image = LoadImageFile(fullName);
        g_cacheImageDict[key] = @image;
        //Print(fullName + " " + (@image!= null) + " key: " + key);

        count += 1;
    }

    Print("缓存图片文件夹 " + folderName + " 共 " + count + " 张图片");
}

// 从缓存或硬盘里读取图片文件
Image@ AsLoadImageFile(const string&in filename){
    string filenameAdjust = GetNormalizedFilename(filename);
    string filenameAdjustLower = filenameAdjust.ToLower();
    if (g_cacheImageDict.Exists(filenameAdjustLower)){
        Print("从缓存中读取: " + filenameAdjust);
        return cast<Image@>(g_cacheImageDict[filenameAdjustLower]);
    }
    else{
        Print("从硬盘中读取: " + filenameAdjust);
        return LoadImageFile(filenameAdjust);
    }
}

/******************/

void OnPostUpdate(){
    // 更新 ActionQueue
    for (uint iQueue = 0; iQueue < g_actionQueueList.GetSize(); iQueue++){
        g_currentRunningActionQueueId = iQueue;
        ActionQueue@ queue = g_actionQueueList[iQueue];
        queue.Update();
    }
    g_currentRunningActionQueueId = uint(-1);
}

void Level_OnPostUpdate(){
    OnPostUpdate();
}

void OnPostStop(){
    // 清理 ActionQueue
    for (uint iQueue = 0; iQueue < g_actionQueueList.GetSize(); iQueue++){
        ActionQueue@ queue = g_actionQueueList[iQueue];
        queue.Clear();
    }
    // 清理图片缓存
    g_cacheImageDict.Clear();
}

void Level_OnPostStop(){
    OnPostStop();
}
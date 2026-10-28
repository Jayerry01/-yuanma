/*
在游戏里按下 Ctrl+Shift+K 开始加密

加密的脚本的文件名缀为 .ase

加密的脚本，每次在游戏里，默认只能运行5分钟，
若要解除限制，请联系As脚本引擎作者。
*/

// 是否在加密成功后，删除源文件到回收站
bool g_isDeletefAterSuccess;

void OnStart(){
    g_isDeletefAterSuccess = false;
}

void OnUpdate(){
    if (ImGui_IsKeyDown(ImGuiKey_LeftCtrl) && ImGui_IsKeyDown(ImGuiKey_LeftShift) && ImGui_IsKeyPressed(ImGuiKey_K)){
        Print("开始对脚本进行加密");

        EncryptScript("AsScripts/Startup/Mod信息面板.as", "", g_isDeletefAterSuccess);

        string bindFilename = "AsScripts/Startup/Mod信息面板.ase"; // 绑定的文件，使得以下加密后的脚本依赖这个文件才能生效

        // EncryptScript("AsScripts/Startup/血条.as", bindFilename, g_isDeletefAterSuccess);

        Print("加密结束，请检查控制台信息");
    }
}
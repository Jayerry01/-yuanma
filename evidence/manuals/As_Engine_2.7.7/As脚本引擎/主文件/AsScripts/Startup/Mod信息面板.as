/*
MOD作者可以任意修改该脚本的内容，来显示MOD信息
*/

string ModName;
string Author;
string Contact;
Vector4 BgColor;
Vector2 Position;
double Duration;

// 强制隐藏的标志
bool g_forceHide = false;

int g_randNum;

void OnStart(){
    ModName = "As脚本引擎";
    Author = "滴风";
    Contact = "feiangame@163.com";
    BgColor = Vector4(0,0,0,0.0); // 背景颜色, 0.0~1.0
    Position = Vector2(0.8, 0.0); // 位置, 0.0~1.0
    Duration = 7; // 显示时长， -1为永远显示
}

void OnUpdate(){
    if (g_forceHide){
        return;
    }

    if (Duration < 0){

    }
    else if (GetGlobalTime() > Duration){
        return;
    }
    

    // 设置窗口位置
    auto screenSize = ImGui_GetDisplaySize();
    ImGui_SetNextWindowPos(screenSize * Position);

    // 窗口基本属性
    int windowFlags = 
        ImGuiWindowFlags_NoTitleBar | // 无标题栏
        ImGuiWindowFlags_NoMove |  // 禁止拖动
        ImGuiWindowFlags_NoResize |  // 禁止手动调整窗口大小
        ImGuiWindowFlags_AlwaysAutoResize |  // 总是自动调整窗口大小
        ImGuiWindowFlags_NoInputs | // 穿透鼠标
        ImGuiWindowFlags_NoScrollbar | // 无滚动条
        0;

    ImGui_PushStyleColor(ImGuiCol_WindowBg, BgColor);

    // 窗口边框宽度为0
    ImGui_PushStyleVar(ImGuiStyleVar_WindowPadding,  Vector2(0,0));
    ImGui_PushStyleVar(ImGuiStyleVar_IndentSpacing,  0);
    ImGui_PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

    bool open = true;
    if (g_randNum == 0){
        g_randNum = Rand(1000000);
    }
    if (ImGui_Begin("Mod信息面板" + g_randNum, open, windowFlags)){
        ImGui_Text("Mod名称 " + ModName);
        ImGui_Text("作者 " + Author);
        ImGui_Text("联系方式 " + Contact);
    }

     ImGui_PopStyleVar();
    ImGui_PopStyleVar();
    ImGui_PopStyleVar();
    ImGui_PopStyleColor();

    ImGui_End();
}

void Scene_OnInit(){
    // 进入场景后强制隐藏
    g_forceHide = true;
}

void Scene_OnStop(){
    // 退出场景后取消强制隐藏
    g_forceHide = false;
}
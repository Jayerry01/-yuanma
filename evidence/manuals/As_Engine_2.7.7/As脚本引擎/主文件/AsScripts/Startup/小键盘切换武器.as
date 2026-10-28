#include "../PScriptLib/AsHelper.as"
bool g_said = false;
void Level_OnUpdate(){
    if (!g_said){
        g_said = true;
        PrintSystemText("现在你可以按键盘右方的数字键盘来切换武器");
    }

    if (AsIsKeyPressed(ImGuiKey_Keypad1)){
        AsSwitchWeapon(1);
        PrintSystemText("切换了新武器" + 1);
    }
    else if (AsIsKeyPressed(ImGuiKey_Keypad2)){
        AsSwitchWeapon(2);
        PrintSystemText("切换了新武器" + 2);
    }
    else if (AsIsKeyPressed(ImGuiKey_Keypad3)){
        AsSwitchWeapon(3);
        PrintSystemText("切换了新武器" + 3);
    }
    else if (AsIsKeyPressed(ImGuiKey_Keypad4)){
        AsSwitchWeapon(4);
        PrintSystemText("切换了新武器" + 4);
    }
    else if (AsIsKeyPressed(ImGuiKey_Keypad5)){
        AsSwitchWeapon(5);
        PrintSystemText("切换了新武器" + 5);
    }
    else if (AsIsKeyPressed(ImGuiKey_Keypad6)){
        AsSwitchWeapon(6);
        PrintSystemText("切换了新武器" + 6);
    }
    else if (AsIsKeyPressed(ImGuiKey_Keypad7)){
        AsSwitchWeapon(7);
        PrintSystemText("切换了新武器" + 7);
    }
    else if (AsIsKeyPressed(ImGuiKey_Keypad8)){
        AsSwitchWeapon(8);
        PrintSystemText("切换了新武器" + 8);
    }
    else if (AsIsKeyPressed(ImGuiKey_Keypad9)){
        AsSwitchWeapon(9);
        PrintSystemText("切换了新武器" + 9);
    }
}

void Level_OnStop(){
    g_said = false;
}
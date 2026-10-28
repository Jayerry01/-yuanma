#include "../PScriptLib/AsHelper.as"

// 声明菜单命令回调函数的类型
funcdef void TextMenuItemCallback(int index, string text, int userData1, string userData2);

// 唯一ID计数器
int g_idCounter;

// 页里的条目
class MenuItem{
    MenuItem(){
        g_idCounter += 1;
        id = g_idCounter;
    }

    // 添加条目, 并设置当选择这个条目时, 调用指定函数
    void AddChild(string text, int userData1, string userData2, TextMenuItemCallback@ callback){
        MenuItem@ item = MenuItem();
        item.text = text;
        @item.callback = callback;
        item.parentId = id;
        item.userData1 = userData1;
        item.userData2 = userData2;
        children.Push(item);
    }

    // 添加条目, 这个条目拥有子级页面
    MenuItem@ AddChild(string text){
        MenuItem@ item = MenuItem();
        item.text = text;
        item.parentId = id;
        children.Push(item);
        return item;
    }


    // 唯一id
    int id;
    // 文本
    string text;
    // 回调函数
    TextMenuItemCallback@ callback;
    // 子条目
    array<MenuItem@> children;
    // 上级菜单Id
    int parentId;
    // 自定义数据
    int userData1;
    string userData2;
}

class TextMenu{
    void SetTitle(string title){
        _title = title;
    }
    MenuItem@ CreateRoot(){
        @_root = MenuItem();
        return _root;
    }

    MenuItem@ GetRoot(){
        return _root;
    }

    string GetTitle() const {
        return _title;
    }
    

    MenuItem@ FindMenuItem(MenuItem@ parent, int id){
        for (uint i = 0; i < parent.children.GetSize(); i++){
            auto child = parent.children[i];
            if (child.id == id){
                return child;
            }
            auto item = FindMenuItem(child, id);
            if (item !is null){
                return item;
            }
        }
        return null;
    }

    MenuItem@ FindMenuItem(int id){
        if (_root.id == id){
            return _root;
        }
        return FindMenuItem(_root, id);
    }

private
    string _title;
    MenuItem@ _root;
}



const dictionary g_itemDict = {
    { 1, "肉包" },
    { 2, "华佗" },
    { 3, "铜皮" },
    { 4, "嗜战" },
    { 5, "猫足" }
};

const dictionary g_xmasDict ={
    { 27, "圣诞蛋糕" },
    { 28, "元气糖" },
    { 29, "圣诞围巾" },
    { 30, "圣诞手套" },
    { 31, "圣诞长靴" },
    { 32, "圣诞头套" }
};

const dictionary g_npcDict ={
    { "Unguard", "无防的" },
    { "Guard", "防守的" },
    { "Sword", "拿剑的" },
    { "Blade", "拿大刀的" },
    { "Hammer", "拿锤子的" },
    { "Dagger", "拿匕首的" },
    { "KATANA", "拿忍刀的" },
    { "Lance", "拿长枪的" },
    { "SAMURAI", "拿乾坤的" },
    { "PUNCH", "拿指虎的" },
    { "Stinger", "拿双刺的" }
};

const dictionary g_weaponDict = {
    { 1, "飞镖"},
    { 2, "飞轮"},
    { 3, "火铳"},
    { 4, "双刺"},
    { 5, "匕首"},
    { 6, "长剑"},
    { 7, "长枪"},
    { 8, "大刀"},
    { 9, "重锤"},
    { 49, "乾坤刀"},
    { 51, "指虎"},
    { 55, "忍刀"}
};

const dictionary g_teleportCharDict ={
    {1, "1号角色"},
    {2, "2号角色"},
    {3, "3号角色"},
    {4, "4号角色"},
    {5, "5号角色"},
    {6, "6号角色"},
    {7, "7号角色"},
    {8, "8号角色"},
    {9, "9号角色"},
    {10, "10号角色"}
};

const dictionary g_teleportWaypointDict ={
    {1, "1号路点"},
    {2, "2号路点"},
    {3, "3号路点"},
    {4, "4号路点"},
    {5, "5号路点"},
    {6, "6号路点"},
    {7, "7号路点"},
    {8, "8号路点"},
    {9, "9号路点"},
    {10, "10号路点"}
};

const dictionary g_teleportItemDict ={
    {1, "1号道具"},
    {2, "2号道具"},
    {3, "3号道具"},
    {4, "4号道具"},
    {5, "5号道具"},
    {6, "6号道具"},
    {7, "7号道具"},
    {8, "8号道具"},
    {9, "9号道具"},
    {10, "10号道具"}
};

const dictionary g_teleportSafeDict ={
    {1, "流星出口"},
    {2, "蝴蝶出口"}
};

const dictionary g_skinDict = {
    {0, "孟星魂"},
    {1, "冷燕"},
    {2, "铁胡子"},
    {3, "夜猫子"},
    {4, "破空"},
    {5, "冯浩"},
    {6, "孙剑"},
    {7, "萧安"},
    {8, "子舆"},
    {9, "王强"},
    {10, "无名"},
    {11, "叶翔"},
    {12, "小何"},
    {13, "凤凰"},
    {14, "石群"},
    {15, "屠城"},
    {16, "范旋"},
    {17, "高寄萍"},
    {18, "孙玉伯"},
    {19, "律香川"}
};

const dictionary g_keyDict = {
    { 1, ImGuiKey_1 },
    { 2, ImGuiKey_2 },
    { 3, ImGuiKey_3 },
    { 4, ImGuiKey_4 },
    { 5, ImGuiKey_5 },
    { 6, ImGuiKey_6 },
    { 7, ImGuiKey_7 },
    { 8, ImGuiKey_8 },
    { 9, ImGuiKey_9 },
    { 0, ImGuiKey_0 }
};

// 将字符串数组转换成数字数组, 再对其排序
array<int> SortKeys(const array<string>& keys){
    array<int> newKeys;
    for (uint i = 0; i < keys.GetSize(); i++){
        newKeys.Push(keys[i].ToInt());
    }
    newKeys.Sort();
    return newKeys;
}
// 当选择了道具
void HandleItemSelected(int index, string text, int userData1, string userData2){
    Print("选择了 " + text);
     // 调用游戏API
    int itemId = userData1;
    PlayerPerform("use", itemId);
    PrintSystemText("我使用了道具 " + text);
}
// 当选择了武器
void HandleWeaponSelected(int index, string text, int userData1, string userData2){
    Print("选择了 " + text);
    
    int weaponId = userData1;
    AsSwitchWeapon(weaponId);
    PrintSystemText("我选择了武器 " + text);
}

// 当选择了瞬移到某个角色
void HandleTeleportCharSelected(int index, string text, int userData1, string userData2){
    Print("选择了 " + text);
    int targetCharId = userData1;
    if (AsMoveToChar(targetCharId)){
        PrintSystemText("我瞬移到了 " + text + " 的位置");
    }
    else{
        PrintSystemText("瞬移失败，因为该目标不存在");
    }
}
// 当选择了瞬移到某个路点
void HandleTeleportWaypointSelected(int index, string text, int userData1, string userData2){
    Print("选择了 " + text);
    int targetWaypointId = userData1;
    if (AsMoveToWayPoint(targetWaypointId)){
        PrintSystemText("我瞬移到了 " + text + " 的位置");
    }
    else{
        PrintSystemText("瞬移失败，因为 "+ text + " 不存在");
    }
}

// 当选择了瞬移到某个道具
void HandleTeleportItemSelected(int index, string text, int userData1, string userData2){
    Print("选择了 " + text);
    int targetItemId = userData1;
    int targetIndex = 0;
    auto playerId = GetChar("player");
    // 获取道具名字
    auto itemName = GetSceneItemName(targetItemId);
    // 如果道具名字不为空，说明道具存在
    if (itemName.length > 0){
        // 这里使用 Misc("transfer", ...)
        Misc("transfer", playerId, itemName);
        PrintSystemText("我瞬移到了 " + text + " " + itemName + " 的位置");
    }
    else{
        PrintSystemText("瞬移失败，因为 "+ text + " 不存在");
    }
}

// 当选择了瞬移到某个出口
void HandleTeleportSafeSelected(int index, string text, int userData1, string userData2){
    Print("选择了 " + text);
    int targetTeam = userData1;
    if (AsMoveToSafe(targetTeam)){
        PrintSystemText("我瞬移到了 " + text + " 的位置");
    }
    else{
        PrintSystemText("瞬移失败，因为 "+ text + " 不存在");
    }
}

// 当选择了瞬移到镖物
void HandleTeleportFlagSelected(int index, string text, int userData1, string userData2){
    Print("选择了 " + text);
    if (AsMoveToFlag(0)){
        PrintSystemText("我瞬移到了 " + "镖物" + " 的位置");
    }
    else{
        PrintSystemText("瞬移失败，因为 镖物 不存在");
    }
}

// 当选择了瞬移到门
void HandleTeleportDoorSelected(int index, string text, int userData1, string userData2){
    Print("选择了 " + text);
    if (AsMoveToFlag(0)){
        PrintSystemText("我瞬移到了 " + "门" + " 的位置");
    }
    else{
        PrintSystemText("瞬移失败，因为 门 不存在");
    }
}

// 当选择了皮肤
void HandleSkinSelected(int index, string text, int userData1, string userData2){
    Print("选择了 " + text);
    int skinIndex = userData1;
    string skinName = "p" + skinIndex;
    AsSwitchPlayerSkin(skinName);
    PrintSystemText("我选择了皮肤 " + text);
}

// 当选择了NPC
void HandleNpcSelected(int index, string text, int userData1, string userData2){
    Print("选择了 " + text);
    string npcFilename = userData2;
    AddNPC(npcFilename);
    PrintSystemText("我添加了NPC " + text);
}
// 当选择了攻击道具
void HandleAttackSelected(int index, string text, int userData1, string userData2){
    Print("选择了 " + text);
    // 获取场景脚本的Id
    int scriptId = GetSceneScriptId();
    // 跨脚本执行函数, 目前只支持传入int 和 string 类型的参数， 不支持接收目标函数的返回值
    int stoneId = userData1;
    int damage = 100000;
    if (ExecuteFunction(scriptId, "StoneOnAttack", stoneId, damage)){
        PrintSystemText("我破坏了 " + stoneId + "号石柱");
    }
    else{
        PrintSystemText("破坏失败，找不到StoneOnAttack函数");
    }
}
// 当选择了保存
void HandleSaveSelected(int index, string text, int userData1, string userData2){
    Print("选择了 " + text);
    Say(1, "将要保存 游戏时间、玩家位置 到文件 UserData/Saves/test.sav");
    int gameTime = GetGameTime(); // 通关时间
    SetTarget(0, "char", 1);
    Vector3 pos = GetPosition(0);
    int numStats = 100; // 最大状态数量
    int[] stats(numStats);
    stats[0] = gameTime;
    stats[1] = int(pos.x);
    stats[2] = int(pos.y);
    stats[3] = int(pos.z);
    string name = "test";
    bool encrypt = userData1 == 1; // 是否加密
    if (AsSaveStats(name, stats, encrypt)){
        Say(1, "保存成功");
    }
    else{
        Say(1, "保存失败");
    }
}

// 当选择了读取
void HandleLoadSelected(int index, string text, int userData1, string userData2){
    Print("选择了 " + text);
    Say(1, "将要从文件 UserData/Saves/test.sav 读取上次保存的 游戏时间、玩家位置");
    // 将 支线id、通关时间 这2个状态保存到文件 UserData/Saves/关卡6.sav
    int[] stats;
    string name = "test";
    bool encrypt = userData1 == 1; // 是否加密
    if (AsLoadStats(name, encrypt, stats)){
        int lastGameTime = stats[0];
        int x, y, z;
        x = stats[1];
        y = stats[2];
        z = stats[3];
        Say(1, "读取成功 上次保存的 游戏时间: " + lastGameTime + ", 玩家位置: " + x + " " + y + " " + z);
    }
    else{
        Say(1, "读取失败");
    }
}

// 当选择了执行Pose
void HandlePerformPoseSelected(int index, string text, int userData1, string userData2){
    Print("选择了 " + text);
    AsPlayerPose(userData1);
}

// 建立Buffer页
void BuildBufferPage(MenuItem@ page){
    // 因为字典的键值是乱序储存的, 且键值类型是字符串, 所以这里要进行排序处理
    auto keys = SortKeys(g_itemDict.GetKeys());
    
    for (uint i = 0; i < keys.GetSize(); i++){
        int itemId = keys[i];
        string itemName = string(g_itemDict[itemId]);
        // 添加条目
        page.AddChild(itemName, itemId, "", HandleItemSelected);
    }
}

// 建立武器页
void BuildWeaponPage(MenuItem@ page){
    // 因为字典的键值是乱序储存的, 且键值类型是字符串, 所以这里要进行排序处理
    auto keys = SortKeys(g_weaponDict.GetKeys());
    
    for (uint i = 0; i < keys.GetSize(); i++){
        int weaponId = keys[i];
        string weaponName = string(g_weaponDict[weaponId]);
        // 添加条目
        page.AddChild(weaponName, weaponId, "", HandleWeaponSelected);
    }
}

// 建立瞬移到某个角色页
void BuildTeleportCharPage(MenuItem@ page){
    // 因为字典的键值是乱序储存的, 且键值类型是字符串, 所以这里要进行排序处理
    auto keys = SortKeys(g_teleportCharDict.GetKeys());
    
    for (uint i = 0; i < keys.GetSize(); i++){
        int charId = keys[i];
        string text = string(g_teleportCharDict[charId]);
        // 添加条目
        page.AddChild(text, charId, "", HandleTeleportCharSelected);
    }
}

// 建立瞬移到某个路点页
void BuildTeleportWaypointPage(MenuItem@ page){
    // 因为字典的键值是乱序储存的, 且键值类型是字符串, 所以这里要进行排序处理
    auto keys = SortKeys(g_teleportWaypointDict.GetKeys());
    
    for (uint i = 0; i < keys.GetSize(); i++){
        int waypointId = keys[i];
        string text = string(g_teleportWaypointDict[waypointId]);
        // 添加条目
        page.AddChild(text, waypointId, "", HandleTeleportWaypointSelected);
    }
}

// 建立瞬移到某个道具页
void BuildTeleportItemPage(MenuItem@ page){
    // 因为字典的键值是乱序储存的, 且键值类型是字符串, 所以这里要进行排序处理
    auto keys = SortKeys(g_teleportItemDict.GetKeys());
    
    for (uint i = 0; i < keys.GetSize(); i++){
        int itemId = keys[i];
        string text = string(g_teleportItemDict[itemId]);
        // 添加条目
        page.AddChild(text, itemId, "", HandleTeleportItemSelected);
    }
}

// 建立瞬移到某个出口页
void BuildTeleportSafePage(MenuItem@ page){
    // 因为字典的键值是乱序储存的, 且键值类型是字符串, 所以这里要进行排序处理
    auto keys = SortKeys(g_teleportSafeDict.GetKeys());
    
    for (uint i = 0; i < keys.GetSize(); i++){
        int team = keys[i];
        string text = string(g_teleportSafeDict[team]);
        // 添加条目
        page.AddChild(text, team, "", HandleTeleportSafeSelected);
    }
}

// 建立瞬移页
void BuildTeleportPage(MenuItem@ page){
    auto charPage = page.AddChild("瞬移到角色");
    BuildTeleportCharPage(charPage);
    auto waypointPage = page.AddChild("瞬移到路点");
    BuildTeleportWaypointPage(waypointPage);
    auto itemPage = page.AddChild("瞬移到道具");
    BuildTeleportItemPage(itemPage);
    auto safePage = page.AddChild("瞬移到出口");
    BuildTeleportSafePage(safePage);
    page.AddChild("瞬移到镖物", 0, "", HandleTeleportFlagSelected);
    page.AddChild("瞬移到门", 0, "", HandleTeleportDoorSelected);
}

// 建立皮肤页
void BuildSkinPage(MenuItem@ page){
    // 因为字典的键值是乱序储存的, 且键值类型是字符串, 所以这里要进行排序处理
    auto keys = SortKeys(g_skinDict.GetKeys());
    
    for (uint i = 0; i < keys.GetSize(); i++){
        int skinId = keys[i];
        string skinText = string(g_skinDict[skinId]);
        // 添加条目
        page.AddChild(skinText, skinId, "", HandleSkinSelected);
    }
}

// 建立圣诞套装页
void BuildXmasPage(MenuItem@ page){
    auto keys = SortKeys(g_xmasDict.GetKeys());
    // 因为字典的键值是乱序储存的, 且键值类型是字符串, 所以这里要进行排序处理
    keys.Sort();

    for (uint i = 0; i < keys.GetSize(); i++){
        int itemId = keys[i];
        string itemName = string(g_xmasDict[itemId]);
        // 添加条目
        page.AddChild(itemName, itemId, "", HandleItemSelected);
    }
}

// 建立npc页
void BuildNpcPage(MenuItem@ page){
    auto keys = g_npcDict.GetKeys();
    for (uint i = 0; i < keys.GetSize(); i++){
        string npcFilename = keys[i];
        string npcDesc = string(g_npcDict[npcFilename]);
        // 添加条目
        page.AddChild(npcDesc, 0, npcFilename, HandleNpcSelected);
    }
}

// 建立破坏页
void BuildAttackPage(MenuItem@ page){
    for (uint stoneId = 1; stoneId <= 20; stoneId++){
        string text = stoneId + "号石柱";
        page.AddChild(text, stoneId, "", HandleAttackSelected);
    }
}

TextMenu@ g_menu;
bool g_open = false;
bool g_said = false;

// 当前正在绘制的菜单页
MenuItem@ g_pageDrawing = null;
// 当前正在绘制的菜单页的起始索引
int g_pageDrawingStartIndex = 0;

// 仅在进入关卡时才初始化菜单
void Level_OnStart(){
    @g_menu = TextMenu();
    g_menu.SetTitle("娱乐菜单");
    auto root = g_menu.CreateRoot();
    root.AddChild("保存存档示例", 0, "", HandleSaveSelected);
    root.AddChild("读取存档示例", 0, "", HandleLoadSelected);
    root.AddChild("保存加密存档示例", 1, "", HandleSaveSelected);
    root.AddChild("读取加密存档示例", 1, "", HandleLoadSelected);
    root.AddChild("执行Pose300", 300, "", HandlePerformPoseSelected);
    auto bufferPage = root.AddChild("Buffer相关");
    BuildBufferPage(bufferPage);
    auto weaponPage = root.AddChild("选择武器");
    BuildWeaponPage(weaponPage);
    auto teleportPage = root.AddChild("瞬移到指定目标");
    BuildTeleportPage(teleportPage);
    auto skinPage = root.AddChild("更换皮肤");
    BuildSkinPage(skinPage);
    auto xmasPage = root.AddChild("圣诞套装");
    BuildXmasPage(xmasPage);
    auto npcPage = root.AddChild("添加NPC");
    BuildNpcPage(npcPage);
    auto attackPage = root.AddChild("破坏钟乳洞的石柱");
    BuildAttackPage(attackPage);
}

// 绘制页面
// 参数: 
// page: 要绘制的菜单页
// startIndex: 要绘制的菜单页的起始条目索引
// pageForNextFrame: 指定下一帧要绘制的菜单页
// pageForNextFrameStateIndex: 指定下一帧要绘制的菜单页的起始条目索引
void DrawPage(MenuItem@ page, uint startIndex, MenuItem@&out pageForNextFrame, uint&out pageForNextFrameStateIndex){
    @pageForNextFrame = page;
    pageForNextFrameStateIndex = startIndex;

    // 每页显示7项, 对应数字键1到7
    const int itemCountPerPage = 7;
    int keyNumber = 0;
    for (uint i = startIndex; i < page.children.GetSize(); i++){
        if ( keyNumber < itemCountPerPage ) {
            keyNumber += 1;
            auto child = page.children[i];
            ImGui_Text(keyNumber + ". " +  child.text);
            if (AsIsKeyPressed(int(g_keyDict[keyNumber]))){
                // 如果条目没有子条目,表示是最终命令, 要调用回调函数
                if (child.children.IsEmpty()){
                    // 因为热加载后可能会丢失句柄指向的对象, 所以这里要检查是否为空
                    if (child.callback !is null){
                        child.callback(i, child.text, child.userData1, child.userData2);
                    }
                    // 关闭菜单
                    @pageForNextFrame = null;
                    pageForNextFrameStateIndex = 0;
                }
                else{
                    // 指定下级菜单
                    @pageForNextFrame = child;
                    pageForNextFrameStateIndex = startIndex;
                }
            }
        }
        else{
            pageForNextFrameStateIndex = 0;
            break;
        }
    }
    // 如果条目没有铺满, 就对剩余空间填充空白
    for (int i = keyNumber; i < itemCountPerPage; i++){
        keyNumber += 1;
        ImGui_Text("");
    }
    keyNumber += 1; // 8
    // 判断是否是首页, 不是的话就显示上一页按键
    if (startIndex >= itemCountPerPage){
        ImGui_Text(keyNumber + ". " + "上一页");
        if (AsIsKeyPressed(int(g_keyDict[keyNumber]))){
            pageForNextFrameStateIndex = startIndex - itemCountPerPage;
        }
    }
    else{
        ImGui_Text(""); // 填充空白
    }
    keyNumber += 1; // 9
    // 判断是否还有条目没显示完
    bool rest = startIndex + itemCountPerPage < page.children.GetSize();
    // 如果没显示完, 就显示翻页键
    if (rest){
        ImGui_Text(keyNumber + ". " + "下一页");
        if (AsIsKeyPressed(int(g_keyDict[keyNumber]))){
            pageForNextFrameStateIndex = startIndex + itemCountPerPage;
        }
    }
    else{
        ImGui_Text(""); // 填充空白
    }
    // 如果当前有上级菜单,就显示返回上一级按键
    keyNumber += 1; // 10
    if (keyNumber == 10){
        keyNumber = 0;
    }
    
    if (page.parentId != 0){
        ImGui_Text(keyNumber + ". 返回上一级");
        if (AsIsKeyPressed(int(g_keyDict[keyNumber]))){
            // 获得上一级菜单的句柄
            auto parentId = page.parentId;
            auto parentPage = @g_menu.FindMenuItem(parentId);
            // 设置当前显示的菜单为上一级菜单
            @pageForNextFrame = parentPage;
            pageForNextFrameStateIndex = 0;
        }
    }
    // 是顶级菜单, 显示退出键
    else{
        ImGui_Text(keyNumber + ". 退出");
        if (AsIsKeyPressed(int(g_keyDict[keyNumber]))){
            @pageForNextFrame = null;
            pageForNextFrameStateIndex = 0;
        }
    }
    
}




void Level_OnStop(){
    g_open = false;
    @g_menu = null;
    @g_pageDrawing = null;
    g_said = false;
}

void OnStart(){
    // 如果g_menu不是空句柄，则说明现在在热重载
    // 销毁菜单，再重建
    Level_OnStop();
    Level_OnStart();


}


void Level_OnUpdate(){
    if (@g_menu is null){
        return;
    }

    if (!g_said){
        g_said = true;
        PrintSystemText("现在你可以按J键打开娱乐菜单");
    }

    // 按 J 键 切换显示菜单
    if (AsIsKeyPressed(ImGuiKey_J)){
        g_open = !g_open;
    }

    if (!g_open){
        return;
    }
    
    // 如果没指定当前的显示页面, 就显示最顶级的页面
    if (g_pageDrawing is null){
        @g_pageDrawing = g_menu.GetRoot();
        g_pageDrawingStartIndex = 0;
    }

    // 设置窗口位置为屏幕左边
    auto screenSize = ImGui_GetDisplaySize();
    Vector2 posPercentage = Vector2(0.05, 0.5); // 屏幕内的相对位置
    ImGui_SetNextWindowPos(screenSize * posPercentage);
    // 半透明背景和标题栏
    ImGui_PushStyleColor(ImGuiCol_WindowBg, Vector4(0.0, 0.0,0.0,0.5));
    ImGui_PushStyleColor(ImGuiCol_TitleBgActive, Vector4(0.0, 0.0,0.0,0.5));
    ImGui_PushStyleColor(ImGuiCol_TitleBg, Vector4(0.0, 0.0,0.0,0.5));
    // 显示窗口
    int windowFlags = 
        ImGuiWindowFlags_NoMove |  // 禁止拖动
        ImGuiWindowFlags_NoResize |  // 禁止手动调整窗口大小
        ImGuiWindowFlags_AlwaysAutoResize |  // 总是自动调整窗口大小
        ImGuiWindowFlags_NoInputs; // 穿透鼠标
    if (ImGui_Begin(g_menu.GetTitle(), windowFlags)){
        MenuItem@ nextFramePage;
        int nextFramePageStartIndex;

        DrawPage(g_pageDrawing, g_pageDrawingStartIndex, nextFramePage, nextFramePageStartIndex);

        @g_pageDrawing = @nextFramePage;
        g_pageDrawingStartIndex = nextFramePageStartIndex;

        if (@g_pageDrawing is null){
            g_open = false;
        }
    }
    ImGui_End();
}


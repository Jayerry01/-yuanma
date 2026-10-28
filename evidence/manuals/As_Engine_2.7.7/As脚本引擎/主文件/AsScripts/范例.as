// 不要忘记在你的脚本里添加这行哦
#include "../PScriptLib/AsHelper.as"

/*******************/

// 脚本语法基础

// 创建变量
int zhengshu = 10; // 整数
bool shiFou = true; // 是或否
string zifuchuan = "字符串"; // 字符串
float xiaoshu = 1.375; // 小数
int[] shuzu(10); // 长度为10的数组，下标可以是0到9
shuzu[0] = 100; // 将数组下标为0的数设为100
shuzu[1] = 100; // 将数组下标为1的数设为100
shuzu[9] = 100; // 将数组下标为9的数设为100
Vector3 position = Vector3(100, 200, 300); // 位置，xyz分别是100 200 300
PrintSystemText(position.x + " " + position.y + " " + position.z); // 在屏幕右侧打印位置

// 连接两个字符串，这里fullText的值为 "ab"
string fullText = "a" + "b";

// 无返回值的函数
void Do(){
}

// 返回整数的函数
int GetIntNumber(){
    return 100;
}

// 返回true或者false的函数
bool AreYouHuman(){
    return true;
}

// 返回字符串的函数
string TargetName(string npcName){
    if (npcName == "小明"){
        return "小红"
    }
    else{
        return "小新"
    }
}

// 条件判断(两级)
if (GetIntNumber() == 1){
    // 如果条件判断为是，则运行到这里
}
else{
    // 如果条件判断为否，则运行到这里
}

// 条件判断(多级)
if (GetIntNumber() == 1){
    // 如果条件判断为是，则运行到这里
}
else if (AreYouHuman()){
    // 如果条件判断为是，则运行到这里
}
else{
    // 如果条件判断为否，则运行到这里
}

// 循环
// 循环100次
for (int i = 0; i < 100; i+=1){
    Print(i);
}

// 类
// 定义一个叫做 Person 的类，有两个成员变量、一个方法
class Person{
    string name;
    int age;

    void SayMyName(){
        Say(1, "我的名字叫" + name + "，今年" + age + "岁");
    }
}
// 创建一个叫做 me 的实例
Person me;
// 在 OnUpdate 里 访问修改调用实例 me
void OnUpdate(){
    // 访问
    Print(me.age);
    // 修改
    me.name = "小明";
    me.age = 18;
    // 调用
    me.SayMyName();
}

// 数的函数
fundef void MyAnonymousFunc(); // 声明委托
MyAnonymousFunc@ func = function(){ Print("Hello!"); } // 创建一个委托，并指向一个匿名函数



/*******************/

// 切换背景音乐
string yinyue = "music/s8.mp3";
PlayMusic(yinyue);


/*******************/

// 当按下某个键之后就执行某些操作
if (AsIsKeyPressed(ImGuiKey_5) || AsIsKeyPressed(ImGuiKey_Keypad5)){ // 判断是否按下了大键盘数字5或小键盘数字5
    // 在这里填写要做的操作
}
if (AsIsKeyDown(ImGuiKey_LeftCtrl) && AsIsKeyPressed(ImGuiKey_F9)){ // 判断是否按下了左Ctrl+F9
    // 在这里填写要做的操作
}
if (AsIsKeyDown(ImGuiKey_LeftShift) && AsIsKeyPressed(ImGuiKey_F9)){ // 判断是否按下了左Shift+F9
    // 在这里填写要做的操作
}

/*******************/

//将当前武器切换到武器8
AsSwitchWeapon(8);

/*******************/

//玩家做出指定Pose300
AsPlayerPose(300);

/*******************/

//将玩家移动到 500 600 400
AsMoveTo(500, 600, 400);

/*******************/

//玩家瞬移到指定路点
AsMoveToWayPoint(3);

/*******************/

//切换玩家皮肤
AsSwitchPlayerSkin("p12");

/*******************/

//将 支线id、通关时间 这2个状态保存到文件 UserData/Saves/关卡6.sav

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

/*******************/

//将 支线id、通关时间 这2个状态从文件 UserData/Saves/关卡6.sav 里 读取出来

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

/*******************/

// 关于通过读取存档来设置任务和NPC基础变量的两种方法

// 假设有以下两个读取存档的函数
int LoadHP(){
    // 读取存档....
}
int LoadWeapon(){
    // 读取存档....
}

/*******/

/* 任务脚本 */
// 第一种方法：推荐写法（As引擎1.3.1以及之前的版本）
int PlayerHP = 999;
int PlayerWeapon = 5;

void OnInit(){
	PlayerHP = LoadHP(); 
	PlayerWeapon = LoadWeapon();
}

// 第二种方法：不推荐的写法（高于As引擎1.3.1的版本）
int PlayerHP = LoadHP();
int PlayerWeapon = LoadWeapon();

/*******/

/* Npc脚本 */
// 第一种方法：推荐写法（As引擎1.3.1以及之前的版本）
int HP = 1000;
int Weapon = 3;
void OnInit(int this){
	g_selfAddr = this;
	
	HP = LoadHP(); 
	Weapon = LoadWeapon();
}

// 第二种方法：不推荐的写法（高于As引擎1.3.1的版本）
int HP = LoadHP();
int Weapon = LoadWeapon();

/*******************/

// 给 2号NPC 做出 pose 565 然后再做 369 
int npcId = 2;
Perform(npcId, "aggress");
SetAggressPose(npcId, 369);
Perform(npcId, "aggress");
SetAggressPose(npcId, 565);

/*******************/
/*
角色模拟搓招

f 前
b 后
l 左
r 右
n 单A
j 跳
, 停顿0.2秒
. 停顿0.5秒
*/
// 如果2号NPC拿着长枪，就做出长枪三连
if (GetWeaponType(2) == 7){
    ChangeBehavior(2, "idle");
    // 前A，停顿1秒，前前A，停顿1.5秒，后后前A
    // AsNpcAttack(2, "f..ff...bbf"); // 旧版
    AsCharAttack(2, "f..ff...bbf" )
}
// 如果2号NPC拿着大刀，就做出大刀三连
if (GetWeaponType(2) == 5){
    ChangeBehavior(2, "idle");
    // 单A，停顿0.5秒，前前A，停顿1秒，前前A
    // AsNpcAttack(2, "n.ff..ff"); // 旧版
    AsCharAttack(2, "n.ff..ff"); // 新版
}

/*******************/
// 修改\和Esc的按键提示

// 有文字提示
SetKeyCommandHint("已打开 \\ 键 功能", "已禁用 \\ 键 功能", "\\ 键被锁定");
SetKeyEscHint("已打开 Esc 键 功能", "已禁用 Esc 键 功能", "Esc 键被锁定");
// 无文字提示
SetKeyCommandHint("", "", "");
SetKeyEscHint("", "", "");

/*******************/
// NPC切换主副武器相关

// 禁止2号NPC切换武器，比如在第一关的炎硫岛可以禁止NPC切换出飞轮
SetAllowCharSwitchWeapon(2, false);
 // 允许2号NPC切换武器
SetAllowCharSwitchWeapon(2, true);
// 检查是否允许2号NPC切换武器
if (IsAllowCharSwitchWeapon(2)) {
    // 做一些操作
}
// 3秒后， 命令2号NPC切换武器(不受SetAllowCharSwitchWeapon影响)
CharSwitchWeapon(2);
Perform(2, "pause", 3)
// 3秒后，命令2号NPC切换武器(受SetAllowCharSwitchWeapon影响)
CharSwitchWeapon(2, false);
Perform(2, "pause", 3)

/*******************/
// NPC扔掉身上的主武器和镖物

// 3秒后，命令2号NPC扔掉主武器
CharDropWeapon(2);
Perform(2, "pause", 3)

// 1秒后，命令2号NPC扔掉镖物
CharDropVipItem(2);
Perform(2, "pause", 1)

/*******************/

// "任务脚本"里调用"场景脚本"里的函数

// 假设"场景脚本"有以下函数
void ChangeSceneSomething1(){
	Say(1, "这里是场景脚本的 ChangeSceneSomething1");
}

void ChangeSceneSomething2(int canshu1, int canshu2){
	Say(1, "这里是场景脚本的 ChangeSceneSomething2", "(", canshu1, ", ", canshu2, ")");
}

// 在"任务脚本"里调用"场景脚本"的 ChangeSceneSomething1 函数
int sceneScriptId = GetSceneScriptId();
ExecuteFunction(sceneScriptId, "ChangeSceneSomething1");

// 在"任务脚本"里调用"场景脚本"的 ChangeSceneSomething2 函数，并传入参数
int sceneScriptId = GetSceneScriptId();
int canshu1 = 10;
int canshu2 = 20;
ExecuteFunction(sceneScriptId, "ChangeSceneSomething2", canshu1, canshu2);

/*******************/

// "任务脚本"里调用"NPC脚本"里的函数

// 假设"NPC脚本"有以下函数
void ChangeNpcSomething1(){
	Say(1, "这里是NPC脚本的 ChangeNpcSomething1");
}

void ChangeNpcSomething2(int canshu1, int canshu2){
	Say(1, "这里是NPC脚本的 ChangeNpcSomething2", "(", canshu1, ", ", canshu2, ")");
}

// 在"任务脚本"里调用2号"NPC脚本"的 ChangeNpcSomething1 函数
int npcScriptId = GetNpcScriptId(2);
ExecuteFunction(npcScriptId, "ChangeNpcSomething1");

// 在"任务脚本"里调用2号"NPC脚本"的 ChangeNpcSomething2 函数，并传入参数
int npcScriptId = GetNpcScriptId(2);
int canshu1 = 50;
int canshu2 = 60;
ExecuteFunction(npcScriptId, "ChangeNpcSomething2", canshu1, canshu2);

/*******************/

// "场景脚本"里调用"任务脚本"里的函数

// 假设"任务脚本"有以下函数
void ChangeSceneSomething1(){
	Say(1, "这里是任务脚本的 ChangeSceneSomething1");
}

void ChangeSceneSomething2(int canshu1, int canshu2){
	Say(1, "这里是任务脚本的 ChangeSceneSomething2", "(", canshu1, ", ", canshu2, ")");
}

// 在"场景脚本"里调用"任务脚本"的 ChangeSceneSomething1 函数
int levelScriptId = GetLevelScriptId();
ExecuteFunction(levelScriptId, "ChangeSceneSomething1");

// 在"场景脚本"里调用"任务脚本"的 ChangeSceneSomething2 函数，并传入参数
int levelScriptId = GetLevelScriptId();
int canshu1 = 10;
int canshu2 = 20;
ExecuteFunction(levelScriptId, "ChangeSceneSomething2", canshu1, canshu2);


/*******************/
// 声音相关

// 概念：
// 声音管理器有a0~a99，b0~b99，共200条音轨
// 其中 a0~a99是全局音效（无论在哪个位置，音量都一样），b0~b99是3D音效（根据远近自动调整声音大小）
// 如果你的任务最大人数为50人，那么对话语音功能就会占用a1~a50这50条音轨，所以，如果你要自己控制全局音效，建议你用a51~a99这个范围的音轨
// 只要是同一个任务，都可以在任何脚本共享音轨
// 如果你不缓存声音文件，那么在游戏过程中突然播放声音文件，很可能就会出现卡顿一下的情况

/*********/
// 以下是根据对话自动播放语音的功能示例：
void OnStart(){
    string voiceFolder = "UserData/Voice/sn01";
    // 设定对话语音文件夹
    AsSetChatVoiceFolder(voiceFolder);

    // 缓存指定文件夹下的所有wav文件
    AsSoundCacheFolder(voiceFolder);
}

// 2号NPC 金枪哨兵长 说话，并播放语音
// 这个函数做了以下动作：
// 1. 在屏幕显示出对话
// 2. 找到 对话语音文件夹/角色名字/对话.wav, 这里的路径是 UserData/Voice/sn01/金枪哨兵长/你好啊.wav
// 3. 在 音轨a{角色ID} 播放语音, 这里的音轨是a2
AsPerform(2, "say", "你好啊");

// 2号NPC 金枪哨兵长 说话，并播放特定语音文件
// 这个函数做了以下动作：
// 1. 在屏幕显示出对话
// 2. 找到指定语音文件 , 这里的路径是 Patch/Bell.wav
// 3. 在 音轨a{角色ID} 播放语音, 这里的音轨是a2
AsPerform(2, "say", "你好啊", "Patch/Bell.wav");


// 玩家 说话，并播放语音
// 这个函数做了以下动作：
// 1. 在屏幕显示出对话
// 2. 找到 对话语音文件夹/角色名字/对话.wav, 这里的路径是 UserData/Voice/sn01/player/欢迎.wav
// 3. 在 音轨a{角色ID} 播放语音, 这里的音轨是a1
AsPlayerPerform("say", "欢迎");

// 玩家 说话，并播放特定语音文件
// 这个函数做了以下动作：
// 1. 在屏幕显示出对话
// 2. 找到指定语音文件 , 这里的路径是 Patch/Bell.wav
// 3. 在 音轨a{角色ID} 播放语音, 这里的音轨是a1
AsPlayerPerform("say", "你好啊", "Patch/Bell.wav");

// 以下同理
AsSay(2, "不错");
AsSay(2, "不错", "Patch/Bell.wav");

/*********/
// 以下是将喇叭绑定到人物身上的示例
// 在3号NPC身上绑定一条3D音效的音轨，循环播放，且走到哪喊到哪
string yingui_b3 = "b3";
AsSoundLoad(yingui_b3, "UserData/Noise/江南皮革厂倒闭了.wav");
AsSoundBindObject(yingui_b3, "char", 3); // 绑定音轨到对象，char是角色、waypoint是路点
bool isLoop = true; // 是否循环
AsSoundPlay(yingui_b3, isLoop);

// 解绑
AsSoundUnBindObject(yingui_b3);

// 停止播放
AsSoundStop(yingui_b3);

/*********/
// 以下是将喇叭放到指定位置的示例
// 在位置 (100, 200, 300)放置一个喇叭，并播放一次
string yingui_b10 = "b10";
AsSoundLoad(yingui_b10, "UserData/Noise/江南皮革厂倒闭了.wav");
AsSoundSetPosition(yingui_b10, 100, 200, 300);
AsSoundPlay(yingui_b10);

/*********/
// 以下是播放自定义全局音效的示例
string yingui_a51 = "a51";
AsSoundPlay(yingui_a51, "UserData/Noise/警报.wav");

/*******************/
// 图片精灵
// 这是一个封装过的图片模块
// 这里的大小、位置、锚点，用的都是相对坐标，最小(0,0) ，最大 (1,1)

AsSprite g_sprite;
void OnStart(){
    // 缓存指定文件夹内的所有图片文件，默认缓存jpg和png图片
    AsImageCacheFolder("image/");
}

void OnUpdate(){
    int randNum = Rand(1, 9);
    g_sprite.Load("image/scene" + randNum + ".JPG");
    g_sprite.Size = Vector2(0.5, 0.5); // 尺寸设置屏幕的一半大小
    g_sprite.BgColor = Vector4(0,0,0,0); // 底色为透明
    g_sprite.Position = Vector2(0.0, 0.0); //位置为屏幕左上角
    g_sprite.Anchor = Vector2(0, 0); // 锚点为图片左上角
    g_sprite.Tint = Vector4(1,1,1,1); // 正常色调
    //g_sprite.Tint = Vector4(1,1,1,0.5); // 一半透明度
    g_sprite.Draw(); // 画一次图
}

/*******************/
// 动作队列
/*
概念：
1. 这里的动作不是指Pose，而是指你的代码块要做的事情
2. 正序执行动作队列里的动作
3. 每个动作可以指定持续时间，每帧执行一次，直到超时，如果指定为0，则只执行一次
4. 上一个动作执行完毕后，就会接着执行下一个动作
5. 可以在动作内部跳过当前的动作，接着执行下一个动作
6，支持10个动作队列并行运行，id 为 0~9
7. 可以用来显示一段时间的图片
8. 可以用来做，让玩家按下按键来执行分支剧情的功能

*/

// 例子1：
// 如果按下F3键，游戏提示你需要在3秒内按下数字1或数字2键，并且不让主角动
// 如果在规定时间内按下数字1或数字2，游戏立刻会显示你按了哪个键
// 如果在规定时间内什么都没按，也会提示你没有做出选择

int g_keySelected = 0;
void OnUpdate(){
    if (AsIsKeyPressed(ImGuiKey_F3)){
        PrintSystemText("正在测试按键判断");
        Say(1, "请在3秒内按下数字1或2键");
        int queueId = 0; // 队列ID
        float testDuration = 3; // 持续时间为3秒
        PlayerPerform("block", 1); // 不让主角移动
        AsActionQueuePushFunc(queueId, function(){
            // 以下代码块将会被每帧执行一次，共持续3秒
            g_keySelected = 0;
            if (AsIsKeyPressed(ImGuiKey_1)){ // 如果按下1键
                g_keySelected = 1; // 标记按了1键
                AsActionQueueSkip(); // 跳出当前动作，也就是不需要等待就接着做下一个动作
            }
            else if (AsIsKeyPressed(ImGuiKey_2)){
                g_keySelected = 2; // 标记按了2键
                AsActionQueueSkip(); // 跳出当前动作，也就是不需要等待就接着做下一个动作
            }
        }, testDuration);

        AsActionQueuePushFunc(queueId, function(){
            // 以下代码块将会被执行1次
            PlayerPerform("block", 0); // 允许主角移动
            if (g_keySelected == 1){
                Say(1, "你选择了数字1");
            }
            else if (g_keySelected == 2){
                Say(1, "你选择了数字2");
            }
            else{
                Say(1, "你没有做出选择");
            }
        });
    }
}

// 例子2：
// 如果按下F4键，则在屏幕左上角(0,0)处画一个占屏幕尺寸比例为(0.5,0.5) 的图片，持续3秒，
// 然后等待1秒，接着在屏幕正中间显示图片,持续3秒
AsSprite g_sprite;
void OnUpdate(){
    if (AsIsKeyPressed(ImGuiKey_F4)){
        PrintSystemText("正在测试图片精灵");
        int randNum = Rand(1, 9);
        g_sprite.Load("image/scene" + randNum + ".JPG");
        g_sprite.Size = Vector2(0.5, 0.5); // 尺寸
        g_sprite.BgColor = Vector4(0,0,0,0); // 底色
        int queueId = 0; // 队列ID为0
        float showDuration = 3; // 持续3秒
        AsActionQueuePushFunc(queueId, function() { 
            // 以下代码块将会被每帧执行一次，共持续3秒
            g_sprite.Position = Vector2(0.0, 0.0); //位置
            g_sprite.Anchor = Vector2(0, 0); // 锚点
            g_sprite.Draw(); // 画图
        }, showDuration);
        AsActionQueuePushWait(queueId, 1); // 等待一秒
        AsActionQueuePushFunc(queueId, function() { 
            // 以下代码块将会被每帧执行一次，共持续3秒
            g_sprite.Position = Vector2(0.5, 0.5);  //位置
            g_sprite.Anchor = Vector2(0.5, 0.5); // 这里锚点改为图片中点
            g_sprite.Draw(); // 画图
        }, showDuration);
    }
}

/*******************/
// 缓存图片资源
void OnStart(){
    // 缓存头像文件夹下的所有图片
    AsImageCacheFolder("UserData/Avatar");
}

/*********************/
// 根据表格配置文件来创建宝藏
// 用Excel或者WPS编辑 AsScripts/snXX/treasure.csv
// 将以下代码复制到AsScripts/snXX/snXX.as
#include "../PScriptLib/AsSceneTreasure.as"
void Scene_OnInit()
{
	CreateTreasureFromCsv("AsScripts/" + GetSceneScriptName() + "/treasure.csv");
}

void Item_OnIdle(int id){
    AsDispatchOnIdleForAsSceneItemList(id);
}

void Item_OnAttack(int id, int characterId, int damage){
    Print("Item_OnAttack", id, characterId, damage);
    AsDispatchOnAttackForAsSceneItemList(id, characterId, damage);
}

void Item_OnPickUp(int id, int characterId){
	string modelName = GetSceneItemModelName(id); //道具模型名称
    Say(characterId, " 捡起了", id, modelName);
}


/*********************/
// 遍历角色的Buffer列表
void OnUpdate(){
    int charId = GetChar("player");
    BufferDetail[] buffers = CharGetBufferList(charId);
    if (buffers.GetSize() > 0){
        Say(charId, "角色 ", charId, " 有以下 Buffer");
    }
    else{
        Say(charId, "角色 ", charId, " 没有 Buffer");
    }
    for (uint bufferIndex = 0; bufferIndex < buffers.GetSize(); bufferIndex++){
        BufferDetail buffer = buffers[bufferIndex];
        Say(charId, "res道具Id: ", buffer.resItemId, "最大时长: ", buffer.durationMax, "剩余时长: ", buffer.durationRest);
    }
}

/*********************/
// 判断角色是否有指定Buffer，并移除它
void OnUpdate(){
    int charId = GetChar("player");
    int targetResItemId = 14; // 要查找的Res道具ID，这里的14是尸毒
    BufferDetail[] buffers = CharGetBufferList(charId);
    for (uint bufferIndex = 0; bufferIndex < buffers.GetSize(); bufferIndex++){
        BufferDetail buffer = buffers[bufferIndex];
        if (buffer.resItemId == targetResItemId){
            Say(charId, "我中毒了，我需要寻找解药");
        }
    }
    // .......
    // 找到解药后，服药
    CharRemoveBuffer(charId, targetResItemId);
}

/*********************/
// 移除指定角色的1个或多个Buffer
void CharRemoveBufferArray(int charId, int[] resItemIdList){
    for (uint i = 0; i < resItemIdList.GetSize(); i++){
        int resItemId = resItemIdList[i];
        CharRemoveBuffer(charId, resItemId);
    }
}
void OnUpdate(){
    int charId = GetChar("player");
    int[] targetResItemIdList = {3,4,14}; // 红手、金钟罩、尸毒
    CharRemoveBufferArray(charId, targetResItemIdList);
}

/*********************/
// 将任务默认胜利动画修改为其他动画
// 将以下代码复制到任务脚本里即可
string RedirectMediaFile(string filenameOriginal){
    // 将一线天的胜利动画修改为钟乳洞的胜利动画
    string filenameReplaced;
    // 比较文件名，如果匹配，则返回新的文件名，否则返回原文件名
    // 注意，动画文件名的后缀名必须是mv，否则会遇到不可预料的问题
    if (0 == Stricmp(filenameOriginal, "mmv/V3.mv")){  
        filenameReplaced = "mmv/V1.mv";
        Print(filenameOriginal, "->", filenameReplaced);
        return filenameReplaced;
    }
    else{
        return filenameOriginal;
    }
}

/*********************/
// 使用 GetCharIdList 和 GetActivePose ，在屏幕右上角显示各个角色当前的Pose
void ShowActivePosePanel(){
    // 设置窗口位置
    Vector4 bgColor = Vector4(0,0,0,0.0); // 背景颜色, 0.0~1.0
    Vector2 position = Vector2(0.8, 0.0); // 位置, 0.0~1.0
    auto screenSize = ImGui_GetDisplaySize();
    ImGui_SetNextWindowPos(screenSize * position);

    // 窗口基本属性
    int windowFlags = 
        ImGuiWindowFlags_NoTitleBar | // 无标题栏
        ImGuiWindowFlags_NoMove |  // 禁止拖动
        ImGuiWindowFlags_NoResize |  // 禁止手动调整窗口大小
        ImGuiWindowFlags_AlwaysAutoResize |  // 总是自动调整窗口大小
        ImGuiWindowFlags_NoInputs | // 穿透鼠标
        ImGuiWindowFlags_NoScrollbar | // 无滚动条
        0;

    ImGui_PushStyleColor(ImGuiCol_WindowBg, bgColor);

    // 窗口边框宽度为0
    ImGui_PushStyleVar(ImGuiStyleVar_WindowPadding,  Vector2(0,0));
    ImGui_PushStyleVar(ImGuiStyleVar_IndentSpacing,  0);
    ImGui_PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

    bool open = true;
    if (ImGui_Begin("角色Pose面板", open, windowFlags)){
        int[] idList = GetCharIdList(); // 获取角色ID列表
        int charCount = idList.GetSize(); // 总角色人数
        // 循环获取角色ID，并在屏幕上写字
        for (int i = 0; i < charCount; i++){ 
            int charId = idList[i]; 
            int pose = GetActivePose(charId);
            ImGui_Text(charId + " : " + pose);
        }
    }

    ImGui_PopStyleVar();
    ImGui_PopStyleVar();
    ImGui_PopStyleVar();
    ImGui_PopStyleColor();

    ImGui_End();
}

void OnUpdate(){
    ShowActivePosePanel();
}

/*********************/
// 修改角色的显示名称和所属队伍
bool playerChanged; // 标识是否已修改主角
bool lengyanChanged; // 标识是否已修改冷燕
void OnUpdate(){
    // 必须用 IsAlive 判断来确保角色活着，才能继续修改
    // 否则会造成不可预料的后果
    // 不要用 GetHP 来判断是否活着，因为不准

    // 修改主角
    int player = GetChar("player");
    if (!playerChanged && IsAlive(player)){
        // 修改显示名称，注意，这并不会改变角色真名
        SetDisplayName(player, "绿头发的男人");
        // 修改所属队伍为蝴蝶
        SetTeam(player, 2);
        // 标识为已修改
        playerChanged = true;
    }
    // 当NPC进入游戏时进行修改
    AddNPC("LengYan");
    int c2 = GetChar("冷燕");
    if (!lengyanChanged && IsAlive(c2)){
        // 修改显示名称，注意，这并不会改变角色真名
        SetDisplayName(c2, "衣衫单薄的女人");
        // 修改所属队伍为蝴蝶
        SetTeam(c2, 2);
        // 标识为已修改
        lengyanChanged = true;
    }
}

/*********************/
// 获取并修改角色的“基础属性”，包括 最大血量、当前血量、攻击力、防御力、速度
// 注意， 角色 最终属性值 = 基础属性值 + 武器属性值 + Buffer属性值 + 其它
// 你可以用修改基础属性值的功能来做角色养成的游戏玩法
void OnUpdate(){
    // 获取 1号角色的 最大血量基础值
    int maxHP = CharGetBaseAttrib(1, CharAttrib_MaxHP);
    // 获取 当前血量基础值
    int hp = CharGetBaseAttrib(1, CharAttrib_HP);
    // 获取 攻击力基础值
    int attack = CharGetBaseAttrib(1, CharAttrib_Attack);
    // 获取 防御力基础值
    int defense = CharGetBaseAttrib(1, CharAttrib_Defense);
    // 获取 速度基础值
    int speed = CharGetBaseAttrib(1, CharAttrib_Speed);

    // 修改 1号角色的 最大血量基础值为2500
    CharSetBaseAttrib(1, CharAttrib_MaxHP, 2500);
    // 修改 当前血量基础值
    CharSetBaseAttrib(1, CharAttrib_HP, 1500);
    // 修改 攻击力基础值
    CharSetBaseAttrib(1, CharAttrib_Attack, 200);
    // 修改 防御力基础值
    CharSetBaseAttrib(1, CharAttrib_Defense, 1500);
    // 修改 速度基础值
    CharSetBaseAttrib(1, CharAttrib_Speed, 300);
}

/*********************/
// 凭空扔出和创建临时道具
void OnUpdate(){
    // 按下H键触发
    if (AsIsKeyPressed(ImGuiKey_H)){
        // 在指定角色的面前扔出1个灵芝
        int charId = GetAnyChar("player");
        int itemType = 2; // 道具类型， 1：武器，2：道具，4：VIP道具
        int itemId = 2; // 道具ID, 灵芝
        CharDropTempItem(charId, itemType, itemId); 
        // 在指定角色周围的4个方向扔出4个红手
        Vector3 pos = CharGetPosition(charId); 
        float dir = CharGetRotationYaw(charId);
        itemId = 4; // 道具ID, 红手
        CharDropTempItem(charId, itemType, itemId, pos, dir+0); // 角色的前面(0度)
        CharDropTempItem(charId, itemType, itemId, pos, dir+90);  // 角色的右边(90度)
        CharDropTempItem(charId, itemType, itemId, pos, dir+180); // 角色的后边(180度)
        CharDropTempItem(charId, itemType, itemId, pos, dir+270); // 角色的左边(270度)
        // 由指定角色，在某个位置朝某个方向扔出1个猫足
        itemId = 5; // 道具ID, 猫足
        pos = Vector3(-406, 978, 96); // 世界坐标
        dir = 48;// 角度
        CharDropTempItem(charId, itemType, itemId, pos, dir);

        // 由指定角色，在某个位置创建1个护甲
        itemId = 3; // 道具ID, 护甲
        pos = Vector3(0, 0, 0); // 世界坐标
        CharCreateTempItem(charId, itemType, itemId, pos);
    }
}
/*********************/
// 处理事件
// 将以下代码按需粘贴到任务/场景/自启动脚本即可

// 处理临时道具被捡起的事件
void OnTempItemPickUp(int resItemType, int resItemId, int charId){
    Say(1, "角色 " + charId + " 捡起了临时物品 " + "类型：" + resItemType + " 编号：" + resItemId);
}

// 处理角色击杀事件
void OnCharacterKill(int killerId, int beKilledId){
    Say(1, "角色", killerId, "击杀", beKilledId);
}

// 处理角色死亡事件
void OnCharacterDeath(int charId, int reason){
    string reasonText = "未知";
    if (reason == 1){
        reasonText = "被其他角色击杀";
    }
    else if (reason == 2) {
        reasonText = "服务器指定死亡";
    }
    else if (reason == 3) {
        reasonText = "其它";
    }
    Say(1, "角色", charId, "死亡", "原因：", reasonText);
}

// 处理角色复活事件
void OnCharacterReborn(int charId){
    Say(1, "角色", charId, "复活了");
}

/*********************/
// 判断两个角色之间是否互相可见
void OnUpdate() {
    Vector3 p1 = CharGetPosition(1); // 获取1号角色的位置
    p1.z += 10; // 提升10个单位的高度，下面有解释为何这么做
    Vector3 p2 = CharGetPosition(2); // 获取2号角色的位置
    p2.z += 10; // 提升10个单位的高度
    // 判断1号角色和2号角色是否互相可见
    if (IsTwoPointsVisible(p1, p2)) {
        // 可见，做一些操作
    }
    else {
        // 不可见，做另外一些操作
    }

    /*
    注意，CharGetPosition获取的角色位置，位于脚下，
    如果人物站在地面上，该位置点就会在地面下，会造成API判断错误，也就是两点永不互相可见，
    所以要提升10个单位到人物头部的位置，这样才能避免API判断错误
    */
}

/*********************/
// 设置共享变量，可以在任意时机、跨脚本调用
void OnUpdate(){
    SetSharedVarInt("BianLiang1", 100); // 设置一个名为BianLiang1的整数变量的值为100
    int temp1 = GetSharedVarInt("BianLiang1"); // 读取BianLiang1的值

    SetSharedVarString("BianLiang2", "Hello"); // 设置一个名为BianLiang2的字符串变量的值为Hello
    string temp2 = GetSharedVarString("BianLiang2"); // 读取BianLiang2的值
}

/*********************/
// 模拟 OpenFile() ReadFile() WriteFile()
// 适用于自启动脚本

void OnUpdate(){
    // 读取
    File file1("UserData/Saves/file.sav");
    int temp1 = file1.ReadLine().ToInt();
    file1.Close();

    // 写入
    File file2("UserData/Saves/file.sav", FILE_WRITE);
    int num = 200; // 要写入的数字
    file2.WriteLine("" + num);
    file2.Close();
}

/*********************/
// 测试图片的UV变换，每按一次Z键，图片的UV变换就会改变一次
AsSprite g_spriteUVTesting;
int keyCounting = 0;
void OnUpdate(){
    g_spriteUVTesting.Load("image/P0019.JPG");
    g_spriteUVTesting.Size = Vector2(0.2, 0.1); // 尺寸
    g_spriteUVTesting.BgColor = Vector4(0,0,0,0); // 底色为透明
    g_spriteUVTesting.Position = Vector2(0.5, 0.5); //位置为屏幕中央
    g_spriteUVTesting.Anchor = Vector2(0.5, 0.5); // 锚点为图片中央
    g_spriteUVTesting.UV0 = Vector2(0, 0); // 设置UV
    g_spriteUVTesting.UV1 = Vector2(1, 1);

    if (AsIsKeyPressed(ImGuiKey_Z)){
        keyCounting += 1;
    }

    UVTransform uvTransform; // 创建UV变换
    switch (keyCounting % 4){
        case 0: {
            uvTransform = FlipX; // 水平翻转
            break;
        }
        case 1: {
            uvTransform = FlipXY; // 水平垂直翻转
            break;
        }
        case 2: {
            uvTransform = FlipY; // 垂直翻转
            break;
        }
        case 3: {
            uvTransform = None; // 不变换
            break;
        }
    }

    g_spriteUVTesting.UVTransform = uvTransform; // 设置UV变换
    g_spriteUVTesting.Draw(); // 画一次图
}

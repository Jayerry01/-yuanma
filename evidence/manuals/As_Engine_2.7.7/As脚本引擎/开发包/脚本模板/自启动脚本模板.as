// NPC的Update事件计数器
dictionary g_npcUpdateCounter;

// 在合适的情况下调用Say函数
void CheckedSay(int id, string text){
	// 判断是否可以调用Say函数, 仅仅是为了避免烦人的控制台警告信息
	// 你可以尝试不判断而直接调用Say函数, 查看控制台的警告信息
	if (CanInvokeGameAPI("Say")){
		Say(id, text);
	}
	
}


void SayFunction(string funcName, bool hasCounter = false, int counter = -1)
{
	array<string> vec = {};
	
	string text = funcName + "(" + Join(vec, ", ") + ")";
	if (hasCounter) {
		text += " 第" + counter + "次";
	}
	CheckedSay(1, text);
}

void SayFunction(string funcName, int arg1, bool hasCounter = false, int counter = -1)
{
	array<string> vec = {arg1};
	
	string text = funcName + "(" + Join(vec, ", ") + ")";
	if (hasCounter) {
		text += " 第" + counter + "次";
	}
	CheckedSay(1, text);
}

void SayFunction(string funcName, int arg1, int arg2, bool hasCounter = false, int counter = -1)
{
	array<string> vec = {arg1, arg2};
	
	string text = funcName + "(" + Join(vec, ", ") + ")";
	if (hasCounter) {
		text += " 第" + counter + "次";
	}
	CheckedSay(1, text);
}


void SayFunction(string funcName, int arg1, int arg2, int arg3, bool hasCounter = false, int counter = -1)
{
	array<string> vec = {arg1, arg2, arg3};
	
	string text = funcName + "(" + Join(vec, ", ") + ")";
	if (hasCounter) {
		text += " 第" + counter + "次";
	}
	CheckedSay(1, text);
}

void SayFunction(string funcName, int arg1, string arg2, int arg3, int arg4, bool hasCounter = false, int counter = -1)
{
	array<string> vec = {arg1, arg2, arg3, arg4};
	
	string text = funcName + "(" + Join(vec, ", ") + ")";
	if (hasCounter)
	{
		text += " 第" + counter + "次";
	}
	CheckedSay(1, text);
	
}

//*******************************************************************
// 该脚本启动时
void OnStart(){
    Print("OnStart");
}

// 游戏更新时
void OnUpdate(){
	
}

// 该脚本结束时
void OnStop(){
	Print("OnStop");
}


/*********** 关卡事件 *************/ 
// 关卡开始时
void Level_OnStart()
{
	Print("Level_OnStart");
}
// 关卡结束时
void Level_OnStop(){
	Print("Level_OnStop");
}

/*********** NPC事件 ************/
// NPC开始时
void NPC_OnStart(int id)
{
	// 重置计数器
	g_npcUpdateCounter[id] = 0;
	
	string name = GetNpcScriptName(id);
	SayFunction("NPC_OnStart", id);
	PlayerPerform("say", "加入了一个NPC " + name);
}

void NPC_OnStop(int id)
{
	string name = GetNpcScriptName(id);
	SayFunction("NPC_OnStop", id);
	PlayerPerform("say", "移除了一个NPC " + name);
}

/*********** 场景事件 ************/
// 场景开始时
void Scene_OnInit()
{
	Print("Scene_OnInit");
}
// 场景结束时
void Scene_OnStop()
{
	Print("Scene_OnStop");
}
// 场景角色事件
void Scene_OnCharacterEvent(int characterId, int event)
{
	Print("Scene_OnCharacterEvent", characterId, event);
}

/*********** 道具事件 ************/
// 道具初始化时
void Item_OnInit(int id)
{
	Print("Item_OnInit", id);
}
// 道具被接触时
void Item_OnTouch(int id, int characterId)
{
	SayFunction("Item_OnTouch", id, characterId);
	string name = GetSceneItemName(id);
	string charName = GetCharName(characterId);
    int playerId = GetChar("player");
	if (characterId == playerId)
	{
		charName = "我";
	}
	PlayerPerform("say", charName + " 碰到了道具 " + name);
}
// 道具被捡起时
void Item_OnPickUp(int id, int characterId)
{
	SayFunction("Item_OnPickUp", id, characterId);
	string name = GetSceneItemName(id);
	string charName = GetCharName(characterId);
	if (characterId == GetChar("player"))
	{
		charName = "我";
	}
	PlayerPerform("say", charName + " 捡起了道具 " + name);
}
// 道具被攻击时
void Item_OnAttack(int id, int characterId, int damage)
{
	SayFunction("Scene_OnAttack", id, characterId, damage);
	string name = GetSceneItemName(id);
	string charName = GetCharName(characterId);
	if (characterId == GetChar("player")) {
		charName = "我";
	}
	PlayerPerform("say", charName + " 攻击了道具 " + name + ",伤害 " + damage + ", 并让它消失");
	NetEvent(1);
	SetSceneItem(id, "attribute", "active", 0);
	NetEvent(0);
}

// 道具静止时
void Item_OnIdle(int id)
{
	
}
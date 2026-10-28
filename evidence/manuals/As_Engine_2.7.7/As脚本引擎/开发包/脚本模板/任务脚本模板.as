/****必须填写的变量*******************/
int Rule = 10;
int RoundTime = 10;
int PlayerSpawn = 9;
int PlayerSpawnDir = 90;
int PlayerWeapon = 5;
int PlayerWeapon2 = 1;
int PlayerHP = 1500;
/*************************/

// 关卡初始化时
void OnInit()
{
	Print("OnInit");
}

// 关卡开始时
void OnStart()
{
	Print("OnStart");
}

// 游戏更新时
void OnUpdate()
{
	
}

// 关卡结束时
void OnStop(){
	Print("OnStop");
}
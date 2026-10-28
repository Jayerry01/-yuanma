/****必须填写的变量*******************/
string Name	= "NPC模板";
int Model =	8;
int Weapon = 7;
int Weapon2 = 0;
int Team = 2;
int View = 400;
int Think = 40;
int	Attack1	= 50;
int Attack2 = 30;
int Attack3 = 0;
int	Guard =	20;
int	Dodge =	10;
int Jump = 5;
int Look = 10;
int Burst = 2;
int Aim = 60;
int GetItem = 3;
int Spawn = 53;
int HP = 1000;	
/*************************/

// init function
int g_selfAddr;
int g_self;
// NPC初始化时
void OnInit(int this)
{
	g_selfAddr = this;
}
// NPC进入场景时
void OnStart()
{
	g_self = GetSelf(g_selfAddr);
	ChangeBehavior(g_self, "wait");
	Say(g_self, "天空一声霹雳，老子闪亮登场");
}
// 游戏更新时
void OnUpdate()
{

}
// NPC退出战场时
void OnStop()
{
	PlayerPerform("say", Name + " 跑掉了");
}
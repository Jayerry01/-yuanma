#include "..\PScriptLib\Def.as"

#include "..\PScriptLib\box.as"
#include "..\PScriptLib\desk.as"
#include "..\PScriptLib\chair.as"
#include "..\PScriptLib\jug.as"


// 场景载入时
void Scene_OnLoad()
{
	Print("Scene_OnLoad");
}
// 场景开始时
void Scene_OnInit()
{
	InitBoxes(g_iNumBoxes);
	InitBBoxes(g_iNumBBoxes);
	InitChairs(g_iNumChairs);
	InitDeskes(g_iNumDeskes);
	InitJugs(g_iNumJugs);

	Print("Scene_OnInit");
}

// 场景更新时
void Scene_OnIdle()
{
}

// 场景结束时
void Scene_OnStop()
{
	Print("Scene_OnStop");
}
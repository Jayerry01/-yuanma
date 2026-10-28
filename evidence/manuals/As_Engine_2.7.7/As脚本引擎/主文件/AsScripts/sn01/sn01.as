/*
	PScript for scene 01
		by Peter Pon 2002/09/27
*/

#include "../PScriptLib/Def.as"

#include "../PScriptLib/box.as"
#include "../PScriptLib/desk.as"
#include "../PScriptLib/chair.as"
#include "../PScriptLib/jug.as"

#include "../PScriptLib/AsSceneTreasure.as"

int g_iStoneMaxHP = 500;
int g_iNumStones = 32;
array<int> g_iStoneHP(g_iNumStones);
array<int> g_bStoneAlive(g_iNumStones);

void Scene_OnLoad()
{
	int i;
	string name;

	for ( i=1; i<=g_iNumStones; i++ )
	{
		MakeString(name, "D_St", i);
		SetSceneItem(name, "name", "machine");
		SetSceneItem(name, "attribute", "damagevalue", 50);
	}
	
	g_iStoneMaxHP = g_iLevel01StoneMaxHP;
}

void Scene_OnInit()
{
	int i;
	string name;

	InitBoxes(g_iNumBoxes);
	InitBBoxes(g_iNumBBoxes);
	InitChairs(g_iNumChairs);
	InitDeskes(g_iNumDeskes);
	InitJugs(g_iNumJugs);
	
	for ( i=1; i<=g_iNumStones; i++ )
	{
		g_iStoneHP[i-1] = g_iStoneMaxHP;
		g_bStoneAlive[i-1] = 1;
		
		Output(i, g_iStoneHP[i-1]);
		MakeString(name, "D_St", i);
		SetSceneItem(name, "attribute", "active", 1);
		SetSceneItem(name, "attribute", "damage", 0);
		SetSceneItem(name, "attribute", "collision", 1);
		SetSceneItem(name, "pose", 0, 0);
		
		MakeString(name, "D_itSt", i);
		SetSceneItem(name, "attribute", "active", 0);
		SetSceneItem(name, "attribute", "interactive", 0);		
		MakeString(name, "D_wpSt", i);
		SetSceneItem(name, "attribute", "active", 0);
		SetSceneItem(name, "attribute", "interactive", 0);		
	}

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

int RemoveItem(int id)
{
	int pose = GetSceneItem(id, "pose");
	if ( pose==0 )
	{
		return 0;
	}
	int state = GetSceneItem(id, "state");
	if ( state!=3 )
	{
		return 0;
	}
	NetEvent(1);
	SetSceneItem(id, "attribute", "active", 0);
	NetEvent(0);
	return 1;
}

int ActiveStoneItem(int index)
{
	string stonename;
	string itemname;
	string weaponname;
	
	MakeString(stonename, "D_St", index);
	int pose = GetSceneItem(stonename, "pose");
	if ( pose==1 )
	{
		return 0;
	}
	
	MakeString(itemname, "D_itSt", index);
	MakeString(weaponname, "D_wpSt", index);
	
	Output("Active Stone", index);
	NetEvent(1);
	CreateEffect(stonename, "StoneBRK");
	SetSceneItem(stonename, "pose", 1, 0);
	SetSceneItem(stonename, "attribute", "collision", 0);
	SetSceneItem(stonename, "attribute", "damage", 1);
	SetSceneItem(itemname, "attribute", "active", 1);
	SetSceneItem(itemname, "attribute", "interactive", 1);
	SetSceneItem(weaponname, "attribute", "active", 1);
	SetSceneItem(itemname, "attribute", "interactive", 1);
	NetEvent(0);
	return 0;
}

void StoneOnAttack(int index, int damage)
{
	string name;
	g_iStoneHP[index-1] = g_iStoneHP[index-1] - damage;
	Output(g_iStoneHP[index-1]);
	MakeString(name, "D_st", index);

	NetEvent(1);
	CreateEffect(name, "StoneHIT");
	NetEvent(0);
	
	if ( g_iStoneHP[index-1]<=0 )
	{
		ActiveStoneItem(index);
	}
}

void StoneOnIdle(int id, int index)
{
	if ( g_bStoneAlive[index-1] )
	{
		if ( RemoveItem(id) )
		{
			g_bStoneAlive[index-1]=0;
		}
	}
}

void D_St01_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(1, damage);
}
void D_St01_OnIdle(int id)
{
	StoneOnIdle(id, 1);
}

void D_St02_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(2, damage);
}
void D_St02_OnIdle(int id)
{
	StoneOnIdle(id, 2);
}

void D_St03_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(3, damage);
}
void D_St03_OnIdle(int id)
{
	StoneOnIdle(id, 3);
}

void D_St04_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(4, damage);
}
void D_St04_OnIdle(int id)
{
	StoneOnIdle(id, 4);
}

void D_St05_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(5, damage);
}
void D_St05_OnIdle(int id)
{
	StoneOnIdle(id, 5);
}

void D_St06_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(6, damage);
}
void D_St06_OnIdle(int id)
{
	StoneOnIdle(id, 6);
}

void D_St07_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(7, damage);
}
void D_St07_OnIdle(int id)
{
	StoneOnIdle(id, 7);
}

void D_St08_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(8, damage);
}
void D_St08_OnIdle(int id)
{
	StoneOnIdle(id, 8);
}

void D_St09_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(9, damage);
}
void D_St09_OnIdle(int id)
{
	StoneOnIdle(id, 9);
}

void D_St10_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(10, damage);
}
void D_St10_OnIdle(int id)
{
	StoneOnIdle(id, 10);
}

void D_St11_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(11, damage);
}
void D_St11_OnIdle(int id)
{
	StoneOnIdle(id, 11);
}

void D_St12_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(12, damage);
}
void D_St12_OnIdle(int id)
{
	StoneOnIdle(id, 12);
}

void D_St13_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(13, damage);
}
void D_St13_OnIdle(int id)
{
	StoneOnIdle(id, 13);
}

void D_St14_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(14, damage);
}
void D_St14_OnIdle(int id)
{
	StoneOnIdle(id, 14);
}

void D_St15_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(15, damage);
}
void D_St15_OnIdle(int id)
{
	StoneOnIdle(id, 15);
}

void D_St16_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(16, damage);
}
void D_St16_OnIdle(int id)
{
	StoneOnIdle(id, 16);
}

void D_St17_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(17, damage);
}
void D_St17_OnIdle(int id)
{
	StoneOnIdle(id, 17);
}

void D_St18_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(18, damage);
}
void D_St18_OnIdle(int id)
{
	StoneOnIdle(id, 18);
}

void D_St19_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(19, damage);
}
void D_St19_OnIdle(int id)
{
	StoneOnIdle(id, 19);
}

void D_St20_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(20, damage);
}
void D_St20_OnIdle(int id)
{
	StoneOnIdle(id, 20);
}

void D_St21_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(21, damage);
}
void D_St21_OnIdle(int id)
{
	StoneOnIdle(id, 21);
}

void D_St22_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(22, damage);
}
void D_St22_OnIdle(int id)
{
	StoneOnIdle(id, 22);
}

void D_St23_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(23, damage);
}
void D_St23_OnIdle(int id)
{
	StoneOnIdle(id, 23);
}

void D_St24_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(24, damage);
}
void D_St24_OnIdle(int id)
{
	StoneOnIdle(id, 24);
}

void D_St25_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(25, damage);
}
void D_St25_OnIdle(int id)
{
	StoneOnIdle(id, 25);
}

void D_St26_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(26, damage);
}
void D_St26_OnIdle(int id)
{
	StoneOnIdle(id, 26);
}

void D_St27_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(27, damage);
}
void D_St27_OnIdle(int id)
{
	StoneOnIdle(id, 27);
}

void D_St28_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(28, damage);
}
void D_St28_OnIdle(int id)
{
	StoneOnIdle(id, 28);
}

void D_St29_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(29, damage);
}
void D_St29_OnIdle(int id)
{
	StoneOnIdle(id, 29);
}

void D_St30_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(30, damage);
}
void D_St30_OnIdle(int id)
{
	StoneOnIdle(id, 30);
}

void D_St31_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(31, damage);
}
void D_St31_OnIdle(int id)
{
	StoneOnIdle(id, 31);
}

void D_St32_OnAttack(int id, int characterid, int damage)
{
	StoneOnAttack(32, damage);
}
void D_St32_OnIdle(int id)
{
	StoneOnIdle(id, 32);
}

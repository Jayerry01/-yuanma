/*
	PScript file for desk Items of all scenes
		by Peter Pon 2002/09/26

	message handle for 20 desks
*/

int g_iNumDeskes = 20;
array<int> g_iDeskHP(g_iNumDeskes);
array<int> g_bDeskAlive(g_iNumDeskes);

void InitDeskes(int num)
{
	int i;
string name;
	
	for ( i=1; i<=num; i++ )
	{
		g_bDeskAlive[i-1] = 1;
		g_iDeskHP[i-1] = g_iDeskMaxHP;
		
		MakeString(name, "D_Desk", i);
		int id = GetSceneItem(name, "index");
		SetSceneItem(id, "name", "machine");
		SetSceneItem(id, "attribute", "collision", 1);
		SetSceneItem(id, "pose", 0, 0);

		MakeString(name, "D_itDesk", i);
		SetSceneItem(name, "attribute", "active", 0);
		SetSceneItem(name, "attribute", "interactive", 0);

		MakeString(name, "D_wpDesk", i);
		SetSceneItem(name, "attribute", "active", 0);
		SetSceneItem(name, "attribute", "interactive", 0);
	}
}

int DeskOnAttack(int id, int index, int damage)
{
	g_iDeskHP[index-1] = g_iDeskHP[index-1] - damage;
	if ( g_iDeskHP[index-1]>0 )
	{
		NetEvent(1);
		CreateEffect(id, "BoxHIT");
		NetEvent(0);
	}
	
	if ( GetSceneItem(id, "pose")==1 )
	{
		return 0;
	}

string itemname;
string weaponname;
	MakeString(itemname, "D_itDesk", index);
	MakeString(weaponname, "D_wpDesk", index);

	NetEvent(1);
	CreateEffect(id, "BoxBRK");
	SetSceneItem(id, "pose", 1, 0);
	SetSceneItem(id, "attribute", "interactive", 0);
	SetSceneItem(id, "attribute", "collision", 0);
	SetSceneItem(itemname, "attribute", "active", 1);
	SetSceneItem(itemname, "attribute", "interactive", 1);
	SetSceneItem(weaponname, "attribute", "active", 1);
	SetSceneItem(weaponname, "attribute", "interactive", 1);
	NetEvent(0);
	
	return 1;
}

int RemoveDesk(int id)
{
	int state;
	int pose;
	
	pose = GetSceneItem(id, "pose");
	if ( pose==0 )
	{
		return 0;
	}
	
	state = GetSceneItem(id, "state");
	if ( state!=3 )
	{
		return 0;
	}
	
	NetEvent(1);
	SetSceneItem(id, "attribute", "active", 0);
	NetEvent(0);
	Output("remove item", id);
	return 1;
}

void DeskOnIdle(int id, int index)
{
	if ( g_bDeskAlive[index-1] )
	{
		if ( RemoveDesk(id) )
		{
			g_bDeskAlive[index-1]=0;
		}
	}
}

void D_Desk01_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 1, damage);
}
void D_Desk01_OnIdle(int id)
{
	DeskOnIdle(id, 1);
}

void D_Desk02_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 2, damage);
}
void D_Desk02_OnIdle(int id)
{
	DeskOnIdle(id, 2);
}

void D_Desk03_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 3, damage);
}
void D_Desk03_OnIdle(int id)
{
	DeskOnIdle(id, 3);
}

void D_Desk04_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 4, damage);
}
void D_Desk04_OnIdle(int id)
{
	DeskOnIdle(id, 4);
}

void D_Desk05_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 5, damage);
}
void D_Desk05_OnIdle(int id)
{
	DeskOnIdle(id, 5);
}

void D_Desk06_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 6, damage);
}
void D_Desk06_OnIdle(int id)
{
	DeskOnIdle(id, 6);
}

void D_Desk07_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 7, damage);
}
void D_Desk07_OnIdle(int id)
{
	DeskOnIdle(id, 7);
}

void D_Desk08_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 8, damage);
}
void D_Desk08_OnIdle(int id)
{
	DeskOnIdle(id, 8);
}

void D_Desk09_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 9, damage);
}
void D_Desk09_OnIdle(int id)
{
	DeskOnIdle(id, 9);
}

void D_Desk10_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 10, damage);
}
void D_Desk10_OnIdle(int id)
{
	DeskOnIdle(id, 10);
}

void D_Desk11_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 11, damage);
}
void D_Desk11_OnIdle(int id)
{
	DeskOnIdle(id, 11);
}

void D_Desk12_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 12, damage);
}
void D_Desk12_OnIdle(int id)
{
	DeskOnIdle(id, 12);
}

void D_Desk13_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 13, damage);
}
void D_Desk13_OnIdle(int id)
{
	DeskOnIdle(id, 13);
}

void D_Desk14_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 14, damage);
}
void D_Desk14_OnIdle(int id)
{
	DeskOnIdle(id, 14);
}

void D_Desk15_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 15, damage);
}
void D_Desk15_OnIdle(int id)
{
	DeskOnIdle(id, 15);
}

void D_Desk16_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 16, damage);
}
void D_Desk16_OnIdle(int id)
{
	DeskOnIdle(id, 16);
}

void D_Desk17_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 17, damage);
}
void D_Desk17_OnIdle(int id)
{
	DeskOnIdle(id, 17);
}

void D_Desk18_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 18, damage);
}
void D_Desk18_OnIdle(int id)
{
	DeskOnIdle(id, 18);
}

void D_Desk19_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 19, damage);
}
void D_Desk19_OnIdle(int id)
{
	DeskOnIdle(id, 19);
}

void D_Desk20_OnAttack(int id, int character, int damage)
{
	DeskOnAttack(id, 20, damage);
}
void D_Desk20_OnIdle(int id)
{
	DeskOnIdle(id, 20);
}

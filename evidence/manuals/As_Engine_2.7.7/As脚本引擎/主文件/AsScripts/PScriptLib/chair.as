/*
	PScript file for chair Items of all scenes
		by Peter Pon 2002/09/26

	message handle for 20 chairs
*/
int g_iNumChairs = 20;
array<int> g_iChairHP(g_iNumChairs);
array<int> g_bChairAlive(g_iNumChairs);

void InitChairs(int num)
{
	int i;
string name;
	
	for ( i=1; i<=num; i++ )
	{
		g_bChairAlive[i-1] = 1;
		g_iChairHP[i-1] = g_iChairMaxHP;
		
		MakeString(name, "D_Chair", i);
		int id = GetSceneItem(name, "index");
		SetSceneItem(id, "name", "machine");
		SetSceneItem(id, "attribute", "collision", 1);
		SetSceneItem(id, "pose", 0, 0);

		MakeString(name, "D_itChair", i);
		SetSceneItem(name, "attribute", "active", 0);
		SetSceneItem(name, "attribute", "interactive", 0);

		MakeString(name, "D_wpChair", i);
		SetSceneItem(name, "attribute", "active", 0);
		SetSceneItem(name, "attribute", "interactive", 0);
	}
}

int ChairOnAttack(int id, int index, int damage)
{
	g_iChairHP[index-1] = g_iChairHP[index-1] - damage;
	if ( g_iChairHP[index-1]>0 )
	{
		NetEvent(1);
		CreateEffect(id, "BoxHIT");
		NetEvent(0);
		return 0;
	}
	
	if ( GetSceneItem(id, "pose")==1 )
	{
		return 0;
	}
	
string itemname;
string weaponname;
	MakeString(itemname, "D_itChair", index);
	MakeString(weaponname, "D_wpChair", index);

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

int RemoveChair(int id)
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

void ChairOnIdle(int id, int index)
{
	if ( g_bChairAlive[index-1] )
	{
		if ( RemoveChair(id) )
		{
			g_bChairAlive[index-1] = 0;
		}
	}
}

void D_Chair01_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 1, damage);
}
void D_Chair01_OnIdle(int id)
{
	ChairOnIdle(id, 1);
}

void D_Chair02_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 2, damage);
}
void D_Chair02_OnIdle(int id)
{
	ChairOnIdle(id, 2);
}

void D_Chair03_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 3, damage);
}
void D_Chair03_OnIdle(int id)
{
	ChairOnIdle(id, 3);
}

void D_Chair04_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 4, damage);
}
void D_Chair04_OnIdle(int id)
{
	ChairOnIdle(id, 4);
}

void D_Chair05_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 5, damage);
}
void D_Chair05_OnIdle(int id)
{
	ChairOnIdle(id, 5);
}

void D_Chair06_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 6, damage);
}
void D_Chair06_OnIdle(int id)
{
	ChairOnIdle(id, 6);
}

void D_Chair07_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 7, damage);
}
void D_Chair07_OnIdle(int id)
{
	ChairOnIdle(id, 7);
}

void D_Chair08_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 8, damage);
}
void D_Chair08_OnIdle(int id)
{
	ChairOnIdle(id, 8);
}

void D_Chair09_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 9, damage);
}
void D_Chair09_OnIdle(int id)
{
	ChairOnIdle(id, 9);
}

void D_Chair10_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 10, damage);
}
void D_Chair10_OnIdle(int id)
{
	ChairOnIdle(id, 10);
}

void D_Chair11_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 11, damage);
}
void D_Chair11_OnIdle(int id)
{
	ChairOnIdle(id, 11);
}

void D_Chair12_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 12, damage);
}
void D_Chair12_OnIdle(int id)
{
	ChairOnIdle(id, 12);
}

void D_Chair13_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 13, damage);
}
void D_Chair13_OnIdle(int id)
{
	ChairOnIdle(id, 13);
}

void D_Chair14_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 14, damage);
}
void D_Chair14_OnIdle(int id)
{
	ChairOnIdle(id, 14);
}

void D_Chair15_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 15, damage);
}
void D_Chair15_OnIdle(int id)
{
	ChairOnIdle(id, 15);
}

void D_Chair16_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 16, damage);
}
void D_Chair16_OnIdle(int id)
{
	ChairOnIdle(id, 16);
}

void D_Chair17_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 17, damage);
}
void D_Chair17_OnIdle(int id)
{
	ChairOnIdle(id, 17);
}

void D_Chair18_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 18, damage);
}
void D_Chair18_OnIdle(int id)
{
	ChairOnIdle(id, 18);
}

void D_Chair19_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 19, damage);
}
void D_Chair19_OnIdle(int id)
{
	ChairOnIdle(id, 19);
}

void D_Chair20_OnAttack(int id, int character, int damage)
{
	ChairOnAttack(id, 20, damage);
}
void D_Chair20_OnIdle(int id)
{
	ChairOnIdle(id, 20);
}

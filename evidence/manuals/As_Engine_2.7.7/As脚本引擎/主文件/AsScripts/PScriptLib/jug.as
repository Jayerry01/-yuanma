/*
	PScript file for jug Items of all scenes
		by Peter Pon 2002/09/26

	message handle for 20 jugs
*/
int g_iNumJugs = 20;
array<int> g_bJugAlive(g_iNumJugs);
array<int> g_iJugHP(g_iNumJugs);

int g_iNumRJugs = 20;
array<int> g_bRJugAlive(g_iNumRJugs);
array<int> g_iRJugHP(g_iNumRJugs);

void InitJugs(int num)
{
	int i;
string name;
	int id;
	
	for ( i=1; i<=num; i++ )
	{
		g_bJugAlive[i-1] = 1;
		g_iJugHP[i-1] = g_iJugMaxHP;
		
		MakeString(name, "D_Jug", i);
		id = GetSceneItem(name, "index");
		SetSceneItem(id, "name", "machine");
		SetSceneItem(id, "attribute", "collision", 1);
		SetSceneItem(id, "pose", 0, 0);

		MakeString(name, "D_itJug", i);
		SetSceneItem(name, "attribute", "active", 0);
		SetSceneItem(name, "attribute", "interactive", 0);

		MakeString(name, "D_wpJug", i);
		SetSceneItem(name, "attribute", "active", 0);
		SetSceneItem(name, "attribute", "interactive", 0);
	}
	
	int j;
string itemname;
	
	for ( i=1; i<=g_iNumRJugs; i++ )
	{
		g_bRJugAlive[i-1] = 1;
		g_iRJugHP[i-1] = g_iJugMaxHP;
		
		MakeString(name, "D_RJug", i);
		id = GetSceneItem(name, "index");
		SetSceneItem(id, "name", "machine");
		SetSceneItem(id, "attribute", "collision", 1);
		SetSceneItem(id, "pose", 0, 0);
		
		for ( j=1; j<=4; j++ )
		{
			MakeString(name, "D_itRJug", i);
			MakeString(itemname, name, j);
			SetSceneItem(itemname, "attribute", "active", 0);
			SetSceneItem(itemname, "attribute", "interactive", 0);
	
			MakeString(name, "D_wpRJug", i);
			MakeString(itemname, name, j);
			SetSceneItem(itemname, "attribute", "active", 0);
			SetSceneItem(itemname, "attribute", "interactive", 0);
		}
	}
}

int JugOnAttack(int id, int index, int damage)
{
	g_iJugHP[index-1] = g_iJugHP[index-1] - damage;
	if ( g_iJugHP[index-1]>0 )
	{
		NetEvent(1);
		CreateEffect(id, "WonHIT");
		NetEvent(0);
		return 0;
	}
	
	if ( GetSceneItem(id, "pose")==1 )
	{
		return 0;
	}
	
string itemname;
string weaponname;
	MakeString(itemname, "D_itJug", index);
	MakeString(weaponname, "D_wpJug", index);

	NetEvent(1);
	CreateEffect(id, "WonBRK");
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

int RemoveJug(int id)
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

void JugOnIdle(int id, int index)
{
	if ( g_bJugAlive[index-1] )
	{
		if ( RemoveJug(id) )
		{
			g_bJugAlive[index-1] = 0;
		}
	}
}

void D_Jug01_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 1, damage);
}
void D_Jug01_OnIdle(int id)
{
	JugOnIdle(id, 1);
}

void D_Jug02_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 2, damage);
}
void D_Jug02_OnIdle(int id)
{
	JugOnIdle(id, 2);
}

void D_Jug03_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 3, damage);
}
void D_Jug03_OnIdle(int id)
{
	JugOnIdle(id, 3);
}

void D_Jug04_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 4, damage);
}
void D_Jug04_OnIdle(int id)
{
	JugOnIdle(id, 4);
}

void D_Jug05_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 5, damage);
}
void D_Jug05_OnIdle(int id)
{
	JugOnIdle(id, 5);
}

void D_Jug06_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 6, damage);
}
void D_Jug06_OnIdle(int id)
{
	JugOnIdle(id, 6);
}

void D_Jug07_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 7, damage);
}
void D_Jug07_OnIdle(int id)
{
	JugOnIdle(id, 7);
}

void D_Jug08_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 8, damage);
}
void D_Jug08_OnIdle(int id)
{
	JugOnIdle(id, 8);
}

void D_Jug09_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 9, damage);
}
void D_Jug09_OnIdle(int id)
{
	JugOnIdle(id, 9);
}

void D_Jug10_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 10, damage);
}
void D_Jug10_OnIdle(int id)
{
	JugOnIdle(id, 10);
}

void D_Jug11_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 11, damage);
}
void D_Jug11_OnIdle(int id)
{
	JugOnIdle(id, 11);
}

void D_Jug12_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 12, damage);
}
void D_Jug12_OnIdle(int id)
{
	JugOnIdle(id, 12);
}

void D_Jug13_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 13, damage);
}
void D_Jug13_OnIdle(int id)
{
	JugOnIdle(id, 13);
}

void D_Jug14_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 14, damage);
}
void D_Jug14_OnIdle(int id)
{
	JugOnIdle(id, 14);
}

void D_Jug15_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 15, damage);
}
void D_Jug15_OnIdle(int id)
{
	JugOnIdle(id, 15);
}

void D_Jug16_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 16, damage);
}
void D_Jug16_OnIdle(int id)
{
	JugOnIdle(id, 16);
}

void D_Jug17_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 17, damage);
}
void D_Jug17_OnIdle(int id)
{
	JugOnIdle(id, 17);
}

void D_Jug18_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 18, damage);
}
void D_Jug18_OnIdle(int id)
{
	JugOnIdle(id, 18);
}

void D_Jug19_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 19, damage);
}
void D_Jug19_OnIdle(int id)
{
	JugOnIdle(id, 19);
}

void D_Jug20_OnAttack(int id, int character, int damage)
{
	JugOnAttack(id, 20, damage);
}
void D_Jug20_OnIdle(int id)
{
	JugOnIdle(id, 20);
}

int RJugOnAttack(int id, int index, int damage)
{
	g_iRJugHP[index-1] = g_iRJugHP[index-1] - damage;
	if ( g_iRJugHP[index-1]>0 )
	{
		NetEvent(1);
		CreateEffect(id, "WonHIT");
		NetEvent(0);
		return 0;
	}
	
	if ( GetSceneItem(id, "pose")==1 )
	{
		return 0;
	}
	
string itemname;
string weaponname;

	MakeString(itemname, "D_itRJug", index);
	MakeString(weaponname, "D_wpRJug", index);

int rand = Rand(1,4);
	
string ritemname;
string rweaponname;

	MakeString(ritemname, itemname, rand);
	MakeString(rweaponname, weaponname, rand);
	
	NetEvent(1);
	CreateEffect(id, "WonBRK");
	SetSceneItem(id, "pose", 1, 0);
	SetSceneItem(id, "attribute", "interactive", 0);
	SetSceneItem(id, "attribute", "collision", 0);
	SetSceneItem(ritemname, "attribute", "active", 1);
	SetSceneItem(ritemname, "attribute", "interactive", 1);
	SetSceneItem(rweaponname, "attribute", "active", 1);
	SetSceneItem(rweaponname, "attribute", "interactive", 1);
	NetEvent(0);
	
	return 1;
}

int RemoveRJug(int id)
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

void RJugOnIdle(int id, int index)
{
	if ( g_bRJugAlive[index-1] )
	{
		if ( RemoveRJug(id) )
		{
			g_bRJugAlive[index-1] = 0;
		}
	}
}

void D_RJug01_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 1, damage);
}
void D_RJug01_OnIdle(int id)
{
	RJugOnIdle(id, 1);
}

void D_RJug02_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 2, damage);
}
void D_RJug02_OnIdle(int id)
{
	RJugOnIdle(id, 2);
}

void D_RJug03_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 3, damage);
}
void D_RJug03_OnIdle(int id)
{
	RJugOnIdle(id, 3);
}

void D_RJug04_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 4, damage);
}
void D_RJug04_OnIdle(int id)
{
	RJugOnIdle(id, 4);
}

void D_RJug05_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 5, damage);
}
void D_RJug05_OnIdle(int id)
{
	RJugOnIdle(id, 5);
}

void D_RJug06_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 6, damage);
}
void D_RJug06_OnIdle(int id)
{
	RJugOnIdle(id, 6);
}

void D_RJug07_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 7, damage);
}
void D_RJug07_OnIdle(int id)
{
	JugOnIdle(id, 7);
}

void D_RJug08_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 8, damage);
}
void D_RJug08_OnIdle(int id)
{
	RJugOnIdle(id, 8);
}

void D_RJug09_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 9, damage);
}
void D_RJug09_OnIdle(int id)
{
	RJugOnIdle(id, 9);
}

void D_RJug10_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 10, damage);
}
void D_RJug10_OnIdle(int id)
{
	RJugOnIdle(id, 10);
}

void D_RJug11_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 11, damage);
}
void D_RJug11_OnIdle(int id)
{
	RJugOnIdle(id, 11);
}

void D_RJug12_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 12, damage);
}
void D_RJug12_OnIdle(int id)
{
	RJugOnIdle(id, 12);
}

void D_RJug13_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 13, damage);
}
void D_RJug13_OnIdle(int id)
{
	RJugOnIdle(id, 13);
}

void D_RJug14_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 14, damage);
}
void D_RJug14_OnIdle(int id)
{
	RJugOnIdle(id, 14);
}

void D_RJug15_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 15, damage);
}
void D_RJug15_OnIdle(int id)
{
	RJugOnIdle(id, 15);
}

void D_RJug16_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 16, damage);
}
void D_RJug16_OnIdle(int id)
{
	RJugOnIdle(id, 16);
}

void D_RJug17_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 17, damage);
}
void D_RJug17_OnIdle(int id)
{
	JugOnIdle(id, 17);
}

void D_RJug18_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 18, damage);
}
void D_RJug18_OnIdle(int id)
{
	RJugOnIdle(id, 18);
}

void D_RJug19_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 19, damage);
}
void D_RJug19_OnIdle(int id)
{
	RJugOnIdle(id, 19);
}

void D_RJug20_OnAttack(int id, int character, int damage)
{
	RJugOnAttack(id, 20, damage);
}
void D_RJug20_OnIdle(int id)
{
	RJugOnIdle(id, 20);
}

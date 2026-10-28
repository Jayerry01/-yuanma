/*
	PScript file for box Items of all scenes
		by Peter Pon 2002/09/26

	message handle for 60 Boxes &
	message handle for 60 BBoxes
*/

int g_iNumBoxes = 65;
array<int> g_iBoxHP(g_iNumBoxes);
array<int> g_bBoxAlive(g_iNumBoxes);

int g_iNumBBoxes = 60;
array<int> g_iBBoxHP(g_iNumBBoxes);
array<int> g_bBBoxAlive(g_iNumBBoxes);

void InitBoxes(int num)
{
	int i;
string name;
	
	for ( i=1; i<=num; i++ )
	{
		g_bBoxAlive[i-1] = 1;
		g_iBoxHP[i-1] = g_iBoxMaxHP;
		
		MakeString(name, "D_BBox", i);
		int id = GetSceneItem(name, "index");
		SetSceneItem(id, "name", "machine");
		SetSceneItem(id, "attribute", "collision", 1);
		SetSceneItem(id, "pose", 0, 0);

		MakeString(name, "D_itBBox", i);
		SetSceneItem(name, "attribute", "active", 0);
		SetSceneItem(name, "attribute", "interactive", 0);

		MakeString(name, "D_wpBBox", i);
		SetSceneItem(name, "attribute", "active", 0);
		SetSceneItem(name, "attribute", "interactive", 0);
	}
}

int BoxOnAttack(int id, int index, int damage)
{
	g_iBoxHP[index-1] = g_iBoxHP[index-1] - damage;
	if ( g_iBoxHP[index-1]>0 )
	{
		NetEvent(1);
		Output("effect:", id, "BoxHit");
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
	MakeString(itemname, "D_itBBox", index);
	MakeString(weaponname, "D_wpBBox", index);

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

int RemoveBox(int id)
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

void BoxOnIdle(int id, int index)
{
	if ( g_bBoxAlive[index-1] )
	{
		if ( RemoveBox(id) )
		{
			g_bBoxAlive[index-1] = 0;
		}
	}
}

void D_BBox01_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 1, damage);
}
void D_BBox01_OnIdle(int id)
{
	BoxOnIdle(id, 1);
}

void D_BBox02_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 2, damage);
}
void D_BBox02_OnIdle(int id)
{
	BoxOnIdle(id, 2);
}

void D_BBox03_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 3, damage);
}
void D_BBox03_OnIdle(int id)
{
	BoxOnIdle(id, 3);
}

void D_BBox04_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 4, damage);
}
void D_BBox04_OnIdle(int id)
{
	BoxOnIdle(id, 4);
}

void D_BBox05_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 5, damage);
}
void D_BBox05_OnIdle(int id)
{
	BoxOnIdle(id, 5);
}

void D_BBox06_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 6, damage);
}
void D_BBox06_OnIdle(int id)
{
	BoxOnIdle(id, 6);
}

void D_BBox07_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 7, damage);
}
void D_BBox07_OnIdle(int id)
{
	BoxOnIdle(id, 7);
}

void D_BBox08_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 8, damage);
}
void D_BBox08_OnIdle(int id)
{
	BoxOnIdle(id, 8);
}

void D_BBox09_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 9, damage);
}
void D_BBox09_OnIdle(int id)
{
	BoxOnIdle(id, 9);
}

void D_BBox10_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 10, damage);
}
void D_BBox10_OnIdle(int id)
{
	BoxOnIdle(id, 10);
}

void D_BBox11_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 11, damage);
}
void D_BBox11_OnIdle(int id)
{
	BoxOnIdle(id, 11);
}

void D_BBox12_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 12, damage);
}
void D_BBox12_OnIdle(int id)
{
	BoxOnIdle(id, 12);
}

void D_BBox13_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 13, damage);
}
void D_BBox13_OnIdle(int id)
{
	BoxOnIdle(id, 13);
}

void D_BBox14_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 14, damage);
}
void D_BBox14_OnIdle(int id)
{
	BoxOnIdle(id, 14);
}

void D_BBox15_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 15, damage);
}
void D_BBox15_OnIdle(int id)
{
	BoxOnIdle(id, 15);
}

void D_BBox16_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 16, damage);
}
void D_BBox16_OnIdle(int id)
{
	BoxOnIdle(id, 16);
}

void D_BBox17_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 17, damage);
}
void D_BBox17_OnIdle(int id)
{
	BoxOnIdle(id, 17);
}

void D_BBox18_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 18, damage);
}
void D_BBox18_OnIdle(int id)
{
	BoxOnIdle(id, 18);
}

void D_BBox19_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 19, damage);
}
void D_BBox19_OnIdle(int id)
{
	BoxOnIdle(id, 19);
}

void D_BBox20_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 20, damage);
}
void D_BBox20_OnIdle(int id)
{
	BoxOnIdle(id, 20);
}

void D_BBox21_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 21, damage);
}
void D_BBox21_OnIdle(int id)
{
	BoxOnIdle(id, 21);
}

void D_BBox22_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 22, damage);
}
void D_BBox22_OnIdle(int id)
{
	BoxOnIdle(id, 22);
}

void D_BBox23_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 23, damage);
}
void D_BBox23_OnIdle(int id)
{
	BoxOnIdle(id, 23);
}

void D_BBox24_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 24, damage);
}
void D_BBox24_OnIdle(int id)
{
	BoxOnIdle(id, 24);
}

void D_BBox25_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 25, damage);
}
void D_BBox25_OnIdle(int id)
{
	BoxOnIdle(id, 25);
}

void D_BBox26_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 26, damage);
}
void D_BBox26_OnIdle(int id)
{
	BoxOnIdle(id, 26);
}

void D_BBox27_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 27, damage);
}
void D_BBox27_OnIdle(int id)
{
	BoxOnIdle(id, 27);
}

void D_BBox28_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 28, damage);
}
void D_BBox28_OnIdle(int id)
{
	BoxOnIdle(id, 28);
}

void D_BBox29_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 29, damage);
}
void D_BBox29_OnIdle(int id)
{
	BoxOnIdle(id, 29);
}

void D_BBox30_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 30, damage);
}
void D_BBox30_OnIdle(int id)
{
	BoxOnIdle(id, 30);
}

void D_BBox31_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 31, damage);
}
void D_BBox31_OnIdle(int id)
{
	BoxOnIdle(id, 31);
}

void D_BBox32_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 32, damage);
}
void D_BBox32_OnIdle(int id)
{
	BoxOnIdle(id, 32);
}

void D_BBox33_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 33, damage);
}
void D_BBox33_OnIdle(int id)
{
	BoxOnIdle(id, 33);
}

void D_BBox34_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 34, damage);
}
void D_BBox34_OnIdle(int id)
{
	BoxOnIdle(id, 34);
}

void D_BBox35_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 35, damage);
}
void D_BBox35_OnIdle(int id)
{
	BoxOnIdle(id, 35);
}

void D_BBox36_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 36, damage);
}
void D_BBox36_OnIdle(int id)
{
	BoxOnIdle(id, 36);
}

void D_BBox37_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 37, damage);
}
void D_BBox37_OnIdle(int id)
{
	BoxOnIdle(id, 37);
}

void D_BBox38_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 38, damage);
}
void D_BBox38_OnIdle(int id)
{
	BoxOnIdle(id, 38);
}

void D_BBox39_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 39, damage);
}
void D_BBox39_OnIdle(int id)
{
	BoxOnIdle(id, 39);
}

void D_BBox40_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 40, damage);
}
void D_BBox40_OnIdle(int id)
{
	BoxOnIdle(id, 40);
}

void D_BBox41_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 41, damage);
}
void D_BBox41_OnIdle(int id)
{
	BoxOnIdle(id, 41);
}

void D_BBox42_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 42, damage);
}
void D_BBox42_OnIdle(int id)
{
	BoxOnIdle(id, 42);
}

void D_BBox43_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 43, damage);
}
void D_BBox43_OnIdle(int id)
{
	BoxOnIdle(id, 43);
}

void D_BBox44_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 44, damage);
}
void D_BBox44_OnIdle(int id)
{
	BoxOnIdle(id, 44);
}

void D_BBox45_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 45, damage);
}
void D_BBox45_OnIdle(int id)
{
	BoxOnIdle(id, 45);
}

void D_BBox46_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 46, damage);
}
void D_BBox46_OnIdle(int id)
{
	BoxOnIdle(id, 46);
}

void D_BBox47_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 47, damage);
}
void D_BBox47_OnIdle(int id)
{
	BoxOnIdle(id, 47);
}

void D_BBox48_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 48, damage);
}
void D_BBox48_OnIdle(int id)
{
	BoxOnIdle(id, 48);
}

void D_BBox49_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 49, damage);
}
void D_BBox49_OnIdle(int id)
{
	BoxOnIdle(id, 49);
}

void D_BBox50_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 50, damage);
}
void D_BBox50_OnIdle(int id)
{
	BoxOnIdle(id, 50);
}

void D_BBox51_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 51, damage);
}
void D_BBox51_OnIdle(int id)
{
	BoxOnIdle(id, 51);
}

void D_BBox52_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 52, damage);
}
void D_BBox52_OnIdle(int id)
{
	BoxOnIdle(id, 52);
}

void D_BBox53_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 53, damage);
}
void D_BBox53_OnIdle(int id)
{
	BoxOnIdle(id, 53);
}

void D_BBox54_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 54, damage);
}
void D_BBox54_OnIdle(int id)
{
	BoxOnIdle(id, 54);
}

void D_BBox55_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 55, damage);
}
void D_BBox55_OnIdle(int id)
{
	BoxOnIdle(id, 55);
}

void D_BBox56_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 56, damage);
}
void D_BBox56_OnIdle(int id)
{
	BoxOnIdle(id, 56);
}

void D_BBox57_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 57, damage);
}
void D_BBox57_OnIdle(int id)
{
	BoxOnIdle(id, 57);
}

void D_BBox58_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 58, damage);
}
void D_BBox58_OnIdle(int id)
{
	BoxOnIdle(id, 58);
}

void D_BBox59_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 59, damage);
}
void D_BBox59_OnIdle(int id)
{
	BoxOnIdle(id, 59);
}

void D_BBox60_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 60, damage);
}
void D_BBox60_OnIdle(int id)
{
	BoxOnIdle(id, 60);
}

void D_BBox61_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 61, damage);
}
void D_BBox61_OnIdle(int id)
{
	BoxOnIdle(id, 61);
}

void D_BBox62_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 62, damage);
}
void D_BBox62_OnIdle(int id)
{
	BoxOnIdle(id, 62);
}

void D_BBox63_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 63, damage);
}
void D_BBox63_OnIdle(int id)
{
	BoxOnIdle(id, 63);
}

void D_BBox64_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 64, damage);
}
void D_BBox64_OnIdle(int id)
{
	BoxOnIdle(id, 64);
}

void D_BBox65_OnAttack(int id, int characterid, int damage)
{
	BoxOnAttack(id, 65, damage);
}
void D_BBox65_OnIdle(int id)
{
	BoxOnIdle(id, 65);
}

void InitBBoxes(int num)
{
	int i;
string name;
	
	for ( i=1; i<=num; i++ )
	{
		g_bBBoxAlive[i-1] = 1;
		g_iBBoxHP[i-1] = g_iBBoxMaxHP;
		
		MakeString(name, "D_BBBox", i);
		int id = GetSceneItem(name, "index");
		SetSceneItem(id, "name", "machine");
		SetSceneItem(id, "attribute", "collision", 1);
		SetSceneItem(id, "pose", 0, 0);

		MakeString(name, "D_itBBBox", i);
		SetSceneItem(name, "attribute", "active", 0);
		SetSceneItem(name, "attribute", "interactive", 0);

		MakeString(name, "D_wpBBBox", i);
		SetSceneItem(name, "attribute", "active", 0);
		SetSceneItem(name, "attribute", "interactive", 0);
	}
}

int BBoxOnAttack(int id, int index, int damage)
{
	g_iBBoxHP[index-1] = g_iBBoxHP[index-1] - damage;
	if ( g_iBBoxHP[index-1]>0 )
	{
		NetEvent(1);
		CreateEffect(id, "BoxHIT");
		NetEvent(0);
		return 0;
	}
	
string itemname;
string weaponname;
	MakeString(itemname, "D_itBBBox", index);
	MakeString(weaponname, "D_wpBBBox", index);

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

int RemoveBBox(int id)
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

void BBoxOnIdle(int id, int index)
{
	if ( g_bBBoxAlive[index-1] )
	{
		if ( RemoveBBox(id) )
		{
			g_bBBoxAlive[index-1] = 0;
		}
	}
}

void D_BBBox01_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 1, damage);
}
void D_BBBox01_OnIdle(int id)
{
	BBoxOnIdle(id, 1);
}

void D_BBBox02_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 2, damage);
}
void D_BBBox02_OnIdle(int id)
{
	BBoxOnIdle(id, 2);
}

void D_BBBox03_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 3, damage);
}
void D_BBBox03_OnIdle(int id)
{
	BBoxOnIdle(id, 3);
}

void D_BBBox04_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 4, damage);
}
void D_BBBox04_OnIdle(int id)
{
	BBoxOnIdle(id, 4);
}

void D_BBBox05_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 5, damage);
}
void D_BBBox05_OnIdle(int id)
{
	BBoxOnIdle(id, 5);
}

void D_BBBox06_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 6, damage);
}
void D_BBBox06_OnIdle(int id)
{
	BBoxOnIdle(id, 6);
}

void D_BBBox07_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 7, damage);
}
void D_BBBox07_OnIdle(int id)
{
	BBoxOnIdle(id, 7);
}

void D_BBBox08_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 8, damage);
}
void D_BBBox08_OnIdle(int id)
{
	BBoxOnIdle(id, 8);
}

void D_BBBox09_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 9, damage);
}
void D_BBBox09_OnIdle(int id)
{
	BBoxOnIdle(id, 9);
}

void D_BBBox10_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 10, damage);
}
void D_BBBox10_OnIdle(int id)
{
	BBoxOnIdle(id, 10);
}

void D_BBBox11_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 11, damage);
}
void D_BBBox11_OnIdle(int id)
{
	BBoxOnIdle(id, 11);
}

void D_BBBox12_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 12, damage);
}
void D_BBBox12_OnIdle(int id)
{
	BBoxOnIdle(id, 12);
}

void D_BBBox13_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 13, damage);
}
void D_BBBox13_OnIdle(int id)
{
	BBoxOnIdle(id, 13);
}

void D_BBBox14_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 14, damage);
}
void D_BBBox14_OnIdle(int id)
{
	BBoxOnIdle(id, 14);
}

void D_BBBox15_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 15, damage);
}
void D_BBBox15_OnIdle(int id)
{
	BBoxOnIdle(id, 15);
}

void D_BBBox16_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 16, damage);
}
void D_BBBox16_OnIdle(int id)
{
	BBoxOnIdle(id, 16);
}

void D_BBBox17_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 17, damage);
}
void D_BBBox17_OnIdle(int id)
{
	BBoxOnIdle(id, 17);
}

void D_BBBox18_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 18, damage);
}
void D_BBBox18_OnIdle(int id)
{
	BBoxOnIdle(id, 18);
}

void D_BBBox19_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 19, damage);
}
void D_BBBox19_OnIdle(int id)
{
	BBoxOnIdle(id, 19);
}

void D_BBBox20_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 20, damage);
}
void D_BBBox20_OnIdle(int id)
{
	BBoxOnIdle(id, 20);
}

void D_BBBox21_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 21, damage);
}
void D_BBBox21_OnIdle(int id)
{
	BBoxOnIdle(id, 21);
}

void D_BBBox22_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 22, damage);
}
void D_BBBox22_OnIdle(int id)
{
	BBoxOnIdle(id, 22);
}

void D_BBBox23_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 23, damage);
}
void D_BBBox23_OnIdle(int id)
{
	BBoxOnIdle(id, 23);
}

void D_BBBox24_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 24, damage);
}
void D_BBBox24_OnIdle(int id)
{
	BBoxOnIdle(id, 24);
}

void D_BBBox25_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 25, damage);
}
void D_BBBox25_OnIdle(int id)
{
	BBoxOnIdle(id, 25);
}

void D_BBBox26_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 26, damage);
}
void D_BBBox26_OnIdle(int id)
{
	BBoxOnIdle(id, 26);
}

void D_BBBox27_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 27, damage);
}
void D_BBBox27_OnIdle(int id)
{
	BBoxOnIdle(id, 27);
}

void D_BBBox28_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 28, damage);
}
void D_BBBox28_OnIdle(int id)
{
	BBoxOnIdle(id, 28);
}

void D_BBBox29_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 29, damage);
}
void D_BBBox29_OnIdle(int id)
{
	BBoxOnIdle(id, 29);
}

void D_BBBox30_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 30, damage);
}
void D_BBBox30_OnIdle(int id)
{
	BBoxOnIdle(id, 30);
}

void D_BBBox31_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 31, damage);
}
void D_BBBox31_OnIdle(int id)
{
	BBoxOnIdle(id, 31);
}

void D_BBBox32_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 32, damage);
}
void D_BBBox32_OnIdle(int id)
{
	BBoxOnIdle(id, 32);
}

void D_BBBox33_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 33, damage);
}
void D_BBBox33_OnIdle(int id)
{
	BBoxOnIdle(id, 33);
}

void D_BBBox34_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 34, damage);
}
void D_BBBox34_OnIdle(int id)
{
	BBoxOnIdle(id, 34);
}

void D_BBBox35_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 35, damage);
}
void D_BBBox35_OnIdle(int id)
{
	BBoxOnIdle(id, 35);
}

void D_BBBox36_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 36, damage);
}
void D_BBBox36_OnIdle(int id)
{
	BBoxOnIdle(id, 36);
}

void D_BBBox37_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 37, damage);
}
void D_BBBox37_OnIdle(int id)
{
	BBoxOnIdle(id, 37);
}

void D_BBBox38_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 38, damage);
}
void D_BBBox38_OnIdle(int id)
{
	BBoxOnIdle(id, 38);
}

void D_BBBox39_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 39, damage);
}
void D_BBBox39_OnIdle(int id)
{
	BBoxOnIdle(id, 39);
}

void D_BBBox40_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 40, damage);
}
void D_BBBox40_OnIdle(int id)
{
	BBoxOnIdle(id, 40);
}

void D_BBBox41_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 41, damage);
}
void D_BBBox41_OnIdle(int id)
{
	BBoxOnIdle(id, 41);
}

void D_BBBox42_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 42, damage);
}
void D_BBBox42_OnIdle(int id)
{
	BBoxOnIdle(id, 42);
}

void D_BBBox43_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 43, damage);
}
void D_BBBox43_OnIdle(int id)
{
	BBoxOnIdle(id, 43);
}

void D_BBBox44_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 44, damage);
}
void D_BBBox44_OnIdle(int id)
{
	BBoxOnIdle(id, 44);
}

void D_BBBox45_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 45, damage);
}
void D_BBBox45_OnIdle(int id)
{
	BBoxOnIdle(id, 45);
}

void D_BBBox46_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 46, damage);
}
void D_BBBox46_OnIdle(int id)
{
	BBoxOnIdle(id, 46);
}

void D_BBBox47_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 47, damage);
}
void D_BBBox47_OnIdle(int id)
{
	BBoxOnIdle(id, 47);
}

void D_BBBox48_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 48, damage);
}
void D_BBBox48_OnIdle(int id)
{
	BBoxOnIdle(id, 48);
}

void D_BBBox49_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 49, damage);
}
void D_BBBox49_OnIdle(int id)
{
	BBoxOnIdle(id, 49);
}

void D_BBBox50_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 50, damage);
}
void D_BBBox50_OnIdle(int id)
{
	BBoxOnIdle(id, 50);
}

void D_BBBox51_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 51, damage);
}
void D_BBBox51_OnIdle(int id)
{
	BBoxOnIdle(id, 51);
}

void D_BBBox52_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 52, damage);
}
void D_BBBox52_OnIdle(int id)
{
	BBoxOnIdle(id, 52);
}

void D_BBBox53_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 53, damage);
}
void D_BBBox53_OnIdle(int id)
{
	BBoxOnIdle(id, 53);
}

void D_BBBox54_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 54, damage);
}
void D_BBBox54_OnIdle(int id)
{
	BBoxOnIdle(id, 54);
}

void D_BBBox55_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 55, damage);
}
void D_BBBox55_OnIdle(int id)
{
	BBoxOnIdle(id, 55);
}

void D_BBBox56_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 56, damage);
}
void D_BBBox56_OnIdle(int id)
{
	BBoxOnIdle(id, 56);
}

void D_BBBox57_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 57, damage);
}
void D_BBBox57_OnIdle(int id)
{
	BBoxOnIdle(id, 57);
}

void D_BBBox58_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 58, damage);
}
void D_BBBox58_OnIdle(int id)
{
	BBoxOnIdle(id, 58);
}

void D_BBBox59_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 59, damage);
}
void D_BBBox59_OnIdle(int id)
{
	BBoxOnIdle(id, 59);
}

void D_BBBox60_OnAttack(int id, int characterid, int damage)
{
	BBoxOnAttack(id, 60, damage);
}
void D_BBBox60_OnIdle(int id)
{
	BBoxOnIdle(id, 60);
}


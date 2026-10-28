/*
流星模型导出 v0.81(测试版) by：漠之北 
修正没有贴图时获取材质报错
修正没有UVW纹理时报错
增加对象转网格功能，不需要转换为可编辑网格也可以导出
使用纹理顶点导出减少UV错乱
*/
_path = undefined

attcls = #( --属性类型
	#(
		"model",
		"name",
		"ticket",
		"effect",
		"visible",
		"billboard",
		"ObjectType",
		"deform",
		"TextureAnimation"
	),
	#(
		"模型文件，道具/武器 请在关于中查看道具/武器表！",
		"功能，出生点/死亡hell/伤血damage30/出口safe，等...",
		"模式显示，1盟主 2截镖 3护城 4暗杀 5死斗 6剧情 不添加为全模式显示，多模式显示请用逗号隔开，如：1,2,3",
		"特效文件 请在关于中查看特效表！",
		"透明，0透明 1不透明(默认)",
		"展示牌 1面向镜头 2水平面向镜头",
		"安全区域，超出该对象范围强制死亡！",
		"变形动画 值：sin#三角函数 \"xyz\"#波动轴 30#幅度 0.1#频率 10#波大小",
		"纹理(uv)动画，值：1 0.1 0.1 说明：1为开关，0关1开 2为x轴流动 3为y轴流动"
	),
	#(
		"",
		"",
		"",
		"",
		"0:透明 1:不透明(默认)",
		"1:面向镜头 2:水平面向镜头",
		"camerabox",
		"sin \"xyz\" 30 0.1 10",
		"1 0.1 0.1"
	)
)
Textureval = #( --通道
	"NORMAL",
	"COLORKEY",
	"ALPHACHANNEL"
)
Texturestr = #( --通道
	"NORMAL 标准",
	"COLORKEY 色彩增强",
	"ALPHACHANNEL 透明通道"
)
blendval = #( --混合
	"DISABLE 1 0",
	"DISABLE 0 1",
	"ENABLE 0 s",
	"ENABLE 0 sa",
	"ENABLE 0 1-s",
	"ENABLE 0 1-sa",
	"ENABLE 1 s",
	"ENABLE 1 sa",
	"ENABLE s 1",
	"ENABLE s 1-s",
	"ENABLE sa 0",
	"ENABLE sa 1",
	"ENABLE sa 1-sa",
	"ENABLE sa sa"
)
blendstr = #( --混合
	"DISABLE 1 0 普通无混合",
	"DISABLE 0 1 透明不显示材质",
	"ENABLE 0 s 过滤白色 ALPHA通道失效",
	"ENABLE 0 sa ALPHA通道为黑色",
	"ENABLE 0 1-s 过滤黑色，并反向白色（白变黑）ALPHA通道失效",
	"ENABLE 0 1-sa ALPHA通道有效，贴图全黑",
	"ENABLE 1 s 过滤灰色 ALPHA通道失效",
	"ENABLE 1 sa 过滤黑色 ALPHA通道保持原图不变，不滤色",
	"ENABLE s 1 过滤黑色 强光 ALPHA通道失效",
	"ENABLE s 1-s 过滤黑色 正常 ALPHA通道失效",
	"ENABLE sa 0 贴图正常， ALPHA通道为黑色",
	"ENABLE sa 1 过滤黑色 强 ALPHA通道有效 有羽化效果",
	"ENABLE sa 1-sa 使ALPHA通道有羽化效果",
	"ENABLE sa sa 过滤黑色 稍弱 ALPHA通道为黑色"
)
struct GET_Tex(
	obj, --对象
	mat,
	cls, --类型
	mid, --材质id
	path,--路径
	tname, --名字
	tex --贴图名
)
fn xs var1 var2=(--1要保留小数点的数，2小数点位数

    var = var1 as float
    str = "0."+ var2 as string +"f"
    ret = formattedPrint var format:str
    return ret
)
fn getatt obj num=(--取des属性 undefined
	tname = getUserProp obj "name"
	tmodel = getUserProp obj "model"
	tticket = getUserProp obj "ticket"
	teffect = getUserProp obj "effect"
	tvisible = getUserProp obj "visible"
	tbillboard = getUserProp obj "billboard"
	tObjectType = getUserProp obj "ObjectType"
	tdeform = getUserProp obj "deform"
	tTextureAnimation = getUserProp obj "TextureAnimation"
	atttxt = ""
	if tname != undefined then(
		atttxt += "    name = \"" + (tname as string) + "\"\n"
	)else if num > 2 and num < 6 then(
		atttxt += "    name = \"" + (obj.name as string) + "\"\n"
	)
	if tmodel != undefined then(
		atttxt += "    model = \"" + (tmodel as string) + "\"\n"
	)else if num == 6 then(
		atttxt += "    model = \"" + (obj.name as string) + "\"\n"
	)
	if tticket != undefined then(
		atttxt += "    ticket = " + (tticket as string) + "\n"
	)
	if teffect != undefined then(
		atttxt += "    effect = \"" + (teffect as string) + "\"\n"
	)
	if tvisible != undefined then(
		atttxt += "    visible = " + (tvisible as string) + "\n"
	)else if num == 2 then (
		atttxt += "    visible = 0\n"
	)
	if tbillboard != undefined then(
		atttxt += "    billboard = " + (tbillboard as string) + "\n"
	)
	if tObjectType != undefined then(
		atttxt += "    ObjectType = " + (tObjectType as string) + "\n"
	)
	if tdeform != undefined then(
		tstr = filterString  tdeform " "
		if tstr.count == 5 then(
			atttxt += "    animation = " + (tstr[1] as string) + "\n"
			atttxt += "    deformref = " + (tstr[2] as string) + "\n"
			atttxt += "    deformsize = " + (tstr[3] as string) + "\n"
			atttxt += "    deformfreq = " + (tstr[4] as string) + "\n"
			atttxt += "    deformrange = " + (tstr[5] as string) + "\n"
		)
	)
	atttstr = "0 0.0 0.0"
	if tTextureAnimation != undefined then(
		tstr = filterString  tTextureAnimation " "
		if tstr.count == 3 then(
			atttstr = tTextureAnimation
		)
	)
	ret = #()
	append ret atttstr
	append ret atttxt
	return ret
)
fn topos str num=(--生成pos
	_txt = stringstream ""
	if str.count then(
		str1 = filterString str " "--分割
		if str1.count then(
			for i = 1 to str1.count do(
				sstr = filterString  str1[i] "-"--分割
				if sstr.count == 2 then(
					format "pose\n" to:_txt
					format "{\n" to:_txt
					format "  start %\n" sstr[1] to:_txt
					format "  end %\n" sstr[2] to:_txt
					format "}\n" to:_txt
				)
			)
		)else(
			format "pose\n" to:_txt
			format "{\n" to:_txt
			format "  start %\n" 0 to:_txt
			format "  end %\n" (num-1) to:_txt
			format "}\n" to:_txt	
		)
	)else(
		format "pose\n" to:_txt
		format "{\n" to:_txt
		format "  start %\n" 0 to:_txt
		format "  end %\n" (num-1) to:_txt
		format "}\n" to:_txt
	)
	return _txt
)
fn tofmc obj start num=(--生成fmc
	_txt	=	stringstream ""
	format "# GModel Animation File V1.0\n"		to:_txt	
	format "# Model For Lxres.com Creation Time %\n" LocalTime to:_txt	
	format "SceneObjects % DummeyObjects %\n" obj.count 0 to:_txt	
	format "FPS % Frames % Mode: %\n" frameRate num "RIGID" to:_txt	
	Animate On
	for i = 1 to num do(
		at time (i-1+start)	
		(
			format "frame %\n" (i-1) to:_txt	
			format "{\n" to:_txt	
				for j = 1 to obj.count do
				(
					pos = obj[j].pos
					posx = xs pos.x 4
					posy = xs pos.y 4
					posz = xs pos.z 4
					rot = obj[j].rotation --流星四元序是 w,x,y,z max是 x,y,z,w
					rotw = xs rot.w 4
					rotx = xs rot.x 4
					roty = xs rot.y 4
					rotz = xs rot.z 4
					format "  t % % % q % % % %\n" posx posy posz rotw rotx roty rotz to:_txt	
				) 
			format "}\n" to:_txt	
		)
	)
	Animate off
	return _txt
)
fn topst obj pname=(--生成pst
	_txt	=	stringstream ""
	format "/*\n"	to:_txt	
	format "	PScript For Lxres.com Creation Time %\n" LocalTime to:_txt
	format "	scene %\n" pname to:_txt
	format "*/\n" to:_txt
	format "#include \"..\\PScriptLib\\Def.h\"\n\n" to:_txt
	format "#include \"..\\PScriptLib\\box.pst\"\n" to:_txt
	format "#include \"..\\PScriptLib\\desk.pst\"\n" to:_txt
	format "#include \"..\\PScriptLib\\chair.pst\"\n" to:_txt
	format "#include \"..\\PScriptLib\\jug.pst\"\n\n" to:_txt
	format "Scene_OnInit()\n" to:_txt
	format "{\n" to:_txt
	format "  InitBoxes(g_iNumBoxes);\n" to:_txt
	format "  InitBBoxes(g_iNumBBoxes);\n" to:_txt
	format "  InitChairs(g_iNumChairs);\n" to:_txt
	format "  InitDeskes(g_iNumDeskes);\n" to:_txt
	format "  InitJugs(g_iNumJugs);\n" to:_txt
	for i = 1 to obj.count do(
		format "\n  SetSceneItem(\"D_%\", \"attribute\", \"collision\", 0);\n" obj[i].name to:_txt
		format "  SetSceneItem(\"D_%\", \"attribute\", \"interactive\", 1);\n" obj[i].name to:_txt
	)
	format "}\n" to:_txt
	return _txt
)
fn togmc tex mat dat atdat totga =(--生成gmc
	_txt	=	stringstream ""
	format "# GModel Geometry File V1.0\n"	to:_txt	
	format "# Model For Lxres.com Creation Time %\n" LocalTime to:_txt
	--贴图
	format "Textures %\n" tex.count to:_txt
	format "{\n" to:_txt
	for i = 1 to tex.count do(
		if tex[i] == "" then(
			format "  %\n" "NONE" to:_txt
		)else(
			texname = filenameFromPath tex[i]--全名
			if totga then(
				textyp = getFilenameType tex[i]--后缀
				textex = getFilenameFile tex[i]--前缀
				if (textyp as name) == (".dds" as name) or (textyp as name) == (".psd" as name) or (textyp as name) == (".png" as name) then(
					texname = textex + ".tga"
				)
			)
			format "  %\n" texname to:_txt
		)
	)
	format "}\n" to:_txt
	--材质
	format "Shaders %\n" mat[1].count to:_txt
	for i = 1 to mat[1].count do(
		tstr = filterString  mat[1][i] "|||"
		texid = (findItem tex tstr[1])-1
		format "shader %\n" (i-1) to:_txt
		format "{\n" to:_txt
		format "  Texture % %\n" texid Textureval[tstr[2] as integer] to:_txt
		format "  TwoSide %\n" tstr[3] to:_txt
		format "  Blend   %\n" blendval[tstr[4] as integer] to:_txt
		format "  Opaque  %\n" tstr[5] to:_txt
		format "}\n" to:_txt
	)
	--模型
	allvv = 0
	allfac = 0
	for i = 1 to dat.count do(
		allvv += dat[i].vv.count
		allfac += dat[i].fac.count
	)
	for i = 1 to atdat.count do(
		allvv += atdat[i].vv.count
		allfac += atdat[i].fac.count
	)
	format "SceneObjects % DummeyObjects %\n" (dat.count + atdat.count) 0 to:_txt
	format "Vertices % Faces %\n" allvv allfac to:_txt
	for i = 1 to dat.count do(
		format "Object %\n" dat[i].tex to:_txt
		format "{\n" to:_txt
		format "  Vertices % Faces %\n" dat[i].vv.count dat[i].fac.count to:_txt
		for j = 1 to dat[i].vv.count do(
			vvx = xs dat[i].vv[j].x 5
			vvy = xs dat[i].vv[j].y 5
			vvz = xs dat[i].vv[j].z 5
			nvx = xs dat[i].nv[j].x 5
			nvy = xs dat[i].nv[j].y 5
			nvz = xs dat[i].nv[j].z 5
			r = dat[i].col[j].red as integer
			g = dat[i].col[j].green as integer
			b = dat[i].col[j].blue as integer
			a = dat[i].col[j].alpha as integer
			tvx = xs dat[i].tv[j].x 5
			tvy = xs dat[i].tv[j].y 5
			format "  v % % % n % % % c % % % % t % %\n" vvx vvy vvz nvx nvy nvz r g b a tvx tvy to:_txt
		)
		--  f 0 0 1 2	 0.754  0.000 -0.657
		for j = 1 to dat[i].fac.count do(
			mid = -1
			id = dat[i].mid[j] as integer
			for k = 1 to mat[2][i].count do(
				if mat[2][i][k][1] == id then(
					mid = mat[2][i][k][2]-1
					exit
				)
			)
			fac1 = dat[i].fac[j][1] as integer-1
			fac2 = dat[i].fac[j][2] as integer-1
			fac3 = dat[i].fac[j][3] as integer-1
			fnvx = xs dat[i].fnv[j].x 5
			fnvy = xs dat[i].fnv[j].y 5
			fnvz = xs dat[i].fnv[j].z 5
			format "  f % % % % % % %\n" mid fac1 fac2 fac3 fnvx fnvy fnvz to:_txt
		)
		format "}\n" to:_txt
	)
	for i = 1 to atdat.count do(
		format "Object %\n" atdat[i].tex to:_txt
		format "{\n" to:_txt
		format "  Vertices % Faces %\n" atdat[i].vv.count atdat[i].fac.count to:_txt
		for j = 1 to atdat[i].vv.count do(
			vvx = xs atdat[i].vv[j].x 5
			vvy = xs atdat[i].vv[j].y 5
			vvz = xs atdat[i].vv[j].z 5
			nvx = xs atdat[i].nv[j].x 5
			nvy = xs atdat[i].nv[j].y 5
			nvz = xs atdat[i].nv[j].z 5
			r = atdat[i].col[j].red as integer
			g = atdat[i].col[j].green as integer
			b = atdat[i].col[j].blue as integer
			a = atdat[i].col[j].alpha as integer
			tvx = xs atdat[i].tv[j].x 5
			tvy = xs atdat[i].tv[j].y 5
			format "  v % % % n % % % c % % % % t % %\n" vvx vvy vvz nvx nvy nvz r g b a tvx tvy to:_txt
		)
		--  f 0 0 1 2	 0.754  0.000 -0.657
		for j = 1 to atdat[i].fac.count do(
			fac1 = atdat[i].fac[j][1] as integer-1
			fac2 = atdat[i].fac[j][2] as integer-1
			fac3 = atdat[i].fac[j][3] as integer-1
			fnvx = xs atdat[i].fnv[j].x 5
			fnvy = xs atdat[i].fnv[j].y 5
			fnvz = xs atdat[i].fnv[j].z 5
			format "  f % % % % % % %\n" -1 fac1 fac2 fac3 fnvx fnvy fnvz to:_txt
		)
		format "}\n" to:_txt
	)
	return _txt
)
fn todes obj tem ddd wpn=(--生成des
	_txt = stringstream ""
	dum = 0
	if tem then(
		dum += obj[3].count + obj[4].count + obj[5].count
	)
	if ddd then(
		dum += obj[6].count
	)
	if wpn then(
		dum += obj[7].count
	)
	format "# GModel Geometry File V1.0\n"	to:_txt	
	format "# Model For Lxres.com Creation Time %\n" LocalTime to:_txt
	format "SceneObjects % DummeyObjects %\n" (obj[1].count + obj[2].count) dum to:_txt
	for i = 1 to obj[1].count do(
		att = getatt obj[1][i] 1
		format "Object %\n" obj[1][i].name to:_txt
		format "{\n" to:_txt
		posx = xs obj[1][i].pos.x 5
		posy = xs obj[1][i].pos.y 5
		posz = xs obj[1][i].pos.z 5
		rotx = xs obj[1][i].rotation.x 5
		roty = xs obj[1][i].rotation.y 5
		rotz = xs obj[1][i].rotation.z 5
		rotw = xs obj[1][i].rotation.w 5
		format "  Position: % % %\n" posx posy posz to:_txt
		format "  Quaternion: % % % %\n" rotw rotx roty rotz to:_txt
		format "  TextureAnimation: %\n" att[1] to:_txt
		format "  Custom:\n" to:_txt
		format "  {\n" to:_txt
		format "%" att[2] to:_txt
		format "  }\n" to:_txt
		format "}\n" to:_txt
	)
	for i = 1 to obj[2].count do(
		att = getatt obj[2][i] 2
		format "Object %\n" obj[2][i].name to:_txt
		format "{\n" to:_txt
		posx = xs obj[2][i].pos.x 5
		posy = xs obj[2][i].pos.y 5
		posz = xs obj[2][i].pos.z 5
		rotx = xs obj[2][i].rotation.x 5
		roty = xs obj[2][i].rotation.y 5
		rotz = xs obj[2][i].rotation.z 5
		rotw = xs obj[2][i].rotation.w 5
		format "  Position: % % %\n" posx posy posz to:_txt
		format "  Quaternion: % % % %\n" rotw rotx roty rotz to:_txt
		format "  TextureAnimation: %\n" att[1] to:_txt
		format "  Custom:\n" to:_txt
		format "  {\n" to:_txt
		format "%" att[2] to:_txt
		format "  }\n" to:_txt
		format "}\n" to:_txt
	)
	for i = 1 to obj[3].count do(
		att = getatt obj[3][i] 3
		format "Object D_%\n" obj[3][i].name to:_txt
		format "{\n" to:_txt
		posx = xs obj[3][i].pos.x 5
		posy = xs obj[3][i].pos.y 5
		posz = xs obj[3][i].pos.z 5
		rotx = xs obj[3][i].rotation.x 5
		roty = xs obj[3][i].rotation.y 5
		rotz = xs obj[3][i].rotation.z 5
		rotw = xs obj[3][i].rotation.w 5
		format "  Position: % % %\n" posx posy posz to:_txt
		format "  Quaternion: % % % %\n" rotw rotx roty rotz to:_txt
		format "  TextureAnimation: %\n" att[1] to:_txt
		format "  Custom:\n" to:_txt
		format "  {\n" to:_txt
		format "%" att[2] to:_txt
		format "  }\n" to:_txt
		format "}\n" to:_txt
	)
	for i = 1 to obj[4].count do(
		att = getatt obj[4][i] 4
		format "Object D_%\n" obj[4][i].name to:_txt
		format "{\n" to:_txt
		posx = xs obj[4][i].pos.x 5
		posy = xs obj[4][i].pos.y 5
		posz = xs obj[4][i].pos.z 5
		rotx = xs obj[4][i].rotation.x 5
		roty = xs obj[4][i].rotation.y 5
		rotz = xs obj[4][i].rotation.z 5
		rotw = xs obj[4][i].rotation.w 5
		format "  Position: % % %\n" posx posy posz to:_txt
		format "  Quaternion: % % % %\n" rotw rotx roty rotz to:_txt
		format "  TextureAnimation: %\n" att[1] to:_txt
		format "  Custom:\n" to:_txt
		format "  {\n" to:_txt
		format "%" att[2] to:_txt
		format "  }\n" to:_txt
		format "}\n" to:_txt
	)
	for i = 1 to obj[5].count do(
		att = getatt obj[5][i] 5
		format "Object D_%\n" obj[5][i].name to:_txt
		format "{\n" to:_txt
		posx = xs obj[5][i].pos.x 5
		posy = xs obj[5][i].pos.y 5
		posz = xs obj[5][i].pos.z 5
		rotx = xs obj[5][i].rotation.x 5
		roty = xs obj[5][i].rotation.y 5
		rotz = xs obj[5][i].rotation.z 5
		rotw = xs obj[5][i].rotation.w 5
		format "  Position: % % %\n" posx posy posz to:_txt
		format "  Quaternion: % % % %\n" rotw rotx roty rotz to:_txt
		format "  TextureAnimation: %\n" att[1] to:_txt
		format "  Custom:\n" to:_txt
		format "  {\n" to:_txt
		format "%" att[2] to:_txt
		format "  }\n" to:_txt
		format "}\n" to:_txt
	)
	for i = 1 to obj[6].count do(
		att = getatt obj[6][i] 6
		format "Object D_%\n" obj[6][i].name to:_txt
		format "{\n" to:_txt
		posx = xs obj[6][i].pos.x 5
		posy = xs obj[6][i].pos.y 5
		posz = xs obj[6][i].pos.z 5
		rotx = xs obj[6][i].rotation.x 5
		roty = xs obj[6][i].rotation.y 5
		rotz = xs obj[6][i].rotation.z 5
		rotw = xs obj[6][i].rotation.w 5
		format "  Position: % % %\n" posx posy posz to:_txt
		format "  Quaternion: % % % %\n" rotw rotx roty rotz to:_txt
		format "  TextureAnimation: %\n" att[1] to:_txt
		format "  Custom:\n" to:_txt
		format "  {\n" to:_txt
		format "%" att[2] to:_txt
		format "  }\n" to:_txt
		format "}\n" to:_txt
	)
	for i = 1 to obj[7].count do(
		att = getatt obj[7][i] 7
		format "Object D_%\n" obj[7][i].name to:_txt
		format "{\n" to:_txt
		posx = xs obj[7][i].pos.x 5
		posy = xs obj[7][i].pos.y 5
		posz = xs obj[7][i].pos.z 5
		rotx = xs obj[7][i].rotation.x 5
		roty = xs obj[7][i].rotation.y 5
		rotz = xs obj[7][i].rotation.z 5
		rotw = xs obj[7][i].rotation.w 5
		format "  Position: % % %\n" posx posy posz to:_txt
		format "  Quaternion: % % % %\n" rotw rotx roty rotz to:_txt
		format "  TextureAnimation: %\n" att[1] to:_txt
		format "  Custom:\n" to:_txt
		format "  {\n" to:_txt
		format "%" att[2] to:_txt
		format "  }\n" to:_txt
		format "}\n" to:_txt
	)
	return _txt
)
fn getmatatt obj mat cls=(--取材质属性
	tex = ""--贴图名
	option = getUserProp obj "Texture"--通道
	twoside = getUserProp obj "TwoSide"--双面
	tblend = getUserProp obj "Blend"--混合
	opacity = getUserProp obj "Opaque"--不透明度
	
	case cls of (
		1:(
			try (
				tex	=	mat.diffuseMap.filename
				if option == undefined then (option = 3-mat.diffuseMap.alphasource)--通道
				if twoside == undefined then (twoside = mat.twoSided as integer)--双面
				if opacity == undefined then (opacity = mat.opacity/100.0)--不透明度
				if tblend == undefined then(tblend = 1)--混合	
			) catch (
				tex	=	"NONE"
				if option == undefined then (option = 1)--通道
				if twoside == undefined then (twoside = 0)--双面
				if opacity == undefined then (opacity = 1.0)--不透明度
				if tblend == undefined then(tblend = 1)--混合	
			)
		)
		2:(
			try (
				tex	=	mat.base_color_map.filename
				if option == undefined then (option = 3-mat.base_color_map.alphasource)--通道
				if twoside == undefined then (twoside = 1)--双面
				if opacity == undefined then (opacity = 1-mat.Transparency)--不透明度
				if tblend == undefined then(tblend = 1)--混合	
			) catch (
				tex	=	"NONE"
				if option == undefined then (option = 1)--通道
				if twoside == undefined then (twoside = 0)--双面
				if opacity == undefined then (opacity = 1.0)--不透明度
				if tblend == undefined then(tblend = 1)--混合	
			)
		)
	)
	if tex == "" or tex == undefined then(tex = "NONE")
	str = (tex as string) + "|||" + (option as string) + "|||" + (twoside as string) + "|||" + (tblend as string) + "|||" + (opacity as string)
	return str
)
fn getouttex obj=(--取贴图
	ret = #()
	if obj.count == 0 then(
		return #()
	)
	for i = 1 to obj.count do(
		m = obj[i].material --取材质
		mtype = classof m
		case mtype of (
			Standardmaterial:(--单材质
				try (
					tex = m.diffuseMap.filename
				) catch (
					tex = "NULL"
					--MessageBox("对象：" + obj[i].name + "没有贴图！") title:"提示!" beep:false
				)
				appendIfUnique ret tex
			)
			PhysicalMaterial:(/*物理材质*/
				try (
					tex = m.base_color_map.filename
				) catch (
					tex = "NULL"
					--MessageBox("对象：" + obj[i].name + "没有贴图！") title:"提示!" beep:false
				)
				appendIfUnique ret tex
			)/*物理材质*/
			Multimaterial:(/*多维材质*/
				for j = 1 to m.numsubs do (
					mu = m.materialList[j]
					mtype = classof mu 
					case mtype of (
						Standardmaterial:(
							try (
								tex = mu.diffuseMap.filename
							) catch (
								tex = "NULL"
								--MessageBox("对象：" + obj[i].name + "没有贴图！") title:"提示!" beep:false
							)
							appendIfUnique ret tex
						)
						PhysicalMaterial:(
							try (
								tex = mu.base_color_map.filename
							) catch (
								tex = "NULL"
							)
							appendIfUnique ret tex
						)
						default:(
						)
					)
				)
			)/*多维材质*/
			NoMaterial:(--无
			)
			default:(	
			)
		)
	)
	return ret
)
fn getoutmat obj=(--取材质
	if obj.count == 0 then(
		return #(#(),#())
	)
	ret = #()
	mid = #()
	for i = 1 to obj.count do(
		append mid #()
		m = obj[i].material --取材质
		mtype = classof m
		case mtype of (
			Standardmaterial:(--单材质
				matdat = getmatatt obj[i] m 1
				if findItem ret matdat == 0 then(
					append ret matdat
					append mid[i] #(1,ret.count)
				)else(
					append mid[i] #(1,findItem ret matdat)
				)
			)
			PhysicalMaterial:(/*物理材质*/
				matdat = getmatatt obj[i] m 2
				if findItem ret matdat == 0 then(
					append ret matdat
					append mid[i] #(1,ret.count)
				)else(
					append mid[i] #(1,findItem ret matdat)
				)
			)/*物理材质*/
			Multimaterial:(/*多维材质*/
				for j = 1 to m.numsubs do (
					mu = m.materialList[j]
					mtype = classof mu 
					case mtype of (
						Standardmaterial:(
							matdat = getmatatt obj[i] mu 1
							if findItem ret matdat == 0 then(
								append ret matdat
								append mid[i] #(j,ret.count)
							)else(
								append mid[i] #(j,findItem ret matdat)
							)			
						)
						PhysicalMaterial:(
							matdat = getmatatt obj[i] mu 2
							if findItem ret matdat == 0 then(
								append ret matdat
								append mid[i] #(j,ret.count)
							)else(
								append mid[i] #(j,findItem ret matdat)
							)			
						)
						default:(
						)
					)
				)
			)/*多维材质*/
			NoMaterial:(--无
			)
			default:(	
			)
		)
	)
	_ret = #()
	append _ret ret
	append _ret mid
	return _ret
)
fn outcls obj=(--分类
	ret = #()
	if obj.count == 0 then(
		return -1
	)
	--类型
	cls1 = #() --模型
	cls2 = #() --包围盒
	cls3 = #() --盟主
	cls4 = #() --流星
	cls5 = #() --蝴蝶
	cls6 = #() --道具
	cls7 = #() --武器拖影
	cls8 = #() --跳过

	for i = 1 to obj.count do(
		par = obj[i].parent
		if par != undefined then(
			parname = par.name as string
		)else(
			parname = "null"
		)
		case of (
			(matchPattern parname pattern:"盟主出生点_*"):(
				append cls3 obj[i]
			)
			(matchPattern parname pattern:"流星出生点_*"):(
				append cls4 obj[i]
			)
			(matchPattern parname pattern:"蝴蝶出生点_*"):(
				append cls5 obj[i]
			)
			(matchPattern parname pattern:"道具声明_*"):(
				append cls6 obj[i]
			)
			(matchPattern parname pattern:"武器拖影_*"):(
				append cls7 obj[i]
			)
			(matchPattern obj[i].name pattern:"AtBox*"):(
				try (
					tmp = snapshotAsMesh obj[i]
					append cls2 obj[i]
				) catch (
					append cls8 obj[i]
				)
			)
			default:(
				try (
					tmp = snapshotAsMesh obj[i]
					append cls1 obj[i]
				) catch (
					append cls8 obj[i]
				)
			)
		)
	)
	append ret cls1
	append ret cls2
	append ret cls3
	append ret cls4
	append ret cls5
	append ret cls6
	append ret cls7
	append ret cls8
	return ret
)
fn getoutdat obj=(--导出文件
	if (obj.count == 0 ) then (
		--MessageBox("请选择要导出的对象!") title:"提示!"beep:false;
		return #()
	)
	struct Out_dat(
		tex,
		vv=#(),--顶点坐标
		nv=#(),--顶点法线坐标
		col=#(),--顶点颜色
		tv=#(),--顶点纹理坐标
		fac=#(),--面ID
		fnv=#(),--面法线坐标
		mid=#()--面材质ID
	)
	ret = #()
	for i = 1 to obj.count do(
		vid = #()
		tmp = Out_dat()
		test = #() --判断重复点
		tmp.tex = obj[i].name
		tmpobj = snapshotAsMesh obj[i]
		colnum = getNumCPVVerts tmpobj --判断顶点颜色 0为无
		tvvnum = tmpobj.numtverts --纹理顶点数
		--vvnum = tmpobj.numverts --顶点数
		if tvvnum == 0 then(
			if ((queryBox ("对象 " + tmp.tex + " 没有UV坐标，是否导出 " + tmp.tex + " ？")) == false )then (
				continue
			)
		)
		for j = 1 to tmpobj.numfaces do(
			if classof obj[i].material == Multimaterial then(
				fmid = getFaceMatID tmpobj j
			)else(
				fmid = 1
			)
			--fmid = getFaceMatID obj[i] j
			fid = getFace tmpobj j
			ffn = getFaceNormal tmpobj j
			if tvvnum == 0 then(
				tvf = fid
			)else(
				tvf = getTVFace tmpobj j
			)
			for k = 1 to 3 do(
				cf = findItem vid tvf[k]
				if cf == 0 then(
					vv = getVert tmpobj fid[k]
					nv = getNormal tmpobj fid[k]
					if colnum == 0 then(
						cc = Color 255 255 255
					)else(
						cc = getVertColor tmpobj tvf[k]
					)
					if tvvnum == 0 then(
						tv = [0.0,0.0,0.0]
					)else(
						tv = getTVert tmpobj tvf[k]
					)
					AppEnd tmp.vv vv -- 取得一个顶点
					AppEnd tmp.tv tv -- 取得纹理坐标
					AppEnd tmp.nv nv --顶点法线
					AppEnd tmp.col cc --顶点颜色
					append vid tvf[k]
					tvf[k] = vid.count
				)else(
					tvf[k] = cf
				)
			)
			AppEnd tmp.fac tvf --面
			AppEnd tmp.fnv ffn --面法线
			AppEnd tmp.mid fmid --面材质ID
		)
		append ret tmp
	)
	return ret
)
fn filecom path1 path2 = ( -- 文件比较 路径1 路径2
	if doesFileExist path1 == false and doesFileExist path2 == false then(
		return -1 --文件不存在
	)
	tex1 = fopen path1 "rb"
	tex2 = fopen path2 "rb"
	fseek tex1 0 #seek_end
	len1 = ftell tex1
	fseek tex2 0 #seek_end
	len2 = ftell tex2
	if len1 != len2 then(
		fclose tex1
		fclose tex2
		return 0 --不同
	)

	fseek tex1 0 #seek_set
	fseek tex2 0 #seek_set
	tlen = ftell tex1
	while (tlen != len1) do (
		b1 = ReadByte tex1
		b2 = ReadByte tex2
		tlen = ftell tex1
		if b1 != b2 then(
			fclose tex1
			fclose tex2
			return 0 --不同
			--exit
		)
	)
	
	fclose tex1
	fclose tex2
	return 1 --相同
)
fn settex obj tex_ =( -- 对象 改名数组[i][1原名,2新名,3有没有复制成功]
	m = obj.material --取材质
	--format "对象：%\n" obj.name
	mtype = classof m
	case mtype of (
		Standardmaterial:(--单材质
			--format "原贴图：%\n" m.diffuseMap.filename
			for i = 1 to tex_.count do(
				if m.diffuseMap.filename == tex_[i][1] then(
					if tex_[i][3] == false then (return 0)
					m.diffuseMap.filename = tex_[i][2]
					--format "贴图：id:%, %，%，%, %\n" 1 m.diffuseMap.filename tex_[i][1] tex_[i][2] tex_[i][3]
					return 1
				)
			)
			return 0
		)
		PhysicalMaterial:(/*物理材质*/
			--format "原贴图：%\n" m.base_color_map.filename
			for i = 1 to tex_.count do(
				if m.base_color_map.filename == tex_[i][1] then(
					if tex_[i][3] == false then (return 0)
					m.base_color_map.filename = tex_[i][2]
					--format "贴图：id:%, %，%，%\n" 1 m.base_color_map.filename tex_[i][1] tex_[i][2]
					return 1
				)
			)
			return 0
		)/*物理材质*/
		Multimaterial:(/*多维材质*/
			for j = 1 to m.numsubs do (
				mu = m.materialList[j]
				mtype = classof mu 
				case mtype of (
					Standardmaterial:(
						--format "原贴图：%\n" mu.diffuseMap.filename
						for i = 1 to tex_.count do(
							if mu.diffuseMap.filename == tex_[i][1] then(
								if tex_[i][3] then(
									mu.diffuseMap.filename = tex_[i][2]
									--format "贴图：id:%, %，%，%\n" j mu.diffuseMap.filename tex_[i][1] tex_[i][2]
								)
							)
						)							
					)
					PhysicalMaterial:(
						--format "原贴图：%\n" mu.base_color_map.filename
						for i = 1 to tex_.count do(
							if mu.base_color_map.filename == tex_[i][1] then(
								if tex_[i][3] then(
									mu.base_color_map.filename = tex_[i][2]
									--format "贴图：id:%, %，%，%\n" j mu.base_color_map.filename tex_[i][1] tex_[i][2]
								)
							)
						)
					)
					default:(
						return 0
						--format "多维未知类型\n"
					)
				)
			)
		)/*多维材质*/
		NoMaterial:(--无
			--format "无材质\n"
			return 0
		)
		default:(
			--format "未知类型\n"
			return 0	
		)
	)
	return 2
)
fn gettex obj=(
	ret = #()
	m = obj.material --取材质
	mtype = classof m
	case mtype of (
		Standardmaterial:(--单材质
			tmp = GET_Tex()
			tmp.obj = obj
			tmp.mat = m
			tmp.cls = 1
			tmp.mid = 1
			tmp.tex = m.diffuseMap.filename
			tmp.path = getFilenamePath tmp.tex
			tmp.tname = filenameFromPath tmp.tex
			append ret tmp
		)
		PhysicalMaterial:(/*物理材质*/
			tmp = GET_Tex()
			tmp.obj = obj
			tmp.mat = m
			tmp.cls = 2
			tmp.mid = 1
			tmp.tex = m.base_color_map.filename
			tmp.path = getFilenamePath tmp.tex
			tmp.tname = filenameFromPath tmp.tex
			append ret tmp
		)/*物理材质*/
		Multimaterial:(/*多维材质*/
			for j = 1 to m.numsubs do (
				mu = m.materialList[j]
				mtype = classof mu 
				case mtype of (
					Standardmaterial:(
						tmp = GET_Tex()
						tmp.obj = obj
						tmp.mat = mu
						tmp.cls = 3
						tmp.mid = j
						tmp.tex = mu.diffuseMap.filename
						tmp.path = getFilenamePath tmp.tex
						tmp.tname = filenameFromPath tmp.tex
						append ret tmp						
					)
					PhysicalMaterial:(
						tmp = GET_Tex()
						tmp.obj = obj
						tmp.mat = mu
						tmp.cls = 4
						tmp.mid = j
						tmp.tex = mu.base_color_map.filename
						tmp.path = getFilenamePath tmp.tex
						tmp.tname = filenameFromPath tmp.tex
						append ret tmp
					)
					default:(
					)
				)
			)
		)/*多维材质*/
		NoMaterial:(--无
		)
		default:(	
		)
	)
	return ret
)

rollout param1 "整理" width:360 height:306
(
	groupBox 'grp1' "模型改名" pos:[3,10] width:342 height:65 align:#left
	groupBox 'grp2' "贴图整理" pos:[3,83] width:342 height:145 enabled:true align:#left
	button 'btn1' "执行" pos:[255,34] width:79 height:25 align:#left
	--checkbox 'chk1' "选择无法导出的对象并移动到父对象(如果有)" pos:[27,64] width:252 height:14 align:#left
	--checkbox 'chk2' "按规则重命名选择对象" pos:[27,64] width:192 height:16 align:#left
	editText 'edt1' "" pos:[63,37] width:140 height:20 align:#left
	label 'lbl1' "前缀：" pos:[23,41] width:40 height:16 align:#left
	label 'lbl3' "路径" pos:[9,114] width:40 height:16 align:#left
	editText 'edt2' "" pos:[32,110] width:231 height:22 align:#left
	label 'lbl4' "前缀" pos:[9,143] width:40 height:16 align:#left
	editText 'edt3' "" pos:[32,139] width:146 height:21 align:#left
	checkbox 'chk4' "重命名并复制到路径(如果有)" pos:[35,166] width:190 height:18 align:#left
	checkbox 'chk5' "修改材质中的贴图路径" pos:[35,186] width:190 height:18 align:#left
	button 'btn2' "选择" pos:[274,110] width:51 height:21 enabled:true toolTip:"" align:#left
	label 'lbl2' "名字=前缀_编号" pos:[180,143] width:107 height:22 align:#left
	button 'btn3' "复制" pos:[260,198] width:79 height:25 align:#left

	on btn1 pressed  do(
		--选择
		out=#()
		out = getCurrentSelection() --获取选择对象
		if out.count == 0 then (
			if ((queryBox ("没有选择对象！\n\n是否全选！")) !=false )then (
				max select all
				out = getCurrentSelection() --获取选择对象
			)
		)
		/*
		if edt1.text.count and chk1.checked then(
			if getNodeByName edt1.text == undefined then(
				_par = Dummy length:0.2 width:0.2 height:0.2;
				_par.boxsize  = [0.8,0.8,0.8]
				_par.name = edt1.text;
			)
		)
		*/
		--_err = #() --报错的模型
		tmpobj = outcls out
		_obj = #()
		join _obj tmpobj[1]
		join _obj tmpobj[2]
		for i = 1 to _obj.count do(
			/*
			if chk1.checked then(
				if canConvertTo _obj[i] Mesh then(
					try (
						for j = 1 to _obj[i].numverts do (--顶点
							getVert _obj[i] j -- 取得一个顶点
							GetTVert _obj[i] j -- 取得纹理坐标
							getNormal _obj[i] j --顶点法线
						)
						for j = 1 to _obj[i].numfaces do (--/--*面*--/
							getFace _obj[i] j --面
							getFaceNormal _obj[i] j --面法线
							getFaceMatID _obj[i] j --面材质ID	
						)
					) catch (
						if edt1.text.count then(
							_obj[i].parent = getNodeByName edt1.text
						)
						append _err _obj[i]
					)
				)
			)
			*/
			--if chk2.checked then(
				if edt1.text.count then(
					_obj[i].name = edt1.text + "_" + i as string
				)else(
					MessageBox("请输入改名前缀!") title:"提示!" beep:false
					exit
				)
			--)
		)
		/*
		if _err.count then(
			select _err
			MessageBox("已选中错误对象！请尝试导出选定对象为3ds后导入以解决错误！\n\n如果导出3ds时提示贴图名字不合规，请先修改贴图名字！") title:"提示!" beep:false
		)else if chk1.checked then(
			MessageBox("执行完成!没有错误对象！") title:"提示!" beep:false
		)
		*/
	)
	on btn2 pressed  do(
		_dir = getSavePath caption:"选择贴图保存路径" initialDir:maxFilePath
		if _dir != undefined then(
			edt2.text = _dir
		)
	)
	on btn3 pressed  do(
		--选择
		if edt2.text.count == 0 then(
			MessageBox("请先选择路径！") title:"提示!" beep:false
			return -1
		)
		if chk4.checked then(
			if edt3.text.count == 0 then(
				MessageBox("请输入前缀！") title:"提示!" beep:false
				return -1
			)
		)
		if ((queryBox ("复制路径请选择空文件夹！否则排查重复文件会消耗大量时间！\n\n是否开始复制贴图？")) == false )then (
			return -1
		)
		out=#()
		out = getCurrentSelection() --获取选择对象
		if out.count == 0 then (
			if ((queryBox ("没有选择对象！\n\n是否全选！")) !=false )then (
				max select all
				out = getCurrentSelection() --获取选择对象
			)
		)
		coptex = #()
		for i = 1 to out.count do(--取所有材质
			cop = gettex out[i]
			if cop == undefined then( continue )
			if cop.count then(
				for j = 1 to cop.count do(
					if cop[j] == undefined then( continue )
					append coptex cop[j]
				)
			)
		)
		--format "数量：%\n" coptex.count
		--整理材质
		zltex = #()
		for i = 1 to coptex.count do(
			if coptex[i] != undefined then(
				cmgo = 1
				for j = 1 to zltex.count do(
					if zltex[j].tex == coptex[i].tex then(
						cmgo = 0
						exit
					)
				)
				if cmgo then(
					append zltex coptex[i]
					--format "%\n" coptex[i]
				)
			)
		)
		/*
		for i = 1 to zltex.count do(
			format "%\n" zltex[i]
		)
		return -1
		*/
		--开始复制
		coptmp = #() --寄存复制信息
		path = edt2.text
		for i = 1 to zltex.count do(
			tex = zltex[i].tex
			if doesFileExist tex == false then(
				if _path == undefined then(
					_path = zltex[i].path --路径
				)
				if _path == "" then (
					_path = maxFilePath
				)
				--format "%\n" _path
				while ((doesFileExist (_path + zltex[i].tname)) == false) do (
					msg = yesNoCancelBox ("没有找到“" + zltex[i].tname + "”文件！\n\n是否手动指定贴图路径？") title:"提示!" beep:false;
					case msg of (
						#yes:(
							_dir = getSavePath caption:"选择贴图路径" initialDir:maxFilePath
							if _dir != undefined then(
								_path = _dir + "\\"
							)
						)
						#no:(
							tmp = #()
							append tmp zltex[i].tex
							append tmp "错误"
							append tmp false
							append coptmp tmp
							exit --跳过
						)
						default:(
							return -1 --取消
						)
					)
				)
			)else(
				_path = zltex[i].path
			)
			if chk4.checked and edt3.text.count then (--判断文件名规则
				textyp = getFilenameType zltex[i].tex --后缀
				texname = filenameFromPath zltex[i].tex --名字
				--textex = getFilenameFile tex--前缀		
				nname = edt3.text
				tmpname = nname + "_" + i as string
				cop = copyFile (_path + texname) (path + "\\" + tmpname + textyp)
				/*
				tmpname = nname + "_1"
				cop = copyFile (_path + texname) (path + "\\" + tmpname + textyp)
				if cop == false then(
					i = 1
					tmpname = nname + "_" + i as string
					while (doesFileExist (path + "\\" + tmpname + textyp)) do (
						i += 1
						tmpname = nname + "_" + i as string
					)
					nname = tmpname
					cop = copyFile (_path + texname) (path + "\\" + nname + textyp)
				)*/
				nname = tmpname
				tmp = #()
				append tmp zltex[i].tex
				append tmp (path + "\\" + nname + textyp)
				append tmp cop
				append coptmp tmp
			)else(
				texname = filenameFromPath zltex[i].tex --名字
				textyp = getFilenameType zltex[i].tex --后缀
				textex = getFilenameFile zltex[i].tex--前缀		
				cop = copyFile (_path + texname) (path + "\\" + texname)
				if cop == false then(
					if doesFileExist (_path + texname) and doesFileExist (path + "\\" + texname) then(
						--format "是否相同：%\n" (filecom (_path + texname) (path + "\\" + texname))
						if (filecom (_path + texname) (path + "\\" + texname)) == 0 then(
							i = 0
							tmptextex = textex
							while (doesFileExist (path + "\\" + tmptextex + textyp)) do (
								i += 1
								tmptextex = textex + "_" + i as string
							)
							textex = tmptextex
							cop = copyFile (_path + texname) (path + "\\" + textex + textyp)	
						)else(
							cop = true
						)
					)else(
						cop = false
					)
				)
				tmp = #()
				append tmp zltex[i].tex
				append tmp (path + "\\" + textex + textyp)
				append tmp cop
				append coptmp tmp
			)
		)
		--统计成功失败
		texok = 0
		texno = 0
		for i = 1 to coptmp.count do(
			if coptmp[i][3] then(
				texok += 1
			)else(
				texno += 1
			)
		)
		--format "数量：%\n" coptmp.count
		if chk5.checked == false then( -- 不修改贴图时直接结束
			MessageBox("贴图文件复制完成！(成功" + texok as string + "，失败" + texno as string + ")") title:"提示!" beep:false
			return -1
		)
		--修改库贴图名

		for i = 1 to out.count do(
			settex out[i] coptmp
		)
		MessageBox("贴图文件复制和材质贴图修改完成！(成功" + texok as string + "，失败" + texno as string + ")") title:"提示!" beep:false
	)
	on chk4 changed state do(
		if chk4.checked == True then(
			chk5.Checked = True
		)
	)
	on chk5 changed state do(
		if chk5.checked == false then(
			chk4.Checked = false
		)
	)
	on param1 open  do(
		--MessageBox("打开啦!") title:"提示!"beep:false;

	)
	on param1 close  do(
		--MessageBox("关闭啦!") title:"提示!"beep:false;
	)
)
rollout param2 "辅助" width:360 height:270
(
	dropDownList 'ddl1' "辅助对象：" pos:[9,12] width:330 height:41 items:#("盟主出生点", "流星出生点", "蝴蝶出生点", "道具声明", "武器拖影") align:#left
	label 'lbl1' "数量：" pos:[9,63] width:42 height:25 align:#left
	editText 'edt1' "" text:"1" pos:[40,61] width:116 height:16 align:#left
	label 'lbl2' "位置：" pos:[9,83] width:42 height:25 align:#left
	editText 'edt2' "" text:"0 0 0" pos:[40,81] width:214 height:16 align:#left
	label 'lbl3' "间隔：" pos:[9,103] width:42 height:27 align:#left
	editText 'edt3' "" text:"0 0 0" pos:[40,101] width:214 height:16 align:#left
	button 'btn1' "生成" pos:[265,136] width:79 height:25 align:#left

	on btn1 pressed  do(
		_par = undefined
		_pos = [0,0,0] as Point3
		_jpos = [0,0,0] as Point3
		--format "%\n" (edt1.text as integer)
		if edt1.text.count == 0 or (edt1.text as integer) == undefined or (edt1.text as integer) < 1 then(
			MessageBox("请输入正确的数量！") title:"提示!" beep:false
			return -1
		)
		if edt2.text.count then(
			str = filterString  edt2.text " "--分割
			if str.count == 3 then(
				if str[1] as float != undefined then(
					_pos.x = str[1] as float
				)
				if str[2] as float != undefined then(
					_pos.y = str[2] as float
				)
				if str[3] as float != undefined then(
					_pos.z = str[3] as float
				)
			)
		)
		if edt3.text.count then(
			str = filterString  edt3.text " "--分割
			if str.count == 3 then(
				if str[1] as float != undefined then(
					_jpos.x = str[1] as float
				)
				if str[2] as float != undefined then(
					_jpos.y = str[2] as float
				)
				if str[3] as float != undefined then(
					_jpos.z = str[3] as float
				)
			)
		)
		
		case ddl1.selected of (
		"盟主出生点":(
			if getNodeByName "盟主出生点_1" != undefined then(
				i = 1
				parname = "盟主出生点_1"
				while (getNodeByName parname != undefined) do (
					i += 1
					parname = "盟主出生点_" + i as string
				)
				_par = Dummy length:1 width:1 height:1;
				--_par.boxsize  = [1,1,1]
				_par.name = parname;
			)else(
				_par = Dummy length:1 width:1 height:1;
				--_par.boxsize  = [1,1,1]
				_par.name = "盟主出生点_1";
			)
			--user01
			for i = 1 to edt1.text as integer do(
				_pos += _jpos
				_user = box length:40 width:40 height:40;
				if i < 10 then(
					_user.name = "user0" + i as string
					setUserProp _user "name" ("user0" + i as string)
				)else(
					_user.name = "user" + i as string
					setUserProp _user "name" ("user" + i as string)
				)
				_user.pos = _pos
				_user.parent = _par
			)
		)
		"流星出生点":(
			if getNodeByName "流星出生点_1" != undefined then(
				i = 1
				parname = "流星出生点_1"
				while (getNodeByName parname != undefined) do (
					i += 1
					parname = "流星出生点_" + i as string
				)
				_par = Dummy length:1 width:1 height:1;
				--_par.boxsize  = [1,1,1]
				_par.name = parname;
			)else(
				_par = Dummy length:1 width:1 height:1;
				--_par.boxsize  = [1,1,1]
				_par.name = "流星出生点_1";
			)
			--user01
			for i = 1 to edt1.text as integer do(
				_pos += _jpos
				_team = box length:40 width:40 height:40;
				if i < 10 then(
					_team.name = "teamA0" + i as string
					setUserProp _team "name" ("teamA0" + i as string)
				)else(
					_team.name = "teamA" + i as string
					setUserProp _team "name" ("teamA" + i as string)
				)
				_team.pos = _pos
				_team.parent = _par
			)			
		)
		"蝴蝶出生点":(
			if getNodeByName "蝴蝶出生点_1" != undefined then(
				i = 1
				parname = "蝴蝶出生点_1"
				while (getNodeByName parname != undefined) do (
					i += 1
					parname = "蝴蝶出生点_" + i as string
				)
				_par = Dummy length:1 width:1 height:1;
				--_par.boxsize  = [1,1,1]
				_par.name = parname;
			)else(
				_par = Dummy length:1 width:1 height:1;
				--_par.boxsize  = [1,1,1]
				_par.name = "蝴蝶出生点_1";
			)
			--team
			for i = 1 to edt1.text as integer do(
				_pos += _jpos
				_team = box length:40 width:40 height:40;
				if i < 10 then(
					_team.name = "teamB0" + i as string
					setUserProp _team "name" ("teamB0" + i as string)
				)else(
					_team.name = "teamB" + i as string
					setUserProp _team "name" ("teamB" + i as string)
				)
				_team.pos = _pos
				_team.parent = _par
			)			
		)
		"道具声明":(
			if getNodeByName "道具声明_1" != undefined then(
				i = 1
				parname = "道具声明_1"
				while (getNodeByName parname != undefined) do (
					i += 1
					parname = "道具声明_" + i as string
				)
				_par = Dummy length:1 width:1 height:1;
				--_par.boxsize  = [1,1,1]
				_par.name = parname;
			)else(
				_par = Dummy length:1 width:1 height:1;
				--_par.boxsize  = [1,1,1]
				_par.name = "道具声明_1";
			)
			--ddd
			for i = 1 to edt1.text as integer do(
				_pos += _jpos
				_ddd = box length:40 width:40 height:40;
				_ddd.name = "ddd" + i as string
				_ddd.pos = _pos
				_ddd.parent = _par
			)
		)
		"武器拖影":(
			if getNodeByName "武器拖影_1" != undefined then(
				i = 1
				parname = "武器拖影_1"
				while (getNodeByName parname != undefined) do (
					i += 1
					parname = "武器拖影_" + i as string
				)
				_par = Dummy length:1 width:1 height:1;
				--_par.boxsize  = [1,1,1]
				_par.name = parname;
			)else(
				_par = Dummy length:0.2 width:0.2 height:0.2;
				_par.boxsize  = [0.8,0.8,0.8]
				_par.name = "武器拖影_1";
			)
			--wpn
			_pos += _jpos
			_wpn = Dummy length:0.2 width:0.2 height:0.2;
			_wpn.boxsize  = [0.8,0.8,0.8]
			_wpn.name = "wpnRS"
			_wpn.pos = _pos
			_wpn.parent = _par

			_pos += _jpos
			_wpn = Dummy length:0.2 width:0.2 height:0.2;
			_wpn.boxsize  = [0.8,0.8,0.8]
			_wpn.name = "wpnRE"
			_wpn.pos = _pos
			_wpn.parent = _par
		)
		default:(body)
		)
	)
)
sel3 = undefined
rollout param3 "材质" width:360 height:270
(
	dropDownList 'ddl1' "通道：" pos:[9,11] width:330 height:41 items:Texturestr align:#left
	dropDownList 'ddl2' "混合：" pos:[9,59] width:330 height:41 items:blendstr align:#left
	checkbox 'chk1' "使用双面材质" pos:[9,171] width:250 height:20 align:#left
	slider 'sld1' "透明度" pos:[9,111] width:340 height:44 enabled:true range:[0,100,100] type:#float align:#left
	button 'btn1' "确认" pos:[265,196] width:79 height:25 align:#left
	timer 'tmr1' "Timer" pos:[16,206] width:24 height:24 enabled:true interval:500 active:true align:#left
	on tmr1 tick  do(
		sel = getCurrentSelection()
		if sel.count == 0 then(
			sel3 = undefined
		)
		if sel.count != 1 then(
			return -1
		)
		if sel3 != undefined then(
			if sel3 == sel[1] then(
				return -1
			)
		)
		--format "%\n" "1234567890"
		sel3 = sel[1]
		colt = getUserProp sel3 "Texture"
		two = getUserProp sel3 "TwoSide"
		ble = getUserProp sel3 "Blend"
		opa = getUserProp sel3 "Opaque"
		if colt != undefined then(
			--ddl1.selected = colt
			ddl1.selection = colt
		)else(
			ddl1.selection = 1
		)
		if ble != undefined then(
			--ddl2.selected = ble
			ddl2.selection = ble
		)else(
			ddl2.selection = 1
		)
		if two != undefined then(
			chk1.checked = two
		)else(
			chk1.checked = false
		)
		if opa != undefined then(
			val = ((opa as float) * 100) as integer
			sld1.value = val
		)else(
			sld1.value = 100
		)
	)
	on btn1 pressed  do(
		sel = getCurrentSelection()
		if sel.count == 0 then(
			MessageBox("请先选择修改对象!") title:"提示!"beep:false;
			return -1	
		)
		if sel.count > 1 then(
			if ((queryBox ("您当前选择了多个对象！\n是否确定批量修改？")) ==false )then (
				return -1
			)
		)
		for i = 1 to sel.count do(
			setUserProp sel[i] "Texture" ddl1.selection
			setUserProp sel[i] "TwoSide" (chk1.checked as integer)
			setUserProp sel[i] "Blend" ddl2.selection
			setUserProp sel[i] "Opaque" (sld1.value/100)
		)
	)
	on ddl1 selected sel do(
		if sel3 == undefined then(return -1)
		setUserProp sel3 "Texture" ddl1.selection
	)
	on ddl2 selected sel do(
		if sel3 == undefined then(return -1)
		setUserProp sel3 "Blend" ddl2.selection
	)
	on sld1 changed val do(
		if sel3 == undefined then(return -1)
		setUserProp sel3 "Opaque" (sld1.value/100)
	)
	on chk1 changed state do(
		if sel3 == undefined then(return -1)
		setUserProp sel3 "TwoSide" (chk1.checked as integer)
	)
)
sel4 = undefined
rollout param4 "属性" width:388 height:270
(
	listBox 'lbx1' "" pos:[9,6] width:330 height:11 enabled:true items:#() selection:1 align:#left
	dropDownList 'ddl1' "类型" pos:[9,160] width:330 height:41 items:#() align:#left
	label 'lbl1' "值：" pos:[10,205] width:42 height:27 align:#left
	editText 'tex1' "" pos:[7,222] width:330 height:21 align:#left --readOnly:true
	button btn1 "添加/修改" pos:[132,265] width:108 height:24 align:#left
	timer 'tmr1' "Timer" pos:[16,206] width:24 height:24 enabled:true interval:500 active:true align:#left
	on param4 open  do(
		attitems = #()
		for i = 1 to attcls[1].count do(
			append attitems (attcls[1][i] + ":" + attcls[2][i])
		)
		ddl1.items = attitems
	)
	on tmr1 tick  do(
		--format "%\n" (findItem attcls[1] "name")
		if sel3 == undefined then(
			return -1
		)
		if sel3 == sel4 then(
			return -1
		)
		sel4 = sel3
		attstr = getUserPropBuffer sel3
		lststr = filterString  attstr "\n"--分割
		list = #()
		for i = 1 to lststr.count do(
			if lststr[i] == undefined or lststr[i] == "" then (continue)
			tstr = filterString  lststr[i] " = "
			lid = findItem attcls[1] tstr[1]
			if lid != 0 then(
				append list lststr[i]
			)
		)
		lbx1.items = list
		--format "%\n" attstr
	)
	on ddl1 selected sel do(
		if sel3 == undefined then(
			return -1
		)
		lid = ddl1.selection
		val = getUserProp sel3 attcls[1][lid]
		if val != undefined then(
			tex1.text = val as string
		)else(
			tex1.text = attcls[3][lid]
		)
	)
	on lbx1 selected sel do
	(
		if sel3 == undefined then(
			return -1
		)
	    str = lbx1.Items[ lbx1.selection ]
		tstr = filterString  str " = "--分割
		lid = findItem attcls[1] tstr[1]
		if lid != 0 then(
			ddl1.selection = lid
			tex1.text = (getUserProp sel3 tstr[1]) as string
		)
	)
	on btn1 pressed  do(
		if sel3 == undefined then(
			return -1
		)
		did = ddl1.selection
		valstr = (filterString tex1.text ":")[1]
		if valstr == undefined or valstr.count == 0 then(--删除
			attstr = getUserPropBuffer sel3
			lststr = filterString  attstr "\n"--分割
			for i = 1 to lststr.count do(
				if lststr[i] == undefined or lststr[i] == "" then ( continue )
				tstr = filterString  lststr[i] " = "--分割
				if attcls[1][did] == tstr[1] then(
					deleteitem lststr i
				)
			)
			str = ""
			for i = 1 to lststr.count do(
				str += lststr[i] + "\n"
			)
			setUserPropBuffer sel3 str
			list = #()
			for i = 1 to lststr.count do(
				if lststr[i] == undefined or lststr[i] == "" then (continue)
				tstr = filterString  lststr[i] " = "
				lid = findItem attcls[1] tstr[1]
				if lid != 0 then(
					append list lststr[i]
				)
			)
			lbx1.items = list
		)else(
			setUserProp sel3 attcls[1][did] valstr
			attstr = getUserPropBuffer sel3
			lststr = filterString  attstr "\n"--分割
			list = #()
			for i = 1 to lststr.count do(
				if lststr[i] == undefined or lststr[i] == "" then (continue)
				tstr = filterString  lststr[i] " = "
				lid = findItem attcls[1] tstr[1]
				if lid != 0 then(
					append list lststr[i]
				)
			)
			lbx1.items = list
		)
		--lbx1.items = #((clsstr[1] + " = " + valstr[1]))
	)
)
rollout param5 "动画" width:360 height:170
(
    Edittext text1 "动画帧数：" text:"1" pos:[9,12] width:164 height:16
    Edittext text2 "这帧开始：" text:"0" pos:[9,32] width:164 height:16
    Edittext text3 "动画片段：" text:"" pos:[9,52] width:330 height:16
    label titleLabel2 "动画总帧数" pos:[185,12] width:240 height:16
    label titleLabel3 "动画在时间轴上的开始帧" pos:[185,32] width:320 height:16
    label titleLabel4 "注：动画动画片段，输入格式 “0-10 20-30 40-50”" pos:[9,82] width:330 height:16
)
rollout param6 "生成" width:360 height:270
(
	dropDownList 'ddl1' "快捷选择" pos:[9,9] width:330 height:41 align:#left items:#("地图","武器","道具","动画道具")
	groupBox 'grp1' "文件" pos:[9,61] width:330 height:112 align:#left
	button 'btn1' "生成" pos:[124,220] width:94 height:32 align:#left
	checkbox 'gmc' "*.gmc" pos:[22,84] width:120 height:14 align:#left checked:true
	checkbox 'pst' "*.pst" pos:[22,100] width:120 height:14 align:#left checked:true
	checkbox 'fmc' "*.fmc" pos:[22,116] width:120 height:14 align:#left
	checkbox 'pos' "*.pos" pos:[22,132] width:120 height:14 align:#left
	checkbox 'des' "*.des" pos:[160,84] width:120 height:14 align:#left checked:true
	checkbox 'tem' "包含出生点" pos:[180,100] width:120 height:14 align:#left checked:true
	checkbox 'ddd' "包含道具" pos:[180,116] width:120 height:14 align:#left checked:true
	checkbox 'wpn' "包含武器拖影" pos:[180,132] width:121 height:14 align:#left
	checkbox 'tga' "将DDS\\PSD\\PNG后缀改成TGA (注意：图片格式需要手动转换)" pos:[9,180] width:330 height:14 align:#left checked:true

	on btn1 pressed  do(
		if gmc.checked or pst.checked or fmc.checked or pos.checked or des.checked then(
			out = getCurrentSelection()
			if out.count == 0 then(
				MessageBox("请选择导出对象！") title:"提示!" beep:false
				return -1
			)
			--开始导出
			out_path = getSaveFileName types:"All (*.*)|*.*|" caption:"保存文件"
			/*判断保存文件的名称*/
			if out_path == undefine then(
				--MessageBox("警告:不能取得保存文件的名称,无法导出!") title:"警告!" beep:false;
				return -1
			)
			out_name = getFilenameFile out_path --寄存导出名字
			out_dir	= getFilenamePath out_path --路径

			_obj = outcls out --分类

			tmpobj = #()
			join tmpobj _obj[1]
			join tmpobj _obj[2]
			/*
			for i = 1 to tmpobj.count do(
				try (
					for j = 1 to tmpobj[i].numverts do (--顶点
						getVert tmpobj[i] j -- 取得一个顶点
						GetTVert tmpobj[i] j -- 取得纹理坐标
						getNormal tmpobj[i] j --顶点法线
					)
					for j = 1 to tmpobj[i].numfaces do (--面
						getFace tmpobj[i] j --面
						getFaceNormal tmpobj[i] j --面法线
						getFaceMatID tmpobj[i] j --面材质ID	
					)
				) catch (
					MessageBox("选择对象中存在不能导出的对象！请在“整理”中整理模型！") title:"警告!" beep:false;
					return -1
				)
			)
			*/

			if gmc.checked then(
				_tex = getouttex _obj[1] --取贴图
				_mat = getoutmat _obj[1] --取材质 与id
				_dat = getoutdat _obj[1] --取纹理顶点数据
				_atdat = getoutdat _obj[2] --取包围盒数据
				_txt = (togmc _tex _mat _dat _atdat tga.checked) as string

				out_gmc = out_dir + out_name + ".gmc"
				out_file = createfile out_gmc /*创建输出文件*/
				format "%" _txt to:out_file
				close out_file
			)
			if des.checked then(
				_txt = (todes _obj tem.checked ddd.checked wpn.checked) as string

				out_des = out_dir + out_name + ".des"
				out_file = createfile out_des /*创建输出文件*/
				format "%" _txt to:out_file
				close out_file
			)
			if pst.checked then(
				_txt = (topst _obj[6] out_name) as string

				out_pst = out_dir + out_name + ".pst"
				out_file = createfile out_pst /*创建输出文件*/
				format "%" _txt to:out_file
				close out_file
			)
			if fmc.checked then(
				tobj = #()
				join tobj _obj[1]
				join tobj _obj[2]
				start = 0
				num = 0
				if param5.text2.text.count != 0 and (param5.text2.text as integer) != undefined then(
					start = param5.text2.text as integer
				)
				if param5.text1.text.count != 0 and (param5.text1.text as integer) != undefined then(
					num = param5.text1.text as integer
				)
				_txt = (tofmc tobj start num) as string

				out_fmc = out_dir + out_name + ".fmc"
				out_file = createfile out_fmc /*创建输出文件*/
				format "%" _txt to:out_file
				close out_file
			)
			if pos.checked then(
				num = 0
				str = param5.text3.text
				if param5.text1.text.count != 0 and (param5.text1.text as integer) != undefined then(
					num = param5.text1.text as integer
				)
				_txt = (topos str num) as string

				out_pos = out_dir + out_name + ".pos"
				out_file = createfile out_pos /*创建输出文件*/
				format "%" _txt to:out_file
				close out_file
			)
			MessageBox("生成成功！") title:"提示!" beep:false

		)else(
			MessageBox("请选择导出文件类型！") title:"提示!" beep:false
		)
	)
	on ddl1 selected sel do(
		case ddl1.selection of (
			1:(
				gmc.checked = true
				pst.checked = true
				des.checked = true
				tem.checked = true
				ddd.checked = true
				fmc.checked = false
				pos.checked = false
				wpn.checked = false
			)
			2:(
				gmc.checked = true
				pst.checked = false
				des.checked = true
				tem.checked = false
				ddd.checked = false
				fmc.checked = false
				pos.checked = false
				wpn.checked = true
			)
			3:(
				gmc.checked = true
				pst.checked = false
				des.checked = true
				tem.checked = false
				ddd.checked = false
				fmc.checked = false
				pos.checked = false
				wpn.checked = false
			)
			4:(
				gmc.checked = true
				pst.checked = false
				des.checked = true
				tem.checked = false
				ddd.checked = false
				fmc.checked = true
				pos.checked = true
				wpn.checked = false
			)
		)
	)
)
rollout param7 "关于" width:360 height:270
(
	label titleLabel1 "资料：" pos:[9,10] width:240 height:16
	HyperLink add1 "道具资料表" pos:[180,30] width:160 height:16 address:"https://www.lxres.com/LiuXingBiJi/1555.html" color:(color 94 234 255) hovercolor:(color 255 0 0)
	HyperLink add2 "地图属性表" pos:[19,50] width:160 height:16 address:"https://www.lxres.com/LiuXingBiJi/1561.html" color:(color 94 234 255) hovercolor:(color 255 0 0)
	HyperLink add3 "地图场景表" pos:[19,30] width:160 height:16 address:"https://www.lxres.com/LiuXingBiJi/1558.html" color:(color 94 234 255) hovercolor:(color 255 0 0)
	HyperLink add4 "地图脚本基础" pos:[19,70] width:160 height:16 address:"https://www.lxres.com/LiuXingBiJi/1776.html" color:(color 94 234 255) hovercolor:(color 255 0 0)
	HyperLink add5 "武器资料表" pos:[180,50] width:160 height:16 address:"https://www.lxres.com/LiuXingBiJi/1557.html" color:(color 94 234 255) hovercolor:(color 255 0 0)
	HyperLink add6 "特效资料表" pos:[180,70] width:160 height:16 address:"https://www.lxres.com/LiuXingBiJi/1556.html" color:(color 94 234 255) hovercolor:(color 255 0 0)
	label titleLabel2 "教程：" pos:[9,100] width:240 height:16
	HyperLink add7 "地图制作教程图文版     -- 滴风" pos:[19,120] width:330 height:16 address:"https://www.lxres.com/LiuXingBiJi/1553.html" color:(color 94 234 255) hovercolor:(color 255 0 0)
	HyperLink add8 "地图制作常见问题和技巧 -- 过山河。" pos:[19,140] width:330 height:16 address:"https://www.lxres.com/LiuXingBiJi/2192.html" color:(color 94 234 255) hovercolor:(color 255 0 0)
	HyperLink add9 "流星蝴蝶剑武器制作教程 -- 漠之北" pos:[19,160] width:330 height:16 address:"https://www.lxres.com/LiuXingBiJi/1948.html" color:(color 94 234 255) hovercolor:(color 255 0 0)
	HyperLink add0 "访问流星资源网 (To Lxres.com)" pos:[9,400] width:240 height:16 address:"www.lxres.com" color:(color 94 234 255) hovercolor:(color 255 0 0)
	label titleLabel3 "by 漠之北" pos:[286,400] width:60 height:16
)

if floater != undefined do
(
closerolloutfloater floater
)
floater = newrolloutfloater "流星模型导出 v0.81(测试版)" 360 440
addrollout param1 floater rolledUp:true
addrollout param2 floater rolledUp:true
addrollout param3 floater rolledUp:true
addrollout param4 floater rolledUp:true
addrollout param5 floater rolledUp:true
addrollout param6 floater rolledUp:false
addrollout param7 floater rolledUp:true
--removeRollout param5
--addrollout param6 floater

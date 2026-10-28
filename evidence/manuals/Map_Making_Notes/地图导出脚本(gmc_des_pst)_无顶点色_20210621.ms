--	************************************************************************
--	!!! 此版用于导出 [流星地图模型（gmc），描述（des)，声明（pst)等多个文件]  
--
--	流星地图模型导出脚本 	v0.1
--	作者: yish
--  二修: 滴风
--  三修: 漠之北
--	日期:   2011-04-05
--  二修:   2012-11-16
--  三修:   2016-06-30
--	四修：	2021-06-21
--	************************************************************************
--	简介:	导出 [流星地图模型（gmc），描述（des)，声明（pst)等多个文件]  
--  修正:可正确导出材质和顶点颜色
--	修改：免导出3ds、免添加【顶点绘制】修改器、直接一步导出。
--  备注:整理好场景后,先导出为3DS格式(主要是为了整理法线),再重新导入3DS,此时,必须为每个模型添加"顶点绘制"修改器,再用此脚本才能正确导出.
--	环境:	3DSMAX2009
--	/////////////////////////////////////////////////////////
--	//	BUG:
--	//	** 
--	/////////////////////////////////////////////////////////
--	更新记录:
--	-2011-04-051-----------------------------------------------------------
--	版本	0.1
--	增加:		1,初步完成导出数据
--
--	待做:
--			无
--	************************************************************************

-- beAutoNamed = false	--!!!是否打开自动命名？		会在每个对象原来的名字后加  "S01"（数值递增）,如原名为 "box01",则改为 "box01S01"	通常不启用
--=========================
scenceObjCount = 0	--	场景对象总数
dummyObjCount =	0	--	辅助对象总数
exportObjList =#()	--	导出文件列表
exportName =""		--	用户所起的导出文件名，在第一步导出gmc时指定，以后2步自动记忆


struct	LX_Tex(
	tex,	col,	amb,	dif, 	spe,	emi,	opacity,	option,		twoside
)
lxTexs=	 #()
--=========================

if ((queryBox "导出规则: \n 1 要导出的对象必须全部是【可编辑网格类型】\n 2 必须有纹理坐标 \n  \n\n 备注:选择要导出的模型，无需添加任何修改器即可一次导出。\r\n" title:"流星地图模型导出脚本" beep:false) ==false )
	then return false
	
	

--	==================================================================================================
--																		导出 Des 道具声明
--	==================================================================================================

	
--////////////////////////////////////////////////////////////////////////////////////
	fn	ExportDes 	objList	=(
	
--	out_name = getSaveFileName 	filename:exportName		 types:"流星道具声明*.des (*.des)|*.des" caption:"导出des文件"

	out_name = exportName + ".des"
	if out_name == undefine then 
		(MessageBox("警告:不能取得保存文件的名称,无法导出!") title:"警告!" beep:false;return false)
	
	out_file =  createfile 		out_name
	
--	====================== 开始导出 des	声明 ================================	
	
	format "	*******	调试输出	 步骤=%	,	%\n" 		"创建 des 输出文件"	out_name
 
	format "# GModel Description File V1.0\n"		to:out_file	
	format "# Des for lxres.com\n"		time()  	to:out_file	
	

	format "SceneObjects % DummeyObjects %\n"		scenceObjCount		(dummyObjCount+6)		to:out_file	
/*
	frameCount = ((animationRange.end - animationRange.start) as integer) / 160
	format "FPS % Frames % Mode: %\n"		frameRate		frameCount		"RIGID"		to:out_file	
*/	
	
	for  i = 1  to  objList.count do
	(
/*
Object Object07
{
  Position: 13.121 -4.328 13.278
  Quaternion: -1.000 0.000 0.000 0.000
  TextureAnimation: 0 0.000 0.000
  Custom:
  {
  }
}
*/
		format "Object %\n"		objList[i].name  	to:out_file	
		format "{\n"								to:out_file	
			pos = objList[i].pos
			rot = objList[i].rotation		--	流星四元序是 w,x,y,z  		max是 x,y,z,w
		format "  Position: % % %\n"			pos.x	pos.y	pos.z	  		to:out_file	
		format "  Quaternion: % % % %\n"		rot.w	rot.x	rot.y	rot.z	  	to:out_file	
		format "  TextureAnimation: % % %\n"	0	0	0	  	to:out_file
		
		format "  Custom:\n"		 	 	to:out_file
			format "  {\n"		  			to:out_file
			format "  }\n"		  			to:out_file
		
		format "}\n"								to:out_file	
	)
	
	format "Object D_user01\n"		                        to:out_file	
	format "{\n"		                                    to:out_file	
	format "  Position: 0.000 0.000 20.000 \n"		        to:out_file	
	format "  Quaternion: -1.000 0.000 0.000 0.000 \n"		to:out_file	
	format "  TextureAnimation: 0 0.000 0.000\n"		    to:out_file	
	format "  Custom:\n"		                            to:out_file	
	format "  {\n"		                                    to:out_file	
	format "    name=\"user01\"\n"	         to:out_file	
	format "  }\n"		                                    to:out_file	
	format "}\n"		                                    to:out_file	
	format "Object D_teamA01\n"		                        to:out_file	
	format "{\n"		                                    to:out_file	
	format "  Position: 0.000 0.000 20.000\n"		        to:out_file	
	format "  Quaternion: -1.000 0.000 0.000 0.000\n"		to:out_file	
	format "  TextureAnimation: 0 0.000 0.000\n"		    to:out_file	
	format "  Custom:\n"		                            to:out_file	
	format "  {\n"		                                    to:out_file	
	format "    name=\"teamA01\"\n"	      to:out_file	
	format "  }\n"		                                    to:out_file	
	format "}\n"		                                    to:out_file	
	format "Object D_teamB01\n"		                        to:out_file	
	format "{\n"		                                    to:out_file	
	format "  Position: 0.000 0.000 20.000\n"		        to:out_file	
	format "  Quaternion: -1.000 0.000 0.000 0.000\n"		to:out_file	
	format "  TextureAnimation: 0 0.000 0.000\n"		    to:out_file	
	format "  Custom:\n"		                            to:out_file	
	format "  {\n"		                                    to:out_file	
	format "    model=\"teamB01\"\n"	 to:out_file	
	format "  }\n"		                                    to:out_file	
	format "}\n"		                                    to:out_file	
	format "Object D_wp01\n"		                        to:out_file	
	format "{\n"		                                    to:out_file	
	format "  Position: 0.000 0.000 -10000.000\n"		    to:out_file	
	format "  Quaternion: -1.000 0.000 0.000 0.000\n"		to:out_file	
	format "  TextureAnimation: 0 0.000 0.000\n"		    to:out_file	
	format "  Custom:\n"		                            to:out_file	
	format "  {\n"		                                    to:out_file	
	format "    model=\"W0_0\"\n"		                        to:out_file	
	format "  }\n"		                                    to:out_file	
	format "}\n"		                                    to:out_file	
	format "Object D_Item01\n"		                        to:out_file	
	format "{\n"		                                    to:out_file	
	format "  Position: 0.000 0.000 -10000.000\n"		    to:out_file	
	format "  Quaternion: -1.000 0.000 0.000 0.000\n"		to:out_file	
	format "  TextureAnimation: 0 0.000 0.000\n"		    to:out_file	
	format "  Custom:\n"		                            to:out_file	
	format "  {\n"		                                    to:out_file	
	format "    model=\"Item01\"\n"		                        to:out_file
	format "    ticket=6\n"		                        to:out_file	
	format "  }\n"		                                    to:out_file	
	format "}\n"		                                    to:out_file	
	format "Object D_SSWind01\n"		                        to:out_file	
	format "{\n"		                                    to:out_file	
	format "  Position: 0.000 0.000 -10000.000\n"		    to:out_file	
	format "  Quaternion: -1.000 0.000 0.000 0.000\n"		to:out_file	
	format "  TextureAnimation: 0 0.000 0.000\n"		    to:out_file	
	format "  Custom:\n"		                            to:out_file	
	format "  {\n"		                                    to:out_file	
	format "    effect=\"SSWind01\"\n"		                        to:out_file
	format "  }\n"		                                    to:out_file	
	format "}\n"		                                    to:out_file	

--		animationRange.start	or	.end
	
	close out_file
--	MessageBox("Des 完成导出!") title:"完成!" beep:false

)

--	==================================================================================================
--																			导出 Pst DES声明
--	==================================================================================================

	
--////////////////////////////////////////////////////////////////////////////////////
	fn	ExportPst 	objList	=(
	
--	out_name = getSaveFileName 	filename:exportName		 types:"流星DES声明*.pst (*.pst)|*.pst" caption:"导出pst文件"

	out_name = exportName + ".pst"
	
	if out_name == undefine then 
		(MessageBox("警告:不能取得保存文件的名称,无法导出!") title:"警告!" beep:false;return false)
	
	out_file =  createfile 		out_name
	
--	====================== 开始导出 pst	声明 ================================	
	
	format "	*******	调试输出	 步骤=%	,	%\n" 		"创建 pst 输出文件"	out_name
 
	format "/*\n\n"		to:out_file	
	format "	PScript for lxres.com\n\n"  	to:out_file	
	format "*/\n\n"		to:out_file	

	format "#include \"..\PScriptLib\Def.h\"\n\n"	to:out_file	

	format "#include \"..\PScriptLib\box.pst\"\n"	to:out_file	
	format "#include \"..\PScriptLib\desk.pst\"\n"	to:out_file	
	format "#include \"..\PScriptLib\chair.pst\"\n"	to:out_file	
	format "#include \"..\PScriptLib\jug.pst\"\n\n"	to:out_file

	format "Scene_OnInit()\n"	to:out_file	
	format "{\n"	to:out_file	
	format "	InitBoxes(g_iNumBoxes);\n"	to:out_file	
	format "	InitBBoxes(g_iNumBBoxes);\n"	to:out_file	
	format "	InitChairs(g_iNumChairs);\n"	to:out_file	
	format "	InitDeskes(g_iNumDeskes);\n"	to:out_file	
	format "	InitJugs(g_iNumJugs);\n"	to:out_file	
	format "}\n"	to:out_file	

	
--		animationRange.start	or	.end
	
	close out_file
--	MessageBox("Pst 完成导出!") title:"完成!" beep:false

)

	
--	==================================================================================================
--																				取所有材质
--	==================================================================================================
--==================材质知识==================
-- max中 只有一个材质时 【classof  $.material 】  类型为Standardmaterial， 2个以上时为 Multimaterial
-- $.material.numsubs 数量
-- $.material.materialList[1].diffuseMap.filename   输出贴图文件名


fn getAllTexName   m =(
	

	mtype = classof  m
	format "	*******	调试输出	 步骤=%	,	%\n"		"开始读取材质类型　==" 	  mtype
	if	mtype == Standardmaterial	then 
	(	
		aTex = LX_Tex()
		if m.diffuseMap != undefined then
		(
			aTex.tex	=	m.diffuseMap.filename
		)
		else
		(
			aTex.tex	=	m.name
		)
		aTex.col	=	m.filterColor	--Color default: (color 127.5 127.5 127.5) -- animatable, alias: Filter_Color,The color transmitted through transparent or semi-transparent materials such as glass. 


		aTex.amb	=	m.ambient 	 	/	255.0		--Color default: (color 149.94 149.94 149.94) 	-- animatable; RGB color; Ambient_Color
		aTex.dif	=	m.diffuse 		/	255.0		--Color default: (color 149.94 149.94 149.94) 	-- animatable, alias: Diffuse_Color
		aTex.spe	=	m.specular 		/	255.0		--Color default: (color 229.5 229.5 229.5) 	-- animatable; Specular_Color
		aTex.emi	=	m.selfIllumColor	/	255.0	--自发光 <Standard>.selfIllumColor Color default: (color 0 0 0) -- animatable; Self_Illum_Color

		aTex.opacity	=	m.opacity 	/	100.0		--Float default: 100.0 -- animatable; percentage
		--aTex.option		=	m.opacity	--<Standard>.opacity Float default: 100.0 -- animatable, percentage
		aTex.twoside	=	m.twoSided		--Boolean default: false -- alias: Two_sided
		cunzai=0
		for	tmpidx =1 to lxTexs.count do
		(
			if lxTexs[tmpidx].tex == aTex.tex then
			(
				cunzai=1
				exit
			)
		)
		if cunzai==0 then
			append	lxTexs		aTex
	)else(
		
		for i = 1 to m.numsubs do
		(
			aTex = LX_Tex()
			aTex.tex	=	m.materialList[i].diffuseMap.filename
			aTex.col	=	m.materialList[i].filterColor	--Color default: (color 127.5 127.5 127.5) -- animatable, alias: Filter_Color,The color transmitted through transparent or semi-transparent materials such as glass. 


			aTex.amb	=	m.materialList[i].ambient 	 	/	255.0		--Color default: (color 149.94 149.94 149.94) 	-- animatable; RGB color; Ambient_Color
			aTex.dif	=	m.materialList[i].diffuse 		/	255.0		--Color default: (color 149.94 149.94 149.94) 	-- animatable, alias: Diffuse_Color
			aTex.spe	=	m.materialList[i].specular 		/	255.0		--Color default: (color 229.5 229.5 229.5) 	-- animatable; Specular_Color
			aTex.emi	=	m.materialList[i].selfIllumColor	/	255.0	--自发光 <Standard>.selfIllumColor Color default: (color 0 0 0) -- animatable; Self_Illum_Color

			aTex.opacity	=	m.materialList[i].opacity 	/	100.0		--Float default: 100.0 -- animatable; percentage
			--aTex.option		=	m.materialList[i].opacity	--<Standard>.opacity Float default: 100.0 -- animatable, percentage
			aTex.twoside	=	m.materialList[i].twoSided		--Boolean default: false -- alias: Two_sided
			cunzai=0
			for	tmpidx =1 to lxTexs.count do
			(
				if lxTexs[tmpidx].tex == aTex.tex then
				(
					cunzai=1
					exit
				)
			)
			if cunzai==0 then
				append	lxTexs		aTex
			
		
	--<Standard>.diffuse Color default: (color 149.94 149.94 149.94) -- animatable, alias: Diffuse_Color

	--<Standard>.ambient Color default: (color 149.94 149.94 149.94) - animatable; RGB color; Ambient_Color

	--<Standard>.specular Color default: (color 229.5 229.5 229.5) -- animatable; Specular_Color

	--<Standard>.opacity Float default: 100.0 -- animatable; percentage
	--<Standard>.selfIllumColor Color default: (color 0 0 0) -- animatable; Self_Illum_Color

	/***
			format "    Texture   %\n" 			"nm011b01.jpg"	 	to:out_file
			format "    ColorKey  % % % %\n" 	0 0 0 0	 		to:out_file
			format "    Ambient   % % %\n" 		1.000 1.000 1.000	 to:out_file
			format "    Diffuse   % % %\n" 		1.000 1.000 1.000	 to:out_file
			format "    Specular  % % %\n" 		1.000 1.000 1.000	 to:out_file
			format "    Emissive  % % %\n" 		0.000 0.000 0.000	 to:out_file	--自发光
			format "    Opacity   %\n" 			1.000	 		to:out_file
			format "    Option    %\n" 			"NONE"	 		to:out_file
			format "    TwoSide   %\n" 			"FALSE"	 		to:out_file
	***/
		)
	)
)


--	==================================================================================================
--																			开始导出
--	==================================================================================================

fn objfilt obj=isKindof obj Editable_mesh

fn exportLx	arg=
(
	out=#()
	out=selectByName title:"选择要导出的部件" ButtonText:"导出" --filter:objfilt obj
	
if (out==undefined or out.count <=0 ) then 
	(MessageBox("警告:未选择任何对象,无法导出!") title:"警告!" beep:false;		return false)
	
	format "out.count==%\n" out.count
	
	exportObjList =out

	global all_verts =0	--所有obj共有的顶点和面数
	global all_faces =0

	local cnt_i=0
	for	cntobj =1 to  out.count 	do	
	(
		all_verts = all_verts + out[cntobj].numverts
		all_faces = all_faces + out[cntobj].numfaces
		
		if (matchPattern out[cntobj].name	 pattern:"*atbox") then 
		(
			cnt_i = cnt_i+ 1
		)
	)--end for

/*
	if(cnt_i != 1) then
	(
		if  (queryBox "警告:未检测到有效的【边界盒】名称,【边界盒】的名字必须以atbox结尾！！ \n\n\n 是否确认不导出边界盒？\n           【选是 继续导出，选否 返回修改】" title:"警告!" beep:false)==false	then
			return false
	)
*/
	format "out.name=%\n" out[1].name
	format"out.verts=%\n" all_verts 
	format"out.faces=%\n" all_faces 
	
	


	
	
	

	 select out
	 

	  
	--out_name=  	(GetDir #export)+"/../unname.gmc"

	out_name = getSaveFileName types:"流星模型*.gmc (*.gmc)|*.gmc|All (*.*)|*.*|" caption:"导出gmc文件"
	if out_name == undefine then 
		(MessageBox("警告:不能取得保存文件的名称,无法导出!") title:"警告!" beep:false;return false)
	
	
	exportName	=	getFilenameFile	out_name
	
	
	out_file =  createfile 		out_name
	format "	*******	调试输出	 步骤=%	,	%\n" 		"创建输出文件"	out_name

-- 开始导出
	format "# GModel Geometry File V1.0\n"	to:out_file	
	format "# Gmc for lxres.com\n"	to:out_file	
	numsel=out.count
	
	format "	*******	调试输出	 步骤=%	,	%\n" 	"计算选定物体总数 ="  	numsel  	
-----------------------------------------------------------------------------------------
---- 						材质导出 
-----------------------------------------------------------------------------------------	
	print " 准备查点材质 %\n"
	for outidx=1 to out.count do
	(
		getAllTexName	out[outidx].material
	)
	format "Textures %\n" 		 	lxTexs.count		to:out_file	
	format "{\n" 										to:out_file	
	
	for	ti = 1	to lxTexs.count	do
	(
	  	
		format "  %\n" 		/*texName */	 (filenameFromPath	lxTexs[ti].tex)  	to:out_file

		
	)
	format "}\n" 		  								to:out_file		
	
	format "Shaders %\n" 	lxTexs.count		to:out_file	
	for	ti = 1	to lxTexs.count	do
	(
		format "shader %\n" 		(ti - 1)	  			to:out_file
		format "{\n" 		  to:out_file
		format "  Texture % NORMAL\n" 	 (ti - 1)		  	to:out_file
		format "  TwoSide 0\n" 		  to:out_file
		format "  Blend   DISABLE 1 0\n" 		  	to:out_file
		format "  Opaque  1.000\n" 		  			to:out_file
		format "}\n" 		  to:out_file		
		
	)

		
------------------------------------------
	format "SceneObjects % DummeyObjects %\n" 	numsel	2	 to:out_file
	format "Vertices % Faces %\n" 	all_verts  all_faces	 to:out_file

scenceObjCount = out.count
dummyObjCount =	0
--=====================================
--		遍历所有物体,并导出,	q 循环子为 当前物体
--======================================

is_atbox =0
for	q =1 to  numsel	do		
(
	/*
		字符匹配 举例
		s= "text1"
		matchPattern s pattern:"*t1" 	-- returns true
	*/
	m_str= out[q].name 
	if (matchPattern m_str pattern:"*atbox") then 	-- 碰撞边界盒 的名字必须以这5个字母结尾
	(
		is_atbox = q	-- 必须让 碰撞盒是最后1个写出的物体，所以这里先保存其id，跳过不处理，循环结束后再写出
		continue
	)
	
	if  q < 10 then 
	( 	
		tmpNum = ( "0"+ q as string) 
	)else(
		tmpNum = q as integer
	)
	
	format "	*******	调试输出	 步骤=%	,	%\n" 		"选定物体" 	out[q].name
	
	select	 out[q] 				--	选中当前子物体
 	tmesh = out[q]
	
	if	beAutoNamed == true	then
		format "Object %S%\n" 		out[q].name	  tmpNum	 to:out_file		--	"Object wpnLS01\n"
	else
		format "Object %\n" 		out[q].name	  			 to:out_file		--	"Object wpnL\n"
	
	
	format "{\n" 		 to:out_file
	


	
	
	
-----------------------------------------------------------------------------------------
---- 						顶点导出 
-----------------------------------------------------------------------------------------


	num_verts = tmesh.numverts 
	num_faces = tmesh.numfaces
	format "	*******	调试输出	 步骤=%	,\n"	"开始输出顶点 "
	format "	*******	调试输出	 步骤=%	,	%\n"		"取得顶点总数　" 	  num_verts 
	format "	*******	调试输出	 步骤=%	,	%\n"		"取得三角面总数　" 	  num_faces
	--  Vertices 119 Faces 146
	format "  Vertices % Faces %\n" 		num_verts		  num_faces		to:out_file
		
	
	
	
	
	tv = point
	--setNumCPVVerts tmesh num_verts false
	--buildVCFaces tmesh
	for n=	1 to num_verts  do		--num_verts
	(
		-- 格式:		    v   4.009  -0.445  29.497 vt 0.794 0.765 Bones 3 11 0.51823 15 0.31075 14 0.17102
		--  v   -0.283    3.785    0.049 n -0.513  0.859  0.000 c 255 255 255 255 t 0.85272 0.75261
		vert = 	getVert  tmesh 	n	-- 取得一个顶点
		tv	=	GetTVert	tmesh	n	-- 取得纹理坐标
		
		nv = getNormal  tmesh n --顶点法线
		tmpVtx =	(tv.x * 10000)as  integer	--为了消除科学计数法
		tmpVty =	(tv.y * 10000)as  integer 
		
--	不添加顶点绘制修改器，直接导出模型		
		r = 255
		g = 255
		b = 255
		a = 255
		
--	原添加顶点绘制修改器后导出顶点色		
--		col = getVertColor tmesh n
--		r=col.red as integer
--		g=col.green as integer
--		b=col.blue as integer
--		a=col.alpha as integer

		--ttttt = color 46 188 103 255
		--if col == ttt then
		
		colnums =getNumCPVVerts tmesh
		format "  v   %    %    % n %  %  % c % % % % t % %\n"  vert.x  vert.y  vert.z   nv.x nv.y nv.z	 r g b a	(tmpVtx*0.0001)  (tmpVty*0.0001)      to:out_file

		
		
		
	)--end for n
	
	-----------------------------	取出顶点法线 方法 -------------------------
	--	getNormal <mesh> <vert_index_integer> 			 return <point3>


-----------------------------------------------------------------------------------------
----						面 导出 
----格式
----  f 0 0 1 2	-0.088  0.578 -0.811
-----------------------------------------------------------------------------------------
--	 取面法线方法，	getFaceNormal <mesh> <face_index_integer>   return <point3>


	--	材质序号, 当前未实现,先给出一个定值
	matID = 1		--注意,流星游戏中 是从 0 起,	要减1
	
	format "	*******	调试输出	 步骤=%	,\n"	"开始输出		三角面 "	
	for  i = 1 to  num_faces do		--
	(
		iface = getFace 		tmesh  	i
		nface = getFaceNormal 	tmesh	i
		matID = getFaceMatID 	tmesh	i		--	!!!!!!!!!!!!  暂时只用一个纹理试验
		
		mtype = classof tmesh.material
		if mtype == Standardmaterial then
		(
			if tmesh.material.diffuseMap != undefined then
				texname = tmesh.material.diffuseMap.filename
			else
				texname = tmesh.material.name
			for texidx=1 to lxTexs.count do 
			(
				if lxTexs[texidx].tex == texname then
				(
					matID=texidx
					exit
				)
			)
		)
		else
		(
			
			
			texname = tmesh.material.materialList[matID].diffuseMap.filename
			for texidx=1 to lxTexs.count do 
			(
				if lxTexs[texidx].tex == texname then
				(
					matID=texidx
					exit
				)
			)
			
		)
		realmatID=matID-1
		if realmatID == 65535 then 
			realmatID=-1
		format 	"  f %  % % %	% % %\n" 	  realmatID		(iface[1]as integer -1) 	( iface[2]as integer -1)	( iface[3]as integer -1)	nface.x nface.y nface.z		to:out_file
			
	)--end for iface

	
	format "}\n" 		to:out_file		-- 最后必须加 } 结束 

)-- end for q=1 ...		--遍历所有物体



	if (is_atbox > 0  ) then
	(
		
		format "	*******	调试输出	 步骤=%	,	%\n" 		"选定物体【碰撞盒】" 	out[is_atbox].name
		
		select	 out[is_atbox] 				--	选中当前子物体
		tmesh = snapshotAsMesh out[is_atbox]
		format "Object %\n" 		out[is_atbox].name	  	 to:out_file		--	"Object wpnLS01\n"
		format "{\n" 		 to:out_file

		-----------------------------------------------------------------------------------------
		---- 						顶点导出 
		-----------------------------------------------------------------------------------------

		num_verts = tmesh.numverts 
		num_faces = tmesh.numfaces
		format "	*******	调试输出	 步骤=%	,\n"	"开始输出顶点 "
		format "	*******	调试输出	 步骤=%	,	%\n"		"取得顶点总数　" 	  num_verts 
		format "	*******	调试输出	 步骤=%	,	%\n"		"取得三角面总数　" 	  num_faces
		--  Vertices 119 Faces 146
		format "  Vertices % Faces %\n" 		num_verts		  num_faces		to:out_file
		
		for n=	1 to num_verts  do		--num_verts
		(
			--  v   -0.283    3.785    0.049 n -0.513  0.859  0.000 c 255 255 255 255 t 0.85272 0.75261
			vert = 	getVert  tmesh 	n	-- 取得一个顶点

			nv = getNormal  tmesh n --顶点法线			
			format "  v   %    %    % n %  %  % c 255 255 255 255 t % %\n"  vert.x  vert.y  vert.z   nv.x nv.y nv.z		0.0  0.0      to:out_file
			
		)--end for n
		
		-----------------------------	取出顶点法线 方法 -------------------------
		--	getNormal <mesh> <vert_index_integer> 			 return <point3>

		-----------------------------------------------------------------------------------------
		----						面 导出 
		----格式
		----  f 0 0 1 2	-0.088  0.578 -0.811
		-----------------------------------------------------------------------------------------
		--	 取面法线方法，	getFaceNormal <mesh> <face_index_integer>   return <point3>


		--	材质序号, 当前未实现,先给出一个定值
		
		format "	*******	调试输出	 步骤=%	,\n"	"开始输出		三角面 "	
		for  i = 1 to  num_faces do		--
		(
			iface = getFace tmesh  i
			nface = getFaceNormal tmesh i
			
			format 	"  f % % % %	% % %\n" 	  -1		(iface[1]as integer -1) 	( iface[2]as integer -1)	( iface[3]as integer -1)	nface.x nface.y nface.z		to:out_file
				
		)--end for iface

		
		format "}\n" 		to:out_file		-- 最后必须加 } 结束 
	)
	
-----------------------------------------------------------------------------------------
----					 全部结束
-----------------------------------------------------------------------------------------
	
	
	
	close out_file
--	MessageBox("GMC 完成导出!") title:"完成!" beep:false
	
	
	--	***************	gmc 导出完毕，开始导出	des**************
	format "des begin	\n"		
	ExportDes		exportObjList
	--	***************	des 导出完毕，开始导出	pst**************
	format "pst begin	\n"		
	ExportPst		exportObjList
	
	
	return true

)	--end fn exportLx




	
--	==================================================================================================
--						Main() 
--	==================================================================================================
if	(exportLx "name" ) then
	messagebox	" ***	[OK]		流星地图模型导出脚本运行正常结束!"
else
	(
		messagebox	" ***	[Err]	流星地图模型导出脚本运行失败!"
		if  out_file != undefine do	close out_file	
	)

	
	
	
	
	
	

	
	

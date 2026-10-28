--	************************************************************************
--
--	流星模型载入脚本 	v0.1
--	作者:	yish
--	日期:	2010-10-31
--	简介:	解析流星蝴蝶剑模型< *.gmb > 格式,载入3DSMAX
--	环境:	3DSMAX2009
--
--	更新记录:
--	-20110323-----------------------------------------------------------
--	版本	0.1
--	增加:		1,实现导入
--
--	待做:
--			1,纹理未导入
--	************************************************************************



print "--------		流星模型 gmb 载入脚本 v0.1	-----------"
print "--------		by Yish   		-----------"
print "--------		2011-03-23   		-----------"

global lxPath =""
global	lxfileType =""
struct LXMAT
(
    Id,     tex,    col,    amb,    dif,    spec,   emis,   opac,   opt,    twoside
 --   Texture   nm011b01.jpg
 --   ColorKey  0 0 0 0
 --   Ambient   1.000 1.000 1.000
 --   Diffuse   1.000 1.000 1.000
 --   Specular  1.000 1.000 1.000
 --   Emissive  0.000 0.000 0.000
 --   Opacity   1.000
 --   Option    NONE
 --   TwoSide   FALSE
)	-- end struct LXMAT

struct SHADER_STRUCT
(
	/***
	Shaders 1			//	int32	1		sharder数量

	shader 0
	{
	  Texture 0 NORMAL		//	int32 	0		int32	6 下面字串长度
					//	字串	"NORMAL"

	  TwoSide 0			//	int32	0
					//	int32 	11  	后面字串长度	
	  Blend   DISABLE 1 0		//	字串	"DISABLE 1 0"
	  Opaque  1.000			//	float	1.0
	}
***/
	
	nTex,	--0
	sTex,	--NORMAL	
	twoSide,	--0
	bld	,	-- "DISABLE 1 0"
	opa		--1.0
)

struct LXOBJ	
(

	Id,  verts = #(), colors = #(),	faces = #(),	face_mat =#(),	uvs =#(),	bone_ids =#(),      bone_v_count =#(),	weight_array =#(),	
    groups = #(), mats = #(),  num_mat,   num_vert,  num_face,  skin_name,   face_normal=#(),

--========================================================================================
--                                      取子模型名称
--========================================================================================
    fn  getSkinName in_file=
	(
		skin_name	=	readGmbStr	in_file
		--format 	"已取得 obj 名称 = %\n"   	skin_name
    ),
--========================================================================================
--                                      取材质
--========================================================================================
    fn  getSkinMats in_file=
	(
                                while not eof in_file do 	                -- read until reach end of file
                                (
                                   line=   readline  in_file 	            -- 读入一行
                                    subline = filterString  line " "		-- 用空格分解为文本数组
                                    if subline[1] == "#" do continue 	    -- 跳过注释行
                                        
                                    if  ( subline[1] == "Materials:") then 
                                            (  
                                                num_mat = subline[2]as integer             --  取得skin名字
                                                print 	("已取得材质数量 =" + num_mat as string)
										 exit
                                            )
                                    else 
                                        continue
                                )
                                
                                --==================取 每个材质========= ============
                                for i = 1 to num_mat do
                                (
								for m= 1 to 10 do
	                                 (
								   line=readline  in_file 	 
	                                    subline = filterString  line " "	
	                                    
		                                    case  subline[1] of 
		                                    (
		                                        "Material"  :   mats[i] =  ( LXMAT     Id:i  )    --创建一个材质
		                                        
		                                        "Texture"   :   mats[i].tex =   subline[2]      --取纹理名
		                                        
		                                        "ColorKey"  :   mats[i].col =   #(subline[2] as integer , subline[3] as integer , subline[4] as integer ,  subline[5] as integer )   -- ColorKey  0 0 0 0
		                                        
		                                        "Ambient"  :   mats[i].amb =   #(subline[2] as float , subline[3] as float , subline[4] as float )  
		                                        
		                                        "Diffuse"  :   mats[i].dif =   #(subline[2] as float , subline[3] as float , subline[4] as float )   
		                                        
		                                        "Specular"  :   mats[i].spec =   #(subline[2] as float , subline[3] as float , subline[4] as float )   
		                                    
		                                        "Emissive"  :   mats[i].emis =   #(subline[2] as float , subline[3] as float , subline[4] as float )   
		                                    
		                                        "Opacity"  :   mats[i].opac =   subline[2]as float
		                                        
		                                        "Option"  :   mats[i].opt =     subline[2]      -- NONE
		                                        
		                                        "TwoSide"  :   mats[i].twoside =     subline[2]      -- FALSE
		                                        
		                                    )	 --end case
										
								)--end for
                                )
                         
     ) , 
--========================================================================================
--                                      取顶点
--========================================================================================
    fn  getSkinVerts in_file=(
		
/***		
	int32		8	//Vertices 8
	int32		12	//Faces 12
***/
		num_vert	= readLong	in_file 
		--format " 取得顶点数=     %   \n"     num_vert
		num_face	= readLong	in_file
		--format " 取得三角面数=     %   \n"     num_face
                                
                                --==================取 每个顶点========= ============
/***
//开始顶点
//v  -12.780  -13.403   -3.019 n -0.333 -0.667 -0.667 c 255 255 255 255 t 0.00000 0.00000

	vector3 (3*4字节）	vector3(3*4字节）	color4(4字节，每个字节为1~255色）	tex2（2*4字节） == 每顶点共 36 字节
***/

            for v = 1 to num_vert do
			(                                    
				---------------     读入 顶点格式	每个顶点如下
				---------------    v   0.743  -2.853  0.209 n  0.080 -0.114  0.990 c 254 211 157 255 t 0.26085 0.04720
					tmpv = [ (ReadFloat	in_file ),(ReadFloat	in_file ), (ReadFloat	in_file )	]	--读入顶点 坐标
					tmpn = [ (ReadFloat	in_file ),(ReadFloat	in_file ), (ReadFloat	in_file )	]
					r = (readByte	in_file #unsigned)
					g = (readByte	in_file #unsigned)
					b = (readByte	in_file #unsigned)
					a =(readByte	in_file #unsigned)
					col	 = color r g b a
					--col.alpha = 	(readByte	in_file #unsigned)	
					tmpt = [ (ReadFloat	in_file ),(ReadFloat	in_file ), 0.0	]						--	uv坐标是  Point3 类型,	
							
					append verts 		tmpv
					append uvs 			tmpt
					append colors col 
					
				--if v >= num_vert then
						--format	" v=%		col=%		uv=%\n"		verts[v]		colors[v]		uvs[v]	

			)--end for
			--format	"-----------子	obj【%】		顶点读取完成----------\n"	skin_name
			
			
			--==================取 每个三角面========= ============
			---------------     读入 顶点格式	每个顶点如下
			---------  f 0 0 1 2	 0.194 -0.296  0.935
/***
	// 开始面
	//  f -1 0 1 2	 0.000 -0.000 -1.000
	每个数据都为4字节 ，前4个为int32,后3个为float ==  每面共 28 字节
***/
			for v = 1 to num_face do
			(
				tmpmat = (readLong	in_file) + 1
				tmpface= [ (readLong	in_file) + 1,		(readLong	in_file) + 1,		(readLong	in_file) + 1	]
				tmpff	=	[ (ReadFloat	in_file ),(ReadFloat	in_file ), (ReadFloat	in_file )	]	--	未知
				append face_mat		tmpmat
				append faces 		tmpface
				append face_normal	tmpff
				--if v >= num_face then
				--	format	" mat=%		fac=%\n"		tmpmat		tmpface
             )
			--format	"-----------子	obj【%】	面 读取完成----------\n"			skin_name
			 
                         
	)  -- end fn


)  -- end struct LXOBJ


--======================================================================================== 
--                                     读取 GMB 字符串 （前面有长度）
--========================================================================================
fn readGmbStr	in_file		strCount: =(
	if strCount == unsupplied then 
		strCount 	= ReadLong 	in_file
	
	retStr=""
	for i=1 to strCount do(
		
		bt=	ReadByte 	in_file
		retStr += (bit.intAsChar	bt)		-- bit.charAsInt	可以转换 字节到 整数
	)

	--format "读取到字串 =	%\n"	retStr
	return	retStr
)

global	num_skins	

global  num_SceneObjects	--场景对象总数
global  num_DummeyObjects	--动态对象总数

shaderArray = #()
texArray = #()

--======================================================================================== 
--                                     读取模型
--========================================================================================
fn	readLxObj		in_file=
(
	gmbFlag =	"GMDL V1.00"

	sGmb =	readGmbStr		in_file		strCount:gmbFlag.count
	if	sGmb	!= "GMDL V1.00"	then--标志头
	(
		format "---	err!	不是正确的GMB格式"
		return	false
	)
/***
	Textures 1		// int32	1
	{
	  w8_4.jpg		// int32	8	String	"w8_4.jpg"
	}
***/
	texNum	= ReadLong 	in_file	

	for	 i=1 to texNum	do(
		texArray[i] = readGmbStr	in_file
	)
	
/***
	Shaders 1			//	int32	1		sharder数量

	shader 0
	{
	  Texture 0 NORMAL		//	int32 	0		int32	6 下面字串长度
					//	字串	"NORMAL"

	  TwoSide 0			//	int32	0
					//	int32 	11  	后面字串长度	
	  Blend   DISABLE 1 0		//	字串	"DISABLE 1 0"
	  Opaque  1.000			//	float	1.0
	}
***/
	
	shaderNum	= ReadLong 	in_file	
	--shaderArray = #()
	for i =1 to shaderNum do(
		sd = SHADER_STRUCT()
		sd.nTex	= ReadLong 	in_file	
		sd.sTex	= readGmbStr	in_file
		sd.twoSide=	ReadByte 	in_file	
		sd.bld	=	readGmbStr	in_file
		sd.opa	=	ReadFloat	in_file
		
		shaderArray[i] = sd
	)
	
	
/***
	int32	2	//SceneObjects 2 	场景对象
	int32	2	//DummeyObjects 2	辅助对象

	int32	252	// 本文件所有obj的顶点之和
	int32	201	// 本文件所有obj的面数之和
***/
	
	num_SceneObjects 	= ReadLong 	in_file	
	num_DummeyObjects 	= ReadLong 	in_file	
	vertCountAll 	= ReadLong 	in_file	
	faceCountALl 	= ReadLong 	in_file	
	
	format " 取得 场景对象总数=     % ，  取得 动态对象总数=     %   \n"      num_SceneObjects 	num_DummeyObjects
      
 -- line=readline  in_file 				-- 跳过一行(顶点和面 总数）	Vertices 157 Faces 170


	myobj = #()
	
	for i=1 to  num_SceneObjects   do
	(
        --      开始遍历所有子模型,通常 流星低模只有1个模型
       -- line=readline  in_file 				-- 跳过一行	"{"	

        myobj[i] = LXOBJ Id:i               --创建一个子模型
        myobj[i].getSkinName    in_file     -- 取模型名称
	

		format 	"---	开始读取	OBJ name = %\n"  myobj[i].skin_name 

--       myobj[i].getSkinMats    in_file     --取材质
--		print 	("--------------- 	材质数量  = " + ( myobj[i].mats.count as string) )


        myobj[i].getSkinVerts   in_file     --取顶点
       -- myobj[i].getSkinFaces   in_file     --取面
        
				-- 跳过一行	"}"			-- 至此取得一个静态子模型
	  format	"---	 取得一个OBJ成功!	名称=%		顶点数=%		面数=%	 ----------\n"	myobj[i].skin_name	myobj[i].num_vert	myobj[i].num_face
	)-- end for
	  
	  return	myobj
) -- end fn readLxObj



--========================================================================================
--                                      Main()
-- 分析gmb格式
--========================================================================================
fn 	mainFunc  argName=
(

delete $*


--------------------		读入 gmb 模型		-----------------------

--in_name = ((GetDir #export)+"/../scripts/SMDImporter/p9_300.skc") 

lx_objs 	= 	#()



if doesFileExist  argName then

--if in_name != undefined then
( 
	in_name = argName
	
	lxfileType = getFilenameFile	argName
	
	
	
	---a_file = openFile in_name 	
	a_file  = fopen in_name "rb"
	if a_file != undefined then
	(
		print ("   ---	开始读入流星[gmb模型]文件:	"+ in_name)
		lx_objs = readLxObj a_file	
		fclose a_file 
		print ("   ---	流星[gmb模型]文件读入完毕:	"+ in_name)	 
	)

)else(
	return NULL
)-- end if 	





--------------------		创建模型		-----------------------
lx_meshs	=#()

print ("	***		开始创建模型")

	cmats = 	multimaterial name:"lxmats"	 numsubs:shaderArray.count
	--cmats = multimaterial numsubs: shaderArray.count
	format "材质总数= % \n"	shaderArray.count
		texPath = lxPath +"ctexture\\ctexture\\"
		for	cnt=1 to 20 do
		(
			if cnt < 10 then
				tmp = ( "0" + (cnt as string))
			else
				tmp = cnt as string
			--format "cnt	==%		lxfileType=%	tmp=%\n"	cnt		 		lxfileType	tmp
			if	lxfileType == ("sn" + tmp) then
			(
				texPath = lxPath +	lxfileType + "\\"
				--format "texPath==%		lxfileType=%\n"		texPath		lxfileType
				break
			)
		)
		for  itx=1 to shaderArray.count do
		(
			
			--local skinMaterial = standardMaterial name:("Mat_" + name_read + "_" + s as string)
			--cmat[s] = skinMaterial
			format "材质%	= 	% \n"		itx		shaderArray[itx].nTex 
			tname=""
			if	shaderArray[itx].nTex  >= 0 then
			(
				tname1 = texArray[ shaderArray[itx].nTex + 1 ]
				tname = texPath + tname1
				print (tname) --+lx_objs[i].mats[itx].tex )
				--local bt = BitmapTexture()
				--bt.filename =  (lxPath +"ptexture\\ptexture\\" + lx_objs[i].mats[itx].tex)
				--meditMaterials[mitx].diffuseMap = Bitmaptexture fileName:	tname		--	"F:\local_Game\Meteor\ptexture\ptexture\nm001b01.tga"
			)
		--	cmats[itx] = meditMaterials[mitx]
			local subMat = standardmaterial name:( "mat" + (itx as string) )
			--local	tmpmat =  standard diffuseMap:(Bitmaptexture fileName:	tname) 	showInViewport:true
			local dmap = bitmaptexture filename: tname
			subMat.maps[2] = dmap
			subMat.mapEnables[2] = true
			showTextureMap subMat dmap true
			
			cmats[itx] = submat

		)

for	i = 1 to lx_objs.count	do		-- 为每个模型创建
(

	if	i == 126 then
		format	" i==126,	uvs==%\n"	lx_objs[i].uvs
	
	lx_meshs[i]  =      mesh    name:lx_objs[i].skin_name	 vertices:lx_objs[i].verts  faces:lx_objs[i].faces  materialIDs: lx_objs[i].face_mat	tverts:lx_objs[i].uvs

	
	lx_meshs[i].material = cmats
		
		for  itx=1 to shaderArray.count do
		(
			showTextureMap lx_meshs[i].material[itx]		on	--cmat[itx] meditMaterials[itx].diffuseMap on 
		)
		
	update lx_meshs[i]
		
	if	lx_objs[i].uvs.count == 0 then
	(
		format	" === 对象[%]	 % 没有纹理顶点 \n"	i	lx_objs[i].skin_name
		continue
	)

	
	BUILDTVFACES 	lx_meshs[i]	-- FALSE

	/*	
		--建造材质
		    meditmaterials[1].ambient= lx_meshs[i].amb
		    meditmaterials[1].diffuse=  lx_meshs[i].dif
		    meditmaterials[1].shaderbyname=  lx_meshs[i].name
		    meditmaterials[1].specular=  lx_meshs[i].spec
		    meditmaterials[1].specularlevel=  lx_meshs[i].specularlever
		    meditmaterials[1].glossiness=_material_glossiness
		    meditmaterials[1].selfillumcolor=_Material_SelfillumColor
		    meditmaterials[1].selfillumamount=_Material_SelfillumAmount
		    meditmaterials[1].diffuseMapEnable=true
		    bmp =bitmaptexture filename:  lx_meshs[i].tex
		    meditmaterials[1].diffusemap=bmp
	*/
		
		--	meshop.setMapSupport lx_meshs[i]  0 true
    		--	meshop.setMapSupport lx_meshs[i]  1 true
	
		--13. Build the faces
  
         -- lx_meshs[i].materialIDs = #(0,1)
        --14. Set the UVW coordinates to the faces.
         for f = 1 to lx_objs[i].faces.count do
         (
			setFaceNormal	lx_meshs[i]		f	lx_objs[i].face_normal[f]
            setFaceMatID 	lx_meshs[i] 	f 	(lx_objs[i].face_mat[f] + 0)
			SETTVFACE	 	lx_meshs[i] 	f	lx_objs[i].faces[f]
         )
		
		--lx_meshs[i].Material=		getMeditMaterial 1
		--lx_meshs[i].material=meditmaterials[2]
	
		     

		update lx_meshs[i]
		--tmpnode = getNodeByName lx_meshs[i].name exact:false
		--addModifier tmpnode (VertexPaint())
		--modPanel.setCurrentObject tmpnode.modifiers[2]
		setNumCPVVerts lx_meshs[i] lx_meshs[i].numverts
		defaultVCFaces lx_meshs[i]
		if lx_objs[i].colors.count > 0 then
		(
			
		for idxcol = 1 to lx_objs[i].colors.count  do
		(
			--format	"this is% \n"	lx_objs[i].colors[idxcol]
			setVertColor lx_meshs[i] idxcol lx_objs[i].colors[idxcol]
		)
		)
 )-- end for
 print ("	***		创建模型完毕")
------------------------------------------------------------------------
	
	disableSceneRedraw()	---------   取消重画, 可以提高速度,必须再用 enableSceneRedraw() 打开重画


	enableSceneRedraw()	---------------- 充许重画

	
)	-- end function mainFunc

--=======================================================================
--				Main	UI
--======================================================================

fn  getLxPath  cfgPath=
(
	fname = getOpenFileName types:"Meteor (*.exe)|*.exe|All (*.*)|*.*|" caption:"请选择流星蝴蝶剑主程序"
	if fname == undefined then return NULL
	lxPath = getFilenamePath fname	--取得流星主目录
	
	out_cfg_file = createfile 	cfgPath
	-- 创建配置文件
	if out_cfg_file == undefined then return NULL
	format "%\n"  lxPath  to: out_cfg_file
	close out_cfg_file 
	-- 结束创建
	fs= getFiles (lxPath + "cmodel\\*.gmb") 
	return fs
)

rollout PrintRollout "流星蝴蝶剑gmb模型导入 v0.1 by Yish" width:484 height:379
(
 
	button printbtn "导入模型" pos:[350,10] width:124 height:68
	GroupBox grp1 "关于:" pos:[5,2] width:316 height:77
	label titleLabel "流星蝴蝶剑 gmb模型导入工具v0.1" pos:[73,19] width:193 height:18
	HyperLink add0 "访问网站" pos:[96,41] width:89 height:15 address:"http://bbs.lx766.com/read-htm-tid-1766.html" color:(color 0 0 255) hovercolor:(color 255 0 0)
	label txtdata "2010-10-31" pos:[229,62] width:78 height:13
	listbox lbx1 "选择文件" pos:[7,83] width:472 height:19
	label lbl12 "by Yish" pos:[232,42] width:59 height:16

 

	on PrintRollout open do
	(		
	
	config_name = "lx2max2_res.config"
	
	cfg_fname= ((GetDir #import)+"/lx2max2_res.config")
	
			
	
	
	
	
	
	if  doesFileExist cfg_fname	then	-- 如果文件存在
	
	(
	
		in_text = openfile  cfg_fname --打开配置文件
	
		--skipToString in_text "="
	
		while not eof in_text do
	
		( 
	
			lxPath = readline in_text
	
			exit
	
		) 
	
		close in_text 
	
	
	
		file_array = getFiles (lxPath + "*.gmb") 
		for sn =1 to 20 do
		(
			--snname	=	"sn" + sn
			if sn <	10	then	
				fa		= 	getFiles (lxPath + "sn0" + (sn as string) + "\\*.gmb") 
			else	
				fa		= 	getFiles (lxPath + "sn" + (sn as string) + "\\*.gmb") 
			file_array	+= 	fa
		)

		

		
		if file_array == undefined then return NULL
	
		for lf in file_array do
	
		(
	
			tmp = lbx1.Items 
	
			append tmp  lf
	
			lbx1.Items = tmp
	
			--print lf
	
		)
	
	)else
	
	(
	
		file_array = getLxPath 		cfg_fname
	
		if file_array == undefined then return NULL
	
		for lf in file_array do
	
		(
	
			tmp = lbx1.Items 
	
			append tmp  lf
	
			lbx1.Items = tmp
	
			print lf
	
		)
	
	)
	
	
	)
	on printbtn pressed do
	(
	
	--mainFunc()
		
		retFile = lbx1.Items[ lbx1.selection ]
		if( retFile != undefined )then 
		(	mainFunc retFile	--	打开双击的文件
	--messagebox "此按钮功能暂时无效, 请双击列表框中的模型文件导入(注意是 *.gmb 文件!)"
		)
	
	)
	on lbx1 doubleClicked sel do
	(
	    retFile = lbx1.Items[ lbx1.selection ]
		mainFunc retFile	--	打开双击的文件
	)
)
createDialog PrintRollout
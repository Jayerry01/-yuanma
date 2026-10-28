/*流星gmb/gmc模型导入脚本
v0.3 2022 06 02
1、同时支持gmb/gmc导入
2、增加gmc材质导入
3、增加顶点颜色导入
4、增加des坐标轴旋转轴导入，模型坐标不会全为0
5、增加fmc动画导入
6、优化文件列表载入速度
*/
global texs = #()--暂存贴图名
global shas = #()--暂存材质
global scenum --对象数
global lxPath =""
global objname = #()
struct modmat--材质
(
    tex,--贴图 Texture
    cls,--类型 NORMAL
    two,--双面 TwoSide
    ble,--混合 Blend
    opa,--半透明 Opaque
	fn gmcmat in_file=(
		while not eof in_file do -- read until reach end of file
		(
			line= readline in_file -- 读入一行
			subline = filterString line " \t" -- 用空格分解为文本数组
			case subline[1] of (
				"#":(continue)
				"}":(exit)
				"Texture":(
					texid = (subline[2] as integer) +1
					if texid < 1 or texid > texs.count then(
						tex = ""
					)else(
						tex = texs[texid]
					)
					cls	= subline[3]
				)
				"TwoSide":(
					two = subline[2] as integer
				)
				"Blend":(--长度不定暂跳过
					continue
				)
				"Opaque":(
					opa = subline[2] as float
				)
			)
		)

	)
)
--定义一个仅旋转支点的函数 
fn RotatePivotOnly obj rotation=(
	local rotValInv=inverse(rotation as quat) 
	animate off in coordsys local obj.rotation*=RotValInv 
	obj.objectoffsetrot*=RotValInv 
	obj.objectoffsetpos*=RotValInv 
)
fn getdes in_file=(
	if (doesFileExist in_file) == false then (return false)
	a_file = openFile in_file 	
	if a_file == undefined then (return false)
	local subline
	desscenum = -1
	objname = #()
	while not eof a_file do 	-- read until reach end of file
	(	
		if desscenum = 0 then(exit)
		line=readline  a_file 	-- 读入一行
		subline = filterString  line " \t" -- 用空格分解为文本数组
		if subline[1] == "#" do continue -- 跳过注释行
		if  (subline[1] == "SceneObjects" and subline[3] == "DummeyObjects") then 
		(  
			desscenum = subline[2] as integer --对象数量
		)
		case subline[1] of (
			"Object":(
				local des_nam,des_pos,des_qua
				des_nam = subline[2]
				append objname des_nam
				line=readline  a_file 	-- 读入一行
				line=readline  a_file 	-- 读入一行
				subline = filterString  line " \t" -- 用空格分解为文本数组
				if subline[1] == "Position:" then(
					des_pos = [(subline[2] as float),(subline[3] as float),(subline[4] as float)]
				)else(
					return false
				)
				line=readline  a_file 	-- 读入一行
				subline = filterString  line " \t" -- 用空格分解为文本数组
				if subline[1] == "Quaternion:" then(
					des_qua = quat (subline[3] as float) (subline[4] as float) (subline[5] as float) (subline[2] as float)
				)else(
					return false
				)
				des_obj = getNodeByName des_nam
				if des_obj != undefined then(
					des_obj.pivot = des_pos
					RotatePivotOnly des_obj des_qua
				)
				desscenum -=1
			)
		)
	)
	close a_file
	return true
)
fn getfmc in_file=(
	if (doesFileExist in_file) == false then (return false)
	a_file = openFile in_file 	
	if a_file == undefined then (return false)
	local subline
	franum = -1
	objnum = -1
	--lx_objs
	while not eof a_file do 	-- read until reach end of file
	(	
		if desscenum == 0 then(exit)
		line=readline  a_file 	-- 读入一行
		subline = filterString  line " \t" -- 用空格分解为文本数组
		if subline[1] == "#" do continue -- 跳过注释行
		if  (subline[1] == "SceneObjects" and subline[3] == "DummeyObjects") then 
		(  
			objnum = subline[2] as integer --对象数量
		)
		if  (subline[1] == "FPS" and subline[3] == "Frames") then 
		(  
			franum = subline[4] as integer --帧数
			exit
		)
	)
	for i = 1 to franum do(
		line=readline  a_file 	-- 读入一行
		subline = filterString  line " \t" -- 用空格分解为文本数组
		if subline[1] == "#" do continue -- 跳过注释行
		fid = 0
		if subline[1] == "frame" then(
			fid = subline[2] as integer
		)
		line=readline  a_file 	-- 读入一行
		for j =1 to objnum do(
			line=readline  a_file 	-- 读入一行
			subline = filterString  line " \t" -- 用空格分解为文本数组
			fmc_pos = [(subline[2] as float),(subline[3] as float),(subline[4] as float)]
			fmc_rot = quat (subline[7] as float) (subline[8] as float) (subline[9] as float) (subline[6] as float)
			fmc_obj = getNodeByName objname[j]
			if fmc_obj != undefined then(
				at time fid(
					animate on(
						fmc_obj.rotation = fmc_rot
						fmc_obj.pos = fmc_pos	
					)
					--animate off
					--max set key keys
				)
			)
		)
		line=readline  a_file 	-- 读入一行
	)
	close a_file
	return true
)
fn readGmbStr in_file strCount: =(
	if strCount == unsupplied then(
		strCount = ReadLong in_file
    )
	retStr=""
	for i=1 to strCount do(
		bt=	ReadByte 	in_file
		retStr += (bit.intAsChar bt) --字节到整数
	)
	return	retStr
)
struct objdat(
    nam,--名字
    verts = #(),--顶点位置
    vn = #(),--纹理
    vc = #(),--顶点颜色
    uvs =#(),--顶点uv
    face_mat =#(),--面材质
    faces = #(),--面顶点
    faces_n = #(),--面纹理

    fn gmbObjName in_file=(--取对象名
		nam	= readGmbStr in_file
    ),
	fn gmcObjName in_file=(
		while not eof in_file do 	                -- read until reach end of file
		(
			line= readline  in_file 	            -- 读入一行
			subline = filterString  line " \t"		-- 用空格分解为文本数组
			if subline[1] == "#" do continue 	    -- 跳过注释行
			if subline[1] == "Object" then(  
				nam = subline[2]
				exit
			)else(
				continue
			)
		)
    ),
    fn  gmbObjVerts in_file=(--取顶点和面
		num_vert = readLong	in_file --顶点数
		num_face = readLong	in_file --面数
		for v = 1 to num_vert do( --顶点                                   
			append verts [(ReadFloat in_file ),(ReadFloat	in_file ),(ReadFloat in_file )]	--顶点
			append vn [(ReadFloat in_file ),(ReadFloat	in_file ),(ReadFloat in_file )] --纹理
			append vc (color (readByte in_file) (readByte in_file) (readByte in_file) (readByte in_file))--顶点颜色
			append uvs [(ReadFloat in_file ), (ReadFloat in_file ), 0.0] --uv坐标是  Point3 类型,
		)--end for
		for v = 1 to num_face do(--面
			append face_mat ((readLong in_file) +1) --材质id
			append faces [(readLong in_file) + 1, (readLong in_file) + 1, (readLong in_file) + 1]--顶点编号
			append faces_n [(ReadFloat in_file),(ReadFloat in_file),(ReadFloat in_file)]--纹理
		)
	),
	fn gmcObjVerts in_file=(
		num_vert = 0
		num_face = 0
		while not eof in_file do -- read until reach end of file
		(
			line= readline in_file -- 读入一行
			subline = filterString line " \t" -- 用空格分解为文本数组
			if subline[1] == "#" do (continue) -- 跳过注释行
			if  ( subline[1] == "Vertices") then(
				num_vert = subline[2]as integer --取得顶点数
				num_face = subline[4]as integer --取得面数
				exit
			)else(
				continue
			)
		)
		for v = 1 to num_vert do(
			line=readline  in_file 	 
			subline = filterString  line " \t"	

			append verts [(subline[2]as float) ,(subline[3]as float), (subline[4]as float)]	--顶点坐标
			append vn [(subline[6]as float) ,(subline[7]as float), (subline[8]as float)]
			append vc (color (subline[10]as integer) (subline[11]as integer) (subline[12]as integer) (subline[13]as integer))
			append uvs [(subline[15]as float) ,(subline[16]as float), 0,0]
		)--end for
		for v = 1 to num_face do(
			line=readline  in_file 	 
			subline = filterString  line " \t"
			append face_mat ((subline[2]as integer)+1)
			append faces [(subline[3]as integer)+1 ,(subline[4]as integer)+1, (subline[5]as integer)+1]
			append faces_n [(subline[6]as integer) ,(subline[7]as integer), (subline[8]as integer)]
		)
	)-- end fn

)  -- end struct LXOBJ

fn readGmbObj in_file=(
	gmbFlag = "GMDL V1.00"
	sGmb = readGmbStr in_file strCount:gmbFlag.count
	if	sGmb	!= "GMDL V1.00"	then--标志头
	(
		format "---	err!	不是正确的GMB格式"
		return	false
	)
	texNum = ReadLong in_file --贴图数量
    texs = #() --清空贴图以防错误
	for	 i=1 to texNum	do(
		texs[i] = readGmbStr in_file
	)
	shaderNum = ReadLong in_file --材质数量	
    shas = #() --清空材质以防错误
	for i =1 to shaderNum do(
		tmp = modmat()
        texid = (ReadLong in_file) +1
        if texid < 1 or texid > texs.count then(
            tmp.tex = ""
        )else(
            tmp.tex = texs[texid]
        )
		tmp.cls	= readGmbStr in_file
		tmp.two= ReadByte in_file
		tmp.ble	= readGmbStr in_file
		tmp.opa	= ReadFloat in_file
		shas[i] = tmp
	)

	scenum = ReadLong in_file --对象数量
	tmp = ReadLong in_file --辅助数量
	tmp = ReadLong in_file --总点数
	tmp = ReadLong in_file --总面数

    lxobj = #() --清空对象
	for i=1 to scenum do(
        lxobj[i] = objdat() --创建一个子模型
        lxobj[i].gmbObjName in_file -- 取模型名称
        lxobj[i].gmbObjVerts in_file --取顶点面
	)-- end for
	return lxobj
) -- end fn readGmbObj
fn	readgmcObj in_file=(
	local subline
	texnum = 0
	while not eof in_file do 	-- read until reach end of file
	( 
		line=readline  in_file 	-- 读入一行
		subline = filterString  line " \t" -- 用空格分解为文本数组
		if subline[1] == "#" do continue -- 跳过注释行
		if  ( subline[1] == "Textures") then 
		(  
			texnum = subline[2] as integer --贴图数量
			exit
		)
	)
	texs = #()--清空贴图数组
	while not eof in_file do 	-- read until reach end of file
	( 
		line=readline  in_file 	-- 读入一行
		subline = filterString  line " \t"
		if subline[1] == "{" do exit 	-- 跳过空行
	)
	for i=1 to texnum do(
		line=readline  in_file 	-- 读入一行
		subline = filterString  line " \t" -- 用空格分解为文本数组
		append texs subline[1]
	)
	shas = #() --清空材质
	shanum = 0
	while not eof in_file do 	-- read until reach end of file
	( 
		line=readline  in_file 	-- 读入一行
		subline = filterString  line " \t"
		if subline[1] == "#" do continue 	-- 跳过注释行, skip to next line
		if subline[1] == "Shaders" then(
			shanum = subline[2] as integer
			exit
		)
	)
	for i=1 to shanum do(--取材质
		shas[i] = modmat()
		shas[i].gmcmat in_file
	)
	
	while not eof in_file do 	-- read until reach end of file
	( 
		line=readline  in_file 	-- 读入一行
		subline = filterString  line " \t"		-- 用空格分解为文本数组
		if subline[1] == "#" do continue 	-- 跳过注释行, skip to next line
		if  ( subline[1] == "SceneObjects" and subline[3] == "DummeyObjects" ) then 
		(  
			scenum = subline[2] as integer       --取得 场景对象总数
			exit
		)
	)
	lxobj = #()
	for i=1 to  scenum  do
	(
		lxobj[i] = objdat() --创建一个子模型
		lxobj[i].gmcObjName in_file -- 取模型名称
		line=readline in_file -- 跳过一行	"{"	
		lxobj[i].gmcObjVerts in_file --取顶点
		line=readline in_file -- 跳过一行	"}"
	)-- end for
	  return	lxobj
)
fn mainFunc argName des fmc=(
    lx_objs = #()
    if doesFileExist argName then
    ( 
        in_name = argName
        
        lxfileType = getFilenameFile argName
		lxtype = (getFilenameType argName) as name
        ---a_file = openFile in_name
		if lxtype == ".gmb" as name then(
			a_file  = fopen in_name "rb"
			if a_file != undefined then
			(
				lx_objs = readGmbObj a_file	
				fclose a_file 
			)	
		)else if lxtype == ".gmc" as name then(
			a_file = openFile in_name 	
			if a_file != undefined then
			(
				lx_objs = readgmcObj a_file	
				close a_file 
			)
		)
    )else(
        return NULL
    )-- end if 	
    --------------------		创建模型		-----------------------
    lx_meshs =#()
	cmats = multimaterial name: (lxfileType + "_" + lxtype + "_mats")	 numsubs:shas.count--多维材质
	--format "材质总数= % \n"	shas.count
    texPath = lxPath + "ctexture\\"
    for	cnt=1 to 20 do
    (
        if cnt < 10 then
            tmp = ( "0" + (cnt as string))
        else
            tmp = cnt as string
        if	lxfileType == ("sn" + tmp) then
        (
            texPath = lxPath +	lxfileType + "\\"
            break
        )
    )
    for  itx=1 to shas.count do
    (
        tname=""
        if	shas[itx].Tex != "" then
        (
            tname = texPath + shas[itx].Tex
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
        lx_meshs[i] = mesh name:lx_objs[i].nam vertices:lx_objs[i].verts faces:lx_objs[i].faces materialIDs: lx_objs[i].face_mat tverts:lx_objs[i].uvs
        lx_meshs[i].material = cmats
            
            for  itx=1 to shas.count do
            (
                showTextureMap lx_meshs[i].material[itx]		on	--cmat[itx] meditMaterials[itx].diffuseMap on 
            )
            
        update lx_meshs[i]
            
        if	lx_objs[i].uvs.count == 0 then
        (
            format	" === 对象[%]	 % 没有纹理顶点 \n"	i	lx_objs[i].nam
            continue
        )
        BUILDTVFACES 	lx_meshs[i]	-- FALSE

        for f = 1 to lx_objs[i].faces.count do
        (
            setFaceNormal	lx_meshs[i]		f	lx_objs[i].faces_n[f]
            setFaceMatID 	lx_meshs[i] 	f 	(lx_objs[i].face_mat[f] + 0)
            SETTVFACE	 	lx_meshs[i] 	f	lx_objs[i].faces[f]
        )
        update lx_meshs[i]

        setNumCPVVerts lx_meshs[i] lx_meshs[i].numverts
		defaultVCFaces lx_meshs[i]
		if lx_objs[i].vc.count > 0 then
		(
            for idxcol = 1 to lx_objs[i].vc.count  do
            (
                setVertColor lx_meshs[i] idxcol lx_objs[i].vc[idxcol]
            )
		)
    )-- end for
	if des then(
		inpath = getFilenamePath argName
		inname = getFilenameFile argName
		desname = inpath + inname + ".des"
		if doesFileExist desname then
		( 
			getdes desname
		)	
	)
	if fmc then(
		inpath = getFilenamePath argName
		inname = getFilenameFile argName
		fmcname = inpath + inname + ".fmc"
		if doesFileExist desname then
		( 
			getfmc fmcname
		)	
	)	
	disableSceneRedraw()	---------   取消重画, 可以提高速度,必须再用 enableSceneRedraw() 打开重画
	enableSceneRedraw()	---------------- 充许重画
)	-- end function mainFunc

fn  getLxPath  cfgPath=
(
	fname = getOpenFileName types:"流星模型文件 (*.gmb,*.gmc)|*.gmb;*.gmc|All (*.*)|*.*|" caption:"请选择流星蝴蝶剑模型文件"
	if fname == undefined then return NULL
	lxPath = getFilenamePath fname	--取得流星主目录
	
	out_cfg_file = createfile 	cfgPath
	-- 创建配置文件
	if out_cfg_file == undefined then return NULL
	format "%\n"  lxPath  to: out_cfg_file
	close out_cfg_file 
	-- 结束创建
	fs= getFiles (lxPath + "\*.gm*") 
	return fs
)

rollout param1 "导入" width:720 height:270
(
	listbox 'lbx1' "文件（双击文件导入）" pos:[5,5] width:700 height:20
	button 'btn1' "开始导入" pos:[610,370] width:94 height:32 align:#left
	button 'btn2' "选择路径" pos:[496,370] width:94 height:32 align:#left
	checkbox 'des' "根据des文件设置模型坐标轴 (如果有)" pos:[5,270] width:330 height:14 align:#left checked:true
	checkbox 'fmc' "导入fmc文件中的动画 (如果有，max存在同名对象时动画会出错，推荐勾选清空)" pos:[5,290] width:630 height:14 align:#left checked:true
	checkbox 'del' "清空max中现有的模型 (无法撤消，注意保存文件)" pos:[5,310] width:330 height:14 align:#left checked:false
	label titleLabel1 "贴图文件目录规则如下：\n道具：放在gmb/gmc目录下 ctexture 文件夹中\n地图：地图gmb目录下gmb同名文件夹中 (如sn01.gmb放在gmb目录下sn01中)" pos:[5,340] width:400 height:48
	on des changed state do(
		if des.checked == false then(
			fmc.checked = false
		)
	)
	on fmc changed state do(
		if fmc.checked == True then(
			des.checked = True
		)
	)
	on param1 open do
	(		
		config_name = "lxmod2max.config"
		cfg_fname= ((GetDir #import)+"/"+config_name)
		if  doesFileExist cfg_fname	then	-- 如果文件存在
		(
			in_text = openfile  cfg_fname --打开配置文件
			while not eof in_text do
			( 
				lxPath = readline in_text
				exit
			) 
			close in_text 
			file_array = getFiles (lxPath + "\*.gm*") 
			if file_array == undefined then return NULL
			tmp =#()
			lbx1.Items =#()
			for lf in file_array do(
				append tmp  lf
			)
			lbx1.Items = tmp
		)else(
			file_array = getLxPath cfg_fname
			if file_array == undefined then return NULL
			tmp =#()
			lbx1.Items =#()
			for lf in file_array do(
				append tmp  lf
			)
			lbx1.Items = tmp
		)
	)
	on btn1 pressed do
	(
		retFile = lbx1.Items[ lbx1.selection ]
		if( retFile != undefined )then(
			if del.checked then (delete $*)
			mainFunc retFile des.checked fmc.checked
		)
	)
	on btn2 pressed do
	(
		config_name = "lxmod2max.config"
		cfg_fname= ((GetDir #import)+"/"+config_name)
		file_array = getLxPath cfg_fname
		if file_array == undefined then return NULL
        lbx1.Items = #()
        tmp = #()
		for lf in file_array do
		(
			append tmp  lf
		)
        lbx1.Items = tmp
	)
	on lbx1 doubleClicked sel do
	(
	    retFile = lbx1.Items[ lbx1.selection ]
		if del.checked then (delete $*)
		mainFunc retFile des.checked fmc.checked--打开双击的文件
	)
)
rollout param2 "关于" width:720 height:270
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
	label titleLabel3 "by 漠之北" pos:[640,400] width:60 height:16
)

if floater != undefined do
(
closerolloutfloater floater
)
floater = newrolloutfloater "流星模型导入 v0.3(测试版)" 720 440
addrollout param1 floater rolledUp:false
addrollout param2 floater rolledUp:true


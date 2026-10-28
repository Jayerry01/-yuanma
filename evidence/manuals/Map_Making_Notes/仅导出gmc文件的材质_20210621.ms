--	************************************************************************
--	脚本仅用于辅助 gmc导出插件生成的错误多为材质问题_v1.1
--	作者：yish
--	修改：过山河。
--	
--	使用方法：
--	需要运行两次，才能正常导出mat文件。将此脚本生成的mat文件中所有内容覆盖到
--	由gmc导出插件生成的错误材质。切记要完整覆盖。无需添加【顶点绘制】修改器
--	且只对小材质数值差距不大的地图有效。若双方gmc材质数量相差几倍大，则无法替换！
--	比如由脚本生成的材质数量是15，而由gmc导出插件生成的是355。则无法使用替换法替换！
--	适合小规模、单模型，等不多材质的地图
--	详细操作请查看【流星蝴蝶剑地图制作基本流程 + 各种技巧】
--
--	************************************************************************

exportName =""		--导出mat的文件名


struct	LX_Tex(
	tex,	col,	amb,	dif, 	spe,	emi,	opacity,	option,		twoside
)

lxTexs=	 #()

if ((queryBox "材质导出脚本: \n\r\n" title:"辅助gmc插件生成的错误材质" beep:false) ==false )
	then return false

--	==================================================================================================
--																							取材质
--	==================================================================================================

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
		aTex.col	=	m.filterColor	
		aTex.amb	=	m.ambient 	 	/	255.0		
		aTex.dif	=	m.diffuse 		/	255.0		
		aTex.spe	=	m.specular 		/	255.0		
		aTex.emi	=	m.selfIllumColor	/	255.0	

		aTex.opacity	=	m.opacity 	/	100.0		
		aTex.twoside	=	m.twoSided		
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
			aTex.col	=	m.materialList[i].filterColor	


			aTex.amb	=	m.materialList[i].ambient 	 	/	255.0		
			aTex.dif	=	m.materialList[i].diffuse 		/	255.0		
			aTex.spe	=	m.materialList[i].specular 		/	255.0		
			aTex.emi	=	m.materialList[i].selfIllumColor	/	255.0	

			aTex.opacity	=	m.materialList[i].opacity 	/	100.0		
			aTex.twoside	=	m.materialList[i].twoSided		
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
			

		)
	)
)

--	==================================================================================================
--																						开始导出
--	==================================================================================================

fn exportLx	arg=
(
	out=#()
	out=selectByName title:"全选模型" ButtonText:"导出" --filter:objfilt obj
	
if (out==undefined or out.count <=0 ) then 	(MessageBox("警告:未选择任何对象,无法导出!") title:"警告!" beep:false;		return false)

	out_name = getSaveFileName types:"*.mat (*.mat)|*.mat|All (*.*)|*.*|" caption:"导出mat文件"
	if out_name == undefine then (MessageBox("警告:不能取得保存文件的名称,无法导出!") title:"警告!" beep:false;return false)
	
	exportName	=	getFilenameFile	out_name
	out_file =  createfile 		out_name
	format "	*******	调试输出	 步骤=%	,	%\n" 		"创建输出文件"	out_name

-- 开始导出
	format "# GModel Geometry File V1.0\n"	to:out_file	
	format "# mat 2 fix gep\n"	to:out_file	
	numsel=out.count
	
	format "	*******	调试输出	 步骤=%	,	%\n" 	"计算选定物体总数 ="  	numsel  	
-----------------------------------------------------------------------------------------
---- 						写出mat文件
-----------------------------------------------------------------------------------------	
	print " 准备查找材质 %\n"
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
	close out_file
	return true

)	--end fn exportLx



	
--	==================================================================================================
--						Main() 
--	==================================================================================================
if	(exportLx "name" ) then
	Messagebox	" 导出材质成功"
else
	(
		messagebox	"导出失败！按F11查看日志!"
		if  out_file != undefine do	close out_file	
	)
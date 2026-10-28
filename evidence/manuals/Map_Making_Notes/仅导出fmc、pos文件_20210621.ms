--	************************************************************************
--	脚本仅用于导出fmc和pos文件，辅助gmc导出插件，以减少材质错误的概率_v1.0
--	作者：yish
--	修改：过山河。
--	
--	使用方法：
--	本脚本无需添加【顶点绘制】修改器，直接拖放到3dsmax中即可
--	详细操作请查看【流星蝴蝶剑地图制作基本流程 + 各种技巧】
--
--	************************************************************************

scenceObjCount = 0	--	场景对象总数
dummyObjCount =	0	--	辅助对象总数
exportObjList =#()	--	导出文件列表
exportName =""		--	用户所起的导出文件名，在第一步导出gmc时指定，以后2步自动记忆


struct	LX_Tex(
	tex,	col,	amb,	dif, 	spe,	emi,	opacity,	option,		twoside
)
lxTexs=	 #()
--=========================

if ((queryBox "pos、fmc专用导出脚本: \n--1，可选导入3ds格式，\n--2，必须有纹理坐标\n--3，可选动画\r\n" title:"流星.net动画(fmc、pos)导出专用脚本_20210621" beep:false) ==false )
	then return false
	
	
--	==================================================================================================
--																			导出 fmc 道具动画
--	==================================================================================================
fn	ExportAnim 	objList	=(
	
--	out_name = getSaveFileName 	filename:exportName		types:"流星fmc动画*.fmc (*.fmc)|*.fmc" caption:"导出fmc文件"
	out_name = exportName + ".fmc"
	
	if out_name == undefine then 
		(MessageBox("警告:不能取得保存文件的名称,无法导出!") title:"警告!" beep:false;return false)
	
	out_file =  createfile 		out_name
	
--	====================== 开始导出 fmc 动画================================	
	
	format "	*******	调试输出	 步骤=%	,	%\n" 		"创建	fmc	输出文件"	out_name
 
	format "# GModel Animation File V1.0\n"		to:out_file	
	format "# by yish for 2011-04-05\n"			to:out_file	
	

	format "SceneObjects % DummeyObjects %\n"		scenceObjCount		dummyObjCount		to:out_file	
	
	frameCount = ((animationRange.end - animationRange.start) as integer) / 160
	
--	FPS控制播放速度，frameRate可以整除2，以减慢播放速度。默认已降低一半速度

	tmpFrameRate = frameRate / 2
	format "FPS % Frames % Mode: %\n"		tmpFrameRate		frameCount		"RIGID"		to:out_file	
	
	
	Animate On
	
	local	frameStep = 0
	
	for  t	= animationRange.start	to animationRange.end do
	(
		
		at time t 	
		(
			--	 t    13.121    -4.328    13.278 q -1.00000  0.00000  0.00000  0.00000
			
			format "frame %\n"		frameStep			to:out_file	
			format "{\n"							to:out_file	
			
			
				for k=1 to objList.count do
				(
					pos = objList[k].pos
					rot = objList[k].rotation		--	流星四元序是 w,x,y,z  		max是 x,y,z,w
					
--烛火OP添加  2021年6月5日00:38:15 Begin
-- 解决科学计数法的输出问题
					if  pos.x < 0.0001 then (	if pos.x>-0.0001 then		(pos.x=0 )	)
					if  pos.y < 0.0001 then (	if pos.y>-0.0001 then		(pos.y=0 )	)
					if  pos.z < 0.0001 then (	if pos.z>-0.0001 then		(pos.z=0 )	)
--烛火OP添加  2021年6月5日00:38:57 End
					format "  t    %    %    % q %  %  %  %\n"		 pos.x		pos.y		pos.z	rot.w	rot.x	rot.y	rot.z			to:out_file	
				) 
			format "}\n"							to:out_file	

			
		)
		frameStep = frameStep + 1
	)
	Animate off
--		animationRange.start	or	.end
	
	close out_file
--	MessageBox("FMC 完成导出!") title:"完成!" beep:false

)

--	==================================================================================================
--																						导出 Pos 声明
--	==================================================================================================

	
--////////////////////////////////////////////////////////////////////////////////////
	fn	ExportPos 	objList	=(
	
--	out_name = getSaveFileName 	filename:exportName		 types:"流星pos声明*.pst (*.pos)|*.pos" caption:"导出pos文件"
	out_name = exportName + ".pos"
	
	if out_name == undefine then 
		(MessageBox("警告:不能取得保存文件的名称,无法导出!") title:"警告!" beep:false;return false)
	
	out_file =  createfile 		out_name
	
--	====================== 开始导出 pst	声明 ================================	
	
	format "	*******	调试输出	 步骤=%	,	%\n" 		"创建 pos 输出文件"	out_name
 
 	frameCount = ((animationRange.end - animationRange.start) as integer) / 160
 
	format "pose\n"											to:out_file
	format "{\n"												to:out_file
	format "	start 0\n"								to:out_file
	format "	end 0\n"									to:out_file
	format "}\n"												to:out_file	
	
	format "pose\n"											to:out_file
	format "{\n"												to:out_file
	format "	start 0\n"								to:out_file
	format "	end %\n"		frameCount		to:out_file
	format "}\n"												to:out_file	

	
	close out_file
)


--	==================================================================================================
--																						开始导出
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


	out_name = getSaveFileName types:"流星模型*.fmc (*.fmc)|*.fmc|All (*.*)|*.*|" caption:"导出fmc文件"
	if out_name == undefine then 
		(MessageBox("警告:不能取得保存文件的名称,无法导出!") title:"警告!" beep:false;return false)
	
	
	exportName	=	getFilenameFile	out_name
	
	
	out_file =  createfile 		out_name
	format "	*******	调试输出	 步骤=%	,	%\n" 		"创建输出文件"	out_name

scenceObjCount = out.count
dummyObjCount =	0



-----------------------------------------------------------------------------------------
----					 												全部结束
-----------------------------------------------------------------------------------------

	
	--	***************	 开始导出	fmc**************
	format "fmc begin	\n"		
	ExportAnim		exportObjList

	--	***************	fmc 导出完毕，开始导出	pos**************

	format "pos begin	\n"		
	ExportPos		exportObjList
	
	
	return true

)	--end fn exportLx

	
--	==================================================================================================
--						Main() 
--	==================================================================================================
if	(exportLx "name" ) then
	Messagebox	" 导出成功 !"
else
	(
		messagebox	" ***	[Err]	导出失败，请查看运行日志!"
		if  out_file != undefine do	close out_file	
	)
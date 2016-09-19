@echo off
REM *******************************************************************************************************************
REM FILE DESCRIPTION
REM -------------------------------------------------------------------------------------------------------------------
REM File:         Testplan_BaselineTest.bat
REM Description:  
REM -------------------------------------------------------------------------------------------------------------------
REM REVISION HISTORY
REM -------------------------------------------------------------------------------------------------------------------
REM 01.00.00  2009-10-23  vismas  initial version
REM *******************************************************************************************************************
set CDP.File=%0
set CDP.Name=TestPlan
set CDP.Version=1.00.00
set CoverageKind=NONE

REM *******************************************************************************************************************
if "%TestPlanInitIsCalled%"=="" (
  set TestPlanInitIsCalled=true
  setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION
  call :TscStandardConfiguration
)
if not "%1"=="" (
  goto :%1
)
goto :Default


REM *******************************************************************************************************************
:CheckVariants
  call :TscStandardConfiguration
  set EmbeddedSystem.TestData.SelectionType=iterate
  Set AskAndLogTestResult.PreSelect=o
  cd %~dp0
  set EmbeddedSystem.TestData.SelectionPath=%TestSuite.EmbeddedSystem.Path%\TestData_Storage
  call CDM EmbeddedSystem checkVariantCoverage  
  cd %~dp0 
  goto :EOF

REM *******************************************************************************************************************
:ExecuteTests
  call :TscStandardConfiguration
  set CDP.Report.File=%TestReport.Path%\TestReport_Stub.vtr
  set CDP.Report.Type=structured
  Set AskAndLogTestResult.PreSelect=o
  set EmbeddedSystem.TestData.SelectionType=iterate
  cd %~dp0
  set EmbeddedSystem.TestData.SelectionPath=%TestSuite.EmbeddedSystem.Path%\TestData_Storage
  call CDP_GenericDefaults.bat
  call CDM Common InitTestReport
  
  set EmbeddedSystem.TestData.SourcePath=%2
    
  Call CDM EmbeddedSystem GUI_Executor CheckQAC
  cd %~dp0\EmbeddedSystem
  Call CDM EmbeddedSystem GUI_Executor CheckVectorCodingRules
  cd %~dp0\EmbeddedSystem
  rem Call CDM EmbeddedSystem GUI_Executor checkPClint 
  cd %~dp0\EmbeddedSystem
  Call CDM Bswmd GUI_Executor StartBswmdChecker 
  cd %~dp0\EmbeddedSystem
  Call CDM EmbeddedSystem GUI_Executor execute
  cd %~dp0\EmbeddedSystem
  
  
  Call CDM Vtr Convert2StandardHtml_Silent "%CDP.Report.File%"
  goto :EOF

REM *******************************************************************************************************************
:Default
  if "%CDP.CalledFromVisualStudio%"=="true" (
    set CDP.Report.File=%TestReport.Path%\Test_Temp.vtr
    set CDP.Report.Type=structured
    call CDP_GenericDefaults.bat
    call CDM Common InitTestReport
    call CDM Testplan StartTest_EmbeddedSystem
  ) else (
    set CDP.Report.File=%TestReport.Path%\TestReport_Stub.vtr
    set CDP.Report.Type=structured
    call CDP_GenericDefaults.bat
    call CDM Common InitTestReport
    call CDM Testplan Overview
  )
goto :EOF

REM *******************************************************************************************************************
:TscStandardConfiguration
  set TscStandard.Path=%~dp0
  echo %TscStandard.Path%

  set Component.Name=DrvTrans_Tja1080FrdioAsr
  set Component.AutosarName=FrTrcv_30_Tja1080
REM Added for SafeBsw process as presented in SafeBsw Meeting
  set Process=Safe

  set Component.TestSpec.Path=%TscStandard.Path%..\..\20_Design
  set Description.Path=%EmbeddedSystem\FrTrcv_30_Tja1080\external\BSWMD\FrTrcv_30_Tja1080
  set Doc_TechRef.Path=%TscStandard.Path%..\Doc_TechRef
  set GenTool_GENy.Path=%TscStandard.Path%..\..\..\internal\GenTool_GENy
  set Implementation.Path=%TscStandard.Path%EmbeddedSystem\FrTrcv_30_Tja1080
  set Kon.Path=%TscStandard.Path%..\Kon
  set Make.Path=%TscStandard.Path%..\..\..\external\BSW\%Component.AutosarName%\mak
  set TestReport.Path=%TscStandard.Path%TestReport
  set TsiStandard.Path=%TscStandard.Path%..\TsiStandard
  set TestSuite.EmbeddedSystem.Path=%TscStandard.Path%EmbeddedSystem
  set TestSuite.GENySystem.Path=%GenTool_GENy.Path%
  set GENySystem.TestEnv.ComponentPath=%TscStandard.Path%..\..\..\external\Generators\Components
  set GENySystem.GENyFile=%TscStandard.Path%EmbeddedSystems\TestData_Storage
  set GENySystem.TestEnv.FrameworkExe=%GenTool_GENy.Path%\GENy.exe
  set TestSuite.KonSystem.Path=%TscStandard.Path%Kon

  set EmbeddedSystem.TestData.SelectionPath=%TestSuite.EmbeddedSystem.Path%\TestData_Storage\Tja1080_Cfg5_000\Appl\GenData %TestSuite.EmbeddedSystem.Path%\TestData_Storage\Tja1080_Cfg5_001\Appl\GenData %TestSuite.EmbeddedSystem.Path%\TestData_Storage\Tja1080_Cfg5_002\Appl\GenData %TestSuite.EmbeddedSystem.Path%\TestData_Storage\Tja1080_Cfg5_003\Appl\GenData
  
  set EmbeddedComponent.Path=FrTrcv_30_Tja1080
  set EmbeddedComponent.StaticSource.List=%EmbeddedComponent.Path%\FrTrcv_30_Tja1080.c %EmbeddedComponent.Path%\FrTrcv_30_Tja1080_Phy.c
  set EmbeddedComponent.StaticHeader.List=%EmbeddedComponent.Path%\FrTrcv_30_Tja1080.h %EmbeddedComponent.Path%\FrTrcv_30_Tja1080_Cbk.h %EmbeddedComponent.Path%\FrTrcv_30_Tja1080_Phy.h
  set EmbeddedComponent.DynamicSource.List=TestData\FrTrcv_30_Tja1080_Cfg.c
  set EmbeddedComponent.DynamicHeader.List=TestData\FrTrcv_30_Tja1080_Cfg.h
  
  set COVFILE=%TscStandard.Path%_Temp\FrTrcv_30_Tja1080.cov

  call CDP_GenericDefaults.bat

  set EmbeddedSystem.TestEnv.FileList=%Bte_FileList% TestAppl\TscAppl.c TestAppl\TscPbData.c TestAppl\TscTest.c TestEnv_Stub\TscCom.c TestEnv_Stub\TscDio.c TestEnv_Stub\TscIcu.c  TestEnv_Stub\TscDem.c TestEnv_Stub\TscDet.c TestEnv_Stub\TscEcuM.c TestEnv_Stub\TscSchM.c
  set EmbeddedSystem.IncludeList=%EmbeddedComponent.Path% TestAppl TestData TestEnv_Stub TestFw\zBte TestObj
  set EmbeddedSystem.TestDataCollection.Path=%EmbeddedSystem.Path%\TestData_Storage
  set EmbeddedSystem.CheckPClint.FileList=%EmbeddedComponent.OverallSource.List% TestAppl\TscAppl.c
  set EmbeddedSystem.CheckPClint.UserOptions=-e537
  set EmbeddedSystem.CheckVectorRules.UserOptions=-v15
  set EmbeddedSystem.BuildVC8Lib.LibName=FrTrcv_30_Tja1080.lib
  set EmbeddedSystem.BuildVC8Lib.LibFileList=FrTrcv_30_Tja1080.obj TscAppl.obj TscTest.obj
  set EmbeddedSystem.VC.Project=%TscStandard.Path%EmbeddedSystem\TestEnv_Stub.vcxproj
  set EmbeddedSystem.CheckVectorRules.UserOptions=-v6 -v12 -v15

  set Baseline.VAP.Use=1
  set Baseline.ComponentTarget.Path=.\_slp\SysService
goto :EOF

REM *******************************************************************************************************************
REM Name:         CDP_UserOverview
REM Description:  
REM Parameter:    
REM *******************************************************************************************************************
:CDP_UserOverview
  echo   u1      GHS codeOptim
  echo   u2      Sample
  echo   u3      CheckVariants
goto :EOF

REM *******************************************************************************************************************
REM Name:         CDP_UserSelect
REM Description:  
REM Parameter:    
REM *******************************************************************************************************************
:CDP_UserSelect
  set CDP.UserSequence.Name=
  if "%SELECTION%"=="u1"        set CDP.UserSequence.Name=GHScodeOptim
  if "%SELECTION%"=="u2"        set CDP.UserSequence.Name=Sample
  if "%SELECTION%"=="u3"        set CDP.UserSequence.Name=CheckVariants
goto :EOF

REM *******************************************************************************************************************
REM Name:         CDM_PreHandler
REM Description:  
REM Parameter:    
REM *******************************************************************************************************************
:CDM_PreHandler
goto :EOF

REM *******************************************************************************************************************
REM Name:         CDM_PreHandler
REM Description:  
REM Parameter:    
REM *******************************************************************************************************************
:CDM_TCPreHandler
goto :EOF

:Sample
  set EmbeddedSystem.GreenHill.cFlags=-Ospace -O -needprototype -Wundef -dual_debug --long_long -registermode=22
  set TC.Parameter=config=%EmbeddedSystem.ActiveTestData.Reference%, compileFlags=%EmbeddedSystem.GreenHill.cFlags%
  call CDM EmbeddedSystem buildGreenHills
goto :EOF


REM *******************************************************************************************************************
REM Name:         GHScodeOptim
REM Description:  
REM Parameter:    
REM *******************************************************************************************************************
:GHScodeOptim
  set EmbeddedSystem.GreenHill.cFlags=-Ospace -O -needprototype -Wundef -dual_debug --long_long -registermode=22
  set TC.Parameter=config=%EmbeddedSystem.ActiveTestData.Reference%, compileFlags=%EmbeddedSystem.GreenHill.cFlags%
  call CDM EmbeddedSystem buildGreenHills

  set EmbeddedSystem.GreenHill.cFlags=-Ospace -O -needprototype -Wundef -dual_debug --long_long -registermode=22
  set TC.Parameter=config=%EmbeddedSystem.ActiveTestData.Reference%, compileFlags=%EmbeddedSystem.GreenHill.cFlags%, customer=DC
  call CDM EmbeddedSystem buildGreenHills
goto :EOF

REM *******************************************************************************************************************

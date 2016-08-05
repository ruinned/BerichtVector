@echo off
setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION

call CDK_GenericConfig.bat
call CDM ConfigMatrixTxt Run %~dp0ConfigMatrix.txt

pause
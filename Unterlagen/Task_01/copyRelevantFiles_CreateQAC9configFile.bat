@echo off
echo copy files from QAC7.0-version-analysis or create new QAC9.0 
echo project files
echo.
echo.
echo copy files from QAC7.0-version-analysis = 1
echo.
echo create new QAC9.0 project files = 2
echo.
set re=
set /p re=what do you need to do?:
if %re%==1 goto :COPY_FILES
if %re%==2 goto :CREATE_PROJECTFILES
pause
exit

:COPY_FILES
echo create a folder with the files to be analysed
echo.
perl "%~dp0script_copy_v1.1.pl"
goto :endoffile
:CREATE_PROJECTFILES
echo create new QAC9.0 project files
echo.
perl "%~dp0script_copy_v1.4.pl"
goto :endoffile
:endoffile
pause
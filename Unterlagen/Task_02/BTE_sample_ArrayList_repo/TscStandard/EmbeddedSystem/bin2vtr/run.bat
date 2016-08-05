@echo off
rem the following command can be used if the file test.bin dosn´t lies in the same path like the perl file
rem perl bin2xml_v2.pl "%~d0..\_Temp\VC_X_Asr4Msn\test.bin" AnwenderFile1.txt 
rem the following command can be used if the files in the parameter lies in the same path like the perl file
perl bin2xml_v2.pl test.bin AnwenderFile1.txt BteReport_Log.xml
pause
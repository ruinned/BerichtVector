@echo off
rem screenshot
rem "%~dp0\nircmd-x64\nircmd.exe" savescreenshot screen.jpg
"%~dp0\jpeg2pdf\jpeg2pdf.exe" -o new.pdf -p auto -n portrait -z none -r height QAC8.jpg
rem "%~dp0\jpeg2pdf\jpeg2pdf.exe" 2016-06-12.png -o 2016_06_12.pdf
java -jar "%~dp0\briss-0.9\briss-0.9.jar" -s new.pdf -d QAC8.pdf
rem java -jar "%~dp0\briss-0.9\briss-0.9.jar" new.pdf
pause
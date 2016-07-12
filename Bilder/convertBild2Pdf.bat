@echo off
rem "%~dp0jpeg2pdf\jpeg2pdf.exe" -o %1.pdf -p auto -n portrait -z none -r height %1.%2
"%~dp0jpeg2pdf\jpeg2pdf.exe"  %1.%2 -o %1.pdf
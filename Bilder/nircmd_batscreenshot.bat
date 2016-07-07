nircmd cmdwait 3000 savescreenshot "%~dp0%1.jpg"
call mspaint "%1.jpg"
call cmdwait 20000
"%~dp0\jpeg2pdf\jpeg2pdf.exe" -o new.pdf -p auto -n portrait -z none -r height %1.jpg
java -jar "%~dp0\briss-0.9\briss-0.9.jar" -s new.pdf -d %1.pdf
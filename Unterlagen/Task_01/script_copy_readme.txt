v0
- Programm zum Trennen von Zeileinhalt �ber \ und ausw�hlen des letzten Eintrag des Arrays

v1.0
- Gleiche grundlegende Funktionalit�t wie v0
- Untermethode "suche" funktioniert
- Funktionst�chtige �betragung eines Files, der sich auf dem Pfad des Perl-Files befindet, auf den Zielornder 

v1.1
- Gleiche grundlegende Funktionalit�t wie v0
- �bertragung von Dateien, die sich iwo im Computer befinden, auf einen Zielordner

v1.2
- �berschreiben einer Zieldatei funktioniert
- Falls bestimmte Zeilen einer Datei �berschrieben werden m�ssen, ist es besser, die zu �ndernde Datei
zu kopieren, die richtige Eintr�ge anzupassen und danach am besten eine neue Datei aufzumachen und die 
Inhalte anpassen.
- Mit dieser Datei wird die Zieldatei SCHREIBEN (*.prj) �berschieben und mit den richtigen Eintr�gen 
zur QAC-Analyse eingef�hrt

v1.3
- Diese Version m�chte ich verwenden, um Dateien von einem Quellorder in einen anderen zu �bertragen
- Die Methoden funktionieren, damit alle vohandene Header- bzw. Sourcefiles in den 
Zielordner kopiert werden

v1.4
- Mit dieser Version wird von einer vorhandenen xml-Datei, die sich im Verzeichnis der
perl-Datei befindet, ein Teil in eine andere xml-Datei(prqaproject_copy.xml) kopiert und noch
ein paar Zeilen hinzugef�gt.

v1.5
- Mit dieser Version wird �ber die xml-Datei nach bestimmten Pattern gesucht und die Zeilen ausgegeben.
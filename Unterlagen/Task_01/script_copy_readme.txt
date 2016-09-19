v0
- Programm zum Trennen von Zeileinhalt über \ und auswählen des letzten Eintrag des Arrays

v1.0
- Gleiche grundlegende Funktionalität wie v0
- Untermethode "suche" funktioniert
- Funktionstüchtige Übetragung eines Files, der sich auf dem Pfad des Perl-Files befindet, auf den Zielornder 

v1.1
- Gleiche grundlegende Funktionalität wie v0
- Übertragung von Dateien, die sich iwo im Computer befinden, auf einen Zielordner

v1.2
- Überschreiben einer Zieldatei funktioniert
- Falls bestimmte Zeilen einer Datei überschrieben werden müssen, ist es besser, die zu ändernde Datei
zu kopieren, die richtige Einträge anzupassen und danach am besten eine neue Datei aufzumachen und die 
Inhalte anpassen.
- Mit dieser Datei wird die Zieldatei SCHREIBEN (*.prj) überschieben und mit den richtigen Einträgen 
zur QAC-Analyse eingeführt

v1.3
- Diese Version möchte ich verwenden, um Dateien von einem Quellorder in einen anderen zu Übertragen
- Die Methoden funktionieren, damit alle vohandene Header- bzw. Sourcefiles in den 
Zielordner kopiert werden

v1.4
- Mit dieser Version wird von einer vorhandenen xml-Datei, die sich im Verzeichnis der
perl-Datei befindet, ein Teil in eine andere xml-Datei(prqaproject_copy.xml) kopiert und noch
ein paar Zeilen hinzugefügt.

v1.5
- Mit dieser Version wird über die xml-Datei nach bestimmten Pattern gesucht und die Zeilen ausgegeben.
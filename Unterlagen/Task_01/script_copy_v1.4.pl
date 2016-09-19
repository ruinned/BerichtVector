#!/Dwimperl/perl/bin/perl.exe -w
use strict;
use Cwd;

my $working = cwd();
my $string1 = "  \<file target=\"C\" name\=\"";
my $string2 = "\" folder\=\"=$working/Relevant\"\/\>";

my $z1 = 0;

# file where the paths of the source and header files are indicated 
open(LESEN1,"$working/Baseline/Folder.prj")
or die "Fehler beim Oeffnen von 'Folder.prj': $!\n";
# default file where the default information of the qac9 project is indicated
open(LESEN2,"prqaproject.xml")
or die "Fehler beim Oeffnen von 'prqaproject.xml': $!\n";

my @zeilen_files = <LESEN1>;
my @zeilen_xml = <LESEN2>;

close(LESEN1);
close(LESEN2);
unlink "prqaproject.xml";	# delete default file, afterwards a new file will be again created


my @var_arr;		#store the splited strings
my @var_arr_files;	#store the strings of the source files
my $var_str;
my $hilfsvar = 0;
my $h1 = 0;	# wird der Anfangpunkt der Source-Pfade
my $h2 = 0;	
my $h3 = 0;	# wird der Endpunkt der Source-Pfade
my $h1_xml = 0;
my $h2_xml = 0;


# es muss ermoeglicht werden, den Punkt zu finden, ab dem die Source-Pfade ausgelesen werden koennen
foreach(@zeilen_files){	# iteriere ueber die Einstellungsdatei
	
	if($_ =~ /CompPers/){	# suche nach dem Muster
		$h3 = $h1;	# wurde der Muster gefunden, dann halte die Zeilenummer -h1- fest und fange eine neue Suche ab dem Ort an
		for (my $p = $h1+1 ;$p < @zeilen_files ; $p++){
			if($zeilen_files[$p] =~ /EndContainedFilesMarker/){
				last;	# verlasse innere for-Schleife
			}
		$h3++
		}
		last;	# verlasse aeussere for-Schleife
	}	
	$h1++;
}


for(my $t = $h1+1;$t <= $h3; $t ++ )	{ #wird ueber Datei iteriert
	
	@var_arr = split(/\\/,$zeilen_files[$t]);	# trenne Zeile in Array ueber \ Zeichen
	# print $zeilen_files[$t]."\n";
	$var_str = $var_arr[$#var_arr];		# bekomme letzter Eintrag des Arrays, also den Namen der c-Datei
	
	$var_arr_files[$t-$h1-1] = $var_str;	# speichere die Namen der Datein in den entsprechenden Eintrag	
	
}	


foreach(@zeilen_xml){	# iteriere ueber die Einstellungsdatei
	
	if($_ =~ /\<\!-- Explicit files... --\>/){	# suche nach dem Muster
		$h2_xml = $h1_xml;	# wurde der Muster gefunden, dann halte die Zeilenummer -h1- fest und fange eine neue Suche ab dem Ort an
		for (my $p = $h1_xml+1 ;$p < @zeilen_xml ; $p++){
			if($zeilen_xml[$p] =~ /\<\/prqaproject\>/){
				last;	# verlasse innere for-Schleife
			}
		$h2_xml++
		}
		last;	# verlasse aeussere for-Schleife
	}	
	$h1_xml++;
}	

print $h1_xml."\n";
print $h2_xml."\n";
	
open(SCHREIBEN,"> prqaproject.xml")
or die "Fehler beim Oeffnen von 'prqaproject.xml': $!\n";


foreach(@zeilen_xml){
	
	if($z1 < $h1_xml+1){	# schreibe die Anfangszeilen zu der Datei
		print SCHREIBEN $zeilen_xml[$z1];
	} else {
		foreach(@var_arr_files){	# schreibe die Namen der Files in die Zieldatei
			chomp($_);
			print SCHREIBEN "$string1".$_."$string2\n";
		}
		print SCHREIBEN " \<\/files\>\n\<\/prqaproject\>";		
		last;
	}
	$z1++;	
}

close(SCHREIBEN) or die "Fehler beim Schliessen von 'prqaproject.xml': $! \n";
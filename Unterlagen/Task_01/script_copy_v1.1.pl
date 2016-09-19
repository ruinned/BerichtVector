#!/Dwimperl/perl/bin/perl.exe -w
use strict;
use File::Copy;
use Cwd;

my $workingdir =cwd();	# find the directory where the script is being run
my $target_loc = "$workingdir/Relevant";	# set the target directory for the files
mkdir $target_loc;

# file where the paths of the source and header files are indicated 
open (PRJ_QAC , "$workingdir/Folder.prj")
or die "Fehler beim Oeffnen von '$workingdir/Baseline/Folder.prj': $!\n";

my @zeilen = <PRJ_QAC>;
my @var_arr;
my $var_str;
# hilfsvariablen
my $h1 = 0;	# wird der Anfangpunkt der Source-Pfade
my $h2 = 0;	
my $h3 = 0;	# wird der Endpunkt der Source-Pfade

# es muss ermoeglicht werden, den Punkt zu finden, ab dem die Source-Pfade ausgelesen werden koennen

foreach(@zeilen){	# iteriere ueber die Einstellungsdatei
	
	my $hola = 4;
	
	if($_ =~ /CompPers/){	# suche nach dem patern
		$h3 = $h1;	# wurde der Patern gefunden, dann halte die Zeilenummer -h1- fest und fange eine neue Suche ab dem Ort an
		for (my $p = $h1+1 ;$p < @zeilen ; $p++){
			if($zeilen[$p] =~ /EndContainedFilesMarker/){
				last;	# verlasse innere for-Schleife
			}
		$h3++
		}
		last;	# verlasse aeussere for-Schleife
	}	
	$h1++;
}

for(my $t = $h1+1;$t <= $h3; $t ++ )	{ #wird ueber Datei iteriert
	
	
	@var_arr = split(/\\/,$zeilen[$t]);	# trenne Zeile in Array ueber \ Zeichen
	$var_str = $var_arr[$#var_arr];		# bekomme letzter Eintrag des Arrays
	
	
	$h2 = $zeilen[$t];
	$h2 =~ tr/\\/\//;
		
	$target_loc = $target_loc."/$var_str";
	
	chomp($target_loc);
	chomp($h2);

	print "$target_loc\n";	# gebe aus, welche Dateien kopiert werden


	copy($h2, $target_loc) or die "File cannot be copied.";
	
	$target_loc = "$workingdir/Relevant";
	
}

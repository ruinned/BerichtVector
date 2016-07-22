#!/Dwimperl/perl/bin/perl.exe -w
use strict;

# open(LESEN1,"probeMISRAmapping.csv")
open(LESEN1,"m3cm-manual-QAC9.0.1_withoutform.txt")
or die "Fehler beim ¨Offnen von 'm3cm-manual-QAC9.0.1_withoutform.txt': $!\n";

my @zeilen_file1 = <LESEN1>;
close(LESEN1);
my @index_MISRA;
my $index = 0;

for(my $t = 220; $t < 939; $t ++ ) { #wird ueber Datei iteriert
	
		if ($zeilen_file1[$t] =~ /MISRA C\:2012/) {
		$index_MISRA[$index] = $t;
		$index ++;
		
		 }
	
	}
	
for(my $t = 0;$t < @index_MISRA; $t ++ ) { #wird ueber Indexes iteriert
	
	
	if ($t ne $index_MISRA[$#index_MISRA]) {	# wenn letzter Eintrag noch nicht erreicht worden ist
		
				for(my $i = $t;$t < @index_MISRA; $t ++ )
		
		 }
	
	}
	
	print "@index_MISRA\n";
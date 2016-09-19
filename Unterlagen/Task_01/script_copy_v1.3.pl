#!/Dwimperl/perl/bin/perl.exe -w
use strict;
use File::Copy;
use File::Find::Rule;

my $tocopy = "D:/usr/Task_01/QAC_Eval/Baseline/Code/Relevant";
my $from = "D:/usr/Task_01/QAC_Eval/Baseline/Code/Relevant/BSW";	# nicht ausfuehren, da dieses Verzeichnis nicht mehr vorhanden

my $working = "C:/Users/visres/Desktop/PERL";
my $hilfsvar;
my @fileshelp_c;
my @fileshelp_h;

opendir( my $DIR, $from ) || die "can't opendir  : $!";
my @files = grep{$_ ne '.' and $_ ne '..' } readdir($DIR);
closedir $DIR;

foreach(@files)	{
	
	@fileshelp_c = <$from/$_/*.c>;
	@fileshelp_h = <$from/$_/*.h>;
	
	foreach(@fileshelp_c){
		
		copy($_, $tocopy) or die "File cannot be copied.";
		print "$_\n";
		
		}
		
	foreach(@fileshelp_h){
	
		copy($_, $tocopy) or die "File cannot be copied.";
		print "$_\n";
		
		}
	
	# copy(@fileshelp_c, $tocopy) or die "File cannot be copied.";
	
	# print "@fileshelp1\n";
	
	
	}


# foreach(@files)	{
	
	# # print "$_\n";
	
	# # $hilfsvar=$from."/$_\n";
	# $hilfsvar=$from."/$_";
	# opendir( my $DIR, $hilfsvar) || die "can't opendir  : $!";
	# @fileshelp1 = grep{$_ ne '.' and $_ ne '..' } readdir($DIR);
	# print "@fileshelp1\n";
	# closedir $DIR;
	
	# # my @fileliste = glob("*.prj");
	
	# }


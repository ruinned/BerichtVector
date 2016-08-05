#!/Dwimperl/perl/bin/perl.exe -w
use strict;

use Cwd;

my $working = cwd();

my $from = $working;
my $Anzahlbytes = -s "$from/test.bin";
my $zeilen_binary;
my @chars;

# get user login data an actual time
my $login = getlogin;
my $now_string = localtime;

my $str_log = "\<log\>";
my $str_log_e = "\<\/log\>";

# open file in binary mode
open(LESEN1,"$from/test.bin")
or die "Fehler beim Oeffnen von 'test.bin': $!\n";
binmode(LESEN1);
read(LESEN1, $zeilen_binary, $Anzahlbytes);
close(LESEN1);

# create byte array
@chars = split("", $zeilen_binary);

# array data proccessing method 
ProcessArray(@chars);

sub ProcessArray
{

	my $end_str = chr(hex '5C').chr(hex '6E');
	my $testcase_str = chr(hex '66');
	my $type_str0 = chr(0);
	my $type_str1 = chr(1);
	my $type_str2 = chr(2);
	my $type_str3 = chr(3);

	if(@_)
	{
		ProcessTestCase();
		
	}
	if(@_)
	{
		ProcessEvent();
		
	}
	
}

sub ProcessTestCase
{
	my $str_testcase1 = "\<testcase id\=\"";
	my $str_testcase2 = "\"\>";
	my $str_testcase_e = "<\/testcase>";
	my $str_testrun1 = "\<testrun date\=\"".$now_string."\" executor\=\"".$login."\" parameter=\"\">";
	my $str_testrun_e = "<\/testrun>";	
	
}

sub ProcessEvent
{
	my $str_elem1 = "\<Element type=\"";
	my $str_elem2 = "\" time\=\"";
	my $str_elem3 = "\">";
	my $str_elem_e = "</Element>";
	
}
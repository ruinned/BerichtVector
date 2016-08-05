#!/Dwimperl/perl/bin/perl.exe -w
use strict;

use Cwd;

my $working = cwd();

my $from = $working;
my $Anzahlbytes = -s "$from/test.bin";
my $counter;
my $counter2 = 5;
my $numParam;
my $codeLogList;
my $dataLogList;
my $type;
my $time;
my $id;		# setzt sich aus comp und code zusammen
my $data1;
my $data2;
my $data3;
my $data4;
my $data5;
my $zeilen_binary;
my $data_length = 4; # maximal data length in bytes
my $testarea_check = 0;	# hilft mir dabei, den die Zwei Kennwerte des testcases zu beschreiten
my @chars;

my $end_str = chr(hex '5C').chr(0).chr(0).chr(0).chr(hex '6E').chr(0).chr(0).chr(0);
my $testcase_str = chr(hex '66').chr(0).chr(0).chr(0).chr(hex '66').chr(0).chr(0).chr(0);
my $data1_str = chr(hex '21').chr(0).chr(0).chr(0);
my $data2_str = chr(hex '22').chr(0).chr(0).chr(0);
my $data3_str = chr(hex '23').chr(0).chr(0).chr(0);
my $data4_str = chr(hex '24').chr(0).chr(0).chr(0);
my $data5_str = chr(hex '25').chr(0).chr(0).chr(0);
my $type_str0 = chr(0);
my $type_str1 = chr(1);
my $type_str2 = chr(2);
my $type_str3 = chr(3);

# get user login data an actual time
my $login = getlogin;
my $now_string = localtime;

my $str_testcase1 = "\<testcase id\=\"";
my $str_testcase2 = "\"\>";
my $str_testcase_e = "<\/testcase>";
my $str_testrun1 = "\<testrun date\=\"".$now_string."\" executor\=\"".$login."\" parameter=\"\">";
my $str_testrun_e = "<\/testrun>";
my $str_elem1 = "\<Element type=\"";
my $str_elem2 = "\" time\=\"";
my $str_elem3 = "\">";
my $str_elem_e = "</Element>";
my $str_log = "\<log\>";
my $str_log_e = "\<\/log\>";



# my $login = getlogin;
# my $now_string = localtime;

# open file in binary mode
open(LESEN1,"$from/test.bin")
or die "Fehler beim ¨Offnen von 'test.bin': $!\n";
binmode(LESEN1);
read(LESEN1, $zeilen_binary, $Anzahlbytes);
close(LESEN1);
@chars = split("", $zeilen_binary);
# @chars = sort @chars;
# @chars[$zeilen_binary-1,0] = @chars[0,$zeilen_binary-1];
# print @chars;

open(SCHREIBEN,"> BteReport_Log.xml")
or die "Fehler beim ¨Offnen von 'BteReport_Log.xml': $!\n";

my $itervar = $data_length;
my $controlflow_testcase = 0;
for (my $i = $data_length; $i < @chars ; $i = $i + 2*$data_length)	# die 2 bei der Erhoehung von i bezeichnet die Elemente des stBteEventLog-Liste 
{	
	
	# testcase check
	if(substr($zeilen_binary,$i,$data_length*2) eq $testcase_str) # falls naechste 8 Bytes dem testcase byte entsprechen
	{
		if($controlflow_testcase == 0){ # tastcase Initialisierung
			print "$str_testcase1\n";
			print "$str_testrun1\n";
			print "$str_log\n";
			print SCHREIBEN "$str_testcase1\n";
			print SCHREIBEN $str_testrun1."\n";
			print SCHREIBEN $str_log."\n";			
			$controlflow_testcase = 1;	
		} 
		else # Schleife wird ausgefuehrt, nachdem Programm gestartet wurde
		{
			print "$str_log_e\n";			
			print "$str_testrun_e\n";
			print "$str_testcase_e\n";
			print SCHREIBEN "$str_log_e\n";		# close actual log tree		
			print SCHREIBEN "$str_testrun_e\n";	# close actual testrun tree		
			print SCHREIBEN "$str_testcase_e\n";	# close actual testcase	tree
			# open, at the end the last strings must be closed again
			print "$str_testcase1\n";
			print "$str_testrun1\n";
			print "$str_log\n";
			print SCHREIBEN "$str_testcase1\n";
			print SCHREIBEN $str_testrun1."\n";
			print SCHREIBEN $str_log."\n";
		}	
	}
	elsif(substr($zeilen_binary,$i,$data_length*2) ne $end_str) # man befindet sich nun im Testcase-Bereich drin
	{	
	
	#element check, should be always run, if the other cases are not matched
	
		$codeLogList = substr($zeilen_binary,$i,$data_length);
		# # print $codeLogList;
		$type = substr($codeLogList,0,1);	# read first Byte (Bitnotation)
		$numParam = substr($codeLogList,1,1);	# read second Byte (Bitnotation)
		# my $string=unpack "H*", $type;
		# print $string."\n";
		# $string=unpack "H*", $numParam;
		# print $string."\n";
		
		$dataLogList = substr($zeilen_binary,$i+$data_length,$data_length);
		$id = substr($dataLogList,0,2);	# read first Byte (Bitnotation)
		$time = substr($dataLogList,2);	# read second Byte (Bitnotation)
		# $string=unpack "H*", $id;
		# print $string."\n";
		# $string=unpack "H*", $time;
		# print $string."\n";
		
		my $type_help = unpack "H*", $type;	# convert into char
		# $type_help = hex($type_help);	# dies funktiniert nicht, da perl interpretiert char falsch
		my $numParam_help = unpack "H*", $numParam;	# convert into char
		# $numParam_help = hex($numParam_help);
		my $id_help = unpack "H*", $id;	# convert into char 
		# $id_help = hex($id_help);
		my $time_help = unpack "H*", $time;	# convert into char
		# $time_help = hex($time_help);
		
		
		if ($numParam eq chr('0'))	# falls nur ein Parameter vorhanden
		{
			
			print SCHREIBEN "$str_elem1$type_help$str_elem2$time_help$str_elem3$id_help$str_elem_e\n";
			print "$str_elem1$type_help$str_elem2$time_help$str_elem3$id_help$str_elem_e\n";
			
		}
		elsif ($numParam eq chr('1'))
		{
		
			
			
		}
		elsif ($numParam eq chr('2'))
		{
		
			
			
		}
		elsif ($numParam eq chr('3'))
		{
		
			
			
		}
		elsif ($numParam eq chr('4')) # falls 4 Parameter vorhanden
		{
			my $substring_help = substr($zeilen_binary,$i+(2*$data_length),4*2*$data_length);	# 2 length of data struct, 4 numParam
			my $c_h = $data_length;
			$data1 = substr($substring_help,$c_h,$data_length);
			my $string_h=unpack "H*", $data1;
			print SCHREIBEN "$str_elem1$type_help$str_elem2$time_help$str_elem3$id_help data1=$string_h ";
			print "$str_elem1$type_help$str_elem2$time_help$str_elem3$id_help data1=$string_h ";
			$c_h = $c_h + 8;	# wird immer um 8 erhoeht, damit die Eintraege der datax-Variablen richtig erfasst werden
			$data2 = substr($substring_help,$c_h,$data_length);
			$string_h=unpack "H*", $data2;
			print SCHREIBEN "data2=$string_h ";
			print "data2=$string_h ";
			$c_h = $c_h + 8;
			$data3 = substr($substring_help,$c_h,$data_length);
			$string_h=unpack "H*", $data3;
			print SCHREIBEN "data3=$string_h ";
			print "data3=$string_h ";
			$c_h = $c_h + 8;
			$data4 = substr($substring_help,$c_h,$data_length);
			$string_h=unpack "H*", $data4;
			print SCHREIBEN "data4=$string_h$str_elem_e\n";
			print "data4=$string_h$str_elem_e\n";
			
			# hiernach muss 4*2*data_length gewartet werden, damit keine Variablen ohne Grund ueberschrieben werden
			$i = $i + (4*2*$data_length);
		}
		elsif ($numParam eq chr('5'))
		{
		
			
			
		}		
		
	}
	elsif(substr($zeilen_binary,$i,$data_length*2) eq $end_str)	#close all trees
	{
		print "$str_log_e\n";			
		print SCHREIBEN "$str_log_e\n";		# close actual log tree		
		print "$str_testrun_e\n";
		print SCHREIBEN "$str_testrun_e\n";	# close actual testrun tree		
		print "$str_testcase_e\n";
		print SCHREIBEN "$str_testcase_e\n";	# close actual testcase	tree			
		last;			
	}	
}
close(SCHREIBEN) or die "Fehler beim Schließen von 'BteReport_Log.xml': $! \n";





# foreach (@chars){	# i was looking in each row of the readen file
	
	# if ($_ eq chr(hex '5C'))
	# {
		# print $_."\n";
	# }
		
		
	
	# # if($_ =~ /$end_string/){
		# # my $end = index($_, $end_string);
		# # my $word = substr($_, 0, $end);
		# # print $word."\n";
		# # print "hola\n";
		# # print $counter."\n";
		
		# # last;
	# # }	
	# # print $_;
	# # $counter++;
# }



# $counter2 = $counter2>>1;
# print $counter2."\n";



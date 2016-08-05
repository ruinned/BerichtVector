#!/Dwimperl/perl/bin/perl.exe -w

use strict;

my $from = "D:/usr/Task_02/BTE_sample/TscStandard/EmbeddedSystem/_Temp/VC_X_Asr4Msn";
my $Anzahlbytes = -s "$from/test.bin";
my $zeilen_binary;
my $data_length = 4; # maximal data length in bytes
my $counter2;

# open file in binary mode
open(LESEN1,"$from/test.bin")
or die "Fehler beim ¨Offnen von 'test.bin': $!\n";
binmode(LESEN1);
read(LESEN1, $zeilen_binary, $Anzahlbytes);
close(LESEN1);
my @chars = split("", $zeilen_binary);


my $numParam;
my $codeLogList;

for (my $i = $data_length; $i < @chars ; $i = $i + $data_length)
{	
	my $hilfe = $i+$data_length-1;
	$codeLogList = @chars[$i..($hilfe)];
	print "$codeLogList\n";

	# $codeLogList = substr($zeilen_binary,$i,$data_length);
	# $dataLogList = substr($zeilen_binary,$i+$data_length,$data_length);
	
	# $numParam =  (hex $codeLogList) & (hex 'FF');
	# my $var = unpack "H*", $codeLogList;
	# # $numParam =  ($var & hex('F0'))>>4;
	# # $numParam =  ($var & hex('FFFFFFFF'));
	# $numParam =  (hex($codeLogList) & hex('FFFFFFFF'));
	# print $codeLogList."\n";
	# print $var."\n";
	# print $numParam."\n";
	# # printf("%#x\n",$numParam);
	$counter2 = 0;

}


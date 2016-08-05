#!/Dwimperl/perl/bin/perl.exe -w

# Kommentare zum aktuellen Stand dieses Files:
#   - Eine Methode zum Eingeben von Nachrichten ist im VS-Programm umzusetzen.
#     Beim Platzhalter -Message- bei der Methode ProcessMessage, sollte die entsprechende
#     verarbeitete Nachricht ersetzt werden, die im binary file gespeichert wurde.  




use strict;
use warnings;

# definition of global variables
my $counter = 0;
my %hash_rows;
my $testcase_opened = 0;
my $datauser_loaded = 0;

# - main method - #
ProcessBinArray();

#-----------------------------------------------------------------#
#-----------------------------------------------------------------#

# main method to process the whole binary array
sub ProcessBinArray
{
  my $binaryFile = $ARGV[0];
  my $zeilen_binary;
  my $Anzahlbytes = -s "$binaryFile";
  # open file in binary mode
  open(LESEN1,"$binaryFile")
  or die "Error opening binary file: $binaryFile\n";
  binmode(LESEN1);
  read(LESEN1, $zeilen_binary, $Anzahlbytes);
  close(LESEN1);
  my @chars = split("", $zeilen_binary);
  
  # short the binary array
  $Anzahlbytes = find_EOF($zeilen_binary);
  @chars = @chars[0..$Anzahlbytes];

  # open the file to be writen
  open(SCHREIBEN,"> $ARGV[2]")
  or die "Error while opening file: $ARGV[2]\n";    
  
  do
  {
    my $next = ReadNext(1, @chars);
    # if the character for a new testcase is found, then its data (just 2 bytes) should be processed
    if( $next eq chr(hex 'FF'))
    {
      ProcessTestCase(ReadNext(2, @chars));
    }  
    # if the character for a message event is found, then it is processed
    elsif($next eq chr(hex('FD')) || $next eq chr(hex('FE')))
    {
      ProcessMessage($next, ReadNext(4, @chars));      
    }
    # otherwise it is necessary to process the data of an event
    else
    {
      my $numParam = GetNumParam($next);
      my $element_type = GetEventKind($next);
      my @next_array = ReadNext(6 + 4*$numParam, @chars);
      ProcessEvent($element_type, $numParam, @next_array);
                
    }
    
  } while($counter < $Anzahlbytes);
  
  # after the analysis of the file the last tree can be closed
  if($testcase_opened == 1)  
  {
    CloseTestcase();
  }
  
  # close the file that was writen 
  close(SCHREIBEN) or die "Error while closing file: '$ARGV[2]'\n";  
  
  ENDOFPROGRAM:

}

# Process the relevant data of the testcase, i.e. the testcase id 
sub ProcessTestCase(@)
{
  my @datatestcaseid = @_;  
  
  # analyse test case id   
  my $testcase_id = ConvertBinArray2Number(@datatestcaseid);  
  
  
  # After the processing of the information, it can be printed out
  if($testcase_opened == 1)
  { 
    # close tastcase           
    CloseTestcase();        
  }
  # open testcase
  OpenTestcase($testcase_id);
}
  
# Process the data of the current event and print the corresponding contents of the test 
sub ProcessEvent($$@)
{
  (my $local_element_type, my $local_numParam, my @dataevent) = @_;   
  
  # length of the array
  my $arraylength = scalar @dataevent;
  # analyse event id
  my $element_id_comp = atoh($dataevent[0]);
  my $element_id_code = atoh($dataevent[1]);
  my $eventText = GetUserEntry("$element_id_comp$element_id_code");

  # analyse time information  
  my $time = ConvertBinArray2Number(@dataevent[2..5]);
 
  # analyse the rest of the information for the current testcase
  my @temp_arr = @dataevent[6..($arraylength-1)];
  my $reportText = ConvertEventText2ReportText($eventText, \@temp_arr);
  
  # print parameters in file
  WriteToFile("<Element type=\"$local_element_type\" time=\"$time\"> $reportText </Element>\n");     
}

# Process the data of the eventText to be analyzed. 
# The corresponding positions in this string are updated
sub ConvertEventText2ReportText($$)
{
  # load the passed arguments
  my $eventText = $_[0];  
  my @dataEvent = @{$_[1]};
  
  # helping variables
  my $index_r_update = 0;
  my $index_l = index(substr($eventText, $index_r_update), '{');
  my $index_r = index(substr($eventText, $index_r_update+$index_l+1), '}');
  
  while($index_l  != -1)
  {
    my $entry;
    # load the string between the relevant symbols      
    my $middlestring = substr($eventText, $index_r_update+$index_l+1,$index_r);
    
    if($index_l ne "-1")
    {
      # process the data of the entry parameters depending on their length  
      if($middlestring =~ /\.\./)
      {        
        $entry = ConvertBinArray2Number(@dataEvent[substr($middlestring, 0, index($middlestring, '.'))..substr( $middlestring, rindex( $middlestring, '.' ) + 1 )]);
      }
      else 
      {
        $entry = atod($dataEvent[$middlestring]);
      }
      # replace the corresponding processed information in the eventText variable
      substr($eventText, $index_r_update+$index_l,$index_r+2) = $entry;
    }
    
    # update save the new location to continue searching from this point
    $index_r_update += $index_l+1+$index_r+1;      
    $index_l = index(substr($eventText, $index_r_update), '{');
    $index_r = index(substr($eventText, $index_r_update+$index_l+1), '}');      
  }
  return $eventText;  
}

# open the current testcase and deactivate the update the corresponding identifier
sub OpenTestcase($)
{
  WriteToFile("<testcase id = TC:\"$_[0]\">\n");
  WriteToFile("<testrun date=\"".localtime."\" executor=\"".getlogin."\" parameter=\"\">\n");
  WriteToFile("<log>\n");
  $testcase_opened = 1;
}

# close the current testcase and deactivate the update the corresponding identifier 
sub CloseTestcase
{
  WriteToFile("<\/log>\n");      
  WriteToFile("<\/testrun>\n");
  WriteToFile("<\/testcase>\n");  
  $testcase_opened = 0;
}

# method to process the number of parameters passed as arguments to the function to be analyzed
sub GetNumParam($)
{  
  # number of parameters are analysed
  return (atod($_[0]) & hex('f0')) >> 4;    
}

# method to obtain the corresponding event id as a string message
sub GetUserEntry($)
{  
  if ($datauser_loaded == 0)
  {
    my $userfile = $ARGV[1];
    
    # open file
    open(USERFILE,$userfile) or die "Error while opening file: 'AnwenderFile1.txt'\n";  
    my @rowsfile = <USERFILE>;
    close(USERFILE);
  
    foreach my $row (@rowsfile)
    {
      # remove white spaces from the left side
      $row =~ s/^\s+//;
      # remove white spaces from the rigth side
      $row =~ s/\s+$//; 
      chomp($row);
      my $eventId = substr($row,0,4);
      my $eventText = "";
      
      # if the user does not indicate the name for the corresponding method then just a empty string is stored
      if (length($row) > 4)
      {
        $eventText = substr($row,5);  
      }                   
      $hash_rows{$eventId} = $eventText; 
    }
    $datauser_loaded = 1;    
  } 
  # if the user does not indicate the name for the corresponding method 
  # then just the corresponding key is returned
  if ($hash_rows{$_[0]} eq "")
  {
    return $_[0];
  }
  return $hash_rows{$_[0]};  
}

# method to recognise, if the current event is of comand, error or default type nature
sub GetEventKind($)
{
  my $type;
  
  if ((atod($_[0]) & hex('f')) == 0)
  {
    $type = "";
  } 
  elsif ((atod($_[0]) & hex('f')) == 1)
  {
    $type = "cmd";
  }
  elsif ((atod($_[0]) & hex('f')) == 2)
  {
    $type = "fail";
  }    
  return $type; 
}

# method to process and release the messages that are stored in the binary file
sub ProcessMessage($@)
{
  (my $loc_val, my @loc_arr) = @_;
  my $result_tc;
  
  my $time = ConvertBinArray2Number(@loc_arr);
  
  if ($loc_val eq chr(hex('FD')))
  {
    $result_tc = "\"ok\"";
  } 
  elsif ($loc_val eq chr(hex('FE')))
  {
    $result_tc = "\"fail\"";
  }    
  WriteToFile("<Element type=$result_tc time=\"$time\"> Message </Element>\n");
}

# method to load a specific number of binary data and update the location 
# of the current byte in the binary file 
sub ReadNext($@)
{
  (my $num2read, my @local_chars) = @_; 
  # if the data to be read is greater than one one byte, than an array is returned
  if ($num2read > 1)
  {
    my @array2return = @local_chars[$counter..($counter + $num2read-1)];
    $counter += $num2read;
    return @array2return;        
  }
  # otherwise just an integer is returned
  else  
  {
    my $elem2return = $local_chars[$counter];
    $counter += $num2read;
    return $elem2return;
  }
}

# print the message to the xml-file
sub WriteToFile($)
{
  print SCHREIBEN $_[0];
  print $_[0];  
}

# method to assemble splited messages depending on the length of entry-dataarray 
sub ConvertBinArray2Number(@)
{
  my $var = 0;
  my @loc_arr = @_;
  my $length_locarr = scalar @loc_arr;
  my $count = $length_locarr-1;
  
  if($length_locarr > 0)
  {
    foreach (@loc_arr)
    {
       $var |= atod($_) << (8*$count);
       $count--;
    }
  }
  return $var;  
}

# method to transform a binary to a decimal number
sub atod($)
{
  return hex(unpack('H*',$_[0]));  
}

# method to transform a binary to a hexadecimal number
sub atoh($)
{
  return unpack('H*',$_[0]);
}

# method to find the end of the binary file
sub find_EOF($)
 {   
   my $ind = index($_[0],chr(hex('5C')).chr(hex('6E')).chr(hex('5C')).chr(hex('6E')));
     
   # if the pattern for the end of file is not found than the creation of the xml-file is not released
   if ($ind == -1) 
   {
     print "Warning: File does not contain the corresponding \"end of file\"-symbol. Check if the correct file is loaded\n";
     goto ENDOFPROGRAM;         
   }
   # otherwise the relevant length of the binary file is returned
   else
   {
     return $ind;
   }       
 }


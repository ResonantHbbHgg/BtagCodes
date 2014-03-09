#!/usr/bin/perl

# ----------------------------------------------------------------------------
#      MAIN PROGRAM
# ----------------------------------------------------------------------------

use Env;

#PG lettura dei parametri da cfg file
#PG --------------------------------
print "reading ".$ARGV[0]."\n" ;

open (USERCONFIG,$ARGV[0]) ;

while (<USERCONFIG>)
{
    chomp; 
    s/#.*//;                # no comments
    s/^\s+//;               # no leading white
    s/\s+$//;               # no trailing white
#    next unless length;     # anything left?
    my ($var, $value) = split(/\s*=\s*/, $_, 2);
    $User_Preferences{$var} = $value;
}

$BASEDir          = $User_Preferences{"BASEDir"};
$CMSSWPath        = $User_Preferences{"CMSSWPath"};
$ProgramName      = $User_Preferences{"ProgramName"};
$JOBCfgTemplate   = $User_Preferences{"JOBCfgTemplate"};
$LISTOFSamples    = $User_Preferences{"LISTOFSamples"};
$OUTPUTSAVEPath   = $User_Preferences{"OUTPUTSAVEPath"} ;
$OUTPUTFILEName   = $User_Preferences{"OUTPUTFILEName"} ;
$JOBModulo        = $User_Preferences{"JOBModulo"} ;
$Queue            = $User_Preferences{"Queue"} ;



print "BASEDir = "          .$BASEDir."\n" ;
print "CMSSWPath = "        .$CMSSWPath."\n" ;
print "ProgramName = "      .$ProgramName."\n" ;
print "JOBCfgTemplate = "   .$JOBCfgTemplate."\n";
print "LISTOFSamples = "    .$LISTOFSamples."\n" ;
print "OUTPUTSAVEPath = "   .$OUTPUTSAVEPath."\n" ;
print "OUTPUTFILEName = "   .$OUTPUTFILEName."\n" ;
print "JOBModulo = "        .$JOBModulo."\n" ;
print "Queue = "            .$Queue."\n\n" ;





$sampleJobListFile = "./lancia.sh";
open(SAMPLEJOBLISTFILE, ">", $sampleJobListFile);


#####################################################
# PG prepare the array containing the root files list
#####################################################


open (LISTOFSamples,$LISTOFSamples) ;
while (<LISTOFSamples>)
{
    system("cd ".$BASEDir."\n");
    
    chomp($_);
  
    ($INPUTSAVEPath,$sample1) = split(" ") ;
    #print "INPUTSAVEPath = "        .$INPUTSAVEPath."\n\n" ;
    $subsample = substr($sample,0,1);
    if($subsample eq "#")
    {
	next;
    }
    
    print("Sample: ".$sample1."\n") ;  

    system ("rm -r ".$sample1."\n") ;
    system ("mkdir ".$sample1."\n") ;
    
  
  
    
  
  
    $LISTOFFiles = "./list_".$sample1.".txt" ;
    
    system ("cmsLs -R ".$INPUTSAVEPath."/".$sample1." | grep root | awk '{print \$5}' > ".$LISTOFFiles."\n") ;

    #$globalPATH = $INPUTSAVEPath."/".$sample1."/" ;
    #system ("rfdir ".$INPUTSAVEPath."/".$sample1." | grep root | awk '{print \"rfio:".$globalPATH."\"\$9}' > ".$LISTOFFiles."\n") ;
  
  
  
    $totNumber = 0;
    $jobNumber = 0;
  
    open (LISTOFFiles,$LISTOFFiles) ;
    while (<LISTOFFiles>)
    {
	++$totNumber;
    }

    $jobNumber = int($totNumber/$JOBModulo);
    if( $totNumber%$JOBModulo != 0)
    {
	$jobNumber = $jobNumber+1;
    }
    
    print "NumberOfJobs = ".$jobNumber."\n";
    

  
    ################
    # loop over jobs 
    ################
    
    for($jobIt = 1; $jobIt <= $jobNumber; ++$jobIt)
    { 
	$currDir = `pwd` ;
	chomp ($currDir) ;
    
	$jobDir = $currDir."/".$sample1."/JOB_".$jobIt ;
	system ("mkdir ".$jobDir." \n") ;
    
	$tempBjob = $jobDir."/bjob_".$jobIt.".sh" ;
	$command = "touch ".$tempBjob ;
	system ($command) ;
	$command = "chmod 777 ".$tempBjob ;
	system ($command) ;
    

	$it = 0;
	$JOBLISTOFFiles;

        system("touch inputList.cfg");
	open (LISTOFFiles2,$LISTOFFiles) ;
	while (<LISTOFFiles2>)
	{
	    chomp; 
	    s/#.*//;                # no comments
	    s/^\s+//;               # no leading white
	    s/\s+$//;               # no trailing white
	    $file = $_ ;
	    
	    $JOBLISTOFFiles = "root://eoscms.cern.ch//eos/cms".$file;
            if(($it+1)/$JOBModulo > $jobIt-1 &&  ($it+1)/$JOBModulo < $jobIt+1)
            {
              system("echo " .$JOBLISTOFFiles. ">> inputList.cfg");
            }
            $JOBLISTOFFiles = "" ;
	    if(($it+1)/$JOBModulo == $jobIt){ last;}
	    ++$it;
	}

	
	$JOBLISTOFFiles = "" ;

	$JOBCfgFile = $jobDir."/inputList.cfg" ;
	system ("mv inputList.cfg ".$JOBCfgFile) ;
        
        $tempo1 = "./tempo1" ;    
	system ("cat ".$JOBCfgTemplate." | sed -e s%INPUTLIST%".$JOBCfgFile."%g > ".$tempo1) ;
        $tempo2 = "./tempo2" ;  
        $form = ".root";
        system ("cat ".$tempo1." | sed -e s%OUTPUTNAME%".$OUTPUTSAVEPath.$sample1."/".$OUTPUTFILEName."_".$jobIt.$form."%g > ".$tempo2) ;
        $JOBCfgFile = $jobDir."/inputList.cfg" ;
	system ("mv ".$tempo2." ".$jobDir."/parserParams.cfg") ;
        
    
    ######################
    # make job files
    ######################    
    
	open (SAMPLEJOBFILE, ">", $tempBjob) or die "Can't open file ".$tempBjob;

	$command = "#!/bin/tcsh" ;
	print SAMPLEJOBFILE $command."\n";

        $command = "cd ".$CMSSWPath ;
	print SAMPLEJOBFILE $command."\n";
        
	$command = "setenv SCRAM_ARCH slc5_amd64_gcc462" ;
	print SAMPLEJOBFILE $command."\n";
        
        $command = "eval  `scramv1 runtime -csh`" ;
	print SAMPLEJOBFILE $command."\n";
    
        $command = "cd ".$BASEDir ;
	print SAMPLEJOBFILE $command."\n";

        $command = "cd ../../";
	print SAMPLEJOBFILE $command."\n";
         
        $command = "source scripts/setup.csh ";
	print SAMPLEJOBFILE $command."\n";
        
	$command = "./bin/".$ProgramName.".exe ".$jobDir."/parserParams.cfg";
	print SAMPLEJOBFILE $command."\n";
	
	############
	# submit job
	############
	
	$command = "bsub -cwd ".$jobDir." -q ".$Queue." ".$tempBjob."\n" ;  
	print SAMPLEJOBLISTFILE $command."\n";
    
    }

    system ("rm ".$LISTOFFiles) ;
}  

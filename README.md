BtagEfficiencyMaps_code
=======================

1) First thing to do is:

    cd CMSSW_5_X_Y/src
    cmsenv
    
note that this package works only in a CMSSW_5_X_Y

2) In BtagEfficiencyMaps_code directory:

    source scripts/setup.sh
    
3) Compile:

    make 
    make exe
    
4) Run:

    ./bin/Make_BtagEfficiencyMaps.exe cfg/Make_BtagEfficiencyMaps.cfg
    
5) NOTE: 
   in the cfg file there are:

    inputList = list of file to run
    inputTree = name of the tree (all the files must have the same tree name)
    outputName = output name
    

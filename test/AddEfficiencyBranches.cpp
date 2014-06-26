
#include "ConfigParser.h"
#include "ParserUtils.h"
#include "TreeUtils.h"
#include "BTagUtils.h"

#include "TROOT.h"
#include "TStyle.h"
#include "TFile.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TGraphAsymmErrors.h"
#include "TGraphAsymmErrors.h"
#include "TPaveStats.h"
#include "TLegend.h"
#include "TChain.h"
#include "TRandom.h"
#include "TVirtualFitter.h"
#include "TLatex.h"
#include "TProfile.h"
#include "TClonesArray.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "THStack.h"
#include "TPad.h"
#include "TEfficiency.h"
#include "TMVA/MsgLogger.h"
#include "TMVA/Config.h"
#include "TMVA/Tools.h"
#include "TMVA/Factory.h"
#include "TMVA/Reader.h"
#include "TKey.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <map>
#include <algorithm>
#include <math.h>
#include <vector>

bool passCutBasedJetId(TLorentzVector* jetP4,TLorentzVector* pho1P4,TLorentzVector* pho2P4);
std::vector<int> chooseMaxptCouple(std::vector<TLorentzVector>* JetP4);

int main(int argc, char** argv)
{

  // Input parameters
  
  std::cout << "\n*******************************************************************************************************************" << std::endl;
  std::cout << "arcg: " << argc << std::endl;
  
  //Check if all nedeed arguments to parse are there
  if(argc != 2)
  {
    std::cerr << ">>>>> Analyses::usage: " << argv[0] << " configFileName" << std::endl ;
    return 1;
  }
 
  /// Parse the config file
  parseConfigFile (argv[1]) ;
  
  std::string inputFile = gConfigParser -> readStringOption("Input::inputFile");
  int doCombinatorics = gConfigParser -> readIntOption("Input::doCombinatorics");
  int addEfficiencies = gConfigParser -> readIntOption("Input::addEfficiencies");
  int saveMaps = gConfigParser -> readIntOption("Input::saveMaps");
  int splitTree = gConfigParser -> readIntOption("Input::splitTree");
  int iFile = gConfigParser -> readIntOption("Input::iFile");
  std::string outputName = gConfigParser -> readStringOption("Output::outputName");

  std::cout << "inputFile       = " << inputFile << std::endl;
  std::cout << "outputName      = " << outputName << std::endl;
  std::cout << "doCombinatorics = " << doCombinatorics << std::endl;
  std::cout << "addEfficiencies = " << addEfficiencies << std::endl;
  std::cout << "saveMaps        = " << saveMaps << std::endl;
  std::cout << "splitTree       = " << splitTree << std::endl;
  std::cout << "iFile           = " << iFile << std::endl;
  
  TFile* file = TFile::Open(inputFile.c_str());

  std::vector<std::string> TreeNames;
  std::string Name  = "";
  std::string Class  = "";
  
  TList* list = (TList*)file->GetListOfKeys();
  TKey *key;
  TObject* object;
  for(int ii = list->GetEntries()-200; ii < list->GetEntries(); ii++){
      key = (TKey*)list->At(ii);
      object = (TObject*) key->ReadObj();
      Class = std::string(object->ClassName());
      Name = std::string(object->GetName());
      if(Class.find("TTree") != std::string::npos && Name.find("8TeV") != std::string::npos) TreeNames.push_back(Name);
  }
  
  TFile* output_final = new TFile(outputName.c_str(),"RECREATE");
  std::map<int,TTree*> ntu;
  std::map<int,TTree*> ntu_output;

  float ptmin[21] = {20., 30., 40., 50., 60., 70., 80., 100., 120., 160., 210., 260., 320., 400., 500., 600., 800.,900.,1000.,1200.,1500.};
  float etamin[8] = {0.,0.5,1.,1.5,2.,2.5,3.,3.5};
 
  TLorentzVector* jetP4 = new TLorentzVector();
  TLorentzVector* pho1P4 = new TLorentzVector();
  TLorentzVector* pho2P4 = new TLorentzVector();

  std::vector<TLorentzVector> JetP4;
  std::vector<int> JetFlavour;
  std::vector<float> JetCSV;
  
  for(unsigned ii = 0; ii < TreeNames.size(); ii++){

    ntu[ii] = (TTree*)file->Get(TreeNames.at(ii).c_str());
    InitTree(ntu[ii],addEfficiencies);

    TH2F* h2_BTaggingEff_Denom_b_L = new TH2F(Form("h2_BTaggingEff_Denom_b_L_%d",ii),Form("h2_BTaggingEff_Denom_b_L_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Num_b_L = new TH2F(Form("h2_BTaggingEff_Num_b_L_%d",ii),Form("h2_BTaggingEff_Num_b_L_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_b_L = new TH2F(Form("h2_BTaggingEff_b_L_%d",ii),Form("h2_BTaggingEff_b_L_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Denom_b_M = new TH2F(Form("h2_BTaggingEff_Denom_b_M_%d",ii),Form("h2_BTaggingEff_Denom_b_M_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Num_b_M = new TH2F(Form("h2_BTaggingEff_Num_b_M_%d",ii),Form("h2_BTaggingEff_Num_b_M_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_b_M = new TH2F(Form("h2_BTaggingEff_b_M_%d",ii),Form("h2_BTaggingEff_b_M_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Denom_b_T = new TH2F(Form("h2_BTaggingEff_Denom_b_T_%d",ii),Form("h2_BTaggingEff_Denom_b_T_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Num_b_T = new TH2F(Form("h2_BTaggingEff_Num_b_T_%d",ii),Form("h2_BTaggingEff_Num_b_T_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_b_T = new TH2F(Form("h2_BTaggingEff_b_T_%d",ii),Form("h2_BTaggingEff_b_T_%d",ii),20, ptmin, 7,etamin);

    TH2F* h2_BTaggingEff_Denom_c_L = new TH2F(Form("h2_BTaggingEff_Denom_c_L_%d",ii),Form("h2_BTaggingEff_Denom_c_L_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Num_c_L = new TH2F(Form("h2_BTaggingEff_Num_c_L_%d",ii),Form("h2_BTaggingEff_Num_c_L_%d",ii),20, ptmin,7,etamin);
    TH2F* h2_BTaggingEff_c_L = new TH2F(Form("h2_BTaggingEff_c_L_%d",ii),Form("h2_BTaggingEff_c_L_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Denom_c_M = new TH2F(Form("h2_BTaggingEff_Denom_c_M_%d",ii),Form("h2_BTaggingEff_Denom_c_M_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Num_c_M = new TH2F(Form("h2_BTaggingEff_Num_c_M_%d",ii),Form("h2_BTaggingEff_Num_c_M_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_c_M = new TH2F(Form("h2_BTaggingEff_c_M_%d",ii),Form("h2_BTaggingEff_c_M_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Denom_c_T = new TH2F(Form("h2_BTaggingEff_Denom_c_T_%d",ii),Form("h2_BTaggingEff_Denom_c_T_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Num_c_T = new TH2F(Form("h2_BTaggingEff_Num_c_T_%d",ii),Form("h2_BTaggingEff_Num_c_T_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_c_T = new TH2F(Form("h2_BTaggingEff_c_T_%d",ii),Form("h2_BTaggingEff_c_T_%d",ii),20, ptmin, 7,etamin);

    TH2F* h2_BTaggingEff_Denom_udsg_L = new TH2F(Form("h2_BTaggingEff_Denom_udsg_L_%d",ii),Form("h2_BTaggingEff_Denom_udsg_L_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Num_udsg_L = new TH2F(Form("h2_BTaggingEff_Num_udsg_L_%d",ii),Form("h2_BTaggingEff_Num_udsg_L_%d",ii),20, ptmin,7,etamin);
    TH2F* h2_BTaggingEff_udsg_L = new TH2F(Form("h2_BTaggingEff_udsg_L_%d",ii),Form("h2_BTaggingEff_udsg_L_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Denom_udsg_M = new TH2F(Form("h2_BTaggingEff_Denom_udsg_M_%d",ii),Form("h2_BTaggingEff_Denom_udsg_M_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Num_udsg_M = new TH2F(Form("h2_BTaggingEff_Num_udsg_M_%d",ii),Form("h2_BTaggingEff_Num_udsg_M_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_udsg_M = new TH2F(Form("h2_BTaggingEff_udsg_M_%d",ii),Form("h2_BTaggingEff_udsg_M_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Denom_udsg_T = new TH2F(Form("h2_BTaggingEff_Denom_udsg_T_%d",ii),Form("h2_BTaggingEff_Denom_c_T_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_Num_udsg_T = new TH2F(Form("h2_BTaggingEff_Num_udsg_T_%d",ii),Form("h2_BTaggingEff_Num_udsg_T_%d",ii),20, ptmin, 7,etamin);
    TH2F* h2_BTaggingEff_udsg_T = new TH2F(Form("h2_BTaggingEff_udsg_T_%d",ii),Form("h2_BTaggingEff_udsg_T_%d",ii),20, ptmin, 7,etamin);

    for(int ientry = 0; ientry < ntu[ii]->GetEntries(); ientry++){
      if(ientry%1000==0) std::cout<<"--- Reading tree: " << TreeNames.at(ii) << " - entry = "<< ientry << " for filling efficiencies maps..."<<std::endl;
      ntu[ii]->GetEntry(ientry);

      if(ph1_ciclevel < 4 || ph2_ciclevel < 4) continue;

      pho1P4->SetPtEtaPhiE(ph1_pt,ph1_eta,ph1_phi,ph1_e);
      pho2P4->SetPtEtaPhiE(ph2_pt,ph2_eta,ph2_phi,ph2_e);

      JetP4.clear();
      JetFlavour.clear();
      JetCSV.clear(); 
      
      bool passedJet = true;

      if(j1_e != -1001.){
         jetP4->SetPtEtaPhiE(j1_pt,j1_eta,j1_phi,j1_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j1_flavour);         
            JetCSV.push_back(j1_csvBtag);
         }
      }
   
      passedJet = false;
      if(j2_e != -1001.){
         jetP4->SetPtEtaPhiE(j2_pt,j2_eta,j2_phi,j2_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j2_flavour);         
            JetCSV.push_back(j2_csvBtag);
         }
      }
      
      passedJet = false;
      if(j3_e != -1001.){
         jetP4->SetPtEtaPhiE(j3_pt,j3_eta,j3_phi,j3_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j3_flavour);         
            JetCSV.push_back(j3_csvBtag);
         }
      }
      
      passedJet = false;
      if(j4_e != -1001.){
         jetP4->SetPtEtaPhiE(j4_pt,j4_eta,j4_phi,j4_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j4_flavour);         
            JetCSV.push_back(j4_csvBtag);
         }
      }

      passedJet = false;
      if(j5_e != -1001.){
         jetP4->SetPtEtaPhiE(j5_pt,j5_eta,j5_phi,j5_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j5_flavour);         
            JetCSV.push_back(j5_csvBtag);
         }
      }

      passedJet = false;
      if(j6_e != -1001.){
         jetP4->SetPtEtaPhiE(j6_pt,j6_eta,j6_phi,j6_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j6_flavour);         
            JetCSV.push_back(j6_csvBtag);
         }
      }
     
      passedJet = false;
      if(j7_e != -1001.){
         jetP4->SetPtEtaPhiE(j7_pt,j7_eta,j7_phi,j7_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j7_flavour);         
            JetCSV.push_back(j7_csvBtag);
         }
      }
     
      passedJet = false;
      if(j8_e != -1001.){
         jetP4->SetPtEtaPhiE(j8_pt,j8_eta,j8_phi,j8_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j8_flavour);         
            JetCSV.push_back(j8_csvBtag);
         }
      }

      passedJet = false;
      if(j9_e != -1001.){
         jetP4->SetPtEtaPhiE(j9_pt,j9_eta,j9_phi,j9_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j9_flavour);         
            JetCSV.push_back(j9_csvBtag);
         }
      }
   
      passedJet = false;
      if(j10_e != -1001.){
         jetP4->SetPtEtaPhiE(j10_pt,j10_eta,j10_phi,j10_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j10_flavour);         
            JetCSV.push_back(j10_csvBtag);
         }
      } 
      
      passedJet = false;
      if(j11_e != -1001.){
         jetP4->SetPtEtaPhiE(j11_pt,j11_eta,j11_phi,j11_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j11_flavour);         
            JetCSV.push_back(j11_csvBtag);
         }
      }
      
      passedJet = false;
      if(j12_e != -1001.){
         jetP4->SetPtEtaPhiE(j12_pt,j12_eta,j12_phi,j12_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j12_flavour);         
            JetCSV.push_back(j12_csvBtag);
         }
      }

      passedJet = false;
      if(j13_e != -1001.){
         jetP4->SetPtEtaPhiE(j13_pt,j13_eta,j13_phi,j13_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j13_flavour);         
            JetCSV.push_back(j13_csvBtag);
         }
      }

      passedJet = false;
      if(j14_e != -1001.){
         jetP4->SetPtEtaPhiE(j14_pt,j14_eta,j14_phi,j14_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j14_flavour);         
            JetCSV.push_back(j14_csvBtag);
         }
      }

      passedJet = false;
      if(j15_e != -1001.){
         jetP4->SetPtEtaPhiE(j15_pt,j15_eta,j15_phi,j15_e);
         passedJet = passCutBasedJetId(jetP4,pho1P4,pho2P4);
         if(passedJet == true){
            JetP4.push_back(*jetP4);
            JetFlavour.push_back(j15_flavour);         
            JetCSV.push_back(j15_csvBtag);
         }
      }
     
      int ijet1 = -1;
      int ijet2 = -1;
      if(doCombinatorics == 1){ 
         if(JetP4.size() < 2) continue;
         ijet1 = chooseMaxptCouple(&JetP4).at(0);
         ijet2 = chooseMaxptCouple(&JetP4).at(1);
      }

      for(unsigned int ii = 0; ii < JetP4.size(); ii++){

           if(doCombinatorics == 1)
              if(int(ii) != ijet1 && int(ii) != ijet2) continue;

           if(abs(JetFlavour.at(ii)) == 5){
                 
                 h2_BTaggingEff_Denom_b_L->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                 if(JetCSV.at(ii) > 0.244) h2_BTaggingEff_Num_b_L->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                   
                 h2_BTaggingEff_Denom_b_M->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                 if(JetCSV.at(ii) > 0.679) h2_BTaggingEff_Num_b_M->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                 
                 h2_BTaggingEff_Denom_b_T->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                 if(JetCSV.at(ii) > 0.898) h2_BTaggingEff_Num_b_T->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
              }
 
              if(abs(JetFlavour.at(ii)) == 4){
                 
                 h2_BTaggingEff_Denom_c_L->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                 if(JetCSV.at(ii) > 0.244) h2_BTaggingEff_Num_c_L->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                   
                 h2_BTaggingEff_Denom_c_M->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                 if(JetCSV.at(ii) > 0.679) h2_BTaggingEff_Num_c_M->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                 
                 h2_BTaggingEff_Denom_c_T->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                 if(JetCSV.at(ii) > 0.898) h2_BTaggingEff_Num_c_T->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
              }

              if(abs(JetFlavour.at(ii)) == 1 || abs(JetFlavour.at(ii)) == 2 || abs(JetFlavour.at(ii)) == 3 || abs(JetFlavour.at(ii)) == 21){
                 
                 h2_BTaggingEff_Denom_udsg_L->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                 if(JetCSV.at(ii) > 0.244) h2_BTaggingEff_Num_udsg_L->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                   
                 h2_BTaggingEff_Denom_udsg_M->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                 if(JetCSV.at(ii) > 0.679) h2_BTaggingEff_Num_udsg_M->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                 
                 h2_BTaggingEff_Denom_udsg_T->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
                 if(JetCSV.at(ii) > 0.898) h2_BTaggingEff_Num_udsg_T->Fill(JetP4.at(ii).Pt(),fabs(JetP4.at(ii).Eta()));
              }
      } 
    }
   
    h2_BTaggingEff_Num_b_L->Sumw2();
    h2_BTaggingEff_Denom_b_L->Sumw2();
    h2_BTaggingEff_b_L->Sumw2();
    h2_BTaggingEff_Num_c_L->Sumw2();
    h2_BTaggingEff_Denom_c_L->Sumw2();
    h2_BTaggingEff_c_L->Sumw2();
    h2_BTaggingEff_Num_udsg_L->Sumw2();
    h2_BTaggingEff_Denom_udsg_L->Sumw2();
    h2_BTaggingEff_udsg_L->Sumw2();
    h2_BTaggingEff_Num_b_M->Sumw2();
    h2_BTaggingEff_Denom_b_M->Sumw2();
    h2_BTaggingEff_b_M->Sumw2();
    h2_BTaggingEff_Num_c_M->Sumw2();
    h2_BTaggingEff_Denom_c_M->Sumw2();
    h2_BTaggingEff_c_M->Sumw2();
    h2_BTaggingEff_Num_udsg_M->Sumw2();
    h2_BTaggingEff_Denom_udsg_M->Sumw2();
    h2_BTaggingEff_udsg_M->Sumw2();
    h2_BTaggingEff_Num_b_T->Sumw2();
    h2_BTaggingEff_Denom_b_T->Sumw2();
    h2_BTaggingEff_b_T->Sumw2();
    h2_BTaggingEff_Num_c_T->Sumw2();
    h2_BTaggingEff_Denom_c_T->Sumw2();
    h2_BTaggingEff_c_T->Sumw2();
    h2_BTaggingEff_Num_udsg_T->Sumw2();
    h2_BTaggingEff_Denom_udsg_T->Sumw2();
    h2_BTaggingEff_udsg_T->Sumw2();
  
    h2_BTaggingEff_b_L->Divide(h2_BTaggingEff_Num_b_L,h2_BTaggingEff_Denom_b_L,1,1,"B");
    h2_BTaggingEff_b_M->Divide(h2_BTaggingEff_Num_b_M,h2_BTaggingEff_Denom_b_M,1,1,"B");
    h2_BTaggingEff_b_T->Divide(h2_BTaggingEff_Num_b_T,h2_BTaggingEff_Denom_b_T,1,1,"B") ;

    h2_BTaggingEff_c_L->Divide(h2_BTaggingEff_Num_c_L,h2_BTaggingEff_Denom_c_L,1,1,"B");
    h2_BTaggingEff_c_M->Divide(h2_BTaggingEff_Num_c_M,h2_BTaggingEff_Denom_c_M,1,1,"B");
    h2_BTaggingEff_c_T->Divide(h2_BTaggingEff_Num_c_T,h2_BTaggingEff_Denom_c_T,1,1,"B");
  
    h2_BTaggingEff_udsg_L->Divide(h2_BTaggingEff_Num_udsg_L,h2_BTaggingEff_Denom_udsg_L,1,1,"B");
    h2_BTaggingEff_udsg_M->Divide(h2_BTaggingEff_Num_udsg_M,h2_BTaggingEff_Denom_udsg_M,1,1,"B");
    h2_BTaggingEff_udsg_T->Divide(h2_BTaggingEff_Num_udsg_T,h2_BTaggingEff_Denom_udsg_T,1,1,"B");

    TFile* output = new TFile(("output/btagEfficiencies_"+TreeNames.at(ii)+".root").c_str(),"RECREATE");
  
    output->cd();

    h2_BTaggingEff_Denom_b_L->Write("h2_BTaggingEff_Denom_b_L");
    h2_BTaggingEff_Num_b_L->Write("h2_BTaggingEff_Num_b_L");
    h2_BTaggingEff_b_L->Write("h2_BTaggingEff_b_L");
    h2_BTaggingEff_Denom_b_M->Write("h2_BTaggingEff_Denom_b_M");
    h2_BTaggingEff_Num_b_M->Write("h2_BTaggingEff_Num_b_M");
    h2_BTaggingEff_b_M->Write("h2_BTaggingEff_b_M");
    h2_BTaggingEff_Denom_b_T->Write("h2_BTaggingEff_Denom_b_T");
    h2_BTaggingEff_Num_b_T->Write("h2_BTaggingEff_Num_b_T");
    h2_BTaggingEff_b_T->Write("h2_BTaggingEff_b_T");
    h2_BTaggingEff_Denom_c_L->Write("h2_BTaggingEff_Denom_c_L");
    h2_BTaggingEff_Num_c_L->Write("h2_BTaggingEff_Num_c_L");
    h2_BTaggingEff_c_L->Write("h2_BTaggingEff_c_L");
    h2_BTaggingEff_Denom_c_M->Write("h2_BTaggingEff_Denom_c_M");
    h2_BTaggingEff_Num_c_M->Write("h2_BTaggingEff_Num_c_M");
    h2_BTaggingEff_c_M->Write("h2_BTaggingEff_c_M");
    h2_BTaggingEff_Denom_c_T->Write("h2_BTaggingEff_Denom_c_T");
    h2_BTaggingEff_Num_c_T->Write("h2_BTaggingEff_Num_c_T");
    h2_BTaggingEff_c_T->Write("h2_BTaggingEff_c_T");
    h2_BTaggingEff_Denom_udsg_L->Write("h2_BTaggingEff_Denom_udsg_L");
    h2_BTaggingEff_Num_udsg_L->Write("h2_BTaggingEff_Num_udsg_L");
    h2_BTaggingEff_udsg_L->Write("h2_BTaggingEff_udsg_L");
    h2_BTaggingEff_Denom_udsg_M->Write("h2_BTaggingEff_Denom_udsg_M");
    h2_BTaggingEff_Num_udsg_M->Write("h2_BTaggingEff_Num_udsg_M");
    h2_BTaggingEff_udsg_M->Write("h2_BTaggingEff_udsg_M");
    h2_BTaggingEff_Denom_udsg_T->Write("h2_BTaggingEff_Denom_udsg_T");
    h2_BTaggingEff_Num_udsg_T->Write("h2_BTaggingEff_Num_udsg_T");
    h2_BTaggingEff_udsg_T->Write("h2_BTaggingEff_udsg_T");

    output->Close();

    BtagEfficiencyReader EffReader(("output/btagEfficiencies_"+TreeNames.at(ii)+".root").c_str());

    int ev_min = 0;
    int ev_max = ntu[ii]->GetEntries();

    if(splitTree == 1 && iFile == 0) ev_max = int(ntu[ii]->GetEntries()/2);
    if(splitTree == 1 && iFile == 1) ev_min = int(ntu[ii]->GetEntries()/2);

    output_final->cd();
   
    ntu_output[ii] = CloneTreeCut(ntu[ii],ev_min,ev_max);
    AddBranches(ntu_output[ii]);
   
    for(int ientry = 0; ientry < ntu_output[ii]->GetEntries(); ientry++){
      if(ientry%1000==0) std::cout<<"--- Reading tree: " << TreeNames.at(ii) << " - entry = "<< ientry << " for filling efficiencies branches..." << std::endl;
      ntu_output[ii]->GetEntry(ientry);

      j1_btagEff_L=j1_btagEffError_L=j1_btagEff_M=j1_btagEffError_M=j1_btagEff_T=j1_btagEffError_T=-1001.;
      j2_btagEff_L=j2_btagEffError_L=j2_btagEff_M=j2_btagEffError_M=j2_btagEff_T=j2_btagEffError_T=-1001.;
      j3_btagEff_L=j3_btagEffError_L=j3_btagEff_M=j3_btagEffError_M=j3_btagEff_T=j3_btagEffError_T=-1001.;
      j4_btagEff_L=j4_btagEffError_L=j4_btagEff_M=j4_btagEffError_M=j4_btagEff_T=j4_btagEffError_T=-1001.;
      j5_btagEff_L=j5_btagEffError_L=j5_btagEff_M=j5_btagEffError_M=j5_btagEff_T=j5_btagEffError_T=-1001.;
      j6_btagEff_L=j6_btagEffError_L=j6_btagEff_M=j6_btagEffError_M=j6_btagEff_T=j6_btagEffError_T=-1001.;
      j7_btagEff_L=j7_btagEffError_L=j7_btagEff_M=j7_btagEffError_M=j7_btagEff_T=j7_btagEffError_T=-1001.;  
      j8_btagEff_L=j8_btagEffError_L=j8_btagEff_M=j8_btagEffError_M=j8_btagEff_T=j8_btagEffError_T=-1001.;
      j9_btagEff_L=j9_btagEffError_L=j9_btagEff_M=j9_btagEffError_M=j9_btagEff_T=j9_btagEffError_T=-1001.;
      j10_btagEff_L=j10_btagEffError_L=j10_btagEff_M=j10_btagEffError_M=j10_btagEff_T=j10_btagEffError_T=-1001.;
      j11_btagEff_L=j11_btagEffError_L=j11_btagEff_M=j11_btagEffError_M=j11_btagEff_T=j11_btagEffError_T=-1001.;   
      j12_btagEff_L=j12_btagEffError_L=j12_btagEff_M=j12_btagEffError_M=j12_btagEff_T=j12_btagEffError_T=-1001.;
      j13_btagEff_L=j13_btagEffError_L=j13_btagEff_M=j13_btagEffError_M=j13_btagEff_T=j13_btagEffError_T=-1001.;
      j14_btagEff_L=j14_btagEffError_L=j14_btagEff_M=j14_btagEffError_M=j14_btagEff_T=j14_btagEffError_T=-1001.;
      j15_btagEff_L=j15_btagEffError_L=j15_btagEff_M=j15_btagEffError_M=j15_btagEff_T=j15_btagEffError_T=-1001.;

      if(j1_e != -1001.){
         jetP4->SetPtEtaPhiE(j1_pt,j1_eta,j1_phi,j1_e);
         j1_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j1_flavour);
         j1_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j1_flavour);
         j1_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j1_flavour);
         j1_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j1_flavour);
         j1_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j1_flavour);
         j1_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j1_flavour);
      }
      
      if(j2_e != -1001.){
         jetP4->SetPtEtaPhiE(j2_pt,j2_eta,j2_phi,j2_e);
         j2_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j2_flavour);
         j2_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j2_flavour);
         j2_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j2_flavour);
         j2_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j2_flavour);
         j2_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j2_flavour);
         j2_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j2_flavour);
      }

      if(j3_e != -1001.){
         jetP4->SetPtEtaPhiE(j3_pt,j3_eta,j3_phi,j3_e);
         j3_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j3_flavour);
         j3_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j3_flavour);
         j3_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j3_flavour);
         j3_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j3_flavour);
         j3_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j3_flavour);
         j3_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j3_flavour);
      }

      if(j4_e != -1001.){
         jetP4->SetPtEtaPhiE(j4_pt,j4_eta,j4_phi,j4_e);
         j4_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j4_flavour);
         j4_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j4_flavour);
         j4_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j4_flavour);
         j4_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j4_flavour);
         j4_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j4_flavour);
         j4_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j4_flavour);
      }

      if(j5_e != -1001.){
         jetP4->SetPtEtaPhiE(j5_pt,j5_eta,j5_phi,j5_e);
         j5_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j5_flavour);
         j5_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j5_flavour);
         j5_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j5_flavour);
         j5_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j5_flavour);
         j5_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j5_flavour);
         j5_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j5_flavour);
      }

      if(j6_e != -1001.){
         jetP4->SetPtEtaPhiE(j6_pt,j6_eta,j6_phi,j6_e);
         j6_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j6_flavour);
         j6_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j6_flavour);
         j6_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j6_flavour);
         j6_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j6_flavour);
         j6_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j6_flavour);
         j6_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j6_flavour);
      }

      if(j7_e != -1001.){
         jetP4->SetPtEtaPhiE(j7_pt,j7_eta,j7_phi,j7_e);
         j7_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j7_flavour);
         j7_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j7_flavour);
         j7_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j7_flavour);
         j7_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j7_flavour);
         j7_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j7_flavour);
         j7_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j7_flavour);
      }

      if(j8_e != -1001.){
         jetP4->SetPtEtaPhiE(j8_pt,j8_eta,j8_phi,j8_e);
         j8_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j8_flavour);
         j8_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j8_flavour);
         j8_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j8_flavour);
         j8_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j8_flavour);
         j8_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j8_flavour);
         j8_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j8_flavour);
      }

      if(j9_e != -1001.){
         jetP4->SetPtEtaPhiE(j9_pt,j9_eta,j9_phi,j9_e);
         j9_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j9_flavour);
         j9_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j9_flavour);
         j9_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j9_flavour);
         j9_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j9_flavour);
         j9_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j9_flavour);
         j9_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j9_flavour);
      }

      if(j10_e != -1001.){
         jetP4->SetPtEtaPhiE(j10_pt,j10_eta,j10_phi,j10_e);
         j10_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j10_flavour);
         j10_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j10_flavour);
         j10_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j10_flavour);
         j10_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j10_flavour);
         j10_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j10_flavour);
         j10_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j10_flavour);
      }

      if(j11_e != -1001.){
         jetP4->SetPtEtaPhiE(j11_pt,j11_eta,j11_phi,j11_e);
         j11_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j11_flavour);
         j11_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j11_flavour);
         j11_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j11_flavour);
         j11_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j11_flavour);
         j11_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j11_flavour);
         j11_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j11_flavour);
      }

      if(j12_e != -1001.){
         jetP4->SetPtEtaPhiE(j12_pt,j12_eta,j12_phi,j12_e);
         j12_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j12_flavour);
         j12_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j12_flavour);
         j12_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j12_flavour);
         j12_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j12_flavour);
         j12_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j12_flavour);
         j12_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j12_flavour);
      }

      if(j13_e != -1001.){
         jetP4->SetPtEtaPhiE(j13_pt,j13_eta,j13_phi,j13_e);
         j13_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j13_flavour);
         j13_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j13_flavour);
         j13_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j13_flavour);
         j13_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j13_flavour);
         j13_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j13_flavour);
         j13_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j13_flavour);
      }

      if(j14_e != -1001.){
         jetP4->SetPtEtaPhiE(j14_pt,j14_eta,j14_phi,j14_e);
         j14_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j14_flavour);
         j14_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j14_flavour);
         j14_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j14_flavour);
         j14_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j14_flavour);
         j14_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j14_flavour);
         j14_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j14_flavour);
      }

      if(j15_e != -1001.){
         jetP4->SetPtEtaPhiE(j15_pt,j15_eta,j15_phi,j15_e);
         j15_btagEff_L = EffReader.getBtagEfficiency(jetP4,"loose",j15_flavour);
         j15_btagEffError_L = EffReader.getBtagEfficiencyError(jetP4,"loose",j15_flavour);
         j15_btagEff_M = EffReader.getBtagEfficiency(jetP4,"medium",j15_flavour);
         j15_btagEffError_M = EffReader.getBtagEfficiencyError(jetP4,"medium",j15_flavour);
         j15_btagEff_T = EffReader.getBtagEfficiency(jetP4,"tight",j15_flavour);
         j15_btagEffError_T = EffReader.getBtagEfficiencyError(jetP4,"tight",j15_flavour);
      }

      FillBranches();
    }

    if(saveMaps != 1) system(("rm output/btagEfficiencies_"+TreeNames.at(ii)+".root").c_str());
  }

  output_final->cd();

  for(unsigned ii = 0; ii < TreeNames.size(); ii++)
      ntu_output[ii]->Write();

  output_final->Close();

}

bool passCutBasedJetId(TLorentzVector* jetP4,TLorentzVector* pho1P4,TLorentzVector* pho2P4){

  bool isGood = true;
  if(jetP4->DeltaR(*pho1P4) < 0.5) isGood = false;
  if(jetP4->DeltaR(*pho2P4) < 0.5) isGood = false;

  return isGood;
}

std::vector<int> chooseMaxptCouple(std::vector<TLorentzVector>* JetP4){

  int jet1 = -1;
  int jet2 = -1; 
   
  float maxPt = 0.;
  TLorentzVector Sum;
  
  for(unsigned int ii = 0; ii <  JetP4->size(); ii++){

      for(unsigned int jj = 0; jj <  JetP4->size(); jj++){

          if(ii == jj) continue;  
          
          Sum = JetP4->at(ii)+JetP4->at(jj);
          
          if(Sum.Pt() > maxPt){
             maxPt = Sum.Pt();
             jet1 = ii;
             jet2 = jj;

          }     
      }  
  }

  std::vector<int> outvec;
  outvec.push_back(jet1);
  outvec.push_back(jet2);

  return outvec;

}

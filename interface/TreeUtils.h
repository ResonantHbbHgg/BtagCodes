#ifndef __TREEUTILS__
#define __TREEUTILS__

#include "TTree.h"

  int           itype;
  int           run;
  int           lumis;
  int           event;
  float         weight;
  float         evweight;
  float         pu_weight;
  float         pu_n;
  float         nvtx;
  float         rho;
  int           category;
  float         ph1_e;
  float         ph2_e;
  float         ph1_pt;
  float         ph2_pt;
  float         ph1_phi;
  float         ph2_phi;
  float         ph1_eta;
  float         ph2_eta;
  int           ph1_ciclevel;
  int           ph2_ciclevel;
  float         j1_e,j2_e,j3_e,j4_e,j5_e,j6_e,j7_e,j8_e,j9_e,j10_e,j11_e,j12_e,j13_e,j14_e,j15_e;
  float         j1_pt,j2_pt,j3_pt,j4_pt,j5_pt,j6_pt,j7_pt,j8_pt,j9_pt,j10_pt,j11_pt,j12_pt,j13_pt,j14_pt,j15_pt;
  float         j1_eta,j2_eta,j3_eta,j4_eta,j5_eta,j6_eta,j7_eta,j8_eta,j9_eta,j10_eta,j11_eta,j12_eta,j13_eta,j14_eta,j15_eta;
  float         j1_phi,j2_phi,j3_phi,j4_phi,j5_phi,j6_phi,j7_phi,j8_phi,j9_phi,j10_phi,j11_phi,j12_phi,j13_phi,j14_phi,j15_phi;
  float         j1_csvBtag,j2_csvBtag,j3_csvBtag,j4_csvBtag,j5_csvBtag,j6_csvBtag,j7_csvBtag,j8_csvBtag,j9_csvBtag,j10_csvBtag,j11_csvBtag, j12_csvBtag,j13_csvBtag,j14_csvBtag,j15_csvBtag;
  float         j1_betaStarClassic,j2_betaStarClassic,j3_betaStarClassic,j4_betaStarClassic,j5_betaStarClassic,j6_betaStarClassic, j7_betaStarClassic,j8_betaStarClassic,j9_betaStarClassic,j10_betaStarClassic,j11_betaStarClassic,j12_betaStarClassic,j13_betaStarClassic, j14_betaStarClassic,j15_betaStarClassic;
  float         j1_dR2Mean,j2_dR2Mean,j3_dR2Mean,j4_dR2Mean,j5_dR2Mean,j6_dR2Mean,j7_dR2Mean,j8_dR2Mean,j9_dR2Mean,j10_dR2Mean,j11_dR2Mean, j12_dR2Mean,j13_dR2Mean,j14_dR2Mean,j15_dR2Mean;
  int    j1_flavour,j2_flavour,j3_flavour,j4_flavour,j5_flavour,j6_flavour,j7_flavour,j8_flavour,j9_flavour,
j10_flavour,j11_flavour, j12_flavour,j13_flavour,j14_flavour,j15_flavour;

 
  float         j1_btagEff_L,j1_btagEffError_L,j1_btagEff_M,j1_btagEffError_M,j1_btagEff_T,j1_btagEffError_T;
  float         j2_btagEff_L,j2_btagEffError_L,j2_btagEff_M,j2_btagEffError_M,j2_btagEff_T,j2_btagEffError_T;
  float         j3_btagEff_L,j3_btagEffError_L,j3_btagEff_M,j3_btagEffError_M,j3_btagEff_T,j3_btagEffError_T;
  float         j4_btagEff_L,j4_btagEffError_L,j4_btagEff_M,j4_btagEffError_M,j4_btagEff_T,j4_btagEffError_T; 
  float         j5_btagEff_L,j5_btagEffError_L,j5_btagEff_M,j5_btagEffError_M,j5_btagEff_T,j5_btagEffError_T;
  float         j6_btagEff_L,j6_btagEffError_L,j6_btagEff_M,j6_btagEffError_M,j6_btagEff_T,j6_btagEffError_T;
  float         j7_btagEff_L,j7_btagEffError_L,j7_btagEff_M,j7_btagEffError_M,j7_btagEff_T,j7_btagEffError_T;  
  float         j8_btagEff_L,j8_btagEffError_L,j8_btagEff_M,j8_btagEffError_M,j8_btagEff_T,j8_btagEffError_T;
  float         j9_btagEff_L,j9_btagEffError_L,j9_btagEff_M,j9_btagEffError_M,j9_btagEff_T,j9_btagEffError_T;
  float         j10_btagEff_L,j10_btagEffError_L,j10_btagEff_M,j10_btagEffError_M,j10_btagEff_T,j10_btagEffError_T;
  float         j11_btagEff_L,j11_btagEffError_L,j11_btagEff_M,j11_btagEffError_M,j11_btagEff_T,j11_btagEffError_T;   
  float         j12_btagEff_L,j12_btagEffError_L,j12_btagEff_M,j12_btagEffError_M,j12_btagEff_T,j12_btagEffError_T;
  float         j13_btagEff_L,j13_btagEffError_L,j13_btagEff_M,j13_btagEffError_M,j13_btagEff_T,j13_btagEffError_T;
  float         j14_btagEff_L,j14_btagEffError_L,j14_btagEff_M,j14_btagEffError_M,j14_btagEff_T,j14_btagEffError_T;
  float         j15_btagEff_L,j15_btagEffError_L,j15_btagEff_M,j15_btagEffError_M,j15_btagEff_T,j15_btagEffError_T;

  // List of branches
  TBranch        *b_itype;   //!
  TBranch        *b_run;   //!
  TBranch        *b_lumis;   //!
  TBranch        *b_event;   //!
  TBranch        *b_weight;   //!
  TBranch        *b_evweight;   //!
  TBranch        *b_pu_weight;   //!
  TBranch        *b_pu_n;   //!
  TBranch        *b_nvtx;   //!
  TBranch        *b_rho;   //!
  TBranch        *b_category;   //!
  TBranch        *b_ph1_e;   //!
  TBranch        *b_ph2_e;   //!
  TBranch        *b_ph1_pt;   //!
  TBranch        *b_ph2_pt;   //!
  TBranch        *b_ph1_phi;   //!
  TBranch        *b_ph2_phi;   //!
  TBranch        *b_ph1_eta;   //!
  TBranch        *b_ph2_eta;   //!
  TBranch        *b_ph1_ciclevel;   //!
  TBranch        *b_ph2_ciclevel;   //!
  TBranch        *b_j1_e,*b_j2_e,*b_j3_e,*b_j4_e,*b_j5_e,*b_j6_e,*b_j7_e,*b_j8_e,*b_j9_e,*b_j10_e,*b_j11_e,*b_j12_e,*b_j13_e,*b_j14_e, *b_j15_e;   //!
  TBranch        *b_j1_pt,*b_j2_pt,*b_j3_pt,*b_j4_pt,*b_j5_pt,*b_j6_pt,*b_j7_pt,*b_j8_pt,*b_j9_pt,*b_j10_pt,*b_j11_pt,*b_j12_pt,*b_j13_pt, *b_j14_pt,*b_j15_pt;   //!
  TBranch        *b_j1_eta,*b_j2_eta,*b_j3_eta,*b_j4_eta,*b_j5_eta,*b_j6_eta,*b_j7_eta,*b_j8_eta,*b_j9_eta,*b_j10_eta,*b_j11_eta,*b_j12_eta, *b_j13_eta,*b_j14_eta,*b_j15_eta;   //!
  TBranch        *b_j1_phi,*b_j2_phi,*b_j3_phi,*b_j4_phi,*b_j5_phi,*b_j6_phi,*b_j7_phi,*b_j8_phi,*b_j9_phi,*b_j10_phi,*b_j11_phi,*b_j12_phi, *b_j13_phi,*b_j14_phi,*b_j15_phi;   //!
  TBranch        *b_j1_csvBtag,*b_j2_csvBtag,*b_j3_csvBtag,*b_j4_csvBtag,*b_j5_csvBtag,*b_j6_csvBtag,*b_j7_csvBtag,*b_j8_csvBtag,*b_j9_csvBtag, *b_j10_csvBtag,*b_j11_csvBtag,*b_j12_csvBtag,*b_j13_csvBtag,*b_j14_csvBtag, *b_j15_csvBtag;   //!
  TBranch        *b_j1_betaStarClassic,*b_j2_betaStarClassic,*b_j3_betaStarClassic,*b_j4_betaStarClassic,*b_j5_betaStarClassic, *b_j6_betaStarClassic,*b_j7_betaStarClassic,*b_j8_betaStarClassic,*b_j9_betaStarClassic,*b_j10_betaStarClassic,*b_j11_betaStarClassic, *b_j12_betaStarClassic, *b_j13_betaStarClassic,*b_j14_betaStarClassic, *b_j15_betaStarClassic;   //!
  TBranch        *b_j1_dR2Mean,*b_j2_dR2Mean,*b_j3_dR2Mean,*b_j4_dR2Mean,*b_j5_dR2Mean,*b_j6_dR2Mean,*b_j7_dR2Mean,*b_j8_dR2Mean, *b_j9_dR2Mean,*b_j10_dR2Mean,*b_j11_dR2Mean,*b_j12_dR2Mean,*b_j13_dR2Mean,*b_j14_dR2Mean, *b_j15_dR2Mean;   //!
  TBranch        *b_j1_flavour,*b_j2_flavour,*b_j3_flavour,*b_j4_flavour,*b_j5_flavour,*b_j6_flavour,*b_j7_flavour,
*b_j8_flavour, *b_j9_flavour,*b_j10_flavour,*b_j11_flavour,*b_j12_flavour,*b_j13_flavour,*b_j14_flavour, *b_j15_flavour;   //!


  TBranch         *b_j1_btagEff_L,*b_j1_btagEffError_L,*b_j1_btagEff_M,*b_j1_btagEffError_M,*b_j1_btagEff_T,*b_j1_btagEffError_T;
  TBranch         *b_j2_btagEff_L,*b_j2_btagEffError_L,*b_j2_btagEff_M,*b_j2_btagEffError_M,*b_j2_btagEff_T,*b_j2_btagEffError_T;
  TBranch         *b_j3_btagEff_L,*b_j3_btagEffError_L,*b_j3_btagEff_M,*b_j3_btagEffError_M,*b_j3_btagEff_T,*b_j3_btagEffError_T;
  TBranch         *b_j4_btagEff_L,*b_j4_btagEffError_L,*b_j4_btagEff_M,*b_j4_btagEffError_M,*b_j4_btagEff_T,*b_j4_btagEffError_T; 
  TBranch         *b_j5_btagEff_L,*b_j5_btagEffError_L,*b_j5_btagEff_M,*b_j5_btagEffError_M,*b_j5_btagEff_T,*b_j5_btagEffError_T;
  TBranch         *b_j6_btagEff_L,*b_j6_btagEffError_L,*b_j6_btagEff_M,*b_j6_btagEffError_M,*b_j6_btagEff_T,*b_j6_btagEffError_T;
  TBranch         *b_j7_btagEff_L,*b_j7_btagEffError_L,*b_j7_btagEff_M,*b_j7_btagEffError_M,*b_j7_btagEff_T,*b_j7_btagEffError_T;  
  TBranch         *b_j8_btagEff_L,*b_j8_btagEffError_L,*b_j8_btagEff_M,*b_j8_btagEffError_M,*b_j8_btagEff_T,*b_j8_btagEffError_T;
  TBranch         *b_j9_btagEff_L,*b_j9_btagEffError_L,*b_j9_btagEff_M,*b_j9_btagEffError_M,*b_j9_btagEff_T,*b_j9_btagEffError_T;
  TBranch         *b_j10_btagEff_L,*b_j10_btagEffError_L,*b_j10_btagEff_M,*b_j10_btagEffError_M,*b_j10_btagEff_T,*b_j10_btagEffError_T;
  TBranch         *b_j11_btagEff_L,*b_j11_btagEffError_L,*b_j11_btagEff_M,*b_j11_btagEffError_M,*b_j11_btagEff_T,*b_j11_btagEffError_T;   
  TBranch         *b_j12_btagEff_L,*b_j12_btagEffError_L,*b_j12_btagEff_M,*b_j12_btagEffError_M,*b_j12_btagEff_T,*b_j12_btagEffError_T;
  TBranch         *b_j13_btagEff_L,*b_j13_btagEffError_L,*b_j13_btagEff_M,*b_j13_btagEffError_M,*b_j13_btagEff_T,*b_j13_btagEffError_T;
  TBranch         *b_j14_btagEff_L,*b_j14_btagEffError_L,*b_j14_btagEff_M,*b_j14_btagEffError_M,*b_j14_btagEff_T,*b_j14_btagEffError_T;
  TBranch         *b_j15_btagEff_L,*b_j15_btagEffError_L,*b_j15_btagEff_M,*b_j15_btagEffError_M,*b_j15_btagEff_T,*b_j15_btagEffError_T;


  void InitTree(TTree* ntu, int addEfficiencies){
  // Set branch addresses and branch pointers
  if(addEfficiencies != 1){
     ntu->SetBranchStatus("j1_btagEff_L",0);
     ntu->SetBranchStatus("j1_btagEffError_L",0);
     ntu->SetBranchStatus("j1_btagEff_M",0);
     ntu->SetBranchStatus("j1_btagEffError_M",0);
     ntu->SetBranchStatus("j1_btagEff_T",0);
     ntu->SetBranchStatus("j1_btagEffError_T",0);
     ntu->SetBranchStatus("j2_btagEff_L",0);
     ntu->SetBranchStatus("j2_btagEffError_L",0);
     ntu->SetBranchStatus("j2_btagEff_M",0);
     ntu->SetBranchStatus("j2_btagEffError_M",0);
     ntu->SetBranchStatus("j2_btagEff_T",0);
     ntu->SetBranchStatus("j2_btagEffError_T",0);
     ntu->SetBranchStatus("j3_btagEff_L",0);
     ntu->SetBranchStatus("j3_btagEffError_L",0);
     ntu->SetBranchStatus("j3_btagEff_M",0);
     ntu->SetBranchStatus("j3_btagEffError_M",0);
     ntu->SetBranchStatus("j3_btagEff_T",0);
     ntu->SetBranchStatus("j3_btagEffError_T",0);
     ntu->SetBranchStatus("j4_btagEff_L",0);
     ntu->SetBranchStatus("j4_btagEffError_L",0);
     ntu->SetBranchStatus("j4_btagEff_M",0);
     ntu->SetBranchStatus("j4_btagEffError_M",0);
     ntu->SetBranchStatus("j4_btagEff_T",0);
     ntu->SetBranchStatus("j4_btagEffError_T",0);
     ntu->SetBranchStatus("j5_btagEff_L",0);
     ntu->SetBranchStatus("j5_btagEffError_L",0);
     ntu->SetBranchStatus("j5_btagEff_M",0);
     ntu->SetBranchStatus("j5_btagEffError_M",0);
     ntu->SetBranchStatus("j5_btagEff_T",0);
     ntu->SetBranchStatus("j5_btagEffError_T",0);
     ntu->SetBranchStatus("j6_btagEff_L",0);
     ntu->SetBranchStatus("j6_btagEffError_L",0);
     ntu->SetBranchStatus("j6_btagEff_M",0);
     ntu->SetBranchStatus("j6_btagEffError_M",0);
     ntu->SetBranchStatus("j6_btagEff_T",0);
     ntu->SetBranchStatus("j6_btagEffError_T",0);
     ntu->SetBranchStatus("j7_btagEff_L",0);
     ntu->SetBranchStatus("j7_btagEffError_L",0);
     ntu->SetBranchStatus("j7_btagEff_M",0);
     ntu->SetBranchStatus("j7_btagEffError_M",0);
     ntu->SetBranchStatus("j7_btagEff_T",0);
     ntu->SetBranchStatus("j7_btagEffError_T",0);
     ntu->SetBranchStatus("j8_btagEff_L",0);
     ntu->SetBranchStatus("j8_btagEffError_L",0);
     ntu->SetBranchStatus("j8_btagEff_M",0);
     ntu->SetBranchStatus("j8_btagEffError_M",0);
     ntu->SetBranchStatus("j8_btagEff_T",0);
     ntu->SetBranchStatus("j8_btagEffError_T",0);
     ntu->SetBranchStatus("j9_btagEff_L",0);
     ntu->SetBranchStatus("j9_btagEffError_L",0);
     ntu->SetBranchStatus("j9_btagEff_M",0);
     ntu->SetBranchStatus("j9_btagEffError_M",0);
     ntu->SetBranchStatus("j9_btagEff_T",0);
     ntu->SetBranchStatus("j9_btagEffError_T",0);
     ntu->SetBranchStatus("j10_btagEff_L",0);
     ntu->SetBranchStatus("j10_btagEffError_L",0);
     ntu->SetBranchStatus("j10_btagEff_M",0);
     ntu->SetBranchStatus("j10_btagEffError_M",0);
     ntu->SetBranchStatus("j10_btagEff_T",0);
     ntu->SetBranchStatus("j10_btagEffError_T",0);
     ntu->SetBranchStatus("j11_btagEff_L",0);
     ntu->SetBranchStatus("j11_btagEffError_L",0);
     ntu->SetBranchStatus("j11_btagEff_M",0);
     ntu->SetBranchStatus("j11_btagEffError_M",0);
     ntu->SetBranchStatus("j11_btagEff_T",0);
     ntu->SetBranchStatus("j11_btagEffError_T",0);
     ntu->SetBranchStatus("j12_btagEff_L",0);
     ntu->SetBranchStatus("j12_btagEffError_L",0);
     ntu->SetBranchStatus("j12_btagEff_M",0);
     ntu->SetBranchStatus("j12_btagEffError_M",0);
     ntu->SetBranchStatus("j12_btagEff_T",0);
     ntu->SetBranchStatus("j12_btagEffError_T",0);
     ntu->SetBranchStatus("j13_btagEff_L",0);
     ntu->SetBranchStatus("j13_btagEffError_L",0);
     ntu->SetBranchStatus("j13_btagEff_M",0);
     ntu->SetBranchStatus("j13_btagEffError_M",0);
     ntu->SetBranchStatus("j13_btagEff_T",0);
     ntu->SetBranchStatus("j13_btagEffError_T",0);
     ntu->SetBranchStatus("j14_btagEff_L",0);
     ntu->SetBranchStatus("j14_btagEffError_L",0);
     ntu->SetBranchStatus("j14_btagEff_M",0);
     ntu->SetBranchStatus("j14_btagEffError_M",0);
     ntu->SetBranchStatus("j14_btagEff_T",0);
     ntu->SetBranchStatus("j14_btagEffError_T",0);
     ntu->SetBranchStatus("j15_btagEff_L",0);
     ntu->SetBranchStatus("j15_btagEffError_L",0);
     ntu->SetBranchStatus("j15_btagEff_M",0);
     ntu->SetBranchStatus("j15_btagEffError_M",0);
     ntu->SetBranchStatus("j15_btagEff_T",0);
     ntu->SetBranchStatus("j15_btagEffError_T",0);
  }
  ntu->SetBranchAddress("itype", &itype, &b_itype);
  ntu->SetBranchAddress("run", &run, &b_run);
  ntu->SetBranchAddress("lumis", &lumis, &b_lumis);
  ntu->SetBranchAddress("event", &event, &b_event);
  ntu->SetBranchAddress("weight", &weight, &b_weight);
  ntu->SetBranchAddress("evweight", &evweight, &b_evweight);
  ntu->SetBranchAddress("pu_weight", &pu_weight, &b_pu_weight);
  ntu->SetBranchAddress("pu_n", &pu_n, &b_pu_n);
  ntu->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
  ntu->SetBranchAddress("rho", &rho, &b_rho);
  ntu->SetBranchAddress("category", &category, &b_category);
  ntu->SetBranchAddress("ph1_e", &ph1_e, &b_ph1_e);
  ntu->SetBranchAddress("ph2_e", &ph2_e, &b_ph2_e);
  ntu->SetBranchAddress("ph1_pt", &ph1_pt, &b_ph1_pt);
  ntu->SetBranchAddress("ph2_pt", &ph2_pt, &b_ph2_pt);
  ntu->SetBranchAddress("ph1_phi", &ph1_phi, &b_ph1_phi);
  ntu->SetBranchAddress("ph2_phi", &ph2_phi, &b_ph2_phi);
  ntu->SetBranchAddress("ph1_eta", &ph1_eta, &b_ph1_eta);
  ntu->SetBranchAddress("ph2_eta", &ph2_eta, &b_ph2_eta);
  ntu->SetBranchAddress("ph1_ciclevel", &ph1_ciclevel, &b_ph1_ciclevel);
  ntu->SetBranchAddress("ph2_ciclevel", &ph2_ciclevel, &b_ph2_ciclevel);
  ntu->SetBranchAddress("j1_e", &j1_e, &b_j1_e);
  ntu->SetBranchAddress("j1_pt", &j1_pt, &b_j1_pt);
  ntu->SetBranchAddress("j1_phi", &j1_phi, &b_j1_phi);
  ntu->SetBranchAddress("j1_eta", &j1_eta, &b_j1_eta);
  ntu->SetBranchAddress("j1_csvBtag", &j1_csvBtag, &b_j1_csvBtag);
  ntu->SetBranchAddress("j1_betaStarClassic", &j1_betaStarClassic, &b_j1_betaStarClassic);
  ntu->SetBranchAddress("j1_dR2Mean", &j1_dR2Mean, &b_j1_dR2Mean);
  ntu->SetBranchAddress("j1_flavour", &j1_flavour, &b_j1_flavour);
  ntu->SetBranchAddress("j2_e", &j2_e, &b_j2_e);
  ntu->SetBranchAddress("j2_pt", &j2_pt, &b_j2_pt);
  ntu->SetBranchAddress("j2_phi", &j2_phi, &b_j2_phi);
  ntu->SetBranchAddress("j2_eta", &j2_eta, &b_j2_eta);
  ntu->SetBranchAddress("j2_csvBtag", &j2_csvBtag, &b_j2_csvBtag);
  ntu->SetBranchAddress("j2_betaStarClassic", &j2_betaStarClassic, &b_j2_betaStarClassic);
  ntu->SetBranchAddress("j2_dR2Mean", &j2_dR2Mean, &b_j2_dR2Mean);
  ntu->SetBranchAddress("j2_flavour", &j2_flavour, &b_j2_flavour);
  ntu->SetBranchAddress("j3_e", &j3_e, &b_j3_e);
  ntu->SetBranchAddress("j3_pt", &j3_pt, &b_j3_pt);
  ntu->SetBranchAddress("j3_phi", &j3_phi, &b_j3_phi);
  ntu->SetBranchAddress("j3_eta", &j3_eta, &b_j3_eta);
  ntu->SetBranchAddress("j3_csvBtag", &j3_csvBtag, &b_j3_csvBtag);
  ntu->SetBranchAddress("j3_betaStarClassic", &j3_betaStarClassic, &b_j3_betaStarClassic);
  ntu->SetBranchAddress("j3_dR2Mean", &j3_dR2Mean, &b_j3_dR2Mean);
  ntu->SetBranchAddress("j3_flavour", &j3_flavour, &b_j3_flavour);
  ntu->SetBranchAddress("j4_e", &j4_e, &b_j4_e);
  ntu->SetBranchAddress("j4_pt", &j4_pt, &b_j4_pt);
  ntu->SetBranchAddress("j4_phi", &j4_phi, &b_j4_phi);
  ntu->SetBranchAddress("j4_eta", &j4_eta, &b_j4_eta);
  ntu->SetBranchAddress("j4_csvBtag", &j4_csvBtag, &b_j4_csvBtag);
  ntu->SetBranchAddress("j4_betaStarClassic", &j4_betaStarClassic, &b_j4_betaStarClassic);
  ntu->SetBranchAddress("j4_dR2Mean", &j4_dR2Mean, &b_j4_dR2Mean);
  ntu->SetBranchAddress("j4_flavour", &j4_flavour, &b_j4_flavour);
  ntu->SetBranchAddress("j5_e", &j5_e, &b_j5_e);
  ntu->SetBranchAddress("j5_pt", &j5_pt, &b_j5_pt);
  ntu->SetBranchAddress("j5_phi", &j5_phi, &b_j5_phi);
  ntu->SetBranchAddress("j5_eta", &j5_eta, &b_j5_eta);
  ntu->SetBranchAddress("j5_csvBtag", &j5_csvBtag, &b_j5_csvBtag);
  ntu->SetBranchAddress("j5_betaStarClassic", &j5_betaStarClassic, &b_j5_betaStarClassic);
  ntu->SetBranchAddress("j5_dR2Mean", &j5_dR2Mean, &b_j5_dR2Mean);
  ntu->SetBranchAddress("j5_flavour", &j5_flavour, &b_j5_flavour);
  ntu->SetBranchAddress("j6_e", &j6_e, &b_j6_e);
  ntu->SetBranchAddress("j6_pt", &j6_pt, &b_j6_pt);
  ntu->SetBranchAddress("j6_phi", &j6_phi, &b_j6_phi);
  ntu->SetBranchAddress("j6_eta", &j6_eta, &b_j6_eta);
  ntu->SetBranchAddress("j6_csvBtag", &j6_csvBtag, &b_j6_csvBtag);
  ntu->SetBranchAddress("j6_betaStarClassic", &j6_betaStarClassic, &b_j6_betaStarClassic);
  ntu->SetBranchAddress("j6_dR2Mean", &j6_dR2Mean, &b_j6_dR2Mean);
  ntu->SetBranchAddress("j6_flavour", &j6_flavour, &b_j6_flavour);
  ntu->SetBranchAddress("j7_e", &j7_e, &b_j7_e);
  ntu->SetBranchAddress("j7_pt", &j7_pt, &b_j7_pt);
  ntu->SetBranchAddress("j7_phi", &j7_phi, &b_j7_phi);
  ntu->SetBranchAddress("j7_eta", &j7_eta, &b_j7_eta);
  ntu->SetBranchAddress("j7_csvBtag", &j7_csvBtag, &b_j7_csvBtag);
  ntu->SetBranchAddress("j7_betaStarClassic", &j7_betaStarClassic, &b_j7_betaStarClassic);
  ntu->SetBranchAddress("j7_dR2Mean", &j7_dR2Mean, &b_j7_dR2Mean);
  ntu->SetBranchAddress("j7_flavour", &j7_flavour, &b_j7_flavour);
  ntu->SetBranchAddress("j8_e", &j8_e, &b_j8_e);
  ntu->SetBranchAddress("j8_pt", &j8_pt, &b_j8_pt);
  ntu->SetBranchAddress("j8_phi", &j8_phi, &b_j8_phi);
  ntu->SetBranchAddress("j8_eta", &j8_eta, &b_j8_eta);
  ntu->SetBranchAddress("j8_csvBtag", &j8_csvBtag, &b_j8_csvBtag);
  ntu->SetBranchAddress("j8_betaStarClassic", &j8_betaStarClassic, &b_j8_betaStarClassic);
  ntu->SetBranchAddress("j8_dR2Mean", &j8_dR2Mean, &b_j8_dR2Mean);
  ntu->SetBranchAddress("j8_flavour", &j8_flavour, &b_j8_flavour);
  ntu->SetBranchAddress("j9_e", &j9_e, &b_j9_e);
  ntu->SetBranchAddress("j9_pt", &j9_pt, &b_j9_pt);
  ntu->SetBranchAddress("j9_phi", &j9_phi, &b_j9_phi);
  ntu->SetBranchAddress("j9_eta", &j9_eta, &b_j9_eta);
  ntu->SetBranchAddress("j9_csvBtag", &j9_csvBtag, &b_j9_csvBtag);
  ntu->SetBranchAddress("j9_betaStarClassic", &j9_betaStarClassic, &b_j9_betaStarClassic);
  ntu->SetBranchAddress("j9_dR2Mean", &j9_dR2Mean, &b_j9_dR2Mean);
  ntu->SetBranchAddress("j9_flavour", &j9_flavour, &b_j9_flavour);
  ntu->SetBranchAddress("j10_e", &j10_e, &b_j10_e);
  ntu->SetBranchAddress("j10_pt", &j10_pt, &b_j10_pt);
  ntu->SetBranchAddress("j10_phi", &j10_phi, &b_j10_phi);
  ntu->SetBranchAddress("j10_eta", &j10_eta, &b_j10_eta);
  ntu->SetBranchAddress("j10_csvBtag", &j10_csvBtag, &b_j10_csvBtag);
  ntu->SetBranchAddress("j10_betaStarClassic", &j10_betaStarClassic, &b_j10_betaStarClassic);
  ntu->SetBranchAddress("j10_dR2Mean", &j10_dR2Mean, &b_j10_dR2Mean);
  ntu->SetBranchAddress("j10_flavour", &j10_flavour, &b_j10_flavour);
  ntu->SetBranchAddress("j11_e", &j11_e, &b_j11_e);
  ntu->SetBranchAddress("j11_pt", &j11_pt, &b_j11_pt);
  ntu->SetBranchAddress("j11_phi", &j11_phi, &b_j11_phi);
  ntu->SetBranchAddress("j11_eta", &j11_eta, &b_j11_eta);
  ntu->SetBranchAddress("j11_csvBtag", &j11_csvBtag, &b_j11_csvBtag);  
  ntu->SetBranchAddress("j11_betaStarClassic", &j11_betaStarClassic, &b_j11_betaStarClassic);
  ntu->SetBranchAddress("j11_dR2Mean", &j11_dR2Mean, &b_j11_dR2Mean);
  ntu->SetBranchAddress("j11_flavour", &j11_flavour, &b_j11_flavour);
  ntu->SetBranchAddress("j12_e", &j12_e, &b_j12_e);
  ntu->SetBranchAddress("j12_pt", &j12_pt, &b_j12_pt);
  ntu->SetBranchAddress("j12_phi", &j12_phi, &b_j12_phi);
  ntu->SetBranchAddress("j12_eta", &j12_eta, &b_j12_eta);
  ntu->SetBranchAddress("j12_csvBtag", &j12_csvBtag, &b_j12_csvBtag);
  ntu->SetBranchAddress("j12_betaStarClassic", &j12_betaStarClassic, &b_j12_betaStarClassic);
  ntu->SetBranchAddress("j12_dR2Mean", &j12_dR2Mean, &b_j12_dR2Mean);
  ntu->SetBranchAddress("j12_flavour", &j12_flavour, &b_j12_flavour);
  ntu->SetBranchAddress("j13_e", &j13_e, &b_j13_e);
  ntu->SetBranchAddress("j13_pt", &j13_pt, &b_j13_pt);
  ntu->SetBranchAddress("j13_phi", &j13_phi, &b_j13_phi);
  ntu->SetBranchAddress("j13_eta", &j13_eta, &b_j13_eta);
  ntu->SetBranchAddress("j13_csvBtag", &j13_csvBtag, &b_j13_csvBtag);
  ntu->SetBranchAddress("j13_betaStarClassic", &j13_betaStarClassic, &b_j13_betaStarClassic);
  ntu->SetBranchAddress("j13_dR2Mean", &j13_dR2Mean, &b_j13_dR2Mean);
  ntu->SetBranchAddress("j13_flavour", &j13_flavour, &b_j13_flavour);
  ntu->SetBranchAddress("j14_e", &j14_e, &b_j14_e);
  ntu->SetBranchAddress("j14_pt", &j14_pt, &b_j14_pt);
  ntu->SetBranchAddress("j14_phi", &j14_phi, &b_j14_phi);
  ntu->SetBranchAddress("j14_eta", &j14_eta, &b_j14_eta);
  ntu->SetBranchAddress("j14_csvBtag", &j14_csvBtag, &b_j14_csvBtag);
  ntu->SetBranchAddress("j14_betaStarClassic", &j14_betaStarClassic, &b_j14_betaStarClassic);
  ntu->SetBranchAddress("j14_dR2Mean", &j14_dR2Mean, &b_j14_dR2Mean);
  ntu->SetBranchAddress("j14_flavour", &j14_flavour, &b_j14_flavour);
  ntu->SetBranchAddress("j15_e", &j15_e, &b_j15_e);
  ntu->SetBranchAddress("j15_pt", &j15_pt, &b_j15_pt);
  ntu->SetBranchAddress("j15_phi", &j15_phi, &b_j15_phi);
  ntu->SetBranchAddress("j15_eta", &j15_eta, &b_j15_eta);
  ntu->SetBranchAddress("j15_csvBtag", &j15_csvBtag, &b_j15_csvBtag);
  ntu->SetBranchAddress("j15_betaStarClassic", &j15_betaStarClassic, &b_j15_betaStarClassic);
  ntu->SetBranchAddress("j15_dR2Mean", &j15_dR2Mean, &b_j15_dR2Mean);
  ntu->SetBranchAddress("j15_flavour", &j15_flavour, &b_j15_flavour);
  }

  void AddBranches(TTree* ntu){
    b_j1_btagEff_L = ntu-> Branch("j1_btagEff_L",&j1_btagEff_L,"j1_btagEff_L/F");
    b_j1_btagEffError_L = ntu-> Branch("j1_btagEffError_L",&j1_btagEffError_L,"j1_btagEffError_L/F");
    b_j1_btagEff_M = ntu-> Branch("j1_btagEff_M",&j1_btagEff_M,"j1_btagEff_M/F");
    b_j1_btagEffError_M = ntu-> Branch("j1_btagEffError_M",&j1_btagEffError_M,"j1_btagEffError_M/F");
    b_j1_btagEff_T = ntu-> Branch("j1_btagEff_T",&j1_btagEff_T,"j1_btagEff_T/F");
    b_j1_btagEffError_T = ntu-> Branch("j1_btagEffError_T",&j1_btagEffError_T,"j1_btagEffError_T/F");
    b_j2_btagEff_L = ntu-> Branch("j2_btagEff_L",&j2_btagEff_L,"j2_btagEff_L/F");
    b_j2_btagEffError_L = ntu-> Branch("j2_btagEffError_L",&j2_btagEffError_L,"j2_btagEffError_L/F");
    b_j2_btagEff_M = ntu-> Branch("j2_btagEff_M",&j2_btagEff_M,"j2_btagEff_M/F");
    b_j2_btagEffError_M = ntu-> Branch("j2_btagEffError_M",&j2_btagEffError_M,"j2_btagEffError_M/F");
    b_j2_btagEff_T = ntu-> Branch("j2_btagEff_T",&j2_btagEff_T,"j2_btagEff_T/F");
    b_j2_btagEffError_T = ntu-> Branch("j2_btagEffError_T",&j2_btagEffError_T,"j2_btagEffError_T/F");
    b_j3_btagEff_L = ntu-> Branch("j3_btagEff_L",&j3_btagEff_L,"j3_btagEff_L/F");
    b_j3_btagEffError_L = ntu-> Branch("j3_btagEffError_L",&j3_btagEffError_L,"j3_btagEffError_L/F");
    b_j3_btagEff_M = ntu-> Branch("j3_btagEff_M",&j3_btagEff_M,"j3_btagEff_M/F");
    b_j3_btagEffError_M = ntu-> Branch("j3_btagEffError_M",&j3_btagEffError_M,"j3_btagEffError_M/F");
    b_j3_btagEff_T = ntu-> Branch("j3_btagEff_T",&j3_btagEff_T,"j3_btagEff_T/F");
    b_j3_btagEffError_T = ntu-> Branch("j3_btagEffError_T",&j3_btagEffError_T,"j3_btagEffError_T/F");
    b_j4_btagEff_L = ntu-> Branch("j4_btagEff_L",&j4_btagEff_L,"j4_btagEff_L/F");
    b_j4_btagEffError_L = ntu-> Branch("j4_btagEffError_L",&j4_btagEffError_L,"j4_btagEffError_L/F");
    b_j4_btagEff_M = ntu-> Branch("j4_btagEff_M",&j4_btagEff_M,"j4_btagEff_M/F");
    b_j4_btagEffError_M = ntu-> Branch("j4_btagEffError_M",&j4_btagEffError_M,"j4_btagEffError_M/F");
    b_j4_btagEff_T = ntu-> Branch("j4_btagEff_T",&j4_btagEff_T,"j4_btagEff_T/F");
    b_j4_btagEffError_T = ntu-> Branch("j4_btagEffError_T",&j4_btagEffError_T,"j4_btagEffError_T/F");
    b_j5_btagEff_L = ntu-> Branch("j5_btagEff_L",&j5_btagEff_L,"j5_btagEff_L/F");
    b_j5_btagEffError_L = ntu-> Branch("j5_btagEffError_L",&j5_btagEffError_L,"j5_btagEffError_L/F");
    b_j5_btagEff_M = ntu-> Branch("j5_btagEff_M",&j5_btagEff_M,"j5_btagEff_M/F");
    b_j5_btagEffError_M = ntu-> Branch("j5_btagEffError_M",&j5_btagEffError_M,"j5_btagEffError_M/F");
    b_j5_btagEff_T = ntu-> Branch("j5_btagEff_T",&j5_btagEff_T,"j5_btagEff_T/F");
    b_j5_btagEffError_T = ntu-> Branch("j5_btagEffError_T",&j5_btagEffError_T,"j5_btagEffError_T/F");
    b_j6_btagEff_L = ntu-> Branch("j6_btagEff_L",&j6_btagEff_L,"j6_btagEff_L/F");
    b_j6_btagEffError_L = ntu-> Branch("j6_btagEffError_L",&j6_btagEffError_L,"j6_btagEffError_L/F");
    b_j6_btagEff_M = ntu-> Branch("j6_btagEff_M",&j6_btagEff_M,"j6_btagEff_M/F");
    b_j6_btagEffError_M = ntu-> Branch("j6_btagEffError_M",&j6_btagEffError_M,"j6_btagEffError_M/F");
    b_j6_btagEff_T = ntu-> Branch("j6_btagEff_T",&j6_btagEff_T,"j6_btagEff_T/F");
    b_j6_btagEffError_T = ntu-> Branch("j6_btagEffError_T",&j6_btagEffError_T,"j6_btagEffError_T/F");
    b_j7_btagEff_L = ntu-> Branch("j7_btagEff_L",&j7_btagEff_L,"j7_btagEff_L/F");
    b_j7_btagEffError_L = ntu-> Branch("j7_btagEffError_L",&j7_btagEffError_L,"j7_btagEffError_L/F");
    b_j7_btagEff_M = ntu-> Branch("j7_btagEff_M",&j7_btagEff_M,"j7_btagEff_M/F");
    b_j7_btagEffError_M = ntu-> Branch("j7_btagEffError_M",&j7_btagEffError_M,"j7_btagEffError_M/F");
    b_j7_btagEff_T = ntu-> Branch("j7_btagEff_T",&j7_btagEff_T,"j7_btagEff_T/F");
    b_j7_btagEffError_T = ntu-> Branch("j7_btagEffError_T",&j7_btagEffError_T,"j7_btagEffError_T/F");
    b_j8_btagEff_L = ntu-> Branch("j8_btagEff_L",&j8_btagEff_L,"j8_btagEff_L/F");
    b_j8_btagEffError_L = ntu-> Branch("j8_btagEffError_L",&j8_btagEffError_L,"j8_btagEffError_L/F");
    b_j8_btagEff_M = ntu-> Branch("j8_btagEff_M",&j8_btagEff_M,"j8_btagEff_M/F");
    b_j8_btagEffError_M = ntu-> Branch("j8_btagEffError_M",&j8_btagEffError_M,"j8_btagEffError_M/F");
    b_j8_btagEff_T = ntu-> Branch("j8_btagEff_T",&j8_btagEff_T,"j8_btagEff_T/F");
    b_j8_btagEffError_T = ntu-> Branch("j8_btagEffError_T",&j8_btagEffError_T,"j8_btagEffError_T/F");
    b_j9_btagEff_L = ntu-> Branch("j9_btagEff_L",&j9_btagEff_L,"j9_btagEff_L/F");
    b_j9_btagEffError_L = ntu-> Branch("j9_btagEffError_L",&j9_btagEffError_L,"j9_btagEffError_L/F");
    b_j9_btagEff_M = ntu-> Branch("j9_btagEff_M",&j9_btagEff_M,"j9_btagEff_M/F");
    b_j9_btagEffError_M = ntu-> Branch("j9_btagEffError_M",&j9_btagEffError_M,"j9_btagEffError_M/F");
    b_j9_btagEff_T = ntu-> Branch("j9_btagEff_T",&j9_btagEff_T,"j9_btagEff_T/F");
    b_j9_btagEffError_T = ntu-> Branch("j9_btagEffError_T",&j9_btagEffError_T,"j9_btagEffError_T/F");   
    b_j10_btagEff_L = ntu-> Branch("j10_btagEff_L",&j10_btagEff_L,"j10_btagEff_L/F");
    b_j10_btagEffError_L = ntu-> Branch("j10_btagEffError_L",&j10_btagEffError_L,"j10_btagEffError_L/F");
    b_j10_btagEff_M = ntu-> Branch("j10_btagEff_M",&j10_btagEff_M,"j10_btagEff_M/F");
    b_j10_btagEffError_M = ntu-> Branch("j10_btagEffError_M",&j10_btagEffError_M,"j10_btagEffError_M/F");
    b_j10_btagEff_T = ntu-> Branch("j10_btagEff_T",&j10_btagEff_T,"j10_btagEff_T/F");
    b_j10_btagEffError_T = ntu-> Branch("j10_btagEffError_T",&j10_btagEffError_T,"j10_btagEffError_T/F");
    b_j11_btagEff_L = ntu-> Branch("j11_btagEff_L",&j11_btagEff_L,"j11_btagEff_L/F");
    b_j11_btagEffError_L = ntu-> Branch("j11_btagEffError_L",&j11_btagEffError_L,"j11_btagEffError_L/F");
    b_j11_btagEff_M = ntu-> Branch("j11_btagEff_M",&j11_btagEff_M,"j11_btagEff_M/F");
    b_j11_btagEffError_M = ntu-> Branch("j11_btagEffError_M",&j11_btagEffError_M,"j11_btagEffError_M/F");
    b_j11_btagEff_T = ntu-> Branch("j11_btagEff_T",&j11_btagEff_T,"j11_btagEff_T/F");
    b_j11_btagEffError_T = ntu-> Branch("j11_btagEffError_T",&j11_btagEffError_T,"j11_btagEffError_T/F");
    b_j12_btagEff_L = ntu-> Branch("j12_btagEff_L",&j12_btagEff_L,"j12_btagEff_L/F");
    b_j12_btagEffError_L = ntu-> Branch("j12_btagEffError_L",&j12_btagEffError_L,"j12_btagEffError_L/F");
    b_j12_btagEff_M = ntu-> Branch("j12_btagEff_M",&j12_btagEff_M,"j12_btagEff_M/F");
    b_j12_btagEffError_M = ntu-> Branch("j12_btagEffError_M",&j12_btagEffError_M,"j12_btagEffError_M/F");
    b_j12_btagEff_T = ntu-> Branch("j12_btagEff_T",&j12_btagEff_T,"j12_btagEff_T/F");
    b_j12_btagEffError_T = ntu-> Branch("j12_btagEffError_T",&j12_btagEffError_T,"j12_btagEffError_T/F");
    b_j13_btagEff_L = ntu-> Branch("j13_btagEff_L",&j13_btagEff_L,"j13_btagEff_L/F");
    b_j13_btagEffError_L = ntu-> Branch("j13_btagEffError_L",&j13_btagEffError_L,"j13_btagEffError_L/F");
    b_j13_btagEff_M = ntu-> Branch("j13_btagEff_M",&j13_btagEff_M,"j13_btagEff_M/F");
    b_j13_btagEffError_M = ntu-> Branch("j13_btagEffError_M",&j13_btagEffError_M,"j13_btagEffError_M/F");
    b_j13_btagEff_T = ntu-> Branch("j13_btagEff_T",&j13_btagEff_T,"j13_btagEff_T/F");
    b_j13_btagEffError_T = ntu-> Branch("j13_btagEffError_T",&j13_btagEffError_T,"j13_btagEffError_T/F");
    b_j14_btagEff_L = ntu-> Branch("j14_btagEff_L",&j14_btagEff_L,"j14_btagEff_L/F");
    b_j14_btagEffError_L = ntu-> Branch("j14_btagEffError_L",&j14_btagEffError_L,"j14_btagEffError_L/F");
    b_j14_btagEff_M = ntu-> Branch("j14_btagEff_M",&j14_btagEff_M,"j14_btagEff_M/F");
    b_j14_btagEffError_M = ntu-> Branch("j14_btagEffError_M",&j14_btagEffError_M,"j14_btagEffError_M/F");
    b_j14_btagEff_T = ntu-> Branch("j14_btagEff_T",&j14_btagEff_T,"j14_btagEff_T/F");
    b_j14_btagEffError_T = ntu-> Branch("j14_btagEffError_T",&j14_btagEffError_T,"j14_btagEffError_T/F");
    b_j14_btagEff_L = ntu-> Branch("j14_btagEff_L",&j14_btagEff_L,"j14_btagEff_L/F");
    b_j14_btagEffError_L = ntu-> Branch("j14_btagEffError_L",&j14_btagEffError_L,"j14_btagEffError_L/F");
    b_j14_btagEff_M = ntu-> Branch("j14_btagEff_M",&j14_btagEff_M,"j14_btagEff_M/F");
    b_j14_btagEffError_M = ntu-> Branch("j14_btagEffError_M",&j14_btagEffError_M,"j14_btagEffError_M/F");
    b_j14_btagEff_T = ntu-> Branch("j14_btagEff_T",&j14_btagEff_T,"j14_btagEff_T/F");
    b_j14_btagEffError_T = ntu-> Branch("j14_btagEffError_T",&j14_btagEffError_T,"j14_btagEffError_T/F");
    b_j15_btagEff_L = ntu-> Branch("j15_btagEff_L",&j15_btagEff_L,"j15_btagEff_L/F");
    b_j15_btagEffError_L = ntu-> Branch("j15_btagEffError_L",&j15_btagEffError_L,"j15_btagEffError_L/F");
    b_j15_btagEff_M = ntu-> Branch("j15_btagEff_M",&j15_btagEff_M,"j15_btagEff_M/F");
    b_j15_btagEffError_M = ntu-> Branch("j15_btagEffError_M",&j15_btagEffError_M,"j15_btagEffError_M/F");
    b_j15_btagEff_T = ntu-> Branch("j15_btagEff_T",&j15_btagEff_T,"j15_btagEff_T/F");
    b_j15_btagEffError_T = ntu-> Branch("j15_btagEffError_T",&j15_btagEffError_T,"j15_btagEffError_T/F");
    b_j15_btagEff_L = ntu-> Branch("j15_btagEff_L",&j15_btagEff_L,"j15_btagEff_L/F");
    b_j15_btagEffError_L = ntu-> Branch("j15_btagEffError_L",&j15_btagEffError_L,"j15_btagEffError_L/F");
    b_j15_btagEff_M = ntu-> Branch("j15_btagEff_M",&j15_btagEff_M,"j15_btagEff_M/F");
    b_j15_btagEffError_M = ntu-> Branch("j15_btagEffError_M",&j15_btagEffError_M,"j15_btagEffError_M/F");
    b_j15_btagEff_T = ntu-> Branch("j15_btagEff_T",&j15_btagEff_T,"j15_btagEff_T/F");
    b_j15_btagEffError_T = ntu-> Branch("j15_btagEffError_T",&j15_btagEffError_T,"j15_btagEffError_T/F");
  }

  void FillBranches(){
    b_j1_btagEff_L->Fill();
    b_j1_btagEffError_L->Fill();
    b_j1_btagEff_M->Fill();
    b_j1_btagEffError_M->Fill();
    b_j1_btagEff_T->Fill();
    b_j1_btagEffError_T->Fill();
    b_j2_btagEff_L->Fill();
    b_j2_btagEffError_L->Fill();
    b_j2_btagEff_M->Fill();
    b_j2_btagEffError_M->Fill();
    b_j2_btagEff_T->Fill();
    b_j2_btagEffError_T->Fill();
    b_j3_btagEff_L->Fill();
    b_j3_btagEffError_L->Fill();
    b_j3_btagEff_M->Fill();
    b_j3_btagEffError_M->Fill();
    b_j3_btagEff_T->Fill();
    b_j3_btagEffError_T->Fill();
    b_j4_btagEff_L->Fill();
    b_j4_btagEffError_L->Fill();
    b_j4_btagEff_M->Fill();
    b_j4_btagEffError_M->Fill();
    b_j4_btagEff_T->Fill();
    b_j4_btagEffError_T->Fill();
    b_j5_btagEff_L->Fill();
    b_j5_btagEffError_L->Fill();
    b_j5_btagEff_M->Fill();
    b_j5_btagEffError_M->Fill();
    b_j5_btagEff_T->Fill();
    b_j5_btagEffError_T->Fill();
    b_j6_btagEff_L->Fill();
    b_j6_btagEffError_L->Fill();
    b_j6_btagEff_M->Fill();
    b_j6_btagEffError_M->Fill();
    b_j6_btagEff_T->Fill();
    b_j6_btagEffError_T->Fill();
    b_j7_btagEff_L->Fill();
    b_j7_btagEffError_L->Fill();
    b_j7_btagEff_M->Fill();
    b_j7_btagEffError_M->Fill();
    b_j7_btagEff_T->Fill();
    b_j7_btagEffError_T->Fill();
    b_j8_btagEff_L->Fill();
    b_j8_btagEffError_L->Fill();
    b_j8_btagEff_M->Fill();
    b_j8_btagEffError_M->Fill();
    b_j8_btagEff_T->Fill();
    b_j8_btagEffError_T->Fill();
    b_j9_btagEff_L->Fill();
    b_j9_btagEffError_L->Fill();
    b_j9_btagEff_M->Fill();
    b_j9_btagEffError_M->Fill();
    b_j9_btagEff_T->Fill();
    b_j9_btagEffError_T->Fill();
    b_j10_btagEff_L->Fill();
    b_j10_btagEffError_L->Fill();
    b_j10_btagEff_M->Fill();
    b_j10_btagEffError_M->Fill();
    b_j10_btagEff_T->Fill();
    b_j10_btagEffError_T->Fill();
    b_j11_btagEff_L->Fill();
    b_j11_btagEffError_L->Fill();
    b_j11_btagEff_M->Fill();
    b_j11_btagEffError_M->Fill();
    b_j11_btagEff_T->Fill();
    b_j11_btagEffError_T->Fill();
    b_j12_btagEff_L->Fill();
    b_j12_btagEffError_L->Fill();
    b_j12_btagEff_M->Fill();
    b_j12_btagEffError_M->Fill();
    b_j12_btagEff_T->Fill();
    b_j12_btagEffError_T->Fill();
    b_j13_btagEff_L->Fill();
    b_j13_btagEffError_L->Fill();
    b_j13_btagEff_M->Fill();
    b_j13_btagEffError_M->Fill();
    b_j13_btagEff_T->Fill();
    b_j13_btagEffError_T->Fill();
    b_j14_btagEff_L->Fill();
    b_j14_btagEffError_L->Fill();
    b_j14_btagEff_M->Fill();
    b_j14_btagEffError_M->Fill();
    b_j14_btagEff_T->Fill();
    b_j14_btagEffError_T->Fill();
    b_j15_btagEff_L->Fill();
    b_j15_btagEffError_L->Fill();
    b_j15_btagEff_M->Fill();
    b_j15_btagEffError_M->Fill();
    b_j15_btagEff_T->Fill();
    b_j15_btagEffError_T->Fill();
  }

#endif

#include "BSMFramework/BSM3G_TNT_Maker/interface/TriggerSelector.h"
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf
TriggerSelector::TriggerSelector(std::string name, TTree* tree, bool debug, const pset& iConfig):baseTree(name,tree,debug){
  triggerBits_       = iConfig.getParameter<edm::InputTag>("bits");
  _maxtriggerversion = iConfig.getParameter<double>("maxtriggerversion");
<<<<<<< HEAD
  _reduced = iConfig.getParameter<bool>("reduced");
=======
  _is_data = iConfig.getParameter<bool>("is_data");
  _reHLT   = iConfig.getParameter<bool>("reHLT");
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  SetBranches();
}
TriggerSelector::~TriggerSelector(){
  delete tree_;
}
void TriggerSelector::Fill(const edm::Event& iEvent, const edm::EventSetup& iSetup){
  if(debug_)    std::cout<<"getting met info"<<std::endl;
  Clear();
<<<<<<< HEAD
  //Trigget paths  
  edm::Handle<edm::TriggerResults> triggerBits;
  iEvent.getByLabel(triggerBits_, triggerBits);
  const edm::TriggerNames &trigNames = iEvent.triggerNames(*triggerBits);
  for(double tv=0.; tv<=_maxtriggerversion; tv++){ 
    char buffer[14]; sprintf(buffer,"%g",tv);
    uint HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_v(trigNames.triggerIndex(("HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_v"+string(buffer)).c_str()));
    if(HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_v<triggerBits->size()) HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg = triggerBits->accept(HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_v);
    uint HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_v(trigNames.triggerIndex(("HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_v"+string(buffer)).c_str()));
    if(HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_v<triggerBits->size()) HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg = triggerBits->accept(HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_v);
    uint HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg_v(trigNames.triggerIndex(("HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg_v"+string(buffer)).c_str()));
    if(HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg_v<triggerBits->size()) HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg = triggerBits->accept(HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg_v);
    uint HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_v(trigNames.triggerIndex(("HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_v"+string(buffer)).c_str()));
    if(HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_v<triggerBits->size()) HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1 = triggerBits->accept(HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_v);
    uint HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1_v(trigNames.triggerIndex(("HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1_v"+string(buffer)).c_str()));
    if(HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1_v<triggerBits->size()) HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1 = triggerBits->accept(HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1_v);
    uint HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1_v(trigNames.triggerIndex(("HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1_v"+string(buffer)).c_str()));
    if(HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1_v<triggerBits->size()) HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1 = triggerBits->accept(HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1_v);
    uint HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_v(trigNames.triggerIndex(("HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_v"+string(buffer)).c_str()));
    if(HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_v<triggerBits->size()) HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1 = triggerBits->accept(HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_v);
    uint HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1_v(trigNames.triggerIndex(("HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1_v"+string(buffer)).c_str()));
    if(HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1_v<triggerBits->size()) HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1 = triggerBits->accept(HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1_v);
    uint HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1_v(trigNames.triggerIndex(("HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1_v"+string(buffer)).c_str()));
    if(HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1_v<triggerBits->size()) HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1 = triggerBits->accept(HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1_v);
    uint HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr_v(trigNames.triggerIndex(("HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr_v"+string(buffer)).c_str()));
    if(HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr_v<triggerBits->size()) HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr = triggerBits->accept(HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr_v);
    uint HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_v(trigNames.triggerIndex(("HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_v"+string(buffer)).c_str()));
    if(HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_v<triggerBits->size()) HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1 = triggerBits->accept(HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_v);
    uint HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100_v(trigNames.triggerIndex(("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100_v"+string(buffer)).c_str()));
    if(HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100_v<triggerBits->size()) HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100 = triggerBits->accept(HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100_v);
    uint HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90_v(trigNames.triggerIndex(("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90_v"+string(buffer)).c_str()));
    if(HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90_v<triggerBits->size()) HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90 = triggerBits->accept(HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90_v);
    uint HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_v(trigNames.triggerIndex(("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_v"+string(buffer)).c_str()));
    if(HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_v<triggerBits->size()) HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr = triggerBits->accept(HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_v);
    uint HLT_PFHT500_PFMET100_PFMHT100_IDTight_v(trigNames.triggerIndex(("HLT_PFHT500_PFMET100_PFMHT100_IDTight_v"+string(buffer)).c_str()));
    if(HLT_PFHT500_PFMET100_PFMHT100_IDTight_v<triggerBits->size()) HLT_PFHT500_PFMET100_PFMHT100_IDTight = triggerBits->accept(HLT_PFHT500_PFMET100_PFMHT100_IDTight_v);
    uint HLT_PFHT700_PFMET85_PFMHT85_IDTight_v(trigNames.triggerIndex(("HLT_PFHT700_PFMET85_PFMHT85_IDTight_v"+string(buffer)).c_str()));
    if(HLT_PFHT700_PFMET85_PFMHT85_IDTight_v<triggerBits->size()) HLT_PFHT700_PFMET85_PFMHT85_IDTight = triggerBits->accept(HLT_PFHT700_PFMET85_PFMHT85_IDTight_v);
    uint HLT_PFHT800_PFMET75_PFMHT75_IDTight_v(trigNames.triggerIndex(("HLT_PFHT800_PFMET75_PFMHT75_IDTight_v"+string(buffer)).c_str()));
    if(HLT_PFHT800_PFMET75_PFMHT75_IDTight_v<triggerBits->size()) HLT_PFHT800_PFMET75_PFMHT75_IDTight = triggerBits->accept(HLT_PFHT800_PFMET75_PFMHT75_IDTight_v);
    uint HLT_CaloJet500_NoJetID_v(trigNames.triggerIndex(("HLT_CaloJet500_NoJetID_v"+string(buffer)).c_str()));
    if(HLT_CaloJet500_NoJetID_v<triggerBits->size()) HLT_CaloJet500_NoJetID = triggerBits->accept(HLT_CaloJet500_NoJetID_v);
    uint HLT_PFHT1050_v(trigNames.triggerIndex(("HLT_PFHT1050_v"+string(buffer)).c_str()));
    if(HLT_PFHT1050_v<triggerBits->size()) HLT_PFHT1050 = triggerBits->accept(HLT_PFHT1050_v);
    uint HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v(trigNames.triggerIndex(("HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight"+string(buffer)).c_str()));
    if(HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v<triggerBits->size()) HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight = triggerBits->accept(HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v);
    uint HLT_PFMET120_PFMHT120_IDTight_v(trigNames.triggerIndex(("HLT_PFMET120_PFMHT120_IDTight_v"+string(buffer)).c_str()));
    if(HLT_PFMET120_PFMHT120_IDTight_v<triggerBits->size()) HLT_PFMET120_PFMHT120_IDTight = triggerBits->accept(HLT_PFMET120_PFMHT120_IDTight_v);
    uint HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v(trigNames.triggerIndex(("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v"+string(buffer)).c_str()));
    if(HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v<triggerBits->size()) HLT_PFMETNoMu120_PFMHTNoMu120_IDTight = triggerBits->accept(HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v);
    uint HLT_PFJet500_v(trigNames.triggerIndex(("HLT_PFJet500_v"+string(buffer)).c_str()));
    if(HLT_PFJet500_v<triggerBits->size()) HLT_PFJet500 = triggerBits->accept(HLT_PFJet500_v);
    uint HLT_AK8PFJet500_v(trigNames.triggerIndex(("HLT_AK8PFJet500_v"+string(buffer)).c_str()));
    if(HLT_AK8PFJet500_v<triggerBits->size()) HLT_AK8PFJet500 = triggerBits->accept(HLT_AK8PFJet500_v);
    uint HLT_Ele27_eta2p1_WPTight_Gsf_v(trigNames.triggerIndex(("HLT_Ele27_eta2p1_WPTight_Gsf_v"+string(buffer)).c_str()));
    if(HLT_Ele27_eta2p1_WPTight_Gsf_v<triggerBits->size()) HLT_Ele27_eta2p1_WPTight_Gsf = triggerBits->accept(HLT_Ele27_eta2p1_WPTight_Gsf_v);
    uint HLT_Ele27_WPTight_Gsf_v(trigNames.triggerIndex(("HLT_Ele27_WPTight_Gsf_v"+string(buffer)).c_str()));
    if(HLT_Ele27_WPTight_Gsf_v<triggerBits->size()) HLT_Ele27_WPTight_Gsf = triggerBits->accept(HLT_Ele27_WPTight_Gsf_v);
    uint HLT_Ele25_eta2p1_WPTight_Gsf_v(trigNames.triggerIndex(("HLT_Ele25_eta2p1_WPTight_Gsf_v"+string(buffer)).c_str()));
    if(HLT_Ele25_eta2p1_WPTight_Gsf_v<triggerBits->size()) HLT_Ele25_eta2p1_WPTight_Gsf = triggerBits->accept(HLT_Ele25_eta2p1_WPTight_Gsf_v);
    uint HLT_Ele115_CaloIdVT_GsfTrkIdT_v(trigNames.triggerIndex(("HLT_Ele115_CaloIdVT_GsfTrkIdT_v"+string(buffer)).c_str()));
    if(HLT_Ele115_CaloIdVT_GsfTrkIdT_v<triggerBits->size()) HLT_Ele115_CaloIdVT_GsfTrkIdT = triggerBits->accept(HLT_Ele115_CaloIdVT_GsfTrkIdT_v);
    uint HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v(trigNames.triggerIndex(("HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v"+string(buffer)).c_str()));
    if(HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v<triggerBits->size()) HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf = triggerBits->accept(HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v);
    uint HLT_DoubleEle33_CaloIdL_MW_v(trigNames.triggerIndex(("HLT_DoubleEle33_CaloIdL_MW_v"+string(buffer)).c_str()));
    if(HLT_DoubleEle33_CaloIdL_MW_v<triggerBits->size()) HLT_DoubleEle33_CaloIdL_MW = triggerBits->accept(HLT_DoubleEle33_CaloIdL_MW_v);
    uint HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v(trigNames.triggerIndex(("HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v"+string(buffer)).c_str()));
    if(HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v<triggerBits->size()) HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW = triggerBits->accept(HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v);
    uint HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v(trigNames.triggerIndex(("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"+string(buffer)).c_str()));
    if(HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v<triggerBits->size()) HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = triggerBits->accept(HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v);
    uint HLT_IsoMu22_v(trigNames.triggerIndex(("HLT_IsoMu22_v"+string(buffer)).c_str()));
    if(HLT_IsoMu22_v<triggerBits->size()) HLT_IsoMu22 = triggerBits->accept(HLT_IsoMu22_v);
    uint HLT_IsoTkMu22_v(trigNames.triggerIndex(("HLT_IsoTkMu22_v"+string(buffer)).c_str()));
    if(HLT_IsoTkMu22_v<triggerBits->size()) HLT_IsoTkMu22 = triggerBits->accept(HLT_IsoTkMu22_v);
    uint HLT_IsoMu24_v(trigNames.triggerIndex(("HLT_IsoMu24_v"+string(buffer)).c_str()));
    if(HLT_IsoMu24_v<triggerBits->size()) HLT_IsoMu24 = triggerBits->accept(HLT_IsoMu24_v);
    uint HLT_IsoTkMu24_v(trigNames.triggerIndex(("HLT_IsoTkMu24_v"+string(buffer)).c_str()));
    if(HLT_IsoTkMu24_v<triggerBits->size()) HLT_IsoTkMu24 = triggerBits->accept(HLT_IsoTkMu24_v);
    uint HLT_IsoMu22_eta2p1_v(trigNames.triggerIndex(("HLT_IsoMu22_eta2p1_v"+string(buffer)).c_str()));
    if(HLT_IsoMu22_eta2p1_v<triggerBits->size()) HLT_IsoMu22_eta2p1 = triggerBits->accept(HLT_IsoMu22_eta2p1_v);
    uint HLT_IsoTkMu22_eta2p1_v(trigNames.triggerIndex(("HLT_IsoTkMu22_eta2p1_v"+string(buffer)).c_str()));
    if(HLT_IsoTkMu22_eta2p1_v<triggerBits->size()) HLT_IsoTkMu22_eta2p1 = triggerBits->accept(HLT_IsoTkMu22_eta2p1_v);
    uint HLT_Mu50_v(trigNames.triggerIndex(("HLT_Mu50_v"+string(buffer)).c_str()));
    if(HLT_Mu50_v<triggerBits->size()) HLT_Mu50 = triggerBits->accept(HLT_Mu50_v);
    uint HLT_TkMu50_v(trigNames.triggerIndex(("HLT_TkMu50_v"+string(buffer)).c_str()));
    if(HLT_TkMu50_v<triggerBits->size()) HLT_TkMu50 = triggerBits->accept(HLT_TkMu50_v);
    uint HLT_DoubleMu33NoFiltersNoVtx_v(trigNames.triggerIndex(("HLT_DoubleMu33NoFiltersNoVtx_v"+string(buffer)).c_str()));
    if(HLT_DoubleMu33NoFiltersNoVtx_v<triggerBits->size()) HLT_DoubleMu33NoFiltersNoVtx = triggerBits->accept(HLT_DoubleMu33NoFiltersNoVtx_v);
    uint HLT_DoubleMu23NoFiltersNoVtxDisplaced_v(trigNames.triggerIndex(("HLT_DoubleMu23NoFiltersNoVtxDisplaced_v"+string(buffer)).c_str()));
    if(HLT_DoubleMu23NoFiltersNoVtxDisplaced_v<triggerBits->size()) HLT_DoubleMu23NoFiltersNoVtxDisplaced = triggerBits->accept(HLT_DoubleMu23NoFiltersNoVtxDisplaced_v);
    uint HLT_Mu30_TkMu11_v(trigNames.triggerIndex(("HLT_Mu30_TkMu11_v"+string(buffer)).c_str()));
    if(HLT_Mu30_TkMu11_v<triggerBits->size()) HLT_Mu30_TkMu11 = triggerBits->accept(HLT_Mu30_TkMu11_v);
    uint HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v(trigNames.triggerIndex(("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v"+string(buffer)).c_str()));
    if(HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v<triggerBits->size()) HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ = triggerBits->accept(HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v);
=======
  if(_reHLT || _is_data){
    //Trigget paths  
    edm::Handle<edm::TriggerResults> triggerBits;
    iEvent.getByLabel(triggerBits_, triggerBits);
    const edm::TriggerNames &trigNames = iEvent.triggerNames(*triggerBits);
    for(double tv=0.; tv<=_maxtriggerversion; tv++){ 
      char buffer[10]; sprintf(buffer,"%g",tv);
      uint HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v(trigNames.triggerIndex(("HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v"+string(buffer)).c_str()));
      if(HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v<triggerBits->size()) HLT_PFHT650_WideJetMJJ900DEtaJJ1p5 = triggerBits->accept(HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v);
      uint HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v(trigNames.triggerIndex(("HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v"+string(buffer)).c_str()));
      if(HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v<triggerBits->size()) HLT_PFHT650_WideJetMJJ950DEtaJJ1p5 = triggerBits->accept(HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v);
      uint HLT_PFHT800_v(trigNames.triggerIndex(("HLT_PFHT800_v"+string(buffer)).c_str()));
      if(HLT_PFHT800_v<triggerBits->size()) HLT_PFHT800 = triggerBits->accept(HLT_PFHT800_v);
      uint HLT_PFHT900_v(trigNames.triggerIndex(("HLT_PFHT900_v"+string(buffer)).c_str()));
      if(HLT_PFHT900_v<triggerBits->size()) HLT_PFHT900 = triggerBits->accept(HLT_PFHT900_v);
      uint HLT_PFJet450_v(trigNames.triggerIndex(("HLT_PFJet450_v"+string(buffer)).c_str()));
      if(HLT_PFJet450_v<triggerBits->size()) HLT_PFJet450 = triggerBits->accept(HLT_PFJet450_v);
      uint HLT_PFJet500_v(trigNames.triggerIndex(("HLT_PFJet500_v"+string(buffer)).c_str()));
      if(HLT_PFJet500_v<triggerBits->size()) HLT_PFJet500 = triggerBits->accept(HLT_PFJet500_v);
      uint HLT_AK8PFJet450_v(trigNames.triggerIndex(("HLT_AK8PFJet450_v"+string(buffer)).c_str()));
      if(HLT_AK8PFJet450_v<triggerBits->size()) HLT_AK8PFJet450 = triggerBits->accept(HLT_AK8PFJet450_v);
      uint HLT_AK8PFJet500_v(trigNames.triggerIndex(("HLT_AK8PFJet500_v"+string(buffer)).c_str()));
      if(HLT_AK8PFJet500_v<triggerBits->size()) HLT_AK8PFJet500 = triggerBits->accept(HLT_AK8PFJet500_v);
      uint HLT_AK8PFJet360_TrimMass30_v(trigNames.triggerIndex(("HLT_AK8PFJet360_TrimMass30_v"+string(buffer)).c_str()));
      if(HLT_AK8PFJet360_TrimMass30_v<triggerBits->size()) HLT_AK8PFJet360_TrimMass30 = triggerBits->accept(HLT_AK8PFJet360_TrimMass30_v);
      uint HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v(trigNames.triggerIndex(("HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v"+string(buffer)).c_str()));
      if(HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v<triggerBits->size()) HLT_AK8PFHT700_TrimR0p1PT0p03Mass50 = triggerBits->accept(HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v);
      //Electron
      uint HLT_Ele35_WPTight_Gsf_v(trigNames.triggerIndex(("HLT_Ele35_WPTight_Gsf_v"+string(buffer)).c_str()));
      if(HLT_Ele35_WPTight_Gsf_v<triggerBits->size()) HLT_Ele35_WPTight_Gsf = triggerBits->accept(HLT_Ele35_WPTight_Gsf_v);
      uint HLT_Ele32_WPTight_Gsf_v(trigNames.triggerIndex(("HLT_Ele32_WPTight_Gsf_v"+string(buffer)).c_str()));
      if(HLT_Ele32_WPTight_Gsf_v<triggerBits->size()) HLT_Ele32_WPTight_Gsf = triggerBits->accept(HLT_Ele32_WPTight_Gsf_v);
      uint HLT_Ele27_eta2p1_WPTight_Gsf_v(trigNames.triggerIndex(("HLT_Ele27_eta2p1_WPTight_Gsf_v"+string(buffer)).c_str()));
      if(HLT_Ele27_eta2p1_WPTight_Gsf_v<triggerBits->size()) HLT_Ele27_eta2p1_WPTight_Gsf = triggerBits->accept(HLT_Ele27_eta2p1_WPTight_Gsf_v);
      uint HLT_Ele27_WPTight_Gsf_v(trigNames.triggerIndex(("HLT_Ele27_WPTight_Gsf_v"+string(buffer)).c_str()));
      if(HLT_Ele27_WPTight_Gsf_v<triggerBits->size()) HLT_Ele27_WPTight_Gsf = triggerBits->accept(HLT_Ele27_WPTight_Gsf_v);
      uint HLT_Ele25_eta2p1_WPTight_Gsf_v(trigNames.triggerIndex(("HLT_Ele25_eta2p1_WPTight_Gsf_v"+string(buffer)).c_str()));
      if(HLT_Ele25_eta2p1_WPTight_Gsf_v<triggerBits->size()) HLT_Ele25_eta2p1_WPTight_Gsf = triggerBits->accept(HLT_Ele25_eta2p1_WPTight_Gsf_v);
      uint HLT_Ele115_CaloIdVT_GsfTrkIdT_v(trigNames.triggerIndex(("HLT_Ele115_CaloIdVT_GsfTrkIdT_v"+string(buffer)).c_str()));
      if(HLT_Ele115_CaloIdVT_GsfTrkIdT_v<triggerBits->size()) HLT_Ele115_CaloIdVT_GsfTrkIdT = triggerBits->accept(HLT_Ele115_CaloIdVT_GsfTrkIdT_v);
      uint HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v(trigNames.triggerIndex(("HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v"+string(buffer)).c_str()));
      if(HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v<triggerBits->size()) HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf = triggerBits->accept(HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v);
      uint HLT_DoubleEle33_CaloIdL_MW_v(trigNames.triggerIndex(("HLT_DoubleEle33_CaloIdL_MW_v"+string(buffer)).c_str()));
      if(HLT_DoubleEle33_CaloIdL_MW_v<triggerBits->size()) HLT_DoubleEle33_CaloIdL_MW = triggerBits->accept(HLT_DoubleEle33_CaloIdL_MW_v);
      uint HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v(trigNames.triggerIndex(("HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v"+string(buffer)).c_str()));
      if(HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v<triggerBits->size()) HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW = triggerBits->accept(HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v);
      uint HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v(trigNames.triggerIndex(("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"+string(buffer)).c_str()));
      if(HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v<triggerBits->size()) HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = triggerBits->accept(HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v);
      uint HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v(trigNames.triggerIndex(("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v"+string(buffer)).c_str()));
      if(HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v<triggerBits->size()) HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL = triggerBits->accept(HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v);
      //Muon
      uint HLT_IsoMu27_v(trigNames.triggerIndex(("HLT_IsoMu27_v"+string(buffer)).c_str()));
      if(HLT_IsoMu27_v<triggerBits->size()) HLT_IsoMu27 = triggerBits->accept(HLT_IsoMu27_v);
      uint HLT_IsoMu22_v(trigNames.triggerIndex(("HLT_IsoMu22_v"+string(buffer)).c_str()));
      if(HLT_IsoMu22_v<triggerBits->size()) HLT_IsoMu22 = triggerBits->accept(HLT_IsoMu22_v);
      uint HLT_IsoTkMu22_v(trigNames.triggerIndex(("HLT_IsoTkMu22_v"+string(buffer)).c_str()));
      if(HLT_IsoTkMu22_v<triggerBits->size()) HLT_IsoTkMu22 = triggerBits->accept(HLT_IsoTkMu22_v);
      uint HLT_IsoMu24_v(trigNames.triggerIndex(("HLT_IsoMu24_v"+string(buffer)).c_str()));
      if(HLT_IsoMu24_v<triggerBits->size()) HLT_IsoMu24 = triggerBits->accept(HLT_IsoMu24_v);
      uint HLT_IsoTkMu24_v(trigNames.triggerIndex(("HLT_IsoTkMu24_v"+string(buffer)).c_str()));
      if(HLT_IsoTkMu24_v<triggerBits->size()) HLT_IsoTkMu24 = triggerBits->accept(HLT_IsoTkMu24_v);
      uint HLT_IsoMu22_eta2p1_v(trigNames.triggerIndex(("HLT_IsoMu22_eta2p1_v"+string(buffer)).c_str()));
      if(HLT_IsoMu22_eta2p1_v<triggerBits->size()) HLT_IsoMu22_eta2p1 = triggerBits->accept(HLT_IsoMu22_eta2p1_v);
      uint HLT_IsoTkMu22_eta2p1_v(trigNames.triggerIndex(("HLT_IsoTkMu22_eta2p1_v"+string(buffer)).c_str()));
      if(HLT_IsoTkMu22_eta2p1_v<triggerBits->size()) HLT_IsoTkMu22_eta2p1 = triggerBits->accept(HLT_IsoTkMu22_eta2p1_v);
      uint HLT_Mu50_v(trigNames.triggerIndex(("HLT_Mu50_v"+string(buffer)).c_str()));
      if(HLT_Mu50_v<triggerBits->size()) HLT_Mu50 = triggerBits->accept(HLT_Mu50_v);
      uint HLT_TkMu50_v(trigNames.triggerIndex(("HLT_TkMu50_v"+string(buffer)).c_str()));
      if(HLT_TkMu50_v<triggerBits->size()) HLT_TkMu50 = triggerBits->accept(HLT_TkMu50_v);
      uint HLT_DoubleMu33NoFiltersNoVtx_v(trigNames.triggerIndex(("HLT_DoubleMu33NoFiltersNoVtx_v"+string(buffer)).c_str()));
      if(HLT_DoubleMu33NoFiltersNoVtx_v<triggerBits->size()) HLT_DoubleMu33NoFiltersNoVtx = triggerBits->accept(HLT_DoubleMu33NoFiltersNoVtx_v);
      uint HLT_DoubleMu23NoFiltersNoVtxDisplaced_v(trigNames.triggerIndex(("HLT_DoubleMu23NoFiltersNoVtxDisplaced_v"+string(buffer)).c_str()));
      if(HLT_DoubleMu23NoFiltersNoVtxDisplaced_v<triggerBits->size()) HLT_DoubleMu23NoFiltersNoVtxDisplaced = triggerBits->accept(HLT_DoubleMu23NoFiltersNoVtxDisplaced_v);
      uint HLT_Mu30_TkMu11_v(trigNames.triggerIndex(("HLT_Mu30_TkMu11_v"+string(buffer)).c_str()));
      if(HLT_Mu30_TkMu11_v<triggerBits->size()) HLT_Mu30_TkMu11 = triggerBits->accept(HLT_Mu30_TkMu11_v);
      uint HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v(trigNames.triggerIndex(("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v"+string(buffer)).c_str()));
      if(HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v<triggerBits->size()) HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL = triggerBits->accept(HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v);
      uint HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v(trigNames.triggerIndex(("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v"+string(buffer)).c_str()));
      if(HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v<triggerBits->size()) HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ = triggerBits->accept(HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v);
      uint HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v(trigNames.triggerIndex(("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"+string(buffer)).c_str()));
      if(HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v<triggerBits->size()) HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8 = triggerBits->accept(HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v);
      uint HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v(trigNames.triggerIndex(("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v"+string(buffer)).c_str()));
      if(HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v<triggerBits->size()) HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL = triggerBits->accept(HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v);
      uint HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v(trigNames.triggerIndex(("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v"+string(buffer)).c_str()));
      if(HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v<triggerBits->size()) HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ = triggerBits->accept(HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v);
      uint HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v(trigNames.triggerIndex(("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v"+string(buffer)).c_str()));
      if(HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v<triggerBits->size()) HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL = triggerBits->accept(HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v);
      uint HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v(trigNames.triggerIndex(("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"+string(buffer)).c_str()));
      if(HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v<triggerBits->size()) HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = triggerBits->accept(HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v);
      uint HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v(trigNames.triggerIndex(("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v"+string(buffer)).c_str()));
      if(HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v<triggerBits->size()) HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ = triggerBits->accept(HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v);
      uint HLT_TripleMu_12_10_5_v(trigNames.triggerIndex(("HLT_TripleMu_12_10_5_v"+string(buffer)).c_str()));
      if(HLT_TripleMu_12_10_5_v<triggerBits->size()) HLT_TripleMu_12_10_5 = triggerBits->accept(HLT_TripleMu_12_10_5_v);
      uint HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_v(trigNames.triggerIndex(("HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_v"+string(buffer)).c_str()));
      if(HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_v<triggerBits->size()) HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ = triggerBits->accept(HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_v);
      uint HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v(trigNames.triggerIndex(("HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v"+string(buffer)).c_str()));
      if(HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v<triggerBits->size()) HLT_Mu8_DiEle12_CaloIdL_TrackIdL = triggerBits->accept(HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v);
      uint HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v(trigNames.triggerIndex(("HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v"+string(buffer)).c_str()));
      if(HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v<triggerBits->size()) HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL = triggerBits->accept(HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v);
    }
  } else {
    HLT_PFHT650_WideJetMJJ900DEtaJJ1p5 = 1;
    HLT_PFHT650_WideJetMJJ950DEtaJJ1p5 = 1;
    HLT_PFHT800 = 1;
    HLT_PFHT900 = 1;
    HLT_PFJet450 = 1;
    HLT_PFJet500 = 1;
    HLT_AK8PFJet450 = 1;
    HLT_AK8PFJet500 = 1;
    HLT_AK8PFJet360_TrimMass30 = 1;
    HLT_AK8PFHT700_TrimR0p1PT0p03Mass50 = 1;
    HLT_Ele27_eta2p1_WPTight_Gsf = 1;
    HLT_Ele27_WPTight_Gsf = 1;
    HLT_Ele25_eta2p1_WPTight_Gsf = 1;
    HLT_Ele115_CaloIdVT_GsfTrkIdT = 1;
    HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf = 1;
    HLT_DoubleEle33_CaloIdL_MW = 1;
    HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW = 1;
    HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = 1;
    HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL = 1;
    HLT_IsoMu22 = 1;
    HLT_IsoTkMu22 = 1;
    HLT_IsoMu24 = 1;
    HLT_IsoTkMu24 = 1;
    HLT_IsoMu22_eta2p1 = 1;
    HLT_IsoTkMu22_eta2p1 = 1;
    HLT_Mu50 = 1;
    HLT_TkMu50 = 1;
    HLT_DoubleMu33NoFiltersNoVtx = 1;
    HLT_DoubleMu23NoFiltersNoVtxDisplaced = 1;
    HLT_Mu30_TkMu11 = 1;
    HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ = 1;
    HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8 = 1;
    HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL = 1;
    HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ = 1;
    HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL = 1;
    HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = 1;
    HLT_Ele32_WPTight_Gsf = 1;
    HLT_Ele35_WPTight_Gsf = 1;
    HLT_IsoMu27 = 1;
    HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL = 1;
    HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ = 1;
    HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL = 1;
    HLT_Mu8_DiEle12_CaloIdL_TrackIdL = 1;
    HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ = 1;
    HLT_TripleMu_12_10_5 = 1;
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  }
}

void TriggerSelector::SetBranches(){
  if(debug_)    std::cout<<"setting branches: calling AddBranch of baseTree"<<std::endl;
<<<<<<< HEAD
  AddBranch(&HLT_PFMET120_PFMHT120_IDTight             ,"HLT_PFMET120_PFMHT120_IDTight");
  AddBranch(&HLT_PFMETNoMu120_PFMHTNoMu120_IDTight     ,"HLT_PFMETNoMu120_PFMHTNoMu120_IDTight");
  AddBranch(&HLT_Mu50				      ,"HLT_Mu50");
  AddBranch(&HLT_TkMu50				      ,"HLT_TkMu50");
  AddBranch(&HLT_DoubleEle33_CaloIdL_MW		      ,"HLT_DoubleEle33_CaloIdL_MW");
  if(!_reduced){
    AddBranch(&HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg           ,"HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg");
    AddBranch(&HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg            ,"HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg");
    AddBranch(&HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg                    ,"HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg");
    AddBranch(&HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1  ,"HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1");
    AddBranch(&HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1 ,"HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1");
    AddBranch(&HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1  ,"HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1");
    AddBranch(&HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1            ,"HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1");
    AddBranch(&HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1           ,"HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1");
    AddBranch(&HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1            ,"HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1");
    AddBranch(&HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr       ,"HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr");
    AddBranch(&HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1           ,"HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1");
    AddBranch(&HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100                 ,"HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100");
    AddBranch(&HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90                  ,"HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90");
    AddBranch(&HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr                        ,"HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr");
    AddBranch(&HLT_PFHT500_PFMET100_PFMHT100_IDTight     ,"HLT_PFHT500_PFMET100_PFMHT100_IDTight");
    AddBranch(&HLT_PFHT700_PFMET85_PFMHT85_IDTight       ,"HLT_PFHT700_PFMET85_PFMHT85_IDTight");
    AddBranch(&HLT_PFHT800_PFMET75_PFMHT75_IDTight       ,"HLT_PFHT800_PFMET75_PFMHT75_IDTight");
    AddBranch(&HLT_CaloJet500_NoJetID                    ,"HLT_CaloJet500_NoJetID");
    AddBranch(&HLT_PFHT1050                              ,"HLT_PFHT1050");
    AddBranch(&HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight   ,"HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight");
    AddBranch(&HLT_PFJet500               ,"HLT_PFJet500");
    AddBranch(&HLT_AK8PFJet500      ,"HLT_AK8PFJet500");
    AddBranch(&HLT_Ele27_eta2p1_WPTight_Gsf             ,"HLT_Ele27_eta2p1_WPTight_Gsf");
    AddBranch(&HLT_Ele27_WPTight_Gsf		      ,"HLT_Ele27_WPTight_Gsf");
    AddBranch(&HLT_Ele25_eta2p1_WPTight_Gsf	      ,"HLT_Ele25_eta2p1_WPTight_Gsf");
    AddBranch(&HLT_Ele115_CaloIdVT_GsfTrkIdT	      ,"HLT_Ele115_CaloIdVT_GsfTrkIdT");
    AddBranch(&HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf    ,"HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf");
    AddBranch(&HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW    ,"HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW");
    AddBranch(&HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ ,"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ");
    AddBranch(&HLT_IsoMu22			,"HLT_IsoMu22");
    AddBranch(&HLT_IsoTkMu22		    ,"HLT_IsoTkMu22");
    AddBranch(&HLT_IsoMu24			,"HLT_IsoMu24");
    AddBranch(&HLT_IsoTkMu24		          ,"HLT_IsoTkMu24");
    AddBranch(&HLT_IsoMu22_eta2p1			  ,"HLT_IsoMu22_eta2p1");
    AddBranch(&HLT_IsoTkMu22_eta2p1		  ,"HLT_IsoTkMu22_eta2p1");
    AddBranch(&HLT_DoubleMu33NoFiltersNoVtx	      ,"HLT_DoubleMu33NoFiltersNoVtx");
    AddBranch(&HLT_DoubleMu23NoFiltersNoVtxDisplaced    ,"HLT_DoubleMu23NoFiltersNoVtxDisplaced");
    AddBranch(&HLT_Mu30_TkMu11			      ,"HLT_Mu30_TkMu11");
    AddBranch(&HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ      ,"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ");
  }
=======
  AddBranch(&HLT_PFHT650_WideJetMJJ900DEtaJJ1p5       ,"HLT_PFHT650_WideJetMJJ900DEtaJJ1p5");
  AddBranch(&HLT_PFHT650_WideJetMJJ950DEtaJJ1p5       ,"HLT_PFHT650_WideJetMJJ950DEtaJJ1p5");
  AddBranch(&HLT_PFHT800                              ,"HLT_PFHT800");
  AddBranch(&HLT_PFHT900                              ,"HLT_PFHT900");
  AddBranch(&HLT_PFJet450                             ,"HLT_PFJet450");
  AddBranch(&HLT_PFJet500                             ,"HLT_PFJet500");
  AddBranch(&HLT_AK8PFJet450                          ,"HLT_AK8PFJet450");
  AddBranch(&HLT_AK8PFJet500                          ,"HLT_AK8PFJet500");
  AddBranch(&HLT_AK8PFJet360_TrimMass30               ,"HLT_AK8PFJet360_TrimMass30");
  AddBranch(&HLT_AK8PFHT700_TrimR0p1PT0p03Mass50      ,"HLT_AK8PFHT700_TrimR0p1PT0p03Mass50");
  AddBranch(&HLT_Ele27_eta2p1_WPTight_Gsf             ,"HLT_Ele27_eta2p1_WPTight_Gsf");
  AddBranch(&HLT_Ele27_WPTight_Gsf		      ,"HLT_Ele27_WPTight_Gsf");
  AddBranch(&HLT_Ele25_eta2p1_WPTight_Gsf	      ,"HLT_Ele25_eta2p1_WPTight_Gsf");
  AddBranch(&HLT_Ele115_CaloIdVT_GsfTrkIdT	      ,"HLT_Ele115_CaloIdVT_GsfTrkIdT");
  AddBranch(&HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf    ,"HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf");
  AddBranch(&HLT_DoubleEle33_CaloIdL_MW		      ,"HLT_DoubleEle33_CaloIdL_MW");
  AddBranch(&HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW    ,"HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW");
  AddBranch(&HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ,"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ");
  AddBranch(&HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL,"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL");
  AddBranch(&HLT_IsoMu22			      ,"HLT_IsoMu22");
  AddBranch(&HLT_IsoTkMu22		              ,"HLT_IsoTkMu22");
  AddBranch(&HLT_IsoMu24			      ,"HLT_IsoMu24");
  AddBranch(&HLT_IsoTkMu24		              ,"HLT_IsoTkMu24");
  AddBranch(&HLT_IsoMu22_eta2p1			      ,"HLT_IsoMu22_eta2p1");
  AddBranch(&HLT_IsoTkMu22_eta2p1		      ,"HLT_IsoTkMu22_eta2p1");
  AddBranch(&HLT_Mu50				      ,"HLT_Mu50");
  AddBranch(&HLT_TkMu50				      ,"HLT_TkMu50");
  AddBranch(&HLT_DoubleMu33NoFiltersNoVtx	      ,"HLT_DoubleMu33NoFiltersNoVtx");
  AddBranch(&HLT_DoubleMu23NoFiltersNoVtxDisplaced    ,"HLT_DoubleMu23NoFiltersNoVtxDisplaced");
  AddBranch(&HLT_Mu30_TkMu11			      ,"HLT_Mu30_TkMu11");
  AddBranch(&HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ      ,"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ");
  AddBranch(&HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8      ,"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8");
  AddBranch(&HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL      ,"HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL");
  AddBranch(&HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ      ,"HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ");
  AddBranch(&HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL      ,"HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL");
  AddBranch(&HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ      ,"HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ");
  AddBranch(&HLT_Ele32_WPTight_Gsf				      ,"HLT_Ele32_WPTight_Gsf");
  AddBranch(&HLT_Ele35_WPTight_Gsf				      ,"HLT_Ele35_WPTight_Gsf");
  AddBranch(&HLT_IsoMu27				      ,"HLT_IsoMu27");
  AddBranch(&HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL				      ,"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL");
  AddBranch(&HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ				      ,"HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ");
  AddBranch(&HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL				      ,"HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL");
  AddBranch(&HLT_Mu8_DiEle12_CaloIdL_TrackIdL				      ,"HLT_Mu8_DiEle12_CaloIdL_TrackIdL");
  AddBranch(&HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ				      ,"HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ");
  AddBranch(&HLT_TripleMu_12_10_5				      ,"HLT_TripleMu_12_10_5");
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  if(debug_)    std::cout<<"set branches"<<std::endl;
}

void TriggerSelector::Clear(){
<<<<<<< HEAD
  HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg = -9999;
  HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg = -9999;
  HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg = -9999;
  HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1 = -9999;
  HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1 = -9999;
  HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1 = -9999;
  HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1 = -9999;
  HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1 = -9999;
  HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1 = -9999;
  HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr = -9999;
  HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1 = -9999;
  HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100 = -9999;
  HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90 = -9999;
  HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr = -9999;
  HLT_PFHT500_PFMET100_PFMHT100_IDTight = -9999;
  HLT_PFHT700_PFMET85_PFMHT85_IDTight = -9999;
  HLT_PFHT800_PFMET75_PFMHT75_IDTight = -9999;
  HLT_CaloJet500_NoJetID = -9999;
  HLT_PFHT1050 = -9999;
  HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight = -9999;
  HLT_PFMET120_PFMHT120_IDTight = -9999;
  HLT_PFMETNoMu120_PFMHTNoMu120_IDTight = -9999;
  HLT_PFJet500 = -9999;
  HLT_AK8PFJet500 = -9999;
=======
  HLT_PFHT650_WideJetMJJ900DEtaJJ1p5 = -9999;
  HLT_PFHT650_WideJetMJJ950DEtaJJ1p5 = -9999;
  HLT_PFHT800 = -9999;
  HLT_PFHT900 = -9999;
  HLT_PFJet450 = -9999;
  HLT_PFJet500 = -9999;
  HLT_AK8PFJet450 = -9999;
  HLT_AK8PFJet500 = -9999;
  HLT_AK8PFJet360_TrimMass30 = -9999;
  HLT_AK8PFHT700_TrimR0p1PT0p03Mass50 = -9999;
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  HLT_Ele27_eta2p1_WPTight_Gsf = -9999;
  HLT_Ele27_WPTight_Gsf = -9999;
  HLT_Ele25_eta2p1_WPTight_Gsf = -9999;
  HLT_Ele115_CaloIdVT_GsfTrkIdT = -9999;
  HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf = -9999;
  HLT_DoubleEle33_CaloIdL_MW = -9999;
  HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW = -9999;
  HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = -9999;
<<<<<<< HEAD
=======
  HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL = -9999;
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  HLT_IsoMu22 = -9999;
  HLT_IsoTkMu22 = -9999;
  HLT_IsoMu24 = -9999;
  HLT_IsoTkMu24 = -9999;
  HLT_IsoMu22_eta2p1 = -9999;
  HLT_IsoTkMu22_eta2p1 = -9999;
  HLT_Mu50 = -9999;
  HLT_TkMu50 = -9999;
  HLT_DoubleMu33NoFiltersNoVtx = -9999;
  HLT_DoubleMu23NoFiltersNoVtxDisplaced = -9999;
  HLT_Mu30_TkMu11 = -9999;
  HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ = -9999;
<<<<<<< HEAD

=======
  HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8 = -9999;
  HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL = -9999;
  HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ = -9999;
  HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL = -9999;
  HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = -9999;
  HLT_Ele32_WPTight_Gsf = -9999;
  HLT_Ele35_WPTight_Gsf = -9999;
  HLT_IsoMu27 = -9999;
  HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL = -9999;
  HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ = -9999;
  HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL = -9999;
  HLT_Mu8_DiEle12_CaloIdL_TrackIdL = -9999;
  HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ = -9999;
  HLT_TripleMu_12_10_5 = -9999;
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
}

void TriggerSelector::startTrigger(edm::EventSetup const& iSetup, edm::Run const & iRun){
  bool changed(true);
<<<<<<< HEAD
=======
  //if(_is_data) hltConfig_.init(iRun,iSetup,"HLT",changed);
  //else         hltConfig_.init(iRun,iSetup,"HLT2",changed);
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  hltConfig_.init(iRun,iSetup,"HLT",changed);
}

#include "BSMFramework/BSM3G_TNT_Maker/interface/BoostedJetSelector.h"
BoostedJetSelector::BoostedJetSelector(std::string name, TTree* tree, bool debug, const pset& iConfig, edm::ConsumesCollector && ic):
  baseTree(name,tree,debug)
{
  vtx_h_        = ic.consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vertices"));
  fatjets_      = ic.consumes<pat::JetCollection >(iConfig.getParameter<edm::InputTag>("fatjets"));
  rhopogHandle_ = ic.consumes<double>(edm::InputTag("fixedGridRhoFastjetAll"));
  rhoJERHandle_ = ic.consumes<double>(edm::InputTag("fixedGridRhoAll"));
  jecPayloadNamesAK8PFchsMC1_   = iConfig.getParameter<edm::FileInPath>("jecPayloadNamesAK8PFchsMC1");
  jecPayloadNamesAK8PFchsMC2_   = iConfig.getParameter<edm::FileInPath>("jecPayloadNamesAK8PFchsMC2");
  jecPayloadNamesAK8PFchsMC3_   = iConfig.getParameter<edm::FileInPath>("jecPayloadNamesAK8PFchsMC3");
  jecPayloadNamesAK8PFchsMCUnc_ = iConfig.getParameter<edm::FileInPath>("jecPayloadNamesAK8PFchsMCUnc");
  jecPayloadNamesAK8PFchsDATA1_   = iConfig.getParameter<edm::FileInPath>("jecPayloadNamesAK8PFchsDATA1");
  jecPayloadNamesAK8PFchsDATA2_   = iConfig.getParameter<edm::FileInPath>("jecPayloadNamesAK8PFchsDATA2");
  jecPayloadNamesAK8PFchsDATA3_   = iConfig.getParameter<edm::FileInPath>("jecPayloadNamesAK8PFchsDATA3");
  jecPayloadNamesAK8PFchsDATA4_   = iConfig.getParameter<edm::FileInPath>("jecPayloadNamesAK8PFchsDATA4");
  jecPayloadNamesAK8PFchsDATAUnc_ = iConfig.getParameter<edm::FileInPath>("jecPayloadNamesAK8PFchsDATAUnc");
  jerAK8PFchs_     = iConfig.getParameter<edm::FileInPath>("jerAK8PFchs").fullPath();
  jerAK8PFchsSF_   = iConfig.getParameter<edm::FileInPath>("jerAK8PFchsSF").fullPath();
  jerAK8PFPuppi_   = iConfig.getParameter<edm::FileInPath>("jerAK8PFPuppi").fullPath();
  jerAK8PFPuppiSF_ = iConfig.getParameter<edm::FileInPath>("jerAK8PFPuppiSF").fullPath();
  _is_data = iConfig.getParameter<bool>("is_data");
<<<<<<< HEAD
  _reduced = iConfig.getParameter<bool>("reduced");
  _year  = iConfig.getParameter<int>("year");
=======
  _MC2016   = iConfig.getParameter<bool>("MC2016");
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  PuppiWeightFilePath_ = iConfig.getParameter<edm::FileInPath>("PuppiWeightFilePath");
  const char *filePath = PuppiWeightFilePath_.fullPath().c_str();
  PuppiWeightFile = new TFile (filePath,"READ");
  puppisd_corrGEN      = (TF1*)PuppiWeightFile->Get("puppiJECcorr_gen");
  puppisd_corrRECO_cen = (TF1*)PuppiWeightFile->Get("puppiJECcorr_reco_0eta1v3");
  puppisd_corrRECO_for = (TF1*)PuppiWeightFile->Get("puppiJECcorr_reco_1v3eta2v5");
  JECInitialization();
  SetBranches();
}
BoostedJetSelector::~BoostedJetSelector(){
  delete tree_;
}
void BoostedJetSelector::Fill(const edm::Event& iEvent){
  Clear();
  /////
  //   Recall collections
  /////  
  edm::Handle<reco::VertexCollection> vertices;
  iEvent.getByToken(vtx_h_, vertices);                                        
  edm::Handle<pat::JetCollection> fatjets;                                       
  iEvent.getByToken(fatjets_, fatjets); 
  edm::Handle<double> rhoHandle;
  iEvent.getByToken(rhopogHandle_,rhoHandle);
  double rho = *rhoHandle;
  edm::Handle<double> rhoJERHandle;
  iEvent.getByToken(rhoJERHandle_,rhoJERHandle);
  double rhoJER = *rhoJERHandle;
  /////
  //   Get fatjet information
  /////  
  for(const pat::Jet &j : *fatjets){ 
<<<<<<< HEAD
    if (j.pt() <= 170.) continue;
=======
    if (j.pt() < 170.) continue;
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
    //Kinematic
    BoostedJet_pt.push_back(j.pt());         
    BoostedJet_eta.push_back(j.eta());       
    BoostedJet_phi.push_back(j.phi());       
    BoostedJet_energy.push_back(j.energy());
    BoostedJet_mass.push_back(j.mass()); 
    BoostedJet_Uncorr_pt.push_back(j.correctedJet("Uncorrected").pt());    
    //ID
    BoostedJet_pfJetProbabilityBJetTags.push_back(j.bDiscriminator("pfJetProbabilityBJetTags"));              
    BoostedJet_pfCombinedMVAV2BJetTags.push_back(j.bDiscriminator("pfCombinedMVAV2BJetTags"));              
    BoostedJet_pfCombinedInclusiveSecondaryVertexV2BJetTags.push_back(j.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags"));              
    BoostedJet_pfCombinedCvsLJetTags.push_back(j.bDiscriminator("pfCombinedCvsLJetTags"));
    BoostedJet_pfCombinedCvsBJetTags.push_back(j.bDiscriminator("pfCombinedCvsBJetTags"));
    //Energy related variables
    BoostedJet_neutralHadEnergyFraction.push_back(j.neutralHadronEnergyFraction());                               
<<<<<<< HEAD
    BoostedJet_neutralEmEnergyFraction.push_back(j.neutralEmEnergyFraction());                                   
=======
    BoostedJet_neutralEmEmEnergyFraction.push_back(j.neutralEmEnergyFraction());                                   
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
    BoostedJet_chargedHadronEnergyFraction.push_back(j.chargedHadronEnergyFraction());                               
    BoostedJet_chargedEmEnergyFraction.push_back(j.chargedEmEnergyFraction());                              
    BoostedJet_muonEnergyFraction.push_back(j.muonEnergyFraction());                                  
    BoostedJet_numberOfConstituents.push_back(j.chargedMultiplicity() + j.neutralMultiplicity());                                  
    BoostedJet_chargedMultiplicity.push_back(j.chargedMultiplicity());
    BoostedJet_electronEnergy.push_back(j.electronEnergy());                               
    BoostedJet_photonEnergy.push_back(j.photonEnergy());
    //Boosted jet prop
<<<<<<< HEAD
    BoostedJet_tau1.push_back(j.userFloat("ak8PFJetsCHSValueMap:NjettinessAK8CHSTau1"));    //
    BoostedJet_tau2.push_back(j.userFloat("ak8PFJetsCHSValueMap:NjettinessAK8CHSTau2"));    //  Access the n-subjettiness variables
    BoostedJet_tau3.push_back(j.userFloat("ak8PFJetsCHSValueMap:NjettinessAK8CHSTau3"));    // 
    BoostedJet_softdrop_mass.push_back(j.userFloat("ak8PFJetsCHSValueMap:ak8PFJetsCHSSoftDropMass")); // access to soft drop mass
    BoostedJet_pruned_mass.push_back(j.userFloat("ak8PFJetsCHSValueMap:ak8PFJetsCHSPrunedMass"));     // access to pruned mass
=======
    if(!_MC2016){
      BoostedJet_tau1.push_back(j.userFloat("ak8PFJetsCHSValueMap:NjettinessAK8CHSTau1"));    //
      BoostedJet_tau2.push_back(j.userFloat("ak8PFJetsCHSValueMap:NjettinessAK8CHSTau2"));    //  Access the n-subjettiness variables
      BoostedJet_tau3.push_back(j.userFloat("ak8PFJetsCHSValueMap:NjettinessAK8CHSTau3"));    // 
      BoostedJet_softdrop_mass.push_back(j.userFloat("ak8PFJetsCHSValueMap:ak8PFJetsCHSSoftDropMass")); // access to soft drop mass
      //BoostedJet_trimmed_mass.push_back(j.userFloat("ak8PFJetsCHSTrimmedMass"));   // access to trimmed mass
      BoostedJet_pruned_mass.push_back(j.userFloat("ak8PFJetsCHSValueMap:ak8PFJetsCHSPrunedMass"));     // access to pruned mass
      //BoostedJet_filtered_mass.push_back(j.userFloat("ak8PFJetsCHSFilteredMass")); // access to filtered mass
    } else {
      BoostedJet_tau1.push_back(j.userFloat("NjettinessAK8:tau1"));    //
      BoostedJet_tau2.push_back(j.userFloat("NjettinessAK8:tau2"));    //  Access the n-subjettiness variables
      BoostedJet_tau3.push_back(j.userFloat("NjettinessAK8:tau3"));    // 
      BoostedJet_softdrop_mass.push_back(j.userFloat("ak8PFJetsCHSSoftDropMass")); // access to soft drop mass
      BoostedJet_pruned_mass.push_back(j.userFloat("ak8PFJetsCHSPrunedMass"));     // access to pruned mass 
    }
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
    //Jet Energy Corrections and Uncertainties
    double corrAK8PFchs     = 1;
    double corrUpAK8PFchs   = 1;
    double corrDownAK8PFchs = 1;
    reco::Candidate::LorentzVector uncorrJetAK8PFchs = j.correctedP4(0);
    if(!_is_data){
      jecAK8PFchsMC_->setJetEta( uncorrJetAK8PFchs.eta()    );
      jecAK8PFchsMC_->setJetPt ( uncorrJetAK8PFchs.pt()     );
      jecAK8PFchsMC_->setJetE  ( uncorrJetAK8PFchs.energy() );
      jecAK8PFchsMC_->setRho	( rho  );
      jecAK8PFchsMC_->setNPV	( vertices->size()  );
      jecAK8PFchsMC_->setJetA  ( j.jetArea()	     );
      corrAK8PFchs = jecAK8PFchsMC_->getCorrection();
      jecAK8PFchsMCUnc_->setJetEta( uncorrJetAK8PFchs.eta() );
      jecAK8PFchsMCUnc_->setJetPt( corrAK8PFchs * uncorrJetAK8PFchs.pt() );
      corrUpAK8PFchs = corrAK8PFchs * (1 + fabs(jecAK8PFchsMCUnc_->getUncertainty(1)));
      jecAK8PFchsMCUnc_->setJetEta( uncorrJetAK8PFchs.eta() );
      jecAK8PFchsMCUnc_->setJetPt( corrAK8PFchs * uncorrJetAK8PFchs.pt() );
      corrDownAK8PFchs = corrAK8PFchs * ( 1 - fabs(jecAK8PFchsMCUnc_->getUncertainty(-1)) );
    } else {
      jecAK8PFchsDATA_->setJetEta( uncorrJetAK8PFchs.eta()    );
      jecAK8PFchsDATA_->setJetPt ( uncorrJetAK8PFchs.pt()     );
      jecAK8PFchsDATA_->setJetE  ( uncorrJetAK8PFchs.energy() );
      jecAK8PFchsDATA_->setRho	( rho  );
      jecAK8PFchsDATA_->setNPV	( vertices->size()  );
      jecAK8PFchsDATA_->setJetA  ( j.jetArea()	     );
      corrAK8PFchs = jecAK8PFchsDATA_->getCorrection();
      jecAK8PFchsDATAUnc_->setJetEta( uncorrJetAK8PFchs.eta() );
      jecAK8PFchsDATAUnc_->setJetPt( corrAK8PFchs * uncorrJetAK8PFchs.pt() );
      corrUpAK8PFchs = corrAK8PFchs * (1 + fabs(jecAK8PFchsDATAUnc_->getUncertainty(1)));
      jecAK8PFchsDATAUnc_->setJetEta( uncorrJetAK8PFchs.eta() );
      jecAK8PFchsDATAUnc_->setJetPt( corrAK8PFchs * uncorrJetAK8PFchs.pt() );
      corrDownAK8PFchs = corrAK8PFchs * ( 1 - fabs(jecAK8PFchsDATAUnc_->getUncertainty(-1)) );
    }
    BoostedJet_JesSF.push_back(corrAK8PFchs);
    BoostedJet_JesSFup.push_back(corrUpAK8PFchs);
    BoostedJet_JesSFdown.push_back(corrDownAK8PFchs);
    //JER scale factor and uncertainties
    float JERScaleFactor     = 1; 
    float JERScaleFactorUP   = 1;
    float JERScaleFactorDOWN = 1;
    if(!_is_data) GetJER(j, corrAK8PFchs, rhoJER, true, JERScaleFactor, JERScaleFactorUP, JERScaleFactorDOWN);
    BoostedJet_JerSF.push_back(JERScaleFactor);
    BoostedJet_JerSFup.push_back(JERScaleFactorUP);
    BoostedJet_JerSFdown.push_back(JERScaleFactorDOWN);
    //PUPPI Softdrop
<<<<<<< HEAD
    BoostedJet_puppi_softdrop_mass.push_back(j.userFloat("ak8PFJetsPuppiSoftDropMass"));
    BoostedJet_puppi_tau1.push_back(j.userFloat("NjettinessAK8Puppi:tau1"));
    BoostedJet_puppi_tau2.push_back(j.userFloat("NjettinessAK8Puppi:tau2"));
    BoostedJet_puppi_tau3.push_back(j.userFloat("NjettinessAK8Puppi:tau3"));
    BoostedJet_puppi_pt.push_back(-99);//j.userFloat("ak8PFJetsPuppiValueMap:pt"));
    BoostedJet_puppi_eta.push_back(-99);//j.userFloat("ak8PFJetsPuppiValueMap:eta"));
    BoostedJet_puppi_phi.push_back(-99);//j.userFloat("ak8PFJetsPuppiValueMap:phi"));
=======
    BoostedJet_puppi_pt.push_back(-99);//j.userFloat("ak8PFJetsPuppiValueMap:pt"));
    BoostedJet_puppi_mass.push_back(-99);//j.userFloat("ak8PFJetsPuppiValueMap:mass"));
    BoostedJet_puppi_eta.push_back(-99);//j.userFloat("ak8PFJetsPuppiValueMap:eta"));
    BoostedJet_puppi_phi.push_back(-99);//j.userFloat("ak8PFJetsPuppiValueMap:phi"));
    BoostedJet_puppi_tau1.push_back(-99);//j.userFloat("ak8PFJetsPuppiValueMap:NjettinessAK8PuppiTau1"));
    BoostedJet_puppi_tau2.push_back(-99);//j.userFloat("ak8PFJetsPuppiValueMap:NjettinessAK8PuppiTau2"));
    BoostedJet_puppi_tau3.push_back(-99);//j.userFloat("ak8PFJetsPuppiValueMap:NjettinessAK8PuppiTau3"));
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
    TLorentzVector puppi_softdrop, puppi_softdrop_subjet;
    auto const & sdSubjetsPuppi = j.subjets("SoftDropPuppi");
    for ( auto const & it : sdSubjetsPuppi ) {
      puppi_softdrop_subjet.SetPtEtaPhiM(it->correctedP4(0).pt(),it->correctedP4(0).eta(),it->correctedP4(0).phi(),it->correctedP4(0).mass());
      puppi_softdrop+=puppi_softdrop_subjet;
    }
    float puppiCorr = getPUPPIweight( j.correctedJet("Uncorrected").pt()*corrAK8PFchs*JERScaleFactor ,j.eta() );
    BoostedJet_puppi_softdrop_masscorr.push_back(puppi_softdrop.M()*puppiCorr);
<<<<<<< HEAD
=======
    //Variables for top-tagging
    double TopMass = -10.;
    double MinMass = -10.;
    double WMass = -10.;
    int NSubJets = -10;
    reco::CATopJetTagInfo const * tagInfo =  dynamic_cast<reco::CATopJetTagInfo const *>( j.tagInfo("caTop"));
    if( tagInfo != 0 ){
      TopMass  = tagInfo->properties().topMass;
      MinMass  = tagInfo->properties().minMass;
      WMass    = tagInfo->properties().wMass;
      NSubJets = tagInfo->properties().nSubJets;
    }
    TopTagging_topMass.push_back(TopMass);
    TopTagging_minMass.push_back(MinMass);
    TopTagging_wMass.push_back(WMass);
    TopTagging_nSubJets.push_back(NSubJets);
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  } 
}
void BoostedJetSelector::JECInitialization(){
  //AK8chs - MC: Get the factorized jet corrector parameters. 
  std::vector<std::string> jecPayloadNamesAK8PFchsMC_;
  jecPayloadNamesAK8PFchsMC_.push_back(jecPayloadNamesAK8PFchsMC1_.fullPath());
  jecPayloadNamesAK8PFchsMC_.push_back(jecPayloadNamesAK8PFchsMC2_.fullPath());
  jecPayloadNamesAK8PFchsMC_.push_back(jecPayloadNamesAK8PFchsMC3_.fullPath());
  std::vector<JetCorrectorParameters> vParAK8PFchsMC;
  for ( std::vector<std::string>::const_iterator payloadBegin = jecPayloadNamesAK8PFchsMC_.begin(),
	  payloadEnd = jecPayloadNamesAK8PFchsMC_.end(), ipayload = payloadBegin; ipayload != payloadEnd; ++ipayload ) {
    JetCorrectorParameters pars(*ipayload);
    vParAK8PFchsMC.push_back(pars);
  }
  jecAK8PFchsMC_    = boost::shared_ptr<FactorizedJetCorrector>  ( new FactorizedJetCorrector(vParAK8PFchsMC) );
  jecAK8PFchsMCUnc_ = boost::shared_ptr<JetCorrectionUncertainty>( new JetCorrectionUncertainty(jecPayloadNamesAK8PFchsMCUnc_.fullPath()) );
  //AK8chs - DATA: Get the factorized jet corrector parameters. 
  std::vector<std::string> jecPayloadNamesAK8PFchsDATA_;
  jecPayloadNamesAK8PFchsDATA_.push_back(jecPayloadNamesAK8PFchsDATA1_.fullPath());
  jecPayloadNamesAK8PFchsDATA_.push_back(jecPayloadNamesAK8PFchsDATA2_.fullPath());
  jecPayloadNamesAK8PFchsDATA_.push_back(jecPayloadNamesAK8PFchsDATA3_.fullPath());
  jecPayloadNamesAK8PFchsDATA_.push_back(jecPayloadNamesAK8PFchsDATA4_.fullPath());
  std::vector<JetCorrectorParameters> vParAK8PFchsDATA;
  for ( std::vector<std::string>::const_iterator payloadBegin = jecPayloadNamesAK8PFchsDATA_.begin(),
	  payloadEnd = jecPayloadNamesAK8PFchsDATA_.end(), ipayload = payloadBegin; ipayload != payloadEnd; ++ipayload ) {
    JetCorrectorParameters pars(*ipayload);
    vParAK8PFchsDATA.push_back(pars);
  }
  jecAK8PFchsDATA_    = boost::shared_ptr<FactorizedJetCorrector>  ( new FactorizedJetCorrector(vParAK8PFchsDATA) );
  jecAK8PFchsDATAUnc_ = boost::shared_ptr<JetCorrectionUncertainty>( new JetCorrectionUncertainty(jecPayloadNamesAK8PFchsDATAUnc_.fullPath()) );
}
void BoostedJetSelector::SetBranches(){
  if(debug_)    std::cout<<"setting branches: calling AddBranch of baseTree"<<std::endl;
  //Kinematic
  AddBranch(&BoostedJet_pt,                          "BoostedJet_pt");
  AddBranch(&BoostedJet_eta,                         "BoostedJet_eta");
  AddBranch(&BoostedJet_phi,                         "BoostedJet_phi");
  AddBranch(&BoostedJet_energy,                      "BoostedJet_energy");
  AddBranch(&BoostedJet_mass,                        "BoostedJet_mass");
  AddBranch(&BoostedJet_Uncorr_pt ,                  "BoostedJet_Uncorr_pt");
  //ID
<<<<<<< HEAD
  if(!_reduced){
    AddBranch(&BoostedJet_pfJetProbabilityBJetTags,                     "BoostedJet_pfJetProbabilityBJetTags");
    AddBranch(&BoostedJet_pfCombinedMVAV2BJetTags,                      "BoostedJet_pfCombinedMVAV2BJetTags");
    AddBranch(&BoostedJet_pfCombinedInclusiveSecondaryVertexV2BJetTags, "BoostedJet_pfCombinedInclusiveSecondaryVertexV2BJetTags");
    AddBranch(&BoostedJet_pfCombinedCvsLJetTags                        ,"BoostedJet_pfCombinedCvsLJetTags");
    AddBranch(&BoostedJet_pfCombinedCvsBJetTags                        ,"BoostedJet_pfCombinedCvsBJetTags");
  }
  //Energy related variables
  AddBranch(&BoostedJet_neutralHadEnergyFraction,    "BoostedJet_neutralHadEnergyFraction");
  AddBranch(&BoostedJet_neutralEmEnergyFraction,     "BoostedJet_neutralEmEnergyFraction");
=======
  AddBranch(&BoostedJet_pfJetProbabilityBJetTags,                     "BoostedJet_pfJetProbabilityBJetTags");
  AddBranch(&BoostedJet_pfCombinedMVAV2BJetTags,                      "BoostedJet_pfCombinedMVAV2BJetTags");
  AddBranch(&BoostedJet_pfCombinedInclusiveSecondaryVertexV2BJetTags, "BoostedJet_pfCombinedInclusiveSecondaryVertexV2BJetTags");
  AddBranch(&BoostedJet_pfCombinedCvsLJetTags                        ,"BoostedJet_pfCombinedCvsLJetTags");
  AddBranch(&BoostedJet_pfCombinedCvsBJetTags                        ,"BoostedJet_pfCombinedCvsBJetTags");
  //Energy related variables
  AddBranch(&BoostedJet_neutralHadEnergyFraction,    "BoostedJet_neutralHadEnergyFraction");
  AddBranch(&BoostedJet_neutralEmEmEnergyFraction,   "BoostedJet_neutralEmEmEnergyFraction");
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  AddBranch(&BoostedJet_chargedHadronEnergyFraction, "BoostedJet_chargedHadronEnergyFraction");
  AddBranch(&BoostedJet_chargedEmEnergyFraction,     "BoostedJet_chargedEmEnergyFraction");
  AddBranch(&BoostedJet_muonEnergyFraction,          "BoostedJet_muonEnergyFraction");
  AddBranch(&BoostedJet_numberOfConstituents,        "BoostedJet_numberOfConstituents");
  AddBranch(&BoostedJet_chargedMultiplicity,         "BoostedJet_chargedMultiplicity");
  AddBranch(&BoostedJet_electronEnergy,              "BoostedJet_electronEnergy");
  AddBranch(&BoostedJet_photonEnergy,                "BoostedJet_photonEnergy");
  //Boosted jet prop 
<<<<<<< HEAD
  AddBranch(&BoostedJet_tau1,               "BoostedJet_tau1");
  AddBranch(&BoostedJet_tau2,               "BoostedJet_tau2");
  AddBranch(&BoostedJet_tau3,               "BoostedJet_tau3");
  AddBranch(&BoostedJet_softdrop_mass,      "BoostedJet_softdrop_mass");
  AddBranch(&BoostedJet_pruned_mass,        "BoostedJet_pruned_mass");
  AddBranch(&BoostedJet_puppi_softdrop_mass,"BoostedJet_puppi_softdrop_mass");
  AddBranch(&BoostedJet_puppi_tau1,         "BoostedJet_puppi_tau1");
  AddBranch(&BoostedJet_puppi_tau2,         "BoostedJet_puppi_tau2");
  AddBranch(&BoostedJet_puppi_tau3,         "BoostedJet_puppi_tau3");
  if(!_reduced){
    AddBranch(&BoostedJet_puppi_pt,  "BoostedJet_puppi_pt");
    AddBranch(&BoostedJet_puppi_eta, "BoostedJet_puppi_eta");
    AddBranch(&BoostedJet_puppi_phi, "BoostedJet_puppi_phi");
    AddBranch(&BoostedJet_puppi_softdrop_masscorr,"BoostedJet_puppi_softdrop_masscorr");
  }
=======
  AddBranch(&BoostedJet_tau1,           "BoostedJet_tau1");
  AddBranch(&BoostedJet_tau2,           "BoostedJet_tau2");
  AddBranch(&BoostedJet_tau3,           "BoostedJet_tau3");
  AddBranch(&BoostedJet_softdrop_mass,  "BoostedJet_softdrop_mass");
  //AddBranch(&BoostedJet_trimmed_mass,   "BoostedJet_trimmed_mass");
  AddBranch(&BoostedJet_pruned_mass,    "BoostedJet_pruned_mass");
  //AddBranch(&BoostedJet_filtered_mass,  "BoostedJet_filtered_mass");
  AddBranch(&BoostedJet_puppi_pt,"BoostedJet_puppi_pt");
  AddBranch(&BoostedJet_puppi_mass,"BoostedJet_puppi_mass");
  AddBranch(&BoostedJet_puppi_eta,"BoostedJet_puppi_eta");
  AddBranch(&BoostedJet_puppi_phi,"BoostedJet_puppi_phi");
  AddBranch(&BoostedJet_puppi_tau1,"BoostedJet_puppi_tau1");
  AddBranch(&BoostedJet_puppi_tau2,"BoostedJet_puppi_tau2");
  AddBranch(&BoostedJet_puppi_tau3,"BoostedJet_puppi_tau3");
  AddBranch(&BoostedJet_puppi_softdrop_masscorr,"BoostedJet_puppi_softdrop_masscorr");
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  //Jet Energy Corrections and Uncertainties
  AddBranch(&BoostedJet_JesSF                ,"BoostedJet_JesSF");
  AddBranch(&BoostedJet_JesSFup              ,"BoostedJet_JesSFup");
  AddBranch(&BoostedJet_JesSFdown            ,"BoostedJet_JesSFdown");
  AddBranch(&BoostedJet_JerSF                ,"BoostedJet_JerSF");
  AddBranch(&BoostedJet_JerSFup              ,"BoostedJet_JerSFup");
  AddBranch(&BoostedJet_JerSFdown            ,"BoostedJet_JerSFdown");
<<<<<<< HEAD
=======
  //Variables for top-tagging
  AddBranch(&TopTagging_topMass,  "TopTagging_topMass");
  AddBranch(&TopTagging_minMass,  "TopTagging_minMass");
  AddBranch(&TopTagging_wMass,    "TopTagging_wMass");
  AddBranch(&TopTagging_nSubJets, "TopTagging_nSubJets");
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  if(debug_)    std::cout<<"set branches"<<std::endl;
}
void BoostedJetSelector::Clear(){
  //Kinematic
  BoostedJet_pt.clear();
  BoostedJet_eta.clear();
  BoostedJet_phi.clear();
  BoostedJet_energy.clear();
  BoostedJet_mass.clear();
  BoostedJet_Uncorr_pt.clear();
  //ID
  BoostedJet_pfJetProbabilityBJetTags.clear();
  BoostedJet_pfCombinedMVAV2BJetTags.clear();
  BoostedJet_pfCombinedInclusiveSecondaryVertexV2BJetTags.clear();
  BoostedJet_pfCombinedCvsLJetTags.clear();
  BoostedJet_pfCombinedCvsBJetTags.clear();
  //Energy related variables
  BoostedJet_neutralHadEnergyFraction.clear();
<<<<<<< HEAD
  BoostedJet_neutralEmEnergyFraction.clear();
=======
  BoostedJet_neutralEmEmEnergyFraction.clear();
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  BoostedJet_chargedHadronEnergyFraction.clear();
  BoostedJet_chargedEmEnergyFraction.clear();
  BoostedJet_muonEnergyFraction.clear();
  BoostedJet_numberOfConstituents.clear();
  BoostedJet_chargedMultiplicity.clear();
  BoostedJet_electronEnergy.clear();
  BoostedJet_photonEnergy.clear();
  //Boosted jet prop 
  BoostedJet_tau1.clear();
  BoostedJet_tau2.clear();
  BoostedJet_tau3.clear();
  BoostedJet_softdrop_mass.clear();
<<<<<<< HEAD
  BoostedJet_pruned_mass.clear();
  BoostedJet_puppi_pt.clear();
  BoostedJet_puppi_softdrop_mass.clear();
=======
  //BoostedJet_trimmed_mass.clear();
  BoostedJet_pruned_mass.clear();
  //BoostedJet_filtered_mass.clear();
  BoostedJet_puppi_pt.clear();
  BoostedJet_puppi_mass.clear();
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  BoostedJet_puppi_eta.clear();
  BoostedJet_puppi_phi.clear();
  BoostedJet_puppi_tau1.clear();
  BoostedJet_puppi_tau2.clear();
  BoostedJet_puppi_tau3.clear();
  BoostedJet_puppi_softdrop_masscorr.clear();
  //Jet Energy Corrections and Uncertainties
  BoostedJet_JesSF.clear();
  BoostedJet_JesSFup.clear();
  BoostedJet_JesSFdown.clear();
  BoostedJet_JerSF.clear();
  BoostedJet_JerSFup.clear();
  BoostedJet_JerSFdown.clear();
<<<<<<< HEAD
}
void BoostedJetSelector::GetJER(pat::Jet jet, float JesSF, float rhoJER, bool AK8PFchs, float &JERScaleFactor, float &JERScaleFactorUP, float &JERScaleFactorDOWN){
  if(!jet.genJet()) return;
  double recoJetPt = (jet.correctedJet("Uncorrected").pt())*JesSF;
  double genJetPt  = jet.genJet()->pt();
  double jetEta=fabs(jet.eta());
  double jetEta2018=jet.eta();
=======
  //Variables for top-tagging
  TopTagging_topMass.clear();
  TopTagging_minMass.clear();
  TopTagging_wMass.clear();
  TopTagging_nSubJets.clear();
}
void BoostedJetSelector::GetJER(pat::Jet jet, float JesSF, float rhoJER, bool AK8PFchs, float &JERScaleFactor, float &JERScaleFactorUP, float &JERScaleFactorDOWN){
  if(!jet.genJet()) return;
  double jetEta=fabs(jet.eta());
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  double cFactorJER = 1.0; 
  double cFactorJERdown = 1.0;
  double cFactorJERup = 1.0;
  //https://twiki.cern.ch/twiki/bin/view/CMS/JetResolution#JER_Scaling_factors_and_Unce_AN1
<<<<<<< HEAD
  if(_year==2017){
    if( jetEta<0.522 ){ 
      cFactorJER = 1.1432; 
      cFactorJERdown = 1.1432-0.0222;
      cFactorJERup   = 1.1432+0.0222; 
    } else if( jetEta<0.783 ){ 
      cFactorJER = 1.1815; 
      cFactorJERdown = 1.1815-0.0484;
      cFactorJERup   = 1.1815+0.0484; 
    } else if( jetEta<1.131 ){ 
      cFactorJER = 1.0989; 
      cFactorJERdown = 1.0989-0.0456;
      cFactorJERup   = 1.0989+0.0456; 
    } else if( jetEta<1.305 ){ 
      cFactorJER = 1.1137; 
      cFactorJERdown = 1.1137-0.1397;
      cFactorJERup   = 1.1137+0.1397; 
    } else if( jetEta<1.740 ){ 
      cFactorJER = 1.1307; 
      cFactorJERdown = 1.1307-0.1470;
      cFactorJERup   = 1.1307+0.1470; 
    } else if( jetEta<1.930 ){ 
      cFactorJER = 1.1600; 
      cFactorJERdown = 1.1600-0.0976;
      cFactorJERup   = 1.1600+0.0976; 
    } else if( jetEta<2.043 ){ 
      cFactorJER = 1.2393; 
      cFactorJERdown = 1.2393-0.1909;
      cFactorJERup   = 1.2393+0.1909; 
    } else if( jetEta<2.322 ){ 
      cFactorJER = 1.2604; 
      cFactorJERdown = 1.2604-0.1501;
      cFactorJERup   = 1.2604+0.1501; 
    } else if( jetEta<2.500 ){ 
      cFactorJER = 1.4085; 
      cFactorJERdown = 1.4085-0.2020;
      cFactorJERup   = 1.4085+0.2020; 
    } else if( jetEta<2.853 ){ 
      cFactorJER = 1.9909; 
      cFactorJERdown = 1.9909-0.5684;
      cFactorJERup   = 1.9909+0.5684; 
    } else if( jetEta<2.964 ){ 
      cFactorJER = 2.2923; 
      cFactorJERdown = 2.2923-0.3743;
      cFactorJERup   = 2.2923+0.3743; 
    } else if( jetEta<3.139 ){ 
      cFactorJER = 1.2696; 
      cFactorJERdown = 1.2696-0.1089;
      cFactorJERup   = 1.2696+0.1089; 
    } else if( jetEta<5.191 ){ 
      cFactorJER = 1.1542; 
      cFactorJERdown = 1.1542-0.1524;
      cFactorJERup   = 1.1542+0.1524;
    }
  }else if(_year==2018){
    if(jetEta2018>-5.191 && jetEta2018<-3.139 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.0760; cFactorJERdown = 1.0000; cFactorJERup = 1.2252;}
    if(jetEta2018>-3.139 && jetEta2018<-2.964 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.2063; cFactorJERdown = 1.1245; cFactorJERup = 1.2880;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>  0 && recoJetPt<  15) {cFactorJER = 1.0747; cFactorJERdown = 1.0000; cFactorJERup = 1.2747;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 15 && recoJetPt<  20) {cFactorJER = 1.0875; cFactorJERdown = 1.0000; cFactorJERup = 1.2875;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 20 && recoJetPt<  25) {cFactorJER = 1.1042; cFactorJERdown = 1.0000; cFactorJERup = 1.3042;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 25 && recoJetPt<  30) {cFactorJER = 1.1246; cFactorJERdown = 1.0000; cFactorJERup = 1.3246;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 30 && recoJetPt<  35) {cFactorJER = 1.1484; cFactorJERdown = 1.0000; cFactorJERup = 1.3484;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 35 && recoJetPt<  40) {cFactorJER = 1.1750; cFactorJERdown = 1.0000; cFactorJERup = 1.3750;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 40 && recoJetPt<  45) {cFactorJER = 1.2040; cFactorJERdown = 1.0041; cFactorJERup = 1.4040;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 45 && recoJetPt<  50) {cFactorJER = 1.2352; cFactorJERdown = 1.0352; cFactorJERup = 1.4352;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 50 && recoJetPt<  55) {cFactorJER = 1.2681; cFactorJERdown = 1.0681; cFactorJERup = 1.4681;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 55 && recoJetPt<  60) {cFactorJER = 1.3023; cFactorJERdown = 1.1023; cFactorJERup = 1.5023;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 60 && recoJetPt<  65) {cFactorJER = 1.3375; cFactorJERdown = 1.1375; cFactorJERup = 1.5375;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 65 && recoJetPt<  70) {cFactorJER = 1.3734; cFactorJERdown = 1.1734; cFactorJERup = 1.5734;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 70 && recoJetPt<  75) {cFactorJER = 1.4098; cFactorJERdown = 1.2098; cFactorJERup = 1.6098;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 75 && recoJetPt<  80) {cFactorJER = 1.4462; cFactorJERdown = 1.2462; cFactorJERup = 1.6462;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 80 && recoJetPt<  85) {cFactorJER = 1.4827; cFactorJERdown = 1.2827; cFactorJERup = 1.6827;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 85 && recoJetPt<  90) {cFactorJER = 1.5189; cFactorJERdown = 1.3189; cFactorJERup = 1.7189;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 90 && recoJetPt<  95) {cFactorJER = 1.5548; cFactorJERdown = 1.3548; cFactorJERup = 1.7548;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt> 95 && recoJetPt< 100) {cFactorJER = 1.5902; cFactorJERdown = 1.3902; cFactorJERup = 1.7902;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>100 && recoJetPt< 105) {cFactorJER = 1.6249; cFactorJERdown = 1.4249; cFactorJERup = 1.8249;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>105 && recoJetPt< 120) {cFactorJER = 1.6923; cFactorJERdown = 1.4923; cFactorJERup = 1.8923;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>120 && recoJetPt< 135) {cFactorJER = 1.7870; cFactorJERdown = 1.5870; cFactorJERup = 1.9870;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>135 && recoJetPt< 150) {cFactorJER = 1.8735; cFactorJERdown = 1.6735; cFactorJERup = 2.0735;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>150 && recoJetPt< 165) {cFactorJER = 1.9516; cFactorJERdown = 1.7516; cFactorJERup = 2.1516;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>165 && recoJetPt< 180) {cFactorJER = 2.0217; cFactorJERdown = 1.8217; cFactorJERup = 2.2217;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>180 && recoJetPt< 195) {cFactorJER = 2.0843; cFactorJERdown = 1.8843; cFactorJERup = 2.2843;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>195 && recoJetPt< 210) {cFactorJER = 2.1400; cFactorJERdown = 1.9400; cFactorJERup = 2.3400;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>210 && recoJetPt< 225) {cFactorJER = 2.1896; cFactorJERdown = 1.9896; cFactorJERup = 2.3896;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>225 && recoJetPt< 240) {cFactorJER = 2.2337; cFactorJERdown = 2.0337; cFactorJERup = 2.4337;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>240 && recoJetPt< 255) {cFactorJER = 2.2730; cFactorJERdown = 2.0730; cFactorJERup = 2.4730;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>255 && recoJetPt< 270) {cFactorJER = 2.3080; cFactorJERdown = 2.1080; cFactorJERup = 2.5080;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>270 && recoJetPt< 285) {cFactorJER = 2.3393; cFactorJERdown = 2.1393; cFactorJERup = 2.5393;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>285 && recoJetPt< 300) {cFactorJER = 2.3672; cFactorJERdown = 2.1672; cFactorJERup = 2.5672;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>300 && recoJetPt< 315) {cFactorJER = 2.3923; cFactorJERdown = 2.1923; cFactorJERup = 2.5923;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>315 && recoJetPt< 330) {cFactorJER = 2.4148; cFactorJERdown = 2.2148; cFactorJERup = 2.6148;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>330 && recoJetPt< 345) {cFactorJER = 2.4350; cFactorJERdown = 2.2351; cFactorJERup = 2.6350;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>345 && recoJetPt< 360) {cFactorJER = 2.4533; cFactorJERdown = 2.2533; cFactorJERup = 2.6533;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>360 && recoJetPt< 375) {cFactorJER = 2.4699; cFactorJERdown = 2.2699; cFactorJERup = 2.6699;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>375 && recoJetPt< 390) {cFactorJER = 2.4849; cFactorJERdown = 2.2849; cFactorJERup = 2.6849;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>390 && recoJetPt< 405) {cFactorJER = 2.4986; cFactorJERdown = 2.2986; cFactorJERup = 2.6986;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>405 && recoJetPt< 420) {cFactorJER = 2.5110; cFactorJERdown = 2.3110; cFactorJERup = 2.7110;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>420 && recoJetPt< 435) {cFactorJER = 2.5224; cFactorJERdown = 2.3224; cFactorJERup = 2.7224;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>435 && recoJetPt< 450) {cFactorJER = 2.5327; cFactorJERdown = 2.3327; cFactorJERup = 2.7327;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>450 && recoJetPt< 465) {cFactorJER = 2.5423; cFactorJERdown = 2.3423; cFactorJERup = 2.7423;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>465 && recoJetPt< 480) {cFactorJER = 2.5510; cFactorJERdown = 2.3510; cFactorJERup = 2.7510;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>480 && recoJetPt< 495) {cFactorJER = 2.5591; cFactorJERdown = 2.3591; cFactorJERup = 2.7591;}
    if(jetEta2018>-2.964 && jetEta2018<-2.853 && recoJetPt>495 && recoJetPt<7000) {cFactorJER = 2.5665; cFactorJERdown = 2.3665; cFactorJERup = 2.7665;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>  0 && recoJetPt<  15) {cFactorJER = 1.0199; cFactorJERdown = 1.0000; cFactorJERup = 1.2199;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 15 && recoJetPt<  20) {cFactorJER = 1.0341; cFactorJERdown = 1.0000; cFactorJERup = 1.2341;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 20 && recoJetPt<  25) {cFactorJER = 1.0528; cFactorJERdown = 1.0000; cFactorJERup = 1.2528;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 25 && recoJetPt<  30) {cFactorJER = 1.0755; cFactorJERdown = 1.0000; cFactorJERup = 1.2755;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 30 && recoJetPt<  35) {cFactorJER = 1.1018; cFactorJERdown = 1.0000; cFactorJERup = 1.3018;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 35 && recoJetPt<  40) {cFactorJER = 1.1311; cFactorJERdown = 1.0000; cFactorJERup = 1.3311;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 40 && recoJetPt<  45) {cFactorJER = 1.1631; cFactorJERdown = 1.0000; cFactorJERup = 1.3632;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 45 && recoJetPt<  50) {cFactorJER = 1.1973; cFactorJERdown = 1.0000; cFactorJERup = 1.3973;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 50 && recoJetPt<  55) {cFactorJER = 1.2333; cFactorJERdown = 1.0333; cFactorJERup = 1.4333;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 55 && recoJetPt<  60) {cFactorJER = 1.2706; cFactorJERdown = 1.0705; cFactorJERup = 1.4706;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 60 && recoJetPt<  65) {cFactorJER = 1.3088; cFactorJERdown = 1.1088; cFactorJERup = 1.5088;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 65 && recoJetPt<  70) {cFactorJER = 1.3477; cFactorJERdown = 1.1477; cFactorJERup = 1.5477;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 70 && recoJetPt<  75) {cFactorJER = 1.3869; cFactorJERdown = 1.1869; cFactorJERup = 1.5869;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 75 && recoJetPt<  80) {cFactorJER = 1.4262; cFactorJERdown = 1.2262; cFactorJERup = 1.6262;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 80 && recoJetPt<  85) {cFactorJER = 1.4654; cFactorJERdown = 1.2654; cFactorJERup = 1.6654;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 85 && recoJetPt<  90) {cFactorJER = 1.5043; cFactorJERdown = 1.3043; cFactorJERup = 1.7043;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 90 && recoJetPt<  95) {cFactorJER = 1.5427; cFactorJERdown = 1.3427; cFactorJERup = 1.7427;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt> 95 && recoJetPt< 100) {cFactorJER = 1.5804; cFactorJERdown = 1.3804; cFactorJERup = 1.7804;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>100 && recoJetPt< 105) {cFactorJER = 1.6175; cFactorJERdown = 1.4175; cFactorJERup = 1.8175;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>105 && recoJetPt< 120) {cFactorJER = 1.6892; cFactorJERdown = 1.4892; cFactorJERup = 1.8892;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>120 && recoJetPt< 135) {cFactorJER = 1.7897; cFactorJERdown = 1.5897; cFactorJERup = 1.9897;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>135 && recoJetPt< 150) {cFactorJER = 1.8812; cFactorJERdown = 1.6812; cFactorJERup = 2.0812;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>150 && recoJetPt< 165) {cFactorJER = 1.9637; cFactorJERdown = 1.7637; cFactorJERup = 2.1637;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>165 && recoJetPt< 180) {cFactorJER = 2.0376; cFactorJERdown = 1.8376; cFactorJERup = 2.2376;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>180 && recoJetPt< 195) {cFactorJER = 2.1034; cFactorJERdown = 1.9034; cFactorJERup = 2.3035;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>195 && recoJetPt< 210) {cFactorJER = 2.1620; cFactorJERdown = 1.9620; cFactorJERup = 2.3620;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>210 && recoJetPt< 225) {cFactorJER = 2.2141; cFactorJERdown = 2.0141; cFactorJERup = 2.4141;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>225 && recoJetPt< 240) {cFactorJER = 2.2604; cFactorJERdown = 2.0604; cFactorJERup = 2.4604;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>240 && recoJetPt< 255) {cFactorJER = 2.3015; cFactorJERdown = 2.1015; cFactorJERup = 2.5015;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>255 && recoJetPt< 270) {cFactorJER = 2.3382; cFactorJERdown = 2.1382; cFactorJERup = 2.5382;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>270 && recoJetPt< 285) {cFactorJER = 2.3709; cFactorJERdown = 2.1709; cFactorJERup = 2.5709;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>285 && recoJetPt< 300) {cFactorJER = 2.4002; cFactorJERdown = 2.2002; cFactorJERup = 2.6002;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>300 && recoJetPt< 315) {cFactorJER = 2.4264; cFactorJERdown = 2.2264; cFactorJERup = 2.6264;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>315 && recoJetPt< 330) {cFactorJER = 2.4500; cFactorJERdown = 2.2500; cFactorJERup = 2.6500;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>330 && recoJetPt< 345) {cFactorJER = 2.4712; cFactorJERdown = 2.2712; cFactorJERup = 2.6712;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>345 && recoJetPt< 360) {cFactorJER = 2.4903; cFactorJERdown = 2.2903; cFactorJERup = 2.6903;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>360 && recoJetPt< 375) {cFactorJER = 2.5076; cFactorJERdown = 2.3076; cFactorJERup = 2.7076;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>375 && recoJetPt< 390) {cFactorJER = 2.5233; cFactorJERdown = 2.3233; cFactorJERup = 2.7233;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>390 && recoJetPt< 405) {cFactorJER = 2.5376; cFactorJERdown = 2.3375; cFactorJERup = 2.7376;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>405 && recoJetPt< 420) {cFactorJER = 2.5505; cFactorJERdown = 2.3505; cFactorJERup = 2.7505;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>420 && recoJetPt< 435) {cFactorJER = 2.5624; cFactorJERdown = 2.3624; cFactorJERup = 2.7624;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>435 && recoJetPt< 450) {cFactorJER = 2.5732; cFactorJERdown = 2.3732; cFactorJERup = 2.7732;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>450 && recoJetPt< 465) {cFactorJER = 2.5832; cFactorJERdown = 2.3832; cFactorJERup = 2.7832;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>465 && recoJetPt< 480) {cFactorJER = 2.5923; cFactorJERdown = 2.3923; cFactorJERup = 2.7923;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>480 && recoJetPt< 495) {cFactorJER = 2.6008; cFactorJERdown = 2.4008; cFactorJERup = 2.8008;}
    if(jetEta2018>-2.853 && jetEta2018<-2.650 && recoJetPt>495 && recoJetPt<7000) {cFactorJER = 2.6085; cFactorJERdown = 2.4085; cFactorJERup = 2.8085;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>  0 && recoJetPt<  15) {cFactorJER = 1.1583; cFactorJERdown = 1.0000; cFactorJERup = 1.3583;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 15 && recoJetPt<  20) {cFactorJER = 1.1607; cFactorJERdown = 1.0000; cFactorJERup = 1.3607;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 20 && recoJetPt<  25) {cFactorJER = 1.1640; cFactorJERdown = 1.0000; cFactorJERup = 1.3640;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 25 && recoJetPt<  30) {cFactorJER = 1.1680; cFactorJERdown = 1.0000; cFactorJERup = 1.3680;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 30 && recoJetPt<  35) {cFactorJER = 1.1729; cFactorJERdown = 1.0000; cFactorJERup = 1.3729;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 35 && recoJetPt<  40) {cFactorJER = 1.1785; cFactorJERdown = 1.0000; cFactorJERup = 1.3785;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 40 && recoJetPt<  45) {cFactorJER = 1.1849; cFactorJERdown = 1.0000; cFactorJERup = 1.3849;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 45 && recoJetPt<  50) {cFactorJER = 1.1920; cFactorJERdown = 1.0000; cFactorJERup = 1.3920;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 50 && recoJetPt<  55) {cFactorJER = 1.1998; cFactorJERdown = 1.0000; cFactorJERup = 1.3998;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 55 && recoJetPt<  60) {cFactorJER = 1.2082; cFactorJERdown = 1.0082; cFactorJERup = 1.4082;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 60 && recoJetPt<  65) {cFactorJER = 1.2173; cFactorJERdown = 1.0173; cFactorJERup = 1.4173;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 65 && recoJetPt<  70) {cFactorJER = 1.2270; cFactorJERdown = 1.0270; cFactorJERup = 1.4270;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 70 && recoJetPt<  75) {cFactorJER = 1.2372; cFactorJERdown = 1.0372; cFactorJERup = 1.4372;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 75 && recoJetPt<  80) {cFactorJER = 1.2479; cFactorJERdown = 1.0479; cFactorJERup = 1.4479;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 80 && recoJetPt<  85) {cFactorJER = 1.2592; cFactorJERdown = 1.0592; cFactorJERup = 1.4592;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 85 && recoJetPt<  90) {cFactorJER = 1.2709; cFactorJERdown = 1.0709; cFactorJERup = 1.4709;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 90 && recoJetPt<  95) {cFactorJER = 1.2830; cFactorJERdown = 1.0830; cFactorJERup = 1.4830;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt> 95 && recoJetPt< 100) {cFactorJER = 1.2954; cFactorJERdown = 1.0954; cFactorJERup = 1.4954;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>100 && recoJetPt< 105) {cFactorJER = 1.3083; cFactorJERdown = 1.1083; cFactorJERup = 1.5083;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>105 && recoJetPt< 120) {cFactorJER = 1.3348; cFactorJERdown = 1.1348; cFactorJERup = 1.5348;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>120 && recoJetPt< 135) {cFactorJER = 1.3764; cFactorJERdown = 1.1764; cFactorJERup = 1.5764;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>135 && recoJetPt< 150) {cFactorJER = 1.4195; cFactorJERdown = 1.2195; cFactorJERup = 1.6195;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>150 && recoJetPt< 165) {cFactorJER = 1.4632; cFactorJERdown = 1.2632; cFactorJERup = 1.6632;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>165 && recoJetPt< 180) {cFactorJER = 1.5071; cFactorJERdown = 1.3071; cFactorJERup = 1.7071;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>180 && recoJetPt< 195) {cFactorJER = 1.5506; cFactorJERdown = 1.3506; cFactorJERup = 1.7506;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>195 && recoJetPt< 210) {cFactorJER = 1.5934; cFactorJERdown = 1.3934; cFactorJERup = 1.7934;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>210 && recoJetPt< 225) {cFactorJER = 1.6351; cFactorJERdown = 1.4351; cFactorJERup = 1.8351;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>225 && recoJetPt< 240) {cFactorJER = 1.6755; cFactorJERdown = 1.4755; cFactorJERup = 1.8755;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>240 && recoJetPt< 255) {cFactorJER = 1.7144; cFactorJERdown = 1.5144; cFactorJERup = 1.9144;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>255 && recoJetPt< 270) {cFactorJER = 1.7518; cFactorJERdown = 1.5518; cFactorJERup = 1.9518;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>270 && recoJetPt< 285) {cFactorJER = 1.7875; cFactorJERdown = 1.5875; cFactorJERup = 1.9875;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>285 && recoJetPt< 300) {cFactorJER = 1.8216; cFactorJERdown = 1.6216; cFactorJERup = 2.0216;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>300 && recoJetPt< 315) {cFactorJER = 1.8540; cFactorJERdown = 1.6540; cFactorJERup = 2.0540;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>315 && recoJetPt< 330) {cFactorJER = 1.8847; cFactorJERdown = 1.6847; cFactorJERup = 2.0847;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>330 && recoJetPt< 345) {cFactorJER = 1.9138; cFactorJERdown = 1.7138; cFactorJERup = 2.1138;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>345 && recoJetPt< 360) {cFactorJER = 1.9414; cFactorJERdown = 1.7414; cFactorJERup = 2.1414;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>360 && recoJetPt< 375) {cFactorJER = 1.9675; cFactorJERdown = 1.7675; cFactorJERup = 2.1675;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>375 && recoJetPt< 390) {cFactorJER = 1.9921; cFactorJERdown = 1.7921; cFactorJERup = 2.1921;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>390 && recoJetPt< 405) {cFactorJER = 2.0154; cFactorJERdown = 1.8154; cFactorJERup = 2.2154;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>405 && recoJetPt< 420) {cFactorJER = 2.0374; cFactorJERdown = 1.8374; cFactorJERup = 2.2374;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>420 && recoJetPt< 435) {cFactorJER = 2.0581; cFactorJERdown = 1.8581; cFactorJERup = 2.2581;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>435 && recoJetPt< 450) {cFactorJER = 2.0777; cFactorJERdown = 1.8777; cFactorJERup = 2.2777;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>450 && recoJetPt< 465) {cFactorJER = 2.0961; cFactorJERdown = 1.8961; cFactorJERup = 2.2961;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>465 && recoJetPt< 480) {cFactorJER = 2.1135; cFactorJERdown = 1.9135; cFactorJERup = 2.3135;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>480 && recoJetPt< 495) {cFactorJER = 2.1300; cFactorJERdown = 1.9300; cFactorJERup = 2.3300;}
    if(jetEta2018>-2.650 && jetEta2018<-2.500 && recoJetPt>495 && recoJetPt<7000) {cFactorJER = 2.1455; cFactorJERdown = 1.9455; cFactorJERup = 2.3455;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>  0 && recoJetPt<  15) {cFactorJER = 1.1755; cFactorJERdown = 1.0000; cFactorJERup = 1.3755;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 15 && recoJetPt<  20) {cFactorJER = 1.1758; cFactorJERdown = 1.0000; cFactorJERup = 1.3758;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 20 && recoJetPt<  25) {cFactorJER = 1.1762; cFactorJERdown = 1.0000; cFactorJERup = 1.3762;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 25 && recoJetPt<  30) {cFactorJER = 1.1766; cFactorJERdown = 1.0000; cFactorJERup = 1.3766;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 30 && recoJetPt<  35) {cFactorJER = 1.1772; cFactorJERdown = 1.0000; cFactorJERup = 1.3772;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 35 && recoJetPt<  40) {cFactorJER = 1.1778; cFactorJERdown = 1.0000; cFactorJERup = 1.3778;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 40 && recoJetPt<  45) {cFactorJER = 1.1785; cFactorJERdown = 1.0000; cFactorJERup = 1.3785;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 45 && recoJetPt<  50) {cFactorJER = 1.1793; cFactorJERdown = 1.0000; cFactorJERup = 1.3794;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 50 && recoJetPt<  55) {cFactorJER = 1.1802; cFactorJERdown = 1.0000; cFactorJERup = 1.3802;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 55 && recoJetPt<  60) {cFactorJER = 1.1812; cFactorJERdown = 1.0000; cFactorJERup = 1.3812;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 60 && recoJetPt<  65) {cFactorJER = 1.1823; cFactorJERdown = 1.0000; cFactorJERup = 1.3823;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 65 && recoJetPt<  70) {cFactorJER = 1.1834; cFactorJERdown = 1.0000; cFactorJERup = 1.3834;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 70 && recoJetPt<  75) {cFactorJER = 1.1846; cFactorJERdown = 1.0000; cFactorJERup = 1.3846;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 75 && recoJetPt<  80) {cFactorJER = 1.1859; cFactorJERdown = 1.0000; cFactorJERup = 1.3859;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 80 && recoJetPt<  85) {cFactorJER = 1.1873; cFactorJERdown = 1.0000; cFactorJERup = 1.3873;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 85 && recoJetPt<  90) {cFactorJER = 1.1887; cFactorJERdown = 1.0000; cFactorJERup = 1.3887;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 90 && recoJetPt<  95) {cFactorJER = 1.1902; cFactorJERdown = 1.0000; cFactorJERup = 1.3902;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt> 95 && recoJetPt< 100) {cFactorJER = 1.1917; cFactorJERdown = 1.0000; cFactorJERup = 1.3917;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>100 && recoJetPt< 105) {cFactorJER = 1.1933; cFactorJERdown = 1.0000; cFactorJERup = 1.3933;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>105 && recoJetPt< 120) {cFactorJER = 1.1967; cFactorJERdown = 1.0000; cFactorJERup = 1.3967;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>120 && recoJetPt< 135) {cFactorJER = 1.2021; cFactorJERdown = 1.0021; cFactorJERup = 1.4021;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>135 && recoJetPt< 150) {cFactorJER = 1.2078; cFactorJERdown = 1.0078; cFactorJERup = 1.4078;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>150 && recoJetPt< 165) {cFactorJER = 1.2137; cFactorJERdown = 1.0137; cFactorJERup = 1.4137;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>165 && recoJetPt< 180) {cFactorJER = 1.2198; cFactorJERdown = 1.0198; cFactorJERup = 1.4198;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>180 && recoJetPt< 195) {cFactorJER = 1.2260; cFactorJERdown = 1.0260; cFactorJERup = 1.4260;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>195 && recoJetPt< 210) {cFactorJER = 1.2323; cFactorJERdown = 1.0323; cFactorJERup = 1.4323;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>210 && recoJetPt< 225) {cFactorJER = 1.2385; cFactorJERdown = 1.0385; cFactorJERup = 1.4385;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>225 && recoJetPt< 240) {cFactorJER = 1.2446; cFactorJERdown = 1.0446; cFactorJERup = 1.4446;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>240 && recoJetPt< 255) {cFactorJER = 1.2507; cFactorJERdown = 1.0507; cFactorJERup = 1.4507;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>255 && recoJetPt< 270) {cFactorJER = 1.2566; cFactorJERdown = 1.0566; cFactorJERup = 1.4566;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>270 && recoJetPt< 285) {cFactorJER = 1.2623; cFactorJERdown = 1.0623; cFactorJERup = 1.4623;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>285 && recoJetPt< 300) {cFactorJER = 1.2679; cFactorJERdown = 1.0679; cFactorJERup = 1.4679;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>300 && recoJetPt< 315) {cFactorJER = 1.2732; cFactorJERdown = 1.0732; cFactorJERup = 1.4732;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>315 && recoJetPt< 330) {cFactorJER = 1.2784; cFactorJERdown = 1.0784; cFactorJERup = 1.4784;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>330 && recoJetPt< 345) {cFactorJER = 1.2833; cFactorJERdown = 1.0833; cFactorJERup = 1.4833;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>345 && recoJetPt< 360) {cFactorJER = 1.2880; cFactorJERdown = 1.0880; cFactorJERup = 1.4880;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>360 && recoJetPt< 375) {cFactorJER = 1.2925; cFactorJERdown = 1.0925; cFactorJERup = 1.4925;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>375 && recoJetPt< 390) {cFactorJER = 1.2968; cFactorJERdown = 1.0968; cFactorJERup = 1.4968;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>390 && recoJetPt< 405) {cFactorJER = 1.3009; cFactorJERdown = 1.1009; cFactorJERup = 1.5009;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>405 && recoJetPt< 420) {cFactorJER = 1.3048; cFactorJERdown = 1.1048; cFactorJERup = 1.5048;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>420 && recoJetPt< 435) {cFactorJER = 1.3085; cFactorJERdown = 1.1085; cFactorJERup = 1.5085;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>435 && recoJetPt< 450) {cFactorJER = 1.3121; cFactorJERdown = 1.1121; cFactorJERup = 1.5121;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>450 && recoJetPt< 465) {cFactorJER = 1.3154; cFactorJERdown = 1.1154; cFactorJERup = 1.5154;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>465 && recoJetPt< 480) {cFactorJER = 1.3186; cFactorJERdown = 1.1186; cFactorJERup = 1.5186;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>480 && recoJetPt< 495) {cFactorJER = 1.3216; cFactorJERdown = 1.1216; cFactorJERup = 1.5216;}
    if(jetEta2018>-2.500 && jetEta2018<-2.322 && recoJetPt>495 && recoJetPt<7000) {cFactorJER = 1.3245; cFactorJERdown = 1.1245; cFactorJERup = 1.5245;}
    if(jetEta2018>-2.322 && jetEta2018<-2.043 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1827; cFactorJERdown = 1.0517; cFactorJERup = 1.3136;}
    if(jetEta2018>-2.043 && jetEta2018<-1.930 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1388; cFactorJERdown = 1.0984; cFactorJERup = 1.1793;}
    if(jetEta2018>-1.930 && jetEta2018<-1.740 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1175; cFactorJERdown = 1.0778; cFactorJERup = 1.1571;}
    if(jetEta2018>-1.740 && jetEta2018<-1.305 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1432; cFactorJERdown = 1.0771; cFactorJERup = 1.2093;}
    if(jetEta2018>-1.305 && jetEta2018<-1.131 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1491; cFactorJERdown = 1.0815; cFactorJERup = 1.2166;}
    if(jetEta2018>-1.131 && jetEta2018<-0.783 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1340; cFactorJERdown = 1.0810; cFactorJERup = 1.1870;}
    if(jetEta2018>-0.783 && jetEta2018<-0.522 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1808; cFactorJERdown = 1.1640; cFactorJERup = 1.1977;}
    if(jetEta2018>-0.522 && jetEta2018< 0.000 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1639; cFactorJERdown = 1.1327; cFactorJERup = 1.1950;}
    if(jetEta2018> 0.000 && jetEta2018< 0.522 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1639; cFactorJERdown = 1.1327; cFactorJERup = 1.1950;}
    if(jetEta2018> 0.522 && jetEta2018< 0.783 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1808; cFactorJERdown = 1.1640; cFactorJERup = 1.1977;}
    if(jetEta2018> 0.783 && jetEta2018< 1.131 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1340; cFactorJERdown = 1.0810; cFactorJERup = 1.1870;}
    if(jetEta2018> 1.131 && jetEta2018< 1.305 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1491; cFactorJERdown = 1.0815; cFactorJERup = 1.2166;}
    if(jetEta2018> 1.305 && jetEta2018< 1.740 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1432; cFactorJERdown = 1.0771; cFactorJERup = 1.2093;}
    if(jetEta2018> 1.740 && jetEta2018< 1.930 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1175; cFactorJERdown = 1.0778; cFactorJERup = 1.1571;}
    if(jetEta2018> 1.930 && jetEta2018< 2.043 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1388; cFactorJERdown = 1.0984; cFactorJERup = 1.1793;}
    if(jetEta2018> 2.043 && jetEta2018< 2.322 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.1827; cFactorJERdown = 1.0517; cFactorJERup = 1.3136;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>  0 && recoJetPt<  20) {cFactorJER = 1.1757; cFactorJERdown = 1.0000; cFactorJERup = 1.3757;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt> 20 && recoJetPt<  30) {cFactorJER = 1.1764; cFactorJERdown = 1.0000; cFactorJERup = 1.3764;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt> 30 && recoJetPt<  40) {cFactorJER = 1.1775; cFactorJERdown = 1.0000; cFactorJERup = 1.3775;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt> 40 && recoJetPt<  50) {cFactorJER = 1.1790; cFactorJERdown = 1.0000; cFactorJERup = 1.3790;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt> 50 && recoJetPt<  60) {cFactorJER = 1.1808; cFactorJERdown = 1.0000; cFactorJERup = 1.3808;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt> 60 && recoJetPt<  70) {cFactorJER = 1.1830; cFactorJERdown = 1.0000; cFactorJERup = 1.3830;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt> 70 && recoJetPt<  80) {cFactorJER = 1.1854; cFactorJERdown = 1.0000; cFactorJERup = 1.3854;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt> 80 && recoJetPt<  90) {cFactorJER = 1.1881; cFactorJERdown = 1.0000; cFactorJERup = 1.3881;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt> 90 && recoJetPt< 100) {cFactorJER = 1.1911; cFactorJERdown = 1.0000; cFactorJERup = 1.3911;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>100 && recoJetPt< 110) {cFactorJER = 1.1943; cFactorJERdown = 1.0000; cFactorJERup = 1.3943;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>110 && recoJetPt< 135) {cFactorJER = 1.2002; cFactorJERdown = 1.0002; cFactorJERup = 1.4002;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>135 && recoJetPt< 160) {cFactorJER = 1.2097; cFactorJERdown = 1.0097; cFactorJERup = 1.4097;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>160 && recoJetPt< 185) {cFactorJER = 1.2198; cFactorJERdown = 1.0198; cFactorJERup = 1.4198;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>185 && recoJetPt< 210) {cFactorJER = 1.2302; cFactorJERdown = 1.0302; cFactorJERup = 1.4302;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>210 && recoJetPt< 235) {cFactorJER = 1.2406; cFactorJERdown = 1.0406; cFactorJERup = 1.4406;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>235 && recoJetPt< 260) {cFactorJER = 1.2507; cFactorJERdown = 1.0507; cFactorJERup = 1.4507;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>260 && recoJetPt< 285) {cFactorJER = 1.2604; cFactorJERdown = 1.0604; cFactorJERup = 1.4604;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>285 && recoJetPt< 310) {cFactorJER = 1.2697; cFactorJERdown = 1.0697; cFactorJERup = 1.4697;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>310 && recoJetPt< 335) {cFactorJER = 1.2784; cFactorJERdown = 1.0784; cFactorJERup = 1.4784;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>335 && recoJetPt< 360) {cFactorJER = 1.2865; cFactorJERdown = 1.0865; cFactorJERup = 1.4865;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>360 && recoJetPt< 385) {cFactorJER = 1.2940; cFactorJERdown = 1.0940; cFactorJERup = 1.4940;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>385 && recoJetPt< 410) {cFactorJER = 1.3009; cFactorJERdown = 1.1009; cFactorJERup = 1.5009;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>410 && recoJetPt< 435) {cFactorJER = 1.3073; cFactorJERdown = 1.1073; cFactorJERup = 1.5073;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>435 && recoJetPt< 460) {cFactorJER = 1.3132; cFactorJERdown = 1.1132; cFactorJERup = 1.5132;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>460 && recoJetPt< 485) {cFactorJER = 1.3186; cFactorJERdown = 1.1186; cFactorJERup = 1.5186;}
    if(jetEta2018> 2.322 && jetEta2018< 2.500 && recoJetPt>485 && recoJetPt<7000) {cFactorJER = 1.3235; cFactorJERdown = 1.1235; cFactorJERup = 1.5235;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>  0 && recoJetPt<  20) {cFactorJER = 1.1596; cFactorJERdown = 1.0000; cFactorJERup = 1.3596;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt> 20 && recoJetPt<  30) {cFactorJER = 1.1663; cFactorJERdown = 1.0000; cFactorJERup = 1.3663;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt> 30 && recoJetPt<  40) {cFactorJER = 1.1762; cFactorJERdown = 1.0000; cFactorJERup = 1.3762;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt> 40 && recoJetPt<  50) {cFactorJER = 1.1891; cFactorJERdown = 1.0000; cFactorJERup = 1.3891;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt> 50 && recoJetPt<  60) {cFactorJER = 1.2048; cFactorJERdown = 1.0048; cFactorJERup = 1.4048;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt> 60 && recoJetPt<  70) {cFactorJER = 1.2230; cFactorJERdown = 1.0230; cFactorJERup = 1.4230;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt> 70 && recoJetPt<  80) {cFactorJER = 1.2436; cFactorJERdown = 1.0436; cFactorJERup = 1.4436;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt> 80 && recoJetPt<  90) {cFactorJER = 1.2661; cFactorJERdown = 1.0661; cFactorJERup = 1.4661;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt> 90 && recoJetPt< 100) {cFactorJER = 1.2904; cFactorJERdown = 1.0904; cFactorJERup = 1.4904;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>100 && recoJetPt< 110) {cFactorJER = 1.3161; cFactorJERdown = 1.1161; cFactorJERup = 1.5161;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>110 && recoJetPt< 135) {cFactorJER = 1.3624; cFactorJERdown = 1.1624; cFactorJERup = 1.5624;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>135 && recoJetPt< 160) {cFactorJER = 1.4340; cFactorJERdown = 1.2340; cFactorJERup = 1.6340;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>160 && recoJetPt< 185) {cFactorJER = 1.5071; cFactorJERdown = 1.3071; cFactorJERup = 1.7071;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>185 && recoJetPt< 210) {cFactorJER = 1.5792; cFactorJERdown = 1.3792; cFactorJERup = 1.7792;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>210 && recoJetPt< 235) {cFactorJER = 1.6487; cFactorJERdown = 1.4487; cFactorJERup = 1.8487;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>235 && recoJetPt< 260) {cFactorJER = 1.7144; cFactorJERdown = 1.5144; cFactorJERup = 1.9144;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>260 && recoJetPt< 285) {cFactorJER = 1.7758; cFactorJERdown = 1.5758; cFactorJERup = 1.9758;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>285 && recoJetPt< 310) {cFactorJER = 1.8325; cFactorJERdown = 1.6325; cFactorJERup = 2.0325;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>310 && recoJetPt< 335) {cFactorJER = 1.8847; cFactorJERdown = 1.6847; cFactorJERup = 2.0847;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>335 && recoJetPt< 360) {cFactorJER = 1.9324; cFactorJERdown = 1.7324; cFactorJERup = 2.1324;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>360 && recoJetPt< 385) {cFactorJER = 1.9759; cFactorJERdown = 1.7759; cFactorJERup = 2.1759;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>385 && recoJetPt< 410) {cFactorJER = 2.0154; cFactorJERdown = 1.8154; cFactorJERup = 2.2154;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>410 && recoJetPt< 435) {cFactorJER = 2.0513; cFactorJERdown = 1.8513; cFactorJERup = 2.2513;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>435 && recoJetPt< 460) {cFactorJER = 2.0839; cFactorJERdown = 1.8839; cFactorJERup = 2.2839;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>460 && recoJetPt< 485) {cFactorJER = 2.1135; cFactorJERdown = 1.9135; cFactorJERup = 2.3135;}
    if(jetEta2018> 2.500 && jetEta2018< 2.650 && recoJetPt>485 && recoJetPt<7000) {cFactorJER = 2.1404; cFactorJERdown = 1.9404; cFactorJERup = 2.3404;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>  0 && recoJetPt<  20) {cFactorJER = 1.0279; cFactorJERdown = 1.0000; cFactorJERup = 1.2279;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt> 20 && recoJetPt<  30) {cFactorJER = 1.0660; cFactorJERdown = 1.0000; cFactorJERup = 1.2659;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt> 30 && recoJetPt<  40) {cFactorJER = 1.1190; cFactorJERdown = 1.0000; cFactorJERup = 1.3190;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt> 40 && recoJetPt<  50) {cFactorJER = 1.1834; cFactorJERdown = 1.0000; cFactorJERup = 1.3834;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt> 50 && recoJetPt<  60) {cFactorJER = 1.2555; cFactorJERdown = 1.0555; cFactorJERup = 1.4555;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt> 60 && recoJetPt<  70) {cFactorJER = 1.3321; cFactorJERdown = 1.1321; cFactorJERup = 1.5321;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt> 70 && recoJetPt<  80) {cFactorJER = 1.4105; cFactorJERdown = 1.2105; cFactorJERup = 1.6105;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt> 80 && recoJetPt<  90) {cFactorJER = 1.4888; cFactorJERdown = 1.2888; cFactorJERup = 1.6888;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt> 90 && recoJetPt< 100) {cFactorJER = 1.5654; cFactorJERdown = 1.3654; cFactorJERup = 1.7654;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>100 && recoJetPt< 110) {cFactorJER = 1.6394; cFactorJERdown = 1.4394; cFactorJERup = 1.8394;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>110 && recoJetPt< 135) {cFactorJER = 1.7572; cFactorJERdown = 1.5572; cFactorJERup = 1.9572;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>135 && recoJetPt< 160) {cFactorJER = 1.9097; cFactorJERdown = 1.7097; cFactorJERup = 2.1097;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>160 && recoJetPt< 185) {cFactorJER = 2.0376; cFactorJERdown = 1.8376; cFactorJERup = 2.2376;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>185 && recoJetPt< 210) {cFactorJER = 2.1433; cFactorJERdown = 1.9433; cFactorJERup = 2.3433;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>210 && recoJetPt< 235) {cFactorJER = 2.2301; cFactorJERdown = 2.0301; cFactorJERup = 2.4301;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>235 && recoJetPt< 260) {cFactorJER = 2.3015; cFactorJERdown = 2.1015; cFactorJERup = 2.5015;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>260 && recoJetPt< 285) {cFactorJER = 2.3604; cFactorJERdown = 2.1604; cFactorJERup = 2.5604;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>285 && recoJetPt< 310) {cFactorJER = 2.4092; cFactorJERdown = 2.2092; cFactorJERup = 2.6092;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>310 && recoJetPt< 335) {cFactorJER = 2.4500; cFactorJERdown = 2.2500; cFactorJERup = 2.6500;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>335 && recoJetPt< 360) {cFactorJER = 2.4841; cFactorJERdown = 2.2841; cFactorJERup = 2.6841;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>360 && recoJetPt< 385) {cFactorJER = 2.5130; cFactorJERdown = 2.3130; cFactorJERup = 2.7130;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>385 && recoJetPt< 410) {cFactorJER = 2.5376; cFactorJERdown = 2.3375; cFactorJERup = 2.7376;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>410 && recoJetPt< 435) {cFactorJER = 2.5586; cFactorJERdown = 2.3586; cFactorJERup = 2.7586;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>435 && recoJetPt< 460) {cFactorJER = 2.5767; cFactorJERdown = 2.3767; cFactorJERup = 2.7767;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>460 && recoJetPt< 485) {cFactorJER = 2.5923; cFactorJERdown = 2.3923; cFactorJERup = 2.7923;}
    if(jetEta2018> 2.650 && jetEta2018< 2.853 && recoJetPt>485 && recoJetPt<7000) {cFactorJER = 2.6060; cFactorJERdown = 2.4060; cFactorJERup = 2.8060;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>  0 && recoJetPt<  20) {cFactorJER = 1.0819; cFactorJERdown = 1.0000; cFactorJERup = 1.2819;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt> 20 && recoJetPt<  30) {cFactorJER = 1.1160; cFactorJERdown = 1.0000; cFactorJERup = 1.3160;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt> 30 && recoJetPt<  40) {cFactorJER = 1.1640; cFactorJERdown = 1.0000; cFactorJERup = 1.3640;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt> 40 && recoJetPt<  50) {cFactorJER = 1.2225; cFactorJERdown = 1.0225; cFactorJERup = 1.4225;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt> 50 && recoJetPt<  60) {cFactorJER = 1.2885; cFactorJERdown = 1.0885; cFactorJERup = 1.4885;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt> 60 && recoJetPt<  70) {cFactorJER = 1.3590; cFactorJERdown = 1.1590; cFactorJERup = 1.5590;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt> 70 && recoJetPt<  80) {cFactorJER = 1.4316; cFactorJERdown = 1.2316; cFactorJERup = 1.6316;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt> 80 && recoJetPt<  90) {cFactorJER = 1.5045; cFactorJERdown = 1.3045; cFactorJERup = 1.7045;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt> 90 && recoJetPt< 100) {cFactorJER = 1.5761; cFactorJERdown = 1.3761; cFactorJERup = 1.7761;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>100 && recoJetPt< 110) {cFactorJER = 1.6454; cFactorJERdown = 1.4454; cFactorJERup = 1.8454;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>110 && recoJetPt< 135) {cFactorJER = 1.7563; cFactorJERdown = 1.5563; cFactorJERup = 1.9563;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>135 && recoJetPt< 160) {cFactorJER = 1.9004; cFactorJERdown = 1.7004; cFactorJERup = 2.1004;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>160 && recoJetPt< 185) {cFactorJER = 2.0217; cFactorJERdown = 1.8217; cFactorJERup = 2.2217;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>185 && recoJetPt< 210) {cFactorJER = 2.1222; cFactorJERdown = 1.9222; cFactorJERup = 2.3222;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>210 && recoJetPt< 235) {cFactorJER = 2.2049; cFactorJERdown = 2.0049; cFactorJERup = 2.4049;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>235 && recoJetPt< 260) {cFactorJER = 2.2730; cFactorJERdown = 2.0730; cFactorJERup = 2.4730;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>260 && recoJetPt< 285) {cFactorJER = 2.3292; cFactorJERdown = 2.1292; cFactorJERup = 2.5292;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>285 && recoJetPt< 310) {cFactorJER = 2.3759; cFactorJERdown = 2.1759; cFactorJERup = 2.5759;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>310 && recoJetPt< 335) {cFactorJER = 2.4148; cFactorJERdown = 2.2148; cFactorJERup = 2.6148;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>335 && recoJetPt< 360) {cFactorJER = 2.4474; cFactorJERdown = 2.2474; cFactorJERup = 2.6474;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>360 && recoJetPt< 385) {cFactorJER = 2.4751; cFactorJERdown = 2.2751; cFactorJERup = 2.6751;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>385 && recoJetPt< 410) {cFactorJER = 2.4986; cFactorJERdown = 2.2986; cFactorJERup = 2.6986;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>410 && recoJetPt< 435) {cFactorJER = 2.5187; cFactorJERdown = 2.3187; cFactorJERup = 2.7187;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>435 && recoJetPt< 460) {cFactorJER = 2.5360; cFactorJERdown = 2.3360; cFactorJERup = 2.7360;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>460 && recoJetPt< 485) {cFactorJER = 2.5510; cFactorJERdown = 2.3510; cFactorJERup = 2.7510;}
    if(jetEta2018> 2.853 && jetEta2018< 2.964 && recoJetPt>485 && recoJetPt<7000) {cFactorJER = 2.5641; cFactorJERdown = 2.3641; cFactorJERup = 2.7641;}
    if(jetEta2018> 2.964 && jetEta2018< 3.139 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.2063; cFactorJERdown = 1.1245; cFactorJERup = 1.2880;}
    if(jetEta2018> 3.139 && jetEta2018< 5.191 && recoJetPt>  0 && recoJetPt<7000) {cFactorJER = 1.0760; cFactorJERdown = 1.0000; cFactorJERup = 1.2252;}
  } else if(_year==2016){
    if( jetEta<0.522 ){ 
      cFactorJER = 1.1595; 
      cFactorJERdown = 1.1595-0.0645;
      cFactorJERup   = 1.1595+0.0645; 
    } else if( jetEta<0.783 ){ 
      cFactorJER = 1.1948; 
      cFactorJERdown = 1.1948-0.0652;
      cFactorJERup   = 1.1948+0.0652; 
    } else if( jetEta<1.131 ){ 
      cFactorJER = 1.1464; 
      cFactorJERdown = 1.1464-0.0632;
      cFactorJERup   = 1.1464+0.0632; 
    } else if( jetEta<1.305 ){ 
      cFactorJER = 1.1609; 
      cFactorJERdown = 1.1609-0.1025;
      cFactorJERup   = 1.1609+0.1025; 
    } else if( jetEta<1.740 ){ 
      cFactorJER = 1.1278; 
      cFactorJERdown = 1.1278-0.0986;
      cFactorJERup   = 1.1278+0.0986; 
    } else if( jetEta<1.930 ){ 
      cFactorJER = 1.1000; 
      cFactorJERdown = 1.1000-0.1079;
      cFactorJERup   = 1.1000+0.1079; 
    } else if( jetEta<2.043 ){ 
      cFactorJER = 1.1426; 
      cFactorJERdown = 1.1426-0.1214;
      cFactorJERup   = 1.1426+0.1214; 
    } else if( jetEta<2.322 ){ 
      cFactorJER = 1.1512; 
      cFactorJERdown = 1.1512-0.1140;
      cFactorJERup   = 1.1512+0.1140; 
    } else if( jetEta<2.500 ){ 
      cFactorJER = 1.2963; 
      cFactorJERdown = 1.2963-0.2371;
      cFactorJERup   = 1.2963+0.2371; 
    } else if( jetEta<2.853 ){ 
      cFactorJER = 1.3418; 
      cFactorJERdown = 1.3418-0.2091;
      cFactorJERup   = 1.3418+0.2091; 
    } else if( jetEta<2.964 ){ 
      cFactorJER = 1.7788; 
      cFactorJERdown = 1.7788-0.2008;
      cFactorJERup   = 1.7788+0.2008; 
    } else if( jetEta<3.139 ){ 
      cFactorJER = 1.1869; 
      cFactorJERdown = 1.1869-0.1243;
      cFactorJERup   = 1.1869+0.1243; 
    } else if( jetEta<5.191 ){ 
      cFactorJER = 1.1922; 
      cFactorJERdown = 1.1922-0.1488;
      cFactorJERup   = 1.1922+0.1488;
    }
  }
=======
  if( jetEta<0.5 ){ 
    cFactorJER = 1.109; 
    cFactorJERdown = 1.109-0.008;
    cFactorJERup   = 1.109+0.008; 
  } else if( jetEta<0.8 ){ 
    cFactorJER = 1.138; 
    cFactorJERdown = 1.138-0.013;
    cFactorJERup   = 1.138+0.013; 
  } else if( jetEta<1.1 ){ 
    cFactorJER = 1.114; 
    cFactorJERdown = 1.114-0.013;
    cFactorJERup   = 1.114+0.013; 
  } else if( jetEta<1.3 ){ 
    cFactorJER = 1.123; 
    cFactorJERdown = 1.123-0.024;
    cFactorJERup   = 1.123+0.024; 
  } else if( jetEta<1.7 ){ 
    cFactorJER = 1.084; 
    cFactorJERdown = 1.084-0.011;
    cFactorJERup   = 1.084+0.011; 
  } else if( jetEta<1.9 ){ 
    cFactorJER = 1.082; 
    cFactorJERdown = 1.082-0.035;
    cFactorJERup   = 1.082+0.035; 
  } else if( jetEta<2.1 ){ 
    cFactorJER = 1.140; 
    cFactorJERdown = 1.140-0.047;
    cFactorJERup   = 1.140+0.047; 
  } else if( jetEta<2.3 ){ 
    cFactorJER = 1.067; 
    cFactorJERdown = 1.067-0.053;
    cFactorJERup   = 1.067+0.053; 
  } else if( jetEta<2.5 ){ 
    cFactorJER = 1.177; 
    cFactorJERdown = 1.177-0.041;
    cFactorJERup   = 1.177+0.041; 
  } else if( jetEta<2.8 ){ 
    cFactorJER = 1.364; 
    cFactorJERdown = 1.364-0.039;
    cFactorJERup   = 1.364+0.039; 
  } else if( jetEta<3.0 ){ 
    cFactorJER = 1.857; 
    cFactorJERdown = 1.857-0.071;
    cFactorJERup   = 1.857+0.071; 
  } else if( jetEta<3.2 ){ 
    cFactorJER = 1.328; 
    cFactorJERdown = 1.328-0.022;
    cFactorJERup   = 1.328+0.022; 
  } else if( jetEta<5.0 ){ 
    cFactorJER = 1.160; 
    cFactorJERdown = 1.160-0.029;
    cFactorJERup   = 1.160+0.029;
  }
  double recoJetPt = (jet.correctedJet("Uncorrected").pt())*JesSF;
  double genJetPt  = jet.genJet()->pt();
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  double diffPt    = recoJetPt - genJetPt;
  JME::JetResolution resolution;
  JME::JetResolutionScaleFactor res_sf;
  if(AK8PFchs){
    resolution = JME::JetResolution(jerAK8PFchs_);
    res_sf = JME::JetResolutionScaleFactor(jerAK8PFchsSF_);
  } else {
    resolution = JME::JetResolution(jerAK8PFPuppi_);
    res_sf = JME::JetResolutionScaleFactor(jerAK8PFPuppiSF_);
  }
  JME::JetParameters parameters;
  parameters.setJetPt(jet.pt());
  parameters.setJetEta(jet.eta());
  parameters.setRho(rhoJER);
  float relpterr = resolution.getResolution(parameters);
<<<<<<< HEAD
  if(genJetPt>0. && deltaR(jet.eta(),jet.phi(),jet.genJet()->eta(),jet.genJet()->phi())<0.2 && (abs(diffPt)<3*relpterr*recoJetPt)){
=======
  if(genJetPt>0. && deltaR(jet.eta(),jet.phi(),jet.genJet()->eta(),jet.genJet()->phi())<0.2
     && (abs(jet.pt()-jet.genJet()->pt())<3*relpterr*jet.pt())) {
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
    JERScaleFactor     = (std::max(0., genJetPt + cFactorJER*diffPt))/recoJetPt;
    JERScaleFactorUP   = (std::max(0., genJetPt + cFactorJERup*diffPt))/recoJetPt;
    JERScaleFactorDOWN = (std::max(0., genJetPt + cFactorJERdown*diffPt))/recoJetPt;
  } else {
    JERScaleFactor     = 1.;
    JERScaleFactorUP   = 1.;
    JERScaleFactorDOWN = 1.;
  } 
}
float BoostedJetSelector::getPUPPIweight(float puppipt, float puppieta ){
  float genCorr  = 1.;
  float recoCorr = 1.;
  float totalWeight = 1.;
  genCorr =  puppisd_corrGEN->Eval( puppipt );
  if( fabs(puppieta)  <= 1.3 ){
    recoCorr = puppisd_corrRECO_cen->Eval( puppipt );
  }
  else{
    recoCorr = puppisd_corrRECO_for->Eval( puppipt );
  }
  totalWeight = genCorr * recoCorr;
  return totalWeight;
}

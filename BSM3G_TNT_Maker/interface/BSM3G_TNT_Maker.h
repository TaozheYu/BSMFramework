//-*- C++ -*-
//
//Package: MiniAOD/BSM3G_TNT_Maker
//Class:   BSM3G_TNT_Maker
// 
#ifndef  TREE_MAKER_H                                                                                                                          
#define  TREE_MAKER_H
/////
//   User include files
/////
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
<<<<<<< HEAD
#include "BSMFramework/BSM3G_TNT_Maker/interface/BoostedJetSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/ElectronPatSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/EventInfoSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/GenParticleSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/JetSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/METSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/MuonSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/PVSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/PileupReweight.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/TauSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/TauboostedSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/TriggerSelector.h"
=======
#include "BSMFramework/BSM3G_TNT_Maker/interface/GenParticleSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/GenHFHadrMatchSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/EventInfoSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/TriggerSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/PVSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/MuonSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/ElectronPatSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/TauSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/JetSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/TTHJetSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/BoostedJetSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/TopSubJetSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/TauJetnessSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/BJetnessSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/BJetnessFVSelector.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/BTagReweight.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/PileupReweight.h"
#include "BSMFramework/BSM3G_TNT_Maker/interface/METSelector.h"
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
#include "BSMFramework/BSM3G_TNT_Maker/interface/PhotonSelector.h"
#include "baseTree.h"
#include <TBranch.h>
#include <TTree.h>
#include <TFile.h>
#include <vector>
#ifdef __MAKECINT__
#pragma link C++ class std::vector<std::vector<int> >+;
#pragma link C++ class std::vector<std::vector<std::string> >+;
#pragma link C++ class std::vector<std::vector<TString> >+;
#pragma link C++ class std::vector<std::vector<float> >+;
#pragma link C++ class std::vector<std::vector<double> >+;
#pragma link C++ class std::vector<std::vector<bool> >+;
#pragma extra_include "std::vector";
#endif
/////
//   Class declaration
/////
class BSM3G_TNT_Maker : public edm::EDAnalyzer {
 public:
  explicit BSM3G_TNT_Maker(const edm::ParameterSet&);
  ~BSM3G_TNT_Maker();
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
 private:
  virtual void beginJob() override;
  virtual void beginRun(edm::Run const &, edm::EventSetup const&);
<<<<<<< HEAD
  virtual void endRun(edm::Run const&, edm::EventSetup const&);
=======
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;
  /////
  //   Config variables
  /////
  edm::EDGetTokenT<edm::TriggerResults> triggerBits_;
  edm::EDGetTokenT<pat::TriggerObjectStandAloneCollection> triggerObjects_;
  edm::EDGetTokenT<pat::PackedTriggerPrescales> triggerPrescales_;
<<<<<<< HEAD
  //edm::EDGetTokenT<LHEEventProduct>     
  edm::EDGetTokenT<LHERunInfoProduct> lheEventProduct_;
  bool _is_data;
  bool _ifevtriggers;
  vector<string> _evtriggers;
  bool _fillBoostedJetinfo;
  bool _fillelectronpatinfo;
  bool _filleventinfo;
  bool _fillgeninfo;
  bool _filljetinfo;
  bool _fillMETinfo;
  bool _fillmuoninfo;
  bool _fillPVinfo;
  bool _fillPileupReweight;
  bool _filltauinfo;
  bool _filltauboostedinfo;
  bool _filltriggerinfo; 
=======
  bool _is_data;
  bool _ifevtriggers;
  vector<string> _evtriggers;
  bool _fillgeninfo;
  bool _fillgenHFCategoryinfo;
  bool _filleventinfo;
  bool _filltriggerinfo; 
  bool _fillPVinfo;
  bool _fillmuoninfo;
  bool _fillelectronpatinfo;
  bool _filltauinfo;
  bool _filljetinfo;
  bool _filltthjetinfo;
  bool _fillBoostedJetinfo;
  bool _fillTopSubJetinfo;
  bool _fillTauJetnessinfo;
  bool _fillBJetnessinfo;
  bool _fillBJetnessFVinfo;
  bool _fillBTagReweight;
  bool _fillPileupReweight;
  bool _fillMETinfo;
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  bool _fillphotoninfo;
  /////
  //   All 
  /////
  TFile* file;
  TTree* evtree_;
  int eventnum;
  int eventnumnegative;
  TTree* tree_;
  const size_t MaxN;
  bool debug_;
<<<<<<< HEAD
  BoostedJetSelector     *BoostedJetselector;
  ElectronPatSelector    *elpatselector;
  EventInfoSelector      *eventinfoselector;
  GenParticleSelector    *genselector;
  JetSelector            *jetselector;
  METSelector            *metselector;
  MuonSelector           *muselector;
  PVSelector             *pvselector;
  PileupReweight         *pileupreweight;
  TauSelector            *tauselector;
  TauboostedSelector     *tauboostedselector;
  TriggerSelector        *trselector;
=======
  bool bjetnessselfilter;
  int bjetnesssel_filter;
  GenParticleSelector    *genselector;
  GenHFHadrMatchSelector *genhfselector;
  EventInfoSelector      *eventinfoselector;
  TriggerSelector        *trselector;
  PVSelector             *pvselector;
  MuonSelector           *muselector;
  ElectronPatSelector    *elpatselector;
  TauSelector            *tauselector;
  JetSelector            *jetselector;
  TTHJetSelector         *tthjetselector;
  BoostedJetSelector     *BoostedJetselector;
  TopSubJetSelector      *TopSubJetselector;
  TauJetnessSelector     *TauJetnessselector;
  BJetnessSelector       *BJetnessselector;
  BJetnessFVSelector     *BJetnessFVselector;
  BTagReweight           *btagreweight;
  PileupReweight         *pileupreweight;
  METSelector            *metselector;
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  PhotonSelector         *photonselector;
};
#endif 

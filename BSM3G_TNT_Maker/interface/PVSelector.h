#ifndef __PV_HE_H_ 
#define __PV_HE_H_
/////
//   Include files and namespaces
/////
#include <memory>
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "Geometry/Records/interface/GlobalTrackingGeometryRecord.h"   
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/CompositeCandidate.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/Math/interface/LorentzVectorFwd.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/PatCandidates/interface/Isolation.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/normalizedPhi.h"
#include "DataFormats/TauReco/interface/PFTau.h"
#include "DataFormats/TauReco/interface/PFTauDiscriminator.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "DataFormats/Common/interface/RefVector.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "CLHEP/Random/RandGauss.h"
#include "CommonTools/CandUtils/interface/Booster.h"
#include "DataFormats/METReco/interface/GenMET.h"
#include "DataFormats/METReco/interface/GenMETCollection.h"
#include <Math/VectorUtil.h>
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/HitPattern.h"
#include "TrackingTools/TransientTrack/interface/TrackTransientTrack.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "CLHEP/Units/GlobalPhysicalConstants.h"
#include "CommonTools/Statistics/interface/ChiSquaredProbability.h"
#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"
#include "JetMETCorrections/Objects/interface/JetCorrectionsRecord.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "CommonTools/ParticleFlow/test/PFIsoReaderDemo.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/JetReco/interface/PFJetCollection.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "JetMETCorrections/Objects/interface/JetCorrector.h"
#include "JetMETCorrections/Objects/interface/JetCorrectionsRecord.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "boost/regex.hpp"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "PhysicsTools/JetMCUtils/interface/JetMCTag.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TProfile.h>
#include <TTree.h>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "baseTree.h"
#include <TRandom3.h>
#include <TBranch.h>
#include "TTree.h"
#include "TLorentzVector.h"
#include "TClonesArray.h"
using namespace std;
using namespace edm;
using namespace reco;
using namespace pat;
/////
//   Class declaration
/////
class PVSelector : public baseTree{
 public:
  PVSelector(std::string name, TTree* tree, bool debug, const edm::ParameterSet& cfg, edm::ConsumesCollector && iC);
  ~PVSelector();
  void Fill(const edm::Event& iEvent);
  void SetBranches();
  void Clear();
 private:
  PVSelector(){};
  /////
  //   Config variables
  /////
  edm::EDGetTokenT<reco::VertexCollection> vtx_;
  edm::EDGetTokenT<reco::BeamSpot> beamSpot_;
  edm::EDGetTokenT<std::vector< PileupSummaryInfo> > PUInfo_;
  //Primary vertex cuts
  double _Pvtx_ndof_min;
  double _Pvtx_vtx_max; 
  double _Pvtx_vtxdxy_max;
  bool   _is_data;
<<<<<<< HEAD
=======
  bool   _super_TNT;
  bool   _MiniAODv2;
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  /////
  //   BSM 
  /////
  //Variables
  int pvertex_notempty;
  int nBestVtx;
  int npuVertices, ootnpuVertices, npuVerticesm1, npuVerticesp1;
  double trueInteractions;
  vector<double> pvertex_x, pvertex_y, pvertex_z;
  vector<double> pvertex_xError, pvertex_yError, pvertex_zError;
  vector<double> pvertex_ndof, pvertex_dxy;
  vector<double> beamSpot_x0, beamSpot_y0, beamSpot_z0, beamSpot_xWidth, beamSpot_yWidth;
};
#endif

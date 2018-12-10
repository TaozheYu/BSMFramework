import FWCore.ParameterSet.Config as cms
#####
##   Initial standard configs
#####
process = cms.Process("Demo")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 10000
process.load('Configuration.Geometry.GeometryRecoDB_cff')
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load("Configuration.StandardSequences.MagneticField_38T_cff")
#process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
process.GlobalTag.globaltag = '94X_mcRun2_asymptotic_v3'
process.prefer("GlobalTag")
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')

#####
##   Input files
#####
process.source = cms.Source("PoolSource",
  fileNames = cms.untracked.vstring(
    '/store/mc/RunIISummer16MiniAODv2/TTTo2L2Nu_noSC_TuneCUETP8M2T4_13TeV-powheg-pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/80000/026FBAB6-EFD1-E611-B8D6-1CC1DE19274E.root'
    '/store/mc/RunIISummer16MiniAODv3/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v2/120000/FCDD7FFF-A8EA-E811-B17A-001E67D89532.root'
    ### THQ
    #'file:/eos/cms/store/cmst3/group/tthlep/peruzzi/THQ_4f_Hincl_13TeV_madgraph_pythia8_Fall17/MINIAODSIM_merged/merged_THQ.root',
    #'file:/eos/cms/store/cmst3/group/tthlep/peruzzi/THQ_4f_Hincl_13TeV_madgraph_pythia8_Fall17/MINIAODSIM_merged/merged_THQ008.root',
    
    ## VHToNonbb
    #'file:/eos/cms/store/cmst3/group/tthlep/peruzzi/VHToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_Fall17/MINIAODSIM_merged/merged_VHToNonbb.root',
    #'file:/eos/cms/store/cmst3/group/tthlep/peruzzi/VHToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_Fall17/MINIAODSIM_merged/merged_VHToNonbb011.root',
    
    ### WpWpJJ
    #'file:/eos/cms/store/cmst3/group/tthlep/peruzzi/WpWpJJ_EWK_QCD_TuneCP5_13TeV_madgraph_pythia8_Fall17/MINIAODSIM_merged/merged_WpWpJJ.root',
    #'file:/eos/cms/store/cmst3/group/tthlep/peruzzi/WpWpJJ_EWK_QCD_TuneCP5_13TeV_madgraph_pythia8_Fall17/MINIAODSIM_merged/merged_WpWpJJ001.root',

    ### tWll
    #'file:/eos/cms/store/cmst3/group/tthlep/peruzzi/ST_tWll_5f_LO_TuneCP5_PSweights_13TeV_madgraph_pythia8_Fall17/MINIAODSIM_merged/merged_tWll.root',
    ### THW
    #'file:/eos/cms/store/cmst3/group/tthlep/peruzzi/THW_5f_Hincl_13TeV_madgraph_pythia8_Fall17/MINIAODSIM_merged/merged_THW.root',
    #'file:/eos/cms/store/cmst3/group/tthlep/peruzzi/THW_5f_Hincl_13TeV_madgraph_pythia8_Fall17/MINIAODSIM_merged/merged_THW001.root',
    #'file:/eos/cms/store/cmst3/group/tthlep/peruzzi/THW_5f_Hincl_13TeV_madgraph_pythia8_Fall17/MINIAODSIM_merged/merged_THW002.root',
    #'file:/eos/cms/store/cmst3/group/tthlep/peruzzi/THW_5f_Hincl_13TeV_madgraph_pythia8_Fall17/MINIAODSIM_merged/merged_THW003.root',
  ),
  skipEvents = cms.untracked.uint32(0)
)
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10000) )


##### JEC
from PhysicsTools.PatAlgos.tools.jetTools import updateJetCollection

updateJetCollection(

  process,

  jetSource = cms.InputTag('slimmedJets'),

  labelName = 'UpdatedJEC',
  jetCorrections = ('AK4PFchs', cms.vstring(['L1FastJet','L2Relative','L3Absolute']), 'None')

)
#####
##   ELECTRON ID SECTION
#####
#process.load("RecoEgamma/ElectronIdentification/ElectronIDValueMapProducer_cfi")
#from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
#switchOnVIDElectronIdProducer(process,DataFormat.MiniAOD)
#switchOnVIDPhotonIdProducer(process,DataFormat.MiniAOD)
#my_id_modules = [ 'RecoEgamma.ElectronIdentification.Identification.heepElectronID_HEEPV70_cff',
#                  'RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_Fall17_94X_V1_cff',
#                  'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Fall17_noIso_V1_cff', 
#                  'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Fall17_iso_V1_cff',
#                  'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Spring16_HZZ_V1_cff'
#                  ]
#pho_id_modules =[ 'RecoEgamma.PhotonIdentification.Identification.cutBasedPhotonID_Fall17_94X_V1_TrueVtx_cff',
#                  'RecoEgamma.PhotonIdentification.Identification.mvaPhotonID_Fall17_94X_V1_cff',  
                  ]
#for idmod in my_id_modules:
#    setupAllVIDIdsInModule(process,idmod,setupVIDElectronSelection)
#for idmod in pho_id_modules:
#    setupAllVIDIdsInModule(process,idmod,setupVIDPhotonSelection)

######
### Electron smear and regression
######
#process.load('EgammaAnalysis.ElectronTools.calibratedPatElectronsRun2_cfi')
#process.load('EgammaAnalysis.ElectronTools.calibratedPatPhotonsRun2_cfi')
#process.load('Configuration.StandardSequences.Services_cff')
#process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService",
#                                                   slimmedElectrons  = cms.PSet( initialSeed = cms.untracked.uint32(81),
#                                                                                 engineName = cms.untracked.string('TRandom3'),
#                                                                                 ),
#                                                   slimmedPhotons  = cms.PSet( initialSeed = cms.untracked.uint32(81),
#                                                                               engineName = cms.untracked.string('TRandom3'),
#                                                                               ),
#                                                   )
#process.slimmedElectrons = process.calibratedPatElectrons.clone(electrons=cms.InputTag("slimmedElectrons",processName=cms.InputTag.skipCurrentProcess()))
#process.slimmedPhotons = process.calibratedPatPhotons.clone(photons=cms.InputTag("slimmedPhotons",processName=cms.InputTag.skipCurrentProcess())) 
#process.electronMVAValueMapProducer.srcMiniAOD = cms.InputTag('slimmedElectrons')
#process.photonMVAValueMapProducer.srcMiniAOD = cms.InputTag('slimmedPhotons')
#process.photonIDValueMapProducer.srcMiniAOD = cms.InputTag('slimmedPhotons')
#process.egammaScaleSmearTask = cms.Task(process.slimmedElectrons,process.slimmedPhotons)
#process.egammaScaleSmearSeq = cms.Sequence( process.egammaScaleSmearTask)
#process.egammaScaleSmearAndVIDSeq = cms.Sequence(process.egmGsfElectronIDSequence*process.egmPhotonIDSequence*process.egammaScaleSmearSeq)

#####
##   For tt+X
#####
# Setting input particle collections to be used by the tools
genParticleCollection = "prunedGenParticles"
genJetCollection      = "slimmedGenJets"
jetFlavourInfos       = "genJetFlavourInfos"
jetAlgo               = "AntiKt"
rParam                = 0.4
genJetPtMin           = 20.
genJetAbsEtaMax       = 2.4
from PhysicsTools.JetMCAlgos.HadronAndPartonSelector_cfi import selectedHadronsAndPartons
from PhysicsTools.JetMCAlgos.AK4PFJetsMCFlavourInfos_cfi import ak4JetFlavourInfos
from PhysicsTools.JetMCAlgos.GenHFHadronMatcher_cff import matchGenBHadron
from PhysicsTools.JetMCAlgos.GenHFHadronMatcher_cff import matchGenCHadron
process.selectedHadronsAndPartons = selectedHadronsAndPartons.clone(particles = genParticleCollection)
process.genJetFlavourInfos = ak4JetFlavourInfos.clone(jets=genJetCollection,rParam=cms.double(rParam),jetAlgorithm = cms.string(jetAlgo))
process.matchGenBHadron = matchGenBHadron.clone(genParticles = genParticleCollection,jetFlavourInfos = jetFlavourInfos)
process.matchGenCHadron = matchGenCHadron.clone(genParticles = genParticleCollection,jetFlavourInfos = jetFlavourInfos)

#####Tau#####

from BSMFramework.BSM3G_TNT_Maker.runTauIdMVA import *
na = TauIDEmbedder(process, cms,
        debug=True,
        toKeep = ["dR0p32017v2"] # pick the one you need: ["2017v1", "2017v2", "newDM2017v2", "dR0p32017v2", "2016v1", "newDM2016v1"]
        )
na.runTauID()

####https://twiki.cern.ch/twiki/bin/view/CMS/EgammaPostRecoRecipes#Running_on_2016_MiniAOD_V1
from RecoEgamma.EgammaTools.EgammaPostRecoTools import setupEgammaPostRecoSeq
setupEgammaPostRecoSeq(process,
                       runVID=True,
                       era='2016-Legacy'
                       )

############### MET Re-correct ##################
#from PhysicsTools.PatUtils.tools.runMETCorrectionsAndUncertainties import runMetCorAndUncFromMiniAOD
#from PhysicsTools.PatAlgos.slimming.puppiForMET_cff import makePuppiesFromMiniAOD
#makePuppiesFromMiniAOD( process, True )
#PFMet
#runMetCorAndUncFromMiniAOD(process,
#                           isData=False
#                           )
#Puppi MET
#runMetCorAndUncFromMiniAOD(process,
#                           isData=False,
#                           metType="Puppi",
#                           postfix="Puppi",
#                           jetFlavor="AK4PFPuppi",
#                           )

#process.puppiNoLep.useExistingWeights = False
#process.puppi.useExistingWeights = False


#####
##   Output file
#####
process.TFileService = cms.Service("TFileService",
  fileName = cms.string("OutTree.root")
)

#####
##   Analysis parameters
#####
process.TNT = cms.EDAnalyzer("BSM3G_TNT_Maker",
  #### Running options
  # Choose which trigger you want (do NOT need to put * as it will consider all the versions by default)
  ifevtriggers      = cms.bool(False), # True means you want to require the triggers
  maxtriggerversion = cms.double(20), # please leave it as a double
  evtriggers        = cms.vstring(
    'HLT_PFHT500_PFMET100_PFMHT100_IDTight_v',
    'HLT_PFHT700_PFMET85_PFMHT85_IDTight_v',
    'HLT_PFHT800_PFMET75_PFMHT75_IDTight_v',
    'HLT_CaloJet500_NoJetID_v',
    'HLT_PFHT1050_v',
    'HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v',
    'HLT_PFMET120_PFMHT120_IDTight_v',
    'HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v',
    'HLT_PFJet500_v',
    'HLT_AK8PFJet500_v',
    'HLT_Ele27_eta2p1_WPTight_Gsf_v',
    'HLT_Ele27_WPTight_Gsf_v',
    'HLT_Ele25_eta2p1_WPTight_Gsf_v',
    'HLT_Ele115_CaloIdVT_GsfTrkIdT_v',
    'HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v',
    'HLT_DoubleEle33_CaloIdL_MW_v',
    'HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v',
    'HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v',
    'HLT_IsoMu22_v',
    'HLT_IsoTKMu22_v',
    'HLT_IsoMu24_v',
    'HLT_IsoTkMu24_v',
    'HLT_IsoMu22_eta2p1_v',
    'HLT_IsoTkMu22_eta2p1_v',
    'HLT_Mu50_v',
    'HLT_TkMu50_v',
    'HLT_DoubleMu33NoFiltersNoVtx_v',
    'HLT_DoubleMu23NoFiltersNoVtxDisplaced_v',
    'HLT_Mu30_TkMu11_v',
    'HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v', 
    'HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v',
    'HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v',
    'HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v',
  ),
  # Choose which information you want to use
  fillgeninfo           = cms.bool(True),
  fillgenHFCategoryinfo = cms.bool(False),
  filleventinfo         = cms.bool(True),
  filltriggerinfo       = cms.bool(True),
  fillPVinfo            = cms.bool(True),
  fillmuoninfo          = cms.bool(True),
  fillelectronpatinfo   = cms.bool(True),
  filltauinfo           = cms.bool(False),#FF
  filljetinfo           = cms.bool(True), #T
  filltthjetinfo        = cms.bool(False), #F
  fillBoostedJetinfo    = cms.bool(True),
  fillTopSubJetinfo     = cms.bool(False), #F
  fillTauJetnessinfo    = cms.bool(False),
  fillBJetnessinfo      = cms.bool(False),
  fillBJetnessFVinfo    = cms.bool(False),
  fillBTagReweight      = cms.bool(False),
  fillPileupReweight    = cms.bool(True),
  fillMETinfo           = cms.bool(True),
  fillphotoninfo        = cms.bool(False), #F   
  # Choose format 
  MiniAODv2 = cms.bool(True),
  is_data   = cms.bool(False),
  reHLT     = cms.bool(True),
  debug_    = cms.bool(False),
  super_TNT = cms.bool(False),
  AJVar     = cms.bool(False),
  tthlepVar = cms.bool(False),#FF
  bjetnessselfilter = cms.bool(False),
  PuppiVar  = cms.bool(False),
  qglVar    = cms.bool(False),#FF
  MC2016    = cms.bool(True),
  # Input tags 
  bits                = cms.InputTag("TriggerResults","","HLT"),
  prescales           = cms.InputTag("patTrigger"),
  objects             = cms.InputTag("selectedPatTrigger"),  
  vertices            = cms.InputTag("offlineSlimmedPrimaryVertices"),
  beamSpot            = cms.InputTag("offlineBeamSpot"),
  muons               = cms.InputTag("slimmedMuons"),
  patElectrons        = cms.InputTag("slimmedElectrons"),
  electronVetoIdMap   = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Fall17-94X-V1-veto"),
  electronLooseIdMap  = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Fall17-94X-V1-loose"),
  electronMediumIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Fall17-94X-V1-medium"),
  electronTightIdMap  = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Fall17-94X-V1-tight"),
  eleMVATrigIdMap        = cms.InputTag("egmGsfElectronIDs:mvaEleID-Fall17-iso-V1-wp80"),
  eleMVAnonTrigIdMap     = cms.InputTag("egmGsfElectronIDs:mvaEleID-Fall17-noIso-V1-wp80"),
  eleMVATrigwp90IdMap    = cms.InputTag("egmGsfElectronIDs:mvaEleID-Fall17-iso-V1-wp90"),
  eleMVAnonTrigwp90IdMap = cms.InputTag("egmGsfElectronIDs:mvaEleID-Fall17-noIso-V1-wp90"),
  eleMVATrigwpLooseIdMap    = cms.InputTag("egmGsfElectronIDs:mvaEleID-Fall17-iso-V1-wpLoose"),
  eleMVAnonTrigwpLooseIdMap = cms.InputTag("egmGsfElectronIDs:mvaEleID-Fall17-noIso-V1-wpLoose"),
  eleHEEPIdMap                 = cms.InputTag("egmGsfElectronIDs:heepElectronID-HEEPV70"),
  elemvaValuesMap_Trig      = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Fall17IsoV1Values"),
  elemvaCategoriesMap_Trig  = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Fall17IsoV1Categories"),
  elemvaValuesMap_nonTrig         = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Fall17NoIsoV1Values"),
  elemvaCategoriesMap_nonTrig     = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Fall17NoIsoV1Categories"),
  eleMVAHZZwpLooseIdMap = cms.InputTag("egmGsfElectronIDs:mvaEleID-Spring16-HZZ-V1-wpLoose"),
  elemvaValuesMap_HZZ          = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Spring16HZZV1Values"),
  elemvaCategoriesMap_HZZ      = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Spring16HZZV1Categories"),
  ebRecHits = cms.InputTag("reducedEgamma","reducedEBRecHits"),
  #taus                = cms.InputTag("slimmedTaus"),
  taus                = cms.InputTag("NewTauIDsEmbedded"),
  jets                = cms.InputTag("slimmedJets"),
  lepjets             = cms.InputTag("updatedPatJetsUpdatedJEC"),
  jetsPUPPI           = cms.InputTag("slimmedJetsPuppi"),
  fatjets             = cms.InputTag("slimmedJetsAK8"),
  topsubjets          = cms.InputTag("slimmedJetsCMSTopTagCHSPacked", "SubJets"),
  mets                = cms.InputTag("slimmedMETs"),
  metsPUPPI           = cms.InputTag("slimmedMETsPuppi"),
  metFilterBits       = cms.InputTag("TriggerResults", "", "PAT"),
  photons             = cms.InputTag("slimmedPhotons"),
  packedPFCandidates  = cms.InputTag("packedPFCandidates"), 
  pruned              = cms.InputTag("prunedGenParticles"),
  # Tau
  #byIsolationMVArun2017v2DBoldDMwLTraw2017 = cms.string('byIsolationMVArun2017v2DBoldDMwLTraw2017'),
  #byVVLooseIsolationMVArun2017v2DBoldDMwLT2017 = cms.string('byVVLooseIsolationMVArun2017v2DBoldDMwLT2017'),
  #byVLooseIsolationMVArun2017v2DBoldDMwLT2017 = cms.string('byVLooseIsolationMVArun2017v2DBoldDMwLT2017'),
  #byLooseIsolationMVArun2017v2DBoldDMwLT2017 = cms.string('byLooseIsolationMVArun2017v2DBoldDMwLT2017'),
  #byMediumIsolationMVArun2017v2DBoldDMwLT2017 = cms.string('byMediumIsolationMVArun2017v2DBoldDMwLT2017'),
  #byTightIsolationMVArun2017v2DBoldDMwLT2017 = cms.string('byTightIsolationMVArun2017v2DBoldDMwLT2017'),
  #byVTightIsolationMVArun2017v2DBoldDMwLT2017 = cms.string('byVTightIsolationMVArun2017v2DBoldDMwLT2017'),
  #byVVTightIsolationMVArun2017v2DBoldDMwLT2017 = cms.string('byVVTightIsolationMVArun2017v2DBoldDMwLT2017'),
  # JER
  jerAK4PFchs     =  cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JER/Summer16_25nsV1_MC_PtResolution_AK4PFchs.txt"),
  jerAK4PFchsSF   =  cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JER/Summer16_25nsV1_MC_SF_AK4PFchs.txt"),
  jerAK4PFPuppi   =  cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JER/Summer16_25nsV1_MC_PtResolution_AK4PFPuppi.txt"),
  jerAK4PFPuppiSF =  cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JER/Summer16_25nsV1_MC_SF_AK4PFPuppi.txt"),
  jerAK8PFchs     =  cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JER/Summer16_25nsV1_MC_PtResolution_AK8PFchs.txt"),
  jerAK8PFchsSF   =  cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JER/Summer16_25nsV1_MC_SF_AK8PFchs.txt"),
  jerAK8PFPuppi   =  cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JER/Summer16_25nsV1_MC_PtResolution_AK8PFPuppi.txt"),
  jerAK8PFPuppiSF =  cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JER/Summer16_25nsV1_MC_SF_AK8PFPuppi.txt"),
  # JEC - CORRECTIONS ON FLY
  jecPayloadNamesAK4PFchsMC1   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/MC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_L1FastJet_AK4PFchs.txt"),
  jecPayloadNamesAK4PFchsMC2   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/MC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_L2Relative_AK4PFchs.txt"),
  jecPayloadNamesAK4PFchsMC3   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/MC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_L3Absolute_AK4PFchs.txt"),
  jecPayloadNamesAK4PFchsMCUnc = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/MC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_Uncertainty_AK4PFchs.txt"),
  jecPayloadNamesAK4PFchsDATA1   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_L1FastJet_AK4PFchs.txt"),
  jecPayloadNamesAK4PFchsDATA2   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_L2Relative_AK4PFchs.txt"),
  jecPayloadNamesAK4PFchsDATA3   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_L3Absolute_AK4PFchs.txt"),
  jecPayloadNamesAK4PFchsDATA4   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_L2L3Residual_AK4PFchs.txt"),
  jecPayloadNamesAK4PFchsDATAUnc = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_Uncertainty_AK4PFchs.txt"),
  jecPayloadNamesAK4PFPuppiMC1   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/MC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_L1FastJet_AK4PFPuppi.txt"),
  jecPayloadNamesAK4PFPuppiMC2   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/MC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_L2Relative_AK4PFPuppi.txt"),
  jecPayloadNamesAK4PFPuppiMC3   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/MC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_L3Absolute_AK4PFPuppi.txt"),
  jecPayloadNamesAK4PFPuppiMCUnc = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/MC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_Uncertainty_AK4PFPuppi.txt"),
  jecPayloadNamesAK4PFPuppiDATA1   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_L1FastJet_AK4PFPuppi.txt"),
  jecPayloadNamesAK4PFPuppiDATA2   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_L2Relative_AK4PFPuppi.txt"),
  jecPayloadNamesAK4PFPuppiDATA3   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_L3Absolute_AK4PFPuppi.txt"),
  jecPayloadNamesAK4PFPuppiDATA4   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_L2L3Residual_AK4PFPuppi.txt"),
  jecPayloadNamesAK4PFPuppiDATAUnc = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_Uncertainty_AK4PFPuppi.txt"),
  jecPayloadNamesAK8PFchsMC1   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/MC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_L1FastJet_AK8PFchs.txt"),
  jecPayloadNamesAK8PFchsMC2   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/MC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_L2Relative_AK8PFchs.txt"),
  jecPayloadNamesAK8PFchsMC3   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/MC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_L3Absolute_AK8PFchs.txt"),
  jecPayloadNamesAK8PFchsMCUnc = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/MC/Summer16_07Aug2017_V11_MC/Summer16_07Aug2017_V11_MC_Uncertainty_AK8PFchs.txt"),
  jecPayloadNamesAK8PFchsDATA1   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_L1FastJet_AK8PFchs.txt"),
  jecPayloadNamesAK8PFchsDATA2   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_L2Relative_AK8PFchs.txt"),
  jecPayloadNamesAK8PFchsDATA3   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_L3Absolute_AK8PFchs.txt"),
  jecPayloadNamesAK8PFchsDATA4   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_L2L3Residual_AK8PFchs.txt"),
  jecPayloadNamesAK8PFchsDATAUnc = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/JEC/DATA/Summer16_07Aug2017BCD_V11_DATA/Summer16_07Aug2017BCD_V11_DATA_Uncertainty_AK8PFchs.txt"),
  # PILEUP REWEIGHTING
  PUReweightfile      = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/PUReweight/PileUpReweighting2016.root"),
  #MyPUReweightfile      = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/PUReweight/MyPileUpReweighting2017.root"),
  #MinBiasUpReweightfile      = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/PUReweight/PileUpUpReweighting2017.root"),
  #MinBiasDownReweightfile      = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/PUReweight/PileUpDownReweighting2017.root"),
  # PUPPI WEIGHT
  PuppiWeightFilePath = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/PUPPI/puppiCorr.root"),
  # BTAG REWEIGHTING
  BTAGReweightfile1   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/BTAGReweight/csv_rwt_fit_hf_v2_final_2016_06_30test.root"),
  BTAGReweightfile2   = cms.FileInPath("BSMFramework/BSM3G_TNT_Maker/data/BTAGReweight/csv_rwt_fit_lf_v2_final_2016_06_30test.root"),
  # Object selection
  # Primary vertex cuts
  Pvtx_ndof_min   = cms.double(4.),
  Pvtx_vtx_max    = cms.double(24.),
  Pvtx_vtxdxy_max = cms.double(24.),
  # Obj primary vertex cuts
  vtx_ndof_min        = cms.int32(4),
  vtx_rho_max         = cms.int32(2),
  vtx_position_z_max  = cms.double(24.),
  # Muon cuts
  Muon_pt_min         = cms.double(5.),
  Muon_eta_max        = cms.double(50),
  # Electron cuts
  patElectron_pt_min  = cms.double(5.),
  patElectron_eta_max = cms.double(50),
  # Tau cuts
  Tau_pt_min          = cms.double(15.),
  Tau_eta_max         = cms.double(50.),
  # Jet cuts
  Jet_pt_min = cms.double(10.),
  # Photon cuts 
  Photon_pt_min   = cms.double(5.0),
  Photon_eta_max  = cms.double(5.0),
  # ttHFCategorization
  genJetPtMin               = cms.double(genJetPtMin),
  genJetAbsEtaMax           = cms.double(genJetAbsEtaMax),
  genJets                   = cms.InputTag(genJetCollection),
  genBHadJetIndex           = cms.InputTag("matchGenBHadron", "genBHadJetIndex"),
  genBHadFlavour            = cms.InputTag("matchGenBHadron", "genBHadFlavour"),
  genBHadFromTopWeakDecay   = cms.InputTag("matchGenBHadron", "genBHadFromTopWeakDecay"),
  genBHadPlusMothers        = cms.InputTag("matchGenBHadron", "genBHadPlusMothers"),
  genBHadPlusMothersIndices = cms.InputTag("matchGenBHadron", "genBHadPlusMothersIndices"),
  genBHadIndex              = cms.InputTag("matchGenBHadron", "genBHadIndex"),
  genBHadLeptonHadronIndex  = cms.InputTag("matchGenBHadron", "genBHadLeptonHadronIndex"),
  genBHadLeptonViaTau       = cms.InputTag("matchGenBHadron", "genBHadLeptonViaTau"),
  genCHadJetIndex           = cms.InputTag("matchGenCHadron", "genCHadJetIndex"),
  genCHadFlavour            = cms.InputTag("matchGenCHadron", "genCHadFlavour"),
  genCHadFromTopWeakDecay   = cms.InputTag("matchGenCHadron", "genCHadFromTopWeakDecay"),
  genCHadBHadronId          = cms.InputTag("matchGenCHadron", "genCHadBHadronId"),
)



#####
##   Dump gen particle list 
#####
process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
process.printGenParticleList = cms.EDAnalyzer("ParticleListDrawer",
  maxEventsToPrint = cms.untracked.int32(-1),
  printVertex = cms.untracked.bool(True),
  src = cms.InputTag("prunedGenParticles")
)


#QG likelihood
process.load('BSMFramework.BSM3G_TNT_Maker.QGTagger_cfi')
process.QGTagger.srcJets       = cms.InputTag('slimmedJets')
process.QGTagger.jetsLabel     = cms.string('QGL_AK4PFchs')

#####
##   PROCESS
#####
process.p = cms.Path(
process.patJetCorrFactorsUpdatedJEC * process.updatedPatJetsUpdatedJEC *
process.egammaPostRecoSeq *
#process.regressionApplication *
#process.calibratedPatElectrons  *
#process.egmGsfElectronIDSequence *
#process.electronIDValueMapProducer *
#process.egmPhotonIDSequence *
#process.egammaScaleSmearAndVIDSeq *
#process.fullPatMetSequence *
#process.puppiMETSequence *
#process.fullPatMetSequencePuppi *
process.QGTagger *
process.rerunMvaIsolationSequence *
process.NewTauIDsEmbedded* # *getattr(process, "NewTauIDsEmbedded")
#process.selectedHadronsAndPartons*process.genJetFlavourInfos*process.matchGenCHadron*process.matchGenBHadron*
#process.primaryVertexFilter* 
#process.CSCTightHaloFilter*process.eeBadScFilter*process.HBHENoiseFilterResultProducer*process.ApplyBaselineHBHENoiseFilter*
process.TNT
)

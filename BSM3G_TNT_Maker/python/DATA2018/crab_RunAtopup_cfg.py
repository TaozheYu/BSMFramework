from WMCore.Configuration import Configuration
config = Configuration()

config.section_('General')
config.General.requestName = 'RunAtopup'
config.General.workArea    = '2018v03'

config.section_('JobType')
config.JobType.pluginName = 'Analysis'
config.JobType.psetName   = 'miniAOD_RunA.py'
config.JobType.sendExternalFolder = True
config.section_('Data')
config.Data.inputDataset  = '/MET/Run2018A-17Sep2018-v1/MINIAOD'
config.Data.inputDBS      = 'global'
config.Data.splitting     = 'FileBased'
config.Data.unitsPerJob   = 1
config.Data.lumiMask      = '/afs/cern.ch/work/a/aspiezia/Ntuplizer/2018/CMSSW_10_2_10/src/BSMFramework/BSM3G_TNT_Maker/python/2018v03/crab_RunA/results/notFinishedLumis.json'
config.Data.outLFNDirBase = '/store/user/aspiezia/'

config.section_('Site')
config.Site.storageSite = 'T2_CN_Beijing'


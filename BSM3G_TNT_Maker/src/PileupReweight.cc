#include "BSMFramework/BSM3G_TNT_Maker/interface/PileupReweight.h"
PileupReweight::PileupReweight(std::string name, TTree* tree, bool debug, const pset& iConfig, edm::ConsumesCollector && ic):
  baseTree(name,tree,debug)
{
  if(debug) std::cout<<"in PileupReweight constructor"<<std::endl;
<<<<<<< HEAD
  _is_data   = iConfig.getParameter<bool>("is_data");
  _year  = iConfig.getParameter<int>("year");
  PUInfo_         = ic.consumes<std::vector< PileupSummaryInfo> >(edm::InputTag("slimmedAddPileupInfo"));
  PUReweightfile_ = iConfig.getParameter<edm::FileInPath>("PUReweightfile");
=======
  _MiniAODv2 = iConfig.getParameter<bool>("MiniAODv2");
  _is_data   = iConfig.getParameter<bool>("is_data");
  PUInfo_         = ic.consumes<std::vector< PileupSummaryInfo> >(edm::InputTag("slimmedAddPileupInfo"));
  PUReweightfile_ = iConfig.getParameter<edm::FileInPath>("PUReweightfile");
  MinBiasUpReweightfile_ = iConfig.getParameter<edm::FileInPath>("MinBiasUpReweightfile");
  MinBiasDownReweightfile_ = iConfig.getParameter<edm::FileInPath>("MinBiasDownReweightfile");
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  // Get data distribution from file
  const char *filePath = PUReweightfile_.fullPath().c_str();
  TFile file(filePath, "READ");
  TH1* h = NULL;
  file.GetObject("pileup",h);
  if( h == NULL ) {
    std::cerr << "\n\nERROR in PUWeight: Histogram 'pileup' does not exist in file \n.";
    throw std::exception();
  }
  h->SetDirectory(0);
  file.Close();

<<<<<<< HEAD
=======
  // Get MydataUp distribution from file
  const char *MinBiasUpfilePath = MinBiasUpReweightfile_.fullPath().c_str();
  TFile MinBiasUpfile(MinBiasUpfilePath, "READ");
  TH1* MinBiasUphist = NULL;
  MinBiasUpfile.GetObject("pileup",MinBiasUphist);
  if( MinBiasUphist == NULL ) {
    std::cerr << "\n\nERROR in PUWeight: Histogram 'pileup' does not exist in file \n.";
    throw std::exception();
  }
  MinBiasUphist->SetDirectory(0);
  MinBiasUpfile.Close();
  
  // Get MydataDown distribution from file
  const char *MinBiasDownfilePath = MinBiasDownReweightfile_.fullPath().c_str();
  TFile MinBiasDownfile(MinBiasDownfilePath, "READ");
  TH1* MinBiasDownhist = NULL;
  MinBiasDownfile.GetObject("pileup",MinBiasDownhist);
  if( MinBiasDownhist == NULL ) {
    std::cerr << "\n\nERROR in PUWeight: Histogram 'pileup' does not exist in file \n.";
    throw std::exception();
  }
  MinBiasDownhist->SetDirectory(0);
  MinBiasDownfile.Close();
  
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  // Computing weights
  // Store probabilites for each pu bin
  unsigned int nPUMax = 0;
  double *npuProbs = 0;
<<<<<<< HEAD
  if(_year==2018){
    nPUMax =100;
    double npu_[nPUMax] = {4.695341e-10, 1.206213e-06, 1.162593e-06, 6.118058e-06, 1.626767e-05,3.508135e-05, 7.12608e-05, 0.0001400641, 0.0002663403, 0.0004867473,0.0008469, 0.001394142, 0.002169081, 0.003198514, 0.004491138,0.006036423, 0.007806509, 0.00976048, 0.0118498, 0.01402411,0.01623639, 0.01844593, 0.02061956, 0.02273221, 0.02476554,0.02670494, 0.02853662, 0.03024538, 0.03181323, 0.03321895,0.03443884, 0.035448, 0.03622242, 0.03674106, 0.0369877,0.03695224, 0.03663157, 0.03602986, 0.03515857, 0.03403612,0.0326868, 0.03113936, 0.02942582, 0.02757999, 0.02563551,0.02362497, 0.02158003, 0.01953143, 0.01750863, 0.01553934,0.01364905, 0.01186035, 0.01019246, 0.008660705, 0.007275915,0.006043917, 0.004965276, 0.004035611, 0.003246373, 0.002585932,0.002040746, 0.001596402, 0.001238498, 0.0009533139, 0.0007282885,0.000552306, 0.0004158005, 0.0003107302, 0.0002304612, 0.0001696012,0.0001238161, 8.96531e-05, 6.438087e-05, 4.585302e-05, 3.23949e-05,2.271048e-05, 1.580622e-05, 1.09286e-05, 7.512748e-06, 5.140304e-06,3.505254e-06, 2.386437e-06, 1.625859e-06, 1.111865e-06, 7.663272e-07,5.350694e-07, 3.808318e-07, 2.781785e-07, 2.098661e-07, 1.642811e-07,1.312835e-07, 1.081326e-07, 9.141993e-08, 7.890983e-08, 6.91468e-08,6.119019e-08, 5.443693e-08, 4.85036e-08, 4.31486e-08, 3.822112e-08};
    npuProbs = npu_;
  } else if(_year==2017){
    nPUMax =99;
    double npu_[nPUMax] = {3.39597497605e-05,6.63688402133e-06,1.39533611284e-05,3.64963078209e-05,6.00872171664e-05,9.33932578027e-05,0.000120591524486,0.000128694546198,0.000361697233219,0.000361796847553,0.000702474896113,0.00133766053707,0.00237817050805,0.00389825605651,0.00594546732588,0.00856825906255,0.0116627396044,0.0148793350787,0.0179897368379,0.0208723871946,0.0232564170641,0.0249826433945,0.0262245860346,0.0272704617569,0.0283301107549,0.0294006137386,0.0303026836965,0.0309692426278,0.0308818046328,0.0310566806228,0.0309692426278,0.0310566806228,0.0310566806228,0.0310566806228,0.0307696426944,0.0300103336052,0.0288355370103,0.0273233309106,0.0264343533951,0.0255453758796,0.0235877272306,0.0215627588047,0.0195825559393,0.0177296309658,0.0160560731931,0.0146022004183,0.0134080690078,0.0129586991411,0.0125093292745,0.0124360740539,0.0123547104433,0.0123953922486,0.0124360740539,0.0124360740539,0.0123547104433,0.0124360740539,0.0123387597772,0.0122414455005,0.011705203844,0.0108187105305,0.00963985508986,0.00827210065136,0.00683770076341,0.00545237697118,0.00420456901556,0.00367513566191,0.00314570230825,0.0022917978982,0.00163221454973,0.00114065309494,0.000784838366118,0.000533204105387,0.000358474034915,0.000238881117601,0.0001984254989,0.000157969880198,0.00010375646169,6.77366175538e-05,4.39850477645e-05,2.84298066026e-05,1.83041729561e-05,1.17473542058e-05,7.51982735129e-06,6.16160108867e-06,4.80337482605e-06,3.06235473369e-06,1.94863396999e-06,1.23726800704e-06,7.83538083774e-07,4.94602064224e-07,3.10989480331e-07,1.94628487765e-07,1.57888581037e-07,1.2114867431e-07,7.49518929908e-08,4.6060444984e-08,2.81008884326e-08,1.70121486128e-08,1.02159894812e-08};
    npuProbs = npu_;
  } else {
    nPUMax =75;
    double npu_[nPUMax] = {1.78653e-05,2.56602e-05,5.27857e-05,8.88954e-05,0.000109362,0.000140973,0.000240998,0.00071209,0.00130121,0.00245255,0.00502589,0.00919534,0.0146697,0.0204126,0.0267586,0.0337697,0.0401478,0.0450159,0.0490577,0.0524855,0.0548159,0.0559937,0.0554468,0.0537687,0.0512055,0.0476713,0.0435312,0.0393107,0.0349812,0.0307413,0.0272425,0.0237115,0.0208329,0.0182459,0.0160712,0.0142498,0.012804,0.011571,0.010547,0.00959489,0.00891718,0.00829292,0.0076195,0.0069806,0.0062025,0.00546581,0.00484127,0.00407168,0.00337681,0.00269893,0.00212473,0.00160208,0.00117884,0.000859662,0.000569085,0.000365431,0.000243565,0.00015688,9.88128e-05,6.53783e-05,3.73924e-05,2.61382e-05,2.0307e-05,1.73032e-05,1.435e-05,1.36486e-05,1.35555e-05,1.37491e-05,1.34255e-05,1.33987e-05,1.34061e-05,1.34211e-05,1.34177e-05,1.32959e-05,1.33287e-05};
    npuProbs = npu_;
  }
=======
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547

  // Check that binning of data-profile matches MC scenario
  if( nPUMax != static_cast<unsigned int>(h->GetNbinsX()) ) {
    std::cerr << "\n\nERROR number of bins (" << h->GetNbinsX() << ") in data PU-profile does not match number of bins (" << nPUMax << ") in MC scenario " << std::endl;
    throw std::exception();
  }
<<<<<<< HEAD

  std::vector<double> result(nPUMax,0.);
  double s = 0.;
  for(unsigned int npu = 0; npu < nPUMax; ++npu) {
    const double npu_estimated = h->GetBinContent(h->GetXaxis()->FindBin(npu));
    result[npu] = npu_estimated / npuProbs[npu];
    s += npu_estimated;
=======

  if( nPUMax != static_cast<unsigned int>(MinBiasUphist->GetNbinsX()) ) {
    std::cerr << "\n\nERROR number of bins (" << MinBiasUphist->GetNbinsX() << ") in MinBiasUpdata PU-profile does not match number of bins (" << nPUMax << ") in MC scenario " << std::endl;
    throw std::exception();
  }

  if( nPUMax != static_cast<unsigned int>(MinBiasDownhist->GetNbinsX()) ) {
    std::cerr << "\n\nERROR number of bins (" << MinBiasDownhist->GetNbinsX() << ") in MinBiasDowndata PU-profile does not match number of bins (" << nPUMax << ") in MC scenario " << std::endl;
    throw std::exception();
  }

  std::vector<double> result(nPUMax,0.);
  //std::vector<double> Myresult(nPUMax,0.);
  std::vector<double> MinBiasUpresult(nPUMax,0.);
  std::vector<double> MinBiasDownresult(nPUMax,0.);
  double s = 0.;
  double MinBiasUps = 0.;
  double MinBiasDowns = 0.;
  for(unsigned int npu = 0; npu < nPUMax; ++npu) {
    const double npu_estimated = h->GetBinContent(h->GetXaxis()->FindBin(npu));
    const double MinBiasUpnpu_estimated = MinBiasUphist->GetBinContent(h->GetXaxis()->FindBin(npu));
    const double MinBiasDownnpu_estimated = MinBiasDownhist->GetBinContent(h->GetXaxis()->FindBin(npu));
    result[npu] = npu_estimated / npuProbs[npu];
    MinBiasUpresult[npu] = MinBiasUpnpu_estimated / npuProbs[npu];
    MinBiasDownresult[npu] = MinBiasDownnpu_estimated / npuProbs[npu];
    s += npu_estimated;
    MinBiasUps += MinBiasUpnpu_estimated;
    MinBiasDowns += MinBiasDownnpu_estimated;
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  }
  // normalize weights such that the total sum of weights over thw whole sample is 1.0, i.e., sum_i  result[i] * npu_probs[i] should be 1.0 (!)
  for(unsigned int npu = 0; npu < nPUMax; ++npu) {
    result[npu] /= s;
<<<<<<< HEAD
  }

  puWeigths_ = result;
  nPUMax_ = puWeigths_.size();

  // Clean up
  delete h;
=======
    MinBiasUpresult[npu] /= MinBiasUps;
    MinBiasDownresult[npu] /= MinBiasDowns;
  }

  puWeigths_ = result;
  MinBiasUpWeigths_ = MinBiasUpresult;
  MinBiasDownWeigths_ = MinBiasDownresult;
  nPUMax_ = puWeigths_.size();
  MinBiasUpnPUMax_ = MinBiasUpWeigths_.size();
  MinBiasDownnPUMax_ = MinBiasDownWeigths_.size();

  // Clean up
  delete h;
  //delete Myhist;
  delete MinBiasUphist;
  delete MinBiasDownhist;
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547

  SetBranches();
}
PileupReweight::~PileupReweight(){
  delete tree_;
}

void PileupReweight::Fill(const edm::Event& iEvent){
  if(debug_) std::cout<<"getting PileupReweight info"<<std::endl;
  double w = 1.;
<<<<<<< HEAD
=======
  //double Myw = 1.;
  double MinBiasUpw = 1.;
  double MinBiasDownw = 1.;
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  if(!_is_data) {
    Handle<std::vector< PileupSummaryInfo > >  PUInfo;
    iEvent.getByToken(PUInfo_, PUInfo);
    std::vector<PileupSummaryInfo>::const_iterator PVI;
    float nPU = -1;
    for(PVI = PUInfo->begin(); PVI != PUInfo->end(); ++PVI) {
      int BX = PVI->getBunchCrossing();
      if(BX == 0) { 
	nPU = PVI->getTrueNumInteractions();
	continue;
      }
    }
    if(nPU<0) nPU=0;
    if( nPU >= nPUMax_ ) {
      //std::cerr << "WARNING: Number of PU vertices = " << nPU << " out of histogram binning." << std::endl;
      // In case nPU is out-of data-profile binning,
      // use weight from last bin
      w = puWeigths_.back();
    } else {
      w = puWeigths_.at(nPU);
    }
<<<<<<< HEAD
  }
  PUWeight=w;
=======
    if( nPU >= MinBiasUpnPUMax_ ) {
      MinBiasUpw = MinBiasUpWeigths_.back();
    } else {
      MinBiasUpw = MinBiasUpWeigths_.at(nPU);
    }
    if( nPU >= MinBiasDownnPUMax_ ) {
      MinBiasDownw = MinBiasDownWeigths_.back();
    } else {
      MinBiasDownw = MinBiasDownWeigths_.at(nPU);
    }
  }
  PUWeight=w;
  MinBiasUpWeight=MinBiasUpw;
  MinBiasDownWeight=MinBiasDownw;
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
  if(debug_) std::cout<<"got PileupReweight info"<<std::endl;
}
void PileupReweight::SetBranches(){
  if(debug_) std::cout<<"setting branches: calling AddBranch of PileupReweight"<<std::endl;
  AddBranch(&PUWeight,"PUWeight");
<<<<<<< HEAD
=======
  AddBranch(&MinBiasUpWeight,"MinBiasUpWeight");
  AddBranch(&MinBiasDownWeight,"MinBiasDownWeight");
>>>>>>> 16466bedeb36b70d7697022ad54df3ffe33ed547
}

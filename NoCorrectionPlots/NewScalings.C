{
// #######################
// ### Load Data Plots ###
// #######################
TFile *f1 = new TFile("../DataAnalysis/Data_PionXSection_histos_noCorrections.root");


// ###################################
// ### Load Pion Monte Carlo Plots ###
// ###################################
TFile *f2 = new TFile("../PionMC/PionMC_PionXSection_histos_noCorrections_KEWeight.root");

// ### Get the Beam Profile Plot ###
TH1F *hdataWCTrackMomentum = (TH1F*)f1->Get("hdataWCTRKMomentum");

// #### Unit Normalize ####
hdataWCTrackMomentum->Sumw2();
hdataWCTrackMomentum->Scale(1/hdataWCTrackMomentum->Integral());


// ### Get the Monte Carlo Beam Profile Plot ###
TH1F *hMCWCTrackMomentum = (TH1F*)f2->Get("hMCPrimaryPz");

// #### Unit Normalize ####
hMCWCTrackMomentum->Sumw2();
hMCWCTrackMomentum->Scale(1/hMCWCTrackMomentum->Integral());

TH1F* Sub1 = new TH1F(*hMCWCTrackMomentum);

// ### Scaling the MC histogram
Sub1->Sumw2();
Sub1->Scale(-1);


// ### Finding the difference ###
TH1D *Difference = new TH1D("Difference", "P_{z}", 250, 0 , 2500);

Difference->Add(hdataWCTrackMomentum, Sub1);

int nbins = hdataWCTrackMomentum->GetNbinsX();

for(int a=1 ;a< nbins; a++)
   {std::cout<<"entry = "<<a<<", "<<Difference->GetBinContent(a)<<std::endl;}


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "Beam Profile");
c01->SetTicks();
c01->SetFillColor(kWhite);

hdataWCTrackMomentum->SetLineColor(kBlack);
hdataWCTrackMomentum->SetLineStyle(0);
hdataWCTrackMomentum->SetLineWidth(3);

hdataWCTrackMomentum->Draw();
hMCWCTrackMomentum->Draw("same");


}//<---End File

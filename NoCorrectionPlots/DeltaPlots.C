{

// #######################
// ### Load Data Plots ###
// #######################
TFile *f1 = new TFile("../DataAnalysis/Data_PionXSection_histos_noCorrections.root");


// ###################################
// ### Load Pion Monte Carlo Plots ###
// ###################################
//TFile *f2 = new TFile("../PionMC/PionMC_PionXSection_histos_noCorrections.root");
TFile *f2 = new TFile("../PionMC/PionMC_PionXSection_histos_noCorrections_KEWeight.root");


// ######################################################
// ### Load Pion Monte Carlo Plots (old beam weights) ###
// ######################################################
TFile *f3 = new TFile("../PionMC/PionMC_PionXSection_histos_noCorrections_OldEventWeights.root");


//--------------------------------------------------------------------------------------------------------------
//						Beam Profile Plots (New)
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "Beam Profile");
c01->SetTicks();
c01->SetFillColor(kWhite);


// ### Get the Beam Profile Plot ###
TH1F *hdataWCTrackMomentum = (TH1F*)f1->Get("hdataWCTRKMomentum");

// ################################
// ### Formatting the histogram ###
// ################################
hdataWCTrackMomentum->SetLineColor(kBlack);
hdataWCTrackMomentum->SetLineStyle(0);
hdataWCTrackMomentum->SetLineWidth(3);
hdataWCTrackMomentum->SetMarkerStyle(8);
hdataWCTrackMomentum->SetMarkerSize(0.9);

// ### Labeling the axis ###
hdataWCTrackMomentum->GetXaxis()->SetTitle("WC Track Momentum (MeV)");
hdataWCTrackMomentum->GetXaxis()->CenterTitle();

hdataWCTrackMomentum->GetYaxis()->SetTitle("Events / 10 MeV");
hdataWCTrackMomentum->GetYaxis()->CenterTitle();


// ### Get the Monte Carlo Beam Profile Plot ###
TH1F *hMCWCTrackMomentum = (TH1F*)f2->Get("hMCPrimaryPz");

// ################################
// ### Formatting the histogram ###
// ################################
hMCWCTrackMomentum->SetLineColor(kBlue);
hMCWCTrackMomentum->SetLineStyle(0);
hMCWCTrackMomentum->SetLineWidth(3);

// ### Labeling the axis ###
hMCWCTrackMomentum->GetXaxis()->SetTitle("WC Track Momentum (MeV)");
hMCWCTrackMomentum->GetXaxis()->CenterTitle();

hMCWCTrackMomentum->GetYaxis()->SetTitle("Events / 10 MeV");
hMCWCTrackMomentum->GetYaxis()->CenterTitle();


// ### Normalizing MC to Data ###
double MCIntegral = hMCWCTrackMomentum->Integral();
double DataIntegral = hdataWCTrackMomentum->Integral();

double scaleMC = DataIntegral/MCIntegral;

hMCWCTrackMomentum->Sumw2();
hMCWCTrackMomentum->Scale(scaleMC);

hMCWCTrackMomentum->Draw("histo");
hdataWCTrackMomentum->Draw("E1same");


//--------------------------------------------------------------------------------------------------------------
//						Beam Profile Plots (New) Data - MC / Data
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c02 = new TCanvas("c02", "Beam Profile Delta");
c02->SetTicks();
c02->SetFillColor(kWhite);

TH1F* Sub1 = new TH1F(*hMCWCTrackMomentum);

// ### Scaling the MC histogram
Sub1->Sumw2();
Sub1->Scale(-1);

/////////////////////////////////// Primary Particle Pz //////////////////////////////////////////
TH1D *Ratio = new TH1D("Ratio", "P_{z}", 250, 0 , 2500);

TH1D *Difference = new TH1D("Difference", "P_{z}", 250, 0 , 2500);

Difference->Add(hdataWCTrackMomentum, Sub1);
Difference->Sumw2();

Ratio->Divide(Difference,hdataWCTrackMomentum);

// ### Labeling the axis ###
Ratio->GetXaxis()->SetTitle("WC-Track Momentum (MeV)");
Ratio->GetXaxis()->CenterTitle();

Ratio->GetYaxis()->SetTitle("(Data - MC) / Data ");
Ratio->GetYaxis()->CenterTitle();


//AddedHisto->Draw();
Ratio->Draw("histo");


//--------------------------------------------------------------------------------------------------------------
//						Kinetic Energy (New Profile)
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c03 = new TCanvas("c03", "Kineitic Energy");
c03->SetTicks();
c03->SetFillColor(kWhite);

// ### Get the Beam Profile Plot ###
TH1F *hdataInitialKinEng = (TH1F*)f1->Get("hdataInitialKEMomentum");

// ################################
// ### Formatting the histogram ###
// ################################
hdataInitialKinEng->SetLineColor(kBlack);
hdataInitialKinEng->SetLineStyle(0);
hdataInitialKinEng->SetLineWidth(3);
hdataInitialKinEng->SetMarkerStyle(8);
hdataInitialKinEng->SetMarkerSize(0.9);

// ### Labeling the axis ###
hdataInitialKinEng->GetXaxis()->SetTitle("Initial Kinetic Energy (MeV)");
hdataInitialKinEng->GetXaxis()->CenterTitle();

hdataInitialKinEng->GetYaxis()->SetTitle("Events / 5 MeV");
hdataInitialKinEng->GetYaxis()->CenterTitle();


// ### Get the Monte Carlo Beam Profile Plot ###
TH1F *hMCInitialKinEng = (TH1F*)f2->Get("hdataInitialKEMomentum");

// ################################
// ### Formatting the histogram ###
// ################################
hMCInitialKinEng->SetLineColor(kBlue);
hMCInitialKinEng->SetLineStyle(0);
hMCInitialKinEng->SetLineWidth(3);

// ### Labeling the axis ###
hMCInitialKinEng->GetXaxis()->SetTitle("Initial Kinetic Energy (MeV)");
hMCInitialKinEng->GetXaxis()->CenterTitle();

hMCInitialKinEng->GetYaxis()->SetTitle("Events / 5 MeV");
hMCInitialKinEng->GetYaxis()->CenterTitle();


// ### Normalizing MC to Data ###
double MCIntegralKE = hMCInitialKinEng->Integral();
double DataIntegralKE = hdataInitialKinEng->Integral();

double scaleMCKE = DataIntegralKE/MCIntegralKE;

hMCInitialKinEng->Sumw2();
hMCInitialKinEng->Scale(scaleMCKE);

hdataInitialKinEng->Draw("E1");
hMCInitialKinEng->Draw("histosame");


//--------------------------------------------------------------------------------------------------------------
//						Beam Profile Plots (New) Data - MC / Data
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c04 = new TCanvas("c04", "KE Delta");
c04->SetTicks();
c04->SetFillColor(kWhite);

TH1F* Sub2 = new TH1F(*hMCInitialKinEng);

// ### Scaling the MC histogram
Sub2->Sumw2();
Sub2->Scale(-1);

/////////////////////////////////// Primary Particle Pz //////////////////////////////////////////
TH1D *Ratio2 = new TH1D("Ratio2", "KE", 500, 0 , 2500);

TH1D *Difference2 = new TH1D("Difference2", "KE", 500, 0 , 2500);

Difference2->Add(hdataInitialKinEng, Sub2);
Difference2->Sumw2();

Ratio2->Divide(Difference2,hdataInitialKinEng);

// ### Labeling the axis ###
Ratio2->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
Ratio2->GetXaxis()->CenterTitle();

Ratio2->GetYaxis()->SetTitle("(Data - MC) / Data ");
Ratio2->GetYaxis()->CenterTitle();


//AddedHisto->Draw();
Ratio2->Draw("E1");



//--------------------------------------------------------------------------------------------------------------
//						Theta (New Profile)
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c05 = new TCanvas("c05", "Theta");
c05->SetTicks();
c05->SetFillColor(kWhite);

// ### Get the Track Upstream Theta Point ###
TH1F *hdataTheta = (TH1F*)f1->Get("hdataTPCTheta");

// ################################
// ### Formatting the histogram ###
// ################################
hdataTheta->SetLineColor(kBlack);
hdataTheta->SetLineStyle(0);
hdataTheta->SetLineWidth(3);
hdataTheta->SetMarkerStyle(8);
hdataTheta->SetMarkerSize(0.9);

// ### Labeling the axis ###
hdataTheta->GetXaxis()->SetTitle("#theta (TPC Track initial point)");
hdataTheta->GetXaxis()->CenterTitle();

hdataTheta->GetYaxis()->SetTitle("Events / 0.5 degree");
hdataTheta->GetYaxis()->CenterTitle();


// ### Get the Monte Carlo Beam Profile Plot ###
TH1F *hMCTheta = (TH1F*)f2->Get("hdataTPCTheta");

// ################################
// ### Formatting the histogram ###
// ################################
hMCTheta->SetLineColor(kBlue);
hMCTheta->SetLineStyle(0);
hMCTheta->SetLineWidth(3);

// ### Labeling the axis ###
hMCTheta->GetXaxis()->SetTitle("#theta (TPC Track initial point)");
hMCTheta->GetXaxis()->CenterTitle();

hMCTheta->GetYaxis()->SetTitle("Events / 0.5 degree");
hMCTheta->GetYaxis()->CenterTitle();


// ### Normalizing MC to Data ###
double MCIntegralTheta = hMCTheta->Integral();
double DataIntegralTheta = hdataTheta->Integral();

double scaleMCTheta = DataIntegralTheta/MCIntegralTheta;

hMCTheta->Sumw2();
hMCTheta->Scale(scaleMCTheta);

hdataTheta->Draw("E1");
hMCTheta->Draw("histosame");



//--------------------------------------------------------------------------------------------------------------
//						Phi (New Profile)
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c06 = new TCanvas("c06", "Phi");
c06->SetTicks();
c06->SetFillColor(kWhite);

// ### Get the Track Upstream Theta Point ###
TH1F *hdataPhi = (TH1F*)f1->Get("hdataTPCPhi");

// ################################
// ### Formatting the histogram ###
// ################################
hdataPhi->SetLineColor(kBlack);
hdataPhi->SetLineStyle(0);
hdataPhi->SetLineWidth(3);
hdataPhi->SetMarkerStyle(8);
hdataPhi->SetMarkerSize(0.9);

// ### Labeling the axis ###
hdataPhi->GetXaxis()->SetTitle("#phi (TPC Track initial point)");
hdataPhi->GetXaxis()->CenterTitle();

hdataPhi->GetYaxis()->SetTitle("Events / 0.5 degree");
hdataPhi->GetYaxis()->CenterTitle();


// ### Get the Monte Carlo Beam Profile Plot ###
TH1F *hMCPhi = (TH1F*)f2->Get("hdataTPCPhi");

// ################################
// ### Formatting the histogram ###
// ################################
hMCPhi->SetLineColor(kBlue);
hMCPhi->SetLineStyle(0);
hMCPhi->SetLineWidth(3);

// ### Labeling the axis ###
hMCPhi->GetXaxis()->SetTitle("#phi (TPC Track initial point)");
hMCPhi->GetXaxis()->CenterTitle();

hMCPhi->GetYaxis()->SetTitle("Events / 0.5 degree");
hMCPhi->GetYaxis()->CenterTitle();


// ### Normalizing MC to Data ###
double MCIntegralPhi = hMCPhi->Integral();
double DataIntegralPhi = hdataPhi->Integral();

double scaleMCPhi = DataIntegralPhi/MCIntegralPhi;

hMCPhi->Sumw2();
hMCPhi->Scale(scaleMCPhi);

hdataPhi->Draw("E1");
hMCPhi->Draw("histosame");



//--------------------------------------------------------------------------------------------------------------
//						Initial X Position (New Profile)
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c07 = new TCanvas("c07", "Inital X");
c07->SetTicks();
c07->SetFillColor(kWhite);

// ### Get the Track Upstream Theta Point ###
TH1F *hdataTPCXi = (TH1F*)f1->Get("hdataTrkInitialX");

// ################################
// ### Formatting the histogram ###
// ################################
hdataTPCXi->SetLineColor(kBlack);
hdataTPCXi->SetLineStyle(0);
hdataTPCXi->SetLineWidth(3);
hdataTPCXi->SetMarkerStyle(8);
hdataTPCXi->SetMarkerSize(0.9);

// ### Labeling the axis ###
hdataTPCXi->GetXaxis()->SetTitle("TPC Track X_{i} (cm)");
hdataTPCXi->GetXaxis()->CenterTitle();

hdataTPCXi->GetYaxis()->SetTitle("Events / 0.5 cm");
hdataTPCXi->GetYaxis()->CenterTitle();


// ### Get the Monte Carlo Beam Profile Plot ###
TH1F *hMCTPCXi = (TH1F*)f2->Get("hdataTrkInitialX");

// ################################
// ### Formatting the histogram ###
// ################################
hMCTPCXi->SetLineColor(kBlue);
hMCTPCXi->SetLineStyle(0);
hMCTPCXi->SetLineWidth(3);

// ### Labeling the axis ###
hMCTPCXi->GetXaxis()->SetTitle("TPC Track X_{i} (cm)");
hMCTPCXi->GetXaxis()->CenterTitle();

hMCTPCXi->GetYaxis()->SetTitle("Events / 0.5 cm");
hMCTPCXi->GetYaxis()->CenterTitle();


// ### Normalizing MC to Data ###
double MCIntegralXi = hMCTPCXi->Integral();
double DataIntegralXi = hdataTPCXi->Integral();

double scaleMCXi = DataIntegralXi/MCIntegralXi;

hMCTPCXi->Sumw2();
hMCTPCXi->Scale(scaleMCXi);

hdataTPCXi->Draw("E1");
hMCTPCXi->Draw("histosame");


//--------------------------------------------------------------------------------------------------------------
//						Initial Y Position (New Profile)
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c08 = new TCanvas("c08", "Inital Y");
c08->SetTicks();
c08->SetFillColor(kWhite);

// ### Get the Track Upstream Theta Point ###
TH1F *hdataTPCYi = (TH1F*)f1->Get("hdataTrkInitialY");

// ################################
// ### Formatting the histogram ###
// ################################
hdataTPCYi->SetLineColor(kBlack);
hdataTPCYi->SetLineStyle(0);
hdataTPCYi->SetLineWidth(3);
hdataTPCYi->SetMarkerStyle(8);
hdataTPCYi->SetMarkerSize(0.9);

// ### Labeling the axis ###
hdataTPCYi->GetXaxis()->SetTitle("TPC Track Y_{i} (cm)");
hdataTPCYi->GetXaxis()->CenterTitle();

hdataTPCYi->GetYaxis()->SetTitle("Events / 0.5 cm");
hdataTPCYi->GetYaxis()->CenterTitle();


// ### Get the Monte Carlo Beam Profile Plot ###
TH1F *hMCTPCYi = (TH1F*)f2->Get("hdataTrkInitialY");

// ################################
// ### Formatting the histogram ###
// ################################
hMCTPCYi->SetLineColor(kBlue);
hMCTPCYi->SetLineStyle(0);
hMCTPCYi->SetLineWidth(3);

// ### Labeling the axis ###
hMCTPCYi->GetXaxis()->SetTitle("TPC Track Y_{i} (cm)");
hMCTPCYi->GetXaxis()->CenterTitle();

hMCTPCYi->GetYaxis()->SetTitle("Events / 0.5 cm");
hMCTPCYi->GetYaxis()->CenterTitle();


// ### Normalizing MC to Data ###
double MCIntegralYi = hMCTPCYi->Integral();
double DataIntegralYi = hdataTPCYi->Integral();

double scaleMCYi = DataIntegralYi/MCIntegralYi;

hMCTPCYi->Sumw2();
hMCTPCYi->Scale(scaleMCYi);

hdataTPCYi->Draw("E1");
hMCTPCYi->Draw("histosame");

}//<---End File

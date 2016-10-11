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

//--------------------------------------------------------------------------------------------------------------
//						Delta X WC-TPC Track
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data Delta X plot ###
TH1F *hDataDeltaXMatch = (TH1F*)f1->Get("hdataDeltaWCTrkX");

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "Delta X");
c01->SetTicks();
c01->SetFillColor(kWhite);


// ################################
// ### Formatting the histogram ###
// ################################
hDataDeltaXMatch->SetLineColor(kBlack);
hDataDeltaXMatch->SetLineStyle(0);
hDataDeltaXMatch->SetLineWidth(3);
hDataDeltaXMatch->SetMarkerStyle(8);
hDataDeltaXMatch->SetMarkerSize(0.9);

// ### Labeling the axis ###
hDataDeltaXMatch->GetXaxis()->SetTitle("#DeltaX between WC/TPC Track (cm)");
hDataDeltaXMatch->GetXaxis()->CenterTitle();

hDataDeltaXMatch->GetYaxis()->SetTitle("Events / 0.5 cm");
hDataDeltaXMatch->GetYaxis()->CenterTitle();

// ######################################################################
// ### Calling the two gaussians I use to fit the different regions ###
// ######################################################################

// ==================================================
// == Initializing the parameters which record the ==
// ==     fit parameters (3 for each gaussian)     ==
// ==================================================
Double_t par_01[6];
TF1 *rightMatch_01 = new TF1("rightMatch_01","gaus",-6,6);
TF1 *wrongMatch_01 = new TF1("wrongMatch_01","gaus",-30,10);
TF1 *combined_01   = new TF1("combined_01","gaus(0)+gaus(3)",-30,30);

// ### Fitting the Right Match Data ###
hDataDeltaXMatch->Fit(rightMatch_01,"R+0LLi","0",-1.0, 4.5);
rightMatch_01->GetParameters(&par_01[0]); //<---Getting parameters from fit 0,1,2

hDataDeltaXMatch->Fit(wrongMatch_01,"R+0LLi","0",-30, 10);
wrongMatch_01->GetParameters(&par_01[3]); //<---Getting parameters from fit 0,1,2



// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_01->SetParameters(par_01);
combined_01->SetParLimits(4,-6,6);

combined_01->SetParName(0,"RM: Norm");
combined_01->SetParName(1,"RM: Mean");
combined_01->SetParName(2,"RM: RMS");
combined_01->SetParName(3,"WM: Norm");
combined_01->SetParName(4,"WM: Mean");
combined_01->SetParName(5,"WM: RMS");

// ### Drawing the histogram ###
hDataDeltaXMatch->Draw("E1");

hDataDeltaXMatch->Fit(combined_01,"R0LLi","0",-30,30);

// === Inputting Parameters for Drawing Fits ====
combined_01->GetParameters(par_01);
rightMatch_01->SetParameters(&par_01[0]);
wrongMatch_01->SetParameters(&par_01[3]);

combined_01->SetRange(-30,30);
TH1D* combined_histo = (TH1D*)combined_01->GetHistogram();
combined_histo->SetFillColor(kBlue);
combined_histo->SetFillStyle(3005);
combined_histo->SetLineColor(kBlue);
combined_histo->SetLineWidth(2);
combined_histo->Draw("Csames");

TH1D *wrong_histo1 = new TH1D("wrong_histo1","wrong_histo1",1000,-10,10);
wrongMatch_01->SetRange(-30,30);
wrong_histo1 = (TH1D*)wrongMatch_01->GetHistogram();
wrong_histo1->SetFillColor(kRed);
wrong_histo1->SetFillStyle(3005);
wrong_histo1->SetLineWidth(2);
wrong_histo1->SetLineColor(kRed);
wrong_histo1->SetMarkerColor(kRed);
wrong_histo1->Draw("Csame");

// ### Drawing the histogram ###
hDataDeltaXMatch->Draw("E1same");

c01->Update();
gPad->RedrawAxis();

// ############################
// # Setting the Latex Header #
// ############################
TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,"");

TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("Run-I Data");
leg->AddEntry(hDataDeltaXMatch,"Data");
leg->AddEntry(combined_histo,"Right Match"); 
leg->AddEntry(wrong_histo1,"Wrong Match");
leg->Draw();


//--------------------------------------------------------------------------------------------------------------
//						Delta Y WC-TPC Track
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data Delta X plot ###
TH1F *hDataDeltaYMatch = (TH1F*)f1->Get("hdataDeltaWCTrkY");

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c02 = new TCanvas("c02", "Delta Y");
c02->SetTicks();
c02->SetFillColor(kWhite);


// ################################
// ### Formatting the histogram ###
// ################################
hDataDeltaYMatch->SetLineColor(kBlack);
hDataDeltaYMatch->SetLineStyle(0);
hDataDeltaYMatch->SetLineWidth(3);
hDataDeltaYMatch->SetMarkerStyle(8);
hDataDeltaYMatch->SetMarkerSize(0.9);

// ### Labeling the axis ###
hDataDeltaYMatch->GetXaxis()->SetTitle("#DeltaY between WC/TPC Track (cm)");
hDataDeltaYMatch->GetXaxis()->CenterTitle();

hDataDeltaYMatch->GetYaxis()->SetTitle("Events / 0.5 cm");
hDataDeltaYMatch->GetYaxis()->CenterTitle();

// ######################################################################
// ### Calling the two gaussians I use to fit the different regions ###
// ######################################################################

// ==================================================
// == Initializing the parameters which record the ==
// ==     fit parameters (3 for each gaussian)     ==
// ==================================================
Double_t par_02[6];
TF1 *rightMatch_02 = new TF1("rightMatch_02","gaus",-6,6);
TF1 *wrongMatch_02 = new TF1("wrongMatch_02","gaus",-30,10);
TF1 *combined_02   = new TF1("combined_02","gaus(0)+gaus(3)",-30,30);

// ### Fitting the Right Match Data ###
hDataDeltaYMatch->Fit(rightMatch_02,"R+0LLi","0",-1.0, 4.5);
rightMatch_02->GetParameters(&par_02[0]); //<---Getting parameters from fit 0,1,2

hDataDeltaYMatch->Fit(wrongMatch_02,"R+0LLi","0",-30, 10);
wrongMatch_02->GetParameters(&par_02[3]); //<---Getting parameters from fit 0,1,2



// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_02->SetParameters(par_01);
combined_02->SetParLimits(4,-6,6);

combined_02->SetParName(0,"RM: Norm");
combined_02->SetParName(1,"RM: Mean");
combined_02->SetParName(2,"RM: RMS");
combined_02->SetParName(3,"WM: Norm");
combined_02->SetParName(4,"WM: Mean");
combined_02->SetParName(5,"WM: RMS");

// ### Drawing the histogram ###
hDataDeltaYMatch->Draw("E1");

hDataDeltaYMatch->Fit(combined_02,"R0LLi","0",-30,30);

// === Inputting Parameters for Drawing Fits ====
combined_02->GetParameters(par_02);
rightMatch_02->SetParameters(&par_02[0]);
wrongMatch_02->SetParameters(&par_02[3]);

combined_02->SetRange(-30,30);
TH1D* combined_histo2 = (TH1D*)combined_02->GetHistogram();
combined_histo2->SetFillColor(kBlue);
combined_histo2->SetFillStyle(3005);
combined_histo2->SetLineColor(kBlue);
combined_histo2->SetLineWidth(2);
combined_histo2->Draw("Csames");

TH1D *wrong_histo2 = new TH1D("wrong_histo2","wrong_histo1",1000,-10,10);
wrongMatch_02->SetRange(-30,30);
wrong_histo2 = (TH1D*)wrongMatch_02->GetHistogram();
wrong_histo2->SetFillColor(kRed);
wrong_histo2->SetFillStyle(3005);
wrong_histo2->SetLineWidth(2);
wrong_histo2->SetLineColor(kRed);
wrong_histo2->SetMarkerColor(kRed);
wrong_histo2->Draw("Csame");

// ### Drawing the histogram ###
hDataDeltaYMatch->Draw("E1same");

c02->Update();
gPad->RedrawAxis();

// ############################
// # Setting the Latex Header #
// ############################
//TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,"");

//TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("Run-I Data");
leg->AddEntry(hDataDeltaYMatch,"Data");
leg->AddEntry(combined_histo2,"Right Match"); 
leg->AddEntry(wrong_histo2,"Wrong Match");
leg->Draw();


//--------------------------------------------------------------------------------------------------------------
//						Alpha
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data Delta X plot ###
TH1F *hAlpha = (TH1F*)f1->Get("hdataAlpha");

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c03 = new TCanvas("c03", "Alpha");
c03->SetTicks();
c03->SetFillColor(kWhite);


// ################################
// ### Formatting the histogram ###
// ################################
hAlpha->SetLineColor(kBlack);
hAlpha->SetLineStyle(0);
hAlpha->SetLineWidth(3);
hAlpha->SetMarkerStyle(8);
hAlpha->SetMarkerSize(0.9);

// ### Labeling the axis ###
hAlpha->GetXaxis()->SetTitle("#alpha (Degrees)");
hAlpha->GetXaxis()->CenterTitle();

hAlpha->GetYaxis()->SetTitle("Events / Degree");
hAlpha->GetYaxis()->CenterTitle();

// ### Drawing the histogram ###
hAlpha->Draw("E1");


// ############################
// # Setting the Latex Header #
// ############################
//TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,"");


//--------------------------------------------------------------------------------------------------------------
//						dE/dX Plots
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data dE/dX plot ###
TH1F *hDatadEdX = (TH1F*)f1->Get("hdataPiondEdX");

// ### Labeling the axis ###
hDatadEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hDatadEdX->GetXaxis()->CenterTitle();

hDatadEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hDatadEdX->GetYaxis()->CenterTitle(); 

// ### Getting the MC dE/dX plot ###
TH1F *hMCdEdX = (TH1F*)f2->Get("hdataPiondEdX");

// ### Labeling the axis ###
hMCdEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hMCdEdX->GetXaxis()->CenterTitle();

hDatadEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hDatadEdX->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegral = hMCdEdX->Integral();
double DataIntegral = hDatadEdX->Integral();

double scaleMC = DataIntegral/MCIntegral;


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t par_03[6];
TF1 *data_dedx_landau = new TF1("data_dedx_landau","landau",0, 50);
TF1 *combined_data_dedx   = new TF1("combined_data_dedx","landau+gaus",0,50);


TF1 *mc_dedx_landau   = new TF1("mc_dedx_landau","landau",0, 50);
TF1 *combined_mc_dedx   = new TF1("combined_mc_dedx","landau+gaus",0,50);

// ### Scaling MC ###
hMCdEdX->Sumw2();
hMCdEdX->Scale(scaleMC);

// ### Fitting the data dE/dX with Landau as a seed ###
hDatadEdX->Fit(data_dedx_landau,"R+0LLi","0",0, 50);

// ### Get the seed parameters for the Landau+Gaus fit ###
data_dedx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2


// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_data_dedx->SetParameters(par_03);
combined_data_dedx->SetParLimits(0,0,900000);


// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================
hDatadEdX->Fit(combined_data_dedx,"R0LLi","0",0,50);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_data_dedx->GetParameters(par_03);
combined_data_dedx->SetRange(0,50);
TH1D* dataFit_histo = (TH1D*)combined_data_dedx->GetHistogram();
dataFit_histo->SetFillColor(kBlack);
dataFit_histo->SetFillStyle(3005);
dataFit_histo->SetLineColor(kBlack);
dataFit_histo->SetLineWidth(2);


// ### Fitting the MC dE/dX with Landau as a seed ###
hMCdEdX->Fit(mc_dedx_landau,"R+0LLi","0",0 , 50);

// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dedx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2

// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_mc_dedx->SetParameters(par_03);
combined_mc_dedx->SetParLimits(0,0,900000);

// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================
hMCdEdX->Fit(combined_mc_dedx,"R0LLi","0",0,50);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_mc_dedx->GetParameters(par_03);
combined_mc_dedx->SetRange(0,50);
TH1D* MCFit_histo = (TH1D*)combined_mc_dedx->GetHistogram();
MCFit_histo->SetFillColor(kCyan-9);
MCFit_histo->SetFillStyle(3002);
MCFit_histo->SetLineColor(kCyan-9);
MCFit_histo->SetLineWidth(2);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c04 = new TCanvas("c04", "dEdX");
c04->SetTicks();
c04->SetFillColor(kWhite);


hMCdEdX->SetLineColor(kBlue);
hMCdEdX->SetLineStyle(0);
hMCdEdX->SetLineWidth(3);

hDatadEdX->SetLineColor(kBlack);
hDatadEdX->SetLineStyle(0);
hDatadEdX->SetLineWidth(3);
hDatadEdX->SetMarkerStyle(8);
hDatadEdX->SetMarkerSize(0.9);


// ### Drawing the histograms ###
hMCdEdX->Draw("histo");
dataFit_histo->Draw("Csames");
MCFit_histo->Draw("Csames");
hDatadEdX->Draw("E1same");


// ############################
// # Setting the Latex Header #
// ############################
//TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


//TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("Run-I Data");
leg->AddEntry(hDatadEdX,"Data");
leg->AddEntry(hMCdEdX,"#pi^{-} MC"); 
leg->AddEntry(dataFit_histo,"Data Fit: MPV = 1.68 #sigma 0.17");
leg->AddEntry(MCFit_histo," MC  Fit: MPV = 1.80 #sigma 0.24");
leg->Draw();




//--------------------------------------------------------------------------------------------------------------
//					Incident Kinetic Energy Plots
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data Incident Kinetic Energy plot ###
TH1F *hDataInKE = (TH1F*)f1->Get("hdataIncidentKE");

// ### Labeling the axis ###
hDataInKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hDataInKE->GetXaxis()->CenterTitle();

hDataInKE->GetYaxis()->SetTitle("Events / 50 MeV");
hDataInKE->GetYaxis()->CenterTitle(); 

// ########################################################
// ###      Scaling factor for through going muon       ###
// ### Note: If you have a 10% contamination than your  ###
// ###            scale factor should be 0.90           ###
// ########################################################
double MuonContaminationScaleFactor = 0.90;
    
// ===============================================================================================================
// 					SCALING FOR THE MUON CONTAMINATION
// ==========================================================================================================
    
hDataInKE->Scale(MuonContaminationScaleFactor);

// ### Getting the MC Incident Kinetic Energy plot ###
TH1F *hMCInKE = (TH1F*)f2->Get("hdataIncidentKE");

// ### Labeling the axis ###
hMCInKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hMCInKE->GetXaxis()->CenterTitle();

hMCInKE->GetYaxis()->SetTitle("Events / 50 MeV");
hMCInKE->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegralInKE = hMCInKE->Integral();
double DataIntegralDataInKE = hDataInKE->Integral();

double scaleMCInKE = DataIntegralDataInKE/MCIntegralInKE;

std::cout<<"scaleMCInKE = "<<scaleMCInKE<<std::endl;

// ### Scaling MC ###
hMCInKE->Sumw2();
hMCInKE->Scale(scaleMCInKE);
//hMCInKE->Scale(5.27729);

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c05 = new TCanvas("c05", "Incident Kinetic Energy");
c05->SetTicks();
c05->SetFillColor(kWhite);


hMCInKE->SetLineColor(kRed+2);
hMCInKE->SetLineStyle(0);
hMCInKE->SetLineWidth(3);
hMCInKE->SetFillColor(kRed+2);
hMCInKE->SetFillStyle(3006);

hDataInKE->SetLineColor(kBlack);
hDataInKE->SetLineStyle(0);
hDataInKE->SetLineWidth(3);
hDataInKE->SetMarkerStyle(8);
hDataInKE->SetMarkerSize(0.9);

// ### Drawing the histograms ###
hMCInKE->Draw("histo");
hDataInKE->Draw("E1same");

// ############################
// # Setting the Latex Header #
// ############################
//TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


//TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("Run-I Data");
leg->AddEntry(hDataInKE,"Data");
leg->AddEntry(hMCInKE,"#pi^{-} MC"); 
//leg->AddEntry(dataFit_histo,"Data Fit: MPV = 1.68 #sigma 0.17");
//leg->AddEntry(MCFit_histo," MC  Fit: MPV = 1.80 #sigma 0.24");
leg->Draw();








//--------------------------------------------------------------------------------------------------------------
//					Interacting Kinetic Energy Plots
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data Incident Kinetic Energy plot ###
TH1F *hDataIntKE = (TH1F*)f1->Get("hdataInteractingKE");

// ### Labeling the axis ###
hDataIntKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hDataIntKE->GetXaxis()->CenterTitle();

hDataIntKE->GetYaxis()->SetTitle("Events / 50 MeV");
hDataIntKE->GetYaxis()->CenterTitle(); 


// ### Getting the MC Incident Kinetic Energy plot ###
TH1F *hMCIntKE = (TH1F*)f2->Get("hdataInteractingKE");

// ### Labeling the axis ###
hMCIntKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hMCIntKE->GetXaxis()->CenterTitle();

hMCIntKE->GetYaxis()->SetTitle("Events / 50 MeV");
hMCIntKE->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegralIntKE = hMCIntKE->Integral();
double DataIntegralDataIntKE = hDataIntKE->Integral();

double scaleMCIntKE = DataIntegralDataIntKE/MCIntegralIntKE;

std::cout<<"scaleMCIntKE = "<<scaleMCIntKE<<std::endl;

// ### Scaling MC ###
hMCIntKE->Sumw2();
//hMCIntKE->Scale(scaleMCInKE);
hMCIntKE->Scale(scaleMCIntKE);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c06 = new TCanvas("c06", "Interacting Kinetic Energy");
c06->SetTicks();
c06->SetFillColor(kWhite);


hMCIntKE->SetLineColor(kGreen+3);
hMCIntKE->SetLineStyle(0);
hMCIntKE->SetLineWidth(3);
hMCIntKE->SetFillColor(kGreen+3);
hMCIntKE->SetFillStyle(3006);

hDataIntKE->SetLineColor(kBlack);
hDataIntKE->SetLineStyle(0);
hDataIntKE->SetLineWidth(3);
hDataIntKE->SetMarkerStyle(8);
hDataIntKE->SetMarkerSize(0.9);

// ### Drawing the histograms ###
hDataIntKE->Draw("E1");
hMCIntKE->Draw("histosame");
//hDataIntKE->Draw("E1same");

// ############################
// # Setting the Latex Header #
// ############################
//TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


//TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("Run-I Data");
leg->AddEntry(hDataIntKE,"Data");
leg->AddEntry(hMCIntKE,"#pi^{-} MC"); 
//leg->AddEntry(dataFit_histo,"Data Fit: MPV = 1.68 #sigma 0.17");
//leg->AddEntry(MCFit_histo," MC  Fit: MPV = 1.80 #sigma 0.24");
leg->Draw();



//--------------------------------------------------------------------------------------------------------------
//					Track Pitch
//--------------------------------------------------------------------------------------------------------------


// ### Getting the data Incident Kinetic Energy plot ###
TH1F *hDataTrkPitch = (TH1F*)f1->Get("hdataPionTrkPitch");

// ### Labeling the axis ###
hDataTrkPitch->GetXaxis()->SetTitle("Track Pitch (cm)");
hDataTrkPitch->GetXaxis()->CenterTitle();

hDataTrkPitch->GetYaxis()->SetTitle("Events / 0.005 cm");
hDataTrkPitch->GetYaxis()->CenterTitle(); 

// ### Getting the MC Incident Kinetic Energy plot ###
TH1F *hMCTrkPitch = (TH1F*)f2->Get("hdataPionTrkPitch");

// ### Labeling the axis ###
hMCTrkPitch->GetXaxis()->SetTitle("Track Pitch (cm)");
hMCTrkPitch->GetXaxis()->CenterTitle();

hMCTrkPitch->GetYaxis()->SetTitle("Events / 0.005 cm");
hMCTrkPitch->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegralTrkPitch = hMCTrkPitch->Integral();
double DataIntegralTrkPitch = hDataTrkPitch->Integral();

double scaleMCTrkPitch = DataIntegralTrkPitch/MCIntegralTrkPitch;

// ### Scaling MC ###
hMCTrkPitch->Sumw2();
hMCTrkPitch->Scale(scaleMCTrkPitch);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c07 = new TCanvas("c07", "Track Pitch");
c07->SetTicks();
c07->SetFillColor(kWhite);

hMCTrkPitch->SetLineColor(kBlue);
hMCTrkPitch->SetLineStyle(0);
hMCTrkPitch->SetLineWidth(3);
hMCTrkPitch->SetFillColor(kBlue);
hMCTrkPitch->SetFillStyle(3006);

hDataTrkPitch->SetLineColor(kBlack);
hDataTrkPitch->SetLineStyle(0);
hDataTrkPitch->SetLineWidth(3);
hDataTrkPitch->SetMarkerStyle(8);
hDataTrkPitch->SetMarkerSize(0.9);

// ### Drawing the histograms ###
hMCTrkPitch->Draw("histo");
hDataTrkPitch->Draw("E1same");

// ############################
// # Setting the Latex Header #
// ############################
//TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


//TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("Run-I Data");
leg->AddEntry(hDataTrkPitch,"Data");
leg->AddEntry(hMCTrkPitch,"#pi^{-} MC"); 
//leg->AddEntry(dataFit_histo,"Data Fit: MPV = 1.68 #sigma 0.17");
//leg->AddEntry(MCFit_histo," MC  Fit: MPV = 1.80 #sigma 0.24");
leg->Draw();



//--------------------------------------------------------------------------------------------------------------
//					TOF vs Pz
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data Incident Kinetic Energy plot ###
TH2F *hTOFvsWCTrk = (TH2F*)f1->Get("hdataWCTrackMomentumVSTOF");

// ### Labeling the axis ###
hTOFvsWCTrk->GetXaxis()->SetTitle("WC Track Momentum (MeV)");
hTOFvsWCTrk->GetXaxis()->CenterTitle();

hTOFvsWCTrk->GetYaxis()->SetTitle("TOF (ns)");
hTOFvsWCTrk->GetYaxis()->CenterTitle();

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c08 = new TCanvas("c08", "TOF vs WC Track");
c08->SetTicks();
c08->SetFillColor(kWhite);

// ### Drawing the histograms ###
hTOFvsWCTrk->Draw("colz");

// ############################
// # Setting the Latex Header #
// ############################
//TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


//--------------------------------------------------------------------------------------------------------------
//					Track Length
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data Incident Kinetic Energy plot ###
TH1F *hDataTrkLength = (TH1F*)f1->Get("hRecoLength");

// ### Labeling the axis ###
hDataTrkLength->GetXaxis()->SetTitle("Track Length (cm)");
hDataTrkLength->GetXaxis()->CenterTitle();

hDataTrkLength->GetYaxis()->SetTitle("Events / 0.5 cm");
hDataTrkLength->GetYaxis()->CenterTitle(); 

// ### Getting the MC Incident Kinetic Energy plot ###
TH1F *hMCTrkLength = (TH1F*)f2->Get("hRecoLength");

// ### Labeling the axis ###
hMCTrkLength->GetXaxis()->SetTitle("Track Length (cm)");
hMCTrkLength->GetXaxis()->CenterTitle();

hMCTrkLength->GetYaxis()->SetTitle("Events / 0.5 cm");
hMCTrkLength->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegralTrkLength = hMCTrkLength->Integral();
double DataIntegralTrkLength = hDataTrkLength->Integral();

double scaleMCTrkLength = DataIntegralTrkLength/MCIntegralTrkLength;

// ### Scaling MC ###
hMCTrkLength->Sumw2();
hMCTrkLength->Scale(scaleMCTrkPitch);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c09 = new TCanvas("c09", "Track Length");
c09->SetTicks();
c09->SetFillColor(kWhite);

hMCTrkLength->SetLineColor(kBlue);
hMCTrkLength->SetLineStyle(0);
hMCTrkLength->SetLineWidth(3);
hMCTrkLength->SetFillColor(kBlue);
hMCTrkLength->SetFillStyle(3006);

hDataTrkLength->SetLineColor(kBlack);
hDataTrkLength->SetLineStyle(0);
hDataTrkLength->SetLineWidth(3);
hDataTrkLength->SetMarkerStyle(8);
hDataTrkLength->SetMarkerSize(0.9);

// ### Drawing the histograms ###
hMCTrkLength->Draw("histo");
hDataTrkLength->Draw("E1same");

// ############################
// # Setting the Latex Header #
// ############################
//TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


//TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("Run-I Data");
leg->AddEntry(hDataTrkLength,"Data");
leg->AddEntry(hMCTrkLength,"#pi^{-} MC"); 
//leg->AddEntry(dataFit_histo,"Data Fit: MPV = 1.68 #sigma 0.17");
//leg->AddEntry(MCFit_histo," MC  Fit: MPV = 1.80 #sigma 0.24");
leg->Draw();



}//<---End file

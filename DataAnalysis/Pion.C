#define Pion_cxx
#include "Pion.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
//This is the macro for the new MC

//Step 2b:
//New beam profile and calo bugs correction
//Stopping particles tagging

// Updated BeamProfile (WC run I Neg) Pz: 0 - 2500 MeV/C: for Pion Candidate events (beamline PID and TPC selections)

//Calo bugs correction: 
//- dEdx ordered
//- interpolation of nearby caloPts when dEdx > 40 MeV/cm || (dEdx > 15MeV/cm && RR > 10 cm)
//- negative dEdx of last caloHit (anatree default) - remove this hit

//instead of tagging PiDecay and PiCapture events from MCtruth, 
//use Stopping particles tagging and remove the enpoint of these events from Nint

//Compare MCTruth/MCreco tracklength and deltaE

//
// ===================================================================================================================
// ====================================       PUT HISTOGRAMS HERE           ==========================================
// ===================================================================================================================

/////////////////////////////////// Primary Particle Start X Position //////////////////////////////////////////
TH1D *hMCPrimaryStartX = new TH1D("hMCPrimaryStartX", "Primary Particle X_{0}", 200, -50 , 50);
/////////////////////////////////// Primary Particle Start Y Position //////////////////////////////////////////
TH1D *hMCPrimaryStartY = new TH1D("hMCPrimaryStartY", "Primary Particle Y_{0}", 200, -50 , 50);
/////////////////////////////////// Primary Particle Start Z Position //////////////////////////////////////////
TH1D *hMCPrimaryStartZ = new TH1D("hMCPrimaryStartZ", "Primary Particle Z_{0}", 600, -120 , 180);

/////////////////////////////////// Primary Projected Particle Start X Position //////////////////////////////////////////
TH1D *hMCPrimaryProjectedStartX = new TH1D("hMCPrimaryProjectedStartX", "Primary Particle X_{0}", 200, -50 , 50);
/////////////////////////////////// Primary Projected Particle Start Y Position //////////////////////////////////////////
TH1D *hMCPrimaryProjectedStartY = new TH1D("hMCPrimaryProjectedStartY", "Primary Particle Y_{0}", 200, -50 , 50);
/////////////////////////////////// Primary Projected Particle Start Z Position //////////////////////////////////////////
TH1D *hMCPrimaryProjectedStartZ = new TH1D("hMCPrimaryProjectedStartZ", "Primary Particle Z_{0}", 400, -50 , 150);

/////////////////////////////////// Primary Particle End X Position //////////////////////////////////////////
TH1D *hMCPrimaryEndX = new TH1D("hMCPrimaryEndX", "Primary Particle X_{f}", 400, -200 , 200);
/////////////////////////////////// Primary Particle End Y Position //////////////////////////////////////////
TH1D *hMCPrimaryEndY = new TH1D("hMCPrimaryEndY", "Primary Particle Y_{f}", 400, -200 , 200);
/////////////////////////////////// Primary Particle End Z Position //////////////////////////////////////////
TH1D *hMCPrimaryEndZ = new TH1D("hMCPrimaryEndZ", "Primary Particle Z_{f}", 600, -120 , 480);

/////////////////////////////////// Primary Particle Px  //////////////////////////////////////////
TH1D *hMCPrimaryPx = new TH1D("hMCPrimaryPx", "Primary Particle P_{x}", 300, -150 , 150);
/////////////////////////////////// Primary Particle Py  //////////////////////////////////////////
TH1D *hMCPrimaryPy = new TH1D("hMCPrimaryPy", "Primary Particle P_{y}", 300, -159 , 150);
/////////////////////////////////// Primary Particle Pz //////////////////////////////////////////
TH1D *hMCPrimaryPz = new TH1D("hMCPrimaryPz", "Primary Particle P_{z}", 3000, -500 , 2500);

/////////////////////////////////// Primary Particle Process //////////////////////////////////////////
TH1D *hMCPrimaryProcess = new TH1D("hMCPrimaryProcess", "Primary Particle Process", 100, 0 , 20);

/////////////////////////////////// Primary End X vs Z Position //////////////////////////////////////////////
TH2D *hMCPrimaryEndXvsZ = new TH2D("hMCPrimaryEndXvsZ", "X_{f} vs Z_{f}", 600, -150, 450, 400, -200, 200);
/////////////////////////////////// Primary End Y vs Z Position //////////////////////////////////////////////
TH2D *hMCPrimaryEndYvsZ = new TH2D("hMCPrimaryEndYvsZ", "Y_{f} vs Z_{f}", 600, -150, 450, 200, -200, 200);

/////////////////////////////////// Energy Loss in the upstream region of the beamline ///////////////////////
TH1D *hMCELossUpstream = new TH1D("hMCELossUpstream", "Energy loss prior to entering the TPC", 1000, 0, 1000);

/////////////////////////////////// True Length //////////////////////////////////////////
TH1D *hTrueLength = new TH1D("hTrueLength", "#True Length of the Primary Particle inside the TPC", 200, 0 , 100);
TH2D *hRecoTruth = new TH2D("hRecoTruth", "recoZint vs truthZint (for pions that gets to tpc) ", 200, 0 , 100,200,0,100);

TH2D *hRecoTruthDeltaE = new TH2D("hRecoTruthDeltaE", "recoDeltaEtrack vs truthDeltaEtrack (for pions that gets to tpc) ", 500, 0 , 500, 500,0,500);


TH1D *hWeirdCaloPts = new TH1D("hWeirdCaloPts", "#of weird caloPoints for each matched track", 50, 0 , 50); //along the track > 15 MeV/cm, > 10 cm RR
TH1D *hBigWeirdCaloPts = new TH1D("hBigWeirdCaloPts", "#of Big weird caloPoints for each matched track", 100, 0 , 100); // > 40 MeV/cm along track
TH1D *hdEdxWeird = new TH1D("hdEdxWeird", "Pion dE/dX - weird evts", 500, 0, 500);
TH1D *hdEdxBigWeird = new TH1D("hdEdxBigWeird", "Pion dE/dX - Big weird evts", 1000, 0, 1000);



// ================================================================================================================
// 						Reconstructed Information 
// ================================================================================================================

/////////////////////////////////// Most Upstream Z point of tracks //////////////////////////////////////////
TH1D *hdataUpstreamZPos = new TH1D("hdataUpstreamZPos", "Most upstream spacepoint of all TPC Tracks", 20, 0, 10);

/////////////////////////////////// Number of Tracks in the TPC versus distance //////////////////////////////////////////
TH2D *hdataNTracksvsZpos = new TH2D("hdataNTracksvsZpos", "Number of TPC tracks vs Z ", 30, 0, 30, 20, 0, 10);

/////////////////////////////////// Alpha Between WC and TPC Tracks //////////////////////////////////////////
TH1D *hAlpha = new TH1D("hAlpha", "#alpha between MC Particle and TPC Track", 90, 0, 90);

/////////////////////////////////// Delta Start X Position //////////////////////////////////////////
TH1D *hDeltaX = new TH1D("hDeltaX", "#Delta X_{0} of the most upstream Reco Track and the Projected Primary Particle X_{0}", 200, -50 , 50);
/////////////////////////////////// Delta Start Y Position //////////////////////////////////////////
TH1D *hDeltaY = new TH1D("hDeltaY", "#Delta Y_{0} of the most upstream Reco Track and the Projected Primary Particle Y_{0}", 200, -50 , 50);
/////////////////////////////////// Delta Start Z Position //////////////////////////////////////////
TH1D *hDeltaZ = new TH1D("hDeltaZ", "#Delta Z_{0} of the most upstream Reco Track and the Projected Primary Particle Z_{0}", 200, -50 , 50);


/////////////////////////////////// Reconstructed Length //////////////////////////////////////////
TH1D *hRecoLength = new TH1D("hRecoLength", "#Reconstructed Length of the Primary Particle inside the TPC", 200, 0 , 100);
TH2D *hRecoTruthLength = new TH2D("hRecoTruthLength", "#Reconstructed Length vs Truth length - of the Primary Particle inside the TPC", 200, 0 , 100,200,0,100);

/////////////////////////////////// Delta Length Position //////////////////////////////////////////
TH1D *hDeltaLength = new TH1D("hDeltaLength", "#Delta Length of the most upstream Reco Track and the Primary Particle Z_{0}", 200, -100 , 100);


TH1D *hIntBefore = new TH1D("hIntBefore", "Intercation Kinetic Energy (MeV) of Pions that Interact before the TPC", 500, 0, 2500);
TH1D *hIntIn = new TH1D("hIntIn", "Interaction Kinetic Energy (MeV) of Pions that enter the TPC: interact in the TPC or cross the TPC", 500, 0, 2500);


/////////////////////////////////// "Pion" initial Kinetic Energy (MeV) //////////////////////////////////////////
TH1D *hMCInitalKE = new TH1D("hMCInitalKE", "Pion Initial Kinetic Energy (MeV)", 500, 0, 2500);
TH1D *hMCInitialMom = new TH1D("hMCInitialMom", "Pion Initial Momentum [at WC4] (MeV/c) - MCtruth", 500, 0, 2500);
/////////////////////////////////// "Pion" dE/dX //////////////////////////////////////////
TH1D *hdataPiondEdX = new TH1D("hdataPiondEdX", "Pion dE/dX", 200, 0, 50);
/////////////////////////////////// "Pion" Residual Range //////////////////////////////////////////
TH1D *hdataPionRR = new TH1D("hdataPionRR", "Pion Residual Range", 240, -10, 110);
/////////////////////////////////// "Pion" Track Pitch //////////////////////////////////////////
TH1D *hdataPionTrkPitch = new TH1D("hdataPionTrkPitch", "Track Pitch", 1000, 0, 5);
///////////////////////////////// "Pion dE/dX vs RR ///////////////////////////////////////////
TH2D *hdataPiondEdXvsRR = new TH2D("", "dE/dX vs Residual Range",200, 0, 100, 200, 0, 50);
TH2D *hdataPiondEdXvsRR0 = new TH2D("hdEdxVSrr_contained", "dE/dX vs Residual Range - contained",200, 0, 100, 200, 0, 50);
TH2D *hdataPiondEdXvsRR1 = new TH2D("hdEdxVSrr_contained_stop", "dE/dX vs Residual Range - possible stop",200, 0, 100, 200, 0, 50);
TH2D *hdataPiondEdXvsRR2 = new TH2D("hdEdxVSrr_contained_after", "dE/dX vs Residual Range - after",200, 0, 100, 200, 0, 50);
TH2D *hdataPiondEdXvsRR3 = new TH2D("hdEdxVSrr_contained_superWeird", "dE/dX vs Residual Range - superWeird",200, 0, 100, 1000, 0, 1000);
TH2D *hdataPiondEdXvsRR4 = new TH2D("hdEdxVSrr_contained_weird", "dE/dX vs Residual Range - weird evts",200, 0, 100, 200, 0, 100);


TH2D *hdataPiondEdXvsEn = new TH2D("hdEdxVSEn_contained", "dE/dX vs kinEn - contained evts ",600, 0, 1500, 200, 0, 50);

/////////////////////////////////// "Pion" Incident to the slab Kinetic Energy (MeV) //////////////////////////////////////////
TH1D *hdataPionIncidentKE = new TH1D("hdataPionIncidentKE", "Pion Incident Kinetic Energy (MeV)", 40, 0, 2000);
/////////////////////////////////// "Pion" Exiting the slab Kinetic Energy (MeV) //////////////////////////////////////////
TH1D *fPionInteractions = new TH1D("fPionInteractions", "Pion Out Kinetic Energy (MeV)", 40, 0, 2000);
/////////////////////////////////// Cross-Section //////////////////////////////////////////////////////////////////////
TH1F *fCrossSection = new TH1F("fCrossSection", "Cross-Section", 40, 0, 2000); 
TH1D *fPionFinalKinEn = new TH1D("fPionFinalKinEn", "Pion Final Kinetic Energy (MeV)", 500, -500, 2000);
////////////////////////////////// Pion Track Start and End Positions //////////////////////////////////////////////////
TH1D *hdataPionTrackEndX = new TH1D("hdataPionTrackEndX", "Pion Track End X Position", 50, 0, 50);
TH1D *hdataPionTrackEndY = new TH1D("hdataPionTrackEndY", "Pion Track End Y Position", 40, -20, 20);
TH1D *hdataPionTrackEndZ = new TH1D("hdataPionTrackEndZ", "Pion Track End Z Position", 100, 0, 100);

TH1D *hdataPionTrackStartX = new TH1D("hdataPionTrackStartX", "Pion Track Start X Position", 50, 0, 50);
TH1D *hdataPionTrackStartY = new TH1D("hdataPionTrackStartY", "Pion Track Start Y Position", 40, -20, 20);
TH1D *hdataPionTrackStartZ = new TH1D("hdataPionTrackStartZ", "Pion Track Start Z Position", 100, 0, 100);

TH1D *hPIDA = new TH1D("hPIDA", "PIDA value for good tracks - contained events (MC) ", 50, 0, 50);
TH1D *hPIDALow = new TH1D("hPIDALow", "PIDA value for tracks with Efin < 100 MeV) ", 50, 0, 50);
TH1D *hPIDAFin = new TH1D("hPIDAFin", "PIDA value for tracks after removal of stoppingPion and pionWithAttachedProton ", 50, 0, 50);
TH1D *hPIDAProbStop = new TH1D("hPIDAProbStop", "PIDA value for tracks with Ein@TPC < 250 MeV ", 50, 0, 50);

TH2D *PIDAEin = new TH2D("PIDAEin", "PIDAEin", 50, 0, 50, 500, -500, 2000);
TH2D *PIDAEfin = new TH2D("PIDAEfin", "PIDAEfin", 50, 0, 50, 500, -500, 2000);
TH2D *PIDALastDE = new TH2D("PIDALastDE", "PIDALastDE", 50, 0, 50, 500, -500, 1000);

TH1D *hlastDeltaE = new TH1D("hlastDeltaE", "Energy loss in last 3 space points (of matched tracks)", 1000, 0, 1000);
TH1D *hlastDeltaEweird = new TH1D("hlastDeltaEweird", "Energy loss in last 3 space points (of matched tracks) - weird evts", 1000, 0, 1000);
TH1D *hlastDeltaEStopPi = new TH1D("hlastDeltaEStopPi", "Energy loss in last 3 space points (of matched tracks) - StopPi", 1000, 0, 1000);
TH1D *hlastDeltaEattProt = new TH1D("hlastDeltaEattProt", "Energy loss in last 3 space points (of matched tracks) - attachedProt", 1000, 0, 1000);

TH2D *weirddEdxVSrr = new TH2D("weirddEdxVSrr", "dEdx vs RR of events which have dEdx >35MeV/cm", 200, 0, 100, 1000, -50, 950);

/////////////////////////////////// Delta End X Position //////////////////////////////////////////
TH1D *hDeltaEndX = new TH1D("hDeltaEndX", "#Delta X_{f} of the most upstream Reco Track and the Projected Primary Particle X_{f}", 200, -50 , 50);
/////////////////////////////////// Delta End Y Position //////////////////////////////////////////
TH1D *hDeltaEndY = new TH1D("hDeltaEndY", "#Delta Y_{f} of the most upstream Reco Track and the Projected Primary Particle Y_{f}", 200, -50 , 50);
/////////////////////////////////// Delta End Z Position //////////////////////////////////////////
TH1D *hDeltaEndZ = new TH1D("hDeltaEndZ", "#Delta Z_{f} of the most upstream Reco Track and the Projected Primary Particle Z_{f}", 200, -50 , 50);




//-----------------------------------------------------------------------------------------------------------------------------------------------
//								Stacked Histograms

/////////////////////////////////// Delta End Z Position InElastic //////////////////////////////////////////
TH1D *hDeltaEndZInElastic = new TH1D("hDeltaEndZInElastic", "#Delta Z_{f} InElastic", 200, -50 , 50);
/////////////////////////////////// Delta End Z Position Neutron InElastic //////////////////////////////////////////
TH1D *hDeltaEndZNeutronInElastic = new TH1D("hDeltaEndZNeutronInElastic", "#Delta Z_{f} Neutron InElastic", 200, -50 , 50);
/////////////////////////////////// Delta End Z Position Hadrondic Elastic //////////////////////////////////////////
TH1D *hDeltaEndZHadElastic = new TH1D("hDeltaEndZHadElastic", "#Delta Z_{f} Hadronic Elastic", 200, -50 , 50);
/////////////////////////////////// Delta End Z Position Neutron Capture //////////////////////////////////////////
TH1D *hDeltaEndZnCap = new TH1D("hDeltaEndZnCap", "#Delta Z_{f} Neutron Capture", 200, -50 , 50);
/////////////////////////////////// Delta End Z Position Nuclear Capture at Rest //////////////////////////////////////////
TH1D *hDeltaEndZnuclearCapatureAtRest = new TH1D("hDeltaEndZnuclearCapatureAtRest", "#Delta Z_{f} Nuclear capture at rest ", 200, -50 , 50);
/////////////////////////////////// Delta End Z Position Decay //////////////////////////////////////////
TH1D *hDeltaEndZDecay = new TH1D("hDeltaEndZDecay", "#Delta Z_{f} Decay ", 200, -50 , 50);
/////////////////////////////////// Delta End Z Position KaonZero InElastic //////////////////////////////////////////
TH1D *hDeltaEndZKaonZeroInElastic = new TH1D("hDeltaEndZKaonZeroInElastic", "#Delta Z_{f} Kaon Zero InElastic ", 200, -50 , 50);
/////////////////////////////////// Delta End Z Position Coulomb Scattering //////////////////////////////////////////
TH1D *hDeltaEndZCoulombScat = new TH1D("hDeltaEndZCoulombScat", "#Delta Z_{f} Coulomb Scattering ", 200, -50 , 50);
/////////////////////////////////// Delta End Z Position MuMinus Capture //////////////////////////////////////////
TH1D *hDeltaEndZMuMinusCapture = new TH1D("hDeltaEndZMuMinusCapture", "#Delta Z_{f} MuMinus Capture ", 200, -50 , 50);
/////////////////////////////////// Delta End Z Position Proton Inelastic //////////////////////////////////////////
TH1D *hDeltaEndZProtonInelastic = new TH1D("hDeltaEndZProtonInelastic", "#Delta Z_{f} Proton Inelastic ", 200, -50 , 50);





/////////////////////////////////// Delta End Y Position InElastic //////////////////////////////////////////
TH1D *hDeltaEndYInElastic = new TH1D("hDeltaEndYInElastic", "#Delta Y_{f} InElastic", 200, -50 , 50);
/////////////////////////////////// Delta End Y Position Neutron InElastic //////////////////////////////////////////
TH1D *hDeltaEndYNeutronInElastic = new TH1D("hDeltaEndYNeutronInElastic", "#Delta Y_{f} Neutron InElastic", 200, -50 , 50);
/////////////////////////////////// Delta End Y Position Hadrondic Elastic //////////////////////////////////////////
TH1D *hDeltaEndYHadElastic = new TH1D("hDeltaEndYHadElastic", "#Delta Y_{f} Hadronic Elastic", 200, -50 , 50);
/////////////////////////////////// Delta End Y Position Neutron Capture //////////////////////////////////////////
TH1D *hDeltaEndYnCap = new TH1D("hDeltaEndYnCap", "#Delta Y_{f} Neutron Capture", 200, -50 , 50);
/////////////////////////////////// Delta End Y Position Nuclear Capture at Rest //////////////////////////////////////////
TH1D *hDeltaEndYnuclearCapatureAtRest = new TH1D("hDeltaEndYnuclearCapatureAtRest", "#Delta Y_{f} Nuclear capture at rest ", 200, -50 , 50);
/////////////////////////////////// Delta End Y Position Decay //////////////////////////////////////////
TH1D *hDeltaEndYDecay = new TH1D("hDeltaEndYDecay", "#Delta Y_{f} Decay ", 200, -50 , 50);
/////////////////////////////////// Delta End Y Position KaonZero InElastic //////////////////////////////////////////
TH1D *hDeltaEndYKaonZeroInElastic = new TH1D("hDeltaEndYKaonZeroInElastic", "#Delta Y_{f} Kaon Zero InElastic ", 200, -50 , 50);
/////////////////////////////////// Delta End Y Position Coulomb Scattering //////////////////////////////////////////
TH1D *hDeltaEndYCoulombScat = new TH1D("hDeltaEndYCoulombScat", "#Delta Y_{f} Coulomb Scattering ", 200, -50 , 50);
/////////////////////////////////// Delta End Y Position MuMinus Capture //////////////////////////////////////////
TH1D *hDeltaEndYMuMinusCapture = new TH1D("hDeltaEndYMuMinusCapture", "#Delta Y_{f} MuMinus Capture ", 200, -50 , 50);
/////////////////////////////////// Delta End Y Position Proton Inelastic //////////////////////////////////////////
TH1D *hDeltaEndYProtonInelastic = new TH1D("hDeltaEndYProtonInelastic", "#Delta Y_{f} Proton Inelastic ", 200, -50 , 50);




/////////////////////////////////// Delta End X Position InElastic //////////////////////////////////////////
TH1D *hDeltaEndXInElastic = new TH1D("hDeltaEndXInElastic", "#Delta X_{f} InElastic", 200, -50 , 50);
/////////////////////////////////// Delta End X Position Neutron InElastic //////////////////////////////////////////
TH1D *hDeltaEndXNeutronInElastic = new TH1D("hDeltaEndXNeutronInElastic", "#Delta X_{f} Neutron InElastic", 200, -50 , 50);
/////////////////////////////////// Delta End X Position Hadrondic Elastic //////////////////////////////////////////
TH1D *hDeltaEndXHadElastic = new TH1D("hDeltaEndXHadElastic", "#Delta X_{f} Hadronic Elastic", 200, -50 , 50);
/////////////////////////////////// Delta End X Position Neutron Capture //////////////////////////////////////////
TH1D *hDeltaEndXnCap = new TH1D("hDeltaEndXnCap", "#Delta X_{f} Neutron Capture", 200, -50 , 50);
/////////////////////////////////// Delta End X Position Nuclear Capture at Rest //////////////////////////////////////////
TH1D *hDeltaEndXnuclearCapatureAtRest = new TH1D("hDeltaEndXnuclearCapatureAtRest", "#Delta X_{f} Nuclear capture at rest ", 200, -50 , 50);
/////////////////////////////////// Delta End X Position Decay //////////////////////////////////////////
TH1D *hDeltaEndXDecay = new TH1D("hDeltaEndXDecay", "#Delta X_{f} Decay ", 200, -50 , 50);
/////////////////////////////////// Delta End X Position KaonZero InElastic //////////////////////////////////////////
TH1D *hDeltaEndXKaonZeroInElastic = new TH1D("hDeltaEndXKaonZeroInElastic", "#Delta X_{f} Kaon Zero InElastic ", 200, -50 , 50);
/////////////////////////////////// Delta End X Position Coulomb Scattering //////////////////////////////////////////
TH1D *hDeltaEndXCoulombScat = new TH1D("hDeltaEndXCoulombScat", "#Delta X_{f} Coulomb Scattering ", 200, -50 , 50);
/////////////////////////////////// Delta End X Position MuMinus Capture //////////////////////////////////////////
TH1D *hDeltaEndXMuMinusCapture = new TH1D("hDeltaEndXMuMinusCapture", "#Delta X_{f} MuMinus Capture ", 200, -50 , 50);
/////////////////////////////////// Delta End X Position Proton Inelastic //////////////////////////////////////////
TH1D *hDeltaEndXProtonInelastic = new TH1D("hDeltaEndXProtonInelastic", "#Delta X_{f} Proton Inelastic ", 200, -50 , 50);

// ### Delta Z Stacked  ###
THStack *hStackDeltaEndZ = new THStack("hStackDeltaEndZ", "#Delta Z_{f}");

// ### Delta Y Stacked  ###
THStack *hStackDeltaEndY = new THStack("hStackDeltaEndY", "#Delta Y_{f}");

// ### Delta X Stacked  ###
THStack *hStackDeltaEndX = new THStack("hStackDeltaEndX", "#Delta X_{f}");

//-----------------------------------------------------------------------------------------------------------------------------------------------



void Pion::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L Pion.C
//      Root > Pion t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// 					  Putting Flexible Cuts here
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------


// ### Putting in the particle mass that is being simulated here ###
// ###    which is used when calculating the energy loss before  ###
// ###                       entering the TPC                    ###

float particle_mass = 139.57; //<---Mass of Pion in MeV


// ### Number of centimeters in Z we require a track ###
// ### to have a space point within (default = 2 cm) ###
double FirstSpacePointZPos = 2.0;


// ########################################################
// ### Delta X Between Wire Chamber Track and TPC Track ###
// ########################################################
double DeltaXLowerBound = -2.0;
double DeltaXUpperBound = 6.0;

// ########################################################
// ### Delta Y Between Wire Chamber Track and TPC Track ###
// ########################################################
double DeltaYLowerBound = -3.0;
double DeltaYUpperBound = 6.0;


// ########################################################################
// ### Fiducial Boundry Cuts (used to determine if a track is stopping) ###
// ########################################################################
double XLowerFid = 0;
double XUpperFid = 47;

double YLowerFid = -20;
double YUpperFid = 20;

double ZLowerFid = 0;
double ZUpperFid = 90;


// ########################################################################
// ### Definition of the upstream part of the TPC where we restrict the ###
// ###             number of tracks which can be present                ###
// ########################################################################
int UpperPartOfTPC = 14.0;

// #####################################################
// ### Number of tracks allowed in the upstream part ###
// #####################################################
int nLowZTracksAllowed = 4;


// #################################################################################
// ### Making shower Cut (ShortTkLength) and the number of short tracks we allow ###
// #################################################################################
double ShortTkLength = 5.0;
int nShortTracksAllowed = 2;


// ############################
// ### Alpha Cut in degrees ###
// ############################
double alphaCut = 10;

// ### Setting the global event weight based on ###
// ###   open box WCTrack momentum spectrum     ###
   
   
float EventWeight = 1.0;

// #################################################   
// ### True  = Use the momentum based weighting  ###
// ### False = Don't weight events               ###
// #################################################
bool UseEventWeight = true;


// ###############################################
// ### Creating a file to output my histograms ###
// ###############################################
TFile myfile("PionMCXSection_histos_NewMC_Step2b.root","RECREATE");




// ----------------------------------------------------------------
// Create the cross section from the incident and interaction plots
// ----------------------------------------------------------------
float rho = 1396; //kg/m^3
//  float cm_per_m = 100;
float molar_mass = 39.95; //g/mol
float g_per_kg = 1000; 
float avogadro = 6.022e+23; //number/mol
float number_density = rho*g_per_kg/molar_mass*avogadro;
float slab_width = 0.0045;//in m

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if (fChain == 0) return;
Long64_t nentries = fChain->GetEntriesFast();
Long64_t nbytes = 0, nb = 0;


// ##########################################################
// ### Putting in some counters for event reduction table ###
// ##########################################################
int nTotalEvents = 0, nEvtsGoodMC = 0, nEvtsTrackZPos = 0, nEvtsMCTrackMatch = 0;
int nEvtsTOF = 0, nEvtsPID = 0, nEventsPassingAlpha = 0, nLowZTrkEvents = 0;
int nNonShowerEvents = 0;

    int nCrossing=0;
    int capture=0;
    int captureBert=0;
    bool stoppingEvt= true;
    int captureContained =0;
    int stopping=0;
    int protonAtt=0;
    int weirdEvt=0;
    
int counter = 0;

bool BertCaptEvt = false;
bool PiDecay = false;

// ###############################
// ### Looping over all Events ###
// ###############################
for (Long64_t jentry=0; jentry<nentries;jentry++)
//for (Long64_t jentry=0; jentry<10000;jentry++)
   {
   stoppingEvt= false;
   Long64_t ientry = LoadTree(jentry);
   if (ientry < 0) break;
   nb = fChain->GetEntry(jentry);   nbytes += nb;
   // if (Cut(ientry) < 0) continue;
       
   // #############################
   // ### Counting Total Events ###
   // #############################
   nTotalEvents++;
   cout << "##### New event ###### " << nTotalEvents << endl;
   
   // === Outputting every nEvents to the screen ===
   if(nTotalEvents % 1000 == 0){std::cout<<"Event = "<<nTotalEvents<<std::endl;} 
   

   //=======================================================================================================================
   //					      GEANT 4 Information
   //=======================================================================================================================
   // ##################################################
   // ### Defining some useful variables we will use ###
   // ##################################################
   int nG4Primary = 0;
   int nG4TrajPoints = 0;
   
   float g4Primary_X0[100] = {0.}, g4Primary_Y0[100] = {0.}, g4Primary_Z0[100] = {0.};
   float g4Primary_ProjX0[100] = {0.}, g4Primary_ProjY0[100] = {0.}, g4Primary_ProjZ0[100] = {0.};
   
   float g4Primary_Xf[100] = {0.}, g4Primary_Yf[100] = {0.}, g4Primary_Zf[100] = {0.};
   float g4Primary_Px[100] = {0.}, g4Primary_Py[100] = {0.}, g4Primary_Pz[100] = {0.};
   
   int g4Primary_TrkID[100] = {999}, g4PrimaryProcess[100] = {0};
   
   int nG4PriTrj = 0;
   float g4Primary_TrueTrjX[10][10000] = {0.}, g4Primary_TrueTrjY[10][10000] = {0.}, g4Primary_TrueTrjZ[10][10000] = {0.};
   float g4Primary_TrueTrjPx[10][10000] = {0.}, g4Primary_TrueTrjPy[10][10000] = {0.}, g4Primary_TrueTrjPz[10][10000] = {0.};
   
   
   float TrueLength = 0;
   float RecoLength = 0;
   
   int TrajPosFirstInt = 0;
   int TypeFirstInt = 0.;
   
   //(x,y,z) of first interaction at MCtruth level
   float xInt_Truth =0.;
   float yInt_Truth =0.;
   float zInt_Truth =0.;
   float zInt_Reco = 0.;
   float DeltaEreco = 0.;
   
   //(x,y,z) of the primary particle when it gets to the TPC
   float xInc_Truth=0.;
   float yInc_Truth=0.;
   float zInc_Truth=0.;
   float PxInc_Truth=0.;
   float PyInc_Truth=0.;
   float PzInc_Truth=0.;
   float EInc_Truth=0.;
   float EInt_Truth =0.; //energy at interaction - if in fiducial volume - or energy at tpc boundary
   float Energy_Int_In =0.;
   float DeltaEtruth=0.;
   
   bool myTypeInt = false;
   
   /*   for( unsigned int iD = 0; iD < InteractionPointType->size(); ++iD ){
   cout << " int Type of the primary " << InteractionPointType->at(iD) << endl;
   cout << "int Point of the primary " << InteractionPoint->at(iD) << endl;
   
    }*/
    
    TypeFirstInt = InteractionPointType->at(0);
    TrajPosFirstInt = InteractionPoint->at(0);
   
   // ##########################################
   // ### Loop over all the GEANT4 particles ###
   // ##########################################
   for (int iG4 = 0; iG4 < geant_list_size; iG4++)
      {
      // #####################################################
      // ### If this is a primary particle then look at it ###
      // #####################################################
      if(process_primary[iG4] == 1)
         {

	 
	 // ### Recording information for use later ###
	 g4Primary_X0[nG4Primary] = StartPointx[iG4];
	 g4Primary_Y0[nG4Primary] = StartPointy[iG4];
	 g4Primary_Z0[nG4Primary] = StartPointz[iG4];
	 
	 g4Primary_Xf[nG4Primary] = EndPointx[iG4];
	 g4Primary_Yf[nG4Primary] = EndPointy[iG4];
	 g4Primary_Zf[nG4Primary] = EndPointz[iG4];
	 
	 g4Primary_Px[nG4Primary] = Px[iG4] * 1000; //<---Converting to MeV
	 g4Primary_Py[nG4Primary] = Py[iG4] * 1000; //<---Converting to MeV
	 g4Primary_Pz[nG4Primary] = Pz[iG4] * 1000; //<---Converting to MeV
	 
	 // ### Setting a global event weight ###
	
	 
	 // ### Setting Event weight ### 
	 if(UseEventWeight)
	    {
	    if(g4Primary_Pz[nG4Primary] > 0      && g4Primary_Pz[nG4Primary] <= 50){EventWeight = 0.;}
	    if(g4Primary_Pz[nG4Primary] > 50     && g4Primary_Pz[nG4Primary] <= 100){EventWeight = 0.;}
	    if(g4Primary_Pz[nG4Primary] > 100    && g4Primary_Pz[nG4Primary] <= 150){EventWeight =0.;}
        if(g4Primary_Pz[nG4Primary] > 150    && g4Primary_Pz[nG4Primary] <= 200){EventWeight = 0.00366544;}
	    if(g4Primary_Pz[nG4Primary] > 200    && g4Primary_Pz[nG4Primary] <= 250){EventWeight = 0.00433189;}
	    if(g4Primary_Pz[nG4Primary] > 250    && g4Primary_Pz[nG4Primary] <= 300){EventWeight = 0.0246584;}
	    if(g4Primary_Pz[nG4Primary] > 300    && g4Primary_Pz[nG4Primary] <= 350){EventWeight = 0.0639787;}
	    if(g4Primary_Pz[nG4Primary] > 350    && g4Primary_Pz[nG4Primary] <= 400){EventWeight = 0.0559813;}
	    if(g4Primary_Pz[nG4Primary] > 400    && g4Primary_Pz[nG4Primary] <= 450){EventWeight = 0.0793069;}
	    if(g4Primary_Pz[nG4Primary] > 450    && g4Primary_Pz[nG4Primary] <= 500){EventWeight = 0.0909697;}
	    if(g4Primary_Pz[nG4Primary] > 500    && g4Primary_Pz[nG4Primary] <= 550){EventWeight = 0.0716428;}
	    if(g4Primary_Pz[nG4Primary] > 550    && g4Primary_Pz[nG4Primary] <= 600){EventWeight = 0.0706431;}
	    if(g4Primary_Pz[nG4Primary] > 600    && g4Primary_Pz[nG4Primary] <= 650){EventWeight = 0.08997;}
	    if(g4Primary_Pz[nG4Primary] > 650    && g4Primary_Pz[nG4Primary] <= 700){EventWeight = 0.102632;}
	    if(g4Primary_Pz[nG4Primary] > 700    && g4Primary_Pz[nG4Primary] <= 750){EventWeight = 0.100966;}
	    if(g4Primary_Pz[nG4Primary] > 750    && g4Primary_Pz[nG4Primary] <= 800){EventWeight = 0.0783072;}
	    if(g4Primary_Pz[nG4Primary] > 800    && g4Primary_Pz[nG4Primary] <= 850){EventWeight = 0.0543152;}
	    if(g4Primary_Pz[nG4Primary] > 850    && g4Primary_Pz[nG4Primary] <= 900){EventWeight = 0.0406531;}
	    if(g4Primary_Pz[nG4Primary] > 900    && g4Primary_Pz[nG4Primary] <= 950){EventWeight = 0.0293236;}
	    if(g4Primary_Pz[nG4Primary] > 950 	 && g4Primary_Pz[nG4Primary] <= 1000){EventWeight = 0.0159947;}
	    if(g4Primary_Pz[nG4Primary] > 1000   && g4Primary_Pz[nG4Primary] <= 1050){EventWeight = 0.00966345;}
	    if(g4Primary_Pz[nG4Primary] > 1050   && g4Primary_Pz[nG4Primary] <= 1100){EventWeight = 0.00566478;}
	    if(g4Primary_Pz[nG4Primary] > 1100   && g4Primary_Pz[nG4Primary] <= 1150){EventWeight = 0.002999;}
	    if(g4Primary_Pz[nG4Primary] > 1150   && g4Primary_Pz[nG4Primary] <= 1200){EventWeight = 0.000999667;}
	    if(g4Primary_Pz[nG4Primary] > 1200   && g4Primary_Pz[nG4Primary] <= 1250){EventWeight = 0.000333222;}
	    if(g4Primary_Pz[nG4Primary] > 1250   && g4Primary_Pz[nG4Primary] <= 1300){EventWeight = 0.000333222;}
	    if(g4Primary_Pz[nG4Primary] > 1300   && g4Primary_Pz[nG4Primary] <= 1350){EventWeight = 0.000666445;}
	    if(g4Primary_Pz[nG4Primary] > 1350   && g4Primary_Pz[nG4Primary] <= 1400){EventWeight = 0.000333222;}
	    if(g4Primary_Pz[nG4Primary] > 1400   && g4Primary_Pz[nG4Primary] <= 1450){EventWeight = 0.000999667;}
	    if(g4Primary_Pz[nG4Primary] > 1450   && g4Primary_Pz[nG4Primary] <= 1500){EventWeight = 0.000333222;}
	    if(g4Primary_Pz[nG4Primary] > 1500   && g4Primary_Pz[nG4Primary] <= 1550){EventWeight = 0.000333222;}
	    if(g4Primary_Pz[nG4Primary] > 1550   && g4Primary_Pz[nG4Primary] <= 1600){EventWeight = 0.;}
	    if(g4Primary_Pz[nG4Primary] > 1600   && g4Primary_Pz[nG4Primary] <= 1650){EventWeight = 0.;}
	    if(g4Primary_Pz[nG4Primary] > 1650   && g4Primary_Pz[nG4Primary] <= 1700){EventWeight = 0.;}
	    if(g4Primary_Pz[nG4Primary] > 1700   && g4Primary_Pz[nG4Primary] <= 1750){EventWeight = 0.;}
	    if(g4Primary_Pz[nG4Primary] > 1750   && g4Primary_Pz[nG4Primary] <= 1800){EventWeight = 0.;}
	    if(g4Primary_Pz[nG4Primary] > 1800   && g4Primary_Pz[nG4Primary] <= 1850){EventWeight = 0.;}
	    if(g4Primary_Pz[nG4Primary] > 1850   && g4Primary_Pz[nG4Primary] <= 1900){EventWeight = 0.;}
	    if(g4Primary_Pz[nG4Primary] > 1900   && g4Primary_Pz[nG4Primary] <= 1950){EventWeight = 0.;}
	    if(g4Primary_Pz[nG4Primary] > 1950   && g4Primary_Pz[nG4Primary] <= 2000){EventWeight = 0.;}
	    if(g4Primary_Pz[nG4Primary] > 2000) {EventWeight = 0.;}
	    
	    }//<---End Assigning Event weight
	    
	 
	 
	/* TrueLength = sqrt( ((EndPointz[iG4]-StartPointz[iG4])*(EndPointz[iG4]-StartPointz[iG4])) + 
	                    ((EndPointy[iG4]-StartPointy[iG4])*(EndPointy[iG4]-StartPointy[iG4])) + 
	                    ((EndPointx[iG4]-StartPointx[iG4])*(EndPointx[iG4]-StartPointx[iG4])) );
			    
	 hTrueLength->Fill(TrueLength);*/
	 
	 // ------------------------------------------------------------------------------------
	 // ---------------        Extrapolate the X, Y, Z position of the primary         -----
	 // ---------------     if it started upstream of the front face of the TPC        -----
	 // ------------------------------------------------------------------------------------
	 
	 double b1 = StartPointz[iG4] - StartPointx[iG4]*Pz[iG4]/Px[iG4];
	 double b2 = StartPointz[iG4] - StartPointy[iG4]*Pz[iG4]/Py[iG4];
	 
	 g4Primary_ProjX0[nG4Primary] = -b1*Px[iG4]/Pz[iG4];
	 g4Primary_ProjY0[nG4Primary] = -b2*Py[iG4]/Pz[iG4];
	 g4Primary_ProjZ0[nG4Primary] = 0.0;
	 
	 // ### Setting the primary particles Track ID ###
	 g4Primary_TrkID[nG4Primary] = TrackId[iG4];
	 
	 
	 hMCPrimaryEndXvsZ->Fill(EndPointz[iG4], EndPointx[iG4]);
	 hMCPrimaryEndYvsZ->Fill(EndPointz[iG4], EndPointy[iG4]);
	 
	 // ##############################
	 // ### Filling the histograms ###
	 // ##############################
	 hMCPrimaryPx->Fill(g4Primary_Px[nG4Primary], EventWeight);
	 hMCPrimaryPy->Fill(g4Primary_Py[nG4Primary], EventWeight);
	 hMCPrimaryPz->Fill(g4Primary_Pz[nG4Primary], EventWeight);

	 hMCPrimaryStartX->Fill(StartPointx[iG4]);
	 hMCPrimaryStartY->Fill(StartPointy[iG4]);
	 hMCPrimaryStartZ->Fill(StartPointz[iG4]);
	 
	 hMCPrimaryEndX->Fill(EndPointx[iG4]);
	 hMCPrimaryEndY->Fill(EndPointy[iG4]);
	 hMCPrimaryEndZ->Fill(EndPointz[iG4]);

	 hMCPrimaryProjectedStartX->Fill(g4Primary_ProjX0[nG4Primary]);
	 hMCPrimaryProjectedStartY->Fill(g4Primary_ProjY0[nG4Primary]);
	 hMCPrimaryProjectedStartZ->Fill(g4Primary_ProjZ0[nG4Primary]);
	 
	 nG4TrajPoints = 0;
	 
	 //std::cout<<"NTrTrajPts[iG4] = "<<NTrTrajPts[iG4]<<std::endl;
	 // ### Recording the primary particles trajectory points ###
	 for(int iG4Tr = 0; iG4Tr < NTrTrajPts[iG4]; iG4Tr++)
	    {
	    g4Primary_TrueTrjX[nG4Primary][nG4PriTrj] = MidPosX[iG4][iG4Tr];
	    g4Primary_TrueTrjY[nG4Primary][nG4PriTrj] = MidPosY[iG4][iG4Tr];
	    g4Primary_TrueTrjZ[nG4Primary][nG4PriTrj] = MidPosZ[iG4][iG4Tr];
	    
	    //std::cout<<"g4Primary_TrueTrjZ[nG4Primary][nG4PriTrj] = "<<g4Primary_TrueTrjZ[nG4Primary][nG4PriTrj]<<std::endl;
	    
	    g4Primary_TrueTrjPx[nG4Primary][nG4PriTrj] = MidPx[iG4][iG4Tr]*1000;//<---Converting to MeV
	    g4Primary_TrueTrjPy[nG4Primary][nG4PriTrj] = MidPy[iG4][iG4Tr]*1000;//<---Converting to MeV
	    g4Primary_TrueTrjPz[nG4Primary][nG4PriTrj] = MidPz[iG4][iG4Tr]*1000;//<---Converting to MeV
	    
	    nG4PriTrj++;
	    }//<---end looping over this primary particles true trajectory points
	 
	 
	 // ### Bumping the counters ###
	 nG4Primary++;
	 
	 }//<---End Looking only at primaries
	 

      }// <---End iG4 Loop
      
      //If this particle has an initial momentum not compatible with beam: remove the event
	 double momentum_test=0.;
	 momentum_test=sqrt( (g4Primary_Px[0]*g4Primary_Px[0]) + (g4Primary_Py[0]*g4Primary_Py[0]) + (g4Primary_Pz[0]*g4Primary_Pz[0]));
	 
	 double energy_test=0.;
	 energy_test= pow( (momentum_test*momentum_test) + (139.57*139.57) ,0.5) - 139.57;
	 
	 
       //if(momentum_test > 1200.) {continue;}
       hMCInitialMom->Fill(momentum_test,EventWeight);
   
   // ################################################
   // ### Loop over all the GEANT4 particles again ###
   // ###  to get the process from the daughters   ###
   // ################################################
   for (int iG4 = 0; iG4 < geant_list_size; iG4++)
      {
      
      // ### Looking for the Daughters of the primary ###
      if(Mother[iG4] == g4Primary_TrkID[nG4Primary - 1])
	 {
	 g4PrimaryProcess[nG4Primary - 1] = Process[iG4];
	 
	 
	 
	 
	 }//<---End matching daughters
      
      }//<---end iG4 loop
   hMCPrimaryProcess->Fill(g4PrimaryProcess[nG4Primary - 1]);
   
 
       
       
   //=======================================================================================================================
   //				Only looking at events where the primary particle enters the TPC
   //=======================================================================================================================
   
   bool GoodMCEventInTPC = true;
   
   //float zInt_Truth=0.;
   //float zInt_Reco =0.;
   
   // ##############################################
   // ### Looping over all the primary particles ###
   // ##############################################
   for(int npri = 0; npri < nG4Primary; npri++)
      {
      //if(g4Primary_Zf[npri] < 0){GoodMCEventInTPC = false;}
      
      
      // ####################################################################
      // ### Calculating the energy loss for particles that enter the TPC ###
      // ####################################################################
     // if(GoodMCEventInTPC)
        // {
	 float DifferenceInEnergy = 0;
	 // ### Loop over the true trajectory points ###
	 for(int ntrj = 0; ntrj < nG4PriTrj; ntrj++)
	    {
	      
	       if(g4Primary_TrueTrjZ[npri][ntrj] > 0. && g4Primary_TrueTrjZ[npri][ntrj] < 0.5){
	          xInc_Truth = g4Primary_TrueTrjX[npri][ntrj];
		  yInc_Truth = g4Primary_TrueTrjY[npri][ntrj];
		  zInc_Truth = g4Primary_TrueTrjZ[npri][ntrj];
		  PxInc_Truth = g4Primary_TrueTrjPx[npri][ntrj];
		  PyInc_Truth = g4Primary_TrueTrjPy[npri][ntrj];
		  PzInc_Truth = g4Primary_TrueTrjPz[npri][ntrj];
		  float momentumInc = sqrt(PxInc_Truth*PxInc_Truth+PyInc_Truth*PyInc_Truth+PzInc_Truth*PzInc_Truth);
		  EInc_Truth = sqrt( (momentumInc*momentumInc) + (particle_mass*particle_mass)  ) - particle_mass;
		  }

	      if(ntrj == TrajPosFirstInt){ //First interaction point
		if(g4Primary_TrueTrjZ[npri][ntrj] < 0){
		//cout << "The first interaction happened before the tpc active volume "  << endl;
		float Momentum_Int_Before = sqrt((g4Primary_TrueTrjPx[npri][ntrj]*g4Primary_TrueTrjPx[npri][ntrj]) + 
	                               (g4Primary_TrueTrjPy[npri][ntrj]*g4Primary_TrueTrjPy[npri][ntrj]) +
				       (g4Primary_TrueTrjPz[npri][ntrj]*g4Primary_TrueTrjPz[npri][ntrj]));
		float Energy_Int_Before = sqrt( (Momentum_Int_Before*Momentum_Int_Before) + (particle_mass*particle_mass)  ) - particle_mass;
		//cout << "energy at interaction for pion that interacts before TPC " << Energy_Int_Before << endl;
		hIntBefore->Fill(Energy_Int_Before); //<-----
		GoodMCEventInTPC = false;
		}
		else {  
		//cout << "The primary enters the TPC: interaction in the TPC volume or crossing primary " << zInc_Truth << " " << g4Primary_TrueTrjZ[npri][ntrj] << endl;
		//cout << "Interaction type " << TypeFirstInt << endl;
		xInt_Truth = g4Primary_TrueTrjX[npri][ntrj];
		yInt_Truth = g4Primary_TrueTrjY[npri][ntrj];
		zInt_Truth = g4Primary_TrueTrjZ[npri][ntrj];
		
		float Momentum_Int_In = 0.;
		if(TypeFirstInt == 1){
		Momentum_Int_In = sqrt((g4Primary_TrueTrjPx[npri][ntrj-1]*g4Primary_TrueTrjPx[npri][ntrj-1]) + 
	                               (g4Primary_TrueTrjPy[npri][ntrj-1]*g4Primary_TrueTrjPy[npri][ntrj-1]) +
				       (g4Primary_TrueTrjPz[npri][ntrj-1]*g4Primary_TrueTrjPz[npri][ntrj-1]));
		}
		else{
		Momentum_Int_In = sqrt((g4Primary_TrueTrjPx[npri][ntrj]*g4Primary_TrueTrjPx[npri][ntrj]) + 
	                               (g4Primary_TrueTrjPy[npri][ntrj]*g4Primary_TrueTrjPy[npri][ntrj]) +
				       (g4Primary_TrueTrjPz[npri][ntrj]*g4Primary_TrueTrjPz[npri][ntrj]));
		}
		
		Energy_Int_In = sqrt( (Momentum_Int_In*Momentum_Int_In) + (particle_mass*particle_mass)  )- particle_mass;
		//cout << "Energy at interaction for pion that interacts in TPC " << Energy_Int_In << endl;
		hIntIn->Fill(Energy_Int_In); //Interaction Kin En of primary pions that get to the TPC
		//if(){
		//EInt_Truth = sqrt( (Momentum_Int_In*Momentum_Int_In) + (particle_mass*particle_mass)  )- particle_mass;
		//}
		/*if(TypeFirstInt == 3){ hIntTPC_Elastic->Fill(g4Primary_TrueTrjZ[npri][ntrj]);}
		if(TypeFirstInt == 1){ hIntTPC_Inelastic->Fill(g4Primary_TrueTrjZ[npri][ntrj]);}
		if(TypeFirstInt == 6){ hIntTPC_Decay->Fill(g4Primary_TrueTrjZ[npri][ntrj]);}
		if(TypeFirstInt == 12){ hIntTPC_Capture->Fill(g4Primary_TrueTrjZ[npri][ntrj]);}*/
		}
	      }
	      
	    
	      
	      
	    // ### Only looking at point which are upstream of the TPC ###
	    if(g4Primary_TrueTrjZ[npri][ntrj] < 0)
	       {
	       
	       float Momentum_Point1 = sqrt((g4Primary_TrueTrjPx[npri][ntrj]*g4Primary_TrueTrjPx[npri][ntrj]) + 
	                               (g4Primary_TrueTrjPy[npri][ntrj]*g4Primary_TrueTrjPy[npri][ntrj]) +
				       (g4Primary_TrueTrjPz[npri][ntrj]*g4Primary_TrueTrjPz[npri][ntrj]));
				       
	       float Momentum_Point2 = sqrt((g4Primary_TrueTrjPx[npri][ntrj+1]*g4Primary_TrueTrjPx[npri][ntrj+1]) + 
	                               (g4Primary_TrueTrjPy[npri][ntrj+1]*g4Primary_TrueTrjPy[npri][ntrj+1]) +
				       (g4Primary_TrueTrjPz[npri][ntrj+1]*g4Primary_TrueTrjPz[npri][ntrj+1]));
				       
	       float Energy_Point1 = sqrt( (Momentum_Point1*Momentum_Point1) + (particle_mass*particle_mass)  );
	       
	       float Energy_Point2 = sqrt( (Momentum_Point2*Momentum_Point2) + (particle_mass*particle_mass)  );
	       
	       DifferenceInEnergy +=  Energy_Point1 - Energy_Point2;
	       
	       //std::cout<<"z = "<<g4Primary_TrueTrjZ[npri][ntrj]<<", DifferenceInEnergy = "<<DifferenceInEnergy<<std::endl;
	       
	       
	       }//<---End only look at points which are upstream of the TPC
	       
	       
	       
	    
	    
	    }//<---End ntrj for loop
	 
	 
	 hMCELossUpstream->Fill(DifferenceInEnergy);
	// }//<---Only looking at events that actually make it into the TPC
      
      
      }//<---End npri loop
   
   if(!GoodMCEventInTPC){continue;}
   nEvtsGoodMC++;

    
  // }
   
   //study only strong int and crossing
  // if(TypeFirstInt == 1 || TypeFirstInt == 3 || TypeFirstInt == 0){ myTypeInt = true;}
   
   //if(TypeFirstInt == 12){ myTypeInt = true;} //study the pi Capture
     
   //if(!myTypeInt){continue;} 
   
   DeltaEtruth = EInc_Truth - Energy_Int_In;
   
   TrueLength = sqrt( (zInt_Truth-zInc_Truth)*(zInt_Truth-zInc_Truth)+ 
	                    (yInt_Truth-yInc_Truth)*(yInt_Truth-yInc_Truth) + (xInt_Truth-xInc_Truth)*(xInt_Truth-xInc_Truth) );
			  //cout << "  TrueLength " << TrueLength << endl;
	 hTrueLength->Fill(TrueLength);
   
   
   
   //=======================================================================================================================
   //						Low Z Spacepoint Track Cut
   //=======================================================================================================================
   
   // ### Boolian for events w/ track which ###
   // ###     starts at the front face      ###
   bool TrackTrjPtsZCut = false;
   
   // ### Recording the index of the track which ###
   // ###   starts at the front face of the TPC  ###
   bool PreLimTrackIndex[500] = {false};
   
   // ##################################################
   // ### Defining a dummy variable used for sorting ###
   // ##################################################
   double dummyXpoint = 999, dummyYpoint = 999, dummyZpoint = 100, dummyPointTrkInd = -1;
   double dummypoint_TempTrjX = 999, dummypoint_TempTrjY = 999, dummypoint_TempTrjZ = 999;
   double dummyTrkX[200] = {0.}, dummyTrkY[200] = {0.}, dummyTrkZ[200] = {100.};
   double dummyTrk_pHat0X[200] = {0.}, dummyTrk_pHat0Y[200] = {0.}, dummyTrk_pHat0Z[200] = {0.};
   double dummyTrk_Theta[200] = {0.}, dummyTrk_Phi[200] = {0.};
   double dummyTrk_Index[200] = {0.};
   
   int nUpStreamTrk = 0;
   
   // ###########################
   // ### Looping over tracks ###
   // ###########################
   for(int iTrk = 0; iTrk < ntracks_reco; iTrk++)
      {
      
      float tempZpoint = 100;
      // ########################################################
      // ### Looping over the trajectory points for the track ###
      // ########################################################
      for(int iTrjPt = 0; iTrjPt < nTrajPoint[iTrk]; iTrjPt++)
         {
	 
	 // ################################################################################ 
         // ### Tracking the lowest Z point that is inside fiducial boundries of the TPC ###
	 // ################################################################################
	 // ### Resetting the variables for each track ###
         dummyXpoint = 999, dummyYpoint = 999, dummyZpoint = 999;
	 
	 // ###########################################################################
	 // ### Setting our dummypoints if this is the lowest Z point on this track ###
	 // ###           and still within the active volume of the TPC             ###
	 // ###########################################################################
	 if(trjPt_Z[iTrk][iTrjPt] < tempZpoint && trjPt_Z[iTrk][iTrjPt] > ZLowerFid && //<---Note: the variable "trjPt_Z[iTrk][iTrjPt]"
	    trjPt_Y[iTrk][iTrjPt] > YLowerFid && trjPt_Y[iTrk][iTrjPt] < YUpperFid &&       // is the z position of the 3d point for the iTrk
	    trjPt_X[iTrk][iTrjPt] > XLowerFid && trjPt_X[iTrk][iTrjPt] < XUpperFid )
	     
	    {
	    dummyXpoint = trjPt_X[iTrk][iTrjPt];
	    dummyYpoint = trjPt_Y[iTrk][iTrjPt];
	    dummyZpoint = trjPt_Z[iTrk][iTrjPt];
	    
	    dummypoint_TempTrjX = pHat0_X[iTrk][iTrjPt];
	    dummypoint_TempTrjY = pHat0_Y[iTrk][iTrjPt];
	    dummypoint_TempTrjZ = pHat0_Z[iTrk][iTrjPt];
	    
	    dummyPointTrkInd = iTrk;
	    
	    tempZpoint = trjPt_Z[iTrk][iTrjPt];
	    }//<---End looking for the most upstream point
        
	 // ### Only passing events with a track that has ###
	 // ###  a spacepoint within the first N cm in Z  ### 
	 // ###    And requiring it to be inside the TPC  ###
	 if(dummyZpoint < FirstSpacePointZPos)
	    {
	    
	    dummyTrkX[nUpStreamTrk] = dummyXpoint;
	    dummyTrkY[nUpStreamTrk] = dummyYpoint;
	    dummyTrkZ[nUpStreamTrk] = dummyZpoint;
	  
	    dummyTrk_pHat0X[nUpStreamTrk] = dummypoint_TempTrjX;
	    dummyTrk_pHat0Y[nUpStreamTrk] = dummypoint_TempTrjY;
	    dummyTrk_pHat0Z[nUpStreamTrk] = dummypoint_TempTrjZ;
	    dummyTrk_Index[nUpStreamTrk] = dummyPointTrkInd;
	    
	    nUpStreamTrk++;
	    
	    TrackTrjPtsZCut = true;
	    }
	 }//<---End looping over nspts	
	 
      // ### Filling the most upstream spacepoint for this track ###
      hdataUpstreamZPos->Fill(tempZpoint);
      
      // ### Recording that this track is a "good Track if ###
      // ###  it has a space point in the first N cm in Z  ###
      if(TrackTrjPtsZCut){ PreLimTrackIndex[iTrk] = true;}
      	 
      }//<---End nTPCtrk loop
      
   // ###############################################
   // ### Skipping events that don't have a track ###
   // ###   in the front of the TPC (Z) Position  ###
   // ###############################################
   if(!TrackTrjPtsZCut){continue;}
   // ### Counting Events w/ front face TPC Track ###
   nEvtsTrackZPos++;
   
   // ###############################################################
   // ### Making plot of number of tracks as a function of length ###
   // ###############################################################
   //LowZCut();
   
   
   //=======================================================================================================================
   //					Cutting on the number of tracks in the upstream TPC
   //=======================================================================================================================
   
   int nLowZTracksInTPC = 0;
   // ################################################################
   // ### Initializing variables for study of low Z track location ###
   // ################################################################
   bool LowZTrackInTPC = false;
   
   float templowz1 = 0;
   float templowz2 = 0;
   
   
    // #################################################################
    // ### Only keeping events if there is less than N tracks in the ###
    // ###    first ## cm of the TPC (to help cut out EM Showers     ###
    // #################################################################
    for(size_t nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ### Start by assuming this track is not in the ###
      // ###          low Z part of the TPC             ###
      LowZTrackInTPC = false;
           
      // ##################################################
      // ### Looping over the spacepoints for the track ###
      // ##################################################
      for(size_t nspts = 0; nspts < nTrajPoint[nTPCtrk]; nspts++)
         {
	 
	 // ##################################################
	 // ### Count this track if it has a spacepoint in ###
	 // ###       the low Z region of the TPC          ###
	 // ##################################################
	 if(trkz[nTPCtrk][nspts] < UpperPartOfTPC)
	    {  
	    if(trky[nTPCtrk][nspts] > YLowerFid && trky[nTPCtrk][nspts] < YUpperFid && 
	       trkx[nTPCtrk][nspts] > XLowerFid && trkx[nTPCtrk][nspts] < XUpperFid)
	        {LowZTrackInTPC = true; templowz1 = trkz[nTPCtrk][nspts];}
		
            }//<---End counting if 
	
         }//<---End nspts loop
      
      // ##################################################################
      // ### If the track was in the "UpperPartOfTPC", bump the counter ###
      // ##################################################################
      if(LowZTrackInTPC)
         {
	 
	 nLowZTracksInTPC++;
	 }//<---End counting track in the Upstream part

      }//<---End nTPCtrk
    
    
     
    // ### Skipping the event if there are too many ###
    // ###       low Z tracks in the event          ###
    if(nLowZTracksInTPC > nLowZTracksAllowed || nLowZTracksInTPC == 0){continue;}  
    
    // ### Counting the event if it passes ###
    nLowZTrkEvents++;
    
    
   
    
   //=======================================================================================================================
   //				Matching the MC Particle to the Reco Track (similar to the WC Track match)
   //=======================================================================================================================
   
   // ################################################
   // ### Calculating the angles for the Geant4 MC ###
   // ################################################
   TVector3 z_hat_MC(0,0,1);
   TVector3 p_hat_0_MC;
   
   // ### Setting the vector for the MC using the ###
   // ###  extrapolated Momentum vector   ###
   p_hat_0_MC.SetX(g4Primary_Px[0]);
   p_hat_0_MC.SetY(g4Primary_Py[0]);
   p_hat_0_MC.SetZ(g4Primary_Pz[0]); 
   
   // ### Getting everything in the same convention ###
   float mcPhi = 0;
   float mcTheta = 0;
   
   // === Calculating Theta for MC ===
   mcTheta = acos(z_hat_MC.Dot(p_hat_0_MC)/p_hat_0_MC.Mag());
   
   // === Calculating Phi for MC ===
   //---------------------------------------------------------------------------------------------------------------------
   if( p_hat_0_MC.Y() > 0 && p_hat_0_MC.X() > 0 ){ mcPhi = atan(p_hat_0_MC.Y()/p_hat_0_MC.X()); }
   else if( p_hat_0_MC.Y() > 0 && p_hat_0_MC.X() < 0 ){ mcPhi = atan(p_hat_0_MC.Y()/p_hat_0_MC.X())+3.141592654; }
   else if( p_hat_0_MC.Y() < 0 && p_hat_0_MC.X() < 0 ){ mcPhi = atan(p_hat_0_MC.Y()/p_hat_0_MC.X())+3.141592654; }
   else if( p_hat_0_MC.Y() < 0 && p_hat_0_MC.X() > 0 ){ mcPhi = atan(p_hat_0_MC.Y()/p_hat_0_MC.X())+6.28318; }
   else if( p_hat_0_MC.Y() == 0 && p_hat_0_MC.X() == 0 ){ mcPhi = 0; }//defined by convention
   else if( p_hat_0_MC.Y() == 0 )
      {
      if( p_hat_0_MC.X() > 0 ){ mcPhi = 0; }

      else{ mcPhi = 3.141592654; }

      }
   else if( p_hat_0_MC.X() == 0 )
      {
      if( p_hat_0_MC.Y() > 0 ){ mcPhi = 3.141592654/2; }
      else{ mcPhi = 3.141592654*3/2; }

      }
   //---------------------------------------------------------------------------------------------------------------------
   
   
   // ######################################################
   // ### Calculating the angles for the Upstream Tracks ###
   // ######################################################
   
   TVector3 z_hat_TPC(0,0,1);
   TVector3 p_hat_0_TPC;
   for(int aa = 0; aa < nUpStreamTrk; aa++)
      {
      // ### Setting the TVector ###
      p_hat_0_TPC.SetX(dummyTrk_pHat0X[aa]);
      p_hat_0_TPC.SetY(dummyTrk_pHat0Y[aa]);
      p_hat_0_TPC.SetZ(dummyTrk_pHat0Z[aa]);
      
      
      // ### Calculating TPC track theta ###
      dummyTrk_Theta[aa] = acos(z_hat_TPC.Dot(p_hat_0_TPC)/p_hat_0_TPC.Mag());
      
      // ### Calculating TPC track phi ###
      //---------------------------------------------------------------------------------------------------------------------
      if( p_hat_0_TPC.Y() > 0 && p_hat_0_TPC.X() > 0 ){ dummyTrk_Phi[aa] = atan(p_hat_0_TPC.Y()/p_hat_0_TPC.X()); }
      else if( p_hat_0_TPC.Y() > 0 && p_hat_0_TPC.X() < 0 ){ dummyTrk_Phi[aa] = atan(p_hat_0_TPC.Y()/p_hat_0_TPC.X())+3.141592654; }
      else if( p_hat_0_TPC.Y() < 0 && p_hat_0_TPC.X() < 0 ){ dummyTrk_Phi[aa] = atan(p_hat_0_TPC.Y()/p_hat_0_TPC.X())+3.141592654; }
      else if( p_hat_0_TPC.Y() < 0 && p_hat_0_TPC.X() > 0 ){ dummyTrk_Phi[aa] = atan(p_hat_0_TPC.Y()/p_hat_0_TPC.X())+6.28318; }
      else if( p_hat_0_TPC.Y() == 0 && p_hat_0_TPC.X() == 0 ){ dummyTrk_Phi[aa] = 0; }//defined by convention
      else if( p_hat_0_TPC.Y() == 0 )
         {
         if( p_hat_0_TPC.X() > 0 ){ dummyTrk_Phi[aa] = 0; }

         else{ dummyTrk_Phi[aa] = 3.141592654; }

         }
      else if( p_hat_0_TPC.X() == 0 )
         {
         if( p_hat_0_TPC.Y() > 0 ){ dummyTrk_Phi[aa] = 3.141592654/2; }
         else{ dummyTrk_Phi[aa] = 3.141592654*3/2; }

         }
      //---------------------------------------------------------------------------------------------------------------------
      
      }//<---End aa loop
   
   // =============================================================================================================
   // 				Cutting on the DeltaX and Delta Y between MC and Reco Track
   // =============================================================================================================
   
   bool MC_TPCMatch = false;
   int nDeltaMatch = 0;
   // ###################################
   // ### Loop over all the US Tracks ###
   // ###################################
   for(int bb = 0; bb < nUpStreamTrk; bb++)
      {
      float DeltaX = dummyTrkX[bb] - g4Primary_ProjX0[0];
      float DeltaY = dummyTrkY[bb] - g4Primary_ProjY0[0];
      float DeltaZ = dummyTrkZ[bb] - g4Primary_ProjZ0[0];
      
      hDeltaX->Fill(DeltaX);
      hDeltaY->Fill(DeltaY);
      hDeltaZ->Fill(DeltaZ);
      
      // ### Matching in Delta X and Delta Y and alpha ###
      if(DeltaX > DeltaXLowerBound && DeltaX < DeltaXUpperBound && DeltaY > DeltaYLowerBound && DeltaY < DeltaYUpperBound)
         {
	 MC_TPCMatch = true;
	 nDeltaMatch++;
	 }//<---End matching
      
      }//<---End bb loop
   
   if(!MC_TPCMatch || nDeltaMatch < 1 || nDeltaMatch > 1){continue;}
   nEvtsMCTrackMatch++;
   
   // =============================================================================================================
   // 				Cutting on the Alpha Angle between MC and Reco Track
   // =============================================================================================================
   
   bool AlphaMatch = false;
   int RecoTrackIndex = -1;
   // #########################################################
   // ### Define the unit vectors for the MC and TPC Tracks ###
   // #########################################################
   TVector3 theUnitVector_MC;
   TVector3 theUnitVector_TPCTrack;
   
   // ###################################
   // ### Loop over all the US Tracks ###
   // ###################################
   for(int bb = 0; bb < nUpStreamTrk; bb++)
      {
      
      // === MC Unit Vector ===
      theUnitVector_MC.SetX(sin(mcTheta)*cos(mcPhi));
      theUnitVector_MC.SetY(sin(mcTheta)*sin(mcPhi));
      theUnitVector_MC.SetZ(cos(mcTheta));
   
      // === TPC Track Unit Vector ===
      theUnitVector_TPCTrack.SetX(sin(dummyTrk_Theta[bb])*cos(dummyTrk_Phi[bb]));
      theUnitVector_TPCTrack.SetY(sin(dummyTrk_Theta[bb])*sin(dummyTrk_Phi[bb]));
      theUnitVector_TPCTrack.SetZ(cos(dummyTrk_Theta[bb]));
      
      // ###########################################################
      // ### Calculating the angle between WCTrack and TPC Track ###
      // ###########################################################
      float alpha = ( acos(theUnitVector_MC.Dot(theUnitVector_TPCTrack)) )* (180.0/3.141592654);
      
      hAlpha->Fill(alpha);
      
      // ### Setting the boolian for the true match ###
      if(alpha < alphaCut)
         {
	 AlphaMatch = true;
	 RecoTrackIndex = dummyTrk_Index[bb];
	 }
      
      }//<---End bb loop
   
   // #############################################################
   // ### Skipping the event if there is no good match in alpha ###
   // #############################################################
   if(!AlphaMatch){continue;}
   nEventsPassingAlpha++;
   
   
   
   // ===========================================================================================================================================
   // 						Vetoing Shower Like Events 
   // ===========================================================================================================================================   
   
   int nShortTrks = 0;
   // ###############################
   // ### Looping over TPC tracks ###
   // ###############################
   for(size_t nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      
      // ### If the track is shorter than our cut ###
      if(trklength[nTPCtrk] < ShortTkLength)
         {
	 nShortTrks++;
	 
	 }
	 
      }//<---End nTPCtrk
   
   // ### Skipping the event if there are too many short tracks ###
   if(nShortTrks > nShortTracksAllowed){continue;}
   
   // ### Bumping the counter ###
   nNonShowerEvents++;
   
   
   
   // ===========================================================================================================================================
   // 						Calculating the cross-section 
   // ===========================================================================================================================================   
   
   // ### The assumed energy loss between the cryostat and the TPC ###
       float entryTPCEnergyLoss = 40.;//DifferenceInEnergy;//36; //MeV

   // ### The assumed mass of the incident particle (here we assume a pion) ###
   float mass = 139.57;
   
   // #################################################
   // ### Setting a flag to exclude exiting tracks  ###
   // ###  from the numerator of the cross-section  ###
   // #################################################
   
   bool ExitingTrack = false;
   
   // #############################################################
   // ### Calculating the momentum from the MC Primary Particle ###
   // #############################################################
   float momentum = sqrt( (g4Primary_Px[0]*g4Primary_Px[0]) + (g4Primary_Py[0]*g4Primary_Py[0]) + (g4Primary_Pz[0]*g4Primary_Pz[0]) );
   hMCInitialMom->Fill(momentum,EventWeight);
   
   // ###   Calculating the initial Kinetic Energy    ###
   // ### KE = Energy - mass = (p^2 + m^2)^1/2 - mass ###   
   float kineticEnergy = pow( (momentum*momentum) + (mass*mass) ,0.5) - mass;
   
   // ### The kinetic energy is that which we calculated ###
   // ###       minus the calculated energy loss         ###
   kineticEnergy -= entryTPCEnergyLoss;
   
   // ### Filling the initial kinetic energy plot ###
   hMCInitalKE->Fill(kineticEnergy,EventWeight);
    
       double InitialKinEnAtTPC = 0.;
       InitialKinEnAtTPC = kineticEnergy;
   
   // ########################################################################
   // ### Variables for the track we are calculating the cross-section for ###
   // ########################################################################
   double Piondedx[1000]={0.};
   double Pionresrange[1000]={0.};
   double Pionpitchhit[1000]={0.};
   int nPionSpts = 0;
   double PionSumEnergy = 0;
   
   // ### Variables for determining the matching of the end point ###
   float TrackEndX = 999, TrackEndY = 999, TrackEndZ = 999;
   
   // ################################
   // ### Loop over all TPC Tracks ###
   // ################################
   for(size_t nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      if(nTPCtrk != RecoTrackIndex){continue;}
          
      // ### Recording the end-point of this track ###
      TrackEndX = trkendx[nTPCtrk];
      TrackEndY = trkendy[nTPCtrk];
      TrackEndZ = trkendz[nTPCtrk];
      zInt_Reco = TrackEndZ;
   
      
      hdataPionTrackEndX->Fill(TrackEndX);
      hdataPionTrackEndY->Fill(TrackEndY);
      hdataPionTrackEndZ->Fill(TrackEndZ);
      
      // ### Recording the start-point of this track ###
      
      hdataPionTrackStartX->Fill(trkvtxx[nTPCtrk]);
      hdataPionTrackStartY->Fill(trkvtxy[nTPCtrk]);
      hdataPionTrackStartZ->Fill(trkvtxz[nTPCtrk]);
      
      RecoLength = trklength[nTPCtrk];
      
      
      
      // #################################################
      // ### If this tracks end point is at a boundary ###
      // ###   then tag this track as "through-going"  ###
      // #################################################
      if(TrackEndX < 1   || TrackEndX > 42.0 || TrackEndY > 19 ||
         TrackEndY < -19 || TrackEndZ > 89.0)
	 {ExitingTrack = true;
         cout << "This is a crossing track" << endl;
	 //continue;
	 }
         
         if(!ExitingTrack){
	 hRecoTruth->Fill(zInt_Reco,zInt_Truth);
	 hRecoLength->Fill(RecoLength);
         hRecoTruthLength->Fill(RecoLength,TrueLength);
	 }
          hPIDA->Fill(trkpida[nTPCtrk][1]);
      
      nPionSpts = 0;
      int countWeird =0;
      int countBigWeird=0;
      
      // ###################################################
      // ### Looping over the spacepoints for this track ###
      // ###################################################
      for(size_t nspts = 0; nspts < ntrkhits[nTPCtrk]; nspts++)
         {
	 // ###                 Note: Format for this variable is:             ###
	 // ### [trk number][plane 0 = induction, 1 = collection][spts number] ###
         Piondedx[nPionSpts]     = trkdedx[nTPCtrk][1][nspts];// * 0.90;//<----Scaling dEdX
	 
	 Pionresrange[nPionSpts] = trkrr[nTPCtrk][1][nspts];
         Pionpitchhit[nPionSpts] = trkpitchhit[nTPCtrk][1][nspts];
	 
      
      //cout << "ehi "<< Piondedx[nPionSpts] << " " << Pionresrange[nPionSpts] << endl;
      
	 // ############ FIXING THE TRACK CALORIMETRY ISSUES!!!! (1) #######
	 
	 // ### Putting in a fix in the case that the dE/dX is negative in this step ### 
	 // ###  then take the point before and the point after and average them
	 if(Piondedx[nPionSpts] < 0. && nspts < ntrkhits[nTPCtrk] && nspts > 0)
	    {
	      Piondedx[nPionSpts]=2.4;
	      continue;
	    }
	/* if(Piondedx[nPionSpts] < 0. && nspts < ntrkhits[nTPCtrk] && nspts > 0)
	    {
	      // cout << "negative dEdx 1 " << Piondedx[nPionSpts] << endl;
	      Piondedx[nPionSpts] = ( (trkdedx[nTPCtrk][1][nspts - 1] + trkdedx[nTPCtrk][1][nspts + 1]) / 2);}
	    
	    cout << "corrected dEdx " << Piondedx[nPionSpts] << endl;
	    // ### If this didn't fix it, then just put in a flat 2.4 MeV / cm fix ###
	 if(Piondedx[nPionSpts] < 0.)
	    {
	    cout << "negative dEdx 2 " << Piondedx[nPionSpts] << endl;
	    Piondedx[nPionSpts] = 2.4;   
	    continue;
	    }*/
	 
	
         
         
	 PionSumEnergy = (Piondedx[nPionSpts] * Pionpitchhit[nPionSpts]) + PionSumEnergy;
	 
	 // ### Recording the dE/dX ###
	 hdataPiondEdX->Fill(Piondedx[nPionSpts], EventWeight);
	 // ### Recording the residual range ###
	 hdataPionRR->Fill(Pionresrange[nPionSpts]);
	 // ### Recording the Pitch ###
	 hdataPionTrkPitch->Fill(Pionpitchhit[nPionSpts], EventWeight);
	 
	 // ### Filling 2d dE/dX vs RR ###
	 hdataPiondEdXvsRR->Fill(Pionresrange[nPionSpts], Piondedx[nPionSpts]);
	 
	 nPionSpts++;
	 
         }//<---End nspts loop
         
	  
	  // ############ FIXING THE TRACK CALORIMETRY ISSUES!!!! (2) #######
	  
	  for(size_t caloPoints = 0; caloPoints < nPionSpts; caloPoints++)
           {
	  //cout << "corrected dEdx " << Piondedx[nPionSpts] << endl;
	//Fix in case of extreme fluctuations of the dEdx (if more than the dEdx expected for a stopping proton at the endpoint)
	if(Piondedx[caloPoints] > 40. && caloPoints == (nPionSpts-1) ){
	  //cout << "dEdx > 40 MeV/cm" << endl; 
	  //cout << run << " " << subrun << " " << event << endl;
	    hdEdxBigWeird->Fill(Piondedx[caloPoints]);
	    Piondedx[caloPoints] = trkdedx[nTPCtrk][1][caloPoints - 1];
	    countBigWeird++;
	    }
	 else if(Piondedx[caloPoints] > 40. && caloPoints < (nPionSpts-1) && caloPoints > 0.)
	    {
	      hdEdxBigWeird->Fill(Piondedx[caloPoints]);
	      Piondedx[caloPoints] = ( (trkdedx[nTPCtrk][1][caloPoints - 1] + trkdedx[nTPCtrk][1][caloPoints + 1]) / 2.);
	      countBigWeird++;
	    }
	    
	   //  Fix in case of big dEdx fluctuations along track
	   if(Piondedx[caloPoints] > 15. && Pionresrange[caloPoints] > 10. && caloPoints > 0.&& caloPoints < (nPionSpts-1) ){
	     countWeird++;
	     hdEdxWeird->Fill(Piondedx[caloPoints]);
	    // cout << "ehi "<< Piondedx[nPionSpts] << " " << Pionresrange[nPionSpts] << endl;
	     if(Piondedx[caloPoints-1] > 15.){
	       if(Piondedx[caloPoints+1] > 15. ){
		Piondedx[caloPoints] = ( (trkdedx[nTPCtrk][1][caloPoints - 2] + trkdedx[nTPCtrk][1][caloPoints + 2]) / 2.);
		}
		else{
		Piondedx[caloPoints] = ( (trkdedx[nTPCtrk][1][caloPoints - 2] + trkdedx[nTPCtrk][1][caloPoints + 1]) / 2.);
		}
	     }
	      else if(Piondedx[caloPoints-1] <= 15.){
	        if(Piondedx[caloPoints+1] > 15. ){
	     Piondedx[caloPoints] = ( (trkdedx[nTPCtrk][1][caloPoints - 1] + trkdedx[nTPCtrk][1][caloPoints + 2]) / 2.);
		}
		else{
		Piondedx[caloPoints] = ( (trkdedx[nTPCtrk][1][caloPoints - 2] + trkdedx[nTPCtrk][1][caloPoints + 1]) / 2.);
		}
	     }
	     else Piondedx[caloPoints] = ( (trkdedx[nTPCtrk][1][caloPoints - 1] + trkdedx[nTPCtrk][1][caloPoints + 1]) / 2.);
	    // cout << "corrected "<< Piondedx[nPionSpts] << " " << Pionresrange[nPionSpts] << endl;
	   }
	   }//<---End nspts loop
	   
          hWeirdCaloPts->Fill(countWeird);
	  hBigWeirdCaloPts->Fill(countBigWeird);
      
      }//<---End nTPCtrk loop
   
   
   // ###################################
   // ### Filling the Delta End Point ###
   // ###################################
   float DeltaEndX = g4Primary_Xf[0] - TrackEndX;
   float DeltaEndY = g4Primary_Yf[0] - TrackEndY;
   float DeltaEndZ = g4Primary_Zf[0] - TrackEndZ;
      
   hDeltaEndX->Fill(DeltaEndX);
   hDeltaEndY->Fill(DeltaEndY);
   hDeltaEndZ->Fill(DeltaEndZ);
   
   if(DeltaEndZ > 3 || DeltaEndZ < 3){counter++;}
   
   if(g4PrimaryProcess[0] == 1){hDeltaEndZInElastic->Fill(DeltaEndZ);}
   if(g4PrimaryProcess[0] == 2){hDeltaEndZNeutronInElastic->Fill(DeltaEndZ);}
   if(g4PrimaryProcess[0] == 3){hDeltaEndZHadElastic->Fill(DeltaEndZ);}
   if(g4PrimaryProcess[0] == 4){hDeltaEndZnCap->Fill(DeltaEndZ);}
   if(g4PrimaryProcess[0] == 5){hDeltaEndZnuclearCapatureAtRest->Fill(DeltaEndZ);}
   if(g4PrimaryProcess[0] == 6){hDeltaEndZDecay->Fill(DeltaEndZ);}
   if(g4PrimaryProcess[0] == 7){hDeltaEndZKaonZeroInElastic->Fill(DeltaEndZ);}
   if(g4PrimaryProcess[0] == 8){hDeltaEndZCoulombScat->Fill(DeltaEndZ);}
   if(g4PrimaryProcess[0] == 9){hDeltaEndZMuMinusCapture->Fill(DeltaEndZ);}
   if(g4PrimaryProcess[0] == 10){hDeltaEndZProtonInelastic->Fill(DeltaEndZ);}
   
   if(g4PrimaryProcess[0] == 1){hDeltaEndYInElastic->Fill(DeltaEndY);}
   if(g4PrimaryProcess[0] == 2){hDeltaEndYNeutronInElastic->Fill(DeltaEndY);}
   if(g4PrimaryProcess[0] == 3){hDeltaEndYHadElastic->Fill(DeltaEndY);}
   if(g4PrimaryProcess[0] == 4){hDeltaEndYnCap->Fill(DeltaEndY);}
   if(g4PrimaryProcess[0] == 5){hDeltaEndYnuclearCapatureAtRest->Fill(DeltaEndY);}
   if(g4PrimaryProcess[0] == 6){hDeltaEndYDecay->Fill(DeltaEndY);}
   if(g4PrimaryProcess[0] == 7){hDeltaEndYKaonZeroInElastic->Fill(DeltaEndY);}
   if(g4PrimaryProcess[0] == 8){hDeltaEndYCoulombScat->Fill(DeltaEndY);}
   if(g4PrimaryProcess[0] == 9){hDeltaEndYMuMinusCapture->Fill(DeltaEndY);}
   if(g4PrimaryProcess[0] == 10){hDeltaEndYProtonInelastic->Fill(DeltaEndY);}
   
   if(g4PrimaryProcess[0] == 1){hDeltaEndXInElastic->Fill(DeltaEndX);}
   if(g4PrimaryProcess[0] == 2){hDeltaEndXNeutronInElastic->Fill(DeltaEndX);}
   if(g4PrimaryProcess[0] == 3){hDeltaEndXHadElastic->Fill(DeltaEndX);}
   if(g4PrimaryProcess[0] == 4){hDeltaEndXnCap->Fill(DeltaEndX);}
   if(g4PrimaryProcess[0] == 5){hDeltaEndXnuclearCapatureAtRest->Fill(DeltaEndX);}
   if(g4PrimaryProcess[0] == 6){hDeltaEndXDecay->Fill(DeltaEndX);}
   if(g4PrimaryProcess[0] == 7){hDeltaEndXKaonZeroInElastic->Fill(DeltaEndX);}
   if(g4PrimaryProcess[0] == 8){hDeltaEndXCoulombScat->Fill(DeltaEndX);}
   if(g4PrimaryProcess[0] == 9){hDeltaEndXMuMinusCapture->Fill(DeltaEndX);}
   if(g4PrimaryProcess[0] == 10){hDeltaEndXProtonInelastic->Fill(DeltaEndX);}
   
   
       if(!ExitingTrack){
           //cout << "Final energy for contained tracks " << kineticEnergy << endl;
           fPionFinalKinEn->Fill(kineticEnergy);
       }
       
       
       
       
       for(size_t nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
       {
           bool noIntEvt=false;
	   
          // cout << "TpcTrack " << nTPCtrk << endl;
           if(nTPCtrk != RecoTrackIndex){continue;}
           
           double ordereddEdx[1000]={0.};
           double orderedRR[1000]={0.};
           double orderedPitch[1000]={0.};
           // ###################################################
	   //### For the TPC track which is matched to the WC track:
           // ### Looping over the spacepoints for this track  && re-ordering dEdx/ResRange/Pitch vectors ###
           // ###################################################
           size_t dimCalo = 0;
           dimCalo = nPionSpts;
	   bool highLastdEdx = false;
	   bool extraLastdEdx = false;
           //cout << "N calo points " << dimCalo << " " << nPionSpts << endl;
           for(size_t caloPoints = 0; caloPoints < nPionSpts; caloPoints++)
           {
               
              // cout <<  Piondedx[caloPoints] << " " << Pionresrange[caloPoints] << endl;
               if(caloPoints < nPionSpts-1){
                   //cout << "pippo" << endl;
                   if(Pionresrange[caloPoints] > Pionresrange[caloPoints+1]) {
                       //If the previous caloHit RR is higher than the next, that's the starting point of the trac
                      ordereddEdx[caloPoints]=Piondedx[caloPoints];
                       orderedRR[caloPoints]= Pionresrange[caloPoints];
                       orderedPitch[caloPoints]=Pionpitchhit[caloPoints];
                   }
                   else {
                      // cout << "pluto" << endl;
                       ordereddEdx[dimCalo-1-caloPoints]= Piondedx[caloPoints];
                       orderedRR[dimCalo-1-caloPoints]= Pionresrange[caloPoints];
                       orderedPitch[dimCalo-1-caloPoints]=Pionpitchhit[caloPoints];
                   }
                   //cout  << " rr: " << orderedRR[caloPoints] << " dEdx: " << ordereddEdx[caloPoints] << " pitch: " << orderedPitch[caloPoints] << endl;
               }
               
             if(caloPoints == nPionSpts-1)  {
	       
	     if(Pionresrange[caloPoints] > Pionresrange[caloPoints-1]){
	               ordereddEdx[dimCalo-1-caloPoints]= Piondedx[caloPoints];
                       orderedRR[dimCalo-1-caloPoints]= Pionresrange[caloPoints];
                       orderedPitch[dimCalo-1-caloPoints]=Pionpitchhit[caloPoints];
	     }
	     else{
	               ordereddEdx[caloPoints]=Piondedx[caloPoints];
                       orderedRR[caloPoints]= Pionresrange[caloPoints];
                       orderedPitch[caloPoints]=Pionpitchhit[caloPoints];
	     }
	     }
             
           }//<---End calo points
           int NweirddEdx =0;
	   int NExtraweirddEdx =0;
	   
           if(!ExitingTrack){
	     
	     //Tag piCapture and piDecay events
	     
	    /* if(g4PrimaryProcess[0] == 12) {
		captureBert++;
		noIntEvt = true;
		//cout << " This is a PiMinus capture in the TPC (BertiniCapture) " << endl;
		}
		
		if(g4PrimaryProcess[0] == 6) {
		//PiDecay
		noIntEvt = true;
		}*/
		
           //dEdx vs RR for contained tracks
	   Double_t tempEn=0.;
	    tempEn= kineticEnergy;
	   for(size_t caloPoints = 0; caloPoints < nPionSpts; caloPoints++){
               hdataPiondEdXvsRR0->Fill(Pionresrange[caloPoints], Piondedx[caloPoints]);
	       hdataPiondEdXvsEn->Fill(tempEn,Piondedx[caloPoints]);
	       tempEn=tempEn-Piondedx[caloPoints]*Pionpitchhit[caloPoints];
	       //cout <<  Piondedx[caloPoints] << " " << Pionresrange[caloPoints] << endl;
	      
           }
               
               PIDAEfin->Fill(trkpida[nTPCtrk][1],tempEn);//pida vs Efin
               PIDAEin->Fill(trkpida[nTPCtrk][1],InitialKinEnAtTPC); //pida vs Ein
               
	       
	   size_t PiRange=0;
           PiRange = nPionSpts;
           //Look at DeltaE in last 3 spacepoints
           double lastDeltaE=0.;
	   
	   
           if(PiRange >= 5){
           for(size_t k= PiRange-1; k > PiRange-5; k--){
              // cout << k << " rr: " << orderedRR[k] << " dEdx: " << ordereddEdx[k] << " pitch: " << orderedPitch[k] << endl;
               lastDeltaE+=(orderedPitch[k]*ordereddEdx[k]);
	       if(ordereddEdx[k] > 35. &&ordereddEdx[k] < 50.){ 
		 //cout << "dEdx > 35 MeV/cm and < 50 MeV/cm in last 6 space pts" << endl; 
	        // cout << run << " " << event << " " << ordereddEdx[k] << " " << orderedRR[k] << endl;
		 weirddEdxVSrr->Fill(orderedRR[k],ordereddEdx[k]);
		 //NweirddEdx++;
		// highLastdEdx = true; 
	       }
		 else if(ordereddEdx[k] > 50.){
		 cout << "dEdx > 50 MeV/cm in last 4 space pts" << endl; 
	        // cout << run << " " << event << " " << ordereddEdx[k] << " " << orderedRR[k] << endl;
		 //extraLastdEdx = true;
		// NExtraweirddEdx++;
		 }
           }
           hlastDeltaE->Fill(lastDeltaE);
           }
	 
	 
           /*else{
	   cout << "ehi we have < 5 spacepts for this track! " << endl;
	   for(size_t caloPoints = 0; caloPoints < nPionSpts; caloPoints++){
	     cout << kineticEnergy << " " << Pionresrange[caloPoints] << " " << Piondedx[caloPoints] << endl;
	   }
	   }*/
               
               PIDAEfin->Fill(trkpida[nTPCtrk][1],tempEn);//pida vs Efin
               PIDAEin->Fill(trkpida[nTPCtrk][1],InitialKinEnAtTPC); //pida vs Ein
               PIDALastDE->Fill(trkpida[nTPCtrk][1],lastDeltaE);
	       
	       //cout << trkpida[nTPCtrk][1] << " " << InitialKinEnAtTPC << " " << tempEn << " " << lastDeltaE << endl;
               
               //Look for Stopping tracks if initial energy less than 300 MeV
               if(InitialKinEnAtTPC <  300.){
                   //if(lastDeltaE >= 10. && lastDeltaE <= 20.){
		    if(trkpida[nTPCtrk][1]>=9 && trkpida[nTPCtrk][1]<=13){
                   if(lastDeltaE >= 7. && lastDeltaE <= 25.){
                      
                   //cout << "Possible stopping track "	<< endl;
                   //std::cout << "Track " << nTPCtrk << " Track PIDA " << trkpida[nTPCtrk][1] << std::endl;
                   hPIDALow->Fill(trkpida[nTPCtrk][1]);
                           hlastDeltaEStopPi->Fill(lastDeltaE);
                   stopping++;
                   for(size_t caloPoints = 0; caloPoints < nPionSpts; caloPoints++){
                       hdataPiondEdXvsRR1->Fill(Pionresrange[caloPoints], Piondedx[caloPoints]);
                   }
                   //continue;
                       stoppingEvt = true;
		       cout << "This is a stopping pion " << endl;
                            }
                            }
                        }

               for(size_t caloPoints = 0; caloPoints < nPionSpts; caloPoints++){
                   hdataPiondEdXvsRR2->Fill(Pionresrange[caloPoints], Piondedx[caloPoints]);
               }
               hPIDAFin->Fill(trkpida[nTPCtrk][1]);
               
	       if(highLastdEdx == true){
		 weirdEvt++;
	        for(size_t caloPoints = 0; caloPoints < nPionSpts; caloPoints++){
                   hdataPiondEdXvsRR4->Fill(Pionresrange[caloPoints], Piondedx[caloPoints]);
               }
	       }
               
               if(extraLastdEdx == true){
	        for(size_t caloPoints = 0; caloPoints < nPionSpts; caloPoints++){
                   hdataPiondEdXvsRR3->Fill(Pionresrange[caloPoints], Piondedx[caloPoints]);
               }
               if(NweirddEdx < 2 && NExtraweirddEdx > 0){
		 cout << "rimuovi evento" <<endl;
	       //continue;
	       }
	       }
	       
	       
	       
           }
           
           // ###########################################################
           // ### Looping over the spacepoints to fill the histograms ###
           // ###########################################################
           //std::cout << "Filling histos " << std::endl;
           for(size_t npoints = 0; npoints < nPionSpts; npoints++)
           {
               // ### Filling the incidient histogram ###
               hdataPionIncidentKE->Fill(kineticEnergy, EventWeight);
	      // cout  << " rr: " << orderedRR[npoints] << " dEdx: " << ordereddEdx[npoints] << " pitch: " << orderedPitch[npoints] << endl;
               //cout << orderedRR[npoints] << endl; <--- still to fix the reordering for first and last points
               // ### Filling the interaction histogram for the last spt ###
	    /*   if(npoints == nPionSpts - 5){
		if(!ExitingTrack && highLastdEdx && NweirddEdx > 1){
		fPionInteractions->Fill(kineticEnergy, EventWeight);
		cout << "qui esci prima dal loop " << endl;
		 //cout << orderedRR[npoints] << endl;
		break;
		} 
	       }*/
               if(npoints == nPionSpts -1){
                   if(!ExitingTrack && !stoppingEvt)// && !noIntEvt)// !stoppingEvt)
                   { //cout << "qui sono a riempire Nint per l'ultimo caloPoint" << endl;
		     fPionInteractions->Fill(kineticEnergy, EventWeight);}}
               
               //float energyLossInStep = Piondedx[npoints] * Pionresrange[npoints] * RecombinationFactor;
               //float energyLossInStep = Piondedx[npoints] * Pionpitchhit[npoints];
	       float energyLossInStep = ordereddEdx[npoints] * orderedPitch[npoints];
               
               
               kineticEnergy -= energyLossInStep;
               DeltaEreco +=energyLossInStep;
               
           }//<---End npoints loop
          
           if(!ExitingTrack){
           hRecoTruthDeltaE->Fill(DeltaEreco,DeltaEtruth);
	   }
           
       }//<---End nTPCtrk loop
       
       
   
   }//<---End jentry loop
//-------------------------------------------------------------------------------------------------------------------------------------------------





//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//						Coloring the histograms
hDeltaEndZInElastic->SetFillColor(kYellow+2);
hDeltaEndZInElastic->SetLineColor(kYellow+2);
hDeltaEndZInElastic->SetFillStyle(3006);
hStackDeltaEndZ->Add(hDeltaEndZInElastic);


hDeltaEndZNeutronInElastic->SetFillColor(kGreen+2);
hDeltaEndZNeutronInElastic->SetLineColor(kGreen+2);
hDeltaEndZNeutronInElastic->SetFillStyle(3002);
hStackDeltaEndZ->Add(hDeltaEndZNeutronInElastic);

hDeltaEndZHadElastic->SetFillColor(kCyan+3);
hDeltaEndZHadElastic->SetLineColor(kCyan+3);
hDeltaEndZHadElastic->SetFillStyle(3002);
hStackDeltaEndZ->Add(hDeltaEndZHadElastic);

hDeltaEndZnCap->SetFillColor(kBlue);
hDeltaEndZnCap->SetLineColor(kBlue);
hDeltaEndZnCap->SetFillStyle(3002);
hStackDeltaEndZ->Add(hDeltaEndZnCap);

hDeltaEndZnuclearCapatureAtRest->SetFillColor(kMagenta);
hDeltaEndZnuclearCapatureAtRest->SetLineColor(kMagenta);
hDeltaEndZnuclearCapatureAtRest->SetFillStyle(3002);
hStackDeltaEndZ->Add(hDeltaEndZnuclearCapatureAtRest);

hDeltaEndZDecay->SetFillColor(kRed+2);
hDeltaEndZDecay->SetLineColor(kRed+2);
hDeltaEndZDecay->SetFillStyle(3002);
hStackDeltaEndZ->Add(hDeltaEndZDecay);

hDeltaEndZKaonZeroInElastic->SetFillColor(kOrange+7);
hDeltaEndZKaonZeroInElastic->SetLineColor(kOrange+7);
hDeltaEndZKaonZeroInElastic->SetFillStyle(3002);
hStackDeltaEndZ->Add(hDeltaEndZKaonZeroInElastic);

hDeltaEndZCoulombScat->SetFillColor(kAzure+1);
hDeltaEndZCoulombScat->SetLineColor(kAzure+1);
hDeltaEndZCoulombScat->SetFillStyle(3002);
hStackDeltaEndZ->Add(hDeltaEndZCoulombScat);

hDeltaEndZMuMinusCapture->SetFillColor(kViolet-1);
hDeltaEndZMuMinusCapture->SetLineColor(kViolet-1);
hDeltaEndZMuMinusCapture->SetFillStyle(3002);
hStackDeltaEndZ->Add(hDeltaEndZMuMinusCapture);

hDeltaEndZProtonInelastic->SetFillColor(kBlack);
hDeltaEndZProtonInelastic->SetLineColor(kBlack);
hDeltaEndZProtonInelastic->SetFillStyle(3002);
hStackDeltaEndZ->Add(hDeltaEndZProtonInelastic);

////////////////////////////////////////////////////////////////////////

hDeltaEndYInElastic->SetFillColor(kYellow+2);
hDeltaEndYInElastic->SetLineColor(kYellow+2);
hDeltaEndYInElastic->SetFillStyle(3006);
hStackDeltaEndY->Add(hDeltaEndYInElastic);


hDeltaEndYNeutronInElastic->SetFillColor(kGreen+2);
hDeltaEndYNeutronInElastic->SetLineColor(kGreen+2);
hDeltaEndYNeutronInElastic->SetFillStyle(3002);
hStackDeltaEndY->Add(hDeltaEndYNeutronInElastic);

hDeltaEndYHadElastic->SetFillColor(kCyan+3);
hDeltaEndYHadElastic->SetLineColor(kCyan+3);
hDeltaEndYHadElastic->SetFillStyle(3002);
hStackDeltaEndY->Add(hDeltaEndYHadElastic);

hDeltaEndYnCap->SetFillColor(kBlue);
hDeltaEndYnCap->SetLineColor(kBlue);
hDeltaEndYnCap->SetFillStyle(3002);
hStackDeltaEndY->Add(hDeltaEndYnCap);

hDeltaEndYnuclearCapatureAtRest->SetFillColor(kMagenta);
hDeltaEndYnuclearCapatureAtRest->SetLineColor(kMagenta);
hDeltaEndYnuclearCapatureAtRest->SetFillStyle(3002);
hStackDeltaEndY->Add(hDeltaEndYnuclearCapatureAtRest);

hDeltaEndYDecay->SetFillColor(kRed+2);
hDeltaEndYDecay->SetLineColor(kRed+2);
hDeltaEndYDecay->SetFillStyle(3002);
hStackDeltaEndY->Add(hDeltaEndYDecay);

hDeltaEndYKaonZeroInElastic->SetFillColor(kOrange+7);
hDeltaEndYKaonZeroInElastic->SetLineColor(kOrange+7);
hDeltaEndYKaonZeroInElastic->SetFillStyle(3002);
hStackDeltaEndY->Add(hDeltaEndYKaonZeroInElastic);

hDeltaEndYCoulombScat->SetFillColor(kAzure+1);
hDeltaEndYCoulombScat->SetLineColor(kAzure+1);
hDeltaEndYCoulombScat->SetFillStyle(3002);
hStackDeltaEndY->Add(hDeltaEndYCoulombScat);

hDeltaEndYMuMinusCapture->SetFillColor(kViolet-1);
hDeltaEndYMuMinusCapture->SetLineColor(kViolet-1);
hDeltaEndYMuMinusCapture->SetFillStyle(3002);
hStackDeltaEndY->Add(hDeltaEndYMuMinusCapture);

hDeltaEndYProtonInelastic->SetFillColor(kBlack);
hDeltaEndYProtonInelastic->SetLineColor(kBlack);
hDeltaEndYProtonInelastic->SetFillStyle(3002);
hStackDeltaEndY->Add(hDeltaEndYProtonInelastic);


////////////////////////////////////////////////////////////////////////

hDeltaEndXInElastic->SetFillColor(kYellow+2);
hDeltaEndXInElastic->SetLineColor(kYellow+2);
hDeltaEndXInElastic->SetFillStyle(3006);
hStackDeltaEndX->Add(hDeltaEndXInElastic);


hDeltaEndXNeutronInElastic->SetFillColor(kGreen+2);
hDeltaEndXNeutronInElastic->SetLineColor(kGreen+2);
hDeltaEndXNeutronInElastic->SetFillStyle(3002);
hStackDeltaEndX->Add(hDeltaEndXNeutronInElastic);

hDeltaEndXHadElastic->SetFillColor(kCyan+3);
hDeltaEndXHadElastic->SetLineColor(kCyan+3);
hDeltaEndXHadElastic->SetFillStyle(3002);
hStackDeltaEndX->Add(hDeltaEndXHadElastic);

hDeltaEndXnCap->SetFillColor(kBlue);
hDeltaEndXnCap->SetLineColor(kBlue);
hDeltaEndXnCap->SetFillStyle(3002);
hStackDeltaEndX->Add(hDeltaEndXnCap);

hDeltaEndXnuclearCapatureAtRest->SetFillColor(kMagenta);
hDeltaEndXnuclearCapatureAtRest->SetLineColor(kMagenta);
hDeltaEndXnuclearCapatureAtRest->SetFillStyle(3002);
hStackDeltaEndX->Add(hDeltaEndXnuclearCapatureAtRest);

hDeltaEndXDecay->SetFillColor(kRed+2);
hDeltaEndXDecay->SetLineColor(kRed+2);
hDeltaEndXDecay->SetFillStyle(3002);
hStackDeltaEndX->Add(hDeltaEndXDecay);

hDeltaEndXKaonZeroInElastic->SetFillColor(kOrange+7);
hDeltaEndXKaonZeroInElastic->SetLineColor(kOrange+7);
hDeltaEndXKaonZeroInElastic->SetFillStyle(3002);
hStackDeltaEndX->Add(hDeltaEndXKaonZeroInElastic);

hDeltaEndXCoulombScat->SetFillColor(kAzure+1);
hDeltaEndXCoulombScat->SetLineColor(kAzure+1);
hDeltaEndXCoulombScat->SetFillStyle(3002);
hStackDeltaEndX->Add(hDeltaEndXCoulombScat);

hDeltaEndXMuMinusCapture->SetFillColor(kViolet-1);
hDeltaEndXMuMinusCapture->SetLineColor(kViolet-1);
hDeltaEndXMuMinusCapture->SetFillStyle(3002);
hStackDeltaEndX->Add(hDeltaEndXMuMinusCapture);

hDeltaEndXProtonInelastic->SetFillColor(kBlack);
hDeltaEndXProtonInelastic->SetLineColor(kBlack);
hDeltaEndXProtonInelastic->SetFillStyle(3002);
hStackDeltaEndX->Add(hDeltaEndXProtonInelastic);
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



// ===============================================================================================================
//					MAKING THE CROSS-SECTION PLOT
// ===============================================================================================================


// ###################################################################
// #### Looping over the exiting bins to extract the cross-section ###
// ###################################################################
for( int iBin = 1; iBin <= fPionInteractions->GetNbinsX(); ++iBin )
   {
   
   std::cout<<std::endl;
   // ### If an incident bin is equal to zero then skip that bin ###
   if( hdataPionIncidentKE->GetBinContent(iBin) == 0 )continue; //Temporary fix to ensure that no Infinities are propagated to pad
   
   // ### Cross-section = (Exit Bins / Incident Bins) * (1/Density) * (1/slab width) ###
   float TempCrossSection = (fPionInteractions->GetBinContent(iBin)/hdataPionIncidentKE->GetBinContent(iBin)) * (1/number_density) * (1/slab_width);
   
   //std::cout<<"Cross-Section before conversion to barns = "<<TempCrossSection<<std::endl;
   
   float crossSection = TempCrossSection * (1/1e-28); //To put this into barns
   //std::cout<<"Cross-Section = "<<crossSection<<std::endl;
   
   
   fCrossSection->SetBinContent(iBin,crossSection);
   
   float numError = pow(fPionInteractions->GetBinContent(iBin),0.5);
   float num = fPionInteractions->GetBinContent(iBin);

   
   if(num == 0){num = 1;}
   float term1 = numError/num;
   //std::cout<<"term1 = "<<term1<<std::endl;
   
   float denomError = pow(hdataPionIncidentKE->GetBinContent(iBin),0.5);
   float denom = hdataPionIncidentKE->GetBinContent(iBin);
   if(denom == 0){denom = 1;}
   float term2 = denomError/denom;
   //std::cout<<"term2 = "<<term2<<std::endl;
   float totalError = (TempCrossSection) * (pow( ( (term1*term1) + (term2*term2) ),0.5)) * (1/number_density) * (1/slab_width) * (1/1e-28) *(1e26);
   //std::cout<<"totalError = "<<totalError<<std::endl;
   fCrossSection->SetBinError(iBin,totalError);
       
   }//<---End iBin loop



// ========================================================================================================
// ===					EVENT REDUCTION TABLE						===
// ========================================================================================================
std::cout<<std::endl;
std::cout<<"###################################################################################"<<std::endl;
std::cout<<"### Number of Events in AnaModule                                         = "<<nTotalEvents<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ Primary MC which enters the TPC                   = "<<nEvtsGoodMC<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ Trk Z < "<<FirstSpacePointZPos<<"                                = "<<nEvtsTrackZPos<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ < "<<nLowZTracksAllowed<<" tracks in the first "<<UpperPartOfTPC<<" cm of the TPC     = "<<nLowZTrkEvents<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ ONE MC Particle Matched                               = "<<nEvtsMCTrackMatch<<" ###"<<std::endl;
std::cout<<"###              ( "<<DeltaXLowerBound<<" < Delta X < "<<DeltaXUpperBound<<" , "<<DeltaYLowerBound<<" < Delta Y < "<<DeltaYUpperBound<<" )             ###"<<std::endl;
std::cout<<"### Number of Events w/ angle alpha less the "<<alphaCut<<" degrees  = "<<nEventsPassingAlpha<<"         ###"<<std::endl;
std::cout<<"### Number of Events that are not Shower Like                        = "<<nNonShowerEvents<<std::endl;
std::cout<<"###################################################################################"<<std::endl;
std::cout<<std::endl;

std::cout<<"counter = "<<counter<<std::endl;
    
    std::cout<<"Stopping tagged = "<<stopping<<std::endl; //contained stopping pions
    std::cout << "MC pion captures (Bertini) " << captureBert << std::endl; //contained pion capture evts
    std::cout << "MC pion captures (CHips nuclear capture) " << capture << std::endl;
    
    std::cout << "Pion tracks with attached proton = " << protonAtt << std::endl;
    std::cout << "Evts with weird energy reco at endpoint (last DeltaE) " << weirdEvt << std::endl;


// ---------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------

// ===========================================================================================
// ============================  Writing out histograms to ROOT File =========================
// ===========================================================================================


// ### Reco Info ###
hdataUpstreamZPos->Write();
hdataNTracksvsZpos->Write();

// ### MC Info ###
hMCPrimaryStartX->Write();
hMCPrimaryStartY->Write();
hMCPrimaryStartZ->Write();
hMCPrimaryProjectedStartX->Write();
hMCPrimaryProjectedStartY->Write();
hMCPrimaryProjectedStartZ->Write();
hMCPrimaryEndX->Write();
hMCPrimaryEndY->Write();
hMCPrimaryEndZ->Write();
hMCPrimaryEndXvsZ->Write();
hMCPrimaryEndYvsZ->Write();
hMCPrimaryProcess->Write();
hMCPrimaryPx->Write();
hMCPrimaryPy->Write();
hMCPrimaryPz->Write();

hIntBefore->Write();
hIntIn->Write();

hAlpha->Write();
hDeltaX->Write();
hDeltaY->Write();
hDeltaZ->Write();  
hMCInitalKE->Write();
hMCInitialMom->Write();
hdataPiondEdX->Write();
hdataPionRR->Write();
hdataPionTrkPitch->Write();
hdataPionIncidentKE->Write();
fPionInteractions->Write();
fCrossSection->Write();
hdataPiondEdXvsRR->Write();
hdataPiondEdXvsRR0->Write();
hdataPiondEdXvsRR1->Write();
hdataPiondEdXvsRR2->Write();
hdataPiondEdXvsRR3->Write();
    hdataPiondEdXvsRR4->Write();
    
   hdataPiondEdXvsEn->Write();
   
//hDeltaEndX->Write();
//hDeltaEndY->Write();
//hDeltaEndZ->Write();

hTrueLength->Write();
hRecoLength->Write();

hRecoTruth->Write();
hRecoTruthLength->Write();
 hRecoTruthDeltaE->Write();

hMCELossUpstream->Write();
    
hPIDA->Write();
//hPIDALow->Write();
   // hPIDAFin->Write();
    hlastDeltaE->Write();
    /*hlastDeltaEattProt->Write();
    hlastDeltaEweird->Write();
    hlastDeltaEStopPi->Write();*/
    
  //hPIDAProbStop->Write();
    PIDAEfin->Write();
    PIDAEin->Write();
    PIDALastDE->Write();
    
fPionFinalKinEn->Write();

/*hWeirdCaloPts->Write();
hBigWeirdCaloPts->Write();
hdEdxWeird->Write();
hdEdxBigWeird->Write();*/

weirddEdxVSrr->Write();

/*hdataPionTrackEndX->Write();
hdataPionTrackEndY->Write();
hdataPionTrackEndZ->Write();
hdataPionTrackStartX->Write();
hdataPionTrackStartY->Write();
hdataPionTrackStartZ->Write();*/

}//<---End Loop Function








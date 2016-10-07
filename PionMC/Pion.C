#define Pion_cxx
#include "Pion.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <iostream>
#include <TVector3.h>

// ===================================================================================================================
// ====================================       PUT HISTOGRAMS HERE           ==========================================
// ===================================================================================================================

// *********************************** GEANT INFORMATION ****************************************************************


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
TH1D *hMCPrimaryPz = new TH1D("hMCPrimaryPz", "Primary Particle P_{z}", 250, 0 , 2500);

/////////////////////////////////// Primary Particle Process //////////////////////////////////////////
TH1D *hMCPrimaryProcess = new TH1D("hMCPrimaryProcess", "Primary Particle Process", 100, 0 , 10);

/////////////////////////////////// Primary End X vs Z Position //////////////////////////////////////////////
TH2D *hMCPrimaryEndXvsZ = new TH2D("hMCPrimaryEndXvsZ", "X_{f} vs Z_{f}", 600, -150, 450, 400, -200, 200);
/////////////////////////////////// Primary End Y vs Z Position //////////////////////////////////////////////
TH2D *hMCPrimaryEndYvsZ = new TH2D("hMCPrimaryEndYvsZ", "Y_{f} vs Z_{f}", 600, -150, 450, 200, -200, 200);

/////////////////////////////////// Energy Loss in the upstream region of the beamline ///////////////////////
TH1D *hMCELossUpstream = new TH1D("hMCELossUpstream", "Energy loss prior to entering the TPC", 1000, 0, 1000);

/////////////////////////////////// True Length //////////////////////////////////////////
TH1D *hTrueLength = new TH1D("hTrueLength", "#True Length of the Primary Particle inside the TPC", 200, 0 , 100);


// **********************************************************************************************************************



// ********************************************** RECONSTRUCTED INFORMATION **********************************************

/////////////////////////////////// Wire Chamber Track Momentum vs TOF, no cuts ////////////////////////////////
TH2D *hdataWCTrackMomentumVSTOF = new TH2D("hdataWCTrackMomentumVSTOF", "TOF vs WCTrack Momentum", 250, 0, 2500, 200, 0, 100);

/////////////////////////////////// Most Upstream Z point of tracks //////////////////////////////////////////
TH1D *hdataUpstreamZPos = new TH1D("hdataUpstreamZPos", "Most upstream spacepoint of all TPC Tracks", 20, 0, 10);

/////////////////////////////////// TPC Track Theta at the upstream point //////////////////////////////////////
TH1D *hdataTPCTheta = new TH1D("hdataTPCTheta", "TPC Track Theta", 180, 0, 90);

/////////////////////////////////// TPC Track Theta at the upstream point unweighted //////////////////////////////////////
TH1D *hdataTPCThetaUnWeighted = new TH1D("hdataTPCThetaUnWeighted", "TPC Track Theta", 180, 0, 90);

/////////////////////////////////// TPC Track Phi at the upstream point ///////////////////////////////////////
TH1D *hdataTPCPhi = new TH1D("hdataTPCPhi", "TPC Track Phi", 360, 0, 360);

/////////////////////////////////// TPC Track Phi at the upstream point unweighted ///////////////////////////////////////
TH1D *hdataTPCPhiUnWeighted = new TH1D("hdataTPCPhiUnWeighted", "TPC Track Phi", 360, 0, 360);

/////////////////////////////////// Wire Chamber Theta ////////////////////////////////////////////////////////
TH1D *hdataWCTheta = new TH1D("hdataWCTheta", "WCTrack Theta", 180, 0, 90);

/////////////////////////////////// Wire Chamber Phi //////////////////////////////////////////////////////////
TH1D *hdataWCPhi = new TH1D("hdataWCPhi", "WCTrack Phi", 360, 0, 360);

/////////////////////////////////// Delta WCTrack X ///////////////////////////////////////////////////////////
TH1D *hdataDeltaWCTrkX = new TH1D("hdataDeltaWCTrkX", "#Delta X TPC/WC Track", 160, -40, 40);

/////////////////////////////////// Delta WCTrack Y ///////////////////////////////////////////////////////////
TH1D *hdataDeltaWCTrkY = new TH1D("hdataDeltaWCTrkY", "#Delta Y TPC/WC Track", 160, -40, 40);

/////////////////////////////////// Alpha Between WC and TPC Tracks //////////////////////////////////////////
TH1D *hdataAlpha = new TH1D("hdataAlpha", "#alpha between WC and TPC Track", 90, 0, 90);

/////////////////////////////////// Number of Matched Tracks ////////////////////////////////////////////////
TH1D *hdataNMatchTPCWCTrk = new TH1D("hdataNMatchTPCWCTrk", "Number of matched TPC/WC Tracks", 20, 0, 10);

/////////////////////////////////// WCTRK Momentum Histogram (MeV) //////////////////////////////////////////
TH1D *hdataWCTRKMomentum = new TH1D("hdataWCTRKMomentum", "WCtrk Momentum (MeV)", 250, 0, 2500);

/////////////////////////////////// Initial Kinetic Energy (MeV) /////////////////////////////////////////////
TH1D *hdataInitialKEMomentum = new TH1D("hdataInitialKEMomentum", "Pion Initial Momentum (MeV)", 500, 0, 2500); 

/////////////////////////////////// Initial Kinetic Energy (MeV) Unweighted /////////////////////////////////////////////
TH1D *hdataInitialKEMomentumUnWeighted = new TH1D("hdataInitialKEMomentumUnWeighted", "Pion Initial Momentum (MeV)", 500, 0, 2500);

/////////////////////////////////// "Matched Track" dE/dX /////////////////////////////////////////////////////
TH1D *hdataPiondEdX = new TH1D("hdataPiondEdX", "Matched Track dE/dX", 200, 0, 50);

/////////////////////////////////// "Matched Track" Residual Range //////////////////////////////////////////
TH1D *hdataPionRR = new TH1D("hdataPionRR", "Matched Track Residual Range", 400, -100, 100);

/////////////////////////////////// "Matched Track" Track Pitch //////////////////////////////////////////
TH1D *hdataPionTrkPitch = new TH1D("hdataPionTrkPitch", "Matched Track Pitch", 1000, 0, 5);

///////////////////////////////// "Matched Track" dE/dX vs RR ///////////////////////////////////////////////
TH2D *hdataPiondEdXvsRR = new TH2D("hdataPiondEdXvsRR", "dE/dX vs Residual Range",200, 0, 100, 200, 0, 50);


//////////////////////////////// "Low Momentum Track" PIDA (no cuts) ///////////////////////////////////////
TH1D *hdataLowMomentumTrkPIDA = new TH1D("hdataLowMomentumTrkPIDA", "Low Momentum PIDA", 30, 0, 30);

/////////////////////////////////// Reconstructed Length //////////////////////////////////////////
TH1D *hRecoLength = new TH1D("hRecoLength", "Reconstructed Length of the Primary Particle inside the TPC", 200, 0 , 100);


/////////////////////////////////// Initial Track X Position ////////////////////////////////////////////////////////
TH1D *hdataTrkInitialX = new TH1D("hdataTrkInitialX", "Initial X Position of the TPC Track", 100, 0, 50);

/////////////////////////////////// Initial Track X Position  Unweighted ////////////////////////////////////////////////////////
TH1D *hdataTrkInitialXUnweighted = new TH1D("hdataTrkInitialXUnweighted", "Initial X Position of the TPC Track", 100, 0, 50);

/////////////////////////////////// Initial Track Y Position ////////////////////////////////////////////////////////
TH1D *hdataTrkInitialY = new TH1D("hdataTrkInitialY", "Initial Y Position of the TPC Track", 100, -25, 25);

/////////////////////////////////// Initial Track Y Position Unweighted ////////////////////////////////////////////////////////
TH1D *hdataTrkInitialYUnweighted = new TH1D("hdataTrkInitialYUnweighted", "Initial Y Position of the TPC Track", 100, -25, 25);




// ###############################################################################
// ### Note: The binning (number and range) needs to match between these plots ###
// ###############################################################################

/////////////////////////////////// "Pion" Incident to the slab Kinetic Energy (MeV) //////////////////////////////////////////
TH1D *hdataIncidentKE = new TH1D("hdataIncidentKE", "Incident Kinetic Energy (MeV)", 40, 0, 2000);

/////////////////////////////////// "Pion" Incident to the slab Kinetic Energy (MeV) //////////////////////////////////////////
TH1D *hdataIncidentKEunweighted = new TH1D("hdataIncidentKEunweighted", "Incident Kinetic Energy (MeV) (unweighted)", 40, 0, 2000);

/////////////////////////////////// "Pion" Exiting the slab Kinetic Energy (MeV) /////////////////////////////////////////////
TH1D *hdataInteractingKE = new TH1D("hdataInteractingKE", "Interacting Kinetic Energy (MeV)", 40, 0, 2000);

/////////////////////////////////// "Pion" Exiting the slab Kinetic Energy (MeV) (Unweighted) ////////////////////////////////
TH1D *hdataInteractingKEunweighted = new TH1D("hdataInteractingKEunweighted", "Interacting Kinetic Energy (MeV) (unweighted)", 40, 0, 2000);


/////////////////////////////////// Cross-Section ////////////////////////////////////////////////////////////////////////////
TH1F *fCrossSection = new TH1F("fCrossSection", "Cross-Section", 40, 0, 2000);


void Pion::Loop()
{
if (fChain == 0) return;
Long64_t nentries = fChain->GetEntriesFast();
Long64_t nbytes = 0, nb = 0;


// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// 					  Putting Flexible Cuts here
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// ### Putting in the particle mass that is being simulated here ###
// ###    which is used when calculating the energy loss before  ###
// ###                       entering the TPC                    ###

float particle_mass = 139.57; //<---Mass of Pion in MeV


// ##########################################################
// ### Preliminary TOF Cut (sets the bounds for TOF Reco) ###
// ##########################################################
double LowerTOFGoodReco = 0;
double UpperTOFGoodReco = 30;

// ###################################################
// ### Setting the Wire Chamber momentum range and ###
// ###     the TOF range for good particle ID      ###
// ###################################################
double LowerWCTrkMomentum = 100.0; //<--(MeV)
double HighWCTrkMomentum  = 1500.0;//<--(MeV)

double LowerTOF = 10.0; //<--(ns)
double HighTOF  = 25.0; //<--(ns)

// #####################################################
// ### Number of centimeters in Z we require a track ###
// ### to have a space point within (default = 2 cm) ###
// #####################################################
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


// ##########################################################
// ### Choose whether to remove identified stopping pions ###
// ###                                                    ###
// ### True  = Remove stoppping tagged tracks             ###
// ### False = Don't remove stopping tagged tracks        ###
// ##########################################################
bool RemoveStopping = true;

// ######################################################
// ### Choose whether or not to fix the calo problems ###
// ###  associated with ordering of the calo points   ###
// ###                                                ###
// ### True  = Use the fix                            ###
// ### False = Don't use the fix                      ###
// ######################################################
bool FixCaloIssue_Reordering = true; 


// ######################################################
// ### Choose whether or not to fix the calo problems ###
// ###   associated with large dE/dX fluctuations     ###
// ###                                                ###
// ### True  = Use the fix                            ###
// ### False = Don't use the fix                      ###
// ######################################################
bool FixCaloIssue_ExtremeFluctuation = true;     

// ########################################################
// ###   Choose whether or not to fix the calo problems ###
// ### associated with slightly large dE/dX fluctuations###
// ###                                                  ###
// ### True  = Use the fix                              ###
// ### False = Don't use the fix                        ###
// ########################################################
bool FixCaloIssue_LessExtremeFluctuation = true;     


// ###################################################
// ### Setting a flag to print out bunch of checks ###
// ###################################################
bool VERBOSE = false;     

// ----------------------------------------------------------------
// Create the cross section from the incident and interaction plots
// ----------------------------------------------------------------

// ### The assumed energy loss between the cryostat and the TPC ###
float entryTPCEnergyLoss = 40.; //MeV

// ### The assumed mass of the incident particle (here we assume a pion) ###
float mass = 139.57;

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


// ##########################################################
// ### Putting in some counters for event reduction table ###
// ##########################################################
int nTotalEvents = 0, nEvtsWCTrack = 0, nEvtsWCTrackMatch = 0, nEvtsTrackZPos = 0, nEvntsTPC = 0;
int nEvtsTOF = 0, nEvtsPID = 0, nLowZTrkEvents = 0;
int nNonShowerEvents = 0, nEvtsGoodMC = 0;



// ###############################
// ### Looping over all events ###
// ###############################
for (Long64_t jentry=0; jentry<nentries;jentry++) 
//for (Long64_t jentry=0; jentry<20000;jentry++)
   {
   
   // #########################
   // ### Loading the event ###
   // #########################
   Long64_t ientry = LoadTree(jentry);
   if (ientry < 0) break;
   nb = fChain->GetEntry(jentry);   nbytes += nb;
   
   // #############################
   // ### Counting Total Events ###
   // #############################
   nTotalEvents++;
   
   // === Outputting every nEvents to the screen ===
   if(nTotalEvents % 500 == 0){std::cout<<"Event = "<<nTotalEvents<<std::endl;}
   
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
	 // 100 MeV < P < 200 MeV = 0.02
   	 // 200 MeV < P < 300 MeV = 0.10
   	 // 300 MeV < P < 400 MeV = 0.535
   	 // 400 MeV < P < 500 MeV = 0.84
   	 // 500 MeV < P < 600 MeV = 0.965
   	 // 600 MeV < P < 700 MeV = 1.0
   	 // 700 MeV < P < 800 MeV = 0.62
   	 // 800 MeV < P < 900 MeV = 0.225
   	 // 900 MeV < P < 1000MeV = 0.094
   	 // 1000MeV < P < 1100MeV = 0.0275
   	 // 1100MeV < P < 1500MeV = 0.01
	 
	 // #############################################################
         // ### Calculating the momentum from the MC Primary Particle ###
         // #############################################################
         float momentumScale = sqrt( (g4Primary_Px[nG4Primary]*g4Primary_Px[nG4Primary]) + 
	                        (g4Primary_Py[nG4Primary]*g4Primary_Py[nG4Primary]) + 
				(g4Primary_Pz[nG4Primary]*g4Primary_Pz[nG4Primary]) );
				
	 float kineticEnergyScale = pow( (momentumScale*momentumScale) + (mass*mass) ,0.5) - mass;
	 
	 //std::cout<<"kineticEnergyScale = "<<kineticEnergyScale<<std::endl;
	 
	 // ### Setting Event weight ### 
	 if(UseEventWeight)
	    {
	    
	    // ### Old event weights ###
	    /*if(g4Primary_Pz[nG4Primary] > 0   && g4Primary_Pz[nG4Primary] < 100){EventWeight = 0.010;}
	    if(g4Primary_Pz[nG4Primary] > 100 && g4Primary_Pz[nG4Primary] < 200){EventWeight = 0.020;}
	    if(g4Primary_Pz[nG4Primary] > 200 && g4Primary_Pz[nG4Primary] < 300){EventWeight = 0.100;}
	    if(g4Primary_Pz[nG4Primary] > 300 && g4Primary_Pz[nG4Primary] < 400){EventWeight = 0.535;}
	    if(g4Primary_Pz[nG4Primary] > 400 && g4Primary_Pz[nG4Primary] < 500){EventWeight = 0.840;}
	    if(g4Primary_Pz[nG4Primary] > 500 && g4Primary_Pz[nG4Primary] < 600){EventWeight = 0.965;}
	    if(g4Primary_Pz[nG4Primary] > 600 && g4Primary_Pz[nG4Primary] < 700){EventWeight = 1.000;}
	    if(g4Primary_Pz[nG4Primary] > 700 && g4Primary_Pz[nG4Primary] < 800){EventWeight = 0.620;}
	    if(g4Primary_Pz[nG4Primary] > 800 && g4Primary_Pz[nG4Primary] < 900){EventWeight = 0.225;}
	    if(g4Primary_Pz[nG4Primary] > 900 && g4Primary_Pz[nG4Primary] <1000){EventWeight = 0.094;}
	    if(g4Primary_Pz[nG4Primary] >1000 && g4Primary_Pz[nG4Primary] <1100){EventWeight = 0.0275;}
	    if(g4Primary_Pz[nG4Primary] >1100){EventWeight = 0.010;}*/
	    
	    
	    if(kineticEnergyScale > 0 	&& kineticEnergyScale < 25)	{EventWeight = 0.00277606;}
	    if(kineticEnergyScale > 25 	&& kineticEnergyScale < 50)	{EventWeight = 0.00215916;}
	    if(kineticEnergyScale > 50 	&& kineticEnergyScale < 75)	{EventWeight = 0.00771129;}
	    if(kineticEnergyScale > 75 	&& kineticEnergyScale < 100)	{EventWeight = 0.0166564;}
	    
	    if(kineticEnergyScale > 100	&& kineticEnergyScale < 125)	{EventWeight = 0.0271437;}
	    if(kineticEnergyScale > 125	&& kineticEnergyScale < 150)	{EventWeight = 0.0431832;}
	    if(kineticEnergyScale > 150	&& kineticEnergyScale < 175)	{EventWeight = 0.0354719;}
	    if(kineticEnergyScale > 175	&& kineticEnergyScale < 200)	{EventWeight = 0.0305367;}
	    
	    if(kineticEnergyScale > 200	&& kineticEnergyScale < 225)	{EventWeight = 0.0397903;}
	    if(kineticEnergyScale > 225	&& kineticEnergyScale < 250)	{EventWeight = 0.0487353;}
	    if(kineticEnergyScale > 250	&& kineticEnergyScale < 275)	{EventWeight = 0.0481184;}
	    if(kineticEnergyScale > 275	&& kineticEnergyScale < 300)	{EventWeight = 0.0456508;}
	    
	    if(kineticEnergyScale > 300	&& kineticEnergyScale < 325)	{EventWeight = 0.0379395;}
	    if(kineticEnergyScale > 325	&& kineticEnergyScale < 350)	{EventWeight = 0.0360888;}
	    if(kineticEnergyScale > 350	&& kineticEnergyScale < 375)	{EventWeight = 0.0351635;}
	    if(kineticEnergyScale > 375	&& kineticEnergyScale < 400)	{EventWeight = 0.0385564;}
	    
	    if(kineticEnergyScale > 400	&& kineticEnergyScale < 425)	{EventWeight = 0.0487353;}
	    if(kineticEnergyScale > 425	&& kineticEnergyScale < 450)	{EventWeight = 0.04781;}
	    if(kineticEnergyScale > 450	&& kineticEnergyScale < 475)	{EventWeight = 0.0508945;}
	    if(kineticEnergyScale > 475	&& kineticEnergyScale < 500)	{EventWeight = 0.0518199;}
	    
	    if(kineticEnergyScale > 500	&& kineticEnergyScale < 525)	{EventWeight = 0.051203;}
	    if(kineticEnergyScale > 525	&& kineticEnergyScale < 550)	{EventWeight = 0.0422579;}
	    if(kineticEnergyScale > 550	&& kineticEnergyScale < 575)	{EventWeight = 0.0388649;}
	    if(kineticEnergyScale > 575	&& kineticEnergyScale < 600)	{EventWeight = 0.0293029;}
	    
	    if(kineticEnergyScale > 600	&& kineticEnergyScale < 625)	{EventWeight = 0.0296114;}
	    if(kineticEnergyScale > 625	&& kineticEnergyScale < 650)	{EventWeight = 0.0246761;}
	    if(kineticEnergyScale > 650	&& kineticEnergyScale < 675)	{EventWeight = 0.0166564;}
	    if(kineticEnergyScale > 675	&& kineticEnergyScale < 700)	{EventWeight = 0.0160395;}
	    
	    if(kineticEnergyScale > 700	&& kineticEnergyScale < 725)	{EventWeight = 0.0138803;}
	    if(kineticEnergyScale > 725	&& kineticEnergyScale < 750)	{EventWeight = 0.0107958;}
	    if(kineticEnergyScale > 750	&& kineticEnergyScale < 775)	{EventWeight = 0.00709439;}
	    if(kineticEnergyScale > 775	&& kineticEnergyScale < 800)	{EventWeight = 0.00555213;}
	    
	    if(kineticEnergyScale > 800	&& kineticEnergyScale < 825)	{EventWeight = 0.00524368;}
	    if(kineticEnergyScale > 825	&& kineticEnergyScale < 850)	{EventWeight = 0.00370142;}
	    if(kineticEnergyScale > 850	&& kineticEnergyScale < 875)	{EventWeight = 0.00185071;}
	    if(kineticEnergyScale > 875	&& kineticEnergyScale < 900)	{EventWeight = 0.00246761;}
	    
	    if(kineticEnergyScale > 900	&& kineticEnergyScale < 925)	{EventWeight = 0.00154226;}
	    if(kineticEnergyScale > 925	&& kineticEnergyScale < 950)	{EventWeight = 0.000616903;}
	    if(kineticEnergyScale > 950	&& kineticEnergyScale < 975)	{EventWeight = 0.000308452;}
	    if(kineticEnergyScale > 975	&& kineticEnergyScale < 1000)	{EventWeight = 0.000308452;}
	    
	    if(kineticEnergyScale > 1000&& kineticEnergyScale < 1025)	{EventWeight = 0.000616903;}
	    if(kineticEnergyScale > 1025&& kineticEnergyScale < 1050)	{EventWeight = 0.000616903;}
	    if(kineticEnergyScale > 1050&& kineticEnergyScale < 1075)	{EventWeight = 0.000616903;}
	    if(kineticEnergyScale > 1075&& kineticEnergyScale < 1100)	{EventWeight = 0.000616903;}
	    
	    if(kineticEnergyScale > 1100&& kineticEnergyScale < 1125)	{EventWeight = 0.000308452;}
	    if(kineticEnergyScale > 1125&& kineticEnergyScale < 1150)	{EventWeight = 0.000308452;}
	    if(kineticEnergyScale > 1150&& kineticEnergyScale < 1175)	{EventWeight = 0.000308452;}
	    if(kineticEnergyScale > 1175&& kineticEnergyScale < 1200)	{EventWeight = 0.000308452;}
	    
	    if(kineticEnergyScale > 1200&& kineticEnergyScale < 1225)	{EventWeight = 0.000308452;}
	    if(kineticEnergyScale > 1225&& kineticEnergyScale < 1250)	{EventWeight = 0.000308452;}
	    if(kineticEnergyScale > 1250&& kineticEnergyScale < 1275)	{EventWeight = 0.000308452;}
	    if(kineticEnergyScale > 1275&& kineticEnergyScale < 1300)	{EventWeight = 0.000308452;}
	    
	    if(kineticEnergyScale > 1300)                               {EventWeight = 0.0;}
	    
	    
	    // ### New Event weights ###
	    if(g4Primary_Pz[nG4Primary] > 0   && g4Primary_Pz[nG4Primary] < 100){EventWeight = 0.0;}
	    if(g4Primary_Pz[nG4Primary] > 100   && g4Primary_Pz[nG4Primary] < 150){EventWeight = 0.001276;}
	    if(g4Primary_Pz[nG4Primary] > 150   && g4Primary_Pz[nG4Primary] < 200){EventWeight = 0.006496;}
	    if(g4Primary_Pz[nG4Primary] > 200   && g4Primary_Pz[nG4Primary] < 250){EventWeight = 0.006496;}
	    /*if(g4Primary_Pz[nG4Primary] > 250   && g4Primary_Pz[nG4Primary] < 300){EventWeight = 0.665;}
	    if(g4Primary_Pz[nG4Primary] > 300   && g4Primary_Pz[nG4Primary] < 350){EventWeight = 0.600;}
	    if(g4Primary_Pz[nG4Primary] > 350   && g4Primary_Pz[nG4Primary] < 400){EventWeight = 0.793;}
	    if(g4Primary_Pz[nG4Primary] > 400   && g4Primary_Pz[nG4Primary] < 450){EventWeight = 0.925;}
	    if(g4Primary_Pz[nG4Primary] > 450   && g4Primary_Pz[nG4Primary] < 500){EventWeight = 0.735;}
	    if(g4Primary_Pz[nG4Primary] > 500   && g4Primary_Pz[nG4Primary] < 550){EventWeight = 0.690;}
	    if(g4Primary_Pz[nG4Primary] > 550   && g4Primary_Pz[nG4Primary] < 600){EventWeight = 0.882;}
	    if(g4Primary_Pz[nG4Primary] > 600   && g4Primary_Pz[nG4Primary] < 650){EventWeight = 1.0;}
	    if(g4Primary_Pz[nG4Primary] > 650   && g4Primary_Pz[nG4Primary] < 700){EventWeight = 0.984;}
	    if(g4Primary_Pz[nG4Primary] > 700   && g4Primary_Pz[nG4Primary] < 750){EventWeight = 0.743;}
	    if(g4Primary_Pz[nG4Primary] > 750   && g4Primary_Pz[nG4Primary] < 800){EventWeight = 0.552;}
	    if(g4Primary_Pz[nG4Primary] > 800   && g4Primary_Pz[nG4Primary] < 850){EventWeight = 0.388;}
	    if(g4Primary_Pz[nG4Primary] > 850   && g4Primary_Pz[nG4Primary] < 900){EventWeight = 0.292;}
	    if(g4Primary_Pz[nG4Primary] > 900   && g4Primary_Pz[nG4Primary] < 950){EventWeight = 0.163;}
	    if(g4Primary_Pz[nG4Primary] > 950   && g4Primary_Pz[nG4Primary] < 1000){EventWeight = 0.093;}
	    if(g4Primary_Pz[nG4Primary] > 1000   && g4Primary_Pz[nG4Primary] < 1050){EventWeight = 0.059;}
	    if(g4Primary_Pz[nG4Primary] > 1050   && g4Primary_Pz[nG4Primary] < 1100){EventWeight = 0.034;}
	    if(g4Primary_Pz[nG4Primary] > 1100   && g4Primary_Pz[nG4Primary] < 1150){EventWeight = 0.009;}
	    if(g4Primary_Pz[nG4Primary] > 1150   && g4Primary_Pz[nG4Primary] < 1500){EventWeight = 0.003;}
	    if(g4Primary_Pz[nG4Primary] > 1500){EventWeight = 0.0;}*/
	    
	    
	    }//<---End Assigning Event weight
	 
	 TrueLength = sqrt( ((EndPointz[iG4]-StartPointz[iG4])*(EndPointz[iG4]-StartPointz[iG4])) + 
	                    ((EndPointy[iG4]-StartPointy[iG4])*(EndPointy[iG4]-StartPointy[iG4])) + 
	                    ((EndPointx[iG4]-StartPointx[iG4])*(EndPointx[iG4]-StartPointx[iG4])) );
			    
	 hTrueLength->Fill(TrueLength);
	 
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
   
   // ##############################################
   // ### Looping over all the primary particles ###
   // ##############################################
   for(int npri = 0; npri < nG4Primary; npri++)
      {
      if(g4Primary_Zf[npri] < 0){GoodMCEventInTPC = false;}
      
      // ####################################################################
      // ### Calculating the energy loss for particles that enter the TPC ###
      // ####################################################################
      if(GoodMCEventInTPC)
         {
	 float DifferenceInEnergy = 0;
	 // ### Loop over the true trajectory points ###
	 for(int ntrj = 0; ntrj < nG4PriTrj; ntrj++)
	    {
\
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
	 }//<---Only looking at events that actually make it into the TPC
      
      
      }//<---End npri loop
   
   if(!GoodMCEventInTPC){continue;}
   nEvtsGoodMC++;



   //=======================================================================================================================
   //						Low Z Spacepoint Track Cut
   //=======================================================================================================================
   
   // ### Boolian for events w/ track which ###
   // ###     starts at the front face      ###
   bool TrackSptsZCut = false;
   
   bool ThisTrackHasLowZPoint = false;
   
   // ### Recording the index of the track which ###
   // ###   starts at the front face of the TPC  ###
   bool PreLimTrackIndex[1000] = {false};
   
   // ###########################
   // ### Looping over tracks ###
   // ###########################
   for(size_t nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      
      float tempZpoint = 100;
      ThisTrackHasLowZPoint = false;
      // ########################################################
      // ### Looping over the trajectory points for the track ###
      // ########################################################
      for(size_t ntrjpts = 0; ntrjpts < nTrajPoint[nTPCtrk]; ntrjpts++)
         {
	 // ################################################################################ 
         // ### Tracking the lowest Z point that is inside fiducial boundries of the TPC ###
	 // ################################################################################
	 if( trjPt_Z[nTPCtrk][ntrjpts] < tempZpoint  && trjPt_Z[nTPCtrk][ntrjpts] > ZLowerFid && 
	     trjPt_Z[nTPCtrk][ntrjpts] < ZUpperFid && trjPt_X[nTPCtrk][ntrjpts] > XLowerFid && trjPt_X[nTPCtrk][ntrjpts] < XUpperFid &&
	     trjPt_Y[nTPCtrk][ntrjpts] < YUpperFid && trjPt_Y[nTPCtrk][ntrjpts] > YLowerFid )
	     
	    {tempZpoint = trjPt_Z[nTPCtrk][ntrjpts];}//<---End looking for the most upstream point
        
	 // ### Only passing events with a track that has ###
	 // ###  a spacepoint within the first N cm in Z  ### 
	 // ###    And requiring it to be inside the TPC  ###
	 if(tempZpoint < FirstSpacePointZPos)
	    {TrackSptsZCut = true;
	     ThisTrackHasLowZPoint = true;}
	 }//<---End looping over ntrjpts	
	 
      // ### Filling the most upstream spacepoint for this track ###
      hdataUpstreamZPos->Fill(tempZpoint);
      
      // ### Recording that this track is a "good Track if ###
      // ###  it has a space point in the first N cm in Z  ###
      if(ThisTrackHasLowZPoint){ PreLimTrackIndex[nTPCtrk] = true;}
      	 
      }//<---End nTPCtrk loop
      
   // ###############################################
   // ### Skipping events that don't have a track ###
   // ###   in the front of the TPC (Z) Position  ###
   // ###############################################
   if(!TrackSptsZCut){continue;}
   // ### Counting Events w/ front face TPC Track ###
   nEvtsTrackZPos++;
   
   
   //=======================================================================================================================
   //					Cutting on the number of tracks in the upstream TPC
   //=======================================================================================================================
   
   int nLowZTracksInTPC = 0;
   // ################################################################
   // ### Initializing variables for study of low Z track location ###
   // ################################################################
   bool LowZTrackInTPC = false;
   
   
   // #################################################################
   // ### Only keeping events if there is less than N tracks in the ###
   // ###    first ## cm of the TPC (to help cut out EM Showers     ###
   // #################################################################
   for(size_t nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
     {
     // ### Start by assuming this track is not in the ###
     // ###          low Z part of the TPC             ###
     LowZTrackInTPC = false;
           
     // ########################################################
     // ### Looping over the trajectory points for the track ###
     // ########################################################
     for(size_t ntrjpts = 0; ntrjpts < nTrajPoint[nTPCtrk]; ntrjpts++)
        {
	 
	// ##################################################
	// ### Count this track if it has a spacepoint in ###
	// ###       the low Z region of the TPC          ###
	// ##################################################
	if(trjPt_Z[nTPCtrk][ntrjpts] < UpperPartOfTPC)
	   {  
	   if(trjPt_Y[nTPCtrk][ntrjpts] > YLowerFid && trjPt_Y[nTPCtrk][ntrjpts] < YUpperFid && 
	      trjPt_X[nTPCtrk][ntrjpts] > XLowerFid && trjPt_X[nTPCtrk][ntrjpts] < XUpperFid)
	       {LowZTrackInTPC = true;}
		
           }//<---End counting if 
	
        }//<---End ntrjpts loop
      
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
   //						Uniquely matching one WC Track (For MC) to TPC Track
   //=======================================================================================================================
   
   // ### Keeping track of the number of matched tracks ###
   int nMatchedTracks = 0;
   
   // ### Variables for Delta WC and TPC tracks ###
   float DeltaX_WC_TPC_Track = 999;
   float DeltaY_WC_TPC_Track = 999;
   
   // ### Setting the index for the track which is ###
   // ### uniquely matched to a wire chamber track ###
   bool MatchTPC_WVTrack[500] = {false};
   
   
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
   
   // ### Grab the WCTrack Theta ###;
   hdataWCTheta->Fill(mcTheta* (180.0/3.141592654));
      
   // ### Grabbing the WCTrack Phi ###
   hdataWCPhi->Fill(mcPhi* (180.0/3.141592654));
      
   // ####################################
   // ### Loop over all the TPC Tracks ###
   // ####################################
   for(size_t nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ############################################
      // ###   Only looking at tracks which have  ###
      // ### a point in the first N cm of the TPC ###
      // ############################################
      if(!PreLimTrackIndex[nTPCtrk]){continue;}
	 
      // === Set a dummy variables for the most upstream point ===
      float FirstSpacePointZ = 999;
      float FirstSpacePointY = 999;
      float FirstSpacePointX = 999;
	 
      float TempTrj_X = 999;
      float TempTrj_Y = 999;
      float TempTrj_Z = 999;
      // ###############################################################
      // ### Looping over the trajectory points for the prelim-track ###
      // ###############################################################
      for(size_t ntrjpts = 0; ntrjpts < nTrajPoint[nTPCtrk]; ntrjpts++)
         {
	    
	 // ### Recording this tracks upstream most X, Y, Z location, ###
	 // ###       which is inside the fiducial boundary           ###
	 if(trjPt_Z[nTPCtrk][ntrjpts] < FirstSpacePointZ && trjPt_Y[nTPCtrk][ntrjpts] > YLowerFid && 
	    trjPt_Y[nTPCtrk][ntrjpts] < YUpperFid && trjPt_X[nTPCtrk][ntrjpts] > XLowerFid && 
	    trjPt_X[nTPCtrk][ntrjpts] < XUpperFid && trjPt_Z[nTPCtrk][ntrjpts] < UpperPartOfTPC)
	    {
	       
	    // ######################################
	    // ### Record the most upstream point ###
	    // ######################################
	    FirstSpacePointZ = trjPt_Z[nTPCtrk][ntrjpts];
	    FirstSpacePointY = trjPt_Y[nTPCtrk][ntrjpts];
	    FirstSpacePointX = trjPt_X[nTPCtrk][ntrjpts];
	       
	    TempTrj_X = pHat0_X[nTPCtrk][ntrjpts];
	    TempTrj_Y = pHat0_Y[nTPCtrk][ntrjpts];
	    TempTrj_Z = pHat0_Z[nTPCtrk][ntrjpts];
	       
	       
	    }//<---End finding the most upstream point
         }//<---End ntrjpts loop
	 
      // ###################################################
      // ### Vectors for angles between TPC and WC Track ###
      // ###################################################
      TVector3 z_hat(0,0,1);
      TVector3 p_hat_0;
      
      // ### Setting the vector for the matched track ###
      // ###      most upstream trajectory point      ###
      p_hat_0.SetX(TempTrj_X);
      p_hat_0.SetY(TempTrj_Y);
      p_hat_0.SetZ(TempTrj_Z); //<--Note: since at this point we only have one unique match
       		               //         only having one entry should be fine
	 			  
      // ===============================================================================================================
      // 				Calculating Theta and Phi for this TPC Track
      // ===============================================================================================================
      // ### Calculating the Theta for the TPC Track ###
      float tpcTheta = acos(z_hat.Dot(p_hat_0)/p_hat_0.Mag());  
      hdataTPCTheta->Fill(tpcTheta* (180.0/3.141592654), EventWeight);
      
      hdataTPCThetaUnWeighted->Fill(tpcTheta* (180.0/3.141592654));
   
      // ### Using same convention as WCTrack to calculate phi ###
      float phi = 0;
      //Calculating phi (degeneracy elimination for the atan function)
      //----------------------------------------------------------------------------------------------
      if( p_hat_0.Y() > 0 && p_hat_0.X() > 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X()); }
      else if( p_hat_0.Y() > 0 && p_hat_0.X() < 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X())+3.141592654; }
      else if( p_hat_0.Y() < 0 && p_hat_0.X() < 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X())+3.141592654; }
      else if( p_hat_0.Y() < 0 && p_hat_0.X() > 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X())+6.28318; }
      else if( p_hat_0.Y() == 0 && p_hat_0.X() == 0 ){ phi = 0; }//defined by convention
      else if( p_hat_0.Y() == 0 )
         {
         if( p_hat_0.X() > 0 ){ phi = 0; }

         else{ phi = 3.141592654; }

         }
      else if( p_hat_0.X() == 0 )
         {
         if( p_hat_0.Y() > 0 ){ phi = 3.141592654/2; }
         else{ phi = 3.141592654*3/2; }

         }
      //----------------------------------------------------------------------------------------------
   
      // ### Using TPC Phi ###
      float tpcPhi = phi; 
      hdataTPCPhi->Fill(tpcPhi* (180.0/3.141592654), EventWeight);
      
      hdataTPCPhiUnWeighted->Fill(tpcPhi* (180.0/3.141592654));
      
      // ===============================================================================================================            
      // ===============================================================================================================
	 
      // #######################################################
      // ### Defining unit vectors for the WC and TPC tracks ###
      // #######################################################
      TVector3 theUnitVector_WCTrack;
      TVector3 theUnitVector_TPCTrack;
	 
      // === WCTrack Unit Vector ===
      theUnitVector_WCTrack.SetX(sin(mcTheta)*cos(mcPhi));
      theUnitVector_WCTrack.SetY(sin(mcTheta)*sin(mcPhi));
      theUnitVector_WCTrack.SetZ(cos(mcTheta));
    
      // === TPC Track Unit Vector ===
      theUnitVector_TPCTrack.SetX(sin(tpcTheta)*cos(tpcPhi));
      theUnitVector_TPCTrack.SetY(sin(tpcTheta)*sin(tpcPhi));
      theUnitVector_TPCTrack.SetZ(cos(tpcTheta));
	 
      // ##########################################################################
      // ### Calculating the Delta X and Delta Y between WC track and TPC track ###
      // ##########################################################################
      DeltaX_WC_TPC_Track = FirstSpacePointX - (g4Primary_ProjX0[0]);
      DeltaY_WC_TPC_Track = FirstSpacePointY - (g4Primary_ProjY0[0]);
      
      hdataTrkInitialX->Fill(FirstSpacePointX, EventWeight);
      hdataTrkInitialXUnweighted->Fill(FirstSpacePointX);
      
      hdataTrkInitialY->Fill(FirstSpacePointY, EventWeight);
      hdataTrkInitialYUnweighted->Fill(FirstSpacePointY);
	 
      // ###########################################################
      // ### Calculating the angle between WCTrack and TPC Track ###
      // ###########################################################
      float alpha = ( acos(theUnitVector_WCTrack.Dot(theUnitVector_TPCTrack)) )* (180.0/3.141592654);
   
         
      // ### Filling the Delta X and Delta Y  and alpha between WC tracks and TPC Tracks ###
      hdataDeltaWCTrkY->Fill(DeltaY_WC_TPC_Track);
      hdataDeltaWCTrkX->Fill(DeltaX_WC_TPC_Track);
      hdataAlpha->Fill(alpha);
	 
	 // ###########################################################################
	 // ### If this TPC track matches this Wire Chamber Track, bump the counter ###
	 // ###########################################################################
      if( DeltaX_WC_TPC_Track >  DeltaXLowerBound && DeltaX_WC_TPC_Track < DeltaXUpperBound && 
	  DeltaY_WC_TPC_Track > DeltaYLowerBound && DeltaY_WC_TPC_Track < DeltaYUpperBound &&
	  alpha < alphaCut )
         {
	 // ### Counting the matched tracks ###
	 nMatchedTracks++;
	 
	 // ### Setting the index of this track to true ###
	 MatchTPC_WVTrack[nTPCtrk] = true;

         }  
	 
      }//<---end nTPCtrk loop
      
      
   
   // ### Filling the number of matched WC and TPC Tracks ###
   hdataNMatchTPCWCTrk->Fill(nMatchedTracks);
   
   // #####################################################
   // ### Skipping this event if no WC track is matched ###
   // ###    OR if more than one WC track is matched    ###
   // #####################################################
   if( (nMatchedTracks < 1 || nMatchedTracks > 1)){continue;}
   
   // ### Counting the number of events with ONE WC track matched ###
   nEvtsWCTrackMatch++;







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


   // =========================================================================================================================================
   //						Recording information about the Wire Chamber Track
   // =========================================================================================================================================
   
   // ---   First grab the tracks "initial" momentum which we take from ---
   // --- the momentum of the primary MC track which has been matched ---
   // ---  and correct for the "typical" energy loss for a track in the ---
   // ---   argon between the cryostat and the front face of the TPC    ---
   
   
   
   // #############################################################
   // ### Calculating the momentum from the MC Primary Particle ###
   // #############################################################
   float momentum = sqrt( (g4Primary_Px[0]*g4Primary_Px[0]) + (g4Primary_Py[0]*g4Primary_Py[0]) + (g4Primary_Pz[0]*g4Primary_Pz[0]) );
         
   
   // ###   Calculating the initial Kinetic Energy    ###
   // ### KE = Energy - mass = (p^2 + m^2)^1/2 - mass ###
   float kineticEnergy = pow( (momentum*momentum) + (mass*mass) ,0.5) - mass;
   
   // ### The kinetic energy is that which we calculated ###
   // ###       minus the calculated energy loss         ###
   kineticEnergy -= entryTPCEnergyLoss;
  
   double InitialKinEnAtTPC = 0.;
   InitialKinEnAtTPC = kineticEnergy;
   
   // ###############################################
   // ### Filling the initial kinetic energy plot ###
   // ###############################################
   hdataInitialKEMomentum->Fill(kineticEnergy, EventWeight);
   hdataInitialKEMomentumUnWeighted->Fill(kineticEnergy);



   // =========================================================================================================================================
   //							 Calorimetry Points
   // =========================================================================================================================================
   
   //Vectors with calo info of the matched tpc track
   double Piondedx[1000]={0.};
   double Pionresrange[1000]={0.};
   double Pionpitchhit[1000]={0.};
   int nPionSpts = 0;
   
   // ################################################
   // ### Creating a flag for through going tracks ###
   // ################################################
   bool ThroughGoingTrack[1000]={false};
   
   
   // ###########################################
   // ### Creating a flag for stopping tracks ###
   // ###########################################
   bool StoppingParticle[1000] = {false};
   
   // ############################
   // ### Loop over all tracks ###
   // ############################
   for(size_t nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ### Skipping all the tracks which aren't well matched ###
      if(!MatchTPC_WVTrack[nTPCtrk]){continue;}
      
      // ### Recording the track length ###
      hRecoLength->Fill(trklength[nTPCtrk]);
      
      // ###################################################
      // ### Check to see if this track is through going ###
      // ### by checking to see if it ends on a boundary ###
      // ###################################################
      if(trkendx[nTPCtrk] < 1   || trkendx[nTPCtrk] > 42.0 || trkendy[nTPCtrk] > 19 ||
         trkendy[nTPCtrk] < -19 || trkendz[nTPCtrk] > 89.0)
         {ThroughGoingTrack[nTPCtrk] = true;}
      
      // #####################################################
      // ### Check to see if this track is consistent with ###
      // ###          being from a stopping track 	   ###
      // #####################################################
      if(InitialKinEnAtTPC < 300)
         {
	 // ### Filling the  tracks PIDA value ###
	 hdataLowMomentumTrkPIDA->Fill(trkpida[nTPCtrk][1]);
	 
	 // ##########################################
	 // ###  If the PIDA is between 9 and 13   ###
	 // ##########################################
	 if(trkpida[nTPCtrk][1] >= 9 && trkpida[nTPCtrk][1] <= 13)
	    {
	    
	    //### Setting the last energy points variable ###
	    double lastDeltaE = 0;
	    
	    // ### Loop over the last five points of the track ###
	    if(ntrkhits[nTPCtrk] >= 5)
	       {
	       for(size_t nlastspts = ntrkhits[nTPCtrk] - 1; nlastspts > ntrkhits[nTPCtrk] - 5; nlastspts--)
	          {
		  // ### Add up the energy in the last 5 points ###
		  lastDeltaE += (trkpitchhit[nTPCtrk][1][nlastspts] * trkdedx[nTPCtrk][1][nlastspts]);

	          }//<---End nlastspts loop

	       }//<---End only looking if the track has 5 points
	    
	    // ### IF the Delta E is between 7 and 25, tag as a stopping track ###
	    if(lastDeltaE >= 7 && lastDeltaE <= 25)
	       // ### Only setting the flag if we are tagging events ###
	       {
	       if(RemoveStopping)
	          {StoppingParticle[nTPCtrk] = true;}
	       
	       }
	    
	    
	    }//<---End looking at 9 < PIDA < 13
	 }//<---End looking at low momentum tracks
      
      
      // ###############################################################
      // ### Looping over the calorimetry spacepoints for this track ###
      // ###############################################################
      for(size_t nspts = 0; nspts < ntrkhits[nTPCtrk]; nspts++)
         {
	 // ###                 Note: Format for this variable is:             ###
	 // ### [trk number][plane 0 = induction, 1 = collection][spts number] ###
         Piondedx[nPionSpts]     = trkdedx[nTPCtrk][1][nspts];
	 
	 // ### Putting in a fix in the case that the dE/dX is negative in this step ### 
	 // ###  then take the point before and the point after and average them
	 if(Piondedx[nPionSpts] < 0 && nspts < ntrkhits[nTPCtrk] && nspts > 0)
	    {Piondedx[nPionSpts] = ( (trkdedx[nTPCtrk][1][nspts - 1] + trkdedx[nTPCtrk][1][nspts + 1]) / 2);}
	 
	 // ### If this didn't fix it, then just put in a flat 2.4 MeV / cm fix ###
	 if(Piondedx[nPionSpts] < 0)
	    {continue;}
	    
	 Pionresrange[nPionSpts] = trkrr[nTPCtrk][1][nspts];
         Pionpitchhit[nPionSpts] = trkpitchhit[nTPCtrk][1][nspts];
	 
	 // ### Histogramming the dE/dX ###
	 hdataPiondEdX->Fill(Piondedx[nPionSpts]);
	 // ### Histogramming the residual range ###
	 hdataPionRR->Fill(Pionresrange[nPionSpts]);
	 // ### Histogramming the Pitch ###
	 hdataPionTrkPitch->Fill(Pionpitchhit[nPionSpts]);
	 
	 // ### Filling 2d dE/dX vs RR ###
	 hdataPiondEdXvsRR->Fill(Pionresrange[nPionSpts], Piondedx[nPionSpts]);
	 
	 nPionSpts++;
	 
	 }//<---End spacepoints loop
      
      
      }//<---End nTPCtrk loop 
   
// ---------------------------------------------------------------------------------------------------------------------------------------
   bool HasToBeReordered = false;
   int ReorderedCount = 0;
   int bb = 0;
   // ############################################################
   // ### Fix the reordering problem of the calorimetry points ###
   // ############################################################
   if(FixCaloIssue_Reordering)
      {
      // ################################
      // ### Loop over the caloPoints ###
      // ################################
      for(size_t caloPoints = 0; caloPoints < nPionSpts-1; caloPoints++)
         {
	 // ###           If this points Residual Range is smaller than the       ###
	 // ### next point, then things may be out of wack and we want to reorder ###
	 if(Pionresrange[caloPoints] < Pionresrange[caloPoints+1])
	    {
	    // #######################################################
	    // ### Set a flag that this might have to be reordered ###
	    // #######################################################
	    HasToBeReordered = true;
	    
	    // ### counting the points that are out of order ###
	    ReorderedCount++;
	    }

         }//<---End caloPoints
      }//<---End fixing the ordering problem
   
   // #####################################################
   // ### The things need to be reorderd for this track ###
   // #####################################################
   if(HasToBeReordered && ( (nPionSpts - ReorderedCount) == 1))
      {
      
      // ### Temp Variables for fixing ###
      double tempRR[1000] = {0.};
      double tempdEdX[1000] = {0.};
      double tempPitch[1000] = {0.};
      
      // ### Start at the last point ###
      for(int aa = nPionSpts; aa > -1; aa--)
         {
	 // ##########################################
	 // ### Skip the point if it is at the end ###
	 // ##########################################
	 if(Pionresrange[aa] == 0){continue;}
	 
	 // ### Reorder the points ###
	 tempRR[bb] = Pionresrange[aa];
	 tempdEdX[bb]     = Piondedx[aa];
	 tempPitch[bb] = Pionpitchhit[aa];
	 
	 bb++;
	 }//<---end aa 
      
      // ###########################
      // ### Now swap the points ###
      // ###########################
      for(size_t reorder = 0; reorder < nPionSpts; reorder++)
         {
	 Pionresrange[reorder] = tempRR[reorder];
	 Piondedx[reorder]     = tempdEdX[reorder];
	 Pionpitchhit[reorder] = tempPitch[reorder];
	 
	 
	 }//<---End reorder loop
      
      
      }//<---End Has to be reordered

   // ##################################
   // ### Printing things as a check ###
   // ##################################
   if(HasToBeReordered && VERBOSE)
      {
      for(size_t caloPoints = 0; caloPoints < nPionSpts; caloPoints++)
         {
	 std::cout<<"Run = "<<run<<", Event = "<<event<<" point = "<<caloPoints<<", RR = "<<Pionresrange[caloPoints]<<", dE/dX = "<<Piondedx[caloPoints]<<std::endl;
      
      
         }//<---End caloPoints
      std::cout<<std::endl;	 
      }//<---Putting in a print to make sure things are reordered correctly   
   
// ---------------------------------------------------------------------------------------------------------------------------------------
   
   
   
   // ####################################################################
   // ### Fix the calorimetry issues associated with huge fluctuations ###
   // ###            by extrapolating through the points               ###
   // ####################################################################
   if(FixCaloIssue_ExtremeFluctuation)
      {
      // ################################
      // ### Loop over the caloPoints ###
      // ################################
      for(size_t caloPoints = 0; caloPoints < nPionSpts; caloPoints++)
         {
	 
	 // ###################################################
	 // ### If the dE/dX is large and at the end of the ###
	 // ###  track as expected with a proton attached   ###
	 // ###################################################
	 if(Piondedx[caloPoints] > 40. && caloPoints == (nPionSpts-1) )
	    {
	    // ##########################################################
	    // ### Set this point equal to the previous point's dE/dX ###
	    // ##########################################################
	    Piondedx[caloPoints] = Piondedx[caloPoints - 1];
	    }//<---End large and at the end of the track
	 
	 // ############################################################
	 // ### Else, if it is a large dE/dX but not the first point ###
	 // ############################################################
	 else if(Piondedx[caloPoints] > 40. && caloPoints < (nPionSpts-1) && caloPoints > 0.)
	    {
	    
	    if(VERBOSE){std::cout<<"Large Fluctuation"<<std::endl;}
	    // #################################################################
	    // ### Then just average between the previous and the next point ###
	    // #################################################################
	    Piondedx[caloPoints] = ( (Piondedx[caloPoints - 1] + Piondedx[caloPoints + 1]) / 2.);
	    
	    }//<--End large and not at the end of the track
      
         }//<---End caloPoints loop
      
      }//<---Only fixing calorimetry for big fluctuations

// ---------------------------------------------------------------------------------------------------------------------------------------
   
   // ##############################################################################
   // ### Fix the calorimetry issues associated with slightly large fluctuations ###
   // ###                 by extrapolating through the points                    ###
   // ##############################################################################
   if(FixCaloIssue_LessExtremeFluctuation)
      {
      for(size_t caloPoints = 0; caloPoints < nPionSpts; caloPoints++)
         {
	 // ### If dE/dX > 15 and more than 10cm from the end of the track and isn't the first or last point ###
	 if(Piondedx[caloPoints] > 15. && Pionresrange[caloPoints] > 10. && caloPoints > 0.&& caloPoints < (nPionSpts-1) )
	    {
	    if(VERBOSE){std::cout<<"Small Fluctuation"<<std::endl;}
	    // ### Check to see if the previous point is greater than 15 ###
	    if(Piondedx[caloPoints-1] > 15.)
	       {
	       // ### Check to see if the next point is greater than 15 ###
	       if(Piondedx[caloPoints+1] > 15. )
	          {
		  // ### Go 2 points before and after ###
		  Piondedx[caloPoints] = ( (Piondedx[caloPoints - 2] + Piondedx[caloPoints + 2]) / 2.);
		  }
	       else
	          {
		  // ### Go 2 points before and one point after ###
		  Piondedx[caloPoints] = ( (Piondedx[caloPoints - 2] + Piondedx[caloPoints + 1]) / 2.);
		  }
	        }
	    else if(Piondedx[caloPoints-1] <= 15.)
	       {
	       if(Piondedx[caloPoints+1] > 15. )
	          {
		  Piondedx[caloPoints] = ( (Piondedx[caloPoints - 1] + Piondedx[caloPoints+2]) / 2.);
		  }
	       else
	          {
		  Piondedx[caloPoints] = ( (Piondedx[caloPoints - 2] + Piondedx[caloPoints + 1]) / 2.);
		  }
	       }
	   else Piondedx[caloPoints] = ( (Piondedx[caloPoints - 1] + Piondedx[caloPoints+1]) / 2.);
	   }
	
      
         }//<---End caloPoints loop
      
      }//<---Only fixing calorimetry for less big fluctuations   
   
   
   
   // =========================================================================================================================================
   //						Filling Incident and Interacting Histograms
   // =========================================================================================================================================
   
   // #########################################
   // ### Loop over the tracks in the event ###
   // #########################################
   for(size_t nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ### Skipping all the tracks which aren't well matched ###
      if(!MatchTPC_WVTrack[nTPCtrk]){continue;}
      
      // ############################################
      // ### Loop over all the calorimetry points ###
      // ############################################
      for(size_t npoints = 0; npoints < nPionSpts; npoints++)
         {
	 // ### Filling the incidient histogram weighted by beam profile ###
         hdataIncidentKE->Fill(kineticEnergy, EventWeight);
	 
	 hdataIncidentKEunweighted->Fill(kineticEnergy);
      
         // ###            Filling the interaction histogram for the last spt          ###
	 // ### As long as it isn't a through going track and isn't tagged as stopping ###
         if(npoints == nPionSpts -1 && !ThroughGoingTrack[nTPCtrk] && !StoppingParticle[nTPCtrk] )
            {
	    
	    // ### Weighting the Interaction by the beam profile ###
	    hdataInteractingKE->Fill(kineticEnergy, EventWeight);
	    
	    // ### Saving the unweighted interaction ###
	    hdataInteractingKEunweighted->Fill(kineticEnergy);
	    }
         
	 // ################################################
	 // ### Subtracting the energy loss in this step ###
	 // ################################################
         float energyLossInStep = Piondedx[npoints] * Pionpitchhit[npoints];
         
	 // #######################################################
	 // ### Removing that kinetic energy from the histogram ###
	 // #######################################################
         kineticEnergy -= energyLossInStep;
      
      
      
      
         }//<---End npoints loop
      }//<---End nTPCtrk loop





   }//<---End jentry loop


// ===============================================================================================================
//					MAKING THE CROSS-SECTION PLOT
// ===============================================================================================================

// ###################################################################
// #### Looping over the exiting bins to extract the cross-section ###
// ###################################################################
for( int iBin = 1; iBin <= hdataInteractingKE->GetNbinsX(); ++iBin )
   {
   // ### If an incident bin is equal to zero then skip that bin ###
   if( hdataIncidentKE->GetBinContent(iBin) == 0 )continue; //Temporary fix to ensure that no Infinities are propagated to pad
   
   // ### Cross-section = (Exit Bins / Incident Bins) * (1/Density) * (1/slab width) ###
   float TempCrossSection = (hdataInteractingKE->GetBinContent(iBin)/hdataIncidentKE->GetBinContent(iBin)) * (1/number_density) * (1/slab_width);
   
   // ### Covert this into Barns ###
   float crossSection = TempCrossSection * (1/1e-28);
   
   // ### Putting the value on the plot
   fCrossSection->SetBinContent(iBin,crossSection);
   
   // ###########################################################
   // ### Calculating the error on the numerator of the ratio ###
   // ###########################################################
   float numError = pow(hdataInteractingKE->GetBinContent(iBin),0.5);
   float num = hdataInteractingKE->GetBinContent(iBin);

   // ### Putting in a protection against dividing by zero ###   
   if(num == 0){num = 1;}
   float term1 = numError/num;
   
   // #################################################
   // ### Calculating the error on the denomentator ###
   // #################################################
   float denomError = pow(hdataIncidentKE->GetBinContent(iBin),0.5);
   float denom = hdataIncidentKE->GetBinContent(iBin);
   if(denom == 0){denom = 1;}
   
   // ### Putting in a protection against dividing by zero ###
   float term2 = denomError/denom;
   
   float totalError = (TempCrossSection) * (pow( ( (term1*term1) + (term2*term2) ),0.5)) * (1/number_density) * (1/slab_width) * (1/1e-28) *(1e26);
   //std::cout<<"totalError = "<<totalError<<std::endl;
   fCrossSection->SetBinError(iBin,totalError);
   
   }//<---End iBin Loop




// ========================================================================================================
// ===					EVENT REDUCTION TABLE						===
// ========================================================================================================
std::cout<<std::endl;
std::cout<<"########################################################################"<<std::endl;
std::cout<<"### Number of Events in AnaModule                                = "<<nTotalEvents<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 0   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ WC Track                                 = "<<nEvtsWCTrack<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ TOF > "<<LowerTOFGoodReco<<" ns and < "<<UpperTOFGoodReco<<" ns                   = "<<nEvtsTOF<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ Good TPC info (nHits > 0)		     = "<<nEvntsTPC<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 1   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ PID consistent with Pi/Mu                = "<<nEvtsPID<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 2   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ Primary MC which enters the TPC                   = "<<nEvtsGoodMC<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ Trk Z < "<<FirstSpacePointZPos<<"                                = "<<nEvtsTrackZPos<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ < "<<nLowZTracksAllowed<<" tracks in the first "<<UpperPartOfTPC<<" cm of the TPC = "<<nLowZTrkEvents<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ ONE WC Track Matched                     = "<<nEvtsWCTrackMatch<<" ###"<<std::endl;
std::cout<<"###              ( "<<DeltaXLowerBound<<" < Delta X < "<<DeltaXUpperBound<<" , "<<DeltaYLowerBound<<" < Delta Y < "<<DeltaYUpperBound<<" )              ###"<<std::endl;
std::cout<<"###                 and alpha less the "<<alphaCut<<" degrees                      ###"<<std::endl;
std::cout<<"### Number of Events that are not Shower Like                        = "<<nNonShowerEvents<<std::endl;
std::cout<<"########################################################################"<<std::endl;
std::cout<<std::endl;   
   
// ===========================================================================================
// ============================  Writing out histograms to ROOT File =========================
// ===========================================================================================
// ###############################################
// ### Creating a file to output my histograms ###
// ###############################################
//TFile myfile("PionMC_PionXSection_histos_noCorrections.root","RECREATE");
//TFile myfile("PionMC_PionXSection_histos_noCorrections_KEWeight.root","RECREATE");
//TFile myfile("PionMC_PionXSection_histos_noCorrections_OldEventWeights.root","RECREATE");
//TFile myfile("PionMC_PionXSection_histos_KEWeight_reorderingOnly.root","RECREATE");
//TFile myfile("PionMC_PionXSection_histos_KEWeight_reordering_FixExtremeFluctuation.root","RECREATE");
//TFile myfile("PionMC_PionXSection_histos_KEWeight_reordering_FixExtremeAndSmallFluctuation.root","RECREATE");
TFile myfile("PionMC_PionXSection_histos_KEWeight_reordering_FixExtremeAndSmallFluctuation_RemoveStopping.root","RECREATE");

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

hdataUpstreamZPos->Write();
hdataTPCTheta->Write();
hdataTPCPhi->Write();
hdataTPCPhiUnWeighted->Write();
hdataTPCThetaUnWeighted->Write();
hdataWCTheta->Write();
hdataWCPhi->Write();
hdataDeltaWCTrkX->Write();
hdataDeltaWCTrkY->Write();
hdataAlpha->Write();
hdataNMatchTPCWCTrk->Write();
hdataWCTRKMomentum->Write();
hdataInitialKEMomentum->Write();
hdataInitialKEMomentumUnWeighted->Write();
hdataPiondEdX->Write();
hdataPionRR->Write();
hdataPionTrkPitch->Write();
hdataPiondEdXvsRR->Write();
hdataLowMomentumTrkPIDA->Write();
hdataIncidentKE->Write();
hdataIncidentKEunweighted->Write();
hdataInteractingKE->Write();
hdataInteractingKEunweighted->Write();
fCrossSection->Write();   
hRecoLength->Write();
hdataTrkInitialX->Write();
hdataTrkInitialXUnweighted->Write();
hdataTrkInitialY->Write();
hdataTrkInitialYUnweighted->Write();

   
}//<---End Loop() Function

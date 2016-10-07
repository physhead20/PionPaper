   //=======================================================================================================================
   //						Uniquely matching one WC Track to TPC Track
   //=======================================================================================================================
   
   // ### Keeping track of the number of matched tracks ###
   int nMatchedTracks = 0;
   
   // ### Setting the index for the track which is ###
   // ### uniquely matched to a wire chamber track ###
   bool MatchTPC_WVTrack[500] = {false};
   
   MatchWCTrackIndex[0] = 0;
   MatchWCTrackIndex[1] = 0;
   MatchWCTrackIndex[2] = 0;
   MatchWCTrackIndex[3] = 0;
   MatchWCTrackIndex[4] = 0;
   MatchWCTrackIndex[5] = 0;
   MatchWCTrackIndex[6] = 0;
   MatchWCTrackIndex[7] = 0;
   MatchWCTrackIndex[8] = 0;
   
   float TempTrj_X = 999;
   float TempTrj_Y = 999;
   float TempTrj_Z = 999;
   
   
   
   // ###############################################################
   // ### Loop over tracks again for WCTrack / TPC Track Matching ###
   // ###############################################################
   float FirstSpacePointIndex[500] = {0.};
   for(size_t nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ############################################
      // ###   Only looking at tracks which have  ###
      // ### a point in the first N cm of the TPC ###
      // ############################################
      if(!PreLimTrackIndex[nTPCtrk]){continue;}
      
      float FirstSpacePointZ = 999;
      float FirstSpacePointY = 999;
      float FirstSpacePointX = 999;
      
      // #########################################################
      // ### Looping over the spacepoints for the prelim-track ###
      // #########################################################
      for(size_t ntrjpts = 0; ntrjpts < nTrajPoint[nTPCtrk]; ntrjpts++)
         {
	 
	 // ### Recording this tracks upstream most X, Y, Z location, ###
	 // ###       which is inside the fiducial boundary           ###
	 if(trjPt_Z[nTPCtrk][ntrjpts] < FirstSpacePointZ && trjPt_Y[nTPCtrk][ntrjpts] > YLowerFid && 
	    trjPt_Y[nTPCtrk][ntrjpts] < YUpperFid && trjPt_X[nTPCtrk][ntrjpts] > XLowerFid && 
	    trjPt_X[nTPCtrk][ntrjpts] < XUpperFid && trjPt_Z[nTPCtrk][ntrjpts] < UpperPartOfTPC)
	    {
	    
	    // ######################################
	    // ### Saving the upstream most point ###
	    // ######################################
	    FirstSpacePointIndex[nTPCtrk] = ntrjpts;
	    FirstSpacePointZ = trjPt_Z[nTPCtrk][ntrjpts];
	    FirstSpacePointY = trjPt_Y[nTPCtrk][ntrjpts];
	    FirstSpacePointX = trjPt_X[nTPCtrk][ntrjpts];
	    
	    // #################################################
	    // ### Saving the most upstream trajectory point ###
	    // #################################################
	    TempTrj_X = pHat0_X[nTPCtrk][ntrjpts];
	    TempTrj_Y = pHat0_Y[nTPCtrk][ntrjpts];
	    TempTrj_Z = pHat0_Z[nTPCtrk][ntrjpts];
	    
	    
	    }//<---End Recording the tracks upstream X,Y,Z coordinate
         }//<---end ntrjpts loop
      
      std::cout<<"FirstSpacePointZ = "<<FirstSpacePointZ<<std::endl;
      
      
      // #################################################################
      // ### Skipping this track if this isn't the going to be matched ###
      // #################################################################
      if(FirstSpacePointZ == 999){continue;}
      
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
      hdataTPCTheta->Fill(tpcTheta* (180.0/3.141592654));
   
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
      hdataTPCPhi->Fill(tpcPhi* (180.0/3.141592654));
      
      // ===============================================================================================================            
      // ===============================================================================================================      
      
      // ### Now that I've gotten the earliest X, Y, Z trajectory point for this track ###
      // ###     I record the Delta X, Y, Z between this track and the WCTrack         ###
      
      
      // ### Variables for Delta WC and TPC tracks ###
      float DeltaX_WC_TPC_Track = 999;
      float DeltaY_WC_TPC_Track = 999;
      
      // #########################################################
      // ### Define the unit vectors for the WC and TPC Tracks ###
      // #########################################################
      
      float wcTheta = 999;
      float wcPhi = 999;
      
      TVector3 theUnitVector_WCTrack;
      TVector3 theUnitVector_TPCTrack;
      
      // #################################      
      // ### Looping over the WCTrack ####
      // #################################
      std::cout<<"N WCTrks = "<<nwctrks<<std::endl;
      for(size_t mwctrk = 0; mwctrk < nwctrks; mwctrk++)
         {
	 
	 // ### Grabbing the WCTrack Theta ###
         wcTheta = wctrk_theta[mwctrk];
         hdataWCTheta->Fill(wcTheta* (180.0/3.141592654));
   
         // ### Grabbing the WCTRack Phi ###
         wcPhi = wctrk_phi[mwctrk];
         hdataWCPhi->Fill(wcPhi* (180.0/3.141592654));
 
	 // ### Calculating the Delta X and Delta Y between WC track and TPC track ###
	 DeltaX_WC_TPC_Track = FirstSpacePointX - (wctrk_XFaceCoor[mwctrk]* 0.1);//<---Note: *0.1 to convert to cm
	 DeltaY_WC_TPC_Track = FirstSpacePointY - (wctrk_YFaceCoor[mwctrk]* 0.1);
	 
	 // ### Filling the Delta X and Delta Y between WC tracks and TPC Tracks ###
	 hdataDeltaWCTrkY->Fill(DeltaY_WC_TPC_Track);
	 hdataDeltaWCTrkX->Fill(DeltaX_WC_TPC_Track);
         
         // === WCTrack Unit Vector ===
         theUnitVector_WCTrack.SetX(sin(wcTheta)*cos(wcPhi));
         theUnitVector_WCTrack.SetY(sin(wcTheta)*sin(wcPhi));
         theUnitVector_WCTrack.SetZ(cos(wcTheta));
    
         // === TPC Track Unit Vector ===
         theUnitVector_TPCTrack.SetX(sin(tpcTheta)*cos(tpcPhi));
         theUnitVector_TPCTrack.SetY(sin(tpcTheta)*sin(tpcPhi));
         theUnitVector_TPCTrack.SetZ(cos(tpcTheta));
	 
	 // ###########################################################
         // ### Calculating the angle between WCTrack and TPC Track ###
         // ###########################################################
         float alpha = ( acos(theUnitVector_WCTrack.Dot(theUnitVector_TPCTrack)) )* (180.0/3.141592654);
   
         hdataAlpha->Fill(alpha);
	 std::cout<<"DeltaX_WC_TPC_Track = "<<DeltaX_WC_TPC_Track<<std::endl;
	 std::cout<<"DeltaY_WC_TPC_Track = "<<DeltaY_WC_TPC_Track<<std::endl;
	 std::cout<<"alpha = "<<alpha<<std::endl;
	 // ### Counting the number of matched tracks ###
	 if( (DeltaX_WC_TPC_Track > DeltaXLowerBound && DeltaX_WC_TPC_Track < DeltaXUpperBound) &&
	     (DeltaY_WC_TPC_Track > DeltaYLowerBound && DeltaY_WC_TPC_Track < DeltaYUpperBound) &&
	      alpha < alphaCut )
	     {
	     // ### Setting the index of this track to true ###
	     MatchTPC_WVTrack[nTPCtrk] = true;
	     // ### Counting the matched tracks ###
	     nMatchedTracks++;
	     
	     // ### Setting the WCTrack Index = 1 if this WCTrack was matched ###
	     MatchWCTrackIndex[mwctrk] = 1;
	     }
	 
	 }//<---End mwctrk loop
      
      }//<---End nTPCtrk loop
   
   
   // ### Filling the number of matched WC and TPC Tracks ###
   hdataNMatchTPCWCTrk->Fill(nMatchedTracks); 
    
   // ### Skipping this event if no WC track is matched ###
   // ###    OR if more than one WC track is matched    ###
   if( (nMatchedTracks < 1 || nMatchedTracks > 1)){continue;}
   
   // ### Counting the number of events with ONE WC track matched ###
   nEvtsWCTrackMatch++;
   
   std::cout<<"Passed"<<std::endl;

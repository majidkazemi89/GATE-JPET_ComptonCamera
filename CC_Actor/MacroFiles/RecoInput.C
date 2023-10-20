#include <bits/stdc++.h>
using namespace std;
// ----------------------------------------------------------------------------------------------
// Convert function get the requested input file for our reconstruction framework
// ----------------------------------------------------------------------------------------------
void Convert() {
    
   
   TFile *input = TFile::Open("./output/2_modules_doubleWidths/test2_sequenceCoincidence.root");
   //TFile *input = TFile::Open("test2_sequenceCoincidence.root");
   
   Float_t energy, energyFinal, energyIni, globalPosX, globalPosY, globalPosZ; 
   Float_t localPosX, localPosY, localPosZ, sourcePosX, sourcePosY, sourcePosZ, sourceEnergy; 
   Int_t runID, coincID, eventID, sourcePDG;
   Double_t time;
   Int_t nCrystalConv, nCrystalCompt, nCrystalRayl;
   
   Char_t layerName;
   
   Int_t volumeID[10];
   std::vector< std::pair<Int_t, Int_t>> coinc;
   map<int, int> M;
   
   //Int_t val[100];
    
   TTree* theTree = (TTree*)input->Get("sequenceCoincidence");
   std::cout << "--- Processing: " << theTree->GetEntries() << " entries" << std::endl;
  
   
   theTree->SetBranchAddress("runID", &runID);
   theTree->SetBranchAddress("coincID", &coincID);
   theTree->SetBranchAddress("eventID", &eventID);
   theTree->SetBranchAddress("time", &time);
   theTree->SetBranchAddress( "energy", &energy );
   theTree->SetBranchAddress("energyFinal", &energyFinal);
   theTree->SetBranchAddress( "energyIni", &energyIni );
   theTree->SetBranchAddress("globalPosX", &globalPosX);
   theTree->SetBranchAddress( "globalPosY", &globalPosY );
   theTree->SetBranchAddress("globalPosZ", &globalPosZ);
   theTree->SetBranchAddress( "localPosX", &localPosX );
   theTree->SetBranchAddress("localPosY", &localPosY );
   theTree->SetBranchAddress( "localPosZ", &localPosZ );
   theTree->SetBranchAddress("sourcePosX", &sourcePosX);
   theTree->SetBranchAddress( "sourcePosY", &sourcePosY );
   theTree->SetBranchAddress("sourcePosZ", &sourcePosZ);
   theTree->SetBranchAddress( "sourceEnergy", &sourceEnergy );
   theTree->SetBranchAddress("sourcePDG", &sourcePDG);
   theTree->SetBranchAddress( "nCrystalConv", &nCrystalConv );
   theTree->SetBranchAddress("nCrystalCompt", &nCrystalCompt );
   theTree->SetBranchAddress( "nCrystalRayl", &nCrystalRayl );
   theTree->SetBranchAddress( "layerName", &layerName );
   theTree->SetBranchAddress( "volumeID", volumeID );
   
   
   
  ///////////////////////////////////////////////////////////////////////
   TFile *target  = new TFile( "ReconstructionInput.root","RECREATE" );
   
   Double_t PosX_1, PosY_1, PosZ_1, Energy_1;
   Double_t PosX_2, PosY_2, PosZ_2, Energy_2;
   TVector3* PosScat = new TVector3();
   TVector3* PosAbs = new TVector3();
   Double_t DEnergy, REnergy, DPosition, EnergyS, PEnergy, ReEnSunc, ReEnS, ReEnP, EnFin, EnIni;
   Double_t EnFin_1, EnIni_1, EnFin_2, EnIni_2;
   Int_t nCrystalCompt_1, nCrystalCompt_2;
   
   Int_t volumeID_1[10],volumeID_2[10];
   
   TTree* tree = new TTree("Reco", "Reco");
   //tree->Branch("EventNumber", &EventNumber);
   tree->Branch("runID", &runID);
   tree->Branch("coincID", &coincID);
   tree->Branch("eventID", &eventID);
   tree->Branch("time", &time);
   //tree->Branch("EnergyFinal", &EnFin);
   //tree->Branch( "EnergyIni", &EnIni );
   tree->Branch("Energy_Primary", &PEnergy);
   //tree->Branch("ReEnergy_Sum", &ReEnS);
   tree->Branch("PosX_Scat", &PosX_1);
   tree->Branch("PosY_Scat", &PosY_1);
   tree->Branch("PosZ_Scat", &PosZ_1);
   tree->Branch("Pos_Scat", &PosScat);
   tree->Branch("Energy_Scat", &Energy_1);
   tree->Branch("EnergyFinal_1", &EnFin_1);
   tree->Branch( "EnergyIni_1", &EnIni_1 );
   //tree->Branch("nCrystalCompt_1", &nCrystalCompt_1 );
   //tree->Branch( "volumeID_1", volumeID_1 );
   tree->Branch("PosX_Abs", &PosX_2);
   tree->Branch("PosY_Abs", &PosY_2);
   tree->Branch("PosZ_Abs", &PosZ_2);
   tree->Branch("Pos_Abs", &PosAbs);
   tree->Branch("Energy_Abs", &Energy_2);
   tree->Branch("EnergyFinal_2", &EnFin_2);
   tree->Branch( "EnergyIni_2", &EnIni_2 );
   //tree->Branch("nCrystalCompt_2", &nCrystalCompt_2 );
   //tree->Branch( "volumeID_2", volumeID_2 );
   //tree->Branch("sourcePDG", &sourcePDG);
   //tree->Branch( "nCrystalConv", &nCrystalConv );
   //tree->Branch("nCrystalCompt", &nCrystalCompt );
   //tree->Branch( "nCrystalRayl", &nCrystalRayl );
   //tree->Branch( "layerName", &layerName );
   //tree->Branch( "volumeID", volumeID );
   //tree->Branch("Energy_Sum", &EnergyS);
   //tree->Branch("Multiplicity", &Multiplicity);
   //tree->Branch("classID", &classID);
   
   for (Int_t ievt=0; ievt < theTree->GetEntries();ievt++) {
     
     theTree->GetEntry(ievt);
     
     //coinc.push_back(coincID);
     coinc.push_back({ ievt, coincID});
   }
   
   /*
   for( int i=0; i<coinc.size(); i++) {
   
     cout << i << " : " << coinc.at(i) << endl;
   }
   */
  /* for (int i = 0; coinc[i]; i++) {
     
     if (M.find(coinc[i]) == M.end()) {
       M[coinc[i]] = 1;
     } else {
       M[coinc[i]]++;
     }
     //cout <<"/////////////////////////////////////////////////" << endl;
   }
   // Traverse the map to print the
    // frequency
   for (auto& it : M) {
     cout << it.first << ' ' << it.second << '\n';
   }
   */
   
   for (Int_t ievt=0; ievt < theTree->GetEntries();ievt++) {
   //for (Int_t ievt=0; ievt < 2;ievt++) {
      theTree->GetEntry(ievt);
      //theTree->Show(ievt);
      Int_t C1 = coincID;
      cout << C1 << endl;
      //coinc.push_back(coincID);
      theTree->GetEntry(ievt+1);
      //theTree->Show(ievt+1);
      Int_t C2 = coincID;
      cout << C2 << endl;
      //coinc.push_back(coincID);
      theTree->GetEntry(ievt+2);
      //theTree->Show(ievt+2);
      Int_t C3 = coincID;
      cout << C3 << endl;
      cout <<"/////////////////////////////////////////////////" << endl;
      
      if (C1 == C2 && C1 == C3) {
      
        theTree->GetEntry(ievt);
        
        if (globalPosX >= 368.25 && globalPosX <= 392.25) {
        
          PosX_2 = globalPosX;
          PosY_2 = globalPosY;
          PosZ_2 = globalPosZ;
          PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
          Energy_2 = energy;
          EnFin_2 = energyFinal;
          EnIni_2 = energyIni;
          //nCrystalCompt_2 = nCrystalCompt;
          //volumeID_2[ievt] = volumeID[ievt];
          PEnergy = sourceEnergy;
          runID = runID;
          coincID = coincID;
          eventID = eventID;
          time = time;
          //EnFin = energyFinal;
          //cout << "in absorber.EnFin..." << EnFin << endl;
          //EnIni = energyIni;
          //cout << "in absorber...." << EnIni << endl;
          
          //sourcePDG = sourcePDG;
          
          theTree->GetEntry(ievt+1); // when 3 singles available in the last coincidence, put this
          if (globalPosX >= 368.25 && globalPosX <= 392.25) {
          
            Energy_2 = Energy_2 + energy;
            EnIni_2 = EnIni_2 + energyIni;
            EnFin_2 = EnFin_2 + energyFinal;
            cout << "in absorber...." << "Depos. :"<< Energy_2 << "," << "EnIni :"<< EnIni_2 << "," << "EnFin :"<< EnFin_2 << endl;
          }
          
       } else {
           cout<<"illegal..posx..in..triple..singles....."<< "posX : "<< globalPosX <<endl;
           continue;
         
       }
       theTree->GetEntry(ievt+2); // when 2 singles available in the last coincidence, put ievt+1
       
       if (globalPosX >= 300.25 && globalPosX <= 324.25) {
    
          //EventNumber = EventNumber;
        
          PosX_1 = globalPosX;
          PosY_1 = globalPosY;
          PosZ_1 = globalPosZ;
          PosScat->SetXYZ(PosX_1,PosY_1,PosZ_1);
          Energy_1 = energy;
          EnFin_1 = energyFinal;
          EnIni_1 = energyIni;
          //nCrystalCompt_1 = nCrystalCompt;
          //volumeID_1[ievt] = volumeID[ievt];
          PEnergy = sourceEnergy;
          runID = runID;
          coincID = coincID;
          eventID = eventID;
          time = time;
          //sourcePDG = sourcePDG;
          //EnFin = energyFinal;
          //cout << "in scatterer.EnFin..." << EnFin << endl;
          //EnIni = EnIni;
          //cout << "in Scatterer...." << EnIni << endl;
          
          theTree->GetEntry(ievt+1); // when 3 singles available in the last coincidence, put this
          if (globalPosX >= 300.25 && globalPosX <= 324.25) {
          
            Energy_1 = Energy_1 + energy;
            EnIni_1 = EnIni_1 + energyIni;
            EnFin_1 = EnFin_1 + energyFinal;
            cout << "in scatterer...." << "Depos. :"<< Energy_1 << "," << "EnIni :"<< EnIni_1 << "," << "EnFin :"<< EnFin_1 << endl;
          }
        
       }
       tree->Fill(); 
       
       ievt = ievt+2; 
      
      } else if (C1 == C2 && C1!= C3) {
      
        theTree->GetEntry(ievt);
        
        if (globalPosX >= 368.25 && globalPosX <= 392.25) {
        
          PosX_2 = globalPosX;
          PosY_2 = globalPosY;
          PosZ_2 = globalPosZ;
          PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
          Energy_2 = energy;
          EnFin_2 = energyFinal;
          EnIni_2 = energyIni;
          //nCrystalCompt_2 = nCrystalCompt;
          //volumeID_2[ievt] = volumeID[ievt];
          PEnergy = sourceEnergy;
          runID = runID;
          coincID = coincID;
          eventID = eventID;
          time = time;
          //sourcePDG = sourcePDG;
          //EnFin = energyFinal;
          //cout << "in absorber.EnFin..0." << EnFin << endl;
          //EnIni = energyIni;
          
       } else {
           cout<<"illegal............."<< "posX : "<< globalPosX <<endl;
           continue;
         
       }  
       theTree->GetEntry(ievt+1);
       
       if (globalPosX >= 300.25 && globalPosX <= 324.25) {
    
          //EventNumber = EventNumber;
        
          PosX_1 = globalPosX;
          PosY_1 = globalPosY;
          PosZ_1 = globalPosZ;
          PosScat->SetXYZ(PosX_1,PosY_1,PosZ_1);
          Energy_1 = energy;
          EnFin_1 = energyFinal;
          EnIni_1 = energyIni;
          //nCrystalCompt_1 = nCrystalCompt;
          //volumeID_1[ievt] = volumeID[ievt];
          PEnergy = sourceEnergy;
          runID = runID;
          coincID = coincID;
          eventID = eventID;
          time = time;
          //sourcePDG = sourcePDG;
          //cout << "FinalEnergy" << EnFin << endl;
          //EnFin = energyFinal;
          //cout << "FinalEnergy" << EnFin << endl;
          //cout << "InitialEnergy" << EnIni << endl;
          //EnIni = energyIni;
          //cout << "InitialEnergy" << EnIni << endl;
          //cout << "''''" << energyIni << endl;
        
      }
      tree->Fill();
      
      ievt = ievt+1;
      
    } else {
        cout << "unequal and no coincidences !!!!!" << endl;
        continue;
    }
    //tree->Fill();
  }
   
   tree->Write();
      
   target->Close();
   
   std::cout << "==> conversion is done!" << std::endl << std::endl;
   
}

////////////////////////////////////////////////
/////////////////////////////////////////

void RecoInput(){
// ----------------------------------------------------------------------------------------
// Run all
// ----------------------------------------------------------------------------------------
   
   
   cout << "========================" << endl;
   cout << "--- Conversion of Final Tree" << endl;
   Convert();
   cout << "========================" << endl;

  
}

int main( int argc, char** argv ) {
   RecoInput();
} 
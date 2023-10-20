#include <bits/stdc++.h>
using namespace std;
// ----------------------------------------------------------------------------------------------
// Convert function get the requested input file for our reconstruction framework
// ----------------------------------------------------------------------------------------------
void Convert() {
    
   
   TFile *input = TFile::Open("./output/test2_sequenceCoincidence.root");
   //TFile *input = TFile::Open("test2_sequenceCoincidence.root");
   
   Float_t energy, energyFinal, energyIni, globalPosX, globalPosY, globalPosZ; 
   Float_t localPosX, localPosY, localPosZ, sourcePosX, sourcePosY, sourcePosZ, sourceEnergy; 
   Int_t runID, coincID, eventID, sourcePDG;
   Double_t time;
   Int_t nCrystalConv, nCrystalCompt, nCrystalRayl;
   
   Char_t layerName;
   
   Int_t volumeID[10];
   std::vector< std::pair<Int_t, Int_t>> coinc;
   //map<int, int> M;
   
   //std::vector<std::pair<Int_t, Int_t>, Int_t> Map;
   std::vector<Int_t> val;
   std::map<std::pair<Int_t, Int_t>, Int_t> counts;
   
   int count2 = 0, count3 = 0, count4 = 0;
   int count = 0;
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
   Int_t EventNumber, nCrystalCompt_1, nCrystalCompt_2;
   
   Int_t classID;
   Int_t volumeID_1[156],volumeID_2[156];
   
   TTree* tree = new TTree("TreeSB", "TreeSB");
   tree->Branch("EventNumber", &EventNumber);
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
   tree->Branch( "EnergyIni_1", &EnIni_1 );
   tree->Branch("EnergyFinal_1", &EnFin_1);
   //tree->Branch("nCrystalCompt_1", &nCrystalCompt_1 );
   //tree->Branch( "volumeID_1", volumeID_1 );
   tree->Branch("PosX_Abs", &PosX_2);
   tree->Branch("PosY_Abs", &PosY_2);
   tree->Branch("PosZ_Abs", &PosZ_2);
   tree->Branch("Pos_Abs", &PosAbs);
   tree->Branch("Energy_Abs", &Energy_2);
   tree->Branch( "EnergyIni_2", &EnIni_2 );
   tree->Branch("EnergyFinal_2", &EnFin_2);
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
   tree->Branch("classID", &classID);
   
   for (Int_t ievt=0; ievt < theTree->GetEntries();ievt++) {
     
       theTree->GetEntry(ievt);
     
       coinc.push_back({ ievt, coincID});
       val.push_back(coincID);
     
   }
  
   std::vector<Int_t> frequency;
   std::vector< std::pair<Int_t, Int_t>> coinc_count;
   
   for (Long64_t i=0; i < val.size(); ++i) {
   
       int freq = std::count(val.begin(), val.end(), val[i]);
       
       coinc_count.push_back({ val[i], freq});
       //std::cout << "Element " << val[i] << " occurs " << freq << " times" << endl;
       
       //counts.insert(std::make_pair(std::make_pair(coinc[i].first,coinc[i].second), freq));
       
       //frequency.push_back(std::count(val.begin(), val.end(), val[i]));
       
   }
    
   for (Long64_t i=0; i < coinc_count.size(); ++i) {
   
       cout << i << " : " << coinc_count[i].first << " , " << coinc_count[i].second << endl;
   }
  
  /* for (Long64_t i=0; i < frequency.size(); ++i) {
   
       cout << i << " : " << frequency[i] << endl;
   }
   for (Int_t ievt=0; ievt < coinc.size();ievt++) {
       
       counts.insert(std::make_pair(std::make_pair(coinc[ievt].first,coinc[ievt].second), frequency[ievt]));
       
   }*/
   /*
   for (const auto &elem: counts) std::cout << "{" << elem.first.first <<
                                                 "," << elem.first.second <<
                                                 "," << elem.second<<
                                                 "}: " << std::endl; //<< elem.second << std::endl; 
   
   */
   
   for (Int_t ievt=0; ievt < theTree->GetEntries();ievt++) {
   
        theTree->GetEntry(ievt);
      
      
        if (coinc_count[ievt].second == 2 && coinc_count[ievt].first == coinc_count[ievt+1].first) {
        
           theTree->GetEntry(ievt); 
           
           if (globalPosX >= 300.25 && globalPosX <= 324.25) {
              //cout <<"....posx..in..double..singles..in Scatterer..."<< "posX : "<< globalPosX <<endl;
              //cout << "Deposited Energy first single.in Scat." << energy << endl;
              //cout << "in Scat.EnIni..." << energyIni << endl;
              //cout << "in Scat.EnFin..." << energyFinal << endl;
              //cout << "'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''" << endl;
              
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
     
          } else {
              //cout <<"...unexpected..posx..in..double..singles..Not in Scatterer..."<< "posX : "<< globalPosX <<endl;
              //cout << "Deposited Energy first single.in Abs." << energy << endl;
              //cout << "in Abs.EnIni..." << energyIni << endl;
              //cout << "in Abs.EnFin..." << energyFinal << endl;
              /*PosX_2 = globalPosX;
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
              time = time;*/
              continue;
          }
          
          theTree->GetEntry(ievt+1); 
 
          if (globalPosX >= 368.25 && globalPosX <= 392.25) {
              //cout <<"....posx..in..double..singles..in Absorber..."<< "posX : "<< globalPosX <<endl;
              //cout << "Deposited Energy first single.in Abs." << energy << endl;
              //cout << "in Abs.EnIni..." << energyIni << endl;
              //cout << "in Abs.EnFin..." << energyFinal << endl;
              //cout << "'''''''''''''''''''''''''''Event''''''''''''''''''''''''''''''''''" << endl;
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
              
          } else {
              //cout <<"...unexpected..posx..in..double..singles..Not in Absorber..."<< "posX : "<< globalPosX <<endl;
              //cout << "Deposited Energy first single.in Scat." << energy << endl;
              //cout << "in Scat.EnIni..." << energyIni << endl;
              //cout << "in Scat.EnFin..." << energyFinal << endl;
              /*PosX_1 = globalPosX;
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
              time = time;*/
              continue;
          }
          
          classID = coinc_count[ievt].second;
          tree->Fill(); 
       
          ievt = ievt+1; 
          
          count2++;
          count++;
          
       } else if (coinc_count[ievt].second == 3 && coinc_count[ievt].first == coinc_count[ievt+1].first && coinc_count[ievt].first == coinc_count[ievt+2].first) { 
       
           theTree->GetEntry(ievt); 
  
           if (globalPosX >= 300.25 && globalPosX <= 324.25) {
              
               cout <<"....posx..in..triple..singles..in Scatterer..."<< "posX : "<< globalPosX <<endl;
               cout << "Deposited Energy first single.in Scat." << energy << endl;
               cout << "in Scat.EnIni..." << energyIni << endl;
               cout << "in Scat.EnFin..." << energyFinal << endl;
               cout << "''''''''''''''''''''''''''''''''First in Scat'''''''''''''''''''''''''''''" << endl;
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
              
              
          } else {
              
              cout <<"...unexpected..posx..in..triple..First single.. in Absorber..Back-scattering."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy first single.in Abs." << energy << endl;
              cout << "in absorber.EnIni..." << energyIni << endl;
              cout << "in absorber.EnFin..." << energyFinal << endl;
              theTree->GetEntry(ievt+1);
              cout <<"...unexpected..posx..in..triple..Second single.. in Absorber."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy second single.in Abs." << energy << endl;
              cout << "in absorber.EnIni..." << energyIni << endl;
              cout << "in absorber.EnFin..." << energyFinal << endl;
              theTree->GetEntry(ievt+2);
              cout <<"...unexpected..posx..in..triple..Last single.. in Scatterer."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy last single.in Scat." << energy << endl;
              cout << "in Scatterer.EnIni..." << energyIni << endl;
              cout << "in Scatterer.EnFin..." << energyFinal << endl;
              cout << ".........................Back-scattering Event..................................." << endl;
              /*
              PosX_1 = globalPosX;
              PosY_1 = globalPosY;
              PosZ_1 = globalPosZ;
              PosScat->SetXYZ(PosX_1,PosY_1,PosZ_1);
              Energy_1 = energy;
              EnFin_1 = energyFinal;
              EnIni_1 = energyIni;
              //nCrystalCompt_2 = nCrystalCompt;
              //volumeID_2[ievt] = volumeID[ievt];
              PEnergy = sourceEnergy;
              runID = runID;
              coincID = coincID;
              eventID = eventID;
              time = time;
              */
              continue;
          } 
          theTree->GetEntry(ievt+1); 
          if (globalPosX >= 368.25 && globalPosX <= 392.25) {
            
              cout <<"posx..in.. Absorber..second single."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy second single.in Abs." << energy << endl;
              Energy_2 = energy;
              EnIni_2 = energyIni;
              EnFin_2 = energyFinal;
              cout << "in absorber.EnIni..Second single." << EnIni_2 << endl;
              cout << "in absorber.EnFin..Second single." << EnFin_2 << endl;
              cout << ".........................Second in Abs..................................." << endl;
            
          } else {
              cout <<"...unexpected..posx..in..triple..singles..Second single..."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy Second single.in Scat." << energy << endl;
              cout << "in absorber.EnIni..Second single." << energyIni << endl;
              cout << "in absorber.EnFin..Second single." << energyFinal << endl;
              Energy_1 = Energy_1 + energy;
              EnIni_1 = energyIni;
              EnFin_1 = energyFinal;
             //continue;
              cout << "Total Deposited Energy.in Scat." <<  Energy_1 << endl;
              cout << ".........................Second in Scat..................................." << endl;
          }
          theTree->GetEntry(ievt+2); 
  
          if (globalPosX >= 368.25 && globalPosX <= 392.25) {
  
              PosX_2 = globalPosX;
              PosY_2 = globalPosY;
              PosZ_2 = globalPosZ;
              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
              EnFin_2 = energyFinal;
              EnIni_2 = energyIni;
              //nCrystalCompt_2 = nCrystalCompt;
              //volumeID_2[ievt] = volumeID[ievt];
              PEnergy = sourceEnergy;
              runID = runID;
              coincID = coincID;
              eventID = eventID;
              time = time;
              Energy_2 = Energy_2 + energy;

              cout <<"....posx..in..triple..singles..in Absorber..."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy last single.in Abs." << energy << endl;
              cout << "Total deposited Energy in Abs." << Energy_2 << endl;
              cout << "in Abs.EnIni..." << energyIni << endl;
              cout << "in Abs.EnFin..." << energyFinal << endl;
              cout << "''''''''''''''''''''''''''''''Event'''''''''''''''''''''''''''''''" << endl;
              
          } else {
              
              cout <<"...unexpected..posx..in..triple..third single.. in Scatterer..."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy third single.in Scat." << energy << endl;
              cout << "in scatterer.EnIni..." << energyIni << endl;
              cout << "in scatterer.EnFin..." << energyFinal << endl;
              cout << ".........................Third in Scat..................................." << endl;
              /*PosX_1 = globalPosX;
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
              time = time;*/
              continue;
              
          }
          
          classID = coinc_count[ievt].second;
          tree->Fill(); 
       
          ievt = ievt+2; 
          
          count3++;
          count++; 
          
       } else if (coinc_count[ievt].second == 4 && coinc_count[ievt].first == coinc_count[ievt+1].first && coinc_count[ievt].first == coinc_count[ievt+2].first && coinc_count[ievt].first == coinc_count[ievt+3].first) { 
       
           theTree->GetEntry(ievt); 
  
           if (globalPosX >= 300.25 && globalPosX <= 324.25) {
              
               cout <<"....posx..in..four..singles..in Scatterer..."<< "posX : "<< globalPosX <<endl;
               cout << "Deposited Energy first single.in Scat." << energy << endl;
               cout << "in Scat.EnIni..." << energyIni << endl;
               cout << "in Scat.EnFin..." << energyFinal << endl;
               cout << "''''''''''''''''''''''''''''First in Scat'''''''''''''''''''''''''''''''''" << endl;
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
              
              
          } else {
              
              cout <<"...unexpected..posx..in..Four singles..First single.. in Absorber..Back-scattering."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy first single.in Abs." << energy << endl;
              cout << "in absorber.EnIni..." << energyIni << endl;
              cout << "in absorber.EnFin..." << energyFinal << endl;
              theTree->GetEntry(ievt+1);
              cout <<"...unexpected..posx..in..Four..Second single..."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy second single.in Abs." << energy << endl;
              cout << "in absorber.EnIni..." << energyIni << endl;
              cout << "in absorber.EnFin..." << energyFinal << endl;
              theTree->GetEntry(ievt+2);
              cout <<"...unexpected..posx..in..Four..Third single..."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy last single.in Scat." << energy << endl;
              cout << "in Scatterer.EnIni..." << energyIni << endl;
              cout << "in Scatterer.EnFin..." << energyFinal << endl;
              theTree->GetEntry(ievt+3);
              cout <<"...unexpected..posx..in..Four..Last single..."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy last single.in Scat." << energy << endl;
              cout << "in Scatterer.EnIni..." << energyIni << endl;
              cout << "in Scatterer.EnFin..." << energyFinal << endl;
              cout << ".........................Back-scattering Event..................................." << endl;
              /*
              PosX_1 = globalPosX;
              PosY_1 = globalPosY;
              PosZ_1 = globalPosZ;
              PosScat->SetXYZ(PosX_1,PosY_1,PosZ_1);
              Energy_1 = energy;
              EnFin_1 = energyFinal;
              EnIni_1 = energyIni;
              //nCrystalCompt_2 = nCrystalCompt;
              //volumeID_2[ievt] = volumeID[ievt];
              PEnergy = sourceEnergy;
              runID = runID;
              coincID = coincID;
              eventID = eventID;
              time = time;
              */
              continue;
          } 
          theTree->GetEntry(ievt+1); 
          if (globalPosX >= 368.25 && globalPosX <= 392.25) {
            
              cout <<"posx..in.. Absorber..second single."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy second single.in Abs." << energy << endl;
              Energy_2 = energy;
              EnIni_2 = energyIni;
              EnFin_2 = energyFinal;
              cout << "in absorber.EnIni..Second single." << EnIni_2 << endl;
              cout << "in absorber.EnFin..Second single." << EnFin_2 << endl;
              cout << ".........................Second in Abs..................................." << endl;
            
          } else {
              cout <<"...unexpected..posx..in..four..singles..Second single..."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy Second single.in Scat." << energy << endl;
              cout << "in absorber.EnIni..Second single." << energyIni << endl;
              cout << "in absorber.EnFin..Second single." << energyFinal << endl;
              Energy_1 = Energy_1 + energy;
              EnIni_1 = energyIni;
              EnFin_1 = energyFinal;
             //continue;
              cout << "Total Deposited Energy.in Scat." <<  Energy_1 << endl;
              cout << ".........................Second in Scat..................................." << endl;
          }
          theTree->GetEntry(ievt+2); 
          if (globalPosX >= 368.25 && globalPosX <= 392.25) {
            
              cout <<"posx..in.. Absorber..third single."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy third single.in Abs." << energy << endl;
              Energy_2 = Energy_2 + energy;
              EnIni_2 = energyIni;
              EnFin_2 = energyFinal;
              cout << "in absorber.EnIni..Second single." << EnIni_2 << endl;
              cout << "in absorber.EnFin..Second single." << EnFin_2 << endl;
              cout << "Total Deposited Energy.in Abs." <<  Energy_2 << endl;
              cout << ".........................Third in Abs..................................." << endl;
            
          } else {
              cout <<"...unexpected..posx..in..four..singles..third single..."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy third single.in Scat." << energy << endl;
              cout << "in absorber.EnIni..third single." << energyIni << endl;
              cout << "in absorber.EnFin..third single." << energyFinal << endl;
              Energy_1 = Energy_1 + energy;
              EnIni_1 = energyIni;
              EnFin_1 = energyFinal;
             //continue;
              cout << "Total Deposited Energy.in Scat." <<  Energy_1 << endl;
              cout << ".........................Third in Scat..................................." << endl;
          }
          theTree->GetEntry(ievt+3); 
  
          if (globalPosX >= 368.25 && globalPosX <= 392.25) {
  
              PosX_2 = globalPosX;
              PosY_2 = globalPosY;
              PosZ_2 = globalPosZ;
              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
              EnFin_2 = energyFinal;
              EnIni_2 = energyIni;
              //nCrystalCompt_2 = nCrystalCompt;
              //volumeID_2[ievt] = volumeID[ievt];
              PEnergy = sourceEnergy;
              runID = runID;
              coincID = coincID;
              eventID = eventID;
              time = time;
              Energy_2 = Energy_2 + energy;

              cout <<"....posx..in..four..singles..in Absorber..."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy last single.in Abs." << energy << endl;
              cout << "Total deposited Energy in Abs." << Energy_2 << endl;
              cout << "in Abs.EnIni..." << energyIni << endl;
              cout << "in Abs.EnFin..." << energyFinal << endl;
              cout << "''''''''''''''''''''''''''''''Event'''''''''''''''''''''''''''''''" << endl;
              
          } else {
              
              cout <<"...unexpected..posx..in..triple..third single.. in Scatterer..."<< "posX : "<< globalPosX <<endl;
              cout << "Deposited Energy third single.in Scat." << energy << endl;
              cout << "in scatterer.EnIni..." << energyIni << endl;
              cout << "in scatterer.EnFin..." << energyFinal << endl;
              cout << ".........................Fourth in Scat..................................." << endl;
              /*PosX_1 = globalPosX;
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
              time = time;*/
              continue;
              
          }
          
          classID = coinc_count[ievt].second;
          tree->Fill(); 
       
          ievt = ievt+3; 
          
          count4++;
          count++; 
       }    
  
  }
   
   tree->Write();
      
   target->Close();
   
   std::cout << "==> Total event number: " << count << std::endl << std::endl;
   std::cout << "==> Total event number with 2 coincidences: " << count2 << std::endl << std::endl;
   std::cout << "==> Total event number with 3 coincidences: " << count3 << std::endl << std::endl;
   std::cout << "==> Total event number with 4 coincidences: " << count4 << std::endl << std::endl;
   std::cout << "==> conversion is done!" << std::endl << std::endl;
   
}

////////////////////////////////////////////////
/////////////////////////////////////////

void RecoInputNew(){
// ----------------------------------------------------------------------------------------
// Run all
// ----------------------------------------------------------------------------------------
   
   
   cout << "========================" << endl;
   cout << "--- Conversion of Final Tree" << endl;
   Convert();
   cout << "========================" << endl;

  
}

int main( int argc, char** argv ) {
   RecoInputNew();
} 
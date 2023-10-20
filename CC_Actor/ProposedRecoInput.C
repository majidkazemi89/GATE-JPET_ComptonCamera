#include <bits/stdc++.h>
using namespace std;
// ----------------------------------------------------------------------------------------------
// Convert function get the requested input file for our reconstruction framework
// ----------------------------------------------------------------------------------------------
void Convert() {
    
   
   
   TFile *input = TFile::Open("./output/proposed_Twopointsrc4.44_8Modu_2x24Scat_4x24Abs_2e6_sequenceCoincidence.root");
   
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
   
   Float_t lowerlimit_Scat1 = 200;
   Float_t upperlimit_Scat1 = 224;
   Float_t lowerlimit_Scat2 = 324;
   Float_t upperlimit_Scat2 = 348;
   Float_t lowerlimit_Abs = 448;
   Float_t upperlimit_Abs = 544;
   /*
   Float_t lowerlimit_Scat1 = 195;
   Float_t upperlimit_Scat1 = 242.5;
   Float_t lowerlimit_Scat2 = 332.5;
   Float_t upperlimit_Scat2 = 380;
   Float_t lowerlimit_Abs = 470;
   Float_t upperlimit_Abs = 580;
   */
   int count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;
   int count21 = 0, count31 = 0, count41 = 0, count51 = 0, count61 = 0;
   int count22 = 0, count32 = 0, count42 = 0;
   int count = 0, counttriple = 0;
   int count2back = 0, count3back = 0, count4back = 0;
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
   TFile *target  = new TFile( "ProposedReconstructionInput_Twopointsrc4.44_8Modu_2x24Scat_4x24Abs_2e6.root","RECREATE" );
   
   Double_t PosX_1, PosY_1, PosZ_1, Energy_1, ReEnergy_1;
   Double_t PosX_11, PosY_11, PosZ_11, Energy_11;
   Double_t PosX_12, PosY_12, PosZ_12, Energy_12;
   Double_t PosX_21, PosY_21, PosZ_21, Energy_21;
   
   Double_t PosX_201, PosY_201, PosZ_201, Energy_201;
   
   Double_t PosX_101, PosY_101, PosZ_101, Energy_101;
   Double_t PosX_102, PosY_102, PosZ_102, Energy_102;
   Double_t PosX_111, PosY_111, PosZ_111, Energy_111;
   Double_t PosX_112, PosY_112, PosZ_112, Energy_112;
   
   Double_t PosX_02, PosY_02, PosZ_02, Energy_02;
   Double_t PosX_03, PosY_03, PosZ_03, Energy_03;
   Double_t PosX_021, PosY_021, PosZ_021, Energy_021;
   Double_t PosX_011, PosY_011, PosZ_011, Energy_011;
   Double_t PosX_012, PosY_012, PosZ_012, Energy_012;
   
   Double_t Energy_1111, Energy_2222;
   Double_t PosX_3333, PosY_3333, PosZ_3333, Energy_3333;
   
   Double_t PosX_4444, PosY_4444, PosZ_4444, Energy_4444;
   Double_t PosX_5555, PosY_5555, PosZ_5555, Energy_5555;
   Double_t PosX_6666, PosY_6666, PosZ_6666, Energy_6666;
   
   Double_t PosX_2, PosY_2, PosZ_2, Energy_2;
   TVector3* PosScat = new TVector3();
   TVector3* PosAbs = new TVector3();
   Double_t DEnergy, REnergy, DPosition, EnergyS, PEnergy, ReEnSunc, ReEnS, ReEnP, EnFin, EnIni;
   Double_t EnFin_1, EnIni_1, EnFin_2, EnIni_2;
   Double_t EnFin_11, EnIni_11;
   Int_t EventNumber, nCrystalCompt_1, nCrystalCompt_2;
   
   TVector3 r1r2, r2r3;
   
   Int_t classID;
   Int_t volumeID_1[156],volumeID_2[156];
   
   TTree* tree = new TTree("TreeSB", "TreeSB");
   tree->Branch("EventNumber", &EventNumber);
   //tree->Branch("runID", &runID);
   //tree->Branch("coincID", &coincID);
   //tree->Branch("eventID", &eventID);
   //tree->Branch("time", &time);
   //tree->Branch("EnergyFinal", &EnFin);
   //tree->Branch( "EnergyIni", &EnIni );
   tree->Branch("Energy_Primary", &PEnergy);
   //tree->Branch("ReEnergy_Sum", &ReEnS);
   tree->Branch("PosX_Scat", &PosX_1);
   tree->Branch("PosY_Scat", &PosY_1);
   tree->Branch("PosZ_Scat", &PosZ_1);
   tree->Branch("Pos_Scat", &PosScat);
   tree->Branch("Energy_Scat", &Energy_1);
   tree->Branch("ReEnergy_Scat", &ReEnergy_1);
   //tree->Branch( "EnergyIni_1", &EnIni_1 );
   //tree->Branch("EnergyFinal_1", &EnFin_1);
   //tree->Branch("nCrystalCompt_1", &nCrystalCompt_1 );
   //tree->Branch( "volumeID_1", volumeID_1 );
   tree->Branch("PosX_Abs", &PosX_2);
   tree->Branch("PosY_Abs", &PosY_2);
   tree->Branch("PosZ_Abs", &PosZ_2);
   tree->Branch("Pos_Abs", &PosAbs);
   tree->Branch("Energy_Abs", &Energy_2);
   //tree->Branch( "EnergyIni_2", &EnIni_2 );
   //tree->Branch("EnergyFinal_2", &EnFin_2);
   //tree->Branch("nCrystalCompt_2", &nCrystalCompt_2 );
   //tree->Branch( "volumeID_2", volumeID_2 );
   //tree->Branch("sourcePDG", &sourcePDG);
   //tree->Branch( "nCrystalConv", &nCrystalConv );
   //tree->Branch("nCrystalCompt", &nCrystalCompt );
   //tree->Branch( "nCrystalRayl", &nCrystalRayl );
   //tree->Branch( "layerName", &layerName );
   //tree->Branch( "volumeID", volumeID );
   tree->Branch("Energy_Sum", &EnergyS);
   //tree->Branch("Multiplicity", &Multiplicity);
   tree->Branch("classID", &classID);
   
   for (Int_t ievt=0; ievt < theTree->GetEntries();ievt++) {
     
       theTree->GetEntry(ievt);
     
       //coinc.push_back({ ievt, coincID});
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
/*    
   for (Long64_t i=0; i < coinc_count.size(); ++i) {
   
       cout << i << " : " << coinc_count[i].first << " , " << coinc_count[i].second << endl;
   }
*/  
   
   for (Int_t ievt=0; ievt < theTree->GetEntries();ievt++) {
   
        
        theTree->GetEntry(ievt);
      
      
        if (coinc_count[ievt].second == 2 && coinc_count[ievt].first == coinc_count[ievt+1].first) {
            count21++;
            
            theTree->GetEntry(ievt); 
           
           
           if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
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
              ReEnergy_1 = energyIni - energyFinal;
              PEnergy = sourceEnergy;
              runID = runID;
              coincID = coincID;
              eventID = eventID;
              time = time;
              
              theTree->GetEntry(ievt+1);
              if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
              
                  PosX_2 = globalPosX;
                  PosY_2 = globalPosY;
                  PosZ_2 = globalPosZ;
                  PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                  Energy_2 = energy;
                  PEnergy = sourceEnergy;
                  runID = runID;
                  coincID = coincID;
                  eventID = eventID;
                  time = time;
                  EnergyS = Energy_1 + Energy_2;
                  
              } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
              
                  PosX_2 = globalPosX;
                  PosY_2 = globalPosY;
                  PosZ_2 = globalPosZ;
                  PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                  Energy_2 = energy;
                  PEnergy = sourceEnergy;
                  runID = runID;
                  coincID = coincID;
                  eventID = eventID;
                  time = time;
                  EnergyS = Energy_1 + Energy_2;
                  
              } else {
                  cout <<"...unexpected..posx..in..double..singles.......1........................."<< "posX : "<< globalPosX <<endl;
                  cout <<".............................unacceptable event........................." << endl;
                  continue;
              }
              classID = coinc_count[ievt].second;
              tree->Fill(); 
       
              ievt = ievt+1; 
          
              count2++;
              count++;
              
           } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
           
               PosX_1 = globalPosX;
               PosY_1 = globalPosY;
               PosZ_1 = globalPosZ;
               PosScat->SetXYZ(PosX_1,PosY_1,PosZ_1);
               Energy_1 = energy;
               ReEnergy_1 = energyIni - energyFinal;
               PEnergy = sourceEnergy;
               runID = runID;
               coincID = coincID;
               eventID = eventID;
               time = time;
               
               theTree->GetEntry(ievt+1);
               if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
              
                   PosX_2 = globalPosX;
                   PosY_2 = globalPosY;
                   PosZ_2 = globalPosZ;
                   PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                   Energy_2 = energy;
                   PEnergy = sourceEnergy;
                   runID = runID;
                   coincID = coincID;
                   eventID = eventID;
                   time = time;
                   EnergyS = Energy_1 + Energy_2;
                   classID = coinc_count[ievt].second;
                   count2++;
               } else {
           
                   cout <<"...unexpected..posx..in..double..singles...........2....................."<< "posX : "<< globalPosX <<endl;
                   cout <<".............................unacceptable event........................." << endl;
                   if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                       PosX_2 = globalPosX;
                       PosY_2 = globalPosY;
                       PosZ_2 = globalPosZ;
                       PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                       Energy_2 = energy;
                       PEnergy = sourceEnergy;
                       runID = runID;
                       coincID = coincID;
                       eventID = eventID;
                       time = time;
                       EnergyS = Energy_1 + Energy_2;
                       classID = -21;
                       count22++;
                   }
                   //continue; 
               }
               
               tree->Fill(); 
       
               ievt = ievt+1; 
               count++;
               
           } else {
               //cout <<"...unexpected..posx..in..double..First single................................"<< "posX : "<< globalPosX <<endl;
               //cout << "Deposited Energy first single.in Abs." << energy << endl;
               //cout << "in absorber.EnIni..." << energyIni << endl;
               //cout << "in absorber.EnFin..." << energyFinal << endl;
               PosX_2 = globalPosX;
               PosY_2 = globalPosY;
               PosZ_2 = globalPosZ;
               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
               Energy_2 = energy;
               PEnergy = sourceEnergy;
               runID = runID;
               coincID = coincID;
               eventID = eventID;
               time = time;
               
               theTree->GetEntry(ievt+1);
               //cout <<"...unexpected..posx..in..double..Second single..............................."<< "posX : "<< globalPosX <<endl;
               //cout << "Deposited Energy second single..." << energy << endl;
               //cout << "in absorber.EnIni..." << energyIni << endl;
               //cout << "in absorber.EnFin..." << energyFinal << endl;
               
               PosX_1 = globalPosX;
               PosY_1 = globalPosY;
               PosZ_1 = globalPosZ;
               PosScat->SetXYZ(PosX_1,PosY_1,PosZ_1);
               Energy_1 = energy;
               PEnergy = sourceEnergy;
               runID = runID;
               coincID = coincID;
               eventID = eventID;
               time = time;
               EnergyS = Energy_1 + Energy_2;
               cout << ".........................Back-scatteringEvent..................................." << endl;
               
               classID = -2; // Back-scattering Event with 2 interactions
               tree->Fill();
               ievt = ievt+1;
               count2back++;
               count++;
               //continue;
           
           } 
 
       } else if (coinc_count[ievt].second == 3 && coinc_count[ievt].first == coinc_count[ievt+1].first && coinc_count[ievt].first == coinc_count[ievt+2].first) { 
           
           count31++;
           
           theTree->GetEntry(ievt); 
  
           if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
              
               cout << "''''''''''''''''''''''''''''''''First in first Scat'''''''''''''''''''''''''''''" << endl;
               PosX_1 = globalPosX;
               PosY_1 = globalPosY;
               PosZ_1 = globalPosZ;
               PosScat->SetXYZ(PosX_1,PosY_1,PosZ_1);
               Energy_1 = energy;
               ReEnergy_1 = energyIni - energyFinal;
               
               PEnergy = sourceEnergy;
               runID = runID;
               coincID = coincID;
               eventID = eventID;
               time = time;
               
               theTree->GetEntry(ievt+1);
               if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
            
                   //cout <<".....posx..in..triple..singles. second.in the first layer..."<< "posX : "<< globalPosX <<endl;
                   
                   Energy_1 = Energy_1 + energy;

                   PosX_11 = globalPosX;
                   PosY_11 = globalPosY;
                   PosZ_11 = globalPosZ;
                  
                   Energy_11 = energy;
                   
                   
                   theTree->GetEntry(ievt+2);
                   if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                  
                       PosX_2 = globalPosX;
                       PosY_2 = globalPosY;
                       PosZ_2 = globalPosZ;
                       PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                       
                       PEnergy = sourceEnergy;
                       runID = runID;
                       coincID = coincID;
                       eventID = eventID;
                       time = time;
                       Energy_2 = energy;
                       EnergyS = Energy_1 + Energy_2;
                      
                   } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
               
                       PosX_2 = globalPosX;
                       PosY_2 = globalPosY;
                       PosZ_2 = globalPosZ;
                       PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                      
                       PEnergy = sourceEnergy;
                       runID = runID;
                       coincID = coincID;
                       eventID = eventID;
                       time = time;
                       Energy_2 = energy;
                       EnergyS = Energy_1 + Energy_2; 
                       
                  } else {
                      cout <<"...unexpected..posx..in..triple..singles.........1......................."<< "posX : "<< globalPosX <<endl;
                      cout <<".............................unacceptable event........................." << endl;
                      continue;
                  }
                  classID = coinc_count[ievt].second;
                  tree->Fill(); 
       
                  ievt = ievt+2; 
                  cout << ".......................event class with 2 singles in the first scatterer and 1 single in second scat or absorber............" << endl;
                  count3++;
                  count++;  
              
              } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
          
                  PosX_11 = globalPosX;
                  PosY_11 = globalPosY;
                  PosZ_11 = globalPosZ;
                  
                  Energy_11 = energy;
                  
                  
                  cout << "''''''''''''''''''''''''''''''''Second in second Scat'''''''''''''''''''''''''''''" << endl; 
                  theTree->GetEntry(ievt+2);
                  if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                  
                      PosX_2 = PosX_11;
                      PosY_2 = PosY_11;
                      PosZ_2 = PosZ_11;
                      PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                      
                      PEnergy = sourceEnergy;
                      runID = runID;
                      coincID = coincID;
                      eventID = eventID;
                      time = time;
                      Energy_2 = Energy_11 + energy;
                      EnergyS = Energy_1 + Energy_2;
                      classID = coinc_count[ievt].second;
                      count3++;
                     
                      cout << "''''''''''''''''''''''''''''''''third in second Scat'''''''''''''''''''''''''''''" << endl;
                      cout << ".....................event class with each single in each layer or 2 singles in the second scatterer...................." << endl;
                 } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                
                      PosX_2 = globalPosX;
                      PosY_2 = globalPosY;
                      PosZ_2 = globalPosZ;
                      PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                     
                      PEnergy = sourceEnergy;
                      runID = runID;
                      coincID = coincID;
                      eventID = eventID;
                      time = time;
                      Energy_2 = energy;
                      
                      r1r2.SetXYZ(PosX_1 - PosX_11, PosY_1 - PosY_11, PosZ_1 - PosZ_11);
                      r2r3.SetXYZ(PosX_11 - PosX_2, PosY_11 - PosY_2, PosZ_11 - PosZ_2);
                      Double_t dot = r1r2.X()*r2r3.X() + r1r2.Y()*r2r3.Y() + r1r2.Z()*r2r3.Z();
                      Double_t M1 = r1r2.Mag();
                      Double_t M2 = r2r3.Mag();
                      Double_t cost2 = dot/(M1*M2);
                      //EnergyS = Energy_1 + Energy_2 + Energy_11;
                      EnergyS = Energy_1 + 0.5 * (Energy_11 + sqrt(pow(Energy_11,2) + (4*0.511*Energy_11)/(1 - cost2)));
                      classID = coinc_count[ievt].second;
                      count3++;
                      counttriple++;
                      cout <<"....posx..in..triple..singles..in Absorber..."<< "posX : "<< globalPosX <<endl;
                      cout << "Deposited Energy last single.in Abs." << energy << endl;
                      cout << "Total deposited Energy second single in second Scat." << Energy_11 << endl;
                      cout << "Total deposited Energy in Detector." << EnergyS << endl;
                      //cout << "in Abs.EnIni..." << energyIni << endl;
                      //cout << "in Abs.EnFin..." << energyFinal << endl;
                      
                      cout << "''''''''''''''''''''''''''''''''third in Abs'''''''''''''''''''''''''''''" << endl;
                      cout << "''''''''''''''''''''''''''''''Event'''''''''''''''''''''''''''''''" << endl;
                      cout << ".....................event class with each single in each layer or 2 singles in the second scatterer...................." << endl;
                 } else {
                      cout <<"...unexpected..posx..in..triple..singles...........2....................."<< "posX : "<< globalPosX <<endl;
                      cout <<".............................unacceptable event........................." << endl;
                      if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                          PosX_2 = PosX_11;
                          PosY_2 = PosY_11;
                          PosZ_2 = PosZ_11;
                          PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                          
                          PEnergy = sourceEnergy;
                          runID = runID;
                          coincID = coincID;
                          eventID = eventID;
                          time = time;
                          Energy_2 = Energy_11;  
                          Energy_1 = Energy_1 + energy;
                          EnergyS = Energy_1 + Energy_2; 
                          classID = -31;
                          count32++;
                          
                      }
                      
                      //continue;
                 }
                 
                 tree->Fill(); 
       
                 ievt = ievt+2; 
                 count++;  
                
             } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
             
                 PosX_11 = globalPosX;
                 PosY_11 = globalPosY;
                 PosZ_11 = globalPosZ;
                  
                 Energy_11 = energy;
                
                 
                 cout << "''''''''''''''''''''''''''''''''Second in Abs'''''''''''''''''''''''''''''" << endl; 
                 theTree->GetEntry(ievt+2);
                 if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                  
                     PosX_2 = PosX_11;
                     PosY_2 = PosY_11;
                     PosZ_2 = PosZ_11;
                     PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                    
                     PEnergy = sourceEnergy;
                     runID = runID;
                     coincID = coincID;
                     eventID = eventID;
                     time = time;
                     Energy_2 = Energy_11 + energy;
                     EnergyS = Energy_1 + Energy_2;
                     classID = coinc_count[ievt].second;
                     count3++;
                     
                     cout << "''''''''''''''''''''''''''''''''third in Abs'''''''''''''''''''''''''''''" << endl;
                     cout << ".........................event class with a single in first scatterer and 2 singles in the absorber......................" << endl;
                 } else {
                     cout <<"...unexpected..posx..in..triple..singles.............3..................."<< "posX : "<< globalPosX <<endl;
                     cout <<".............................unacceptable event........................." << endl;
                     if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                          PosX_2 = PosX_11;
                          PosY_2 = PosY_11;
                          PosZ_2 = PosZ_11;
                          PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                          
                          PEnergy = sourceEnergy;
                          runID = runID;
                          coincID = coincID;
                          eventID = eventID;
                          time = time;
                          Energy_2 = Energy_11;  
                          Energy_1 = Energy_1 + energy;
                          EnergyS = Energy_1 + Energy_2;
                          classID = -32;
                          count32++;  
                      } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                          PosX_2 = PosX_11;
                          PosY_2 = PosY_11;
                          PosZ_2 = PosZ_11;
                          PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                          
                          PEnergy = sourceEnergy;
                          runID = runID;
                          coincID = coincID;
                          eventID = eventID;
                          time = time;
                          Energy_2 = Energy_11;  
                          
                          EnergyS = Energy_1 + Energy_2 + energy; 
                          classID = -32;
                          count32++;
                      }
                      
                     //continue;
                 }
                 
                 tree->Fill(); 
       
                 ievt = ievt+2; 
                 count++; 
            }
                
          } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
        
              cout << "''''''''''''''''''''''''''''''''First in second Scat'''''''''''''''''''''''''''''" << endl;
              PosX_1 = globalPosX;
              PosY_1 = globalPosY;
              PosZ_1 = globalPosZ;
              PosScat->SetXYZ(PosX_1,PosY_1,PosZ_1);
              Energy_1 = energy;
              ReEnergy_1 = energyIni - energyFinal;
              
              PEnergy = sourceEnergy;
              runID = runID;
              coincID = coincID;
              eventID = eventID;
              time = time;
               
              theTree->GetEntry(ievt+1);
              if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
            
                  //cout <<".....posx..in..triple..singles. second.in the second scat..."<< "posX : "<< globalPosX <<endl;
                  Energy_1 = Energy_1 + energy;
                  
                  PosX_11 = globalPosX;
                  PosY_11 = globalPosY;
                  PosZ_11 = globalPosZ;
                  
                  Energy_11 = energy;
                   
                  theTree->GetEntry(ievt+2);
                  if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                  
                      PosX_2 = globalPosX;
                      PosY_2 = globalPosY;
                      PosZ_2 = globalPosZ;
                      PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                      
                      PEnergy = sourceEnergy;
                      runID = runID;
                      coincID = coincID;
                      eventID = eventID;
                      time = time;
                      Energy_2 = energy;
                      EnergyS = Energy_1 + Energy_2;
                      classID = coinc_count[ievt].second;
                      count3++;
                      cout << "............................event class with 2 singles in second scatterer and a single in the absorber................." << endl;
                 
                  
                 } else {
                     cout <<"...unexpected..posx..in..triple..singles...........4....................."<< "posX : "<< globalPosX <<endl;
                     cout <<".............................unacceptable event........................." << endl;
                     if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                         PosX_2 = globalPosX;
                         PosY_2 = globalPosY;
                         PosZ_2 = globalPosZ;
                         PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                         
                         PEnergy = sourceEnergy;
                         runID = runID;
                         coincID = coincID;
                         eventID = eventID;
                         time = time;
                         Energy_2 = energy;
                         EnergyS = Energy_1 + Energy_2;
                         classID = -33;
                         count32++; 
                     }
                     
                     //continue;
                 }
                 
                 tree->Fill(); 
       
                 ievt = ievt+2; 
                 
                 count++; 
                 
             } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                  
                 PosX_11 = globalPosX;
                 PosY_11 = globalPosY;
                 PosZ_11 = globalPosZ;
                  
                 Energy_11 = energy;
                  
                 cout << "''''''''''''''''''''''''''''''''Second in Abs'''''''''''''''''''''''''''''" << endl; 
                 theTree->GetEntry(ievt+2);
                 if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                  
                     PosX_2 = PosX_11;
                     PosY_2 = PosY_11;
                     PosZ_2 = PosZ_11;
                     PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                     
                     PEnergy = sourceEnergy;
                     runID = runID;
                     coincID = coincID;
                     eventID = eventID;
                     time = time;
                     Energy_2 = Energy_11 + energy;
                     EnergyS = Energy_1 + Energy_2;
                     classID = coinc_count[ievt].second;
                     count3++;
                  
                     cout << "''''''''''''''''''''''''''''''''third in Abs'''''''''''''''''''''''''''''" << endl;
                     cout << "...............................event class with a single in second scatterer and 2 singles in the absorber..............." << endl;
                 } else {
                     cout <<"...unexpected..posx..in..triple..singles...........5....................."<< "posX : "<< globalPosX <<endl;
                     cout <<".............................unacceptable event........................." << endl;
                     if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                          PosX_2 = PosX_11;
                          PosY_2 = PosY_11;
                          PosZ_2 = PosZ_11;
                          PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                          
                          PEnergy = sourceEnergy;
                          runID = runID;
                          coincID = coincID;
                          eventID = eventID;
                          time = time;
                          Energy_2 = Energy_11;  
                          
                          EnergyS = Energy_1 + Energy_2 + energy;
                          classID = -34;
                          count32++;  
                      } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                          PosX_2 = PosX_11;
                          PosY_2 = PosY_11;
                          PosZ_2 = PosZ_11;
                          PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                          
                          PEnergy = sourceEnergy;
                          runID = runID;
                          coincID = coincID;
                          eventID = eventID;
                          time = time;
                          Energy_2 = Energy_11;  
                          Energy_1 = Energy_1 + energy;
                          EnergyS = Energy_1 + Energy_2;
                          classID = -34;
                          count32++; 
                      }
                      
                     //continue;
                 }
                 
                 tree->Fill(); 
       
                 ievt = ievt+2; 
                 count++;  
                 
             } 
             
          } else {
              
              //cout <<"...unexpected..posx..in..triple..First single................................"<< "posX : "<< globalPosX <<endl;
              //cout << "Deposited Energy first single.in Abs." << energy << endl;
              //cout << "in absorber.EnIni..." << energyIni << endl;
              //cout << "in absorber.EnFin..." << energyFinal << endl;
              PosX_2 = globalPosX;
              PosY_2 = globalPosY;
              PosZ_2 = globalPosZ;
              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
              
              PEnergy = sourceEnergy;
              runID = runID;
              coincID = coincID;
              eventID = eventID;
              time = time;
              Energy_2 = energy;
              
              theTree->GetEntry(ievt+1);
              //cout <<"...unexpected..posx..in..triple..Second single..............................."<< "posX : "<< globalPosX <<endl;
              //cout << "Deposited Energy second single..." << energy << endl;
              //cout << "in absorber.EnIni..." << energyIni << endl;
              //cout << "in absorber.EnFin..." << energyFinal << endl;
              Energy_2 = Energy_2 + energy;
              
              theTree->GetEntry(ievt+2);
              //cout <<"...unexpected..posx..in..triple..Last single................................."<< "posX : "<< globalPosX <<endl;
              //cout << "Deposited Energy last single..." << energy << endl;
              //cout << "in Scatterer.EnIni..." << energyIni << endl;
              //cout << "in Scatterer.EnFin..." << energyFinal << endl;
              PosX_1 = globalPosX;
              PosY_1 = globalPosY;
              PosZ_1 = globalPosZ;
              PosScat->SetXYZ(PosX_1,PosY_1,PosZ_1);
              Energy_1 = energy;
              
              PEnergy = sourceEnergy;
              runID = runID;
              coincID = coincID;
              eventID = eventID;
              time = time;
              EnergyS = Energy_1 + Energy_2;
              classID = -3; // Back-scattering Event with 3 interactions
              tree->Fill();
              ievt = ievt+2;
              cout << ".........................Back-scatteringEvent..................................." << endl;
              count3back++;
              count++; 
              
              //continue;
          } 
          
       } else if (coinc_count[ievt].second == 4 && coinc_count[ievt].first == coinc_count[ievt+1].first && coinc_count[ievt].first == coinc_count[ievt+2].first && coinc_count[ievt].first == coinc_count[ievt+3].first) { 
               
           count41++;
           
           theTree->GetEntry(ievt); 
  
           if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                 
              
               cout << "''''''''''''''''''''''''''''''''First in first Scat'''''''''''''''''''''''''''''" << endl;
               PosX_1 = globalPosX;
               PosY_1 = globalPosY;
               PosZ_1 = globalPosZ;
               PosScat->SetXYZ(PosX_1,PosY_1,PosZ_1);
               Energy_1 = energy;
               ReEnergy_1 = energyIni - energyFinal;
               
               PEnergy = sourceEnergy;
               runID = runID;
               coincID = coincID;
               eventID = eventID;
               time = time;
               
               theTree->GetEntry(ievt+1);
               if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
            
                   //cout <<".....posx..in..four..singles. second.in the first layer..."<< "posX : "<< globalPosX <<endl;
                   Energy_1 = Energy_1 + energy;
                   
                   PosX_11 = globalPosX;
                   PosY_11 = globalPosY;
                   PosZ_11 = globalPosZ;
                  
                   Energy_11 = energy;
                  
                   
                   theTree->GetEntry(ievt+2);
                   if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
            
                       //cout <<".....posx..in..four..singles. second.in the first layer..."<< "posX : "<< globalPosX <<endl;
                       Energy_1 = Energy_1 + energy;
                       
                       PosX_12 = globalPosX;
                       PosY_12 = globalPosY;
                       PosZ_12 = globalPosZ;
                  
                       Energy_12 = energy;
                       
                       
                       theTree->GetEntry(ievt+3);
                       if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                  
                           PosX_2 = globalPosX;
                           PosY_2 = globalPosY;
                           PosZ_2 = globalPosZ;
                           PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                           
                           PEnergy = sourceEnergy;
                           runID = runID;
                           coincID = coincID;
                           eventID = eventID;
                           time = time;
                           Energy_2 = energy;
                           EnergyS = Energy_1 + Energy_2;
                  
                  
                       } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
               
                           PosX_2 = globalPosX;
                           PosY_2 = globalPosY;
                           PosZ_2 = globalPosZ;
                           PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                           
                           PEnergy = sourceEnergy;
                           runID = runID;
                           coincID = coincID;
                           eventID = eventID;
                           time = time;
                           Energy_2 = energy;
                           EnergyS = Energy_1 + Energy_2; 
                           cout << "..............event class with 3 singles in the first scatterer and 1 single in second scat or absorber............" << endl;
                      } else {
                          cout <<"...unexpected..posx..in..four..singles.........1......................."<< "posX : "<< globalPosX <<endl;
                          cout <<".............................unacceptable event........................." << endl;
                          continue;
                      }
                      classID = coinc_count[ievt].second;
                      tree->Fill(); 
       
                      ievt = ievt+3; 
                      
                      count4++;
                      count++;  
              
                   } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
          
                      PosX_21 = globalPosX;
                      PosY_21 = globalPosY;
                      PosZ_21 = globalPosZ;
                  
                      Energy_21 = energy;
                      
                  
                      cout << "''''''''''''''''''''''''''''''''third in second Scat'''''''''''''''''''''''''''''" << endl; 
                      theTree->GetEntry(ievt+3);
                      if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                  
                          PosX_2 = PosX_21;
                          PosY_2 = PosY_21;
                          PosZ_2 = PosZ_21;
                          PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                          
                          PEnergy = sourceEnergy;
                          runID = runID;
                          coincID = coincID;
                          eventID = eventID;
                          time = time;
                          Energy_2 = Energy_21 + energy;
                          EnergyS = Energy_1 + Energy_2;
                          classID = coinc_count[ievt].second;
                          count4++;
                          cout << "''''''''''''''''''''''''''''''''fourth in second Scat'''''''''''''''''''''''''''''" << endl;
                  
                     } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                
                          PosX_2 = globalPosX;
                          PosY_2 = globalPosY;
                          PosZ_2 = globalPosZ;
                          PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                          
                          PEnergy = sourceEnergy;
                          runID = runID;
                          coincID = coincID;
                          eventID = eventID;
                          time = time;
                          Energy_2 = energy;
      
                          EnergyS = Energy_1 + Energy_21 + Energy_2;
                          classID = coinc_count[ievt].second;
                          count4++;
                          cout << "''''''''''''''''''''''''''''''''fourth in Abs'''''''''''''''''''''''''''''" << endl;
                          cout << "''''''''''''''''''''''''''''''Event'''''''''''''''''''''''''''''''" << endl;
                      
                     } else {
                          cout <<"...unexpected..posx..in..four..singles...........2....................."<< "posX : "<< globalPosX <<endl;
                          cout <<".............................unacceptable event........................." << endl;
                          if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                              PosX_2 = PosX_21;
                              PosY_2 = PosY_21;
                              PosZ_2 = PosZ_21;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = Energy_21;
                              Energy_1 = Energy_1 + energy;
                              EnergyS = Energy_1 + Energy_2;
                          }
                          classID = -5;
                          
                          count42++;
                           
                          //continue;
                     }
                     
                     tree->Fill(); 
       
                     ievt = ievt+3; 
                     
                     count++;
                     
                   } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                           
                     PosX_201 = globalPosX;
                     PosY_201 = globalPosY;
                     PosZ_201 = globalPosZ;
                  
                     Energy_201 = energy;
                    
                     cout << "''''''''''''''''''''''''''''''''third in Abs'''''''''''''''''''''''''''''" << endl;
                     
                     theTree->GetEntry(ievt+3);
                     if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                          
                         PosX_2 = PosX_201;
                         PosY_2 = PosY_201;
                         PosZ_2 = PosZ_201;
                         PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                         
                         PEnergy = sourceEnergy;
                         runID = runID;
                         coincID = coincID;
                         eventID = eventID;
                         time = time;
                         Energy_2 = Energy_201 + energy;
      
                         EnergyS = Energy_1 + Energy_2;
                         classID = coinc_count[ievt].second;
                         count4++;
                         cout << "''''''''''''''''''''''''''''''''fourth in Abs'''''''''''''''''''''''''''''" << endl;
                         cout << "''''''''''''''''''''''''''''''Event'''''''''''''''''''''''''''''''" << endl;
                         cout << ".....................event class with 2 singles in first layer and 2 singles in absorber...................." << endl;
                     } else {
                         cout <<"...unexpected..posx..in..four..singles...........3....................."<< "posX : "<< globalPosX <<endl;
                         cout <<".............................unacceptable event........................." << endl;
                         if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                              PosX_2 = PosX_201;
                              PosY_2 = PosY_201;
                              PosZ_2 = PosZ_201;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = Energy_201;
                              Energy_1 = Energy_1 + energy;
                              EnergyS = Energy_1 + Energy_2;
                          } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                              PosX_2 = PosX_201;
                              PosY_2 = PosY_201;
                              PosZ_2 = PosZ_201;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                             
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = Energy_201;
                              EnergyS = Energy_1 + Energy_2 + energy;
                          }
                          classID = -6;
                          
                          count42++;
                           
                         //continue;
                     } 
                     
                     tree->Fill(); 
       
                     ievt = ievt+3; 
                     
                     
                     count++;
                   
               } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
               
                     PosX_11 = globalPosX;
                     PosY_11 = globalPosY;
                     PosZ_11 = globalPosZ;
                  
                     Energy_11 = energy;
                     
                     cout << "''''''''''''''''''''''''''''''''second in second scat'''''''''''''''''''''''''''''" << endl;
                     
                     theTree->GetEntry(ievt+2);
                     if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                     
                         PosX_12 = globalPosX;
                         PosY_12 = globalPosY;
                         PosZ_12 = globalPosZ;
                  
                         Energy_12 = energy;
                         
                         cout << "''''''''''''''''''''''''''''''''third in second scat'''''''''''''''''''''''''''''" << endl;
                         
                         theTree->GetEntry(ievt+3);
                         if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                         
                             PosX_2 = PosX_11;
                             PosY_2 = PosY_11;
                             PosZ_2 = PosZ_11;
                             PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                            
                             PEnergy = sourceEnergy;
                             runID = runID;
                             coincID = coincID;
                             eventID = eventID;
                             time = time;
                             Energy_2 = energy + Energy_11 + Energy_12;
      
                             EnergyS = Energy_1 + Energy_2;
                             classID = coinc_count[ievt].second;
                             count4++;
                             cout << "''''''''''''''''''''''''''''''''fourth in second scat'''''''''''''''''''''''''''''" << endl;
                         
                         } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                          
                             PosX_2 = globalPosX;
                             PosY_2 = globalPosY;
                             PosZ_2 = globalPosZ;
                             PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                            
                             PEnergy = sourceEnergy;
                             runID = runID;
                             coincID = coincID;
                             eventID = eventID;
                             time = time;
                             Energy_2 = energy;
      
                             EnergyS = Energy_1 + Energy_2 + Energy_11 + Energy_12;
                             classID = coinc_count[ievt].second;
                             count4++;
                             cout << "......event class with 1 single in first layer and 3 singles in second or 2 in second and last in abs..........." << endl;
                         
                         } else {
                             cout <<"...unexpected..posx..in..four..singles...........4....................."<< "posX : "<< globalPosX <<endl;
                             cout <<".............................unacceptable event........................." << endl;
                             if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                              PosX_2 = PosX_11;
                              PosY_2 = PosY_11;
                              PosZ_2 = PosZ_11;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = Energy_11 + Energy_12;
                              Energy_1 = Energy_1 + energy;
                              EnergyS = Energy_1 + Energy_2;
                             }
                             classID = -7;
                             
                             count42++;
                              
                             //continue;
                         }
                         
                         tree->Fill(); 
       
                         ievt = ievt+3; 
                         
                         count++;
                     } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                         PosX_111 = globalPosX;
                         PosY_111 = globalPosY;
                         PosZ_111 = globalPosZ;
                  
                         Energy_111 = energy;
                         
                         cout << "''''''''''''''''''''''''''''''''third in abs'''''''''''''''''''''''''''''" << endl;
                         theTree->GetEntry(ievt+3);
                         if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                         
                             PosX_2 = PosX_111;
                             PosY_2 = PosY_111;
                             PosZ_2 = PosZ_111;
                             PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                            
                             PEnergy = sourceEnergy;
                             runID = runID;
                             coincID = coincID;
                             eventID = eventID;
                             time = time;
                             Energy_2 = energy + Energy_111;
      
                             EnergyS = Energy_1 + Energy_2 + Energy_11;
                             classID = coinc_count[ievt].second;
                             count4++;
                             cout << "''''''''''''''''''''''''''''''''fourth in abs'''''''''''''''''''''''''''''" << endl;
                             cout << ".....................event class with 1 single in first layer and 1 singles in second and 2 in abs.............." << endl;
                         } else {
                             cout <<"...unexpected..posx..in..four..singles...........5....................."<< "posX : "<< globalPosX <<endl;
                             cout <<".............................unacceptable event........................." << endl;
                             if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                                 PosX_2 = PosX_111;
                                 PosY_2 = PosY_111;
                                 PosZ_2 = PosZ_111;
                                 PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                                 
                                 PEnergy = sourceEnergy;
                                 runID = runID;
                                 coincID = coincID;
                                 eventID = eventID;
                                 time = time;
                                 Energy_2 = Energy_111;
                                 Energy_1 = Energy_1 + energy;
                                 EnergyS = Energy_1 + Energy_2 + Energy_11;
                             } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                                 PosX_2 = PosX_111;
                                 PosY_2 = PosY_111;
                                 PosZ_2 = PosZ_111;
                                 PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                                
                                 PEnergy = sourceEnergy;
                                 runID = runID;
                                 coincID = coincID;
                                 eventID = eventID;
                                 time = time;
                                 Energy_2 = Energy_111;
                                 EnergyS = Energy_1 + Energy_2 + Energy_11 + energy;
                             }
                             classID = -8;
                         
                             count42++;
                             
                             //continue;  
                         }
                         
                         tree->Fill(); 
       
                         ievt = ievt+3; 
                         
                         count++; 
                         
                     } else {
                         cout <<"...unexpected..posx..in..four..singles...........6....................."<< "posX : "<< globalPosX <<endl;
                         cout <<".............................unacceptable event........................." << endl;
                         if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                             Energy_1111 = energy;
                             theTree->GetEntry(ievt+3);
                             if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                                 PosX_2 = PosX_11;
                                 PosY_2 = PosY_11;
                                 PosZ_2 = PosZ_11;
                                 PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                                
                                 PEnergy = sourceEnergy;
                                 runID = runID;
                                 coincID = coincID;
                                 eventID = eventID;
                                 time = time;
                                 Energy_2 = Energy_11;
                                 Energy_1 = Energy_1 + energy + Energy_1111;
                                 EnergyS = Energy_1 + Energy_2;
                             } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                                 PosX_2 = PosX_11;
                                 PosY_2 = PosY_11;
                                 PosZ_2 = PosZ_11;
                                 PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                                
                                 PEnergy = sourceEnergy;
                                 runID = runID;
                                 coincID = coincID;
                                 eventID = eventID;
                                 time = time;
                                 Energy_2 = Energy_11 + energy;
                                 Energy_1 = Energy_1 + Energy_1111;
                                 EnergyS = Energy_1 + Energy_2;
                             
                             }
                         } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                             Energy_1111 = energy;
                             theTree->GetEntry(ievt+3);
                             if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                                 PosX_2 = PosX_11;
                                 PosY_2 = PosY_11;
                                 PosZ_2 = PosZ_11;
                                 PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                                
                                 PEnergy = sourceEnergy;
                                 runID = runID;
                                 coincID = coincID;
                                 eventID = eventID;
                                 time = time;
                                 Energy_2 = Energy_11 + Energy_1111;
                                 Energy_1 = Energy_1 + energy;
                                 EnergyS = Energy_1 + Energy_2;
                             }
                         }
                         classID = -9;
                         tree->Fill(); 
                         ievt = ievt+3;
                         count42++;
                         count++;
                         
                         //continue;  
                     }
                       
               } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                   PosX_101 = globalPosX;
                   PosY_101 = globalPosY;
                   PosZ_101 = globalPosZ;
                  
                   Energy_101 = energy;
                  
                   cout << "''''''''''''''''''''''''''''''''second in abs'''''''''''''''''''''''''''''" << endl;
                   theTree->GetEntry(ievt+2);      
                   if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                       
                       PosX_102 = globalPosX;
                       PosY_102 = globalPosY;
                       PosZ_102 = globalPosZ;
                  
                       Energy_102 = energy;
                      
                       cout << "''''''''''''''''''''''''''''''''third in abs'''''''''''''''''''''''''''''" << endl;
                       theTree->GetEntry(ievt+3); 
                       if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) { 
                         
                           PosX_2 = PosX_101;
                           PosY_2 = PosY_101;
                           PosZ_2 = PosZ_101;
                           PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                          
                           PEnergy = sourceEnergy;
                           runID = runID;
                           coincID = coincID;
                           eventID = eventID;
                           time = time;
                           Energy_2 = energy + Energy_101 + Energy_102;
      
                           EnergyS = Energy_1 + Energy_2;
                           classID = coinc_count[ievt].second;
                           count4++;
                           cout << ".....................event class with 1 single in first layer and 3 in abs...................." << endl;
                      
                      } else {
                          cout <<"...unexpected..posx..in..four..singles...........7....................."<< "posX : "<< globalPosX <<endl;
                          cout <<".............................unacceptable event........................." << endl;
                          if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                                 PosX_2 = PosX_101;
                                 PosY_2 = PosY_101;
                                 PosZ_2 = PosZ_101;
                                 PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                                
                                 PEnergy = sourceEnergy;
                                 runID = runID;
                                 coincID = coincID;
                                 eventID = eventID;
                                 time = time;
                                 Energy_2 = Energy_102 + Energy_101;
                                 Energy_1= Energy_1 + energy;
                                 EnergyS = Energy_1 + Energy_2;
                             } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                                 PosX_2 = PosX_101;
                                 PosY_2 = PosY_101;
                                 PosZ_2 = PosZ_101;
                                 PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                                
                                 PEnergy = sourceEnergy;
                                 runID = runID;
                                 coincID = coincID;
                                 eventID = eventID;
                                 time = time;
                                 Energy_2 = Energy_102 + Energy_101;
                                 Energy_1= Energy_1;
                                 EnergyS = Energy_1 + Energy_2 + energy;
                             } 
                             classID = -10;
                             
                             count42++;
                              
                           
                          //continue;  
                      }
                      
                      tree->Fill(); 
       
                      ievt = ievt+3; 
                      
                      count++; 
                   } else 
                      cout <<"...unexpected..posx..in..four..singles...........8....................."<< "posX : "<< globalPosX <<endl;
                      cout <<".............................unacceptable event........................." << endl;
                      if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                          Energy_2222 = energy;
                          theTree->GetEntry(ievt+3);
                          if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                              PosX_2 = PosX_101;
                              PosY_2 = PosY_101;
                              PosZ_2 = PosZ_101;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                             
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = Energy_101;
                              Energy_1= Energy_1 + Energy_2222 + energy;
                              EnergyS = Energy_1 + Energy_2;
                          } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                              PosX_2 = PosX_101;
                              PosY_2 = PosY_101;
                              PosZ_2 = PosZ_101;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = Energy_101;
                              Energy_1= Energy_1 + Energy_2222;
                              EnergyS = Energy_1 + Energy_2 + energy;
                          } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                              PosX_2 = PosX_101;
                              PosY_2 = PosY_101;
                              PosZ_2 = PosZ_101;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = Energy_101 + energy;
                              Energy_1= Energy_1 + Energy_2222;
                              EnergyS = Energy_1 + Energy_2;
                          }
                      } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                          
                          Energy_2222 = energy;
                          theTree->GetEntry(ievt+3);
                          if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                              PosX_2 = PosX_101;
                              PosY_2 = PosY_101;
                              PosZ_2 = PosZ_101;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = Energy_101;
                              Energy_1= Energy_1 + energy;
                              EnergyS = Energy_1 + Energy_2 + Energy_2222;
                          } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                              PosX_2 = PosX_101;
                              PosY_2 = PosY_101;
                              PosZ_2 = PosZ_101;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                             
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = Energy_101;
                              Energy_1= Energy_1;
                              EnergyS = Energy_1 + Energy_2 + energy + Energy_2222;
                          } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                              PosX_2 = PosX_101;
                              PosY_2 = PosY_101;
                              PosZ_2 = PosZ_101;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                             
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = Energy_101 + energy;
                              Energy_1= Energy_1;
                              EnergyS = Energy_1 + Energy_2 + Energy_2222;
                          }
                      } 
                      classID = -11;
                      tree->Fill(); 
                      ievt = ievt+3;
                      count42++;
                      count++; 
                      
                      //continue;  
                   }
                   
               }
           } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
           
               cout << "''''''''''''''''''''''''''''''''First in second Scat'''''''''''''''''''''''''''''" << endl;
               PosX_1 = globalPosX;
               PosY_1 = globalPosY;
               PosZ_1 = globalPosZ;
               PosScat->SetXYZ(PosX_1,PosY_1,PosZ_1);
               Energy_1 = energy;
               ReEnergy_1 = energyIni - energyFinal;
               
               PEnergy = sourceEnergy;
               runID = runID;
               coincID = coincID;
               eventID = eventID;
               time = time;
               
               theTree->GetEntry(ievt+1); 
               if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                   PosX_02 = globalPosX;
                   PosY_02 = globalPosY;
                   PosZ_02 = globalPosZ;
                   
                   Energy_1 = energy + Energy_1;
                   
                   Energy_02 = energy;
                  
                   
                   theTree->GetEntry(ievt+2);
                   if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                       PosX_03 = globalPosX;
                       PosY_03 = globalPosY;
                       PosZ_03 = globalPosZ;
                       
                       Energy_1 = energy + Energy_1;
                       
                       Energy_03 = energy;
                      
                       theTree->GetEntry(ievt+3);
                       if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                           PosX_2 = globalPosX;
                           PosY_2 = globalPosY;
                           PosZ_2 = globalPosZ;
                           PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                           
                           PEnergy = sourceEnergy;
                           runID = runID;
                           coincID = coincID;
                           eventID = eventID;
                           time = time;
                           Energy_2 = energy;
      
                           EnergyS = Energy_1 + Energy_2;
                           classID = coinc_count[ievt].second;
                           count4++;
                           cout << ".....................event class with 3 singles in second layer and 1 in abs...................." << endl;
                       
                       } else {
                       
                           cout <<"...unexpected..posx..in..four..singles...........9....................."<< "posX : "<< globalPosX <<endl;
                           cout <<".............................unacceptable event........................." << endl;
                           if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                              PosX_2 = globalPosX;
                              PosY_2 = globalPosY;
                              PosZ_2 = globalPosZ;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = energy;
                              EnergyS = Energy_1 + Energy_2; 
                           
                           }
                           classID = -12;
                           count42++;
                           
                           //continue; 
                       }
                       
                       tree->Fill(); 
       
                       ievt = ievt+3; 
                      
                       count++; 
                   
                   } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                       
                       PosX_021 = globalPosX;
                       PosY_021 = globalPosY;
                       PosZ_021 = globalPosZ;
                       
                       Energy_021 = energy;
                       
                       theTree->GetEntry(ievt+3);
                       if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                           PosX_2 = PosX_021;
                           PosY_2 = PosY_021;
                           PosZ_2 = PosZ_021;
                           PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                           
                           PEnergy = sourceEnergy;
                           runID = runID;
                           coincID = coincID;
                           eventID = eventID;
                           time = time;
                           Energy_2 = energy + Energy_021;
      
                           EnergyS = Energy_1 + Energy_2;
                           classID = coinc_count[ievt].second;
                           count4++;
                           cout << ".....................event class with 2 singles in second layer and 2 in abs...................." << endl;
                       
                       } else {
                           
                           cout <<"...unexpected..posx..in..four..singles...........10....................."<< "posX : "<< globalPosX <<endl;
                           cout <<".............................unacceptable event........................." << endl;
                           if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                              PosX_2 = PosX_021;
                              PosY_2 = PosY_021;
                              PosZ_2 = PosZ_021;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = Energy_021;
                              
                              EnergyS = Energy_1 + Energy_2 + energy; 
                           } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                              PosX_2 = PosX_021;
                              PosY_2 = PosY_021;
                              PosZ_2 = PosZ_021;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = Energy_021;
                              Energy_1 = Energy_1 + energy;
                              EnergyS = Energy_1 + Energy_2; 
                           }
                           classID = -13;
                           count42++;
                           
                           //continue; 
                       } 
                       
                       tree->Fill(); 
       
                       ievt = ievt+3; 
                       
                       count++; 
                   } else {
                       cout <<"...unexpected..posx..in..four..singles...........11....................."<< "posX : "<< globalPosX <<endl;
                       cout <<".............................unacceptable event........................." << endl;
                       if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                          PosX_3333 = globalPosX;
                          PosY_3333 = globalPosY;
                          PosZ_3333 = globalPosZ;
                          Energy_3333 = energy;
                          theTree->GetEntry(ievt+3);
                          if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                              PosX_2 = PosX_3333;
                              PosY_2 = PosY_3333;
                              PosZ_2 = PosZ_3333;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = Energy_3333 + energy;
                              
                              EnergyS = Energy_1 + Energy_2; 
                          } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                              PosX_2 = PosX_3333;
                              PosY_2 = PosY_3333;
                              PosZ_2 = PosZ_3333;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = Energy_3333;
                              Energy_1 = Energy_1 + energy;
                              EnergyS = Energy_1 + Energy_2; 
                              
                          } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                              PosX_2 = globalPosX;
                              PosY_2 = globalPosY;
                              PosZ_2 = globalPosZ;
                              PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                             
                              PEnergy = sourceEnergy;
                              runID = runID;
                              coincID = coincID;
                              eventID = eventID;
                              time = time;
                              Energy_2 = energy;
                              
                              EnergyS = Energy_1 + Energy_2 + Energy_3333; 
                          
                          } 
                          classID = -13;
                          count42++;
                          tree->Fill(); 
                          ievt = ievt+3;
                          count++; 
                       
                       //continue; 
                       }
                   }
                   
               } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                   
                   PosX_011 = globalPosX;
                   PosY_011 = globalPosY;
                   PosZ_011 = globalPosZ;
                   
                   Energy_011 = energy;
                   
                   theTree->GetEntry(ievt+2);
                   if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                   
                       PosX_012 = globalPosX;
                       PosY_012 = globalPosY;
                       PosZ_012 = globalPosZ;
                   
                       Energy_012 = energy;
                       
                       theTree->GetEntry(ievt+3);
                       if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) { 
                           PosX_2 = PosX_011;
                           PosY_2 = PosY_011;
                           PosZ_2 = PosZ_011;
                           PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                          
                           PEnergy = sourceEnergy;
                           runID = runID;
                           coincID = coincID;
                           eventID = eventID;
                           time = time;
                           Energy_2 = energy + Energy_011 + Energy_012;
      
                           EnergyS = Energy_1 + Energy_2;
                           classID = coinc_count[ievt].second; 
                           count4++;
                           cout << ".....................event class with 1 singles in second layer and 3 in abs...................." << endl;
                      } else {
                       
                       cout <<"...unexpected..posx..in..four..singles...........11....................."<< "posX : "<< globalPosX <<endl;
                       cout <<".............................unacceptable event........................." << endl;
                       if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                           PosX_2 = PosX_011;
                           PosY_2 = PosY_011;
                           PosZ_2 = PosZ_011;
                           PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                           
                           PEnergy = sourceEnergy;
                           runID = runID;
                           coincID = coincID;
                           eventID = eventID;
                           time = time;
                           Energy_2 = Energy_011 + Energy_012;
                           EnergyS = Energy_1 + Energy_2 + energy;
                       } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                           PosX_2 = PosX_011;
                           PosY_2 = PosY_011;
                           PosZ_2 = PosZ_011;
                           PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                          
                           PEnergy = sourceEnergy;
                           runID = runID;
                           coincID = coincID;
                           eventID = eventID;
                           time = time;
                           Energy_2 = Energy_011 + Energy_012;
                           Energy_1 = Energy_1 + energy;
                           EnergyS = Energy_1 + Energy_2;
                       }
                       classID = -14;
                       count42++;
                        
                       //continue;
                      }
                      
                      tree->Fill(); 
       
                      ievt = ievt+3; 
                      count++;
                      
                  } else {
                      cout <<"...unexpected..posx..in..four..singles...........12....................."<< "posX : "<< globalPosX <<endl;
                      cout <<".............................unacceptable event........................." << endl;
                      if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                           Energy_4444 = energy;
                           theTree->GetEntry(ievt+3);
                           if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                               
                               PosX_2 = PosX_011;
                               PosY_2 = PosY_011;
                               PosZ_2 = PosZ_011;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_011;
                               EnergyS = Energy_1 + Energy_2 + Energy_4444 + energy;
                               
                           } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                               PosX_2 = PosX_011;
                               PosY_2 = PosY_011;
                               PosZ_2 = PosZ_011;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_011;
                               Energy_1 = Energy_1 + energy;
                               EnergyS = Energy_1 + Energy_2 + Energy_4444;
                               
                           } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                               PosX_2 = PosX_011;
                               PosY_2 = PosY_011;
                               PosZ_2 = PosZ_011;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                               
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_011 + energy;
                               EnergyS = Energy_1 + Energy_2 + Energy_4444;
                           }
                           
                       } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                           Energy_4444 = energy;
                           theTree->GetEntry(ievt+3);
                           if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                               
                               PosX_2 = PosX_011;
                               PosY_2 = PosY_011;
                               PosZ_2 = PosZ_011;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_011;
                               Energy_1 = Energy_1 + energy;
                               EnergyS = Energy_1 + Energy_2 + Energy_4444;
                               
                           } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                               PosX_2 = PosX_011;
                               PosY_2 = PosY_011;
                               PosZ_2 = PosZ_011;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_011;
                               Energy_1 = Energy_1 + energy + Energy_4444;
                               EnergyS = Energy_1 + Energy_2;
                               
                           } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                               PosX_2 = PosX_011;
                               PosY_2 = PosY_011;
                               PosZ_2 = PosZ_011;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_011 + energy;
                               Energy_1 = Energy_1 + Energy_4444;
                               EnergyS = Energy_1 + Energy_2;
                           }
                       }
                       classID = -15;
                       count42++;
                       tree->Fill(); 
                       ievt = ievt+3;
                       count++; 
                        
                      
                      //continue;
                  }
                  
               } else {
                   cout <<"...unexpected..posx..in..four..singles...........13....................."<< "posX : "<< globalPosX <<endl;
                   cout <<".............................unacceptable event........................." << endl;
                   if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                       Energy_5555 = energy;
                       PosX_5555 = globalPosX;
                       PosY_5555 = globalPosX;
                       PosZ_5555 = globalPosX;
                       theTree->GetEntry(ievt+2);
                       if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {
                           Energy_6666 = energy; 
                           theTree->GetEntry(ievt+3);
                           if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {       
                               PosX_2 = PosX_5555;
                               PosY_2 = PosY_5555;
                               PosZ_2 = PosZ_5555;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_5555 + Energy_6666 + energy;
                               EnergyS = Energy_1 + Energy_2;
                               
                           } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                               PosX_2 = PosX_5555;
                               PosY_2 = PosY_5555;
                               PosZ_2 = PosZ_5555;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_5555 + Energy_6666;
                               EnergyS = Energy_1 + Energy_2 + energy;
                           
                           } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                               PosX_2 = PosX_5555;
                               PosY_2 = PosY_5555;
                               PosZ_2 = PosZ_5555;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_5555 + Energy_6666;
                               EnergyS = Energy_1 + Energy_2 + energy;
                           }
                       } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                           Energy_6666 = energy; 
                           theTree->GetEntry(ievt+3);
                           if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {       
                               PosX_2 = PosX_5555;
                               PosY_2 = PosY_5555;
                               PosZ_2 = PosZ_5555;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                               
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_5555 + energy;
                               Energy_1 = Energy_1 + Energy_6666;
                               EnergyS = Energy_1 + Energy_2;
                               
                           } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                               PosX_2 = PosX_5555;
                               PosY_2 = PosY_5555;
                               PosZ_2 = PosZ_5555;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_5555;
                               Energy_1 = Energy_1 + Energy_6666 + energy;
                               EnergyS = Energy_1 + Energy_2;
                           
                           } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                               PosX_2 = PosX_5555;
                               PosY_2 = PosY_5555;
                               PosZ_2 = PosZ_5555;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_5555;
                               Energy_1 = Energy_1 + Energy_6666;
                               EnergyS = Energy_1 + Energy_2 + energy;
                           }
                       } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                           Energy_6666 = energy; 
                           theTree->GetEntry(ievt+3);
                           if (globalPosX >= lowerlimit_Scat1 && globalPosX <= upperlimit_Scat1) {       
                               PosX_2 = PosX_5555;
                               PosY_2 = PosY_5555;
                               PosZ_2 = PosZ_5555;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                               
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_5555 + energy;
                               Energy_1 = Energy_1;
                               EnergyS = Energy_1 + Energy_2 + Energy_6666;
                               
                           } else if (globalPosX >= lowerlimit_Scat2 && globalPosX <= upperlimit_Scat2) {
                               PosX_2 = PosX_5555;
                               PosY_2 = PosY_5555;
                               PosZ_2 = PosZ_5555;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                              
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_5555;
                               Energy_1 = Energy_1 + energy;
                               EnergyS = Energy_1 + Energy_2 + Energy_6666;
                           
                           } else if (globalPosX >= lowerlimit_Abs && globalPosX <= upperlimit_Abs) {
                               PosX_2 = PosX_5555;
                               PosY_2 = PosY_5555;
                               PosZ_2 = PosZ_5555;
                               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
                               
                               PEnergy = sourceEnergy;
                               runID = runID;
                               coincID = coincID;
                               eventID = eventID;
                               time = time;
                               Energy_2 = Energy_5555;
                               EnergyS = Energy_1 + Energy_2 + energy + Energy_6666;
                           }
                       }
                   }
                   classID = -16;
                   count42++;
                   tree->Fill(); 
                   ievt = ievt+3;
                   count++; 
                           
                   //continue;
               }
               
  
           } else {
               
               PosX_2 = globalPosX;
               PosY_2 = globalPosY;
               PosZ_2 = globalPosZ;
               PosAbs->SetXYZ(PosX_2,PosY_2,PosZ_2);
               
               PEnergy = sourceEnergy;
               runID = runID;
               coincID = coincID;
               eventID = eventID;
               time = time;
               Energy_2 = energy;
              
               theTree->GetEntry(ievt+1);
              
               Energy_2 = Energy_2 + energy;
              
               theTree->GetEntry(ievt+2);
               
               Energy_1 = energy;
               
               theTree->GetEntry(ievt+3);
              
               PosX_1 = globalPosX;
               PosY_1 = globalPosY;
               PosZ_1 = globalPosZ;
               PosScat->SetXYZ(PosX_1,PosY_1,PosZ_1);
               Energy_1 = energy + Energy_1;
              
               PEnergy = sourceEnergy;
               runID = runID;
               coincID = coincID;
               eventID = eventID;
               time = time;
               EnergyS = Energy_1 + Energy_2;
               classID = -4; // Back-scattering Event with 4 interactions
               tree->Fill();
               ievt = ievt+3;
               cout << ".........................Back-scatteringEvent..................................." << endl;
               count4back++;
               count++; 
              
              //continue;
           
           }
           
       } else if (coinc_count[ievt].second == 5 && coinc_count[ievt].first == coinc_count[ievt+1].first && coinc_count[ievt].first == coinc_count[ievt+2].first && coinc_count[ievt].first == coinc_count[ievt+3].first&& coinc_count[ievt].first == coinc_count[ievt+4].first) { 
              
              ievt = ievt+4;
              count51++;
              count++;    
       } else if (coinc_count[ievt].second == 6 && coinc_count[ievt].first == coinc_count[ievt+1].first && coinc_count[ievt].first == coinc_count[ievt+2].first && coinc_count[ievt].first == coinc_count[ievt+3].first && coinc_count[ievt].first == coinc_count[ievt+4].first && coinc_count[ievt].first == coinc_count[ievt+5].first) { 
              
              ievt = ievt+5;
              count61++;
              count++;    
       }           

  }
   
  tree->Write();
      
  target->Close();
   
  std::cout << "==> Total event number passing the filteration: " << count << std::endl << std::endl;
  std::cout << "==> Total event number with 2 coincidences: " << count21 << " , Compton Events : " << count2 << " , Back-scattering Events : " << count2back << " , Background Events : " << count22 << std::endl << std::endl;
  std::cout << "==> Total event number with 3 coincidences: " << count31 << " , Compton Events : " << count3 << " , Back-scattering Events : " << count3back  << " , Background Events : " << count32 << std::endl << std::endl;
  std::cout << "==> Total event number with 3 coincidences(IdealTriple): " << counttriple << std::endl << std::endl;
  std::cout << "==> Total event number with 4 coincidences: " << count41 << " , Compton Events : " << count4 << " , Back-scattering Events : " << count4back  << " , Background Events : " << count42 << std::endl << std::endl;
  std::cout << "==> Total event number with 5 coincidences: " << count51 << " , " << count5 << std::endl << std::endl;
  std::cout << "==> Total event number with 6 coincidences: " << count61 << " , " << count6 << std::endl << std::endl;
  std::cout << "==> conversion is done!" << std::endl << std::endl;
   
}

////////////////////////////////////////////////
/////////////////////////////////////////

void ProposedRecoInput(){
// ----------------------------------------------------------------------------------------
// Run all
// ----------------------------------------------------------------------------------------
   
   
   cout << "========================" << endl;
   cout << "--- Conversion of Final Tree" << endl;
   Convert();
   cout << "========================" << endl;

  
}

int main( int argc, char** argv ) {
   ProposedRecoInput();
} 
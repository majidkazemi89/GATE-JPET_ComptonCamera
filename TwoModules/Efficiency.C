#include <bits/stdc++.h>
#include <TMap.h>
using namespace std;
// ----------------------------------------------------------------------------------------------
// Count function get the number of Compton events in two modules
// ----------------------------------------------------------------------------------------------
void Count() {
    
   
   TFile *input = TFile::Open("./output/ps_actor_out_2modules.root");
   
   
   Float_t dX, dY, dZ, X, Y, Z; 
   Float_t EmissionPointX, EmissionPointY, EmissionPointZ; 
   Int_t TrackID, ParentID, EventID, RunID;
   
   Char_t CreatorProcess;
   
   std::vector<int> E1;
   std::vector<int> E2;
   vector<int> finalList;
   
   std::vector< std::pair<Int_t, Char_t>> vec1;
   std::vector< std::pair<Int_t, Char_t>> vec2;
   std::vector< std::pair<Char_t, Char_t>> finalList3;
   
   std::map<std::pair<Int_t, Int_t>, Char_t> checker1;
   std::map<std::pair<Int_t, Int_t>, Char_t> checker2;
   //std::vector<std::pair<std::map, std::map>> checker3;
   
   int count_1 = 0, count_2 = 0, count_3 = 0;
    
   TTree* theTree = (TTree*)input->Get("PhaseSpace");
   std::cout << "--- Processing: " << theTree->GetEntries() << " entries" << std::endl;
  
   
   theTree->SetBranchAddress("X", &X);
   theTree->SetBranchAddress("Y", &Y);
   theTree->SetBranchAddress("Z", &Z);
   theTree->SetBranchAddress("dX", &dX);
   theTree->SetBranchAddress( "dY", &dY );
   theTree->SetBranchAddress("dZ", &dZ);
   theTree->SetBranchAddress( "CreatorProcess", &CreatorProcess );
   theTree->SetBranchAddress("TrackID", &TrackID);
   theTree->SetBranchAddress( "ParentID", &ParentID );
   theTree->SetBranchAddress("EventID", &EventID);
   theTree->SetBranchAddress( "RunID", &RunID );
   theTree->SetBranchAddress("EmissionPointX", &EmissionPointX );
   theTree->SetBranchAddress( "EmissionPointY", &EmissionPointY );
   theTree->SetBranchAddress("EmissionPointZ", &EmissionPointZ);
   
   
  ///////////////////////////////////////////////////////////////////////
  
   for (Int_t i=0; i < theTree->GetEntries();i++) {

       theTree->GetEntry(i);
       
       if (EmissionPointX >= 300.25 && EmissionPointX <= 324.25 /*&& ParentID == 1*/){
         
           E1.push_back(EventID);
           vec1.push_back({ EventID, CreatorProcess});
           
           //checker1.insert(vec1,CreatorProcess);
           
           count_1++;
       
       }
       
       if (EmissionPointX >= 368.25 && EmissionPointX <= 392.25){
       
           E2.push_back(EventID);
           vec2.push_back({ EventID, CreatorProcess});
           
           //checker2.insert(vec1,CreatorProcess);
           
           count_2++;
       }
   }
   
   cout << "Compton events in module_1 : " << count_1 << endl;
   cout << "Compton events in module_2 : " << count_2 << endl;
   
   for(Int_t i=0; i<vec1.size(); ++i){
   
       for(Int_t j=0; j<vec2.size(); ++j){
       
           if(vec1[i].first == vec2[j].first){
           
              finalList3.push_back({vec1[i].second, vec2[j].second});
              //checker3.push_back(checker1[i],checker2[j]);
              count_3++;
           }
       }
   }
   for (const auto &elem: finalList3) std::cout << "{" << elem.first <<
                                                 "," << elem.second <<
                                                 "}: " << std::endl; //<< elem.second << std::endl; 
   cout << "Total number of the same events : " << count_3 << endl;  
                                              
 /*  for (const auto &elem: checker3) std::cout << "{" << elem.first.first.first <<
                                                 "," << elem.first.first.second <<
                                                 "," << elem.first.second <<
                                                 "," << elem.second.first.first <<
                                                 "," << elem.second.first.second <<
                                                 "," << elem.second.second <<
                                                 "}: " << std::endl; //<< elem.second << std::endl; 
  */
  /* 
   vector<int> secondListCopy = E2;

   for (std::vector<int>::iterator i = E1.begin(); i != E1.end(); ++i){
       std::vector<int>::iterator i2 = std::find(secondListCopy.begin(), secondListCopy.end(), *i) ;
       if (i2 != secondListCopy.end()){
          finalList.push_back(*i);
          secondListCopy.erase(i2);

        if(secondListCopy.empty()) break; //just additional optimization.
       }
   }
   
   for(auto& i : finalList)
      cout << i << " "<< endl;
  */     
  /*
   set<int> firstSet{E1.begin(),E1.end()};
   for(auto& i : E2)
      if(*firstSet.find(i)){
      //find i in firstSet/firstList
        finalList.push_back(i);
        //cout << E1.at(i) << " , " << E2.at(i) << endl;
      }
   
   // Sort the vector
  /*  sort(E1.begin(), E1.end());
    sort(E2.begin(), E2.end());
  
    // Print the vector
    cout << "First Vector: ";
    for (int i = 0; i < E1.size(); i++)
        cout << E1[i] << " ";
    cout << endl;
  
    cout << "Second Vector: ";
    for (int i = 0; i < E2.size(); i++)
        cout << E2[i] << " ";
    cout << endl;
  
    // Initialise a vector
    // to store the common values
    // and an iterator
    // to traverse this vector
    vector<int> v(E1.size() + E2.size());
    vector<int>::iterator it, st;
  
    it = set_intersection(E1.begin(),
                          E1.end(),
                          E2.begin(),
                          E2.end(),
                          v.begin());
    cout << "\nCommon elements:\n";
    for (st = v.begin(); st != it; ++st)
        cout << *st << ", ";
    cout << '\n';
    */
  /*  
   int n = 0;
   for ( std::vector<int>::iterator it = finalList.begin(); it < finalList.end(); it++ ){
        
       std::cout << "  List[" << n << "] = " << (*it) << ";"<< std::endl;
       
       n++; 
   }
  /* 
   for (std::vector<int>::const_iterator k = finalList.begin(); k != finalList.end(); ++k){
   
       std::cout << *k << ' ';
   }
   */
  /*  
   for (auto i = finalList.begin(); i != finalList.end(); ++i){
   
       std::cout << *i << ' '; 
   }
   */
   /*for(auto& i : finalList)
      cout << i << " "; 
   */   
}
   
////////////////////////////////////////////////
/////////////////////////////////////////

void Efficiency(){
// ----------------------------------------------------------------------------------------
// Run all
// ----------------------------------------------------------------------------------------
   
   
   cout << "========================" << endl;
   cout << "--- Conversion of Final Tree" << endl;
   Count();
   cout << "========================" << endl;

  
}

int main( int argc, char** argv ) {
   Efficiency();
} 
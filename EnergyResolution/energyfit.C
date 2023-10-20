#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TCanvas.h"
#include "TF1.h"
#include "TH1.h"
#include "TFile.h"

void energyfit()
{
   TCanvas *c1 = new TCanvas("Energy Resolution","Energy Resolution",0,0,1000,1000);
   
   TPad *pad = new TPad("pad","",0,0,1,1);
   pad->SetFillColor(0);
   pad->SetGrid();
   pad->Draw();
   pad->cd();
   
   //TMultiGraph *mg = new TMultiGraph();
   //mg->SetTitle("Energy Resolution");
   //TString name = "EnergyResolutionExample.root";
   TString name1 = "Fiber_1_0.root";
   //TString name2 = "Fiber_1_1.root";
   //TFile* file = new TFile(name, "READ");
   TFile* file1 = new TFile(name1, "READ");
   //TFile* file2 = new TFile(name2, "READ");
   
   //TH1D* fHisto = (TH1D*)file->Get("Scintillator_0ResolutionCombiEnergy");
   TH1D* fHisto1 = (TH1D*)file1->Get("FiberEnergyUnc_Type3");
   //TH1D* fHisto2 = (TH1D*)file2->Get("FiberEnergyUnc_Type5");
   
   
   TH1F *hr = pad->DrawFrame(0,0,0.92,4.5);
   //hr->SetTitle("#sigma_{Z} for different IDD and DSS values");
   hr->SetXTitle("Deposited energy (MeV)");
   hr->SetYTitle("#sigma_{E}/E_{reconstructed}");
   
   //TF1* func = new TF1("fit", "[0]+[1]/sqrt(x)+[2]/x^(3/2)", 0, 4.5);
   //func->SetLineColor(2);
   TF1* func1 = new TF1("fit1", "[0]+[1]/sqrt(x)+[2]/x^(3/2)", 0.1, 4.5);
   func1->SetLineColor(3);
   //TF1* func2 = new TF1("fit2", "[0]+[1]/sqrt(x)+[2]/x^(3/2)", 0.1, 4.5);
   //func2->SetLineColor(4);
   //fHisto->SetFillColor(2);
   //fHisto->Draw("");
   fHisto1->SetFillColor(3);
   fHisto1->Draw(" ");
   //fHisto2->SetFillColor(4);
   //fHisto2->Draw("same");

   //fHisto->Fit("fit","r");
   fHisto1->Fit("fit1","r");
   //fHisto2->Fit("fit2","r");
   
    //TLegend *legend = new TLegend(.75,.80,.95,.95);
    //legend->AddEntry(fHisto,"original");
    //legend->AddEntry(fHisto1,"Type3(fiber1_0)");
    //legend->AddEntry(fHisto2,"Type5(fiber1_1)");
    //legend->Draw();
//    std::cout << "par0 " << func->GetParameter(0) << std::endl;
//    std::cout << "par1 " << func->GetParameter(1) << std::endl;
//    std::cout << "par2 " << func->GetParameter(2) << std::endl;
   //mg->Draw("");
   c1->Update();
}


 

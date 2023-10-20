#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TCanvas.h"
#include "TF1.h"
#include "TH1.h"
#include "TGraphErrors.h"
#include <TLegend.h>
void EnResoFit()
{
TCanvas *c1 = new TCanvas("EnergyResolution_Strip","EnergyResolution_Strip",700,700);
//c1->Divide(1, 1);
//c1->cd(1);
TPad *pad = new TPad("pad","",0,0,1,1);
pad->SetFillColor(0);
pad->SetGrid();
pad->Draw();
pad->cd();

auto l = new TLegend(.2, .2, .2, .2);


  // draw a frame to define the range
TH1F *hr = pad->DrawFrame(0,0,6.5,50);
//hr->SetTitle("#sigma_{Z} for different IDD and DSS values");
hr->SetXTitle("E_{e} (MeV)");
hr->GetXaxis()->SetLabelSize(0.0385);
hr->GetXaxis()->SetTitleSize(0.0385);
hr->GetXaxis()->SetTitleOffset(1.3);
hr->SetYTitle("#sigma_{E}/E (%)");
hr->GetYaxis()->SetLabelSize(0.0385);
hr->GetYaxis()->SetTitleSize(0.0385);
hr->GetYaxis()->SetTitleOffset(1.33);
//hr->SetTextSize(20);
pad->GetFrame()->SetFillColor(0);
pad->GetFrame()->SetBorderSize(26);

  // create first graph
Int_t n1 = 8;
//Double_t x1[] = {0.341,1.409,2.08,4.2};
Double_t x1[] = {0.341,0.541,1.409,1.774,2.08,4.2,5.01,5.88};
//Double_t y1[] = {35.8,15.8,13.8,11.3};
Double_t y1[] = {21.4,14.8,9.4,8.8,7.3,5.4,5.1,4.7};
Double_t ex1[] = {0,0,0,0,0,0,0,0};
//Double_t ex1[] = {0,0,0,0};
Double_t ey1[] = {0.7,0.6,0.6,1,1,1.2,1.2,1.2};
//Double_t ey1[] = {.2,1,2,6};

TGraphErrors *gr1 = new TGraphErrors(n1,x1,y1,ex1,ey1);
gr1->SetName("EnergyResolution");
gr1->SetLineColor(kBlack);
gr1->SetLineWidth(1);
//gr1->SetMarkerStyle(4);
gr1->SetMarkerStyle(8);
gr1->SetMarkerSize(1);
gr1->SetMarkerColor(kBlack);

//gr1->SetMarkerStyle(20);
gr1->Draw("P");

//TF1* func1 = new TF1("fit1", "[0]+[1]/sqrt(x)+[2]/x^(3/2)", 0., 15);
//func1->SetLineColor(3);

TF1* func1 = new TF1("fit1", "[0]/sqrt(x)", 0., 6.5);
func1->SetLineColor(3);

gr1->Fit("fit1","r");

l->AddEntry("EnergyResolution","Fitting Parameters","");
l->AddEntry("EnergyResolution",Form("P_{0} : %.3f #pm %.3f", func1->GetParameter(0),func1->GetParError(0)),"");
//l->AddEntry("EnergyResolution",Form("P_{1} : %.3f #pm %.3f", func1->GetParameter(1),func1->GetParError(1)),"");
//l->AddEntry("EnergyResolution",Form("P_{2} : %.3f #pm %.3f", func1->GetParameter(2),func1->GetParError(2)),"");

l->SetTextSize(0.0365);
l-> Draw(); 
  
TFile* file = new TFile("EnergyResolution_Strip_inverseSquare_6.5MeV.root", "RECREATE");

TH1D *h = new TH1D("EnergyResolution_Strip","EnergyResolution_Strip",6500,0,6.5);

auto nPoints = gr1->GetN(); // number of points in your TGraph

for(int i=0; i < nPoints; ++i) {
   
   gr1->GetPoint(i, x1[i], y1[i]);
   h->Fill(x1[i],y1[i]); 
}
h->Write();

//TF1* func = new TF1("fit", "[0]+[1]/sqrt(x)+[2]/x^(3/2)", 0., 6.5);

//h->Fit("fit","r");


file->Close();  

}
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TCanvas.h"
#include "TF1.h"
#include "TH1.h"
#include "TGraphErrors.h"
#include <TLegend.h>
void DetEff()
{
TCanvas *c1 = new TCanvas("c1","gerrors2",600,600);
c1->Divide(1, 1);
c1->cd(1);
TPad *pad = new TPad("pad","",0,0,1,1);
pad->SetFillColor(0);
pad->SetGrid();
pad->Draw();
pad->cd();

auto l = new TLegend(.2, .2, .2, .2);
auto l1 = new TLegend(.2, .2, .2, .2);

  // draw a frame to define the range
TH1F *hr = pad->DrawFrame(0.1,1,6.5,10);
hr->SetTitle("Detection Efficiency for different width values");
hr->SetXTitle("E_{photon} (MeV)");
hr->GetXaxis()->SetLabelSize(0.0385);
hr->GetXaxis()->SetTitleSize(0.0385);
hr->GetXaxis()->SetTitleOffset(1.3);
hr->SetYTitle("Detection Efficiency(#times 10^{-3})");
hr->GetYaxis()->SetLabelSize(0.0385);
hr->GetYaxis()->SetTitleSize(0.0385);
hr->GetYaxis()->SetTitleOffset(1.33);
//hr->SetTextSize(20);
pad->GetFrame()->SetFillColor(0);
pad->GetFrame()->SetBorderSize(26);

  // create first graph
//Int_t n1 = 31;
// 6*24 strip
/*Double_t x1[] = {0.3,0.5,0.7,0.9,1.1,1.3,1.5,1.7,1.9,2.1,2.3,2.5,2.7,2.9,3.1,3.3,3.5,3.7,3.9,4.1,4.3,4.5,4.7,4.9,5.1,5.3,5.5,5.7,5.9,6.1,6.3};
Double_t y1[] = {6.31,5.04,4.38,3.92,3.67,3.10,3.06,2.71,2.57,2.55,2.28,2.06,2.05,2.07,2.04,1.94,1.93,1.99,1.95,1.73,1.65,1.31,1.35,1.29,1.22,1.15,1.14,1.12,1.11,1.13,1.13};
Double_t ex1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t ey1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
*/
Int_t n1 = 5;
Double_t x1[] = {0.5,1.5,2.5,3.5,4.5};
//Double_t y1[] = {5.79,3.42,2.51,2.18,1.81};
Double_t y1[] = {5.79,3.42,2.51,2.18,1.81};
Double_t ex1[] = {0,0,0,0,0};
Double_t ey1[] = {0,0,0,0,0};

TGraphErrors *gr1 = new TGraphErrors(n1,x1,y1,ex1,ey1);
gr1->SetName("gr1");
gr1->SetLineColor(kBlack);
gr1->SetLineWidth(1);
//gr1->SetMarkerStyle(4);
gr1->SetMarkerStyle(8);
gr1->SetMarkerSize(1);
gr1->SetMarkerColor(kBlack);

//gr1->SetMarkerStyle(20);
gr1->Draw("P");

/*TF1* func1 = new TF1("fit1", "[0]+[1]/sqrt(x)+[2]/x^(3/2)", 0.1, 5.0);
func1->SetLineColor(3);

gr1->Fit("fit1","r");

l->AddEntry("gr1","Fitting Parameters","");
l->AddEntry("gr1",Form("P_{0} : %.3f", func1->GetParameter(0)),"");
l->AddEntry("gr1",Form("P_{1} : %.3f", func1->GetParameter(1)),"");
l->AddEntry("gr1",Form("P_{2} : %.3f", func1->GetParameter(2)),"");

l->SetTextSize(0.0365);

l-> Draw();
*/  
l->AddEntry("gr1","X_thickness: 120 mm","p");
//l->AddEntry("gr1","X_thickness: 24 mm","");
l->AddEntry("gr1","Z_width: 60 mm","");

l->SetTextSize(0.0365);

 
// create second graph
Int_t n2 = 5;
Float_t x2[] = {0.5,1.5,2.5,3.5,4.5};
Float_t y2[] = {8.88,5.17,4.07,3.35,2.77};
Float_t ex2[] = {0,0,0,0,0};
Float_t ey2[] = {0,0,0,0,0};

TPad *overlay = new TPad("overlay","",0,0,1,1);
overlay->SetFillStyle(4000);
overlay->SetFillColor(0);
overlay->SetFrameFillStyle(4000);
overlay->Draw();
overlay->cd();
TGraphErrors *gr2 = new TGraphErrors(n2,x2,y2,ex2,ey2);

gr2->SetLineColor(kRed);
gr2->SetLineWidth(1);
//gr2->SetMarkerStyle(4);
gr2->SetMarkerStyle(8);
gr2->SetMarkerSize(1);
gr2->SetName("gr2");
gr2->SetMarkerColor(kRed);

Double_t xmin = pad->GetUxmin();
Double_t ymin = 1;
Double_t xmax = pad->GetUxmax();
Double_t ymax = 10;
TH1F *hframe = overlay->DrawFrame(xmin,ymin,xmax,ymax);
hframe->GetXaxis()->SetLabelOffset(99);
hframe->GetYaxis()->SetLabelOffset(99);
gr2->Draw("P");  

l1->AddEntry("gr2","X_thickness: 120 mm","p");
//l1->AddEntry("gr2","X_thickness: 24 mm","");
l1->AddEntry("gr2","Z_width: 90 mm","");

l1->SetTextSize(0.0365);
l1-> Draw();
l-> Draw();

}
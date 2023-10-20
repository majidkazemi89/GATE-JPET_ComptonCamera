#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TCanvas.h"
#include "TF1.h"
#include "TH1.h"
#include "TGraphErrors.h"
#include <TLegend.h>
void NumLayEfficiencyArt()
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
TH1F *hr = pad->DrawFrame(1,2,6,9);
//hr->SetTitle("Detection Efficiency for different no. layers in the scatterer");
hr->SetXTitle("n in the Scatterer (mm)");
hr->GetXaxis()->SetLabelSize(0.0385);
hr->GetXaxis()->SetTitleSize(0.0385);
hr->GetXaxis()->SetTitleOffset(1.3);
hr->SetYTitle("Efficiency (#times 10^{-4})");
hr->GetYaxis()->SetLabelSize(0.0385);
hr->GetYaxis()->SetTitleSize(0.0385);
hr->GetYaxis()->SetTitleOffset(1.33);
//hr->SetTextSize(20);
pad->GetFrame()->SetFillColor(0);
pad->GetFrame()->SetBorderSize(26);

Int_t n1 = 4;
Double_t x1[] = {2,3,4,5};
Double_t y1[] = {4.23,5.47,6.86,8.38};
Double_t ex1[] = {0,0,0,0,0};
Double_t ey1[] = {0,0,0,0,0};

TGraphErrors *gr1 = new TGraphErrors(n1,x1,y1,ex1,ey1);
gr1->SetName("gr1");
gr1->SetLineColor(kRed);
gr1->SetLineWidth(1);
//gr1->SetMarkerStyle(4);
gr1->SetMarkerStyle(8);
gr1->SetMarkerSize(1);
gr1->SetMarkerColor(kRed);

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
l->AddEntry("gr1","Detection Efficiency D_{E}","p");
//l->AddEntry("gr1","X_thickness: 24 mm","");
//1->AddEntry("gr1","Z_width: 60 mm","");

l->SetTextSize(0.0365);

 
// create second graph
Int_t n2 = 4;
Float_t x2[] = {2,3,4,5};
Float_t y2[] = {3.12,4.07,5.31,6.55};
Float_t ex2[] = {0,0,0,0,0};
Float_t ey2[] = {0,0,0,0,0};

TPad *overlay = new TPad("overlay","",0,0,1,1);
overlay->SetFillStyle(4000);
overlay->SetFillColor(0);
overlay->SetFrameFillStyle(4000);
overlay->Draw();
overlay->cd();
TGraphErrors *gr2 = new TGraphErrors(n2,x2,y2,ex2,ey2);

gr2->SetLineColor(kBlue);
gr2->SetLineWidth(1);
//gr2->SetMarkerStyle(4);
gr2->SetMarkerStyle(8);
gr2->SetMarkerSize(1);
gr2->SetName("gr2");
gr2->SetMarkerColor(kBlue);

Double_t xmin = pad->GetUxmin();
Double_t ymin = 2;
Double_t xmax = pad->GetUxmax();
Double_t ymax = 9;
TH1F *hframe = overlay->DrawFrame(xmin,ymin,xmax,ymax);
hframe->GetXaxis()->SetLabelOffset(99);
hframe->GetYaxis()->SetLabelOffset(99);
gr2->Draw("P");  

l->AddEntry("gr2","True Efficiency T_{E}","p");
//l1->AddEntry("gr2","X_thickness: 120 mm","p");
//l1->AddEntry("gr2","X_thickness: 24 mm","");
//l1->AddEntry("gr2","Z_width: 90 mm","");

//l1->SetTextSize(0.0365);
//l1-> Draw();
l-> Draw();

}
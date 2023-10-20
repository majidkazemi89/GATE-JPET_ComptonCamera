

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TCanvas.h"
#include "TF1.h"
#include "TH1.h"
#include "TGraphErrors.h"
#include <TLegend.h>
void graph()
{
TCanvas *c1 = new TCanvas("c1","gerrors2",2000,2000);
c1->Divide(2, 1);
c1->cd(1);
TPad *pad = new TPad("pad","",0,0,1,1);
pad->SetFillColor(0);
pad->SetGrid();
pad->Draw();
pad->cd();

auto l = new TLegend(.2, .2, .2, .2);
auto l1 = new TLegend(.2, .2, .2, .2);


  // draw a frame to define the range
TH1F *hr = pad->DrawFrame(90,1,280,3);
//hr->SetTitle("#sigma_{Z} for different IDD and DSS values");
hr->SetXTitle("Distance [mm]");
hr->GetXaxis()->SetLabelSize(0.0385);
hr->GetXaxis()->SetTitleSize(0.0385);
hr->GetXaxis()->SetTitleOffset(1.3);
hr->SetYTitle("#sigma_{X} [mm]");
hr->GetYaxis()->SetLabelSize(0.0385);
hr->GetYaxis()->SetTitleSize(0.0385);
hr->GetYaxis()->SetTitleOffset(1.33);
//hr->SetTextSize(20);
pad->GetFrame()->SetFillColor(0);
pad->GetFrame()->SetBorderSize(26);

  // create first graph
Int_t n1 = 9;
Double_t x1[] = {100,120,140,160,180,200,220,240,260};
Double_t y1[] = {1.08,1.19,1.36,1.57,1.78,1.89,2.01,2.18,2.31};
Double_t ex1[] = {0,0,0,0,0,0,0,0,0};
Double_t ey1[] = {.01,.01,.01,.01,.01,.01,.01,.01,.01};
TGraphErrors *gr1 = new TGraphErrors(n1,x1,y1,ex1,ey1);
gr1->SetName("gr1");
gr1->SetLineColor(kBlack);
gr1->SetLineWidth(1);
gr1->SetMarkerStyle(4);
gr1->SetMarkerSize(2);
gr1->SetMarkerColor(kBlack);

//gr1->SetMarkerStyle(20);
gr1->Draw("P");

l->AddEntry("gr1","DSS","ep");
l->AddEntry("gr1","IDD: 200 mm","");
l->AddEntry("gr1","Scatterer: 80 #times 80 mm^{2}","");
l->AddEntry("gr1","Absorber: 300 #times 300 mm^{2}","");

l->SetTextSize(0.0365);
//l-> Draw();
//TLegendEntry *le1 = l->AddEntry("gr2","DSA = 200mm","ep");
//le1->SetTextColor(kBlue);;
//auto gr = new TGraphErrors(n,x,y,ex,ey);
//   gr->SetName("gr");
//   gr->SetLineColor(kRed);
//   gr->SetLineWidth(2);
//   gr->SetMarkerStyle(21);
//   gr->SetMarkerSize(1.3);
//   gr->SetMarkerColor(7);
//   gr->Draw("P");
/*
TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   //ptstats->SetFillStyle(0);
   //Scintillator_0ResolutionCombiEnergy__1->SetStats(0);
   //ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("");
   //ptstats_LaTex->SetTextSize(0.01);
   ptstats_LaTex = ptstats->AddText("P_{0}" "=" "-0.0026(3)" );
   ptstats_LaTex = ptstats->AddText("P_{1}" "=" "0.0276(6)");
   ptstats_LaTex = ptstats->AddText("P_{2}" "=" "0.0176(3)");
   ptstats->SetOptStat(1001);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   hr->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(hr);
   hr->SetFillColor(38);
*/

  // create second graph
Int_t n2 = 9;
Float_t x2[] = {100,120,140,160,180,200,220,240,260};
Float_t y2[] = {2.21,2.14,2.09,2.00,1.94,1.89,1.90,1.88,1.89};
Float_t ex2[] = {0,0,0,0,0,0,0,0,0};
Float_t ey2[] = {.01,.01,.01,.01,.01,.01,.01,.01,.01};
/*for (Int_t i=0;i<n2;i++) {
y2[i] *= 100;
ey2[i] *= 100;
}*/
//create a transparent pad drawn on top of the main pad
//c1->cd();
TPad *overlay = new TPad("overlay","",0,0,1,1);
overlay->SetFillStyle(4000);
overlay->SetFillColor(0);
overlay->SetFrameFillStyle(4000);
overlay->Draw();
overlay->cd();
TGraphErrors *gr2 = new TGraphErrors(n2,x2,y2,ex2,ey2);
gr2->SetMarkerColor(kRed);
gr2->SetLineColor(kRed);
gr2->SetLineWidth(1);
gr2->SetMarkerStyle(4);
gr2->SetMarkerSize(2);
gr2->SetName("gr2");
Double_t xmin = pad->GetUxmin();
Double_t ymin = 1;
Double_t xmax = pad->GetUxmax();
Double_t ymax = 3;
TH1F *hframe = overlay->DrawFrame(xmin,ymin,xmax,ymax);
hframe->GetXaxis()->SetLabelOffset(99);
hframe->GetYaxis()->SetLabelOffset(99);
gr2->Draw("P");
//l->AddEntry("gr2","IDD","ep");
//TLegendEntry *le = l->AddEntry("gr1","DSS = 200mm","ep");
//le->SetTextColor(kRed);;
l1->AddEntry("gr2","IDD","ep");
l1->AddEntry("gr2","DSS: 200 mm","");
l1->AddEntry("gr2","Scatterer: 80 #times 80 mm^{2}","");
l1->AddEntry("gr2","Absorber: 300 #times 300 mm^{2}","");

l1->SetTextSize(0.0365);
l1-> Draw();

//l->AddEntry("gr","200mm","l");
//l->AddEntry("gr1","230mm","l");
//TLegendEntry *le = l->AddEntry("gr1","DSS","ep");
//le->SetTextColor(kBlue);;

//le->SetLineColor(kBlue);;
//TLegendEntry *le1 = l->AddEntry("gr2","DSA","ep");
//le1->SetTextColor(kRed);;
l-> Draw();

//Draw an axis on the right side
/*TGaxis *axis = new TGaxis(xmax,ymin,xmax, ymax,ymin,ymax,510,"+L");
axis->SetLineColor(kRed);
axis->SetLabelColor(kRed);
axis->Draw();
*/

c1->cd(2);

TPad *pad1 = new TPad("pad","",0,0,1,1);
pad1->SetFillColor(0);
pad1->SetGrid();
pad1->Draw();
pad1->cd();

auto l2 = new TLegend(.2, .2, .2, .2);
auto l3 = new TLegend(.2, .2, .2, .2);



  // draw a frame to define the range
TH1F *hr1 = pad1->DrawFrame(20,1,320,3);
//hr1->SetTitle("#sigma_{Z} for different scatterer and absorber widths");
hr1->SetXTitle("Width [mm]");
hr1->GetXaxis()->SetLabelSize(0.0385);
hr1->GetXaxis()->SetTitleSize(0.0385);
hr1->GetXaxis()->SetTitleOffset(1.3);
hr1->SetYTitle("#sigma_{X} [mm]");
hr1->GetYaxis()->SetLabelSize(0.0385);
hr1->GetYaxis()->SetTitleSize(0.0385);
hr1->GetYaxis()->SetTitleOffset(1.33);
//hr->SetTextSize(20);
pad1->GetFrame()->SetFillColor(0);
pad1->GetFrame()->SetBorderSize(26);

  // create first graph
Int_t n3 = 7;
Double_t x3[] = {40,80,100,120,150,200,300};
Double_t y3[] = {1.86,1.89,1.93,1.95,1.98,2.04,2.10};
Double_t ex3[] = {0,0,0,0,0,0,0,0,0};
Double_t ey3[] = {.01,.01,.01,.01,.01,.01,.01};
TGraphErrors *gr3 = new TGraphErrors(n3,x3,y3,ex3,ey3);
gr3->SetName("gr3");
gr3->SetLineColor(kBlack);
gr3->SetLineWidth(1);
gr3->SetMarkerStyle(4);
gr3->SetMarkerSize(2);
gr3->SetMarkerColor(kBlack);

//gr1->SetMarkerStyle(20);
gr3->Draw("P");
l2->AddEntry("gr3","Scatterer Width","ep");
l2->AddEntry("gr3","DSS: 200 mm","");
l2->AddEntry("gr3","IDD: 200 mm","");
l2->AddEntry("gr3","Absorber: 300 #times 300 mm^{2}","");

l2->SetTextSize(0.0365);
//TLegendEntry *le1 = l->AddEntry("gr2","DSA = 200mm","ep");
//le1->SetTextColor(kBlue);;
//auto gr = new TGraphErrors(n,x,y,ex,ey);
//   gr->SetName("gr");
//   gr->SetLineColor(kRed);
//   gr->SetLineWidth(2);
//   gr->SetMarkerStyle(21);
//   gr->SetMarkerSize(1.3);
//   gr->SetMarkerColor(7);
//   gr->Draw("P");


  // create second graph
Int_t n4 = 7;
Float_t x4[] = {40,80,100,120,150,200,300};
Float_t y4[] = {1.91,1.86,1.83,1.86,1.91,1.92,1.95};
Float_t ex4[] = {0,0,0,0,0,0,0,0,0};
Float_t ey4[] = {.01,.01,.01,.01,.01,.01,.01};
/*for (Int_t i=0;i<n2;i++) {
y2[i] *= 100;
ey2[i] *= 100;
}*/
//create a transparent pad drawn on top of the main pad
//c1->cd();
TPad *overlay1 = new TPad("overlay1","",0,0,1,1);
overlay1->SetFillStyle(4000);
overlay1->SetFillColor(0);
overlay1->SetFrameFillStyle(4000);
overlay1->Draw();
overlay1->cd();
TGraphErrors *gr4 = new TGraphErrors(n4,x4,y4,ex4,ey4);
gr4->SetMarkerColor(kRed);
gr4->SetLineColor(kRed);
gr4->SetLineWidth(1);
gr4->SetMarkerStyle(4);
gr4->SetMarkerSize(2);
gr4->SetName("gr4");
Double_t xmin1 = pad1->GetUxmin();
Double_t ymin1 = 1;
Double_t xmax1 = pad1->GetUxmax();
Double_t ymax1 = 3;
TH1F *hframe1 = overlay1->DrawFrame(xmin1,ymin1,xmax1,ymax1);
hframe1->GetXaxis()->SetLabelOffset(99);
hframe1->GetYaxis()->SetLabelOffset(99);
gr4->Draw("P");
l3->AddEntry("gr4","Absorber Width","ep");
l3->AddEntry("gr4","DSS: 200 mm","");
l3->AddEntry("gr4","IDD: 200 mm","");
l3->AddEntry("gr4","Scatterer: 100 #times 100 mm^{2}","");
//TLegendEntry *le = l->AddEntry("gr1","DSS = 200mm","ep");
//le->SetTextColor(kRed);;
l3->SetTextSize(0.0365);
l3-> Draw();

//l->AddEntry("gr","200mm","l");
//l->AddEntry("gr1","230mm","l");
//TLegendEntry *le = l->AddEntry("gr1","DSS","ep");
//le->SetTextColor(kBlue);;

//le->SetLineColor(kBlue);;
//TLegendEntry *le1 = l->AddEntry("gr2","DSA","ep");
//le1->SetTextColor(kRed);;
l2-> Draw();

//Draw an axis on the right side
/*TGaxis *axis = new TGaxis(xmax,ymin,xmax, ymax,ymin,ymax,510,"+L");
axis->SetLineColor(kRed);
axis->SetLabelColor(kRed);
axis->Draw();
*/








return c1;
}

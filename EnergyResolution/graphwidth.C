

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TCanvas.h"
#include "TF1.h"
#include "TH1.h"
#include "TGraphErrors.h"
#include <TLegend.h>
void graphwidth()
{
TCanvas *c1 = new TCanvas("c1","gerrors2",200,10,800,800);
TPad *pad = new TPad("pad","",0,0,1,1);
pad->SetFillColor(0);
pad->SetGrid();
pad->Draw();
pad->cd();

auto l = new TLegend(.2, .2, .4, .4);



  // draw a frame to define the range
TH1F *hr = pad->DrawFrame(20,1,320,3);
hr->SetTitle("#sigma_{Z} for different scatterer and absorber widths");
hr->SetXTitle("Distance (mm)");
hr->SetYTitle("#sigma_{Z} (mm)");
//hr->SetTextSize(20);
pad->GetFrame()->SetFillColor(0);
pad->GetFrame()->SetBorderSize(26);

  // create first graph
Int_t n1 = 7;
Double_t x1[] = {40,80,100,120,150,200,300};
Double_t y1[] = {1.86,1.89,1.93,1.95,1.98,2.04,2.10};
Double_t ex1[] = {0,0,0,0,0,0,0,0,0};
Double_t ey1[] = {.01,.01,.01,.01,.01,.01,.01};
TGraphErrors *gr1 = new TGraphErrors(n1,x1,y1,ex1,ey1);
gr1->SetName("gr1");
gr1->SetLineColor(kBlue);
gr1->SetLineWidth(1);
gr1->SetMarkerStyle(21);
gr1->SetMarkerSize(0.75);
gr1->SetMarkerColor(kBlue);

//gr1->SetMarkerStyle(20);
gr1->Draw("P");
l->AddEntry("gr1","Scatterer Width","ep");
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
Int_t n2 = 7;
Float_t x2[] = {40,80,100,120,150,200,300};
Float_t y2[] = {1.91,1.86,1.83,1.86,1.91,1.92,1.95};
Float_t ex2[] = {0,0,0,0,0,0,0,0,0};
Float_t ey2[] = {.01,.01,.01,.01,.01,.01,.01};
/*for (Int_t i=0;i<n2;i++) {
y2[i] *= 100;
ey2[i] *= 100;
}*/
//create a transparent pad drawn on top of the main pad
c1->cd();
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
gr2->SetMarkerStyle(20);
gr2->SetMarkerSize(0.75);
gr2->SetName("gr2");
Double_t xmin = pad->GetUxmin();
Double_t ymin = 1;
Double_t xmax = pad->GetUxmax();
Double_t ymax = 3;
TH1F *hframe = overlay->DrawFrame(xmin,ymin,xmax,ymax);
hframe->GetXaxis()->SetLabelOffset(99);
hframe->GetYaxis()->SetLabelOffset(99);
gr2->Draw("P");
l->AddEntry("gr2","Absorber Width","ep");
//TLegendEntry *le = l->AddEntry("gr1","DSS = 200mm","ep");
//le->SetTextColor(kRed);;



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
return c1;
}

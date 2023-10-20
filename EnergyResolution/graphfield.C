
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TCanvas.h"
#include "TF1.h"
#include "TH1.h"
#include "TGraphErrors.h"
#include "TAttLine.h"
#include "TStyle.h"
#include "TColor.h"
void graphfield()

{
   TCanvas *c1 = new TCanvas("c1","Graph with error bars",1000,1000);
   //c1->SetFillColor(42);
   //c1->SetGrid();
   //c1->GetFrame()->SetFillColor(21);
   //c1->GetFrame()->SetBorderSize(12);
   //c1->Divide(2, 1);
   //c1->cd(1);
//    TPad *pad = new TPad("pad","",0,0,1,1);
//    pad->SetFillColor(0);
//    pad->SetGrid();
//    pad->Draw();
//    pad->cd();
//    //pad->Range(-10,0,340,7);
//    const Int_t n = 8;
//    Double_t x[n]  = {0,40,80,100,120,180,240,300};
//    Double_t y[n]  = {1.83,1.96,2.12,2.21,2.54,3.41,5.21,6.25};
//    Double_t ex[n] = {0};
//    Double_t ey[n] = {.01,.01,.01,.01,.01,.01,.01,.01};
//    TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);
//    //gr->SetTitle("Uncertainty along Z-axis(at y=0)");
//    gr->GetXaxis()->SetTitle("Source position [mm]");
//    gr->GetXaxis()->SetLabelSize(0.0385);
//    gr->GetXaxis()->SetTitleSize(0.0385);
//    gr->GetXaxis()->SetTitleOffset(1.35);
//    gr->GetXaxis()->SetLimits(-10.,340);
//    gr->GetYaxis()->SetTitle("#sigma_{X} [mm]");
//    gr->GetYaxis()->SetLabelSize(0.0385);
//    gr->GetYaxis()->SetTitleSize(0.0385);
//    gr->GetXaxis()->SetTitleOffset(1.35);
//    gr->SetMarkerColor(4);
//    gr->SetMarkerStyle(4);
//    gr->SetMarkerSize(2);
//    gr->Draw("AP");
//    gr->SetTitle("");
//    
//    TLine *f=new TLine(50,1.4,50,6.7);
//     f->SetLineColor(kRed);
//     f->Draw();
 //////////////////////////////////////////////////  
   
  // c1->cd(2);

  TPad *pad1 = new TPad("pad","",0,0,1,1);
  pad1->SetFillColor(0);
  pad1->SetGrid();
  pad1->Draw();
  pad1->cd();
  
  ifstream in;
  in.open(Form("graph2D.dat"));
  Float_t x1,y1,z1;
   Int_t nlines = 0;
   //TFile *f = new TFile("Sample.root","RECREATE");
   TH2F *h2 = new TH2F("h2","Field Of View",60,-15,215,60,-15,215);
   while (1) {
      in >> x1 >> y1 >> z1;
      if (!in.good()) break;
      h2->Fill(x1,y1,z1);
      nlines++;
   }
   h2->SetMinimum(70);
   h2->GetXaxis()->SetTitle("Source position along x-axis [mm]");
   h2->GetXaxis()->SetLabelSize(0.0385);
   h2->GetXaxis()->SetTitleSize(0.0385);
   h2->GetXaxis()->SetTitleOffset(1.35);
   h2->GetYaxis()->SetTitle("Source position along y-axis [mm]");
   h2->GetYaxis()->SetLabelSize(0.0385);
   h2->GetYaxis()->SetTitleSize(0.0385);
   h2->GetYaxis()->SetTitleOffset(1.35);
   h2->GetZaxis()->SetTitle("Fraction of reconstructed events [%]");
   h2->GetZaxis()->SetLabelSize(0.0385);
   h2->GetZaxis()->SetTitleSize(0.0385);
   //h2->GetZaxis()->SetTitleOffset(1.35);
   h2->SetTitle("");
   h2->SetStats(0);
   //printf(" found %d points\n",nlines);
   in.close();
   h2->Draw("colz");
   gStyle->SetPalette(56);
   //f->Write();
   TLine *f1=new TLine(50,-15,50,50);
    f1->SetLineColor(kRed);
    f1->Draw();

    TLine *f2=new TLine(-15,50,50,50);
    f2->SetLineColor(kRed);
    f2->Draw();
   return c1;
} 

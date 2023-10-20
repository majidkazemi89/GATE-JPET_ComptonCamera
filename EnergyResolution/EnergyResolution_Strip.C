void Canvas_1()
{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Thu Apr 27 15:58:01 2023) by ROOT version 6.15/01
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",292,108,538,323);
   Canvas_1->Range(-0.8125001,-5.6175,7.3125,50.5575);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1D *EnergyResolution_Strip__1 = new TH1D("EnergyResolution_Strip__1","EnergyResolution_Strip",6500,0,6.5);
   EnergyResolution_Strip__1->SetBinContent(342,21.4);
   EnergyResolution_Strip__1->SetBinContent(542,14.8);
   EnergyResolution_Strip__1->SetBinContent(1410,9.4);
   EnergyResolution_Strip__1->SetBinContent(1775,8.8);
   EnergyResolution_Strip__1->SetBinContent(2081,7.3);
   EnergyResolution_Strip__1->SetBinContent(4201,5.4);
   EnergyResolution_Strip__1->SetBinContent(5011,5.1);
   EnergyResolution_Strip__1->SetBinContent(5881,4.7);
   EnergyResolution_Strip__1->SetBinError(342,21.4);
   EnergyResolution_Strip__1->SetBinError(542,14.8);
   EnergyResolution_Strip__1->SetBinError(1410,9.4);
   EnergyResolution_Strip__1->SetBinError(1775,8.8);
   EnergyResolution_Strip__1->SetBinError(2081,7.3);
   EnergyResolution_Strip__1->SetBinError(4201,5.4);
   EnergyResolution_Strip__1->SetBinError(5011,5.1);
   EnergyResolution_Strip__1->SetBinError(5881,4.7);
   EnergyResolution_Strip__1->SetEntries(8);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("EnergyResolution_Strip");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 8      ");
   ptstats_LaTex = ptstats->AddText("Mean  =  1.758");
   ptstats_LaTex = ptstats->AddText("Std Dev   =   1.74");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   EnergyResolution_Strip__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(EnergyResolution_Strip__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   EnergyResolution_Strip__1->SetLineColor(ci);
   EnergyResolution_Strip__1->GetXaxis()->SetLabelFont(42);
   EnergyResolution_Strip__1->GetXaxis()->SetLabelSize(0.035);
   EnergyResolution_Strip__1->GetXaxis()->SetTitleSize(0.035);
   EnergyResolution_Strip__1->GetXaxis()->SetTitleFont(42);
   EnergyResolution_Strip__1->GetYaxis()->SetLabelFont(42);
   EnergyResolution_Strip__1->GetYaxis()->SetLabelSize(0.035);
   EnergyResolution_Strip__1->GetYaxis()->SetTitleSize(0.035);
   EnergyResolution_Strip__1->GetYaxis()->SetTitleOffset(0);
   EnergyResolution_Strip__1->GetYaxis()->SetTitleFont(42);
   EnergyResolution_Strip__1->GetZaxis()->SetLabelFont(42);
   EnergyResolution_Strip__1->GetZaxis()->SetLabelSize(0.035);
   EnergyResolution_Strip__1->GetZaxis()->SetTitleSize(0.035);
   EnergyResolution_Strip__1->GetZaxis()->SetTitleFont(42);
   EnergyResolution_Strip__1->Draw("");
   
   TPaveText *pt = new TPaveText(0.3202239,0.9351869,0.6797761,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("EnergyResolution_Strip");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}

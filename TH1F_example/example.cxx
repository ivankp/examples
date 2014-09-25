#include <ctime> // for time()
#include <cmath>

#include "TH1.h"
// reference for ROOT 1D histogram class TH1F
// http://root.cern.ch/root/html/TH1F.html

#include "TRandom3.h"
// For random number generation

#include "TCanvas.h"
#include "TLegend.h"
#include "TText.h"
#include "TPaveText.h"
#include "TAxis.h"
#include "TGaxis.h"

using namespace std;

int main(int argc, char* argv[])
{
  // constructor
  // TH1F(const char* name, const char* title, Int_t nbinsx, Double_t xlow, Double_t xup)
  TH1F hist[2] = {
    TH1F("first" ,"Histogram Example",100,0.,10.),
    TH1F("second","Histogram Example",100,0.,10.)
  };

  // Fill the histograms with 1000 random numbers
  // between 0 and 10
  TRandom3 rand( time(0) ); // using time() as the seed
  for (int i=0;i<1000;i++)
    for (int h=0;h<2;h++)
      hist[h].Fill(rand.Rndm()*10);

  // Set histogram minimum and maximum
  // The default vertical axis range is computed
  // for the first drawn histogram
  // We need to set it's range so that the first
  // histogram fits as well.
  // Multiply so that the largest bin is not right on the border
  const Double_t miny = min( hist[0].GetMinimum(), hist[1].GetMinimum() )*0.85;
  const Double_t maxy = max( hist[0].GetMaximum(), hist[1].GetMaximum() )*1.05;
  hist[0].SetMinimum(miny);
  hist[0].SetMaximum(maxy);
  // The Y axis maximum and minumum for 1D histograms
  // are handled in a tricky way.
  // Read the documentation if something other then what
  // what you think should happens
  

  Color_t color[] = {46, 602};
  // 602 is the default color

  // Set properties of the histograms
  for (int h=0;h<2;h++) {
    hist[h].SetStats(0); // remove the default statistics box
    hist[h].SetLineColor(color[h]); // set line color
    hist[h].SetMarkerColor(color[h]); // no marker is drawn by default
                                      // but if you don't set the marker color
                                      // you will have a black dot in the legend over the line
  }

  hist[1].SetLineWidth(2); // make the blue histogram line thicker

  // The title and axes label are only drawn for the first histogram
  hist[0].SetXTitle("Value, units"); // label the horizontal axis
  hist[0].SetYTitle("Num counts"); // label the vertical axis

  TCanvas canv("canv","",600,400);

  hist[0].Draw();
  hist[1].Draw("same");

  // Add second axis
  // ranging from 10 to 100
  // If you want the range of this axis to correspond to something meaningful
  // you have to calculate the range yourself
  TGaxis axis2(
    hist[0].GetXaxis()->GetXmax(),miny,
    hist[0].GetXaxis()->GetXmax(),maxy,
    10.,100.,510,"+L");
  axis2.SetTitle("Second axis");
  // set font and size to match a normal axis
  // the defaults look bad
  axis2.SetLabelFont(hist[0].GetYaxis()->GetLabelFont());
  axis2.SetTitleFont(hist[0].GetYaxis()->GetTitleFont());
  axis2.SetLabelSize(hist[0].GetYaxis()->GetLabelSize());
  axis2.SetTitleSize(hist[0].GetYaxis()->GetTitleSize());
  axis2.Draw();

  // Add Legend
  // absolute coordinates, not axis dependent
  TLegend leg(0.15,0.84,0.3,0.95);
  for (int h=0;h<2;h++) leg.AddEntry(&hist[h],hist[h].GetName());
  leg.SetFillColor(0); // otherwise the legend will be gray
  leg.SetBorderSize(1); // 0 is no border
  // leg.SetFillStyle(0); // uncomment to make the legend transparent
  leg.Draw();

  // Add a text box with number of entries
  TPaveText text_box(0.75,0.86,0.88,0.95,"NDCbr");
  // NDCbr means: NormalizeD Coordinate system, Bottom Right
  // by default, TPaveText is drawn at axes coordinates
  text_box.SetBorderSize(1);
  text_box.SetFillColor(0);
  text_box.SetTextFont(42);
  for (int h=0;h<2;h++)
   text_box.AddText(Form("N_{%d} = %.0f",h,hist[h].GetEntries()));
  text_box.Draw();

  // Add a single line of floating text
  TText floating_text(0.02,0.02,"This is an example of drawing histograms in ROOT");
  floating_text.SetNDC();
  floating_text.SetTextAlign(11);
  floating_text.SetTextFont(42);
  floating_text.SetTextSize(0.03);
  floating_text.Draw();

  canv.SaveAs("hist.pdf");

  return 0;
}

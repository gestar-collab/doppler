{
	gStyle->SetOptStat(0);

	TH1F *h0 = new TH1F("h0", ";kinetic energy of electrons [keV];", 150, 300, 600);
	TH1F *h1 = new TH1F("h1", ";kinetic energy of electrons [keV];", 150, 300, 600);
	h0->SetLineColor(kRed);
	h1->SetLineColor(kBlue);

	TChain t0("t");
	t0.Add("g662keV2HPGe.root");
	t0.Draw("k>>h0", "pdg==11 && vlm==1 && stp==0 && pro==2013");

	TChain t1("t");
	t1.Add("g662keV2HPGeLivermore.root");
	t1.Draw("k>>h1", "pdg==11 && vlm==1 && stp==0 && pro==2013");

	h0->Draw("histe");
	h1->Draw("same");

	TLegend l(0.7, 0.8, 0.95, 0.95);
	l.AddEntry(h0, "w/o Livermore", "l");
	l.AddEntry(h1, "with Livermore", "l");
	l.Draw();
}

void drawEx(const char* folder="250929091850")
{
	TChain *t = new TChain("t");
	for (int i=0; i<10; i++) t->Add(Form("%s/g113keV%d.root",folder,i));

	t->Draw("x:et[2]", "trk==1 && pro==2012 && et[2]>105 && et[2]<107 && abs(x)<4");
}


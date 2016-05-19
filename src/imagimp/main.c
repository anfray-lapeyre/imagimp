/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/
#include "../../include/Inclusion.h"


int main(int argc, char** argv) {
	Calque test=creerCalque(0,0);
	test.rvb=LoadPPM("resources\\FreaksBroz.512.ppm",&(test.width),&(test.height));
	Histogramme * histo = createHisto(test.rvb,test.width, test.height);
	test=HistoToImage(*histo);
	initGLIMAGIMP_IHM(test.width,test.height,test.rvb,650,400,0);
	setFullsreen(0);
	launchApp();
	
	return 0;
}
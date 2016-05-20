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
	test.rvb=LoadPPM("resources/FreaksBroz.512.ppm",&(test.width),&(test.height));

	test = cloneCalque(test);
	// LUT lut=creerLUT();
	// LUT lut2=creerLUT();

	// ADDLUM(&lut, 30);
	// ADDCON(&lut2, 10);

	// lut = fusionLUT(&lut, &lut2);

	// test=appliquerLUT(&lut,test);


	// printf("prout\n");

	LUT lut = creerLUT();

	Liste_LUT liste = initListe_LUT();

	ADDLUM(&lut, 128);

	addNodeLUT(liste, lut);

	addNodeLUT(liste, lut);

	lut = fusionListeLUT(liste);
	
	freeListe_LUT(liste);

	// deleteLastNodeLUT(liste);

	// deleteLastNodeLUT(liste);

	// test = appliquerLUT(&lut,test);

	Histogramme * histo = createHisto(test.rvb,test.width, test.height);
	test=HistoToImage(*histo);







	// Calque calque = creerCalque(600,400);

	// Liste_Calque listeCalque = initListe_Calque();



	

	
	initGLIMAGIMP_IHM(test.width,test.height,test.rvb,800,400,0);
	setFullsreen(0);
	launchApp();
	
	
	return 0;
}
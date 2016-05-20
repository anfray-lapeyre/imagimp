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
	test.rvb=LoadPPM("resources/Billes.256.ppm",&(test.width),&(test.height));

	test = cloneCalque(test);
	// LUT lut=creerLUT();
	// LUT lut2=creerLUT();

	// ADDLUM(&lut, 30);
	// ADDCON(&lut2, 10);

	// lut = fusionLUT(&lut, &lut2);

	// test=appliquerLUT(&lut,test);


	// printf("prout\n");

	// LUT lut = creerLUT();

	// Liste_LUT liste = initListe_LUT();

	// ADDLUM(&lut, 128);

	// addNodeLUT(liste, lut);

	// addNodeLUT(liste, lut);

	// lut = fusionListeLUT(liste);
	
	// freeListe_LUT(liste);

	// deleteLastNodeLUT(liste);

	// deleteLastNodeLUT(liste);

	// test = appliquerLUT(&lut,test);

	// Histogramme * histo = createHisto(test.rvb,test.width, test.height);
	// test=HistoToImage(*histo);


	Liste_Calque listeCalque = initListe_Calque();
	if(isVideListe_Calque(listeCalque)){
		//printf("prout\n");
	}

	Calque calque = creerCalque(600,400);
	changerFusion(&calque, 1);

	// if(calque.width == 600 && calque.height == 400 && calque.fusion == 1 && calque.opacity ==1 && calque.rvb == NULL){
	// 	printf("prout\n");
	// }

	// Node_Calque * node = malloc(sizeof(Node_Calque));

	// node->calque = &calque;

	// printf("prout3\n");

	// addNodeCalque(listeCalque, node);

	// printf("prout4\n");

	// if(!isVideListe_Calque(listeCalque)){
	// 	printf("prout2\n");
	// }
	Calque calque2 = cloneCalque(calque);
	printf("prout2\n");
	if(calque.width == 600 && calque.height == 400 && calque.fusion == 1 && calque.opacity ==1 && calque.rvb == NULL){
		printf("prout\n");
	
	}

	// addNewCalque(listeCalque);
	// if(!isVideListe_Calque(listeCalque)){
	// }

	//Calque * calque = fusionCalques(listeCalque);

	

	// initGLIMAGIMP_IHM(calque->width,calque->height,calque->rvb,800,400,0);
	// setFullsreen(0);
	// launchApp();
	
	
	return 0;
}
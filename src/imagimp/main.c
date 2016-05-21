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
	test.rvb=LoadPPM("resources/Embryos.512.ppm",&(test.width),&(test.height));
	// Histogramme * histo = createHisto(test.rvb,test.width, test.height);
	// test=HistoToImage(*histo);

	Liste_Calque listeCalque = initListe_Calque();


	Node_Calque * node = malloc(sizeof(Node_Calque));

	Calque c=cloneCalque(test);
	node->calque = &c;
	addNodeCalque(listeCalque, node);

	addNewCalque(listeCalque);
	// if(isVideListe_LUT(listeCalque->calque->luts)){
		// printf("test2\n");
	// }
	// printf("test3\n");
	addLUTCalque(listeCalque, 1, 100.);
	// if(!isVideListe_LUT(listeCalque->calque->luts)){
		// printf("test4\n");
	// }
	
	freeListe_LUT(listeCalque->calque->luts);
	printf("zbrrrra,");
	freeListe_Calque(listeCalque);
	printf("Arggh,");
	if(isVideListe_Calque(listeCalque)){
		printf("test5\n");
	}
	// initGLIMAGIMP_IHM(test.width,test.height,test.rvb,800,400,0);
	// setFullsreen(0);
	// launchApp();

	
	
	return 0;
}
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
	Histogramme * histo = createHisto(test.rvb,test.width, test.height);
	test=HistoToImage(*histo);

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

	


	// Liste_Calque listeCalque = initListe_Calque();
	// if(isVideListe_Calque(listeCalque)){
		// printf("prout\n");
	// }

	// Calque *calque =malloc(sizeof(Calque));
	// *calque= creerCalque(600,400);
	// calque->rvb=malloc(sizeof(Uint8)*calque->width*calque->height*3);
	// for(int i=0;i<calque->width*calque->height*3;i++){
		// if(i%3==2)
			// calque->rvb[i]=0;
		// else
			// calque->rvb[i]=255;
	// }
	

	// if(calque.width == 600 && calque.height == 400 && calque.fusion == 1 && calque.opacity ==1 && calque.rvb == NULL){
		// printf("prout\n");
	// }

	// Node_Calque * node = malloc(sizeof(Node_Calque));

	// node->calque = calque;


	// addNodeCalque(listeCalque, node);

	// printf("prout4\n");

	// if(!isVideListe_Calque(listeCalque)){
		// printf("prout2\n");
	// }
	
	
	// addNewCalque(listeCalque);
	// if(!isVideListe_Calque(listeCalque) && listeCalque->next != NULL && listeCalque->next->next == NULL){
		// printf("caca\n");
	// }
	


	// addNewCalque(listeCalque);
	// for(int i=0;i<listeCalque->next->next->calque->width*listeCalque->next->next->calque->height*3;i++){
		// if(i%3==1)
			// listeCalque->next->next->calque->rvb[i]=0;
		// else
			// listeCalque->next->next->calque->rvb[i]=255;
	// }
	// changerOpacite(listeCalque->calque, .2);
	// changerOpacite(listeCalque->next->calque, 0.5);
	// changerOpacite(listeCalque->next->next->calque, 0.2);
	// changerFusion(listeCalque->calque,0);
	// changerFusion(listeCalque->next->calque,0);
	// changerFusion(listeCalque->next->next->calque,0);
	// Calque * calque2 = fusionCalques(listeCalque);
	

	initGLIMAGIMP_IHM(test.width,test.height,test.rvb,800,400,0);
	setFullsreen(0);
	launchApp();
	
	
	return 0;
}
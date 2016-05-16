/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/
#include "../include/Inclusion.h"


int main(int argc, char** argv) {
	
	Calque test=creerCalque(0,0);
	LoadImageNB(&test,"resources\\test.ppm");
	printf("%d,%d\n",test.width,test.height);
	getchar();
	afficherImage(&test);
	SauvegardeImage(&test, "resources\\test2.ppm");
	return 0;
}
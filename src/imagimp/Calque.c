/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/
#include "../../include/Calque.h"

Calque creerCalque(int width, int height){
	Calque res;
	res.width=width;
	res.height=height;
	res.fusion=0;
	res.opacity=1.;
	return res;
	
}
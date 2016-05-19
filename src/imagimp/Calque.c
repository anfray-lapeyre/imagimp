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


void changerOpacite(Calque * c, float new_opacity){
	if(NULL == c)
		return;
	if(new_opacity<=1 && new_opacity>=0)
		c->opacity=new_opacity;
}

void changerFusion(Calque * c,int fusion){
	if(NULL == c)
		return;
	c->fusion=fusion;
}

Liste_Calque initListe_Calque(){
	
}

int isVideListe_Calque(Liste_Calque liste){
	
}

void addNodeCalque(Liste_Calque liste, Node_Calque* node){
	
}

void deleteLastNodeCalque(Liste_Calque liste){
	
}

void freeListe_Calque(Liste_Calque liste){
	
}

Calque fusionCalques(Calque c1, Calque c2){
	
}

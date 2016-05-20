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

	Liste_Calque liste = malloc(sizeof(Node_Calque));
	liste->next = NULL;
	liste->previous = NULL;

	liste->calque = creerCalque(800, 600);

	return liste;
}

int isVideListe_Calque(Liste_Calque liste){

	return NULL == liste->next;
}

void addNodeCalque(Liste_Calque liste, Node_Calque* node){

	if(NULL == liste){
		return;
	}

	if(isVideListe_Calque(liste)){
		liste->next = liste;
		liste->previous =liste;

		return;
	}

	if(liste->next == liste){

		Liste_Calque newCalque = malloc(sizeof(Node_Calque));
		newCalque->next = liste;
		newCalque->previous = liste;

		liste->next = newCalque;
		liste->previous = newCalque;

		return;

	}

	Liste_Calque newCalque = malloc(sizeof(Node_Calque));

	newCalque->next = liste;
	newCalque->previous = liste->previous;

	liste->previous->next = newCalque;
	liste->previous = newCalque;
	
}

void deleteLastNodeCalque(Liste_Calque liste){

	if(NULL == liste || isVideListe_Calque(liste)){
		return;
	}

	if(liste->next == liste){
		liste->next = NULL;
		liste->previous = NULL;

		return;
	}

	Node_Calque * tmp;

	liste->previous->previous->next = NULL;
	tmp = liste->previous->previous = NULL;

	free(liste->previous);

	liste->previous = tmp;
	
}

void freeListe_Calque(Liste_Calque liste){
	
}

Calque * fusionCalques(Calque c1, Calque c2){
	
}

Calque cloneCalque(Calque c){

	Calque clone ;
	clone.width=c.width;
	clone.height=c.height;
	clone.fusion=c.fusion;
	clone.opacity=c.opacity;
	clone.rvb=malloc(sizeof(Uint8)*clone.width*clone.height*3);
	for(int i=0;i<clone.width*clone.height*3;i++){
		clone.rvb[i]=c.rvb[i];
	}
	return clone;
}

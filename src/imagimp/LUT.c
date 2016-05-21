/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/
#include "../../include/LUT.h"


LUT creerLUT(){
	LUT lut;

	for(int i = 0 ; i < max_Value ; i++){
		lut.val[i] = i;
	}

	return lut;
}

Liste_LUT initListe_LUT(){

	Liste_LUT liste = malloc(sizeof(Node_LUT));
	liste->next = NULL;
	liste->previous = NULL;

	liste->lut = creerLUT();

	return liste;
}

int isVideListe_LUT(Liste_LUT liste){

	return NULL == liste->next;
}

void addNodeLUT(Liste_LUT liste, LUT lut){

	if(NULL == liste){
		return;
	}

	if(isVideListe_LUT(liste)){

		liste->next = liste;
		liste->previous = liste;

		for(int i = 0 ; i < max_Value ; i++){
			liste->lut.val[i] = lut.val[i];
		}

		return;
	}

	if(liste->next == liste){
		Liste_LUT newListe = malloc(sizeof(Node_LUT));
		newListe->next = liste;
		newListe->previous = liste;

		liste->next = newListe;
		liste->previous = newListe;

		for(int i = 0 ; i < max_Value ; i++){
			newListe->lut.val[i] = lut.val[i];
		}

		return;
	}

	Liste_LUT newListe = malloc(sizeof(Node_LUT));
	newListe->next = liste;
	newListe->previous = liste->previous;

	liste->previous->next = newListe;
	liste->previous = newListe;

	for(int i = 0 ; i < max_Value ; i++){
		newListe->lut.val[i] = lut.val[i];
	}
}

void deleteLastNodeLUT(Liste_LUT liste){

	if(NULL == liste || isVideListe_LUT(liste)){
		return;
	}

	if(liste->next == liste){
		liste->next = NULL;
		liste->previous = NULL;

		return;
	}

	Node_LUT * tmp;

	liste->previous->previous->next = liste;
	tmp = liste->previous->previous;
	free(liste->previous);
	liste->previous = tmp;
}

void ADDLUM(LUT * lut , int intensity){

	if(NULL == lut){
		return;
	}

	for(int i = 0 ; i < max_Value ; i++){
		lut->val[i] = MIN(255,lut->val[i]+intensity); 
	}
}

void DIMLUM(LUT * lut , int intensity){

	if(NULL == lut){
		return;
	}

	for(int i = 0 ; i < max_Value ; i++){
		lut->val[i] = MAX(0,lut->val[i]-intensity);
	}
}

void INVERT(LUT * lut){

	if(NULL == lut){
		return;
	}

	for(int i = 0 ; i < max_Value ; i++){
		lut->val[i] = MAX(0, MIN(255, lut->val[255-i]));
	}
}

void ADDCON(LUT * lut , float contraste){

	if(NULL == lut || contraste <= 1.){
		return;
	}

	for(int i = 0 ; i < max_Value ; i++){
		lut->val[i] = MAX(0, MIN(255, 128 - (128-lut->val[i]) * contraste ));
	}

}

void DIMCON(LUT * lut , float contraste){

	if(NULL == lut || contraste >= 1.){
		return;
	}

	for(int i = 0 ; i < max_Value ; i++){
		lut->val[i] = MAX(0, MIN(255, 128 - (128-lut->val[i]) * contraste ));
	}

}

Calque appliquerLUT(LUT * lut , Calque calque){

	Calque calqueLut = cloneCalque(calque);

	for(int i = 0 ; i < calqueLut.height*calqueLut.width*3 ; i++){

		calqueLut.rvb[i] = lut->val[calqueLut.rvb[i]];
	}

	return calqueLut;
}

void freeListe_LUT(Liste_LUT liste){
	if(liste == NULL)
		return;
	while(!isVideListe_LUT(liste)){
		deleteLastNodeLUT(liste);
	}
}

LUT fusionLUT(LUT * a, LUT * b){

	LUT fusion ;

	for(int i = 0 ; i < max_Value ; i++){
		fusion.val[i] = b->val[a->val[i]];
	}

	return fusion;
}

LUT fusionListeLUT(Liste_LUT liste){

	LUT res = creerLUT();

	if(NULL == liste){
		return res;
	}

	Node_LUT * tmp = liste ;

	if(isVideListe_LUT(liste)){
		return res;
	}
	else{

		res = fusionLUT(&res , &tmp->lut);
		tmp = tmp->next;

		while(tmp != liste){
			res = fusionLUT(&tmp->lut , &res);
			tmp = tmp->next;

		}
	}
	return res;
}


LUT cloneLUT(LUT lut){
	LUT res;
	for(int i=0;i<max_Value;i++){
		res.val[i]=lut.val[i];
	}
	return res;
}


Liste_LUT cloneListeLUTS(Liste_LUT luts){
	if(luts == NULL)
		return NULL;

	Liste_LUT res= initListe_LUT();
	if(isVideListe_LUT(luts))
		return res;
	Liste_LUT tmp = luts;
	
	res->lut=cloneLUT(luts->lut);
	while(tmp->next != NULL){
		addNodeLUT(res,tmp->lut);
		tmp=tmp->next;
		
	}
	
	return res;
}

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

	Liste_LUT liste = malloc(sizeof(Liste_LUT));
	liste->next = NULL;
	liste->previous = NULL;

	return liste;
}

int isVideListe_LUT(Liste_LUT liste){

	return 0;
}

void addNodeLUT(Liste_LUT liste, Node_LUT* node){

}

void deleteLastNodeLUT(Liste_LUT liste){

}

void freeListe_LUT(Liste_LUT liste){

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

	if(NULL == lut && contraste <= 1.){
		return;
	}

	for(int i = 0 ; i < max_Value ; i++){
		lut->val[i] = MAX(0, MIN(255, 128 - (128-lut->val[i]) * contraste ));
	}

}

void DIMCON(LUT * lut , float contraste){

	if(NULL == lut && contraste >= 1.){
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

LUT fusionLUT(LUT * a, LUT * b){

	LUT fusion ;

	for(int i = 0 ; i < max_Value ; i++){
		fusion.val[i] = b->val[a->val[i]];
	}

	return fusion;
}


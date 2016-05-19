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

	int i;

	for(i = 0 ; i < max_Value ; i++){
		lut.val[i] = i;
	}

	return lut;
}

Liste_LUT initListe_LUT(){

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

	int i;
	for(i = 0 ; i < max_Value ; i++){
		lut->val[i] += intensity ; 
	}
}

void DIMLUM(LUT * lut , int intensity){

	int i;
	for(i = 0 ; i < max_Value ; i++){
		lut->val[i] -= intensity ; 
	}
}

void INVERT(LUT * lut){

	int i ;
	for(i = 0 ; i < max_Value ; i++){
		lut->val[i] = lut->val[128-i] ;
	}
}

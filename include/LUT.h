/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/

/*
Ce fichier contiendra la définition de la structure LUT, ainsi que sa liste Node_LUT et Liste_LUT
Il contiendra les prototypes de fonction nécessaires aux deux structures
*/


#ifndef LUT_H
#define LUT_H
//On inclue le reste du projet
#include "Inclusion.h"
//On utilise bien un unsigned char comme prévu, sous la forme d'un entier
typedef unsigned char Uint8;

typedef struct LUT {
	Uint8 val[max_Value];
}LUT;

typedef struct Node_LUT{
	struct Node_LUT * next;
	struct Node_LUT * previous;
	LUT lut;
}Node_LUT;

typedef Node_LUT * Liste_LUT;

//Initialise un LUT à l'identité -> chaque valeur donne cette même valeur
LUT creerLUT();

Liste_LUT initListe_LUT();

int isVideListe_LUT(Liste_LUT liste);

void addNodeLUT(Liste_LUT liste, LUT lut);

void deleteLastNodeLUT(Liste_LUT liste);

void ADDLUM(LUT * lut , int intensity);

void DIMLUM(LUT * lut , int intensity);

void INVERT(LUT * lut);

void ADDCON(LUT * lut , float contraste);

void DIMCON(LUT * lut, float contraste);

Calque appliquerLUT(LUT * lut , Calque calque);

void freeListe_LUT(Liste_LUT liste);

LUT fusionLUT(LUT * a, LUT * b);

LUT * fusionListeLUT(Liste_LUT liste);

LUT cloneLUT(LUT lut);

Liste_LUT cloneListeLUTS(Liste_LUT luts);

#endif
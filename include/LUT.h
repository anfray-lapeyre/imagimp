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

typedef Node_LUT* Liste_LUT;

//Initialise un LUT à l'identité -> chaque valeur donne cette même valeur
LUT creerLUT();
//Reste à implémenter l'initialisation des différents LUT possibles 


Liste_LUT initListe_LUT();

int isVideListe_LUT(Liste_LUT);

void addNodeLUT(Liste_LUT liste, Node_LUT* node);

void deleteLastNodeLUT(Liste_LUT liste);

void freeListe_LUT(Liste_LUT liste);


#endif
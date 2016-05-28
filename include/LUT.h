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

/*
*Initalise une liste circulaire doublement chainee vide
*/
Liste_LUT initListe_LUT();

/*
*Vérifie si les pointeurs next et previous sont vide
*Si oui retourne 1
*/
int isVideListe_LUT(Liste_LUT liste);

/*
*Rajoute un node en bout de liste, contenant le lut en paramètre
*/
void addNodeLUT(Liste_LUT liste, LUT lut);

/*
*Detruit le dernier Node de la liste.
*/
void deleteLastNodeLUT(Liste_LUT liste);

/*
*Cree un lut d'ajout de lumiere (décalage vers la droite)
*/
void ADDLUM(LUT * lut , int intensity);

/*
*Cree un lut d'ajout de lumiere (décalage vers la gauche)
*/
void DIMLUM(LUT * lut , int intensity);

/*
*Cree un lut d'inversion de couleur 
*/
void INVERT(LUT * lut);

/*
*Cree un lut d'ajout de contraste (on augmente la différence entre les valeurs et 127 -> Le centre)
*/
void ADDCON(LUT * lut , float contraste);

/*
*Cree un lut d'ajout de contraste (on réduit la différence entre les valeurs et 127 -> Le centre)
*/
void DIMCON(LUT * lut, float contraste);

/*
*Applique toutes les lut à un calque et retourne le résultat
*/
Calque appliquerLUT(LUT * lut , Calque calque);

/*
*Nettoie tous les pointeurs d'une liste
*/
void freeListe_LUT(Liste_LUT liste);

/*
*Fusion de deux LUTs et retourne le résultat
*/
LUT fusionLUT(LUT * a, LUT * b);

/*
*Fusion de tous les LUT d'une liste et retourne le résultat
*/
LUT * fusionListeLUT(Liste_LUT liste);

/*
*Clone un LUT sans lui attribuer directement de mémoire
*/
LUT cloneLUT(LUT lut);

/*
*Clone une liste entière de LUT (pour cloner les calques)
*/
Liste_LUT cloneListeLUTS(Liste_LUT luts);

#endif
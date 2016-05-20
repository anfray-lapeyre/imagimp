/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/

/*
Ce fichier contiendra la définition de la structure Calque, ainsi que sa liste Node_Calque et Liste_Calque
Il contiendra les prototypes de fonction nécessaires aux deux structures
*/

#ifndef CALQUE_H
#define CALQUE_H
//On inclue le reste du projet
#include "Inclusion.h"
//On utilise bien un unsigned char comme prévu, sous la forme d'un entier
typedef unsigned char Uint8;

typedef struct Node_LUT * Liste_LUT;

typedef struct Calque {
	float opacity;
	unsigned int width;
	unsigned int height;
	Uint8 * rvb;
	int fusion; //Definit s'il s'additionnera ou se multipliera aux autres calques
	Liste_LUT luts;
}Calque;

typedef struct Node_Calque{
	struct Node_Calque * next;
	struct Node_Calque * previous;
	Calque * calque;
}Node_Calque;

typedef Node_Calque* Liste_Calque;

//Pour les valeurs de 1 à 6 -> Crée les LUT prédéfinis
//Pour toute autre valeur, crée une objet LUT où chaque valeur du tableau vaut 0;
Calque creerCalque(int width, int height);

void changerOpacite(Calque * c, float new_opacity);

void changerFusion(Calque * c,int fusion);

Liste_Calque initListe_Calque();

int isVideListe_Calque(Liste_Calque liste);

void addNodeCalque(Liste_Calque liste, Node_Calque* node);

void addNewCalque(Liste_Calque liste);

void deleteLastNodeCalque(Liste_Calque liste);

void freeListe_Calque(Liste_Calque liste);

Calque *fusionCalques(Liste_Calque liste);

Calque cloneCalque(Calque c);


void addLUTCalque(Liste_Calque liste, int choix, float param);



#endif
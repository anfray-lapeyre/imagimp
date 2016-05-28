/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/

/*
Ce fichier contiendra la d�finition de la structure Calque, ainsi que sa liste Node_Calque et Liste_Calque
Il contiendra les prototypes de fonction n�cessaires aux deux structures
*/

#ifndef CALQUE_H
#define CALQUE_H
//On inclue le reste du projet
#include "Inclusion.h"
//On utilise bien un unsigned char comme pr�vu, sous la forme d'un entier
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

//Pour les valeurs de 1 � 6 -> Cr�e les LUT pr�d�finis
//Pour toute autre valeur, cr�e une objet LUT o� chaque valeur du tableau vaut 0;
Calque creerCalque(int width, int height);

/*
*Modifie l'opacit� du calque pass� en param�tre, en lui donnant la valeur donn�e
*/
void changerOpacite(Calque * c, float new_opacity);

/*
*Change la valeur de fusion pour un calque, en lui donnant la valeur donn�e
*/
void changerFusion(Calque * c,int fusion);

/*
*Initialise une liste de calque en rendant tous les pointeurs nuls
*/
Liste_Calque initListe_Calque();

/*
*Retourne 1 si la liste ne contient pas de calque dans le premier �l�ment
*/
int isVideListe_Calque(Liste_Calque liste);

/*
*Rajoute un Node � la liste, en derni�re place
*/
void addNodeCalque(Liste_Calque liste, Node_Calque* node);

/*
*Rajoute un Node contenant un calque blanc
*/
void addNewCalque(Liste_Calque liste);

/*
*Detruit le dernier node de la liste
*/
void deleteLastNodeCalque(Liste_Calque liste);

/*
*Nettoie tous les pointeurs d'une liste
*/
void freeListe_Calque(Liste_Calque liste);

/*
*Fusionne tous les calques d'une liste et en retourne le calque fusionn�
*/
Calque *fusionCalques(Liste_Calque liste);

/*
*Clone un calque sans lui allouer de m�moire adapt�e
*/
Calque cloneCalque(Calque c);

/*
*Clone un calque en lui allouant sa m�moire
*/
Calque* clonePtrCalque(Calque c);

/*
*Effectue un effet sepia (moyenne des couleurs) sur un calque, attention, cette op�ration n'est pas r�versible, on l'effectue donc sur un clone
*/
Calque * SEPIA(Calque c);

/*
*Rajoute un lut dans le tableau de luts d'un calque
1 : ADDLUM
2 : DIMLUM
3 : ADDCON
4 : DIMCON
5 : INVERT
*/
void addLUTCalque(Liste_Calque liste, int choix, float param);

/*
*Applique un tableau de LUT au calque les contenant
*/
void appliquerListeLUTCalque(Calque * c);

/*
*Passe au calque suivant s'il y en a un
*/
Liste_Calque nextCalque(Liste_Calque liste);

/*
*Passe au calque pr�c�dent s'il y en a un
*/
Liste_Calque prevCalque(Liste_Calque liste);

#endif
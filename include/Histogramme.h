/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/

/*
Ce fichier contiendra la définition de la structure Histogramme 
ainsi que les prototype de fonction concernant l'histogramme

*/

#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H
//On inclue le reste du projet
#include "Inclusion.h"

typedef struct Histogramme{
	int val[max_Value];
}Histogramme;

//Permet de générer l'histogramme rvb par rapport à une image
Histogramme* createHisto(Uint8 * rvb,int width, int height);




#endif
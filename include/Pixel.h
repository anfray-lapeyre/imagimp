/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/

/*
Ce fichier contiendra la définition de la structure Pixel
Ainsi que les fonctions nécessaires à son utilisation (et notamment l'addition et la multiplication de 2 pixels superposés)
*/

#ifndef PIXEL_H
#define PIXEL_H
#include <stdlib.h>
#include <stdio.h>

//On utilise bien un unsigned char comme prévu, sous la forme d'un entier
typedef unsigned char Uint8;
typedef struct Calque Calque;

typedef struct Pixel
 {
	//Uint8 = 1 octet = 256 valeurs
   Uint8 r;
   Uint8 v;
   Uint8 b;
   float a;
 } Pixel;
 
//On inclue le reste du projet
#include "Inclusion.h"


//Crée un pixel et le retourne
Pixel createPixel(Uint8 r, Uint8 v, Uint8 b, float a);

//Utilise l'algorithme additif pour superposer 2 pixels
Pixel addPixels(Pixel p1, Pixel p2);

//Utilise l'algorithme additif pour superposer 2 pixels
Pixel multiplyPixels(Pixel p1, Pixel p2);

void LoadImageNB(Calque * calque,const char * chemin);

void afficherImage(Calque * calque);

void SauvegardeImage(Calque * calque, char* addr);
#endif
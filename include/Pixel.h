/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/

/*
Ce fichier contiendra la d�finition de la structure Pixel
Ainsi que les fonctions n�cessaires � son utilisation (et notamment l'addition et la multiplication de 2 pixels superpos�s)
*/

#ifndef PIXEL_H
#define PIXEL_H

//On utilise bien un unsigned char comme pr�vu, sous la forme d'un entier
typedef unsigned char Uint8;


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


//Cr�e un pixel et le retourne
Pixel createPixel(Uint8 r, Uint8 v, Uint8 b, float a);

//Utilise l'algorithme additif pour superposer 2 pixels
Pixel addPixels(Pixel p1, Pixel p2);

//Utilise l'algorithme additif pour superposer 2 pixels
Pixel multiplyPixels(Pixel p1, Pixel p2);


#endif
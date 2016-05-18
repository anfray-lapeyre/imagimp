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
#include <stdlib.h>
#include <stdio.h>

//On utilise bien un unsigned char comme pr�vu, sous la forme d'un entier
typedef unsigned char Uint8;
typedef struct Calque Calque;
#include <stdbool.h>

unsigned char *LoadPPM(const char *nom_fichier, unsigned int *width, unsigned int *height);
bool SaveImage(const char *nom_fichier, Uint8 *rvb, unsigned w, unsigned h);
#endif
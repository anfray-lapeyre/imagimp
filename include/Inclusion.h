/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/

/*
Ce fichier va permettre d'effectuer toutes les inclusions d'un coup
de ce fait, pas besoin d'écrire 15 inclusions à chaque fois
et aucun risque d'en oublier une lorsqu'on rajoute un ficher


Il servira aussi à définir les constantes de notre programme
*/

#ifndef INCLUSION_H
#define INCLUSION_H



#define MIN(x, y) ((x) < (y)) ? (x) : (y)
#define MAX(x, y) ((x) > (y)) ? (x) : (y)
//On rajoute ici les définitions de constantes



#define M_PI 3.1415926535897932384
#define max_Value 256
#define nbButtons 16
#define Image_Width 600
#define Image_Height 400
#define Interface_Width 200
#define ScreenWidth Image_Width+Interface_Width

//Inclusion de tous les fichiers du projet
#include "Buttons.h"
#include "interface.h"
#include "outils.h"
#include "Pixel.h"
#include "LUT.h"
#include "Calque.h"
#include "Histogramme.h"
#include "Image.h"







#endif
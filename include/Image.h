/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/

/*
Ce fichier contiendra la définition de la structure Image, ainsi que des fonctions de contrôle
*/

#ifndef IMAGE_H
#define IMAGE_H
//On inclue le reste du projet
#include "Inclusion.h"










//On utilise bien un unsigned char comme prévu, sous la forme d'un entier
typedef unsigned char Uint8;
typedef struct Node_Calque Node_Calque;
typedef struct Node_Calque * Liste_Calque;
typedef struct Slider Slider;
typedef struct ButtonsList ButtonsList;
//Ne pas donner de nom à la structure permet d'en faire un singleton
struct {
	ButtonsList *buttons;
	Slider * sliderOpacity;
	Liste_Calque base;
	Liste_Calque calques;
	int activeLayerShowed;
	int sepia;
	int printHisto;
}Image;
/*
*Fonction utilisee par la librairie graphique
*/
void kbdFunc(unsigned char c, int x, int y);


/*
*Fonction utilisee par la librairie graphique
*/
void clickMouse(int button,int state,float x,float y);

/*
*Fonction utilisee par la librairie graphique
*/
void mouseMotion(float x, float y, float deltaX, float deltaY, int pressedButton);

/*
*Fonction utilisee par la librairie graphique
*/
void drawImage();

/*
*Sauvegarde dans save.ppm
*/
void Save();

/*
*Quitte le programme
*/
void Quit();

/*
*Rend le calque suivant actif
*/
void Next();

/*
*Rend le calque précédent actif
*/
void Previous();

/*
*Affiche uniquement le calque actif
*/
void afficherCalqueActif();

/*
*Affiche la fusion de tous les calques
*/
void afficherImageComplete();

/*
*Ajoute un LUT addlum au calque actif
*/
void Addlum();

/*
*Ajoute un LUT dimlum au calque actif
*/
void Dimlum();

/*
*Ajoute un LUT addcon au calque actif
*/
void Addcon();

/*
*Ajoute un LUT dimcon au calque actif
*/
void Dimcon();

/*
*Ajoute un LUT invert au calque actif
*/
void Invert();

/*
*Fait un effet sepia sur le calque actif
*/
void Sepia();

/*
*Ajoute un calque a la fin de la liste
*/
void addCalque();

/*
*Affiche l'histogramme en rvb ou cmj
*/
void printHisto();

/*
*Supprime le dernier lut du calque actif
*/
void suppLastLUT();

/*
*Supprime le dernier calque de la liste
*/
void suppLastCalque();

/*
*Rafraichit l'image
*/
void refreshImage();
#endif
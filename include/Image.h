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
struct {
	ButtonsList *buttons;
	Slider * sliderOpacity;
	Liste_Calque base;
	Liste_Calque calques;
	int activeLayerShowed;
	int sepia;
	int printHisto;
}Image;

void kbdFunc(unsigned char c, int x, int y);
void kbdSpFunc(int c, int x, int y);
void clickMouse(int button,int state,float x,float y);
void mouseMotion(float x, float y, float deltaX, float deltaY, int pressedButton);
void drawImage();
void Save();
void Quit();
void Next();
void Previous();
void afficherCalqueActif();
void afficherImageComplete();
void Addlum();
void Dimlum();
void Addcon();
void Dimcon();
void Invert();
void Sepia();
void addCalque();
void printHisto();
void suppLastLUT();
void suppLastCalque();

void refreshImage();
#endif
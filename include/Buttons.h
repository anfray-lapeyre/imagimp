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

#ifndef BUTTONS_H
#define BUTTONS_H
//On inclue le reste du projet
#include "Inclusion.h"


typedef struct Color{
    float r,g,b,a;
} Color;

extern Color makeColor(float r, float g, float b, float a);
extern Color makeInversedColor(Color c);

typedef struct Bounds{
    float x,y,width,height;
    float x2,y2;
} Bounds;

extern Bounds makeBounds(float x, float y, float width, float height);
extern int isInBounds(float x, float y, const Bounds* b);






typedef struct Slider {
    Bounds bounds;
    Bounds cursorBounds;
    Color fore;
    Color back;
    void (*setHandle)(float);
    int hover;
    int press;
    float value;
} Slider;
Slider makeSlider(Bounds bounds, Color fore, Color back,
                  void (*setHandle)(float));
void drawSlider(const Slider* b);
void pressSlider(Slider* b);
void releaseSlider(Slider* b, int activeAction);
void hoverSlider(Slider* b);
void leaveSlider(Slider* b);
void setSliderValue(Slider *b, float value);
void setSliderValueFromPos(Slider* b, float x);


typedef struct Button {
    char* label;
    Bounds bounds;
    Color fore;
    Color back;
    void (*clickHandle)(void);
    int hover;
    int press;
	int right;
} Button;

extern Button makeButton(char* label, Bounds bounds,Color fore, Color back,void (*clickHandle)(void),int right);
extern void drawButton(const Button* b);
extern void pressButton(Button* b);
extern void releaseButton(Button* b, int activeAction);
extern void hoverButton(Button* b);
extern void leaveButton(Button* b);
extern void setButtonLabel(Button *b, char* label);


typedef struct ButtonsList{
    Button* button;
    struct ButtonsList* next;
} ButtonsList;

ButtonsList* makeButtonList(Button* b);
extern void addButton(Button* b, ButtonsList **list);
void freeButtons(ButtonsList* list);

#endif


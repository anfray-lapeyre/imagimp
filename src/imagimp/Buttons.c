/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/
#include "../../include/Buttons.h"

#include <stdio.h>
#include <stdlib.h>

Color makeColor(float r, float g, float b, float a){
    Color c; c.r=r;c.g=g;c.b=b;c.a=a;
    return c;
}

Color makeInversedColor(Color c){
    Color c2;
    c2.r=1.0 - c.r;
    c2.g=1.0 - c.g;
    c2.b=1.0 - c.b;
    c2.a=c.a;
    return c2;
}

Bounds makeBounds(float x, float y, float w, float h){
    Bounds c; c.x=x;c.y=y;c.width=w;c.height=h;
    c.x2 = c.x + c.width;
    c.y2 = c.y + c.height;
    return c;
}

int isInBounds(float x, float y, const Bounds* b){
    return (x>b->x && x<b->x2 && y>b->y && y<b->y2);
}
























/// ///////////////////////////////////////////////////////////////////////////
/// Sliders
/// ///////////////////////////////////////////////////////////////////////////
void makeCursorBounds(Slider* s){
    float height = (float)glutBitmapWidth(GLUT_BITMAP_8_BY_13,'_') * 8./(13.*(float)Image_Height);
    float h = (s->bounds.y2-height) - s->bounds.y;
    s->cursorBounds = makeBounds(s->bounds.x*1.1 + (s->value-0.01) * s->bounds.width*0.8,s->bounds.y+h*0.3,
                                0.016 * s->bounds.width,h*0.5);
}

void makeCursorBoundsSlider(Slider* s){
    float height = (float)glutBitmapWidth(GLUT_BITMAP_8_BY_13,'_') * 8./(13.*(float)Image_Height);
    float h = (s->bounds.y2-height) - s->bounds.y;
    s->cursorBounds = makeBounds(s->bounds.x+0.015 +(s->value) * s->bounds.width*0.8,s->bounds.y+h*0.3,
                                0.05 * s->bounds.width,h*0.5);
}


Slider makeSlider(Bounds bounds, Color fore, Color back,
                  void (*setHandle)(float)){
    Slider s;
    s.bounds = bounds;
    s.fore = fore;
    s.back = back;
    s.setHandle = setHandle;
    s.press = 0;
    s.hover = 0;
    s.value = 1.f;
    makeCursorBoundsSlider(&s);
    return s;
}

void privateDrawSlider(const Slider* s,const Color* foreCursor,const Color* backCursor, const Color* fore){
    float height = (float)glutBitmapWidth(GLUT_BITMAP_8_BY_13,'_') * 8./(13.*(float)Image_Height);
    glColor4f(fore->r,fore->g,fore->b,fore->a);
    float h2 = (s->bounds.y2-height) - s->bounds.y;
    drawLigne(s->bounds.x+0.02,s->bounds.y + h2/2. + height/2.,
              s->bounds.x+s->bounds.width*0.9,s->bounds.y + h2/2. + height/2.);
    writeString(s->bounds.x,s->bounds.y + h2/2,"0");
    writeString(s->bounds.x2,s->bounds.y + h2/2,"100%");
    char* valueStr = malloc(sizeof(char)*6);
    sprintf(valueStr,"%3.2f",s->value*100);
    float width = (float)glutBitmapLength(GLUT_BITMAP_8_BY_13,(unsigned char*)(valueStr))/(float)ScreenWidth;
    writeString(s->bounds.x + s->bounds.width/2. - width/2.,
               s->bounds.y,valueStr);
    glColor4f(backCursor->r,backCursor->g,backCursor->b,backCursor->a);
    drawCarre(s->cursorBounds.x,s->cursorBounds.y,s->cursorBounds.x2,s->cursorBounds.y2);
    glColor4f(foreCursor->r,foreCursor->g,foreCursor->b,foreCursor->a);
    drawCarreVide(s->cursorBounds.x,s->cursorBounds.y,s->cursorBounds.x2,s->cursorBounds.y2);
}

void drawSlider(const Slider *s){

    if(s->press){
        privateDrawSlider(s,&s->back,&s->fore,&s->fore);
    }
    else if(s->hover)
    {
        Color fore = makeColor(s->fore.r+0.2,s->fore.g+0.4,s->fore.b+0.4,s->fore.a);
        privateDrawSlider(s,&fore,&s->back,&s->fore);
    }
    else{
        privateDrawSlider(s,&s->fore,&s->back,&s->fore);
    }

}

void pressSlider(Slider *s){
    s->press = 1;
}

void releaseSlider(Slider *s, int activeAction){
    s->press = 0;
    if(activeAction && s->setHandle!=NULL) (*s->setHandle)(s->value);
}

void hoverSlider(Slider *s){
    s->hover = 1;
}

void leaveSlider(Slider *s){
    s->hover = 0;
}

void setSliderValueFromPos(Slider *b, float x){
    b->value = (x-b->bounds.x-0.02)/(b->bounds.width*0.8);
    b->value = fminf(1,fmaxf(0,b->value));
    makeCursorBoundsSlider(b);
}

void setSliderValue(Slider *b, float value){
    b->value = value;
    b->value = fminf(1,fmaxf(0,b->value));
    makeCursorBoundsSlider(b);
}









/// ///////////////////////////////////////////////////////////////////////////
/// Buttons
/// ///////////////////////////////////////////////////////////////////////////

Button makeButton(char *label, Bounds bounds, Color fore, Color back,
                  void (*clickHandle)(void),int right){
    Button b;
    b.label = malloc(sizeof(char)*strlen(label)+1);
    strcpy(b.label,label);
    b.bounds = bounds;
    b.fore = fore;
    b.back = back;
    b.clickHandle = clickHandle;
    b.press = 0;
    b.hover = 0;
	b.right=right;
    return b;
}

void privateDrawButton(const Button* b,const Color* fore, const Color* back){
    glColor4f(back->r,back->g,back->b,back->a);
    drawCarre(b->bounds.x,b->bounds.y,b->bounds.x2,b->bounds.y2);
    glColor4f(fore->r,fore->g,fore->b,fore->a);
	printf("%f %f %f %f %s\n",fore->r,fore->g,fore->b,fore->a, b->label);
    drawCarreVide(b->bounds.x,b->bounds.y,b->bounds.x2,b->bounds.y2);
    float width = (float)glutBitmapLength(GLUT_BITMAP_8_BY_13,(unsigned char*)(b->label))/(float)ScreenWidth;
    float height = (float)glutBitmapWidth(GLUT_BITMAP_8_BY_13,'_') * 8./(13.*(float)Image_Height);
	printf("%f %f\n",-(b->bounds.x + b->bounds.width/2. - width/2.),
               b->bounds.y + b->bounds.height/2. - height/2.);
    writeString(-(b->bounds.x + b->bounds.width/2. - width/2.-b->right)/125.,
               b->bounds.y + b->bounds.height/2. - height/2.,b->label);
}

void drawButton(const Button *b){
	if(b->press){
		privateDrawButton(b,&b->back,&b->fore);
	}
	else if(b->hover)
	{
		Color fore = makeColor(b->fore.r+0.2,b->fore.g+0.4,
							   b->fore.b+0.4,b->fore.a);
		privateDrawButton(b,&fore,&b->back);
	}
	else{
		privateDrawButton(b,&b->fore,&b->back);
	}
}

void pressButton(Button *b){
    b->press = 1;
}

void releaseButton(Button *b, int activeAction){
    b->press = 0;
    if(activeAction && b->clickHandle!=NULL) (*b->clickHandle)();
}

void hoverButton(Button *b){
    b->hover = 1;
}

void leaveButton(Button *b){
    b->hover = 0;
}



















ButtonsList* makeButtonList(Button *b){
    ButtonsList* list = malloc(sizeof(ButtonsList));
    list->button = b;
    list->next = NULL;
    return list;
}

void addButton(Button *b, ButtonsList **list){
    ButtonsList* temp = *list;
    *list = makeButtonList(b);
    (*list)->next = temp;
}


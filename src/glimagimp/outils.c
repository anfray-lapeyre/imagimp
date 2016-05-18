/***************************************************************************
 *   Copyright (C) 2005 by Venceslas BIRI                                  *
 *   biri@univ-mlv.fr                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "../../include/interface.h"
#include "../../include/outils.h"
#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/// ///////////////////////////////////////////////////////////////////////////
/// Corps des fonctions utilitaires
/// ///////////////////////////////////////////////////////////////////////////
void writeString(float x, float y,  char* s)
{
		char* c;
		glRasterPos2f(x, y);                // set position to start drawing fonts
        for (c=s; *c != '\0'; c++){
            if((*c) == '\n')
            {
                glRasterPos2f(0, 0);                // set position to its initial state
                y -= (float)glutBitmapWidth(GLUT_BITMAP_8_BY_13,'_') * 24./(13.*(float)screenHeight());
                glRasterPos2f(x, y);
            }
            else
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c ); // draw the character to the screen
        }
		glRasterPos2f(0, 0);                // set position to its initial state
}

void writeChar(float x, float y,  char c)
{
        glRasterPos2f(x, y);                // set position to start drawing fonts
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c ); // draw the character to the screen
        glRasterPos2f(0, 0);                // set position to its initial state
}

void fixeCouleur(float r,float v,float b) {
	glColor3f(r,v,b);
}

void drawLigne(float depart_x,float depart_y,float fin_x,float fin_y) {
	glBegin(GL_LINES);
		glVertex3f(depart_x,depart_y,0.0);
		glVertex3f(fin_x,fin_y,0.0);
	glEnd();
}

void drawCarre(float coin_inf_gauche_x,float coin_inf_gauche_y,
								float coin_sup_droit_x,float coin_sup_droit_y) {
	glBegin(GL_QUADS);
		glVertex3f(coin_inf_gauche_x,coin_inf_gauche_y,0.0);
		glVertex3f(coin_sup_droit_x,coin_inf_gauche_y,0.0);
		glVertex3f(coin_sup_droit_x,coin_sup_droit_y,0.0);
		glVertex3f(coin_inf_gauche_x,coin_sup_droit_y,0.0);
	glEnd();
}

void drawCarreVide(float coin_inf_gauche_x,float coin_inf_gauche_y,
								float coin_sup_droit_x,float coin_sup_droit_y) {
	glBegin(GL_LINE_LOOP);
        glVertex3f(coin_inf_gauche_x,coin_inf_gauche_y,0.0);
        glVertex3f(coin_sup_droit_x,coin_inf_gauche_y,0.0);
        glVertex3f(coin_sup_droit_x,coin_sup_droit_y,0.0);
        glVertex3f(coin_inf_gauche_x,coin_sup_droit_y,0.0);
	glEnd();
}

void drawDisque(float centre_x,float centre_y,float rayon) {
	unsigned int i;
	float pas_rad = 2.*M_PI/128.;
    float r = screenWidth()/(float)screenHeight();
	float pas_cour = 0.0;
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(centre_x,centre_y,0.0);
		for(i=0;i<=128;i++) {
            glVertex3f(centre_x+rayon*cos(pas_cour),centre_y+r*rayon*sin(pas_cour),0.0);
			pas_cour += pas_rad;
		}
	glEnd();
}

void drawCercle(float centre_x,float centre_y,float rayon) {
	unsigned int i;
	float pas_rad = 2.0*M_PI/128.;
    float r = screenWidth()/(float)screenHeight();
	float pas_cour = 0.0;
	glBegin(GL_LINE_STRIP);
		for(i=0;i<=128;i++) {
			glVertex3f(centre_x+rayon*cos(pas_cour),centre_y+r*rayon*sin(pas_cour),0.0);
			pas_cour += pas_rad;
		}
	glEnd();
}

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



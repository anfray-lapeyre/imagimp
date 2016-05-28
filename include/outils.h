/***************************************************************************
                          display.h  -  description
                             -------------------
    begin                : Tue 28 Jul 2005
    copyright            : (C) 1999 by Biri
    email                : biri@univ-mlv.fr
 ***************************************************************************/
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

#ifndef _GLIMAGIMP__OUTILS_H___
#define _GLIMAGIMP__OUTILS_H___

#include <stdio.h>
#include <stdlib.h>
//#include <GL/glut.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include "Inclusion.h"

/// ///////////////////////////////////////////////////////////////////////////
/// Prototypes des fonctions utilitaires
/// ///////////////////////////////////////////////////////////////////////////
// Ecrit une chaine de caractère (s) en position x,y
void writeString(float x, float y, char* s);
// Fixe la couleur d'écriture
// r,v,b sont des flotants compris entre 0 et 1
void fixeCouleur(float r,float v,float b);
// Trace une ligne dans la couleur d'écriture
// depart_x,depart_y : coordonnées du point de départ
// fin_x,fin_y : coordonnées du point d'arrivée
void drawLigne(float depart_x,float depart_y,float fin_x,float fin_y);
// Trace un carre plein de la couleur courante
// coin_inf_gauche_x,coin_inf_gauche_y : coordonnees du point en bas a gauche
// coin_sup_droit_x,coin_sup_droit_y :  coordonnees du point en haut a droite
void drawCarre(float coin_inf_gauche_x,float coin_inf_gauche_y,
								float coin_sup_droit_x,float coin_sup_droit_y);
// Trace un carre de la couleur courante
// coin_inf_gauche_x,coin_inf_gauche_y : coordonnees du point en bas a gauche
// coin_sup_droit_x,coin_sup_droit_y :  coordonnees du point en haut a droite
void drawCarreVide(float coin_inf_gauche_x,float coin_inf_gauche_y,
								float coin_sup_droit_x,float coin_sup_droit_y);
// Trace un disque de la couleur courante
// centre_x,centre_y : coordonnees du centre
// rayon : rayon du disque (defini en pourcentage de la largeur)
void drawDisque(float centre_x,float centre_y,float rayon);
// Trace un cercle de la couleur courante
// centre_x,centre_y : coordonnees du centre
// rayon : rayon du cercle (defini en pourcentage de la largeur)
void drawCercle(float centre_x,float centre_y,float rayon);

#endif

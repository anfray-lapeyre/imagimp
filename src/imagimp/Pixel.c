/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/
#include "../../include/Pixel.h"
unsigned char *LoadPPM(const char *nom_fichier, unsigned int *width, unsigned int *height) {

    FILE *fichier = fopen(nom_fichier, "rb");
    if(!fichier) {
        fprintf(stderr, "%s: N'a pas pu ouvrir le fichier.\n", nom_fichier);
        return NULL;
    }

    char car;
    unsigned variante, valeur_max;
    unsigned etape=0;
    char* buffer = malloc(sizeof(char)*BUFSIZ);
    while(etape<3){
        memset(buffer,0,BUFSIZ);
        fgets(buffer,BUFSIZ,fichier);
        if(!buffer[0])
            return NULL;
        if(buffer[0] == '#') {
            printf("commentaire :%s\n",buffer+1);
            continue;
        }
        switch(etape) {
        case 0: if(sscanf(buffer, "P%u", &variante)<1)
                    return NULL;
                etape++;
                break;
        case 1: if(sscanf(buffer, "%u %u", width, height)<2)
                    return NULL;
                etape++;
                break;
        case 2: if(sscanf(buffer, "%u", &valeur_max)<1)
                    return NULL;
                etape++;
                break;
        }
    }

    char *rgb = malloc(3*(*width)*(*height)), *gris;
    if(!rgb) {
        fprintf(stderr, "%s: Pas de place pour allouer les pixels.\n", nom_fichier);
        return NULL;
    }
    size_t i;
    switch(variante) {
    case 6:
        fread(rgb, 1, 3*(*width)*(*height), fichier);
        break;
    case 5:
        gris = malloc((*width)*(*height));
        if(!gris) {
            fprintf(stderr, "%s: Pas de place pour allouer le gris.\n", nom_fichier);
            free(rgb);
            return NULL;
        }
        fread(gris, 1, (*width)*(*height), fichier);
        for(i=0 ; i<(*width)*(*height) ; i++)
            rgb[3*i] = rgb[3*i+1] = rgb[3*i+2] = gris[i];
        free(gris);
        break;
    }
    fclose(fichier);
    return (unsigned char*)rgb;
}

bool SaveImage(const char *nom_fichier, unsigned char *rvb, unsigned w, unsigned h) {
    FILE *fichier = fopen(nom_fichier, "wb");
    if(!fichier) {
        fprintf(stderr, "%s: Ne peut pas ouvrir le fichier en écriture.\n", nom_fichier);
        return false;
    }
    fprintf(fichier, "P6\n%u %u\n255\n", w, h);
    fwrite(rvb, 1, 3*w*h, fichier);
    fclose(fichier);
    return true;
}
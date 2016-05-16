/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/
#include "../include/Pixel.h"

void LoadImageNB(Calque * calque,const char * chemin){
	if(NULL != calque){
		printf("%s\n",chemin);
		FILE* F;
		F = fopen(chemin,"r");
		if (!F)
		{
			printf("fichier %s introuvable !! \n",chemin);
			exit(-1);
		}
		fscanf(F,"%d %d",&calque->width,&calque->height);
		calque->image = malloc(calque->width*sizeof(Pixel*)); //Des Uint16 suffisent largement
		for(int i=0;i<calque->width;i++)
			calque->image[i] = malloc(calque->height*sizeof(Pixel));
		printf("TEST");
		for(int j=0;j<calque->height;j++)
		{
			for(int i=0;i<calque->width;i++)
			{
				int tmp;
				fscanf(F,"%d",&tmp);
				if (tmp>255)
				{
					printf("Valeur incorrecte\n");
					exit(-1);
				}
				calque->image[i][j].r = tmp;
				
			}
		}
	}
	else{
		exit(-1);
	}
}


void afficherImage(Calque * calque){
	if(NULL != calque){
		for(int j=0;j<calque->height;j++)
		{
			for(int i=0;i<calque->width;i++)
			{
				printf("%d\t",calque->image[i][j].r);
				
			}
			printf("\n");
		}
	}
	else{
		exit(-1);
	}
}


void SauvegardeImage(Calque * calque, char* addr){
	FILE * f=fopen(addr,"w+");
	
	if(NULL != calque){
		fprintf(f,"%d\t%d\n",calque->width, calque->height);
		for(int j=0;j<calque->height;j++)
		{
			for(int i=0;i<calque->width;i++)
			{
				fprintf(f,"%d\t",calque->image[i][j].r);
				
			}
			fprintf(f,"\n");
		}
	}

	fclose(f);
}
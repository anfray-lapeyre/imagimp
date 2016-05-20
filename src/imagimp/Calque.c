/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/
#include "../../include/Calque.h"

Calque creerCalque(int width, int height){
	Calque res;
	res.width=width;
	res.height=height;
	res.fusion=0;
	res.opacity=1.;
	return res;
	
}

void changerOpacite(Calque * c, float new_opacity){
	if(NULL == c)
		return;
	if(new_opacity<=1 && new_opacity>=0)
		c->opacity=new_opacity;
}

void changerFusion(Calque * c,int fusion){
	if(NULL == c)
		return;
	c->fusion=fusion;
}

Liste_Calque initListe_Calque(){

	Liste_Calque liste = malloc(sizeof(Node_Calque));
	liste->next = NULL;
	liste->previous = NULL;

	liste->calque = NULL;

	return liste;
}

int isVideListe_Calque(Liste_Calque liste){

	return NULL == liste->calque;
}

void addNodeCalque(Liste_Calque liste, Node_Calque* node){

	if(NULL == liste){
		return;
	}

	if(isVideListe_Calque(liste)){
		*(liste->calque)=cloneCalque(*node->calque);
		free(node);
		return;
	}
	
	Liste_Calque tmp=liste;
	while(tmp->next != NULL){
		tmp=tmp->next;
	}
	tmp->next=node;
	node->previous=tmp;
	node->next=NULL;
	
}

void addNewCalque(Liste_Calque liste){
	if(NULL == liste){
		return;
	}
	Node_Calque * c = malloc(sizeof(Node_Calque));
	c->calque=malloc(sizeof(Calque));
	if(isVideListe_Calque(liste)){
		*c->calque=creerCalque(600,400);	
	}else{
		*c->calque=creerCalque(liste->calque->width,liste->calque->height);
	}
	c->calque->rvb=malloc(sizeof(Uint8)*c->calque->height*c->calque->width*3);
	for(int i=0;i<c->calque->height*c->calque->width*3;i++){
		c->calque->rvb[i]=255;
	}
	addNodeCalque(liste,c);
}

void deleteLastNodeCalque(Liste_Calque liste){

	if(NULL == liste || isVideListe_Calque(liste)){
		return;
	}

	if(liste->next == NULL ){
		liste->previous = NULL;
		free(liste->calque);

		return;
	}

	Node_Calque * tmp=liste;
	while(tmp->next != NULL){
		tmp=tmp->next;
	}
	free(tmp->next);
	tmp->next=NULL;
	
}

void freeListe_Calque(Liste_Calque liste){
	if(liste == NULL)
		return;
	if(liste->next == NULL){
		free(liste);
		return;
	}
	Liste_Calque tmp=liste->next;
	while(tmp->next != NULL){
		free(tmp->previous);
		tmp=tmp->next;
		
	}
}

Calque * fusionCalques(Liste_Calque liste){
	if(liste == NULL || isVideListe_Calque(liste))
		return NULL;
	Calque * fusion = malloc(sizeof(Calque));
	*fusion=cloneCalque(*liste->calque);
	Liste_Calque tmp = liste;
	if(tmp->next != NULL){
		tmp=tmp->next;
		if(tmp->calque->fusion == 0){
			for(int i=0;i<fusion->width*fusion->height*3;i++){
				fusion->rvb[i]+=tmp->calque->fusion*tmp->calque->rvb[i];
			}
		}else{
			for(int i=0;i<fusion->width*fusion->height*3;i++){
				fusion->rvb[i]=tmp->calque->opacity*tmp->calque->rvb[i]+(1-tmp->calque->opacity)*fusion->rvb[i];
			}
		}
	}
	return fusion;
}

Calque cloneCalque(Calque c){

	Calque clone ;
	clone.width=c.width;
	clone.height=c.height;
	clone.fusion=c.fusion;
	clone.opacity=c.opacity;
	clone.rvb=malloc(sizeof(Uint8)*clone.width*clone.height*3);
	for(int i=0;i<clone.width*clone.height*3;i++){
		clone.rvb[i]=c.rvb[i];
	}
	return clone;
}

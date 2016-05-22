/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/
#include "../../include/Calque.h"
#include "../../include/LUT.h"

Calque creerCalque(int width, int height){
	Calque res;
	res.width=width;
	res.height=height;
	res.fusion=0;
	res.opacity=1.;
	res.rvb = NULL;
	res.luts=initListe_LUT();
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
		liste->calque=malloc(sizeof(Calque));
		*(liste->calque)=cloneCalque(*(node->calque));
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
		*(c->calque)=creerCalque(600,400);	

	}else{
		*(c->calque)=creerCalque(liste->calque->width,liste->calque->height);
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
		freeListe_LUT(liste->calque->luts);
		free(liste->calque->luts);
		free(liste->calque);

		liste->calque=NULL;
		return;
	}
	Node_Calque * tmp=liste;
	while(tmp->next != NULL){
		tmp=tmp->next;
	}
	freeListe_LUT(tmp->calque->luts);
	free(tmp->calque->luts);
	free(tmp->calque);
	tmp=tmp->previous;
	free(tmp->next);
	tmp->next=NULL;
}

void freeListe_Calque(Liste_Calque liste){
	if(liste == NULL)
		return;
	while(!isVideListe_Calque(liste)){
		deleteLastNodeCalque(liste);
	}
	free(liste);
}

Calque * fusionCalques(Liste_Calque liste){
	if(liste == NULL || isVideListe_Calque(liste))
		return NULL;
	Calque * fusion;
	fusion = clonePtrCalque(*(liste->calque));
	for(int i=0;i<fusion->width*fusion->height*3;i++){
		fusion->rvb[i]=0;
	}
	Liste_Calque tmp = liste;
	appliquerListeLUTCalque(liste->calque);
	if(tmp->calque->fusion == 0){
		for(int i=0;i<fusion->width*fusion->height*3;i++){
			fusion->rvb[i]=MIN(255,tmp->calque->opacity*tmp->calque->rvb[i]+(1-tmp->calque->opacity)*fusion->rvb[i]);

		}
	}else{
		for(int i=0;i<fusion->width*fusion->height*3;i++){
			fusion->rvb[i]=MIN(255,fusion->rvb[i]+tmp->calque->opacity*tmp->calque->rvb[i]);

		}
	}

	while(tmp->next != NULL){
	
		tmp=tmp->next;
		appliquerListeLUTCalque(tmp->calque);
		if(tmp->calque->fusion == 0){
			for(int i=0;i<fusion->width*fusion->height*3;i++){
				fusion->rvb[i]=MIN(255,tmp->calque->opacity*tmp->calque->rvb[i]+(1-tmp->calque->opacity)*fusion->rvb[i]);

			}
		}else{
			for(int i=0;i<fusion->width*fusion->height*3;i++){
				fusion->rvb[i]=MIN(255,fusion->rvb[i]+tmp->calque->opacity*tmp->calque->rvb[i]);

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
	clone.luts=cloneListeLUTS(c.luts);
	return clone;
}

Calque* clonePtrCalque(Calque c){
	Calque* clone =malloc(sizeof(Calque));
	clone->width=c.width;
	clone->height=c.height;
	clone->fusion=c.fusion;
	clone->opacity=c.opacity;
	clone->rvb=malloc(sizeof(Uint8)*clone->width*clone->height*3);
	for(int i=0;i<clone->width*clone->height*3;i++){
		clone->rvb[i]=c.rvb[i];
	}
	clone->luts=cloneListeLUTS(c.luts);
	return clone;
	
}

Calque * SEPIA(Calque c){
	Calque * res=clonePtrCalque(c);
	for(int i=0;i<res->width*res->height-1;i++)
	{
		res->rvb[i*3]=(res->rvb[i*3]+res->rvb[i*3+1]+res->rvb[i*3+2])/3;
		res->rvb[i*3+1]=(res->rvb[i*3]+res->rvb[i*3+1]+res->rvb[i*3+2])/3;
		res->rvb[i*3+2]=(res->rvb[i*3]+res->rvb[i*3+1]+res->rvb[i*3+2])/3;
	}
	return res;
}

void addLUTCalque(Liste_Calque liste, int choix, float param){
	if(NULL == liste || isVideListe_Calque(liste)){
		return;
	}
	LUT lut=creerLUT();

	switch(choix){
		case 0 : 
		break;
		case 1 : 
			ADDLUM(&lut,param);
		break;
		case 2 : 
			DIMLUM(&lut,param);
		break;
		case 3 : 
			ADDCON(&lut,param);
		break;
		case 4 : 
			DIMCON(&lut,param);
		break;
		case 5 : 
			INVERT(&lut);
		break;
		
		default:
		
		break;
	}
	addNodeLUT(liste->calque->luts,lut);
}

void appliquerListeLUTCalque(Calque * c){
	if(NULL == c || NULL == c->luts || isVideListe_LUT(c->luts))
		return;
	LUT * fusion = fusionListeLUT(c->luts);
	Calque tmp= appliquerLUT(fusion,*c);
	for(int i=0;i<tmp.width*tmp.height*3;i++){
		c->rvb[i]=tmp.rvb[i];
	}
	
}

void retirerLUTCalque(Liste_Calque liste){
	deleteLastNodeLUT(liste->calque->luts);
}

Liste_Calque nextCalque(Liste_Calque liste){
	if(NULL == liste || NULL == liste->next){
		return liste;
	}
	return liste->next;
}

Liste_Calque prevCalque(Liste_Calque liste){
	if(NULL == liste || NULL == liste->previous){
		return liste;
	}
	return liste->previous;
}

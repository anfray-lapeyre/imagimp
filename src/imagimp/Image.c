/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/
#include "../../include/Image.h"
#include <unistd.h>







void initImage(int argc,char ** argv){
	Calque test=creerCalque(0,0);
	if(argc>1){
		if( access( argv[1], F_OK ) != -1 ){
			test.rvb=LoadPPM(argv[1],&(test.width),&(test.height));
			
		}
		else{
			printf("\nThis file does not exists, please try again with an existing file.\n");
			return;
		}
	}
	else{
		test.rvb=LoadPPM("resources/Embryos.512.ppm",&(test.width),&(test.height));
	}
	
   
	Image.calques = initListe_Calque();
	Image.base=Image.calques;

	Node_Calque * node = malloc(sizeof(Node_Calque));

	node->calque = clonePtrCalque(test);
	addNodeCalque(Image.calques, node);
	initGLIMAGIMP_IHM(test.width,test.height,test.rvb,Image_Width+Interface_Width,Image_Height,0);
	fixeFonctionClicSouris(clickMouse);
	fixeFonctionClavier(kbdFunc);
	fixeFonctionMotionSouris(mouseMotion);
	fixeFonctionDessin(drawImage);
	
	
	 float startX = 0.79;
    float btnsizeX = 0.199f;
    float btnsizeY = 0.04f;
	Button * buttons = malloc(sizeof(Button)*nbButtons);
	buttons[0]=makeButton("Sauvegarder",makeBounds(startX,0.1f,btnsizeX,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),Save,0);
	buttons[1]=makeButton("Quitter",makeBounds(startX,0.05f,btnsizeX,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),Quit,0);
	buttons[2]=makeButton("Histogramme",makeBounds(startX,0.15f,btnsizeX,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),printHisto,0);
	buttons[3]=makeButton("Sepia",makeBounds(startX+btnsizeX/2+0.001,0.25f,btnsizeX/2,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),Sepia,13);
	buttons[4]=makeButton("Col. Inv.",makeBounds(startX-0.001,0.25f,btnsizeX/2,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),Invert,0);
	buttons[5]=makeButton("DIMCON",makeBounds(startX+btnsizeX/2+0.001,0.3f,btnsizeX/2,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),Dimcon,13);
	buttons[6]=makeButton("ADDCON",makeBounds(startX-0.001,0.3f,btnsizeX/2,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),Addcon,0);
	buttons[7]=makeButton("DIMLUM",makeBounds(startX+btnsizeX/2+0.001,0.35f,btnsizeX/2,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),Dimlum,13);
	buttons[8]=makeButton("ADDLUM",makeBounds(startX-0.001,0.35f,btnsizeX/2,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),Addlum,0);
	buttons[9]=makeButton("Aff. Calque Actif",makeBounds(startX,0.78f,btnsizeX,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),afficherCalqueActif,0);
	buttons[10]=makeButton("Aff. Projet entier",makeBounds(startX,0.83f,btnsizeX,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),afficherImageComplete,0);
	buttons[11]=makeButton("Nouveau Calque",makeBounds(startX,0.7f,btnsizeX,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),addCalque,0);
	buttons[12]=makeButton("C. Suivant",makeBounds(startX,0.9f,btnsizeX,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),Next,0);
	buttons[13]=makeButton("C. Préc.",makeBounds(startX,0.95f,btnsizeX,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),Previous,0);
	buttons[14]=makeButton("Supp. dernier LUT",makeBounds(startX,0.65f,btnsizeX,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),suppLastLUT,0);
	buttons[15]=makeButton("Supp. dernier Calq.",makeBounds(startX,0.60f,btnsizeX,btnsizeY),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),suppLastCalque,0);
	Image.sliderOpacity=malloc(sizeof(Slider));
	*(Image.sliderOpacity) = makeSlider(makeBounds(startX,0.35+0.35/3,0.15,0.35/5),makeColor(0.7,0.7,0.7,1),makeColor(0,0,0,0),NULL);
	// Histogramme * histo = createHisto(test.rvb,test.width, test.height);
	// test=HistoToImage(*histo);
	Image.buttons=makeButtonList(&buttons[0]);
	for(int i=0;i<nbButtons;i++){
		addButton(&buttons[i],&Image.buttons);

	}
	Image.activeLayerShowed=0;
	Image.sepia=0;
	Image.printHisto=0;
		/* Ready to go! */
	setFullsreen(0);
	launchApp();
}


/// ///////////////////////////////////////////////////////////////////////////
/// fonction associée aux interruptions clavier
/// - c : caractère saisi
/// - x,y : coordonnée du curseur dans la fenetre
void kbdFunc(unsigned char c, int x, int y) {
	char saisie[100] = {'\0'};
	float val;
	Calque * test2;
	switch(c) {
		case 'd': 
			printf("Debraillement sur le terminal\n");
			printf("Merci de rentrer une chaine de caractère :");
			scanf("%s",saisie);
			printf("On a tape %s\n",saisie);
			printf("Chargement de l'image\n");
			Calque test=creerCalque(0,0);
			if( access( saisie, F_OK ) != -1 ){
				test.rvb=LoadPPM(saisie,&(test.width),&(test.height));
			}
			else{
				printf("\nThis file does not exists, please try again with an existing file.\n");
				return;
			}
			
			Node_Calque * node = malloc(sizeof(Node_Calque));

			node->calque = clonePtrCalque(test);
			addNodeCalque(Image.calques, node);
			break;
		case 'f': 
			printf("Debraillement sur le terminal\n");
			printf("Merci de rentrer une chaine de caractère :");
			scanf("%s",saisie);
			printf("On a tape %s\n",saisie);
			printf("Chargement de l'image\n");
			Calque test3=creerCalque(0,0);
			if( access( saisie, F_OK ) != -1 ){
				test3.rvb=LoadPPM(saisie,&(test3.width),&(test3.height));
			}
			else{
				printf("\nThis file does not exists, please try again with an existing file.\n");
				return;
			}
			
		   
			Image.calques = initListe_Calque();
			Image.base=Image.calques;
			Node_Calque * node1 = malloc(sizeof(Node_Calque));

			node1->calque = clonePtrCalque(test3);
			addNodeCalque(Image.calques, node1);
		break;
		case 'g': 
			if(Image.activeLayerShowed==1)
				afficherImageComplete();
			else{
				afficherCalqueActif();
			}
		break;
		case 's': 
			printf("Debraillement sur le terminal\n");
			printf("Merci de rentrer une chaine de caractère :");
			scanf("%s",saisie);
			printf("On a tape %s\n",saisie);

			printf("Sauvegarde de l'image\n");
			if(Image.activeLayerShowed){ //Calque actif affiché
				test2=clonePtrCalque(*(Image.calques->calque));//fusionCalques(Image.calques);
				appliquerListeLUTCalque(test2);
				
			}else{ //Tous les calques
				test2=fusionCalques(Image.base);
			}
			if(Image.sepia){
				test2=SEPIA(*test2);
			}
			if(Image.printHisto==1){
				Histogramme * histo = createHisto(test2->rvb,test2->width, test2->height);
				*test2=HistoToImageRVB(*histo);
			}else if(Image.printHisto==2){
				Histogramme * histo = createHisto(test2->rvb,test2->width, test2->height);
				*test2=HistoToImageCMJ(*histo);
			}
			SaveImage(saisie,test2->rvb,Image.calques->calque->width,Image.calques->calque->height);
			break;
		case 'h': // Touche Histo
			printf("Histogramme\n");
			printHisto();
			break;
		case 'i': 
			printf("LUT Inversion de couleur\n");
			Invert();
			break;
		case 'n': 
			printf("Ajout calque vierge\n");
			addCalque();
			break;
		case 'q':
			Quit();
			break;
		case ':': 
			printf("Calque precedent\n");
			Previous();
			break;
		case '!': 
			printf("Calque suivant\n");
			Next();
			break;
		case 'a': 
			printf("Supprimer dernier LUT\n");
			suppLastLUT();
			break;
		case 'z': 
			printf("Supprimer dernier calques\n");
			suppLastCalque();
			break;
		case 'e': 
			printf("Opacite\n");
			printf("Veuillez saisir une valeur entre 0 et 1\n");
			scanf("%f",&val);
			if(val<=1 && val>=0)
				Image.calques->calque->opacity=val;
			break;
		case 'r': 
			printf("LUT Luminosité\n");
			printf("Veuillez saisir une valeur entre -100 et 100\n");
			scanf("%f",&val);
			if(val>0)
				addLUTCalque(Image.calques, 1, val);
			else
				addLUTCalque(Image.calques, 2, -val);
			
			break;
		case 't': 
			printf("LUT Contraste\n");
			printf("Veuillez saisir une valeur entre 0 et 127\n");
			scanf("%f",&val);
			if(val>0 && val<=1)
				addLUTCalque(Image.calques, 4, val);
			else if(val>1)
				addLUTCalque(Image.calques, 3, val);
			break;
		case 'y': 
			printf("Sepia\n");
			Sepia();
			break;
		case 'm': 
			printf("Changement du mode de fusion\n");
			if(Image.calques->calque->fusion == 1)
				changerFusion(Image.calques->calque,0);
			else
				changerFusion(Image.calques->calque,1);
			break;
		default :
			printf("Touche non fonctionnelle\n");
	}
	refreshImage();
}



/// ///////////////////////////////////////////////////////////////////////////
/// fonction associée aux evenements souris
/// - x,y : coordonnée de la souris dans la fenêtre
void clickMouse(int button,int state,float x,float y){
	
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_UP){ // state == GLUT_UP
			ButtonsList* tmp = Image.buttons;
			
			while(tmp->next != NULL){
				if(isInBounds(x,y,&(tmp->button->bounds)) && tmp->button->press ==1){
					printf("%s\n",tmp->button->label);
					releaseButton(tmp->button,1);
					refreshImage();
					break;
				}
				tmp=tmp->next;
			}
			
		}else{
			ButtonsList* tmp = Image.buttons;
			
			while(tmp->next != NULL){
				if(isInBounds(x,y,&(tmp->button->bounds)) && tmp->button->press ==0){
					pressButton(tmp->button);
					refreshImage();
					break;
				}
				
				tmp=tmp->next;
			}
		}
	}
	
}


void mouseMotion(float x, float y, float deltaX, float deltaY, int pressedButton) {
    //isInBounds
	ButtonsList* tmp = Image.buttons;
			
	while(tmp->next != NULL){
		if(isInBounds(x+deltaX,y+deltaY,&(tmp->button->bounds))){
			hoverButton(tmp->button);
			refreshImage();
			break;
		}else{
			if(tmp->button->hover){
				leaveButton(tmp->button);
				refreshImage();
				break;
			}
		}
		tmp=tmp->next;
	}
	unsigned char sliderHover = isInBounds(x,y,&Image.sliderOpacity->cursorBounds);
    if(sliderHover){
        if (pressedButton == GLUT_DOWN) {
             pressSlider(Image.sliderOpacity);
        }
        else{
             releaseSlider(Image.sliderOpacity,1);
        }
		refreshImage();
    }
    else{
        if (pressedButton == GLUT_DOWN) {
             if(isInBounds(x,y,&Image.sliderOpacity->bounds)){
                  setSliderValueFromPos(Image.sliderOpacity,x);
				  Image.calques->calque->opacity=Image.sliderOpacity->value;
             }
        }else{
			  releaseSlider(Image.sliderOpacity,1);

		}
		refreshImage();
    }
}

void drawImage(){
	ButtonsList* tmp=Image.buttons;
	while(tmp != NULL){
		drawButton(tmp->button);
		tmp=tmp->next;
	}
	drawSlider(Image.sliderOpacity);
}

void Save(){
	Calque * test2;
	printf("Sauvegarde de l'image\n");
	if(Image.activeLayerShowed){ //Calque actif affiché
		test2=clonePtrCalque(*(Image.calques->calque));//fusionCalques(Image.calques);
		appliquerListeLUTCalque(test2);
		
	}else{ //Tous les calques
		test2=fusionCalques(Image.base);
	}
	if(Image.sepia){
		test2=SEPIA(*test2);
	}
	if(Image.printHisto==1){
		Histogramme * histo = createHisto(test2->rvb,test2->width, test2->height);
		*test2=HistoToImageRVB(*histo);
	}else if(Image.printHisto==2){
		Histogramme * histo = createHisto(test2->rvb,test2->width, test2->height);
		*test2=HistoToImageCMJ(*histo);
	}
	SaveImage("save.ppm",test2->rvb,Image.calques->calque->width,Image.calques->calque->height);
}

void Quit(){
	printf("Sortie d'imagimp\n");
	freeListe_Calque(Image.base);
	freeButtons(Image.buttons);
	free(Image.sliderOpacity);
	exit(0);
}

void Next(){
	Image.calques=nextCalque(Image.calques);
	
}
void Previous(){
	Image.calques=prevCalque(Image.calques);
}

void afficherCalqueActif(){
	Image.activeLayerShowed=1;
}
void afficherImageComplete(){
	Image.activeLayerShowed=0;
}

void Addlum(){
	addLUTCalque(Image.calques, 1, 20.);
}
void Dimlum(){
	addLUTCalque(Image.calques, 2, 20.);
}
void Addcon(){
	addLUTCalque(Image.calques, 3, 2);
}
void Dimcon(){
	addLUTCalque(Image.calques, 4, 0.5);
}
void Invert(){
	addLUTCalque(Image.calques, 5, 0.);
}
void Sepia(){
	
	if(Image.sepia==1)
		Image.sepia=0;
	else
		Image.sepia=1;
}

void addCalque(){
	addNewCalque(Image.calques);
	Image.calques=Image.calques->next;
}

void printHisto(){
	Image.printHisto=(Image.printHisto+1)%3;
}
void suppLastLUT(){
	
	deleteLastNodeLUT(Image.calques->calque->luts);
}
void suppLastCalque(){
	if(Image.base->next != NULL)
		deleteLastNodeCalque(Image.base);
}

void refreshImage(){
	Calque * test2;

	if(Image.activeLayerShowed){ //Calque actif affiché
		test2=clonePtrCalque(*(Image.calques->calque));//fusionCalques(Image.calques);
		appliquerListeLUTCalque(test2);
		
	}else{ //Tous les calques
		test2=fusionCalques(Image.base);
	}
	if(Image.sepia){
		test2=SEPIA(*test2);
	}
	if(Image.printHisto==1){
		Histogramme * histo = createHisto(test2->rvb,test2->width, test2->height);
		*test2=HistoToImageRVB(*histo);
	}else if(Image.printHisto==2){
		Histogramme * histo = createHisto(test2->rvb,test2->width, test2->height);
		*test2=HistoToImageCMJ(*histo);
	}
	actualiseImage(test2->rvb,test2->width,test2->height);
	// int sepia;
	// int printHisto;
}


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
			return 1;
		}
	}
	else{
		test.rvb=LoadPPM("resources/Embryos.512.ppm",&(test.width),&(test.height));
	}
	
   
	Image.calques = initListe_Calque();

	Node_Calque * node = malloc(sizeof(Node_Calque));

	node->calque = clonePtrCalque(test);
	addNodeCalque(Image.calques, node);
	addNewCalque(Image.calques);
	addLUTCalque(Image.calques->next, 2, 200.);
	changerOpacite(Image.calques->next->calque,0.7);
	
	initGLIMAGIMP_IHM(test.width,test.height,test.rvb,Image_Width+Interface_Width,Image_Height,0);
	fixeFonctionClicSouris(clickMouse);
	fixeFonctionClavier(kbdFunc);
	fixeFonctionClavierSpecial(kbdSpFunc);
	fixeFonctionMotionSouris(mouseMotion);
	fixeFonctionDessin(drawImage);
	
	
	 float startX = getUIStartX() + 0.01;
    float btnsizeX = 0.199f;
    float btnsizeY = 0.04f;
	Button * buttons = malloc(sizeof(Button)*nbButtons);
	buttons[0]=makeButton("Sauvegarder",makeBounds(startX,0.1f,btnsizeX,btnsizeY),makeColor(1,1,1,1),makeColor(0,0,0,0),Save);
	buttons[1]=makeButton("Quitter",makeBounds(startX,0.05f,btnsizeX,btnsizeY),makeColor(1,1,1,1),makeColor(0,0,0,0),Quit);
	buttons[2]=makeButton("Histogramme",makeBounds(startX,0.15f,btnsizeX,btnsizeY),makeColor(1,1,1,1),makeColor(0,0,0,0),printHisto);
	buttons[3]=makeButton("Sepia",makeBounds(startX+btnsizeX/2+0.001,0.25f,btnsizeX/2,btnsizeY),makeColor(1,1,1,1),makeColor(0,0,0,0),Sepia);
	buttons[4]=makeButton("Col. Inv.",makeBounds(startX-0.001,0.25f,btnsizeX/2,btnsizeY),makeColor(1,1,1,1),makeColor(0,0,0,0),Invert);
	buttons[5]=makeButton("DIMCON",makeBounds(startX+btnsizeX/2+0.001,0.3f,btnsizeX/2,btnsizeY),makeColor(1,1,1,1),makeColor(0,0,0,0),Dimcon);
	buttons[6]=makeButton("ADDCON",makeBounds(startX-0.001,0.3f,btnsizeX/2,btnsizeY),makeColor(1,1,1,1),makeColor(0,0,0,0),Addcon);
	buttons[7]=makeButton("DIMLUM",makeBounds(startX+btnsizeX/2+0.001,0.35f,btnsizeX/2,btnsizeY),makeColor(1,1,1,1),makeColor(0,0,0,0),Dimlum);
	buttons[8]=makeButton("ADDLUM",makeBounds(startX-0.001,0.35f,btnsizeX/2,btnsizeY),makeColor(1,1,1,1),makeColor(0,0,0,0),Addlum);
	buttons[9]=makeButton("Aff. Calque Actif",makeBounds(startX,0.78f,btnsizeX,btnsizeY),makeColor(1,1,1,1),makeColor(0,0,0,0),afficherCalqueActif);
	buttons[10]=makeButton("Aff. Projet entier",makeBounds(startX,0.83f,btnsizeX,btnsizeY),makeColor(1,1,1,1),makeColor(0,0,0,0),afficherImageComplete);
	buttons[11]=makeButton("Nouveau Calque",makeBounds(startX,0.7f,btnsizeX,btnsizeY),makeColor(1,1,1,1),makeColor(0,0,0,0),addCalque);
	buttons[12]=makeButton("C. Suivant",makeBounds(startX,0.9f,btnsizeX,btnsizeY),makeColor(1,1,1,1),makeColor(0,0,0,0),Next);
	buttons[13]=makeButton("C. Préc.",makeBounds(startX,0.95f,btnsizeX,btnsizeY),makeColor(1,1,1,1),makeColor(0,0,0,0),Previous);
	// Histogramme * histo = createHisto(test.rvb,test.width, test.height);
	// test=HistoToImage(*histo);
	Image.buttons=makeButtonList(&buttons[0]);
	for(int i=0;i<nbButtons;i++){
		addButton(&buttons[i],&Image.buttons);

	}
	Image.activeLayerShowed=0;
	Image.sepia=0;
	Image.printHisto=0;
	
	
	setFullsreen(0);
	launchApp();
}


/// ///////////////////////////////////////////////////////////////////////////
/// fonction associée aux interruptions clavier
/// - c : caractère saisi
/// - x,y : coordonnée du curseur dans la fenetre
void kbdFunc(unsigned char c, int x, int y) {
	char saisie[100] = {'\0'};
	printf("Touche tapee %c (coord souris %d/%d)\n",c,x,y);
	switch(c) {
		case 't': // Exemple de saisie sur le terminal
			printf("Debraillement sur le terminal\n");
			printf("Merci de rentrer une chaine de caractère :");
			scanf("%s",saisie);
			printf("On a tape %s\n",saisie);
			break;
		case 'i': // Exemple d'utilisation des fonctions de la bibliotheque glimagimp
			printInfo();
			break;
		case 's': // Exemple d'utilisation des fonctions de la bibliotheque glimagimp
			// if (!switch_image)
				// actualiseImage(image_switch);
			// else
				// actualiseImage(image_base);
			// switch_image = 1-switch_image;
			break;
		case 27: // Touche Escape
			printf("Fin du programme\n");
			exit(0);
			break;
		default :
			printf("Touche non fonctionnelle\n");
	}
}

/// ///////////////////////////////////////////////////////////////////////////
/// fonction associée aux interruptions clavier speciales
/// - c : caractère saisi
/// - x,y : coordonnée du curseur dans la fenêtre
void kbdSpFunc(int c, int x, int y)
{
	printf("Touche speciale utilisee %d (coord souris %d/%d)\n",c,x,y);
	switch(c) {
		case GLUT_KEY_F1 : // quit
			printf("Touche F1\n");
			break;
		default :
			printf("Touche speciale non fonctionnelle\n");
	}
}

/// ///////////////////////////////////////////////////////////////////////////
/// fonction associée aux evenements souris
/// - x,y : coordonnée de la souris dans la fenêtre
void clickMouse(int button,int state,float x,float y){
	
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_UP){ // state == GLUT_UP
			ButtonsList* tmp = Image.buttons;
			
			while(tmp->next != NULL){
				if(isInBounds(x,y,&(tmp->button->bounds))){
					(tmp->button->clickHandle)();
					printf("%s",tmp->button->label);
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
}

void drawImage(){
	ButtonsList* tmp=Image.buttons;
	while(tmp != NULL){
		drawButton(tmp->button);
		tmp=tmp->next;
	}
}

void Save(){
	Calque * test2;
	printf("Sauvegarde de l'image\n");
	test2=fusionCalques(Image.calques);
	SaveImage("save.ppm",test2->rvb,Image.calques->calque->width,Image.calques->calque->height);
}

void Quit(){
	printf("Sortie d'imagimp\n");
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
}

void printHisto(){
	if(Image.printHisto==1)
		Image.printHisto=0;
	else
		Image.printHisto=1;
}

void refreshImage(){
	Calque * test2;

	if(Image.activeLayerShowed){ //Calque actif affiché
		test2=clonePtrCalque(*(Image.calques->calque));//fusionCalques(Image.calques);
		appliquerListeLUTCalque(test2);
		
	}else{ //Tous les calques
		test2=fusionCalques(Image.calques);
	}
	if(Image.sepia){
		test2=SEPIA(*test2);
	}
	if(Image.printHisto){
		Histogramme * histo = createHisto(test2->rvb,test2->width, test2->height);
		*test2=HistoToImage(*histo);
	}
	actualiseImage(test2->rvb,test2->width,test2->height);
	// int sepia;
	// int printHisto;
}
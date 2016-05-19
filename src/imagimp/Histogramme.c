/*
* 					Anfray Lapeyre & Caroline Vien
*							Projet Imagimp
*					 		19/04/2016
*					Prog. et Algorithmique 2
*							IMAC1
*/
#include "../../include/Histogramme.h"

Histogramme* createHisto(Uint8 * rvb,int width, int height){
	Histogramme * histo =malloc(sizeof(Histogramme));
	for(int i=0;i<width*height*3;i+=3){
		histo->val[(Uint8)((rvb[i]+rvb[i+1]+rvb[i+2])/3)]++;

	}
	
	// for(int j=0;j<256;j++){
		// printf("[%d]=%d\n",j,histo->val[j]);
	// }
	return histo;
}


Calque HistoToImage(Histogramme h){
	int max=0;
	for(int i=0;i<256;i++){
		if(h.val[i]>max){
			max=h.val[i];
		}
	}
	// printf("%d",h.val[255]);
	
	Calque res;
	res.width=max;
	res.height=256;
	res.fusion=0;
	res.opacity=1.;
	
	res.rvb=malloc(sizeof(Uint8)*res.width*res.height*3);
	for(int i=0;i<res.width*res.height;i++){
		// printf("%d,",i/(res.width));
		if(h.val[i/(res.width)]>=i%(res.width)){
			res.rvb[i*3]=0;
			res.rvb[i*3+1]=0;
			res.rvb[i*3+2]=0;
		}else{
			res.rvb[i*3]=255;
			res.rvb[i*3+1]=255;
			res.rvb[i*3+2]=255;
		}
	}
	// for(int j=0;j<res.height;j++){
		// for(int i=0;i<res.width*3;i+=3){
			// if(h.val[j]>=i){
				// res.rvb[(j*res.width*3+i)]=0;
				// res.rvb[(j*res.width*3+i)+1]=0;
				// res.rvb[(j*res.width*3+i)+2]=0;
			// }else{
				// res.rvb[(j*res.width*3+i)]=255;
				// res.rvb[(j*res.width*3+i)+1]=255;
				// res.rvb[(j*res.width*3+i)+2]=255;
			// }
		// }
	// }
	
	return res;
}
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

	for(int i=0; i<256;i++){
		histo->r[i]=0;
		histo->v[i]=0;
		histo->b[i]=0;
		histo->n[i]=0;
	}
	
	for(int i=0;i<width*height*3-3;i+=3){
		histo->r[rvb[i]]++;
		histo->v[rvb[i+1]]++;
		histo->b[rvb[i+2]]++;
		histo->n[(int)(rvb[i]*0.299+rvb[i+1]*0.587+rvb[i+2]*0.114)]++;
	}
	return histo;
}


Calque HistoToImageRVB(Histogramme h){
	int max=0;
	for(int i=0;i<256;i++){
		if(h.r[i]>max){
			max=h.r[i];
		}
		if(h.v[i]>max){
			max=h.v[i];
		}
		if(h.b[i]>max){
			max=h.b[i];
		}
		if(h.n[i]>max){
			max=h.n[i];
		}
	}
	
	Calque res;
	res.width=600;
	res.height=400;
	res.fusion=0;
	res.opacity=1.;
	
	res.rvb=malloc(sizeof(Uint8)*res.width*res.height*3);
	for(int i=0;i<res.width*res.height-1;i++){
		// if(h.r[(int)((i%res.width)/600.*255.)]>262144)
			// printf("%d\n",h.r[(int)((i%res.width)/600.*255.)]);
		// getchar();
		if(i/res.width<390){
			if((400 - i/res.width)<(h.r[(int)((i%res.width)/600.*255.)])*400./max+10){
				res.rvb[i*3]=255;
			}else{
				res.rvb[i*3]=0;
			}
			if((400 - i/res.width)<(h.v[(int)((i%res.width)/600.*255.)])*400./max+10){
				res.rvb[i*3+1]=255;
			}else{
				res.rvb[i*3+1]=0;
			}
			if((400 -i/res.width)<(h.b[(int)((i%res.width)/600.*255.)])*400./max+10){
				res.rvb[i*3+2]=255;
			}else{
				res.rvb[i*3+2]=0;
			}
			if((400 -i/res.width)<(h.n[(int)((i%res.width)/600.*255.)])*400./max+10){
				res.rvb[i*3]=255;
				res.rvb[i*3+1]=255;
				res.rvb[i*3+2]=255;
			}
		}else{
			res.rvb[i*3]=(i%res.width)/600.*255.;
			res.rvb[i*3+1]=(i%res.width)/600.*255.;
			res.rvb[i*3+2]=(i%res.width)/600.*255.;
		}
		
	}
	
	return res;
}

Calque HistoToImageCMJ(Histogramme h){
	int max=0;
	for(int i=0;i<256;i++){
		if(h.r[i]>max){
			max=h.r[i];
		}
		if(h.v[i]>max){
			max=h.v[i];
		}
		if(h.b[i]>max){
			max=h.b[i];
		}
		if(h.n[i]>max){
			max=h.n[i];
		}
	}
	
	Calque res;
	res.width=600;
	res.height=400;
	res.fusion=0;
	res.opacity=1.;
	
	res.rvb=malloc(sizeof(Uint8)*res.width*res.height*3);
	for(int i=0;i<res.width*res.height-1;i++){
		// if(h.r[(int)((i%res.width)/600.*255.)]>262144)
			// printf("%d\n",h.r[(int)((i%res.width)/600.*255.)]);
		// getchar();
		if(i/res.width<390){
			if((400 - i/res.width)<(h.r[(int)((i%res.width)/600.*255.)])*400./max+10){
				res.rvb[i*3]=0;
			}else{
				res.rvb[i*3]=255;
			}
			if((400 - i/res.width)<(h.v[(int)((i%res.width)/600.*255.)])*400./max+10){
				res.rvb[i*3+1]=0;
			}else{
				res.rvb[i*3+1]=255;
			}
			if((400 -i/res.width)<(h.b[(int)((i%res.width)/600.*255.)])*400./max+10){
				res.rvb[i*3+2]=0;
			}else{
				res.rvb[i*3+2]=255;
			}
			if((400 -i/res.width)<(h.n[(int)((i%res.width)/600.*255.)])*400./max+10){
				res.rvb[i*3]=0;
				res.rvb[i*3+1]=0;
				res.rvb[i*3+2]=0;
			}
		}else{
			res.rvb[i*3]=(i%res.width)/600.*255.;
			res.rvb[i*3+1]=(i%res.width)/600.*255.;
			res.rvb[i*3+2]=(i%res.width)/600.*255.;
		}
		
	}
	
	return res;
}
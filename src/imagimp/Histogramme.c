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
		histo->r[rvb[i]]++;
		histo->v[rvb[i+1]]++;
		histo->b[rvb[i+2]]++;
	}
	
	// for(int j=0;j<256;j++){
		// printf("[%d]=%d\n",j,histo->val[j]);
	// }
	return histo;
}


Calque HistoToImage(Histogramme h){
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
	}
	// printf("%d",h.val[255]);
	
	Calque res;
	res.width=600;
	res.height=400;
	res.fusion=0;
	res.opacity=1.;
	
	res.rvb=malloc(sizeof(Uint8)*res.width*res.height*3);
	/*for(int i=0;i<res.width*res.height;i++){
		// printf("%d,",i/(res.width));
		if(h.r[i/(res.width)]>i%(res.width)){
			res.rvb[i*3]=0;
		}else{
			res.rvb[i*3]=255;
		}
		if(h.v[i/(res.width)]>i%(res.width)){
			res.rvb[i*3+1]=0;
		}else{
			res.rvb[i*3+1]=255;
		}
		if(h.b[i/(res.width)]>i%(res.width)){
			res.rvb[i*3+2]=0;
		}else{
			res.rvb[i*3+2]=255;
		}
	}*/
	printf("%f\n%f",max*400./max,400.*max/400.);
	for(int i=0;i<res.width*res.height;i++){
		if(i/res.width<390){
			if((400 - i/res.width)<h.r[(int)((i%res.width)/600.*255.)]/10.){
				res.rvb[i*3]=0;
			}else{
				res.rvb[i*3]=255;
			}
			if((400 - i/res.width)<h.v[(int)((i%res.width)/600.*255.)]/10.){
				res.rvb[i*3+1]=0;
			}else{
				res.rvb[i*3+1]=255;
			}
			if((400 -i/res.width)<h.b[(int)((i%res.width)/600.*255.)]/10.){
				res.rvb[i*3+2]=0;
			}else{
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
#include "image.h"

void Image::flipleft(){
  Image *p= new Image;
  p->resize((*this).width(),(*this).height());
  int a=0;
  for(int x=(*this).width()-1; x>0 || x==0; x--){
    
    for(int y=0; y<(*this).height(); y++){
      (*p)(a,y)->red=(*this)(x,y)->red;
      (*p)(a,y)->green=(*this)(x,y)->green;
      (*p)(a,y)->blue=(*this)(x,y)->blue;
      
    }
    a++;
  }
  
 
  for(int x=0; x<(*this).width(); x++){
    for(int y=0; y<(*this).height(); y++){
      (*this)(x,y)->red=(*p)(x,y)->red;
      (*this)(x,y)->green=(*p)(x,y)->green;
      (*this)(x,y)->blue=(*p)(x,y)->blue;
      
    }
    
  }
  delete p;

	
	
	
}
void Image::invertcolors(){
  for(int x=0; x<(*this).width(); x++){
    for(int y=0; y<(*this).height(); y++){
      (*this)(x,y)->red =255- (*this)(x, y)->red;
      (*this)(x,y)->green =255- (*this)(x, y)->green;
      (*this)(x,y)->blue =255- (*this)(x, y)->blue;
    }
  }
  return;
}

void Image::adjustbrightness(int r, int g, int b){
  for(int x=0; x<(*this).width(); x++){
    for(int y=0; y<(*this).height(); y++){
      if((*this)(x, y)->red + r>255)
	(*this)(x,y)->red= 255;
      else if((*this)(x, y)->red + r<0)
	(*this)(x,y)->red= 0;
      else
	(*this)(x,y)->red = (*this)(x, y)->red + r;

      if((*this)(x, y)->green+g> 255)
	(*this)(x,y)->green= 255;
      else if((*this)(x, y)->green+g<0)
	(*this)(x,y)->green= 0;
      else
      (*this)(x,y)->green = (*this)(x, y)->green + g;

      if((*this)(x, y)->blue+ b> 255)
	(*this)(x,y)->blue = 255;
      else if((*this)(x, y)->blue +b<0)
	(*this)(x,y)->blue = 0;
      else
      (*this)(x,y)->blue = (*this)(x, y)->blue + b;
    }
  }
}

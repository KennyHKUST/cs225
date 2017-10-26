#include "scene.h"
#include "image.h"
using namespace std;


void Scene::clear(){
  for(int i=0; i<maxim; i++)
    if(im[i] != NULL){
      delete im[i];
      im[i] = NULL;
    }
  delete [] im;

}

void Scene::copy(const Scene& other){
  maxim= other.maxim;
  picturecount= other.picturecount;
  im = new Image*[maxim];

  for (int i=0; i< maxim; i++)
    im[i] = NULL;

  for (int i=0; i< maxim; i++){
    if(other.im[i] != NULL){
      im[i] = new Image();
      *im[i] = *other.im[i];
    }
  }
  coor= new int[maxim*2];
  for (int i=0; i<2*maxim; i++)
    coor[i] = 0;


  for (int i=0; i<2*picturecount; i++)
    coor[i] = other.coor[i];
}


Scene::Scene(int max){
  im= new Image*[max];
	for (int i=0; i<max; i++)
		im[i] = NULL;

  coor= new int[2*max];
  for (int i=0; i<2*max; i++)
    coor[i] = 0;

	maxim=max;
  picturecount=0;

}

Scene::~Scene(){
  clear();
  delete[] coor;
}

Scene::Scene (const Scene & source){
  copy(source);
}

const Scene & Scene::operator= ( const Scene & source){
  clear();
  delete[] coor;
  copy(source);

  return *this;
}


void Scene::changemaxlayers(int newmax){
  if (newmax < maxim){
    cout << "invalid newmax" << endl;
    return;
  }

  Image ** p= new Image*[maxim];
    cout<<maxim<<endl;
  for (int i=0; i<maxim; i++){
      if (im[i]!=NULL){
        cout<<"82"<<endl;
        p[i] = new Image();
        *p[i] = *im[i];
      }
      else
        
          p[i] = NULL;
  }
  clear();
 
  im=new Image*[newmax];
  for (int i = 0; i<newmax; i++)
    im[i] = NULL;
    cout<<"94"<<endl;
    for (int i=0; i<maxim; i++){
        if (p[i] != NULL)
            im[i] = new Image();
            *im[i] = *p[i];
    }
    cout<<"98"<<endl;
  for(int i=0; i<maxim; i++)
    if(p[i] != NULL){
        delete p[i];
        p[i] = NULL;
    }
  delete [] p;

    
  int * p2= new int[maxim*2];
  for (int i=0; i<maxim*2; i++){
    p2[i]=coor[i];
  }
  delete [] coor;


  coor=new int[newmax*2];
  for (int i=0; i<newmax*2; i++)
    coor[i] = 0;

  for (int i=0; i<maxim*2; i++)
    coor[i]=p2[i];

  delete [] p2;

  maxim = newmax;
}

void Scene::addpicture(const char* FileName, int index, int x, int y){
  if (index > maxim-1 || index < 0){
    cout << "index out of bounds" << endl;
    return;
  }
  if(im[index] == NULL)
    picturecount++;

  im[index] = new Image();
  im[index]->readFromFile(FileName);
  coor[index*2] = x;
  coor[index*2+1] = y;

}

void Scene::changelayer(int index, int newindex){
  if(index == newindex)
    return;
  if(index < 0 || index > maxim-1 || newindex < 0 || newindex > maxim-1){
    cout << "invalid index" << endl;
    return;
  }

  im[newindex] = im[index];
  im[index] = NULL;
  coor[newindex*2] = coor[index*2];
  coor[newindex*2+1] = coor[index*2+1];
  coor[index*2] = 0;
  coor[index*2+1] = 0;
    cout<<"158"<<endl;
}

void Scene::translate(int index, int xcoord, int ycoord){
  if(im[index] == NULL || index > maxim-1 || index < 0){
    cout << "invalid index" << endl;
    return;
  }

  coor[index*2] = xcoord;
  coor[index*2+1] = ycoord;

}
void Scene::deletepicture(int index){
  if(im[index] == NULL || index > maxim-1 || index < 0){
    cout << "invalid index" << endl;
    return;
  }
  delete im[index];
  im[index] = NULL;
}

Image * Scene::getpicture (int index) const{
  if(im[index] == NULL || index > maxim-1 || index < 0){
    cout << "invalid index" << endl;
    return NULL;
  }


  return im[index];


}

Image Scene::drawscene() const{

  Image newim;
  int maxwidth = 0;
  int maxheight = 0;
  for(int i=0; i< maxim; i++){
    if(im[i]==NULL)
      continue;
    if(coor[i*2] + im[i]->width() > maxwidth)
      maxwidth = coor[i*2] + im[i]->width();
    if(coor[i*2+1] + im[i]->height() > maxheight)
      maxheight = coor[i*2] + im[i]->height();
  }


  newim.resize(maxwidth, maxheight);
  for(int i=0; i< maxim; i++){
    if(im[i]==NULL)
      continue;
    int a = 0;
    for(int x=coor[i*2]; x < coor[i*2]+im[i]->width(); x++){
      int b = 0;
      for (int y=coor[i*2+1]; y < coor[i*2+1]+im[i]->height(); y++){
        newim(x,y)->red = (*im[i])(a, b)->red;
        newim(x,y)->green = (*im[i])(a, b)->green;
        newim(x,y)->blue = (*im[i])(a, b)->blue;
        b++;
      }
      a++;
    }
  }











  return newim;
}

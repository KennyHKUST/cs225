#include <algorithm>
#include <iostream>

#include "rgbapixel.h"
#include "png.h"

using namespace std;

int main()
{

    PNG in("in.png");
    PNG out(in.width(), in.height());

    int x=0;
    
    for(int a=in.width()-1; a>0 || a==0;a--){
       int y=0;
       for(int b=in.height()-1; b>0 || b==0; b--){
	  RGBAPixel *w=new RGBAPixel;
	  w=in.operator()(a, b);
          int red=w->red;
          int green=w->green;
          int blue=w->blue;
          out.operator()(x,y)->red= red;
          out.operator()(x,y)->green= green;
          out.operator()(x,y)->blue= blue;
          y++;
	 
	  
       }
       x++;
    }
    if(out.writeToFile("out.png")){
        cout<<"done"<<endl;
    }else{
        cout<<"fail"<<endl;
    }
    return 0;
}
    


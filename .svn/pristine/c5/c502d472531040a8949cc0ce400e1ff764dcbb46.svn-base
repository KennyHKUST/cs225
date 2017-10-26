/**
 * @file filler.cpp
 * Implementation of functions in the filler namespace. Heavily based on
 * old MP4 by CS225 Staff, Fall 2010.
 *
 * @author Chase Geigle
 * @date Fall 2012
 */
#include "filler.h"

animation filler::dfs::fillSolid(PNG& img, int x, int y, RGBAPixel fillColor,
                                 int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
    solidColorPicker solid(fillColor);

    return filler::dfs::fill(img, x, y, solid, tolerance, frameFreq);
}

animation filler::dfs::fillGrid(PNG& img, int x, int y, RGBAPixel gridColor,
                                int gridSpacing, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
    gridColorPicker grid(gridColor, gridSpacing);

    return filler::dfs::fill(img, x, y, grid, tolerance, frameFreq);
}

animation filler::dfs::fillGradient(PNG& img, int x, int y,
                                    RGBAPixel fadeColor1, RGBAPixel fadeColor2,
                                    int radius, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
    gradientColorPicker gradient(fadeColor1, fadeColor2, radius, x, y);

    return filler::dfs::fill(img, x, y, gradient, tolerance, frameFreq);
}

animation filler::dfs::fill(PNG& img, int x, int y, colorPicker& fillColor,
                            int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to filler::fill with the correct template parameter
     * indicating the ordering structure to be used in the fill.
     */
    return filler::fill<Stack> (img, x, y, fillColor, tolerance, frameFreq);
}

animation filler::bfs::fillSolid(PNG& img, int x, int y, RGBAPixel fillColor,
                                 int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
    solidColorPicker solid(fillColor);

    return filler::bfs::fill(img, x, y, solid, tolerance, frameFreq);
    
}

animation filler::bfs::fillGrid(PNG& img, int x, int y, RGBAPixel gridColor,
                                int gridSpacing, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
    gridColorPicker grid(gridColor, gridSpacing);

    return filler::bfs::fill(img, x, y, grid, tolerance, frameFreq);
}

animation filler::bfs::fillGradient(PNG& img, int x, int y,
                                    RGBAPixel fadeColor1, RGBAPixel fadeColor2,
                                    int radius, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
    gradientColorPicker gradient(fadeColor1, fadeColor2, radius, x, y);

    return filler::bfs::fill(img, x, y, gradient, tolerance, frameFreq);
}

animation filler::bfs::fill(PNG& img, int x, int y, colorPicker& fillColor,
                            int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to filler::fill with the correct template parameter
     * indicating the ordering structure to be used in the fill.
     */
    return filler::fill<Queue> (img, x, y, fillColor, tolerance, frameFreq);

}

template <template <class T> class OrderingStructure>
animation filler::fill(PNG& img, int x, int y, colorPicker& fillColor,
                       int tolerance, int frameFreq)
{
    //define orginal RGBPixel
    //cout<<tolerance<<" "<<frameFreq<<endl;
    uint8_t oRed = img(x, y)->red;
    uint8_t oGreen = img(x, y)->green;
    uint8_t oBlue = img(x, y)->blue;
    //declare a Stack or Queue to store coordinates
    OrderingStructure<int> xcoor;
    OrderingStructure<int> ycoor;
    //initiate a 2D array to indicate which coordinate has been processed
    int w = img.width();
    int h = img.height();
    bool** visit = new bool*[w];
    for (int i = 0; i < w; i++)
        visit[i] = new bool[h];


    for(unsigned long i = 0; i < img.width(); i++)
        for(unsigned long j = 0; j < img.height(); j++)
            visit[i][j] = false;

    xcoor.add(x);
    ycoor.add(y);
    int filled = 0;
    animation animation;

    while(xcoor.isEmpty() == false && ycoor.isEmpty() == false){
        //cout<<"no"<<endl;
        int cx = xcoor.remove();
        int cy = ycoor.remove();
        if(cx < 0 || cy < 0 || cx > w - 1 || cy > h - 1){
            //cout<<"enter"<<endl;
            continue;
        }
        uint8_t cRed = img(cx, cy)->red;
        uint8_t cGreen = img(cx, cy)->green;
        uint8_t cBlue = img(cx, cy)->blue;
        //cout<<unsigned(oRed)<<" "<<unsigned(oGreen)<<" "<<unsigned(oBlue)<<endl;
        //cout<<visit[cx][cy]<<endl;
        if(!visit[cx][cy] && (cRed-oRed)*(cRed-oRed)+(cGreen-oGreen)*(cGreen-oGreen)+(cBlue-oBlue)*(cBlue-oBlue)<=tolerance){
            //cout<<"good"<<endl;
            visit[cx][cy] = true;

            //cout<<img(cx, cy)->red<<endl;
            img(cx, cy)->red = fillColor(cx, cy).red;
            img(cx, cy)->green = fillColor(cx, cy).green;
            img(cx, cy)->blue = fillColor(cx, cy).blue;
            //cout<<img(cx, cy)->red<<endl;
            xcoor.add(cx + 1);
            ycoor.add(cy);

            ycoor.add(cy + 1);
            xcoor.add(cx);

            xcoor.add(cx - 1);
            ycoor.add(cy);

            ycoor.add(cy - 1);
            xcoor.add(cx);
            filled++;
            //cout<<filled<<endl;
            
            if(filled % frameFreq == 0){
                //cout<<"in"<<endl;
                animation.addFrame(img);
            }
        }
    }

     //delete the dynamically allocated 2D array
    for(unsigned long i = 0; i < img.width(); i++)
        delete[] visit[i];
    delete[] visit;
    return animation;
}

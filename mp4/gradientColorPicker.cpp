#include <stdlib.h>
#include "gradientColorPicker.h"

/**
 * Constructs a new gradientColorPicker.
 *
 * @param fadeColor1 The first color to start the gradient at.
 * @param fadeColor2 The second color to end the gradient with.
 * @param radius How quickly to transition to fadeColor2.
 * @param centerX X coordinate for the center of the gradient.
 * @param centerY Y coordinate for the center of the gradient.
 */
gradientColorPicker::gradientColorPicker(RGBAPixel fadeColor1,
                                         RGBAPixel fadeColor2, int radius,
                                         int centerX, int centerY)
{
    colorS = fadeColor1;
    colorE = fadeColor2;
    r = radius;
    centerx = centerX; 
    centery = centerY;
    /**
     * @todo Construct your gradientColorPicker here! You may find it
     *	helpful to create additional member variables to store things.
     */
}

/**
 * Picks the color for pixel (x, y).
 *
 * The first color fades into the second color as you move from the initial
 * fill point, the center, to the radius. Beyond the radius, all pixels
 * should be just color2.
 *
 * You should calculate the distance between two points using the standard
 * Manhattan distance formula,
 *
 * \f$d = |center\_x - given\_x| + |center\_y - given\_y|\f$
 *
 * Then, scale each of the three channels (R, G, and B) from fadeColor1 to
 * fadeColor2 linearly from d = 0 to d = radius.
 *
 * For example, the red color at distance d where d is less than the radius
 * must be
 *
 * \f$ redFill = fadeColor1.red - \left\lfloor
   \frac{d*fadeColor1.red}{radius}\right\rfloor +
   \left\lfloor\frac{d*fadeColor2.red}{radius}\right\rfloor\f$
 *
 * Note that all values are integers. If you do not follow this formula,
 * your colors may be very close but round differently than ours.
 *
 * @param x The x coordinate to pick a color for.
 * @param y The y coordinate to pick a color for.
 * @return The color selected for (x, y).
 */
int gradientColorPicker::distance(int x, int y){
    return abs(centerx - x) + abs(centery - y);
}
RGBAPixel gradientColorPicker::operator()(int x, int y)
{
    uint8_t redFill = colorE.red;
    uint8_t blueFill = colorE.blue;
    uint8_t greenFill = colorE.green;
    //cout<<"r = "<< r<<endl;
    //cout<<"distance(x, y) = "<<distance(x, y)<<endl;
    if(distance(x, y) < r){
        redFill = colorS.red - distance(x, y) * colorS.red/r 
        + distance(x, y) * colorE.red/r;
       // cout << "redfill = "<<unsigned(redFill)<<endl;
        blueFill = colorS.blue - distance(x, y) * colorS.blue/r 
        + distance(x, y) * colorE.blue/r;
       // cout << "bluefill = "<<unsigned(blueFill)<<endl;
        greenFill = colorS.green - distance(x, y) * colorS.green/r 
        + distance(x, y) * colorE.green/r;
        //cout << "greenfill = "<<unsigned(greenFill)<<endl;
    }
    /**
     * @todo Return the correct color here!
     */
    RGBAPixel color(redFill, greenFill, blueFill);
    //cout << "color = "<<unsigned(color.red)<<" "<<unsigned(color.green)<<" "<<unsigned(color.blue)<<endl;
    //color.red = redFill;
    //color.green = greenFill;

    return color;
}

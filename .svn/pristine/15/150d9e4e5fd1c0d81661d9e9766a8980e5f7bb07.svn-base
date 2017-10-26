/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"

using namespace std;

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage> const& theTiles)
{
    /**
     * @todo Implement this function!
     */
    MosaicCanvas* image = new MosaicCanvas(theSource.getRows(), theSource.getColumns());
    vector<Point<3>> rgb;
    // map<Point<3>, Point<2>> pixelmap;
    // for(int i = 0; i < theSource.getRows(); i++){
    // 	for(int j = 0; j < theSource.getColumns(); j++){
    // 		RGBAPixel p = theSource.getRegionColor(i, j);
    // 		double arr[3] = {(double)p.red, (double)p.green, (double)p.blue};
    // 		Point<3> point(arr);
    // 		rgb.push_back(point);
    // 		double xy[2] = {(double)i, (double)j};
    // 		Point<2> xyPoint(xy);
    // 		pixelmap.insert(pair<Point<3>, Point<2>>(point, xyPoint));
    // 	}
    // }
    // cout<<"28"<<endl;
    // KDTree<3> t(rgb);//infinite loop but don't know why yet

    // for(unsigned long i = 0; i < theTiles.size(); i++){
    // 	RGBAPixel avg = theTiles[i].getAverageColor();
    // 	double avgArr[3] = {(double)avg.red, (double)avg.green, (double)avg.blue};
    // 	Point<3> avgPoint(avgArr);
    // 	Point<3> nearestP = t.findNearestNeighbor(avgPoint);
    // 	auto it = pixelmap.find(nearestP);
    // 	if(it != pixelmap.end()){
    // 		image->setTile(it->second[0], it->second[1], theTiles[i]);
    // 	}

    // }

    //
    map<Point<3>, int> pixelmap;
    for(unsigned long i = 0; i < theTiles.size(); i++){
		RGBAPixel avg = theTiles[i].getAverageColor();
		double avgArr[3] = {(double)avg.red, (double)avg.green, (double)avg.blue};
		Point<3> avgPoint(avgArr);
		rgb.push_back(avgPoint);
		pixelmap.insert(pair<Point<3>, int>(avgPoint, i));
    }
    KDTree<3> t(rgb);
    for(int i = 0; i < theSource.getRows(); i++){
		for(int j = 0; j < theSource.getColumns(); j++){
			RGBAPixel p = theSource.getRegionColor(i, j);
			double arr[3] = {(double)p.red, (double)p.green, (double)p.blue};
			Point<3> point(arr);
			Point<3> nearestP = t.findNearestNeighbor(point);
			auto it = pixelmap.find(nearestP);
			image->setTile(i, j, theTiles[it->second]);
		}
    }
    return image;
}



#ifndef scene_H
#define scene_H
#include "png.h"
#include "image.h"

class Scene{
 private:
  Image ** im;
  int maxim;
  int picturecount;
  int * coor;
  void copy(const Scene & other);
  void clear();
 public:
  Scene( int max);
  Scene( const Scene & source);
  ~Scene();
  const Scene & operator= ( const Scene & source);
  void changemaxlayers ( int newmax);
  void addpicture ( const char * FileName, int index, int x, int y);
  void changelayer ( int index, int newindex);
  void translate ( int index, int xcoord, int ycoord);
  void deletepicture ( int index );
  Image * getpicture (int index) const;
  Image drawscene () const;



};
#endif

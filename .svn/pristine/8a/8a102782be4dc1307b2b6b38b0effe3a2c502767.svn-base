/**
 * @file quadtree.h
 * Quadtree class definition.
 * @date Spring 2008
 */

#ifndef QUADTREE_H
#define QUADTREE_H

#include "png.h"

/**
 * A tree structure that is used to compress PNG images.
 */
class Quadtree
{
  public:
    void buildTree(PNG const &img, int d);
    Quadtree();
    ~Quadtree();
    Quadtree(PNG const &img, int d);
    RGBAPixel getPixel(int x, int y)const;
    PNG decompress()const;
    void clockwiseRotate();
    Quadtree(Quadtree const &other);
    Quadtree const & operator=(Quadtree const & other);
    void prune(int tolerance);
    int pruneSize(int tolerance)const;
    //int getLeaves();
    int idealPrune(int NumOfleaves)const;
  private:
    void clear();
    int width;
    /**
     * A simple class representing a single node of a Quadtree.
     * You may want to add to this class; in particular, it could
     * probably use a constructor or two...
     */
    class QuadtreeNode
    {
      public:
        QuadtreeNode* nwChild; /**< pointer to northwest child */
        QuadtreeNode* neChild; /**< pointer to northeast child */
        QuadtreeNode* swChild; /**< pointer to southwest child */
        QuadtreeNode* seChild; /**< pointer to southeast child */

        RGBAPixel element; /**< the pixel stored as this node's "data" */
        int leaves;
    };
    void clear(QuadtreeNode*& croot);
    QuadtreeNode* buildTreeHelp(PNG const &img, int x, int y, int d);
    QuadtreeNode* root; /**< pointer to root of quadtree */
    int getNumberLeaves(QuadtreeNode* croot);
    QuadtreeNode* getPixelHelp(QuadtreeNode* croot, int x, int y, int d)const;
    void decompressHelp(PNG &img, int x, int y);
    void rotateHelp(QuadtreeNode* croot);
    void copy(Quadtree other);
    void copyHelp(QuadtreeNode*& croot, QuadtreeNode* oroot);
    void pruneHelp(QuadtreeNode* croot, int t);
    bool prunable(RGBAPixel r1, RGBAPixel r2, int t)const;
    void pruneSizeHelp(QuadtreeNode* croot, int t, int & l)const;
    bool checkPrune(QuadtreeNode* croot1, QuadtreeNode* croot2, int t)const;
    int idealPruneHelp(int max, int min, int n, int l)const;
/**** Functions for testing/grading                      ****/
/**** Do not remove this line or copy its contents here! ****/
#include "quadtree_given.h"
};

#endif

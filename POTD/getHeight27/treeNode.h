#ifndef _TREENODE_H
#define _TREENODE_H

#include <cstddef>
#include <iostream>
using namespace std;

class TreeNode {
public:
  TreeNode *left;
  TreeNode *right;
  TreeNode();
  int getHeight();
private:
  int Height(TreeNode* root);
};

#endif

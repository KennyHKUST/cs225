#include "treeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left(NULL), right(NULL) { }

bool TreeNode::isPerfect() {

	int l = 0; int r = 0;
 	if(isPerfect(left, l) == isPerfect(right, r) && r == l){
  		//cout<<l<<" "<<r<<endl;
  		return true;
  	}
  	return false;
}

bool TreeNode::isPerfect(TreeNode* croot, int &n){
	if(croot == NULL)
		return false;
	n++;
	if(isPerfect(croot->left, n) == isPerfect(croot->right, n))
		return true;
	return false;
}
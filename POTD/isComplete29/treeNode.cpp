#include "treeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left(NULL), right(NULL) { }

int TreeNode::count() {

	return 1 + count(left) + count(right);
}
int TreeNode::count(TreeNode* croot) {
	if(croot == NULL)
		return 0;
	return 1 + count(croot->left) + count(croot->right);
}
bool TreeNode::isComplete() {
	//cout<<count()<<endl;
	if(count() % 2 != 0 && left != NULL && right != NULL)
		return false;
  	return isComplete(left, 1, count()) && 
  	isComplete(right, 2, count());
}

bool TreeNode::isComplete(TreeNode* croot, int key, int n){
	if(croot == NULL)
		return true;
	if(key >= n)
		return false;
	return (isComplete(croot->left, 2*key + 1, n) &&
            isComplete(croot->right, 2*key + 2, n));
}

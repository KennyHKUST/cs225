#include "treeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left(NULL), right(NULL) { }

int TreeNode::getHeight() {
	if(left == NULL && right == NULL)
		return 0;
 	return 1 + max(Height(left), Height(right));
}

int TreeNode::Height(TreeNode* root){
	if(root == NULL)
		return -1;
	return 1 + max(Height(root->left), Height(root->right));
}

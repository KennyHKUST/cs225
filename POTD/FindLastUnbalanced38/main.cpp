#include <iostream>
#include <stdlib.h>

using namespace std;

struct TreeNode {

    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode(int x) {

      left = NULL;

      right = NULL;

      val = x;

    }

};
int height(TreeNode* croot){
  if(!croot)
    return -1;
  return 1 + max(height(croot->left), height(croot->right));
}

TreeNode* findLastUnbalanced(TreeNode* root) {
  if(!root)
    return NULL;
  TreeNode* crootl = findLastUnbalanced(root->left);
  TreeNode* crootr = findLastUnbalanced(root->right);
  if(!crootl && !crootr){
    if(height(root->left) - height(root->right) > 1 ||
    height(root->left) - height(root->right) < -1)
      return root;
    return NULL;
  }
  if(crootl && !crootr)
    return crootl;
  if(!crootl && crootr)
    return crootr;
	//your code here

	return NULL;

}



void deleteTree(TreeNode* root)

{

  if (root == NULL) return;

  deleteTree(root->left);

  deleteTree(root->right);

  delete root;

  root = NULL;

}


int main() {

  TreeNode * n1 = new TreeNode(4);

  TreeNode * n2 = new TreeNode(7);

  TreeNode * n3 = new TreeNode(11);

  TreeNode * n4 = new TreeNode(13);

  TreeNode * n5 = new TreeNode(14);

  TreeNode * n6 = new TreeNode(22);

  //TreeNode * n7 = new TreeNode(6);

  n5->left = n3;

  n5->right = n6;

	n3->right = n4;

  n3->left = n2;

  n2->left = n1;

  //n1->right = n7;

  cout << "Last Unbalanced Node: " << (findLastUnbalanced(n5))->val << endl;

  deleteTree(n5);

  return 0;

}

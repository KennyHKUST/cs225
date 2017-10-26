#include <iostream>

using namespace std;


// Definition for a binary tree node.

struct TreeNode {

    int val;

    TreeNode *left;

    TreeNode *right;
    
    TreeNode *parent;

    TreeNode(int x) {

      left = NULL;

      right = NULL;

      parent = NULL;

      val = x;

    }

};

int height(TreeNode* croot){
  if(!croot)
    return -1;
  return 1 + max(height(croot->left), height(croot->right));
}

TreeNode** findLastUnbalanced(TreeNode*& root) {
  if(!root)
    return NULL;
  TreeNode** crootl = findLastUnbalanced(root->left);
  TreeNode** crootr = findLastUnbalanced(root->right);
  if(!crootl && !crootr){
    if(height(root->left) - height(root->right) > 1 ||
    height(root->left) - height(root->right) < -1)
      return &root;
    return NULL;
  }
  if(crootl && !crootr)
    return crootl;
  else
    return crootr;
  //your code here

  return NULL;

}

void rightRotate(TreeNode* &croot) {

  // Your Code Here
    cout<<"??"<<endl;
    TreeNode* v = croot->left;
    croot->left = v->right;
    v->right = croot;
    croot = v;
    return;
}


void leftRotate(TreeNode* &croot) {

  // your code here
    TreeNode* v = croot->right;
    croot->right = v->left;
    v->left = croot;
    croot = v;

    return;
}


void deleteTree(TreeNode* &croot)

{

  if (croot == NULL) return;
  cout<<"current val = "<<croot->val<<endl;
  deleteTree(croot->left);

  deleteTree(croot->right);

  delete croot;

  croot = NULL;

}

int main() {

  TreeNode * n1 = new TreeNode(2);

  TreeNode * n2 = new TreeNode(5);

  TreeNode * n3 = new TreeNode(8);

  TreeNode * n4 = new TreeNode(10);

  TreeNode * n5 = new TreeNode(13);

  n4->left = n3;
  
  n3->parent = n4;

  n4->right = n5;

  n5->parent = n4;

  n3->left = n2;

  n2->parent = n3;

  n2->left = n1;

  n1->parent = n2;

 // Your Code Here (Right or left rotate to balance above tree? )
  TreeNode** t = findLastUnbalanced(n4);
  cout<<"t->data = "<<t<<endl;
  cout<<"n4->left = "<<n4->left<<endl;
  rightRotate(*t);

  cout << "Ex 1 Inorder traversal : " << ((n4->left)->left)->val << ", " << (n4->left)->val << ", " <<((n4->left)->right)->val << ", " << n4->val << ", " << (n4->right)->val << endl;

  n1 = new TreeNode(2);

  n2 = new TreeNode(5);

  n3 = new TreeNode(8);

  n4 = new TreeNode(10);

  n5 = new TreeNode(13);

  n2->right = n3;
  
  n3->parent = n2;

  n2->left = n1;

  n1->parent = n2;

  n3->right = n4;

  n4->parent = n3;

  n4->right = n5;

  n5->parent = n4;


  TreeNode** t2 = findLastUnbalanced(n2);
  leftRotate(*t2);
 // // Your Code Here (Right or left rotate to balance above tree? )

  cout << "Ex 2 Inorder traversal : " << (n2->left)->val << ", " << n2->val << ", " << ((n2->right)->left)->val << ", " << (n2->right)->val << ", " << ((n2->right)->right)->val << endl;


  deleteTree(n2);

  return 0;
}

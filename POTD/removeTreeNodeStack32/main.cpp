#include <iostream>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode*& rightmost(TreeNode* &croot){
  if(croot->right == NULL)
    return croot;
  return rightmost(croot->right);
}

void remove2(TreeNode*& croot, int key){
  if(croot == NULL)
    return;
  if(croot->val == key){
    cout<<"remove "<<croot->val<<endl;
    croot = NULL;
  }
  else if(croot->val > key)
    remove2(croot->left, key);
  else
    remove2(croot->right, key);
}

void doremoval(TreeNode* &croot){
  if(croot->left == NULL && croot->right == NULL){
    cout<<"remove "<<croot->val<<endl;
    croot = NULL;
  }
  else if(croot->left != NULL && croot->right != NULL){
    TreeNode* t = rightmost(croot->left);
    int a = t->val;
    remove2(croot, t->val);
    croot->val = a;
    
  }
  else{
    TreeNode* t = croot;
    if(croot->right != NULL)
      croot = croot->right;
    else
      croot = croot->left;
    t = NULL;
  }

}
void remove(TreeNode*& croot, int key){
  if(croot == NULL)
    return;
  if(croot->val == key){
    //cout<<"remove "<<croot->val<<endl;
    doremoval(croot);
  }
  else if(croot->val > key)
    remove(croot->left, key);
  else
    remove(croot->right, key);
}
TreeNode* deleteNode(TreeNode*& root, int key) {
  // your code here
  //cout<<"delete"<<endl;
  remove(root, key);
  return root;
}

void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left);
    cout << node->val << " ";
    inorderPrint(node->right);
}


int main() {
/*
 * Example:
 * key = 3
 *   5
 *  / \
 * 3   6
 * /\   \
 *2 4    7
 *
 * After delete 3:
 * (One valid answer, IoS)
 *      5
 *     / \
 *    4   6
 *   /     \
 *  2       7
 *
 * (Another valid answer, IoP)
 *       5
 *      / \
 *     2   6
 *      \   \
 *       4   7
 */

  TreeNode n_0, n_1, n_2, n_3, n_4, n_5;
  n_0.val = 5;
  n_1.val = 3;
  n_2.val = 6;
  n_3.val = 2;
  n_4.val = 4;
  n_5.val = 7;

  n_0.left = &n_1;
  n_0.right = &n_2;
  n_1.left = &n_3;
  n_1.right = &n_4;
  n_2.left = NULL;
  n_2.right = &n_5;
  n_3.left = NULL;
  n_3.right = NULL;
  n_4.left = NULL;
  n_4.right = NULL;
  n_5.left = NULL;
  n_5.right = NULL;

  cout << "Before removal: " << endl;
  inorderPrint(&n_0);
  TreeNode* p = &n_0;
  TreeNode* ans = deleteNode(p, 3);
  cout << endl;
  cout << "After removal: " << endl;
  inorderPrint(ans);
  cout << endl;

  return 0;

}

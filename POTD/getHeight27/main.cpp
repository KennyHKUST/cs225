#include <iostream>
#include "treeNode.h"
using namespace std;

int main() {
  TreeNode n1, n2, n3, n4, n5, n6, n7;

  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  n5.left = &n6;
  n6.right = &n7;
  cout<<"Height of n1: "<<n1.getHeight()<<endl;
  cout<<"Height of n2: "<<n2.getHeight()<<endl;
  cout<<"Height of n5: "<<n5.getHeight()<<endl;
  cout<<"Height of n6: "<<n6.getHeight()<<endl;

  return 0;
}

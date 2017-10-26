/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    //t->height = t->height - 2;
    //t->balanceFactor = t->balanceFactor + 2;
    //cout<<"t = "<<t->value<<endl;
    Node* p = t->right;
    t->right = p->left;
    p->left = t;
    t = p;


    //p->balanceFactor++;
    //cout<<"left rotate"<<endl;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    //t->height = t->height - 2;
    //t->balanceFactor = t->balanceFactor - 2;
    //cout<<"t = "<<t->value<<endl;
    Node* p = t->left;
    t->left = p->right;
    p->right = t;
    t = p;
    //p->balanceFactor--;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
  if(subtree == NULL)
    return;
  int balanceFactor = height(subtree->left) - height(subtree->right);
  if(balanceFactor == 2){
    if(height(subtree->left->left) - height(subtree->left->right)== 1)
      rotateRight(subtree);
    else
      rotateLeftRight(subtree);
  }
  if(balanceFactor == -2){
      //cout<<"left1"<<endl;
    if(height(subtree->right->left) - height(subtree->right->right)== -1){
      //cout<<"left"<<endl;
      rotateLeft(subtree);
    }
    else
      rotateRightLeft(subtree);
  }
    // your code here
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
int AVLTree<K, V>::getBalance(Node*& subtree)
{
  return 0;
}
template <class K, class V>
int AVLTree<K, V>::height(Node*& subtree)
{
  if(subtree == NULL)
    return -1;
  return 1 + max(height(subtree->left), height(subtree->right));
}
template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if(subtree == NULL){
      subtree = new Node(key, value);
      return;
    }
    else if(key < subtree->key){
      insert(subtree->left, key, value);
      // int balance = height(subtree->left) - height(subtree->right);
      // int balanceLeft = 0;
      // // if(subtree->right == NULL)
      // //   balanceLeft = height(subtree->left->left) + 1;
      // // else
      // balanceLeft = height(subtree->left->left) - height(subtree->left->right);
      // //cout<<"balance = "<<balance<<endl;
      // //cout<<"balanceLeft = "<<balanceLeft<<endl;
      // if(balance == 2){
      //   if(balanceLeft == 1)
      //     rotateRight(subtree);
      //   else
      //     rotateLeftRight(subtree);
      // }
    }
    else if(key > subtree->key){
      insert(subtree->right, key, value);
      // int balance = height(subtree->left) - height(subtree->right);
      // int balanceRight = 0;
      // balanceRight = height(subtree->right->left) - height(subtree->right->right);
      // //cout<<"balance = "<<balance<<endl;
      // //cout<<"balanceRight = "<<balanceRight<<endl;
      // if(balance == -2){
      //   if(balanceRight == -1)
      //     rotateLeft(subtree);
      //   else
      //     rotateRightLeft(subtree);
      // }
    }
    rebalance(subtree);
    subtree->height = max(height(subtree->left), height(subtree->right)) + 1;
    //cout<<"now "<<subtree->value<<"->height = "<<subtree->height<<endl;
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left, key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right, key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            //cout<<"remove "<<key<<endl;
            delete subtree;
            subtree = NULL;
            //cout<<"remove finished"<<endl;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            Node* n = findLeftMost(subtree->left);
            subtree->key = n->key;
            subtree->value = n->value;
            remove(subtree->left, n->key);
            // your code here
        } else {
            /* one-child remove */
            // your code here
            Node* p = subtree;
            if(subtree->left != NULL)
              subtree = subtree->left;
            else
              subtree = subtree->right;
            delete p;
            p = NULL;
        }
        // your code here
        return;
    }
    rebalance(subtree);
    subtree->height = max(height(subtree->left), height(subtree->right)) + 1;
    //cout<<"???"<<endl;
}
template <class K, class V>
typename AVLTree<K, V>::Node*& AVLTree<K, V>::findLeftMost(Node*& subtree)
{
  if(subtree->right == NULL)
    return subtree;
  return findLeftMost(subtree->right);
}
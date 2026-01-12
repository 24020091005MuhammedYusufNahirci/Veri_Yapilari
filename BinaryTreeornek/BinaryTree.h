#ifndef BINARYTREEORNEK_BINARYTREE_H
#define BINARYTREEORNEK_BINARYTREE_H
#include "Node.h"
#include<vector>
using namespace std;

class BinaryTree {
private:
  Node *root;

  Node* insert(Node* node, int value);
  void inorder(Node* node, vector<int>& elements);

public:
    BinaryTree();
    void insert(int value);
    bool findPairWithSum(int target);
    void printInorder();


};
#endif //BINARYTREEORNEK_BINARYTREE_H
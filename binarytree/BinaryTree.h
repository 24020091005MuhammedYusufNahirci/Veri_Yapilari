#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H
#include "Node.h"

class BinaryTree {
private:
    Node* root;

    Node* insert(Node* node, int value);
    void inorder(Node* node);
    void preorde(Node* node);
    void postord(Node* node);

public:
    BinaryTree();
    void insert(int value);

    void printInorder();
    void printPreorder();
    void printPostorder();

};
#endif //BINARYTREE_BINARYTREE_H
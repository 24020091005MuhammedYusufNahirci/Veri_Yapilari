#ifndef BINARYTREE2_BINARYTREE_H
#define BINARYTREE2_BINARYTREE_H
#include "Node.h"

class BinaryTree {
private:
    Node *root;

    Node*insert(Node* node,int value);
    void inorde(Node* node);
    void preorder(Node* node);
    void posto(Node* node);

    public:
    BinaryTree();
    void insert(int value);

    void printPreorder();
    void printInorder();
    void printPostorder();
};
#endif //BINARYTREE2_BINARYTREE_H
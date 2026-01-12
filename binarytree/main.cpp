#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree tree;

    tree.insert(10);
    tree.insert(9);
    tree.insert(20);
    tree.insert(19);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);

    std::cout<<"Inorder: ";
    tree.printInorder();

    std::cout<<"Preorder: ";
    tree.printPreorder();

    std::cout<<"Postorder: ";
    tree.printPostorder();


    return 0;
}
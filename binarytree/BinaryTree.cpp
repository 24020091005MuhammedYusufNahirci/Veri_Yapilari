#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree(): root(nullptr) {}

Node* BinaryTree::insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value< node->data) {
        node->left = insert(node->left, value);
    }
    else {
        node->right = insert(node->right, value);
    }
    return node;
}

void BinaryTree::insert(int value) {
    root = insert(root, value);
}

void BinaryTree::inorder(Node *node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

void BinaryTree::preorde(Node *node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    preorde(node->left);
    preorde(node->right);
}

void BinaryTree::postord(Node *node) {
    if (node == nullptr) {
        return;
    }
    postord(node->left);
    postord(node->right);
    std::cout << node->data << " ";
}

void BinaryTree::printInorder() {
    inorder(root);
    std::cout << "\n";
}

void BinaryTree::printPreorder() {
    preorde(root);
    std::cout << "\n";
}

void BinaryTree::printPostorder() {
    postord(root);
    std::cout << "\n";
}

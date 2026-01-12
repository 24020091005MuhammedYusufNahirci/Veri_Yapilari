#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree(): root(nullptr) {}

Node *BinaryTree::insert(Node *node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->data) {
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

void BinaryTree::inorde(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorde(node->left);
    cout << node->data << " ";
    inorde(node->right);
}

void BinaryTree::preorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void BinaryTree::posto(Node *node) {
    if (node == nullptr) {
        return;
    }
    posto(node->left);
    posto(node->right);
    cout << node->data << " ";
}

void BinaryTree::printInorder() {
    inorde(root);
    cout << endl;
}

void BinaryTree::printPreorder() {
    preorder(root);
    cout << endl;
}

void BinaryTree::printPostorder() {
    posto(root);
    cout << endl;
}



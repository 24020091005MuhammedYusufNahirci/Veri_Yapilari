#include <iostream>
#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree(): root(nullptr) {}

Node* BinaryTree::insert(Node* node, int value) {
    if (!node) return new Node(value);  // node boşsa yeni node oluştur

    if (value < node->data)
        node->left = insert(node->left, value);  // sol subtree
    else
        node->right = insert(node->right, value); // sağ subtree

    return node;
}

void BinaryTree::insert(int value) {
    root = insert(root, value); // root güncelleniyor
}

void BinaryTree::inorder(Node* node, vector<int>& elements) {
    if (!node) return;
    inorder(node->left, elements);
    elements.push_back(node->data);
    inorder(node->right, elements);
}

void BinaryTree::printInorder() {
    vector<int> elements;
    inorder(root, elements);
    for (int x: elements) {
        cout << x << " "<<endl;
    }
}

bool BinaryTree::findPairWithSum(int target) {
    vector<int> elements;
    inorder(root, elements);

    int left = 0;
    int right = elements.size() - 1;

    while (left < right) {
        int sum = elements[left] + elements[right];
        if (sum == target) {
            cout << "pair found"<<elements[left]<<"+ "<<elements[right]<<"=" << target<<endl;
            return true;
        }
        else if (sum < target) {
            left = left + 1;
        }
        else {
            right = right - 1;
        }
    }
    return false;
}

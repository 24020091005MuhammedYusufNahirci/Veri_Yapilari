#include <iostream>

using namespace std;

// Ağaç Düğümü Yapısı
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Yapıcı (Constructor)
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Ağacın boyutunu hesaplayan fonksiyon
int getSize(Node* node) {
    // 1. Baz Durum: Eğer düğüm boşsa, sayı 0'dır.
    if (node == nullptr) {
        return 0;
    }

    // 2. Recursive Adım:
    // Sol tarafın boyutu + Sağ tarafın boyutu + 1 (Kendisi)
    return getSize(node->left) + getSize(node->right) + 1;
}

int main() {
    /*
        Örnek Ağaç Yapısı:
             1
           /   \
          2     3
         / \
        4   5
    */

    // Düğümleri oluşturma
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Boyutu hesapla ve yazdır
    cout << "Agacin Boyutu (Dugum Sayisi): " << getSize(root) << endl;

    return 0;
}
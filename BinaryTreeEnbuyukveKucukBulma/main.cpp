#include <iostream>
#include <climits> // INT_MIN ve INT_MAX için gerekli
#include <algorithm> // max ve min fonksiyonları için

using namespace std;

// Ağaç Düğümü Yapısı
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Maksimum Değeri Bulan Fonksiyon
int findMax(Node* root) {
    // 1. Baz Durum: Düğüm boşsa, en küçük tamsayıyı döndür
    if (root == nullptr)
        return INT_MIN;

    // 2. Recursive Adım:
    int res = root->data; // Şu anki düğümün değeri
    int lres = findMax(root->left); // Sol taraftan gelen en büyük
    int rres = findMax(root->right); // Sağ taraftan gelen en büyük

    // 3. Karşılaştırma:
    // Mevcut (res), Soldan Gelen (lres) ve Sağdan Gelen (rres) arasındaki en büyüğü bul
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;

    return res;
}

// Minimum Değeri Bulan Fonksiyon
int findMin(Node* root) {
    // 1. Baz Durum: Düğüm boşsa, en büyük tamsayıyı döndür
    if (root == nullptr)
        return INT_MAX;

    // 2. Recursive Adım:
    int res = root->data;
    int lres = findMin(root->left); // Sol taraftan gelen en küçük
    int rres = findMin(root->right); // Sağ taraftan gelen en küçük

    // 3. Karşılaştırma: En küçüğü bul
    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;

    return res;
}

int main() {
    /*
        Örnek Ağaç:
             2
           /   \
          7     5
           \     \
            6     9
                 /
                1

        Beklenen Max: 9
        Beklenen Min: 1
    */

    Node* root = new Node(2);
    root->left = new Node(7);
    root->right = new Node(5);
    root->left->right = new Node(6);
    root->right->right = new Node(9);
    root->right->right->left = new Node(1);

    cout << "Agactaki Maksimum Deger: " << findMax(root) << endl;
    cout << "Agactaki Minimum Deger: " << findMin(root) << endl;

    return 0;
}
#include <iostream>
#include <algorithm> // max fonksiyonu için

using namespace std;

// AVL Ağacı Düğümü
class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height; // Dengeyi kontrol etmek için yükseklik tutulur
};

// Yükseklik bilgisini güvenli bir şekilde alma fonksiyonu
// (NULL düğümlerin yüksekliği 0 kabul edilir)
int height(Node *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

// İki sayıdan büyüğünü bulan yardımcı fonksiyon
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Yeni düğüm oluşturma
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // Yeni eklenen düğüm yaprak olduğu için yüksekliği 1'dir
    return node;
}

// --- DÖNDÜRME İŞLEMLERİ ---

// Sağa Döndürme (Right Rotate)
// Genellikle Sol-Sol (Left-Left) durumu için kullanılır
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Döndürme işlemi
    x->right = y;
    y->left = T2;

    // Yükseklikleri güncelle (Önce alttaki y, sonra üstteki x)
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Yeni kökü döndür
    return x;
}

// Sola Döndürme (Left Rotate)
// Genellikle Sağ-Sağ (Right-Right) durumu için kullanılır
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Döndürme işlemi
    y->left = x;
    x->right = T2;

    // Yükseklikleri güncelle
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Yeni kökü döndür
    return y;
}

// Denge Faktörünü (Balance Factor) Hesaplama
// Bir düğümün sol ve sağ yüksekliği arasındaki fark
int getBalance(Node *N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

// --- EKLEME (INSERTION) ---

// Recursive (Özyinelemeli) Ekleme Fonksiyonu
Node* insert(Node* node, int key) {
    // 1. Standart BST Ekleme İşlemi
    if (node == nullptr)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Aynı anahtarlar AVL ağacında genellikle izin verilmez
        return node;

    // 2. Düğümün yüksekliğini güncelle
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Denge faktörünü kontrol et (Dengesizlik var mı?)
    int balance = getBalance(node);

    // 4. Dengesizlik varsa 4 durumdan birini uygula

    // Durum 1: Sol-Sol (Left Left Case)
    // Denge > 1 ve eklenen anahtar sol çocuğun solunda
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Durum 2: Sağ-Sağ (Right Right Case)
    // Denge < -1 ve eklenen anahtar sağ çocuğun sağında
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Durum 3: Sol-Sağ (Left Right Case)
    // Denge > 1 ve eklenen anahtar sol çocuğun sağında
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left); // Önce solu sola döndür
        return rightRotate(node); // Sonra düğümü sağa döndür
    }

    // Durum 4: Sağ-Sol (Right Left Case)
    // Denge < -1 ve eklenen anahtar sağ çocuğun solunda
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right); // Önce sağı sağa döndür
        return leftRotate(node); // Sonra düğümü sola döndür
    }

    // Dengesizlik yoksa düğümü olduğu gibi döndür
    return node;
}

// Ağacı test etmek için PreOrder (Önce Kök) Dolaşma
void preOrder(Node *root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node *root = nullptr;

    /* Örnek Senaryo:
       Sırayla 10, 20, 30, 40, 50, 25 ekliyoruz.
       Normal BST olsaydı sağa doğru uzayan bir çizgi olurdu (Skewed Tree).
       AVL olduğu için sürekli dengeleyecek.
    */

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /*
        Oluşması gereken AVL Ağacı:
              30
             /  \
           20    40
          /  \     \
        10   25    50
    */

    cout << "AVL Agacinin PreOrder Dolasimi: \n";
    preOrder(root);

    return 0;
}
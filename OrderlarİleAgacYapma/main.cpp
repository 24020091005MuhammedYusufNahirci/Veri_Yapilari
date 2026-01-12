#include <iostream>
#include <vector>

using namespace std;

// Ağaç Düğümü
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int key) {
        data = key;
        left = right = nullptr;
    }
};

// Bir elemanın inorder dizisindeki indeksini bulan yardımcı fonksiyon
int search(int arr[], int strt, int end, int value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Ağacı inşa eden ana recursive fonksiyon
// in[]    : Inorder dizisi
// level[] : Level order dizisi
// inStrt  : Inorder'da mevcut alt ağacın başlangıç indeksi
// inEnd   : Inorder'da mevcut alt ağacın bitiş indeksi
// n       : Level order dizisindeki eleman sayısı (mevcut alt ağaçtaki düğüm sayısı)
Node* buildTree(int in[], int level[], int inStrt, int inEnd, int n) {
    // 1. Baz Durum: Eğer eleman kalmadıysa NULL dön
    if (inStrt > inEnd)
        return nullptr;

    // 2. Level order dizisinin ilk elemanı KÖK'tür
    Node* root = new Node(level[0]);

    // Eğer sadece tek bir düğüm varsa, direkt döndür (yaprak düğüm)
    if (inStrt == inEnd)
        return root;

    // 3. Kökün Inorder dizisindeki yerini bul
    int inIndex = search(in, inStrt, inEnd, root->data);

    // 4. Level order dizisini "Sol Level" ve "Sağ Level" olarak ayır
    // Bunun için, Inorder dizisindeki sol tarafta hangi elemanların olduğunu bilmemiz gerek.
    // Sol alt ağaçtaki elemanları tutacak geçici bir Hash veya dizi mantığı kurulabilir.
    // Burada basitlik için level dizisini tarayıp, elemanın Inorder'ın solunda olup olmadığına bakacağız.

    // Sol alt ağacın level order'ını saklamak için dizi
    int* lLevel = new int[inIndex - inStrt];
    // Sağ alt ağacın level order'ını saklamak için dizi
    int* rLevel = new int[inEnd - inIndex];

    int li = 0, ri = 0; // lLevel ve rLevel sayaçları

    // Level order dizisini (kök hariç, 1'den başlayarak) gez
    for (int i = 1; i < n; i++) {
        // level[i] elemanını Inorder dizisinin sol parçasında ara
        // Sol parça: in[inStrt ... inIndex-1]
        int foundInLeft = search(in, inStrt, inIndex - 1, level[i]);

        if (foundInLeft != -1) {
            // Eğer Inorder'ın solunda bulunduysa, sol level dizisine ekle
            lLevel[li++] = level[i];
        } else {
            // Bulunamadıysa sağ taraftadır
            rLevel[ri++] = level[i];
        }
    }

    // 5. Recursive olarak sol ve sağ alt ağaçları oluştur
    // Sol alt ağaç için: Inorder (inStrt -> inIndex-1), Level (lLevel), Boyut (li)
    root->left = buildTree(in, lLevel, inStrt, inIndex - 1, li);

    // Sağ alt ağaç için: Inorder (inIndex+1 -> inEnd), Level (rLevel), Boyut (ri)
    root->right = buildTree(in, rLevel, inIndex + 1, inEnd, ri);

    // Bellek temizliği
    delete[] lLevel;
    delete[] rLevel;

    return root;
}

// Test için Inorder yazdırma fonksiyonu
void printInorder(Node* node) {
    if (node == nullptr)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main() {
    int in[] = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 14, 10};
    int n = sizeof(in) / sizeof(in[0]);

    cout << "Inorder: ";
    for(int x : in) cout << x << " ";
    cout << "\nLevel Order: ";
    for(int x : level) cout << x << " ";
    cout << "\n----------------------------\n";

    Node* root = buildTree(in, level, 0, n - 1, n);

    cout << "Olusturulan Agacin Inorder Gezintisi (Kontrol): ";
    printInorder(root);
    cout << endl;

    return 0;
}
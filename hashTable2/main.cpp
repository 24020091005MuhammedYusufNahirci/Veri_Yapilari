#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Hash {
    int BUCKET;    // Kaç adet yuva (bucket) olacağı
    list<int> *table; // Her yuvada bir liste tutan pointer dizisi

public:
    // Yapıcı Fonksiyon (Constructor)
    Hash(int V) {
        this->BUCKET = V;
        table = new list<int>[V]; // V boyutunda liste dizisi oluştur
    }

    // Hash Fonksiyonu: Değeri anahtara (indekse) dönüştürür
    int hashFunction(int x) {
        return (x % BUCKET);
    }

    // Tabloya eleman ekleme
    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key); // İlgili listenin sonuna ekle
    }

    // Tablodan eleman silme
    void deleteItem(int key) {
        // 1. Anahtarın indeksini bul
        int index = hashFunction(key);

        // 2. O indeksteki listede elemanı ara
        // (std::list olduğu için iterator kullanıyoruz)
        list<int>::iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++) {
            if (*i == key) {
                break; // Elemanı bulduk, döngüden çık
            }
        }

        // 3. Eğer eleman bulunduysa (iterator listenin sonuna gelmediyse) sil
        if (i != table[index].end()) {
            table[index].erase(i);
        }
    }

    // Hash tablosunu yazdırma
    void displayHash() {
        for (int i = 0; i < BUCKET; i++) {
            cout << i;
            for (auto x : table[i]) {
                cout << " --> " << x;
            }
            cout << endl;
        }
    }
};

// Sürücü Program
int main() {
    // Verilen dizi
    vector<int> a = {15, 11, 27, 8, 12};
    int n = a.size();

    // 7 yuvalı bir Hash tablosu oluştur
    Hash h(7);

    // Elemanları ekle
    for (int i = 0; i < n; i++) {
        h.insertItem(a[i]);
    }

    // 12 sayısını sil
    h.deleteItem(12);

    // Tabloyu yazdır
    h.displayHash();

    return 0;
}
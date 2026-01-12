#include <iostream>
#include <vector>
#include <queue>     // priority_queue için
#include <functional> // greater ve less karşılaştırıcıları için

using namespace std;

// En Büyük K elemanı bulan ve yazdıran fonksiyon
void kLargest(const vector<int>& arr, int k) {
    // Min-Heap Tanımlaması (En küçük sayı tepede durur)
    // priority_queue<VeriTipi, Konteyner, Karşılaştırıcı>
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int n = arr.size();

    // 1. ADIM: İlk k elemanı yığına ekle
    for (int i = 0; i < k; ++i) {
        minHeap.push(arr[i]);
    }

    // 2. ADIM: Kalan elemanları (k'dan n'e kadar) kontrol et
    for (int i = k; i < n; ++i) {
        // Eğer sıradaki eleman, yığının tepesindeki (yani şu anki en büyüklerin en küçüğü)
        // elemandan büyükse, değişim yap.
        if (arr[i] > minHeap.top()) {
            minHeap.pop();      // En küçüğü at
            minHeap.push(arr[i]); // Yeniyi ekle
        }
    }

    // 3. ADIM: Sonuçları yazdır
    cout << "Dizideki en buyuk " << k << " eleman: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

// En Küçük K elemanı bulan fonksiyon (Ekstra Örnek)
void kSmallest(const vector<int>& arr, int k) {
    // Max-Heap Tanımlaması (Varsayılan halidir, en büyük tepede durur)
    priority_queue<int> maxHeap;
    int n = arr.size();

    for (int i = 0; i < k; ++i) {
        maxHeap.push(arr[i]);
    }

    for (int i = k; i < n; ++i) {
        // Eğer sıradaki eleman, tepedeki (en küçüklerin en büyüğü) elemandan küçükse
        if (arr[i] < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    cout << "Dizideki en kucuk " << k << " eleman: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
}

int main() {
    // Örnek Dizi
    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;

    cout << "Dizi: {1, 23, 12, 9, 30, 2, 50}" << endl;
    cout << "k: " << k << endl;
    cout << "---------------------------------" << endl;

    // En Büyük K Elemanı Bul
    kLargest(arr, k);

    // En Küçük K Elemanı Bul
    kSmallest(arr, k);

    return 0;
}
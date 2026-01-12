#include <iostream>
#include <vector>
#include <queue> // priority_queue için

using namespace std;

void printKSmallest(const vector<int>& arr, int k) {
    int n = arr.size();

    // Max-Heap Tanımlaması (Tepede en büyük sayıyı tutar)
    priority_queue<int> maxHeap;

    // 1. ADIM: İlk k elemanı olduğu gibi yığına at
    for (int i = 0; i < k; i++) {
        maxHeap.push(arr[i]);
    }

    // 2. ADIM: Kalan elemanları (k'dan n'e kadar) tara
    for (int i = k; i < n; i++) {
        // Eğer şu anki sayı (arr[i]), yığının tepesindeki sayıdan küçükse:
        // Demek ki bu sayı, yığındaki o büyük sayıdan daha değerli (daha küçük).
        if (arr[i] < maxHeap.top()) {
            maxHeap.pop();      // O büyük sayıyı at
            maxHeap.push(arr[i]); // Yeni küçük sayıyı ekle
        }
    }

    // 3. ADIM: Yığında kalanlar en küçük k elemandır. Yazdıralım.
    cout << "Dizideki en kucuk " << k << " eleman: ";

    // Yığın yapısı gereği veriler sırasız çıkabilir (tepeden pop ettikçe).
    // Düzgün yazdırmak için bir vektöre alıp sonra yazdırabiliriz
    // veya direkt yığından çıkararak yazdırabiliriz (büyükten küçüğe çıkar).
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
}

int main() {
    // Örnek Girdi
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    cout << "Girdi Dizi: {7, 10, 4, 3, 20, 15}" << endl;
    cout << "k: " << k << endl;
    cout << "---------------------------------" << endl;

    printKSmallest(arr, k);

    return 0;
}
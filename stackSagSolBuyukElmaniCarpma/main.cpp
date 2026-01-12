#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Maksimum LR Çarpımını bulan fonksiyon
long long getMaxLRProduct(const vector<int>& arr) {
    int n = arr.size();

    // 0 elemanı olmadığı durumlarda kullanılacak varsayılan değerler
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    stack<int> s; // İndeksleri tutacak yığın (stack)

    // 1. ADIM: LEFT dizisini doldurma (Soldan sağa tarama)
    for (int i = 0; i < n; ++i) {
        // Yığındaki eleman şu anki elemandan küçük veya eşitse çıkar (pop)
        // Çünkü biz "daha büyük" olanı arıyoruz.
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }

        // Eğer yığın boş değilse, tepedeki eleman solumuzdaki en yakın büyük sayıdır.
        if (!s.empty()) {
            left[i] = s.top() + 1; // 1-based index olması için +1
        } else {
            left[i] = 0; // Sol tarafta büyük eleman yok
        }

        // Şu anki indeksi yığına ekle
        s.push(i);
    }

    // Yığını temizle (Right hesaplaması için tekrar kullanacağız)
    while (!s.empty()) s.pop();

    // 2. ADIM: RIGHT dizisini doldurma (Sağdan sola tarama)
    for (int i = n - 1; i >= 0; --i) {
        // Yığındaki eleman şu anki elemandan küçük veya eşitse çıkar
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }

        // Eğer yığın boş değilse, tepedeki eleman sağımızdaki en yakın büyük sayıdır.
        if (!s.empty()) {
            right[i] = s.top() + 1; // 1-based index olması için +1
        } else {
            right[i] = 0; // Sağ tarafta büyük eleman yok
        }

        // Şu anki indeksi yığına ekle
        s.push(i);
    }

    // 3. ADIM: Maksimum LR çarpımını hesaplama
    long long maxProduct = 0;
    for (int i = 0; i < n; ++i) {
        // left[i] ve right[i] değerlerini çarp
        long long currentProduct = (long long)left[i] * right[i];
        if (currentProduct > maxProduct) {
            maxProduct = currentProduct;
        }
    }

    return maxProduct;
}

int main() {
    // Örnek 1
    vector<int> arr1 = {1, 1, 1, 1, 0, 1, 1, 1, 1, 1};
    cout << "Input: [1, 1, 1, 1, 0, 1, 1, 1, 1, 1]" << endl;
    cout << "Output: " << getMaxLRProduct(arr1) << endl;
    // Beklenen: 24 (0 elemanının solu 4. indeks, sağı 6. indeks -> 4*6=24)

    cout << "---------------------------" << endl;

    // Örnek 2
    vector<int> arr2 = {5, 4, 3, 4, 5};
    cout << "Input: [5, 4, 3, 4, 5]" << endl;
    cout << "Output: " << getMaxLRProduct(arr2) << endl;
    // Beklenen: 8 (3 elemanının solu 2. indeks, sağı 4. indeks -> 2*4=8)

    return 0;
}
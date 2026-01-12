#include <iostream>
#include <vector>

using namespace std;

// Bir alt ağacı Max-Heap haline getiren fonksiyon (Heapify)
// i: Düzenlenecek düğümün indeksi
// n: Dizinin boyutu
void MaxHeapify(vector<int>& arr, int i, int n) {
    int largest = i;       // Başlangıçta en büyüğü kök (i) olarak kabul et
    int left = 2 * i + 1;  // Sol çocuk indeksi
    int right = 2 * i + 2; // Sağ çocuk indeksi

    // Eğer sol çocuk varsa ve kökten büyükse
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Eğer sağ çocuk varsa ve şu anki en büyükten daha büyükse
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Eğer en büyük eleman kök değilse (değişiklik gerekiyorsa)
    if (largest != i) {
        swap(arr[i], arr[largest]); // Yer değiştir

        // Değişiklik yapılan alt dalın da heap özelliğini koruduğundan emin ol
        MaxHeapify(arr, largest, n);
    }
}

// Min-Heap'i Max-Heap'e dönüştüren fonksiyon
void convertMaxHeap(vector<int>& arr, int n) {
    // Yaprak olmayan son düğümden başla ve köke kadar git.
    // (n-2)/2 formülü son 'parent' düğümü verir.
    for (int i = (n - 2) / 2; i >= 0; --i) {
        MaxHeapify(arr, i, n);
    }
}

// Diziyi yazdırmak için yardımcı fonksiyon
void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    // Örnek Girdi: Geçerli bir Min-Heap dizisi
    /*
             3
           /   \
          5     9
         / \   / \
        6   8 20 10
       / \  /
      12 18 9
    */
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = arr.size();

    cout << "Girdi (Min-Heap): ";
    printArray(arr);

    convertMaxHeap(arr, n);

    cout << "Cikti (Max-Heap): ";
    printArray(arr);

    return 0;
}
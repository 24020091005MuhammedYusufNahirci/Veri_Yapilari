#include <iostream>
#include <climits>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Az önceki MinHeap Sınıfınızın Basitleştirilmiş Hali
class MinHeap {
    int *harr;
    int capacity;
    int heap_size;

    public:
    MinHeap(int cap) {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    int extract_min();
    void MinHeapify(int i);
    void insertKey(int k);
};

void MinHeap::insertKey(int k) {
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extract_min() {
    if (heap_size <= 0) return INT_MAX;
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);
    return root;
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// --- PROBLEMİN ÇÖZÜM FONKSİYONU ---
int kthSmallest(int arr[], int n, int k) {
    // 1. Array boyutunda bir heap oluştur
    MinHeap h(n);

    // 2. Tüm elemanları heape at
    for (int i = 0; i < n; i++) {
        h.insertKey(arr[i]);
    }

    // 3. (k-1) tane elemanı çıkar (bunlar aradığımızdan küçük olanlar)
    for (int i = 0; i < k - 1; i++) {
        h.extract_min();
    }

    // 4. Kalanların en küçüğü (tepedeki) bizim cevabımızdır
    return h.extract_min();
}

int main() {
    int arr[] = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    cout << "Input Array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << "\nk = " << k << endl;

    cout << "k'th smallest element is " << kthSmallest(arr, n, k);
    return 0;
}
#include <iostream>
using namespace std;


void heapify(int arr[], int n, int i) {
    int largest = i;
    int l=2*i+1;
    int r=2*i+2;
    // Sol çocuk kökten büyükse
    if (l<n && arr[l] > arr[largest]) {
        largest = l;
    }
    // Sağ çocuk şu anki en büyükten büyükse
    if (r<n && arr[r] > arr[largest]) {
        largest = r;
    }
    // Eğer en büyük eleman kök değilse
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // 1. ADIM: Diziyi Max Heap haline getir (Build Heap)
    // Son yaprak olmayan düğümden (n/2 - 1) başlayarak yukarı doğru gideriz.
    for (int i = n/2-1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // 2. ADIM: Yığından elemanları tek tek çıkar
    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        // Azaltılmış yığında (i. eleman artık sıralı kısımda) tekrar heapify çağır
        // Kök bozulduğu için sadece kök (0) üzerinde çağırmak yeterlidir.
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
        cout<<"\n";
    }
}


int main() {
    int arr[]={12,11,13,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"orjinal dizi: \n";
    printArray(arr, n);

    heapSort(arr, n);
    cout<< "siralanmis dizi\n";
    printArray(arr, n);
}
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
//basit ve en yavaş best: O(N) worst:O(N^2)
//baştan sona tara iki lemanı kıyasla değiştir.
void bubbleSort(vector<int> arr) {
    int n = arr.size;
    bool swapped;

    for (int i = 0; i < n-1; i++) {
        swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

//seçmeli sıralama sıralı ve sırasız olarak ikiye böler
//sırasızda en küçüğü bul
//sırasız kısmın başında elemanla değiştir
//sınırı sağa kaydır
//her durumda o(N^2) avantajı daha az swwap

void selectionSort(vector<int> arr) {
    int n=arr.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

//eklemeli sıralama basit algoritmaların en iyisi
//kağıt dizer gibi
//2.elemandan başla
//tmp skalar spnra araya ekler.
// O(N) N<20de quick sorttan daha hızlı

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

//insertion sortun gelişmiş hali
//insertion sorta eleman 1 birim kayar
// öncekiği önce uzaktan gap ile karşılaştırma yapar sonra aralığı küçült
//O(N^2), O(N^1.5) veya O(Nlog'2N)
void shellSort(vector<int>& arr) {
    int n = arr.size();

    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j=i;
            while (j >= gap && arr[j-gap] > temp) {
                arr[j] = arr[j-gap];
                j = j-gap;
            }
            arr[j] = temp;
        }
    }
}

// birleştirmeli sıralama merge
//diziyi ortadan ikiye böl
//alt dizileri özyinelemeli olarak sırala
// ikili sıralı alt diziyi tek bir sıralı dizi olacaak şekilde birleştir
// her durumda O(NlogN), ek bellek gerekir (O(N) space)

void mergeSort(vector<int> arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

void merge(vector<int> arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


//pratikte en hızlı genel amaçlı
// pivot seç; medyan
// parçala küçükleri sola, büyükleri sağa. pivotu araya at
//işlemi tekrarla iki tarafı için

void quickSort(vector<int> arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr ,low ,high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int partition(vector<int> arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}


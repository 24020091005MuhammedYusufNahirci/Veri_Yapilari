#include <iostream>
#include <climits>
using namespace std;


void swap(int *x, int *y);

class MinHeap {
    int *harr;      // Heap elemanlarını tutacak dizi işaretçisi
    int capacity;   // Heap'in alabileceği maksimum eleman sayısı
    int heap_size;  // Heap'te şu an bulunan eleman sayısı

    public:
    MinHeap(int capacity);

    // Bir alt ağacı (subtree) Min Heap kuralına uygun hale getiren fonksiyon.
    // Genellikle kök bozulduğunda aşağıya doğru düzeltme (heapify-down) yapar.
    void MinHeapify(int i);

    // Bir düğümün ebeveyninin (parent) indeksini döndürür
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Bir düğümün sol çocuğunun indeksini döndürür
    int left(int i) {
        return 2 * i + 1;
    }

    // Bir düğümün sağ çocuğunun indeksini döndürür
    int right(int i) {
        return 2 * i + 2;
    }

    // En küçük elemanı (kökü) çeker ve heap'ten siler
    int extract_min();

    // İndeksi verilen elemanın değerini daha küçük bir değerle günceller
    void decrease_key(int i, int new_value);

    // Heap'teki en küçük elemanı (kökü) silmeden sadece okur
    int get_min() {
        return harr[0];
    }

    // İndeksi verilen bir anahtarı (key) siler
    void deleteKey(int i);

    // Heap'e yeni bir anahtar ekler
    void insertKey(int k);
};

// Kurucu Fonksiyon: Kapasiteyi belirler ve diziyi oluşturur
MinHeap::MinHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Yeni eleman ekleme fonksiyonu
void MinHeap::insertKey(int k) {
    if (heap_size == capacity) {
        cout << "\n Heap dolu, ekleme yapılamadı";
        return;
    }

    // 1. Adım: Yeni elemanı heap'in en sonuna ekle
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // 2. Adım: Min Heap kuralı sağlanana kadar yukarı taşı (Bubble-Up)
    // Eğer yeni eleman ebeveyninden küçükse yer değiştirirler.
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i); // Bir üst seviyeye çık
    }
}

// Bir elemanın değerini azaltma fonksiyonu
void MinHeap::decrease_key(int i, int new_val) {
    harr[i] = new_val; // Değeri güncelle

    // Min Heap kuralını korumak için, değer küçüldüğü için yukarı doğru çıkması gerekebilir.
    // Eleman ebeveyninden küçük olduğu sürece yukarı taşınır (Bubble-Up).
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// En küçük elemanı (kökü) silme ve döndürme fonksiyonu
int MinHeap::extract_min() {
    if (heap_size <= 0) {
        return INT_MAX; // Heap boşsa hata/sınır değeri döndür
    }
    if (heap_size == 1) {
        heap_size--;
        return harr[0]; // Tek eleman varsa direkt döndür
    }

    // 1. Kökü (en küçüğü) sakla
    int root = harr[0];

    // 2. En sondaki elemanı köke taşı
    harr[0] = harr[heap_size - 1];
    heap_size--;

    // 3. Yeni kök muhtemelen büyüktür, aşağı doğru iterek düzelt (Heapify)
    MinHeapify(0);

    return root;
}

// Belirli bir indeksteki elemanı silme fonksiyonu
// Mantık: Elemanın değerini eksi sonsuz yap (en küçük olsun diye),
// böylece en tepeye çıkar. Sonra extract_min ile tepeyi sil.
void MinHeap::deleteKey(int i) {
    decrease_key(i, INT_MIN);
    extract_min();
}

// Heap düzenini sağlayan rekürsif (özyinelemeli) fonksiyon
// Bir düğümün (i), çocuklarından daha büyük olup olmadığını kontrol eder
// ve gerekirse yer değiştirerek aşağıya doğru düzeltir.
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i; // Başlangıçta en küçüğün 'i' olduğunu varsayıyoruz

    // Sol çocuk var mı ve mevcut en küçükten daha mı küçük?
    if (l < heap_size && harr[l] < harr[i]) {
        smallest = l;
    }

    // Sağ çocuk var mı ve şu ana kadar bulunan en küçükten (i veya l) daha mı küçük?
    // Not: Buradaki harr[smallest] düzeltmesi kritiktir.
    if (r < heap_size && harr[r] < harr[smallest]) {
        smallest = r;
    }

    // Eğer en küçük eleman 'i' (ebeveyn) değilse, yer değiştirme gerekir
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);

        // Yer değiştirmeden sonra alt ağaç bozulmuş olabilir, orayı da düzelt
        MinHeapify(smallest);
    }
}

// Pointer kullanarak değer takası yapan fonksiyon
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    MinHeap h(11);

    // Elemanları ekleyelim
    h.insertKey(3);
    h.insertKey(2);

    // 1 indeksli elemanı silelim (Heap yapısına göre değişebilir ama mantığı test eder)
    h.deleteKey(1);

    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);

    // Çıktıları test edelim
    cout << "Extract Min (En kucuk silindi ve yazildi): " << h.extract_min() << endl;
    cout << "Get Min (Su anki en kucuk): " << h.get_min() << endl;

    // Decrease Key testi: İndeks 2'deki değeri 1 yapıyoruz
    h.decrease_key(2, 1);
    cout << "Get Min after decrease (Guncelleme sonrasi en kucuk): " << h.get_min() << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool canArrange(vector<int>& arr, int k) {
    int n = arr.size();

    // 1. Adım: Eğer dizi boyutu tek ise, herkesin bir eşi olamaz.
    if (n % 2 != 0) {
        return false;
    }

    // 2. Adım: Kalanların frekansını (kaç adet olduklarını) tutan harita
    unordered_map<int, int> remainderFreq;

    for (int x : arr) {
        // Negatif sayıları da kapsamak için ((x % k) + k) % k formülü kullanılır
        // Ancak pozitif sayılar için doğrudan (x % k) yeterlidir.
        int rem = ((x % k) + k) % k;
        remainderFreq[rem]++;
    }

    // 3. Adım: Kalanları kontrol et
    for (auto i : remainderFreq) {
        int rem = i.first;   // Kalan değeri
        int count = i.second; // Bu kalana sahip kaç sayı var?

        // Durum A: Kalan 0 ise
        // Bu sayıların kendi aralarında eşleşmesi lazım, sayıları çift olmalı.
        if (rem == 0) {
            if (count % 2 != 0) return false;
        }
        // Durum B: Kalan tam k/2 ise (Örn: k=4, rem=2)
        // Bu sayıların da kendi aralarında eşleşmesi lazım (2+2=4), sayıları çift olmalı.
        else if (2 * rem == k) {
            if (count % 2 != 0) return false;
        }
        // Durum C: Genel durum (rem ve k-rem)
        // Kalanı 'rem' olanların sayısı, kalanı 'k-rem' olanlara eşit olmalı.
        else {
            if (remainderFreq[rem] != remainderFreq[k - rem]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    // Örnek 1
    vector<int> arr1 = {9, 7, 5, 3};
    int k1 = 6;
    /*
       Açıklama:
       9 % 6 = 3
       7 % 6 = 1
       5 % 6 = 5
       3 % 6 = 3
       Kalanlar: {3, 1, 5, 3} -> {1, 3, 3, 5}
       1'in eşi 5 (1 adet var, 5 de 1 adet) -> Tamam.
       3'ün eşi 3 (k/2 durumu, 2 adet var) -> Tamam.
       Sonuç: True
    */
    if (canArrange(arr1, k1))
        cout << "Output 1: True (Eslestirilebilir)" << endl;
    else
        cout << "Output 1: False (Eslestirilemez)" << endl;


    // Örnek 2
    vector<int> arr2 = {9, 7, 5, 3};
    int k2 = 5;
    /*
       Açıklama:
       Kalanlar: 4, 2, 0, 3
       0 tek başına kaldı (eşi yok).
       Sonuç: False
    */
    if (canArrange(arr2, k2))
        cout << "Output 2: True" << endl;
    else
        cout << "Output 2: False" << endl;

    return 0;
}
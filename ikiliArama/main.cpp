#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ikiliArama(vector<int>& dizi, int arananDeger) {
    sort(dizi.begin(), dizi.end()); // Önce diziyi sırala
    int sol = 0;
    int sag = dizi.size() - 1;

    while (sol <= sag) {
        int orta = (sol + sag) / 2;
        if (dizi[orta] == arananDeger) {
            cout << "Bulundu: " << orta << endl;
            return true;
        }
        else if (dizi[orta] < arananDeger) {
            sol = orta + 1;
        }
        else {
            sag = orta - 1;
        }
    }
    cout << "Deger bulunamadi." << endl;
    return false;
}

int main() {
    vector<int> sayilar = {7, 1, 11, 3, 15, 9, 5, 13};

    int aranan;
    cout << "Aranacak degeri giriniz: ";
    cin >> aranan;

    ikiliArama(sayilar, aranan);

    return 0;
}

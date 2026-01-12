#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& a, vector<int>& b) {
    // 1. Adım: İlk dizinin frekans haritasını çıkar
    // Anahtar: Sayı, Değer: Kaç adet olduğu
    unordered_map<int, int> counts;
    vector<int> res;

    for (int num : a) {
        counts[num]++;
    }


    // 2. Adım: İkinci diziyi gez ve harita ile karşılaştır
    for (int num : b) {
        // Eğer sayı haritada varsa ve adedi 0'dan büyükse
        if (counts[num] > 0) {
            res.push_back(num); // Sonuca ekle
            counts[num]--;      // Haritadaki adedini 1 azalt (kullandık)
        }
    }

    return res;
}

int main() {
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> ress = intersect(a, b);
    for (int i = 0; i < ress.size(); i++) {
        cout << ress[i] << " ";
    }
    cout << endl;

    return 0;
}
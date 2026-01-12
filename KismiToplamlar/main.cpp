#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

vector<long long> kareselToplam(const vector <int>& A) {
    int n = A.size();
    vector<long long> S(n);  // Sonuç dizisi (long long taşma olmasın diye)
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += A[j];
        }
        S[i] = sum;
    }
    return S;
}

vector<long long> dogrudanToplam(const vector <int>& A) {
    int n = A.size();
    vector<long long> S(n);
    S[0] = A[0];
    for (int i = 1; i < n; i++) {
        S[i] = S[i-1] + A[i];
    }
    return S;
}

vector<int> randomSayı(int n) {
    vector<int> A(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, INT_MAX);
    for (int i = 0; i < n; i++) {
        A[i] = dis(gen);
    }
    return A;
}

int main() {
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    cout << "n\t\tO(n^2) (mikrosaniye)\tO(n) (mikrosaniye)" << endl;
    cout << "----------------------------------------------------------" << endl;

    for (int n : sizes) {
        vector<int> A = randomSayı(n);

        auto start = high_resolution_clock::now();
        kareselToplam(A);
        auto end1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(end1 - start).count();

        auto start2 = high_resolution_clock::now();
        dogrudanToplam(A);
        auto end2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(end2 - start2).count();

        cout << n << "\t\t         " << duration1 << "    \t\t" << duration2 << endl;
    }
    return 0;
}

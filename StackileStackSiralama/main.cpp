#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Yığını sıralayan fonksiyon
stack<int> sortStack(stack<int> &input) {
    stack<int> tmpStack;

    while (!input.empty()) {
        // 1. Input yığınından elemanı al
        int temp = input.top();
        input.pop();

        // 2. tmpStack boş değilse ve tepesindeki eleman temp'ten BÜYÜKSE,
        // o elemanları input yığınına geri gönder.
        // (Çünkü temp daha küçük, onların altına girmeli)
        while (!tmpStack.empty() && tmpStack.top() > temp) {
            input.push(tmpStack.top());
            tmpStack.pop();
        }

        // 3. Doğru konumu bulduk, temp'i tmpStack'e ekle
        tmpStack.push(temp);
    }

    return tmpStack;
}

// Yığını yazdırmak için yardımcı fonksiyon (Yığını boşaltmadan kopyasını yazdırır)
void printStack(stack<int> s) {
    // Stack LIFO (Last In First Out) olduğu için,
    // sıralı yazdırmak adına önce bir vektöre aktarıyoruz.
    vector<int> displayVec;
    while(!s.empty()){
        displayVec.push_back(s.top());
        s.pop();
    }

    // Vektör şu an [En Büyük, ..., En Küçük] şeklinde.
    // Örnek çıktıdaki gibi [3, 23...] formatı için tersten yazdıralım:
    cout << "[";
    for(int i = displayVec.size() - 1; i >= 0; i--) {
        cout << displayVec[i];
        if(i > 0) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    // Örnek Girdi: [34, 3, 31, 98, 92, 23]
    // Not: Stack'e push yaparken dizideki sırayla eklersek
    // 23 en son eklenen (top) olur. Trace'e göre ilk 23 çıkıyor.
    stack<int> inputStack;
    inputStack.push(34);
    inputStack.push(3);
    inputStack.push(31);
    inputStack.push(98);
    inputStack.push(92);
    inputStack.push(23);

    cout << "Orijinal Yığın (Input): ";
    printStack(inputStack);

    // Sıralama işlemi
    stack<int> sortedStack = sortStack(inputStack);

    cout << "Sıralanmış Yığın (Output): ";
    printStack(sortedStack);

    return 0;
}
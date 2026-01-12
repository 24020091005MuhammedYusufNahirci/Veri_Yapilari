#include <iostream>

// 2. Değer ile Değiştirme (Swap By Value)
// Bu fonksiyonda yapılan değişiklikler orijinal değişkenleri (a ve b) etkilemez.
void swapByValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    std::cout << "swapByValue icinde: a = " << x << ", b = " << y << std::endl;
    // Orijinal a ve b degismez!
}

// 3. Referans ile Değiştirme (Swap By Reference)
// x ve y, orijinal a ve b degiskenlerinin kendisidir (referansidir).
// Bu fonksiyonda yapilan degisiklikler orijinal degiskenleri etkiler.
void swapByReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
    std::cout << "swapByReference icinde: a = " << x << ", b = " << y << std::endl;
    // Orijinal a ve b degisir!
}

// 4. Pointer (İşaretçi) ile Değiştirme (Swap By Pointer)
// *x ve *y, orijinal a ve b degiskenlerinin bellek adresindeki degeri temsil eder.
// Bu fonksiyonda yapilan degisiklikler orijinal degiskenleri etkiler.
void swapByPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    std::cout << "swapByPointer icinde: a = " << *x << ", b = " << *y << std::endl;
    // Orijinal a ve b degisir!
}

int main() {
    int a = 10;
    int b = 20;

    std::cout << "Baslangic degerleri: a = " << a << ", b = " << b << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // 2. swapByValue'yu çağırma ve sonucu gözlemleme
    std::cout << "2. swapByValue cagriliyor (a=10, b=20):" << std::endl;
    swapByValue(a, b);
    std::cout << "swapByValue sonrasi: a = " << a << ", b = " << b << std::endl; // a=10, b=20 kalir (degismez)
    std::cout << "----------------------------------------" << std::endl;

    // Degiskenleri baslangic degerlerine geri alalim (Gerekli degil ama karsilastirmak icin yapalim)
    a = 10;
    b = 20;

    // 3. swapByReference'ı çağırma ve sonucu gözlemleme
    std::cout << "3. swapByReference cagriliyor (a=10, b=20):" << std::endl;
    swapByReference(a, b);
    std::cout << "swapByReference sonrasi: a = " << a << ", b = " << b << std::endl; // a=20, b=10 olur (degisir)
    std::cout << "----------------------------------------" << std::endl;

    // Degiskenleri tekrar baslangic degerlerine geri alalim (Pointer ile karsilastirmak icin)
    a = 10;
    b = 20;

    // 4. swapByPointer'ı çağırma ve sonucu gözlemleme
    std::cout << "4. swapByPointer cagriliyor (a=10, b=20):" << std::endl;
    swapByPointer(&a, &b); // Fonksiyona degiskenlerin adresini gonderiyoruz
    std::cout << "swapByPointer sonrasi: a = " << a << ", b = " << b << std::endl; // a=20, b=10 olur (degisir)
    std::cout << "----------------------------------------" << std::endl;

    return 0;
}
#include "Dikdortgen.h"
#include <iostream>

int main() {
    std::cout << "--- D1 Nesnesi (Varsayilan Yapici) ---" << std::endl;
    Dikdortgen d1;

    d1.bilgileriYazdir();


    std::cout << "\n--- D2 Nesnesi (Parametreli Yapici) ---" << std::endl;
    Dikdortgen d2(5.5, 3.2);


    d2.bilgileriYazdir();

    std::cout << "\n**Sadece Hesaplama Sonucu**" << std::endl;
    std::cout << "d2'nin Alani: " << d2.alanHesapla() << std::endl;
    std::cout << "d2'nin Cevresi: " << d2.cevreHesapla() << std::endl;

    return 0;
}
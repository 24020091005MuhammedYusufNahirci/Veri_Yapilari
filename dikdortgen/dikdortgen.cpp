#include "Dikdortgen.h"
#include <iostream>

// Varsayılan Yapıcı (Constructor)
// Varsayılan değerler atayalım
Dikdortgen::Dikdortgen() {
    genislik = 0;
    yukseklik = 0;
    std::cout << "Varsayilan Dikdortgen olusturuldu." << std::endl;
}

// Parametreli Yapıcı (Constructor)
// Gelen değerleri üye değişkenlere atayalım
Dikdortgen::Dikdortgen(double g, double y) {
    genislik = g;
    yukseklik = y;
    std::cout << "Parametreli Dikdortgen olusturuldu." << std::endl;
}


double Dikdortgen::alanHesapla() {
    return genislik * yukseklik;
}

double Dikdortgen::cevreHesapla() {
    return 2 * (genislik + yukseklik);
}

void Dikdortgen::bilgileriYazdir() {
    std::cout << "--- Dikdortgen Bilgileri ---" << std::endl;
    std::cout << "Genislik: " << genislik << std::endl;
    std::cout << "Yukseklik: " << yukseklik << std::endl;
    std::cout << "Alan: " << alanHesapla() << std::endl;
    std::cout << "Cevre: " << cevreHesapla() << std::endl;
    std::cout << "----------------------------" << std::endl;
}
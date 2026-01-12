#ifndef DIKDORTGEN_H
#define DIKDORTGEN_H

class Dikdortgen {
private:
    // a. private üyeler: genislik, yukseklik (double tipinde).
    double genislik;
    double yukseklik;

public:
    // i. Bir varsayilan yapici metot (constructor).
    Dikdortgen();

    // ii. Genislik ve yuksekligi parametre alan bir yapici metot.
    Dikdortgen(double g, double y);

    // iii. alanHesapla() metodu.
    double alanHesapla();

    // iv. cevreHesapla() metodu.
    double cevreHesapla();

    // v. bilgileriYazdir() metodu.
    void bilgileriYazdir();
};

#endif // DIKDORTGEN_H
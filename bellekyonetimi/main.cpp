#include <iostream> // Giriş/Çıkış işlemleri için
#include <cstdlib>  // Rastgele sayı üretimi için (rand, srand)
#include <ctime>    // Rastgele sayı üreteci için tohum (seed) belirlemek için (time)

using namespace std;

int main() {
    // 1. Kullanıcıdan bir tam sayı (n) alın.
    int n;
    cout << "Lütfen dizinin eleman sayısını (n) girin: ";
    cin >> n;

    // Geçersiz giriş kontrolü (negatif veya sıfır eleman sayısı)
    if (n <= 0) {
        cout << "Geçersiz eleman sayısı girdiniz. Program sonlandırılıyor." << endl;
        return 1; // Hata koduyla çıkış
    }

    // --- Bellek Ayırma ---

    // 2. new operatörünü kullanarak n elemanlı bir int dizisi için bellekten yer ayırın
    //    ve bir işaretçide adresini tutun.
    int *dinamikDizi = nullptr; // Başlangıçta işaretçiyi boş (nullptr) yapıyoruz.
    try {
        dinamikDizi = new int[n]; // n elemanlı int dizisi için dinamik bellek ayırma
    } catch (const bad_alloc& e) {
        // Bellek ayırma başarısız olursa (örneğin bellek yetersizliği)
        cerr << "Hata: Bellek ayrılamadı. " << e.what() << endl;
        return 1;
    }

    // Rastgele sayı üreteci için tohumu (seed) ayarla
    srand(time(0));

    // 3. Bu diziyi rastgele sayılarla doldurun ve ekrana yazdırın.
    cout << "\nOluşturulan Dinamik Dizi Elemanları:" << endl;
    for (int i = 0; i < n; ++i) {
        // 0 ile 99 arasında rastgele sayılar atayalım.
        dinamikDizi[i] = rand() % 100;
        cout << "Dizi[" << i << "] = " << dinamikDizi[i] << endl;
    }

    // --- Belleği Serbest Bırakma ---

    // 4. delete[] operatörünü kullanarak ayırdığınız belleği sisteme geri iade edin.
    //    Bu adımın önemini vurgulayın (bellek sızıntısını - memory leak - önlemek).
    delete[] dinamikDizi;
    dinamikDizi = nullptr; // İşaretçiyi boş (nullptr) yaparak "sarkan işaretçi" olmasını engellemek de iyi bir uygulamadır.

    cout << "\nAyırılan bellek delete[] operatörü ile sisteme geri iade edildi." << endl;
    cout << "Bellek sızıntısı (memory leak) önlenmiş oldu." << endl;

    return 0;
}
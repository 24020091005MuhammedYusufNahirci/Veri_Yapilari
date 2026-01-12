#include <iostream>
#include "Playlist.h"
using namespace std;

int main() {
    Playlist pl;
    int secim;

    while (true) {
        system("cls");

        // ÇALAN ŞARKIYI GÖSTERME
        Node* cur = pl.getCurrent();
        cout << "===== Calan Sarki =====\n";
        if (cur == nullptr) {
            cout << "Su anda hic sarki calmiyor.\n";
        } else {
            cout << cur->data.title << " - " << cur->data.artist << "\n";
        }
        cout << "Repeat Modu: " << (pl.getRepeatStatus() ? "ACIK" : "KAPALI") << "\n";
        cout << "======================\n";


        cout << "1) Sarki Ekle\n";
        cout << "2) Sarki Sil (Basliga Gore)\n";
        cout << "3) Su Anki Sarkiyi Cal\n";
        cout << "4) Sonraki Sarki\n";
        cout << "5) Onceki Sarki\n";
        cout << "6) Tekrar Modunu Ac/Kapat\n";
        cout << "7) Tum Sarkilari Listele\n";
        cout << "0) Cikis\n";
        cout << "Secim: ";
        cin >> secim;
        cin.ignore();

        switch (secim) {
            case 0:
                cout << "Programdan cikiliyor...\n";
                return 0;

            case 1: {
                string title, artist;
                cout << "Sarki adi: "; getline(cin, title);
                cout << "Sanatci: "; getline(cin, artist);
                pl.addSong({title, artist});
                cout << "Sarki eklendi.\n";
                system("pause");
                break;
            }

            case 2: {
                string title;
                cout << "Silinecek sarki adi: "; getline(cin, title);
                if (pl.removeSong(title))
                    cout << "Sarki silindi.\n";
                else
                    cout << "Sarki bulunamadi.\n";
                system("pause");
                break;
            }

            case 3:
                pl.playCurrent();
                system("pause");
                break;

            case 4:
                pl.nextSong();
                pl.playCurrent();
                system("pause");
                break;

            case 5:
                pl.prevSong();
                pl.playCurrent();
                system("pause");
                break;

            case 6:
                pl.toggleRepeat();
                system("pause");
                break;

            case 7:
                pl.printPlaylist();
                system("pause");
                break;

            default:
                cout << "Gecersiz secim!\n";
                system("pause");
        }
    }

    return 0;
}

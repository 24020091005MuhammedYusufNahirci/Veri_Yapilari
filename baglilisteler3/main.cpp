#include <iostream>
#include "LinkedList.h"
using namespace std;
int main() {
    LinkedLiS list;
    int secim, value, aftervalue;

    while (true) {
        cout << "\n--- Dairesel Bagli Liste Menu ---\n";
        cout << "1 - Basa eleman ekle (push_front)\n";
        cout << "2 - Sona eleman ekle (push_back)\n";
        cout << "3 - Araya ekle (insert_after)\n";
        cout << "4 - Bastan sil (pop_front)\n";
        cout << "5 - Eleman sil (delete_Node)\n";
        cout << "6 - Listeyi yazdir (print_list)\n";
        cout << "7 - Eleman ara (Search)\n";
        cout << "0 - Cikis\n";
        cout << "Secim: ";
        cin >> secim;

        switch (secim) {

            case 1:
                cout << "Eklenecek deger: ";
                cin >> value;
                list.push_front(value);
                break;

            case 2:
                cout << "Eklenecek deger: ";
                cin >> value;
                list.push_back(value);
                break;

            case 3:
                cout << "Hangi degerden sonra ekleyeceksin? ";
                cin >> aftervalue;
                cout << "Eklenecek deger: ";
                cin >> value;
                list.insert_after(aftervalue, value);
                break;

            case 4:
                list.pop_front();
                cout << "Bastan eleman silindi.\n";
                break;

            case 5:
                cout << "Silinecek deger: ";
                cin >> value;
                list.delete_Node(value);
                break;

            case 6:
                cout << "Liste: ";
                list.print_list();
                break;

            case 7:
                cout << "Aranacak deger: ";
                cin >> value;
                list.Search(value);
                break;

            case 0:
                cout << "Cikis yapildi.\n";
                return 0;

            default:
                cout << "Hatali secim!\n";
        }
    }

    return 0;
}
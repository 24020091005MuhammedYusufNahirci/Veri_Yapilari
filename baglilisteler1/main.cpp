#include <iostream>
#include "LşnkedList.h"
using namespace std;

int main() {
    LşnkedList list;
    int choice, value;

    while (true) { // Sonsuz döngü
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Basa ekle\n";
        cout << "2. Sona ekle\n";
        cout << "3. Bastan sil\n";
        cout << "4. Listeyi yazdir\n";
        cout << "5. Deger ara\n";
        cout << "6. Cikis\n";
        cout << "Seciminiz: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Basa eklenecek degeri girin: ";
                cin >> value;
                list.push_front(value);
                list.print_list();
                break;
            case 2:
                cout << "Sona eklenecek degeri girin: ";
                cin >> value;
                list.push_back(value);
                list.print_list();
                break;
            case 3:
                list.pop_front();
                cout << "Bas ogesi silindi.\n";
                list.print_list();
                break;
            case 4:
                cout << "Liste: ";
                list.print_list();
                break;
            case 5:
                cout << "Aranacak degeri girin: ";
                cin >> value;
                list.Search(value);
                break;
            case 6:
                cout << "Program sonlandiriliyor.\n";
                return 0;
            default:
                cout << "Gecersiz secim!\n";
        }
    }

    return 0;
}

#include <iostream>

using namespace std;

// Bağlı Liste Düğüm Yapısı
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Yardımcı Fonksiyon: Döngüdeki eleman sayısını sayar
// n: slow ve fast pointerlarının buluştuğu düğüm
int countNodes(Node* n) {
    int res = 1; // Kendisini sayarak başlıyoruz
    Node* temp = n;

    // temp işaretçisi tekrar n'e gelene kadar dön
    while (temp->next != n) {
        res++;
        temp = temp->next;
    }
    return res;
}

// Ana Fonksiyon: Döngü uzunluğunu bulur
int countLoopLength(Node* head) {
    Node *slow = head;
    Node *fast = head;

    // 1. AŞAMA: Döngü tespiti (Floyd's Cycle Detection)
    while (slow && fast && fast->next) {
        slow = slow->next;       // 1 adım git
        fast = fast->next->next; // 2 adım git

        // Eğer işaretçiler buluşursa döngü var demektir
        if (slow == fast) {
            // 2. AŞAMA: Döngü uzunluğunu hesapla
            return countNodes(slow);
        }
    }

    // Döngü yoksa 0 döndür
    return 0;
}

// Yeni düğüm oluşturmak için yardımcı fonksiyon
Node* newNode(int key) {
    return new Node(key);
}

int main() {
    /* Örnek Bağlı Liste Oluşturma:
       1 -> 2 -> 3 -> 4 -> 5
                 ^         |
                 |_________|
       (5, 3'e bağlanarak döngü oluşturuyor)
    */

    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Döngüyü oluştur: Son düğümü (5), 3. düğüme (head->next->next) bağla
    head->next->next->next->next->next = head->next->next;

    int length = countLoopLength(head);

    if (length > 0)
        cout << "Dongunun uzunlugu: " << length << endl;
    else
        cout << "Listede dongu yok." << endl;

    return 0;
}
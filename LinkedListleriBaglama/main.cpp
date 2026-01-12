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

// İki sıralı listeyi birleştiren fonksiyon
Node* mergeSortedLists(Node* head1, Node* head2) {
    // 1. ADIM: Başlangıç için geçici bir "Dummy" düğüm oluştur.
    // Bu düğüm, sonuç listesinin başını kaybetmememizi sağlar.
    Node dummy(0);

    // Kuyruk işaretçisi (tail) başlangıçta dummy'i gösterir.
    Node* tail = &dummy;

    // 2. ADIM: İki liste de var olduğu sürece döngüye gir
    while (head1 != nullptr && head2 != nullptr) {

        // Hangi listenin elemanı daha küçükse onu kuyruğa ekle
        if (head1->data <= head2->data) {
            tail->next = head1;   // head1'i ekle
            head1 = head1->next;  // head1'i ilerlet
        } else {
            tail->next = head2;   // head2'yi ekle
            head2 = head2->next;  // head2'yi ilerlet
        }

        // Kuyruk işaretçisini yeni eklenen düğüme kaydır
        tail = tail->next;
    }

    // 3. ADIM: Listelerden biri bittiğinde, diğerinde kalanları direkt ekle.
    if (head1 != nullptr) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }

    // Dummy düğümünün (0) sonrasındaki gerçek listeyi döndür
    return dummy.next;
}

// Listeyi yazdırmak için yardımcı fonksiyon
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    /* Liste 1: 5 -> 10 -> 15
       Liste 2: 2 -> 3 -> 20
    */

    // Liste 1 Oluşturma
    Node* head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);

    // Liste 2 Oluşturma
    Node* head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    cout << "Liste 1: ";
    printList(head1);

    cout << "Liste 2: ";
    printList(head2);

    // Birleştirme İşlemi
    Node* result = mergeSortedLists(head1, head2);

    cout << "Birlestirilmis Liste: ";
    printList(result);

    return 0;
}
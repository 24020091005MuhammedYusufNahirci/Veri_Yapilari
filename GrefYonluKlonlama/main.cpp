#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Graf Düğümü Yapısı
class Node {
public:
    int val;
    vector<Node*> neighbors; // Komşuların listesi

    // Yapıcılar (Constructors)
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    // Orijinal düğüm adresini, kopyalanmış düğüm adresiyle eşleştiren harita
    unordered_map<Node*, Node*> map;

public:
    Node* cloneGraph(Node* node) {
        // 1. Baz Durum: Eğer düğüm boşsa işlem yapma
        if (node == nullptr) {
            return nullptr;
        }

        // 2. Kontrol: Eğer bu düğüm daha önce kopyalandıysa,
        // haritadan o kopyayı bul ve döndür.
        if (map.find(node) != map.end()) {
            return map[node];
        }

        // 3. Kopyalama: Yeni bir düğüm oluştur (Henüz komşuları yok)
        Node* copyNode = new Node(node->val);

        // 4. Kayıt: Bu düğümü ve kopyasını haritaya ekle
        // Bunu komşuları gezmeden ÖNCE yapmalıyız ki sonsuz döngü olmasın.
        map[node] = copyNode;

        // 5. Komşuları Kopyalama: Orijinal düğümün komşularını gez
        for (Node* neighbor : node->neighbors) {
            // Recursive çağrı ile komşuyu kopyala (veya varsa getir)
            // ve yeni düğümün komşu listesine ekle.
            copyNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return copyNode;
    }
};

// Yardımcı Fonksiyon: Grafı yazdırmak için (BFS ile gezer)
void printGraph(Node* node) {
    if (!node) return;

    unordered_map<Node*, bool> visited;
    vector<Node*> q; // Basit bir queue mantığı için vector
    q.push_back(node);
    visited[node] = true;

    int head = 0;
    while(head < q.size()){
        Node* curr = q[head++];
        cout << "Düğüm " << curr->val << " komsulari: [";
        for(auto neighbor : curr->neighbors){
            cout << neighbor->val << " ";
            if(visited.find(neighbor) == visited.end()){
                visited[neighbor] = true;
                q.push_back(neighbor);
            }
        }
        cout << "]" << endl;
    }
}

int main() {
    /*
        Örnek Graf Yapısı (DAG):
        0 -> 1
        0 -> 2
        1 -> 2
        2 -> 3
    */

    // Orijinal Grafı Oluşturma
    Node* node0 = new Node(0);
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    node0->neighbors.push_back(node1);
    node0->neighbors.push_back(node2);
    node1->neighbors.push_back(node2); // 1 de 2'ye gidiyor
    node2->neighbors.push_back(node3);

    cout << "--- Orijinal Graf ---" << endl;
    printGraph(node0);

    // Klonlama İşlemi
    Solution solver;
    Node* clonedGraphHead = solver.cloneGraph(node0);

    cout << "\n--- Klonlanmış Graf ---" << endl;
    printGraph(clonedGraphHead);

    // Adres Kontrolü (Deep Copy kanıtı)
    cout << "\n--- Adres Kontrolü ---" << endl;
    cout << "Orijinal Node 0 Adresi: " << node0 << endl;
    cout << "Klon    Node 0 Adresi: " << clonedGraphHead << endl;

    return 0;
}
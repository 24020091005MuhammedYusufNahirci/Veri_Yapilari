#include <iostream>
#include <vector>
#include <queue>
#include <functional> // greater için

using namespace std;

// Çiftleri tutmak için kısaltma: {ağırlık, düğüm}
// Priority Queue varsayılan olarak büyükten küçüğe sıralar,
// tersini yapmak (küçükten büyüğe) için 'pair' kullanacağız.
typedef pair<int, int> pii;

class Graph {
    int V; // Düğüm sayısı
    vector<vector<pii>> adj; // Komşuluk listesi: adj[u] -> {v, ağırlık}

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Grafa kenar ekleme (Yönsüz graf olduğu için iki taraflı eklenir)
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight}); // u -> v (ağırlık: weight)
        adj[v].push_back({u, weight}); // v -> u (ağırlık: weight)
    }

    // Prim Algoritması
    void primMST() {
        // Min-Heap (En küçük ağırlığı tepede tutan Priority Queue)
        // Format: priority_queue<VeriTipi, Konteyner, Karşılaştırıcı>
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        int src = 0; // Algoritmayı 0. düğümden başlatıyoruz

        // Key dizisi: Bir düğüme ulaşmak için gereken minimum ağırlığı tutar.
        vector<int> key(V, 1e9); // Başlangıçta sonsuz (INF)

        // Parent dizisi: MST'yi oluştururken hangi düğümden geldiğimizi tutar.
        vector<int> parent(V, -1);

        // inMST dizisi: Düğümün MST setine dahil edilip edilmediğini tutar.
        vector<bool> inMST(V, false);

        // Başlangıç düğümünü ayarla
        pq.push({0, src}); // {ağırlık, düğüm}
        key[src] = 0;

        while (!pq.empty()) {
            // 1. En küçük ağırlığa sahip düğümü kuyruktan al
            int u = pq.top().second;
            pq.pop();

            // Eğer bu düğüm zaten MST'ye eklendiyse atla (visited kontrolü)
            if (inMST[u] == true) {
                continue;
            }

            // Düğümü MST setine dahil et
            inMST[u] = true;

            // 2. Bu düğümün komşularını gez
            for (auto x : adj[u]) {
                int v = x.first;      // Komşu düğüm
                int weight = x.second; // Kenar ağırlığı

                // Eğer v MST'de DEĞİLSE ve (u-v) kenarı şu anki bilinen yoldan daha kısaysa
                if (inMST[v] == false && weight < key[v]) {
                    // Key değerini güncelle
                    key[v] = weight;
                    // Kuyruğa yeni ağırlıkla ekle
                    pq.push({key[v], v});
                    // Parent'ı güncelle (v'ye u'dan geldik)
                    parent[v] = u;
                }
            }
        }

        // Sonuçları Yazdır
        cout << "Edge \tWeight" << endl;
        int totalWeight = 0;
        for (int i = 1; i < V; ++i) { // 0 kök olduğu için 1'den başlarız
            cout << parent[i] << " - " << i << " \t" << key[i] << endl;
            totalWeight += key[i];
        }
        cout << "Total Cost of MST: " << totalWeight << endl;
    }
};

int main() {
    /*
        Örnek Graf:
           2    3
        (0)--(1)--(2)
         |   / \   |
        6| 8/   \5 |7
         | /     \ |
        (3)-------(4)
              9
    */
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primMST();

    return 0;
}
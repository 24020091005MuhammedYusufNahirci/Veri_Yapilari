#include <iostream>
#include <vector>
#include <algorithm> // sort fonksiyonu için

using namespace std;

// Kenar yapısını temsil eden struct
struct Edge {
    int src, dest, weight;
};

// Kenarları ağırlıklarına göre sıralamak için karşılaştırıcı fonksiyon
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set Union (DSU) Yapısı
// Döngü kontrolü ve kümeleri birleştirmek için kullanılır.
class DSU {
    int* parent;
    int* rank;

public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        // Başlangıçta her düğüm kendisinin ebeveynidir (kendi kümesindedir)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Bir elemanın ait olduğu kümenin kökünü bulur (Path Compression ile)
    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]); // Yolu kısaltarak kökü kaydet
        return parent[i];
    }

    // İki kümeyi birleştirir (Union by Rank ile)
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Rank'ı (derinliği) küçük olanı büyük olana bağla
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Graph {
    int V; // Düğüm sayısı
    vector<Edge> edges; // Tüm kenarların listesi

public:
    Graph(int V) {
        this->V = V;
    }

    // Kenar ekleme
    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    // Kruskal Algoritması
    void kruskalMST() {
        vector<Edge> result; // MST sonucunu tutacak dizi
        int e = 0; // Sonuçtaki kenar sayısı sayacı
        int i = 0; // Sıralanmış kenarlar üzerinde gezmek için indis

        // 1. ADIM: Tüm kenarları ağırlıklarına göre sırala
        sort(edges.begin(), edges.end(), compareEdges);

        // DSU yapısını oluştur
        DSU dsu(V);

        // V-1 adet kenar seçene kadar döngüye devam et
        while (e < V - 1 && i < edges.size()) {
            // 2. ADIM: En küçük kenarı al
            Edge next_edge = edges[i++];

            int x = dsu.find(next_edge.src);
            int y = dsu.find(next_edge.dest);

            // 3. ADIM: Eğer bu kenar döngü oluşturmuyorsa (farklı kümelerdelerse)
            if (x != y) {
                result.push_back(next_edge); // MST'ye ekle
                dsu.unite(x, y); // Kümeleri birleştir
                e++;
            }
            // Else: Döngü oluşturuyorsa (x == y), bu kenarı atla (hiçbir şey yapma)
        }

        // Sonuçları yazdır
        cout << "MST'ye Eklenen Kenarlar ve Agirliklari:" << endl;
        int minimumCost = 0;
        for (auto edge : result) {
            cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
            minimumCost += edge.weight;
        }
        cout << "Minimum Cost Spanning Tree: " << minimumCost << endl;
    }
};

int main() {
    /*
        Örnek Graf:
            10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4
    */
    int V = 4;
    Graph g(V);

    // addEdge(kaynak, hedef, ağırlık)
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();

    return 0;
}
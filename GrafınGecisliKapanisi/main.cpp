#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V; // Düğüm sayısı
    vector<vector<int>> adj; // Komşuluk listesi (Adjacency List)
    vector<vector<bool>> tc; // Transitive Closure Matrisi

    // DFS Yardımcı Fonksiyonu
    // s: source (başlangıç düğümü - aramanın başladığı kök)
    // v: current (şu an ziyaret edilen düğüm)
    void DFSUtil(int s, int v) {
        // Eğer s'den v'ye zaten ulaşıldıysa tekrar bakma (sonsuz döngüden kaçınmak için)
        /* Burada tc[s][v] == true olması, s kaynaklı aramada v'nin
           daha önce ziyaret edildiğini (visited) gösterir.
        */
        if (s != v && tc[s][v]) {
           return;
        }

        // s düğümünden v düğümüne erişilebiliyor olarak işaretle
        tc[s][v] = true;

        // v düğümünün tüm komşularına git
        for (int neighbor : adj[v]) {
            // Eğer s'den bu komşuya henüz gidilmediyse, oraya git
            if (!tc[s][neighbor]) {
                DFSUtil(s, neighbor);
            }
        }
    }

public:
    // Yapıcı Fonksiyon (Constructor)
    Graph(int V) {
        this->V = V;
        adj.resize(V);

        // Matrisi V*V boyutunda false (0) ile başlat
        tc.resize(V, vector<bool>(V, false));
    }

    // Grafa kenar ekleme
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Transitive Closure hesaplama ve yazdırma fonksiyonu
    void findTransitiveClosure() {
        // Grafın her düğümü için DFS başlat
        for (int i = 0; i < V; i++) {
            DFSUtil(i, i); // i: kaynak, i: şu anki düğüm
        }

        // Sonuç matrisini yazdır
        cout << "Transitive Closure Matrisi:" << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << tc[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Örnek: 4 düğümlü bir graf (0, 1, 2, 3)
    Graph g(4);

    /*
       Graf Yapısı:
       0 -> 1 -> 3
       ^    |
       |    v
       2    2 (1'den 2'ye kenar var)

       Eklenen Kenarlar:
       0 -> 1
       0 -> 2
       1 -> 2
       2 -> 0
       2 -> 3
       3 -> 3
    */

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.findTransitiveClosure();

    return 0;
}
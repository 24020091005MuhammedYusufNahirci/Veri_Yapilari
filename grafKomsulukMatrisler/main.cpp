#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int V;
    vector<list<int>> adj;

    // DFS için yardımcı fonksiyon (Recursive/Özyinelemeli)
    // Bunu private yapıyoruz çünkü dışarıdan visited dizisini göndermekle uğraşmamalıyız.
    void DFSUtil(int v, vector<bool> &visited) {
        // Şu anki düğümü ziyaret edildi olarak işaretle ve yazdır
        visited[v] = true;
        cout << v << " ";

        // Bu düğüme komşu olanlar için tekrar et
        for (int neighbour : adj[v]) {
            if (!visited[neighbour]) {
                DFSUtil(neighbour, visited);
            }
        }
    }

    public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int startNode) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[startNode] = true;
        q.push(startNode);
        cout<<"'"<<startNode<<"dugumden baslayan BFS"<<endl;
        while(!q.empty()) {
            if (!q.empty()) {
                int u = q.front();
                q.pop();
                cout<<u<<"'";
                for (int neighbour : adj[u]) {
                    if (!visited[neighbour]) {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
        }
        cout<<endl;
    }

    // Yeni Eklenen DFS Ana Fonksiyonu
    void DFS(int startNode) {
        vector<bool> visited(V, false); // Ziyaret dizisini sıfırla
        cout << "'" << startNode << "' dugumden baslayan DFS: ";

        // Özyinelemeli yardımcı fonksiyonu çağır
        DFSUtil(startNode, visited);

        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(3,5);

    cout<<"graf olusturuldu(V=6, E=7).\n"<<endl;
    g.BFS(0);
    g.BFS(3);

    g.DFS(0);
    g.DFS(3);
    return 0;
}
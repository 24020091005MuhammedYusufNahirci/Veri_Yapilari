#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
    int V;
    vector<list<int>> adj;

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
        cout <<  "'" << startNode <<"'dugumden baslayan BFS: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int neighbour : adj[u]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        cout << endl;
    }

};


int main() {
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(3,5);

    cout<<"Graf olusturuldu (V=6, E=7). \n"<<endl;

    g.BFS(0);
    g.BFS(3);
    return 0;
}
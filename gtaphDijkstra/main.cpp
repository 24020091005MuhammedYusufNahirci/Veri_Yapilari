#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

typedef pair<int, int> pii;

void addEdge(vector<vector<pii>>&adj, int u, int v,int weight) {
    adj[u].push_back(make_pair(v,weight));
    adj[v].push_back(make_pair(u,weight));
}

void shortestPath(int src, int V, const vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0,src));
    dist[src] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;
            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout<< "baslangic dugumu:"<<src<<endl;
    cout <<"dugum\t\tmesafe (en kisa yol)\n";
    cout<<"----------------------\n";
    for (int i=0; i<V; i++) {
        cout<<i<<"\t\t";
        if(dist[i]==INF) {
            cout<<"erisilemez";

        }
        else {
            cout<<dist[i];
            cout<<"\n";
        }
    }
}

int main() {
    int V=9;
    vector<vector<pii>>adj(V);
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 5, 9);
    addEdge(adj, 1, 11, 15);
    addEdge(adj, 2, 1, 10);
    addEdge(adj, 2, 2, 11);
    addEdge(adj, 3, 2, 12);
    addEdge(adj, 4, 3, 13);
    addEdge(adj, 5, 4, 14);



    shortestPath(0, V, adj);
    return 0;
}
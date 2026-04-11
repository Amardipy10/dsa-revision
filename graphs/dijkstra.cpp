#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int,int>>> adj; // {neighbor, weight}

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed
    }

    void dijkstra(int src) {
        // Min heap → {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(auto it : adj[u]) {
                int v = it.first;
                int weight = it.second;

                // Relaxation
                if(dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print shortest distances
        cout << "Shortest distances from source " << src << ":\n";
        for(int i = 0; i < V; i++) {
            cout << "Node " << i << " -> " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 1);

    g.dijkstra(0);

    return 0;
}
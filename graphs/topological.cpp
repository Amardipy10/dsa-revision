#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);   // Directed edge u -> v
    }

    void dfs(int node, vector<bool>& vis, stack<int>& s) {
        vis[node] = true;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, vis, s);
            }
        }

        // push after visiting all neighbours
        s.push(node);
    }

    void topoSort() {
        vector<bool> vis(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, s);
            }
        }

        while (s.size() > 0) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topoSort();

    return 0;
}
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int>* l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool bfs(int start, vector<bool>& vis) {
        queue<pair<int, int>> q; // {node, parent}
        
        vis[start] = true;
        q.push({start, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neigh : l[node]) {
                if (!vis[neigh]) {
                    vis[neigh] = true;
                    q.push({neigh, node});
                }
                else if (neigh != parent) {
                    // visited & not parent → cycle
                    return true;
                }
            }
        }
        return false;
    }

    bool detectCycle() {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfs(i, vis))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0); // cycle

    if (g.detectCycle())
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}
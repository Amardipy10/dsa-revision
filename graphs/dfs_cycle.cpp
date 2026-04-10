#include <iostream>
#include <vector>
#include <list>
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

    bool dfs(int node, int parent, vector<bool>& vis) {
        vis[node] = true;

        for (int neigh : l[node]) {
            if (!vis[neigh]) {
                if (dfs(neigh, node, vis))
                    return true;
            }
            else if (neigh != parent) {
                // visited and not parent → cycle
                return true;
            }
        }
        return false;
    }

    bool detectCycle() {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis))
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
    g.addEdge(3, 0); // creates cycle

    if (g.detectCycle())
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}
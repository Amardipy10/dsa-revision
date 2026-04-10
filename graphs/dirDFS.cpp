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
        l[u].push_back(v); // directed edge
    }

    bool dfs(int node, vector<bool>& vis, vector<bool>& pathVis) {
        vis[node] = true;
        pathVis[node] = true;

        for (int neigh : l[node]) {
            if (!vis[neigh]) {
                if (dfs(neigh, vis, pathVis))
                    return true;
            }
            else if (pathVis[neigh]) {
                // back edge → cycle
                return true;
            }
        }

        pathVis[node] = false; // backtrack
        return false;
    }

    bool detectCycle() {
        vector<bool> vis(V, false);
        vector<bool> pathVis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis))
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
    g.addEdge(3, 1); // cycle

    if (g.detectCycle())
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}
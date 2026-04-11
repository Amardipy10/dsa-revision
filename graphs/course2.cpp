class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for(auto &p : prerequisites) {
            int u = p[0];
            int v = p[1];
            adj[v].push_back(u);  // v → u
            indegree[u]++;
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        // BFS
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If cycle exists → return empty
        if(topo.size() != numCourses) return {};

        return topo;
    }
};
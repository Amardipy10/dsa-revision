class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
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

        int count = 0;

        // BFS
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If all courses processed → no cycle
        return count == numCourses;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Push all rotten oranges + count fresh
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // Directions (up, right, down, left)
        vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

        int time = 0;

        // Step 2: BFS
        while(!q.empty() && fresh > 0) {
            int size = q.size();

            while(size--) {
                auto [i, j] = q.front();
                q.pop();

                for(auto [dx, dy] : dir) {
                    int ni = i + dx;
                    int nj = j + dy;

                    if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        q.push({ni, nj});
                        fresh--;
                    }
                }
            }

            time++; // one minute passed
        }

        // Step 3: Check if all fresh are rotten
        return (fresh == 0) ? time : -1;
    }
};
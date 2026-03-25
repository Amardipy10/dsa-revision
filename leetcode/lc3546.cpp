#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        long long total=0;
        vector<long long> r(m,0),c(n,0);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                r[i]+=grid[i][j];
                c[j]+=grid[i][j];
                total+=grid[i][j];
            }
        }
        if(total%2!=0)return false;
        long long target=total/2,curr=0;
        for(int i=0;i<m-1;++i){
            curr+=r[i];
            if(curr==target)return true;
        }
        curr=0;
        for(int j=0;j<n-1;++j){
            curr+=c[j];
            if(curr==target)return true;
        }
        return false;
    }
};
#include<iostream>
#include<vector>
#include <climits>
using namespace std;
int subarray(vector<int>& v){
    int n=v.size();
    int curr_sum=0;
    int max_sum=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        curr_sum+=v[i];
        max_sum=max(curr_sum,max_sum);
        if(curr_sum<0){
            curr_sum=0;
        }
    }
    return max_sum;
    
}
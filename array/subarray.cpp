#include<iostream>
#include<vector>
#include <climits>
using namespace std;
//optimal
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

//brute
int maxSubarrayBrute(vector<int>& v) {
    int n = v.size();
    int max_sum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int curr_sum = 0;
        for (int j = i; j < n; j++) {
            curr_sum += v[j];
            max_sum = max(max_sum, curr_sum);
        }
    }
    return max_sum;
}
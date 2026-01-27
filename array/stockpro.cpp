//BRUTE 

#include<iostream>
#include<vector>

using namespace std;
int stock(vector<int> v){
    int n=v.size();
    int maxprofit=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int profit=v[j]-v[i];
            maxprofit=max(profit,maxprofit);
        }
        
    }
    return maxprofit;
}

//optimal

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int minPrice=INT_MAX;
        int maxmProfit=0;
        for(int i:arr){
            if(i<minPrice){
                minPrice=i;
            }
            else{
                int profit=i-minPrice;
                maxmProfit=max(profit,maxmProfit);

            }
        }
        return maxmProfit;
    }
};
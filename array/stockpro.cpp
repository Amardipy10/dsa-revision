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

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices) {
        minPrice = min(minPrice, price);           // best buy till now
        maxProfit = max(maxProfit, price - minPrice); // best profit
    }
    return maxProfit;
}
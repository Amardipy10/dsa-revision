#include<iostream>
#include<vector>
using namespace std;

//brute
vector<int> productitself(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(n);
    
    for (int i = 0; i < n; i++)
    {
        int product=1;
        for (int j = 0; j < n; j++)
        {
            if(i!=j){
                product*=nums[j];
            }
        }
        ans[i]=product;
    }
    return ans;
    
    }

    //optimal
    #include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);

    // Step 1: Prefix product
    ans[0] = 1;
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    // Step 2: Suffix product using one variable
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = ans[i] * rightProduct;
        rightProduct *= nums[i];
    }

    return ans;
}
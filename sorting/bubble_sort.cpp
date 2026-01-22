#include<iostream>
#include<vector>
using namespace std;
int bubble_sort(vector<int> &nums){
    int n=nums.size();
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
            }
        }
        
    }
    return 0;
    
}
int main(){
    vector<int> v={34,32,3,21,321};
    bubble_sort(v);
    for(int i: v){
        cout<<i<<" ";;
    }
    return 0;

}
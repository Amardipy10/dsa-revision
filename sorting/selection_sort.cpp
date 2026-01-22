#include<iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int> &nums){
    int n = nums.size();

    for(int i = 0; i < n - 1; i++){
        int minIndex = i;

        for(int j = i + 1; j < n; j++){
            if(nums[j] < nums[minIndex]){
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
}

int main(){
    vector<int> v = {34, 32, 3, 21, 321};
    selection_sort(v);

    for(int x : v){
        cout << x << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threesum(vector<int>& v){
    int n = v.size();
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(v[i] + v[j] + v[k] == 0){
                    vector<int> ele;
                    ele.push_back(v[i]);
                    ele.push_back(v[j]);
                    ele.push_back(v[k]);
                    ans.push_back(ele);
                }
            }
        }
    }
    return ans;
}

//optimal sort+ two pointer
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& v) {
    int n = v.size();
    vector<vector<int>> ans;

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && v[i] == v[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = v[i] + v[left] + v[right];

            if (sum == 0) {
                ans.push_back({v[i], v[left], v[right]});

                while (left < right && v[left] == v[left + 1]) left++;
                while (left < right && v[right] == v[right - 1]) right--;

                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    return ans;
}
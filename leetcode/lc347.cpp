class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> mp;
        for(int n : nums) {
            mp[n]++;
        }
        vector<pair<int,int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.second > b.second;   
        });
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
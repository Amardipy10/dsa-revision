class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            int m=nums2.size();
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nums1[i]);
                    nums2.erase(nums2.begin()+j);
                    break;
                }
            }
        }
        return ans;
    }
};
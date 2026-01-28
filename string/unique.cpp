class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        // Step 1: count frequency
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        // Step 2: find first unique
        for(int i = 0; i < s.size(); i++) {
            if(freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        int n=s.size();

        for(char ch:s){
            freq[ch-'a']++;
        }
        for(int i=0;i<n;i++){
            if(freq[s[i]-'a']==1){
            return i;
            }
        }
        return -1;

        
    }
};
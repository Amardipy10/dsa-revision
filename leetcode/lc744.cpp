class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        set<char>s;
        int n=letters.size();
        for(char i:letters){
            s.insert(i);
        };
        s.insert(target);
        for(char i:s){
            if(i>target){
                return i;
            }
        }
        return letters[0];
        
    }
};
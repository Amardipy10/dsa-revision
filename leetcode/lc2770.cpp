class Solution {
public:
    string getHappyString(int n, int k) {
        string res = "", curr = "";
        int count = 0;
        auto backtrack = [&](auto self) -> bool {
            if (curr.size() == n) {
                if (++count == k) {
                    res = curr;
                    return true;
                }
                return false;
            }
            for (char c : {'a', 'b', 'c'}) {
                if (curr.empty() || curr.back() != c) {
                    curr.push_back(c);
                    if (self(self)) return true;
                    curr.pop_back();
                }
            }
            return false;
        };
        backtrack(backtrack);
        return res;
    }
};
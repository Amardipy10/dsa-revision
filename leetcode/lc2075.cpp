class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        if (n == 0) return "";
        
        int cols = n / rows;
        string res = "";
        
        for (int j = 0; j < cols; ++j) {
            for (int r = 0, c = j; r < rows && c < cols; ++r, ++c) {
                res += encodedText[r * cols + c];
            }
        }
        
        int last = res.find_last_not_of(' ');
        if (last == string::npos) return "";
        
        return res.substr(0, last + 1);
    }
};
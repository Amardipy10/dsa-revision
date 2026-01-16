#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char c : s) {

        // opening brackets
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else {
            // closing bracket but stack empty
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    // stack empty → valid
    return st.empty();
}
#include <vector>
#include <iostream>
using namespace std;

class Stack {
private:
    vector<int> v;

public:
    // Push element
    void push(int val) {
        v.push_back(val);
    }

    // Pop element
    void pop() {
        if (v.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        v.pop_back();
    }

    // Return top element
    int top() {
        if (v.empty()) {
            cout << "Stack is empty\n";
            return -1;   // error value
        }
        return v.back();
    }

    // Check if stack is empty
    bool empty() {
        return v.empty();
    }

    // Print stack (optional helper)
    void print() {
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Top: " << s.top() << endl;  // 4
    s.pop();
    cout << "Top: " << s.top() << endl;  // 3

    cout << "Stack elements: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Stack {
    list<int> ll;

public:
    // O(1)
    void push(int val) {
        ll.push_front(val);
    }

    // O(1)
    void pop() {
        if (ll.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        ll.pop_front();
    }

    // O(1)
    int top() {
        if (ll.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return ll.front();
    }

    bool empty() {
        return ll.size() == 0;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;  // 30
    s.pop();
    cout << s.top() << endl;  // 20

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
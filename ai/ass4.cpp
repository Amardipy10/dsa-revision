#include<iostream>
#include<vector>
using namespace std;

void printBoard(const vector<int>& pos, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pos[i] == j) cout << "Q ";
            else cout << ". ";
        }
        cout << '\n';
    }
}

void solveBT(int row, int n, vector<int>& pos, vector<int>& col, vector<int>& d1, vector<int>& d2, vector<vector<int>>& ans) {
    if (row == n) {
        ans.push_back(pos);
        return;
    }
    for (int c = 0; c < n; c++) {
        if (!col[c] && !d1[row + c] && !d2[row - c + n - 1]) {
            pos[row] = c;
            col[c] = d1[row + c] = d2[row - c + n - 1] = 1;
            solveBT(row + 1, n, pos, col, d1, d2, ans);
            col[c] = d1[row + c] = d2[row - c + n - 1] = 0;
        }
    }
}

vector<vector<int>> backtracking(int n) {
    vector<vector<int>> ans;
    vector<int> pos(n, -1), col(n, 0), d1(2 * n, 0), d2(2 * n, 0);
    solveBT(0, n, pos, col, d1, d2, ans);
    return ans;
}

void solveBB(int row, int n, vector<int>& pos, vector<int>& col, vector<int>& d1, vector<int>& d2, vector<vector<int>>& ans) {
    if (row == n) {
        ans.push_back(pos);
        return;
    }
    for (int c = 0; c < n; c++) {
        if (!col[c] && !d1[row + c] && !d2[row - c + n - 1]) {
            pos[row] = c;
            col[c] = d1[row + c] = d2[row - c + n - 1] = 1;
            solveBB(row + 1, n, pos, col, d1, d2, ans);
            col[c] = d1[row + c] = d2[row - c + n - 1] = 0;
        }
    }
}

vector<vector<int>> branchAndBound(int n) {
    vector<vector<int>> ans;
    vector<int> pos(n, -1), col(n, 0), d1(2 * n, 0), d2(2 * n, 0);
    solveBB(0, n, pos, col, d1, d2, ans);
    return ans;
}

void displaySolutions(const vector<vector<int>>& solutions, int n) {
    for (int i = 0; i < (int)solutions.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        printBoard(solutions[i], n);
        cout << '\n';
    }
    cout << "Total Solutions: " << solutions.size() << '\n';
}

int main() {
    int choice, n;
    while (true) {
        cout << "---- Constraint Satisfaction Problem ----\n";
        cout << "1. Solve N-Queens using Backtracking\n";
        cout << "2. Solve N-Queens using Branch and Bound\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 3) break;

        cout << "Enter value of N: ";
        cin >> n;

        if (choice == 1) {
            auto solutions = backtracking(n);
            displaySolutions(solutions, n);
        } else if (choice == 2) {
            auto solutions = branchAndBound(n);
            displaySolutions(solutions, n);
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
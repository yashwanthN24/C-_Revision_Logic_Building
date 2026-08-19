#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to print numbers from current to n using backtracking
    void printNumbers(int current, int n) {
        // Base case: if current exceeds n, stop recursion
        if (current > n)
            return;

        // Recursive call with next number
        printNumbers(current + 1, n);

        // Print current number during backtracking
        cout << current << " ";
    }
};

int main() {
    Solution sol;
    int n = 10;

    sol.printNumbers(1, n);
    cout << "\n";

    return 0;
}
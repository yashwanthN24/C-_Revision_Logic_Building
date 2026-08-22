#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, ans;

        while (ss >> word) {
            ans = word + (ans.empty() ? "" : " ") + ans;
        }

        return ans;
    }
};

// https://chatgpt.com/c/6a894623-61f0-83e8-ba2e-1c4e45570be8


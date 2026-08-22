#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<int, vector<char>> freq;

        // Count characters
        map<char, int> count;

        for (char c : s) {
            count[c]++;
        }

        // Frequency as key
        for (auto &p : count) {
            freq[p.second].push_back(p.first);
        }

        string ans;

        // Highest frequency first
        for (auto it = freq.rbegin(); it != freq.rend(); it++) {
            int f = it->first;

            for (char c : it->second) {
                ans += string(f, c);
            }
        }

        return ans;
    }
};
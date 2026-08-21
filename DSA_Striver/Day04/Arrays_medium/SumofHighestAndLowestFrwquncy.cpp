#include<bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int sumHighestAndLowestFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;
        int minFreq = nums.size(), maxFreq = 0;
        for (auto& [_, f] : freq) {
            minFreq = min(minFreq, f);
            maxFreq = max(maxFreq, f);
        }
        return minFreq + maxFreq;
    }
};
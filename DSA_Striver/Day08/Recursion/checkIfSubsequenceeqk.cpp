#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool helper(vector<int>& nums, int k, int i, int sum) {
        if (sum == k)
            return true;

        if (i == nums.size())
            return false;

        // take
        if (helper(nums, k, i + 1, sum + nums[i]))
            return true;

        // don't take
        if (helper(nums, k, i + 1, sum))
            return true;

        return false;
    }

    bool checkSubsequenceSum(vector<int>& nums, int k) {
        return helper(nums, k, 0, 0);
    }
};
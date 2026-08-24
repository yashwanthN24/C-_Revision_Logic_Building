
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int helper(vector<int> nums, int i, int sum, int k) {

        if (sum > k) {
            return 0;
        }

        if (i == nums.size()) {
            if (sum == k) {
                return 1;
            }
            return 0;
        }

        // take
        int take = helper(nums, i + 1, sum + nums[i], k);

        // don't take
        int notTake = helper(nums, i + 1, sum, k);

        return take + notTake;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        return helper(nums, 0, 0, k);
    }
};
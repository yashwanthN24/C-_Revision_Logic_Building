#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0 , maxSum = INT_MIN;

        // if current sum is less that 0 then reset sum to 0  kadane algorithm for tracking maximum subarray sum in a narray 
        for(int i = 0 ; i<nums.size() ; i++){
            sum += nums[i];
            maxSum = max(maxSum , sum);

            if(sum < 0 ){
                sum = 0;
            }

        }

        return maxSum;
    }
};
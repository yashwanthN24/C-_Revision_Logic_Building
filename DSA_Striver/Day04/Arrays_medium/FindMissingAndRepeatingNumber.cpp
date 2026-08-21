/*


Find the repeating and missing number
Hard

Hints
Company
Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.



Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.



Note: You are not allowed to modify the original array.


Example 1

Input: nums = [3, 5, 4, 1, 1]

Output: [1, 2]

Explanation:

1 appears two times in the array and 2 is missing from nums

Example 2

Input: nums = [1, 2, 3, 6, 7, 5, 7]

Output: [7, 4]

Explanation:

7 appears two times in the array and 4 is missing from nums.


*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        unordered_map<int,int> mp;
        vector<int> result;

        for(int i = 0 ; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int single = 0;
        for(int i = 1 ; i<=nums.size() ; i++){
            if(!mp.count(i) ) single = i;

            if(mp[i] == 2){
                result.push_back(i);
            }
        }

        result.push_back(single);

        return result;
    }
};
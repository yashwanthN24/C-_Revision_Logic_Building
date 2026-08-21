#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // observation positive number always at evene position so intial positive numeber start at 0 and increment 2 to point to even position only 

        // negative number point to odd indexes intial negative number at 1  st index
        vector<int> ans(nums.size()  , 0);

        int posIdx = 0 , negIdx = 1 ; 
        for(int i = 0; i<nums.size(); i++ ){
            if(nums[i] < 0){
                ans[negIdx] = nums[i];
                negIdx += 2 ;
            }else {
                ans[posIdx] = nums[i];
                posIdx += 2;
            }
        }

        return ans;
    }
};
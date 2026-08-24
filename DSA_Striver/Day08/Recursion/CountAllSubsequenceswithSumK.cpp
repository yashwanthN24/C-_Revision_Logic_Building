#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:    	
    void helper(vector<int> nums , vector<int> curList , vector<vector<int>> &result , int i , int sum , int k ){ 
        
        if (sum > k) {
            return;
        }

        if(i == nums.size()){
            if(sum == k){
                result.push_back(curList);
                
            }
            return;
        }

        curList.push_back(nums[i]);
        helper(nums , curList , result , i+1 , sum + nums[i] , k);
        curList.pop_back();
        helper(nums , curList , result , i+1 , sum , k);


    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here
        vector<int> curList ;
        vector<vector<int>> result;
        helper(nums , curList , result , 0 , 0 , k);
        return result.size();
    }
};
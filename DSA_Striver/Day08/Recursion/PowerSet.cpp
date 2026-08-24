
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:	

    void pset(vector<int> nums , vector<int> &curList , vector<vector<int>> &res , int i){

        if(i == nums.size()){
             res.push_back(curList);
            return;
        }


        curList.push_back(nums[i]);
        pset(nums , curList , res , i+1);
        curList.pop_back();
        pset(nums , curList , res , i+1);
    }

    vector<vector<int> > powerSet(vector<int>& nums) {
        //your code  goes here
        vector<int> currList;
        vector<vector<int>> result;
        pset(nums , currList , result , 0);
        return result;
    }
};
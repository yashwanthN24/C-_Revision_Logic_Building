#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        vector<int> result;

        for(int i = 0 ; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        int count = 0;
        for(auto it: mp){
            
            if(it.second > (nums.size()/3)){
                result.push_back(it.first);
                count++;
            }

            if(count == 2){
                break;
            }
        }
        return result;
    }
};


// https://chatgpt.com/c/6a8817c3-f798-83ee-8edd-714ec17c1541

// https://chatgpt.com/c/6a8817c3-f798-83ee-8edd-714ec17c1541
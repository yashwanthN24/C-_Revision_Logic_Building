
#include <iostream>

#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // iterate till we find 0 and take j as pointer to tha index and start i as its next pointer 
        int j = -1;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]== 0){
                j = i;
                break;
            }
        }

        if(j == - 1) return;

        for(int i = j+1 ; i<nums.size() ;i++){
            if(nums[i]!=nums[j]){
                swap(nums[j] , nums[i]);
                j++;
            }
        }
    }
};


// brute force approach is like create a new array copy non-zero elements done copy back this tenprpay array element to orginal array6

// this two poinmter apprach is like j point to first zero and i track next element after zero fi not not same swap  increment j to point to next zeroposuiition 
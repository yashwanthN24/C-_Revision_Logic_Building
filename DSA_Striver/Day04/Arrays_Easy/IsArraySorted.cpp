// is array rorated by x position sorted in asecinding order 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        for(int i =0; i<n;i++){
            // becayse any sorted arra as only one pair tha is greater that too when circular comparision i.e when comparing last element with first element 

            // so even after rotation thre must be only on e pair if more then not a valid sorted array
            if(nums[i] > (nums[(i+1) %n])){
                count++;
            }
            if(count >1 ){
                return false;
            }
        }
        return true;

        
    }
};


int main(){

    // vector<int> arr  



    // count == 0  only possible for arrays of size 0/1  or all equal element 

    // count == 1 sorted or sorted and rotated 

    // count > 1 not a sorted rotation
}

// https://chatgpt.com/c/6a86b8de-6b08-83e8-8bca-205098c08fd5
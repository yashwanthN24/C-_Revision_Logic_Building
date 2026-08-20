#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    

    void rotateArray(vector<int>& nums, int k) {

        // normalize k 

        k = k % (nums.size()); // so that fall within 0 to n-1 rotations which is valid as per problem
    //     its the same as reverseing firts n-k element 
        //  i.e k to end of list
        reverse(nums , k , nums.size()-1);

    //  Then reversing first k-1 elements 

    reverse(nums , 0 , k-1);

    // reversing entire array 

    reverse(nums , 0 , nums.size()-1);
    }

    void reverse(vector<int> &arr , int start , int end)
    {
        while(start<end){
            swap(arr[start++] , arr[end--]);
        }
    }
};
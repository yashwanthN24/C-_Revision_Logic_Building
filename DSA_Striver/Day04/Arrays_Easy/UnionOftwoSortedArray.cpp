#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        // Approach 1 Using set TC:O(n) sc : O(n) becaue of set
        // set<int> s;

        // vector<int> result;
        // // result.reserve(nums1.size()+nums2.size());
        // for(int i = 0 ; i<nums1.size(); i++){
        //     s.insert(nums1[i]);
           
        // }

        // for(int i = 0 ; i<nums2.size() ; i++){
        //     s.insert(nums2[i]);
        // }
     

        // for(int n : s){
           
        //         result.push_back(n);
            
        // }

        // return result;
  
  
  
  
        // Approach 2 Using map 

        // map<int , int> mp;

        // vector<int> result;


        // for(int i = 0 ;i<nums1.size() ; i++){
        //     mp[nums1[i]]++;
        // }

        // for(int i = 0 ;i<nums2.size() ; i++){
        //     mp[nums2[i]]++;
        // }

        // for(auto it:mp){
        //     result.push_back(it.first);
        // }

        // return result;
  

        // 3) Two pointer Approach

        vector<int> result;

        int i = 0 , j = 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                if(result.empty() || result.back() !=nums1[i])
                result.push_back(nums1[i]);
                i++;
            }else if(nums1[i] > nums2[j]){
                if(result.empty() || result.back()!= nums2[j])
                result.push_back(nums2[j]);
                j++;
            }else{
                if(result.empty() || result.back() !=nums1[i])
                    result.push_back(nums1[i]);
                i++;j++;

            }
        }

        while(i<nums1.size()){
            if(result.back() !=nums1[i])
                result.push_back(nums1[i]);

            i++;
        }


        while(j<nums2.size()){
            if(result.back()!= nums2[j])
                result.push_back(nums2[j]);
            j++;
        }

        return result;
    }
};
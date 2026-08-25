// https://chatgpt.com/c/6a8d40f8-2f88-83ee-b4d0-e13507f9b21d

#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int x : nums)
            freq[x]++;

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        // store freuqnecy , element in priority queue as for priotiy que of pair default compairsion logic is by pairs first value i.e frwquency so isince min hea  keeps lowest freuqnecy at the top of pirootiy queue 
        for(auto &p : freq){
            pq.push({p.second, p.first});
            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};



// https://chatgpt.com/c/6a8d40f8-2f88-83ee-b4d0-e13507f9b21d
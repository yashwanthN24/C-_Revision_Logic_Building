#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count(const vector<int>& arr, int mid) {
        int n = arr.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += ceil((double)arr[i] / (double)mid);
        }

        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1; 
        int high = 0;

        for (int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        } 

        // llow = 1 as atleast one babanaa can be eated in 1 hour batre minimum case max 11 bananas can be eatedn depending on th max sie of pile in array 
        

        int ans = 0;

        while (l <= high) {
            int mid = l + (high - l) / 2;
            int total = count(piles, mid);

            if (total > h) {
                l = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};
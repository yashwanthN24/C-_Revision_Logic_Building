 class Solution {
public:
    bool checkIthBit(int n, int i) {
        // Your code goes here
        return  (1 << i) & n; // bitmask 1<<i (to get only 1 for the ith bit rest all zero and doing & with n gives 1 wth both are one i.e set bit else 0)
    }
};
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        int x = (start ^ goal);

        while(x != 0){
            ans += (x & 1);

            x >>= 1;
        }

        return ans;
    }
};

// idea is xor gives 1 only when both are different so start ^ goal gves the ifference in bits of two numbers 


// so while x not = 0 check rightmoist bit and and add the count  of set bits
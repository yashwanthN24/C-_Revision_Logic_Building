class Solution {
public:
    int floorSqrt(int n) {
        int low = 0;
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (1LL * mid * mid == n) {
                return mid;
            }
            else if (1LL * mid * mid < n) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return high;
    }
};

// https://chatgpt.com/c/6a8943fe-c4b0-83e8-8e3c-64b1f34ba44d

// https://chatgpt.com/c/6a894623-61f0-83e8-ba2e-1c4e45570be8
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
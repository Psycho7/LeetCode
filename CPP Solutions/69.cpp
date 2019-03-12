class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid < x / mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left <= x / left) return left;
        return left - 1;
    }
};
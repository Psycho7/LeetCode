class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int x = 1, y = 2;
        while (n > 2) {
            y = x + y;
            x = y - x;
            n--;
        }
        return y;
    }
};
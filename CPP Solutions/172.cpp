class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 25) return n / 5;
        return n / 5 + trailingZeroes(n / 5);
    }
};
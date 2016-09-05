class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == -2147483648) return (1 / x) * myPow(1 / x, 2147483647);
        if (n < 0) return myPow(1 / x, -n);
        int half = n >> 1;
        double temp = myPow(x, half);
        temp = temp * temp;
        if (n & 1 == 1) temp = temp * x;
        return temp;
    }
};

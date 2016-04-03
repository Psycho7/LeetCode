class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            return -dividend;
        }
        if (divisor == INT_MIN) {
            if (dividend == INT_MIN) return 1;
            return 0;
        }
        int plusOne = 0;
        bool negFlag = false;
        if (dividend < 0) {
            if (dividend == INT_MIN) {
                dividend = INT_MAX;
                plusOne = 1;
            } else {
                dividend = -dividend;
            }
            negFlag = !negFlag;
        }
        if (divisor < 0) {
            negFlag = !negFlag;
            divisor = -divisor;
        }
        int aLen = log2(dividend);
        int bLen = log2(divisor);
        int ans = 0;
        int shift = aLen - bLen;
        while (dividend >= divisor && shift >= 0) {
            if (dividend >= (divisor << shift)) {
                dividend -= (divisor << shift);
                ans |= 1 << shift;
            }
            --shift;
        }
        if (plusOne) {
            dividend += 1;
            if (dividend == divisor) ans++;
        }
        return negFlag ? -ans : ans;
    }
    
    int log2(int v) { // COPY from Bit Twiddling Hacks @ Stanford 
        const unsigned int b[] = {0x2, 0xC, 0xF0, 0xFF00, 0xFFFF0000};
        const unsigned int S[] = {1, 2, 4, 8, 16};
        int i;

        register unsigned int r = 0; // result of log2(v) will go here
        for (i = 4; i >= 0; i--) { // unroll for speed...
            if (v & b[i]) {
                v >>= S[i];
                r |= S[i];
            } 
        }
        return r;
    }
};

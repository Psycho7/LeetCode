static int MOD = 1e9 + 7;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        this->arrLen = arrLen;
        memset(memo, -1, sizeof(int) * 510 * 510);
        return dp(steps, 0);
    }
    
    int dp(int steps, int pos) {
        if (steps == 0 && pos == 0) return 1;
        if (steps < 0 || pos < 0 || pos >= this->arrLen || pos > steps) return 0;
        if (memo[steps][pos] != -1) return memo[steps][pos];
        
        int ans = (dp(steps -1, pos) + dp(steps - 1, pos - 1)) % MOD;
        ans = (ans + dp(steps - 1, pos + 1)) % MOD;
        memo[steps][pos] = ans;
        
        // std::cout << steps << ", " << pos << ": " << ans << std::endl;
        
        return ans;
    }

private:
    int memo[510][510];
    int arrLen = 0;
};
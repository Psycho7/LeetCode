class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int invalid = INT_MAX >> 1;
        vector<int> f(amount + 1, invalid);
        f[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto& c : coins) {
                if (i - c < 0) continue;
                f[i] = min(f[i], f[i - c] + 1);
            }
        }
        
        return f[amount] == invalid ? -1 : f[amount];
    }
};
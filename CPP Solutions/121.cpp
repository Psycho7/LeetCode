class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if (prices.empty()) return ans;
        
        int low = prices[0];
        
        for (auto n : prices) {
            if (n - low > ans) {
                ans = n - low;
            }
            if (n < low) {
                low = n;
            }
        }
        return ans;
    }
};
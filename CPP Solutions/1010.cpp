class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt[60] = {0};
        int ans = 0;
        
        for (int i = time.size() - 1; i >= 0; i--) {
            int mod = time[i] % 60;
            if (mod == 0) {
                ans += cnt[0];
            } else {
                ans += cnt[60 - mod];
            }
            
            cnt[mod]++;
        }
        
        return ans;
    }
};
class Solution {
public:    
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        
        unordered_set<int> num_set;
        num_set.insert(nums.begin(), nums.end());
           
        for (auto n: nums) {
            int tmp = 1;
            int now = n;
            if (num_set.count(now - 1) == 0) {
                while (num_set.count(now + 1)) {
                    now++;
                    tmp++;
                }
            }
            if (tmp > ans) {
                ans = tmp;
            }
        }
        
        return ans;
    }
};
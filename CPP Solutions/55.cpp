class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = 0;
        int p = 0;
        
        while (p <= m) {
            m = max(m, p + nums[p]);
            if (m >= nums.size() - 1) return true;
            p++;
        }
        
        return false;
    }
};
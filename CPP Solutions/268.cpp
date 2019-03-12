class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res ^= (i + 1) ^ nums[i];
        }
        return res;
    }
};
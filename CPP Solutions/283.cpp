class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fz = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                int tmp = nums[i];  // Edge case
                nums[i] = 0;
                nums[fz] = tmp;
                fz++;
            }
        }
    }
};
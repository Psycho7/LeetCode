class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int deviation = 1 << 30;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            int l = i + 1;
            int r = len - 1;
            while (l < r) {
                int temp = nums[i] + nums[l] + nums[r];
                if (temp == target) {
                    return target;
                }
                if (abs(temp - target) < deviation) {
                    ans = temp;
                    deviation = abs(temp - target);
                }
                if (temp < target) l++;
                if (temp > target) r--;
            }
        }
        return ans;
    }
};

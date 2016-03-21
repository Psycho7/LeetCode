class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 3; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            for (int j = i + 1; j < len - 2; j++) {
                if (j > i + 1 && nums[j - 1] == nums[j]) continue;
                if (nums[j + 1] + nums[j + 2] + nums[i] + nums[j] > target) break;          // Branch-cut
                if (nums[len - 1] + nums[len - 2] + nums[i] + nums[j] < target) continue;   // Branch-cut
                int l = j + 1;
                int r = len - 1;
                while (l < r) {
                    while (l < r && nums[i] + nums[j] + nums[l] + nums[r] > target) {
                        r--;
                    }
                    if (l < r && nums[i] + nums[j] + nums[l] + nums[r] == target) {
                        vector<int> temp(4);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[l];
                        temp[3] = nums[r];
                        ans.push_back(temp);
                        while (l < len && nums[l] == temp[2]) l++;
                    } else {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};

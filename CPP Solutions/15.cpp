class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = len - 1;
            while (l < r) {
                while (l < r && nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                }
                if (l < r && nums[i] + nums[l] + nums[r] == 0) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    ans.push_back(temp);
                    while (l < r && nums[l] == temp[1]) l++;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};

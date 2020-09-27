class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int max_key = -1;
        unordered_map<int, vector<int>> map;
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = 0; j < nums[i].size(); j++) {
                int sum = i + j;
                if (sum > max_key) max_key = sum;
                
                map[sum].push_back(nums[i][j]);
            }
        }
        
        vector<int> ans;
        for (int sum = 0; sum <= max_key; sum ++) {
            for (auto ch: map[sum]) {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
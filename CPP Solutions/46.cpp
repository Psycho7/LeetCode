class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visit(nums.size(), false);
        vector<vector<int>> ans;
        
        vector<int> tmp;
        dfs(tmp, ans, nums, visit);
        return ans;
    }
    
    void dfs(vector<int>& temp, vector<vector<int>>& ans,
            vector<int>& nums, vector<bool>& visit) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visit[i]) continue;
            
            visit[i] = true;
            temp.push_back(nums[i]);
            dfs(temp, ans, nums, visit);
            temp.pop_back();
            visit[i] = false;
        }
    }
};
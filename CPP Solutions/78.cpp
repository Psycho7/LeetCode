class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(nums, curr, 0, ans);
        return ans;
    }
    
    void dfs(vector<int>& f, vector<int>& curr, int n, vector<vector<int>>& ans) {
        if (n == f.size()) {
            ans.push_back(curr);
            return;
        }
        
        dfs(f, curr, n + 1, ans);
        
        curr.push_back(f[n]);
        dfs(f, curr, n + 1, ans);
        curr.pop_back();
    }
};
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        ans.clear();
        auto tmp = vector<int>();
        dfs(tmp, 0, 0, 0, 0);
        return ans;
    }
    
    void dfs(vector<int>& cur, int vert, int horz, int left_diag, int right_diag) {
        if (cur.size() == n) {
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                string line(n, '.');
                line[cur[i]] = 'Q';
                temp.push_back(line);
            }
            ans.push_back(temp);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            int vert_flag = 1 << i;
            int horz_flag = 1 << i;
            int l_diag_flag = 1 << (cur.size() - i - 1 + n);
            int r_diag_flag = 1 << (cur.size() + i);
            
            if (vert_flag & vert
               || horz_flag & horz
               || l_diag_flag & left_diag
               || r_diag_flag & right_diag) {
                continue;
            }
            
            cur.push_back(i);
            dfs(cur, vert_flag | vert, horz_flag | horz, l_diag_flag | left_diag, r_diag_flag | right_diag);
            cur.pop_back();
        }   
    }
private:
    vector<vector<string>> ans;
    int n;
};
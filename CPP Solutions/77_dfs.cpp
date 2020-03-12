class Solution {
private:
    vector<int> tmp;
    
    vector<vector<int>> result;
    
    int maxn, dep;
    
    void dfs(int cur, int val) {
        if (cur == dep) {
            result.push_back(tmp);
            return;
        }
        if (val + dep - cur - 1 > maxn) {
            return;
        }
        
        for (int i = val; i <= maxn; i++) {
            tmp.push_back(i);
            dfs(cur + 1, i + 1);
            tmp.pop_back();
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        tmp.clear();
        result.clear();
        dep = k;
        maxn = n;
        
        dfs(0, 1);
        
        return result;
    }
};
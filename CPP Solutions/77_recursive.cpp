class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        
        if (k <= 0) {
            return result;
        }
        
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                result.emplace_back(1, i);
            }
            return result;
        }
        
        auto prev = combine(n, k - 1);
        for (auto sub : prev) {
            int last = sub.back();
            for (int i = last + 1; i <= n; i++) {
                vector<int> tmp = sub;
                tmp.push_back(i);
                result.push_back(move(tmp));
            }
        }
        
        return result;
    }
};
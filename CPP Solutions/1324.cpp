class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ans;
        
        int row = 0, prev = 0;
        for (auto ch: s) {
            if (ch == ' ') {
                row = 0;
                prev++;
                continue;
            }
            
            if (ans.size() <= row) {
                ans.emplace_back(prev, ' ');
            }
            while (ans[row].size() < prev) {
                ans[row].push_back(' ');
            }
            ans[row].push_back(ch);
            row++;
        }
        
        return ans;
    }
};
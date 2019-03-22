class Solution {
public:
    bool isMatch(string s, string p) {
        auto f = vector(s.size() + 1, vector<bool>(p.size() + 1, false));
        f[0][0] = true;
        
        for (int k = 2; k <= p.size() && p[k - 1] == '*'; k += 2) f[0][k] = true;
        
        for (int i = 1; i <= s.size(); i++) {
            char x = s[i - 1];
            for (int j = 1; j <= p.size(); j++) {
                char y = p[j - 1];
                
                if (y == '*') {
                    char pre = p[j - 2];
                    f[i][j] = f[i][j - 2] || (pre == x || pre == '.') && f[i - 1][j];
                } else if (y == '.') {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1] && x == y;
                }
            }
        }
        
        return f[s.size()][p.size()];
    }
};
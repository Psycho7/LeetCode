#include <sstream>

class Solution {
public:
    bool isMatch(string s, string p) {
        stringstream tmp;
        char lst = 0;
        for (auto ch : p) {
            if (lst == '*' && ch == '*') continue;
            tmp << ch;
            lst = ch;
        }
        p = tmp.str();
        
        
        auto f = vector(s.size() + 1, vector<bool>(p.size() + 1, false));
        f[0][0] = true;
        for (int k = 1; k <= p.size() && p[k - 1] == '*'; k++) f[0][k] = true;
        
        for (int i = 1; i <= s.size(); i++) {
            char x = s[i - 1];
            for (int j = 1; j <= p.size(); j++) {
                char y = p[j - 1];
                
                if (y == '*') {
                    f[i][j] = f[i][j - 1] || f[i - 1][j] || f[i - 1][j - 1];
                } else if (y == '?') {
                    f[i][j] = f[i - 1][j - 1];
                }else {
                    f[i][j] = f[i - 1][j - 1] && x == y;
                }
            }
        }
        
        return f[s.size()][p.size()];
    }
};
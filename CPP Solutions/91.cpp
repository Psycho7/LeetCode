class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        if (s[0] == '0') return 0;
        
        vector<int> f(s.size());
        
        f[0] = 1;

        for (int i = 1; i < s.size(); i++) {
            f[i] = 0;
            
            if (s[i] > '0') f[i] += f[i - 1];
            
            int tmp = (s[i - 1] - '0') * 10 + s[i] - '0';
            if (tmp == 0 || tmp > 26  && s[i] == '0') return 0;
            if (tmp < 27) {
                if (i > 1 && s[i - 1] != '0') f[i] += f[i - 2];
                if (i == 1) f[i]++;
            }
        }
        
        return f[s.size() - 1];
    }
};
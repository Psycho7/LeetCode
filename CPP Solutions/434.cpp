class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        bool space = true;
        
        for (auto ch: s) {
            if (ch == ' ') {
                if (!space) ans++;
                space = true;
            } else {
                space = false;
            }
        }
        
        if (!space) ans++;
        
        return ans;
    }
};
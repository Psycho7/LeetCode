class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string prev = countAndSay(n - 1);
        stringstream ss;
        
        int idx = 0;
        while (idx < prev.size()) {
            auto ch = prev[idx];
            int cnt = 0;
            while (idx < prev.size() && ch == prev[idx]) {
                idx++;
                cnt++;
            }
            ss << cnt << ch;
        }
        
        return ss.str();
    }
};
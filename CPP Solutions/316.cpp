class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last[256];
        bool has[256];
        memset(last, 0, sizeof(last));
        memset(has, 0, sizeof(has));
        for (int i = 0; i < s.size(); i++) {
            last[s[i]] = i;
        }
        string result;
        char c;
        for (int i = 0; i < s.size(); i++) {
            c = s[i];
            if (has[c]) {
                continue;
            }
            while (result.size() && c < result.back() && last[result.back()] > i) {
                has[result.back()] = false;
                result.pop_back();
            }
            result.push_back(c);
            has[c] = true;
        }
        return result;
    }
};

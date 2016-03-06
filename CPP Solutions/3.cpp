class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];
        for (int i = 0; i < 256; i++) {
            last[i] = -1;
        }
        int ans = 0;
        int head = 0;
        for (int i = 0; i < s.length(); i++) {
            if (last[s[i]] >= head) {
                head = last[s[i]] + 1;
            }
            if (i - head + 1 > ans) {
                ans = i - head + 1;
            }
            last[s[i]] = i;
        }
        return ans;
    }
};

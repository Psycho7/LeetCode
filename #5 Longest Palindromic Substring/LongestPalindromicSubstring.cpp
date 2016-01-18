class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 1;
        int left = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (i > 0 && s[i - 1] == s[i]) {
                continue;
            }
            int head = i, size = 1;
            while((head + size < len) &&  (s[head] == s[head + size]))
                size++;
            while((head > 0) && (head + size < len) && (s[head - 1] == s[head + size])) {
                head--;
                size += 2;
            }
            if (size > ans) {
                ans = size;
                left = head;
            }
        }
        return s.substr(left, ans);
    }
};
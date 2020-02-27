class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        
        if (n == 0) return 0;
        
        for (int pos = 0; pos < m - n + 1; pos++) {
            bool flag = true;
            for (int len = 0; flag && len < n; len++) {
                flag &= haystack[pos + len] == needle[len];
            }
            if (flag) return pos;
        }
        
        
        return -1;
    }
};
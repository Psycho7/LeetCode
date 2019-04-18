class Solution {
public:
    int firstUniqChar(string s) {
        int dict[30] = {0};
        
        for (char ch : s) {
            dict[ch - 'a']++;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (dict[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
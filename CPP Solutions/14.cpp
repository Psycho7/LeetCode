class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string result = "";
        int len = 0;
        while (len < strs[0].size()) 
        {
            for (int i = 1; i < strs.size(); i++) {
                if (strs[0][len] != strs[i][len]) {
                    return result;
                }
            }
            result += strs[0][len++];
        }
        
        return result;
    }
};
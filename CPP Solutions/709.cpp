class Solution {
public:
    string toLowerCase(string str) {
        string ans;
        for (auto ch: str) {
            if ('A' <= ch && ch <= 'Z') {
                ans.push_back(ch - 'A' + 'a');
            } else {
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};
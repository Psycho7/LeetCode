class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        int cnt = 0;
        for (char ch: S) {
            bool flag = true;
            if (ch == '(') {
                cnt++;
                flag = cnt != 1;
            } else {
                cnt--;
                flag = cnt != 0;
            }
            if (flag) {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
// Just a STUPID and SIMPLE solution

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string lines[1000];

        int n = s.size();
        for (int i(0), x(0), y(0); i < n; i++) {
            lines[x] += s[i];
            if (y % (numRows - 1) == 0 && x < (numRows - 1)) {
                x++;
            } else {
                x--;
                y++;
            }
        }

        string ans("");
        for (int i = 0; i < numRows; i++) ans += lines[i];
        return ans;
    }
};

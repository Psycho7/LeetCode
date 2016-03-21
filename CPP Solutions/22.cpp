#include <functional>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int maxLen = n << 1;
        string temp(maxLen, ' ');
        function<void(int, int)> dfs = [&](int dep, int left) {
            if (dep == maxLen) {
                ans.push_back(temp);
                return;
            }
            if (left < n) {
                temp[dep] = '(';
                dfs(dep + 1, left + 1);
            }
            if (left << 1 > dep) {
                temp[dep] = ')';
                dfs(dep + 1, left);
            }
        };
        dfs(0, 0);
        return ans;
    }
};

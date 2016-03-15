class Solution {
public:
    vector<string> letterCombinations(string digits) {
        char table[10][4] = {{ ' ' }, { ' ' }, { 'a', 'b', 'c' }, {'d', 'e', 'f'}, 
                {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, 
                {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        int num[10] = {1, 0, 3, 3, 3, 3, 3, 4, 3, 4};
        
        int len = digits.size();
        vector<string> result;
        if (!len) return result;
        
        string temp(len, ' ');
        //void (*dfs)(int);
        std::function<void(int)> dfs;
        dfs = [&](int dep) {
            if (dep == len) {
                result.push_back(temp);
                return;
            }
            int number = digits[dep] - '0';
            for (int i = 0; i < num[number]; i++) {
                temp[dep] = table[number][i];
                dfs(dep + 1);
            }
        };
        
        dfs(0);
        return result;
    }
};

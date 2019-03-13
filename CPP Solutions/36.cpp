class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> set;
        
        auto valid = [&set](int encode) -> bool {
            if (set.count(encode)) return false;
            set.insert(encode);
            return true;
        };
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int rowCode = i * 100 + 9 * 10 + board[i][j] - '0';
                int colCode = 9 * 100 + j * 10 + board[i][j] - '0';
                int secCode = (i / 3) * 100 + (j / 3) * 10 + board[i][j] - '0';
                if (!(valid(rowCode) && valid(colCode) && valid(secCode))) return false;
            }
        }
        
        return true;
    }
};
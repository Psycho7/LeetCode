class Solution {
public:
    vector<vector<char>> map;
    
    vector<vector<bool>> visit;
    
    int m, n;
    
    string str;
    
    const int move[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return word.empty();
        
        map = board;
        str = word;
        
        m = board.size();
        n = board[0].size();
        
        visit = vector<vector<bool>>(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == str[0]) {
                    if (dfs(0, i, j)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    bool dfs(int pos, int x, int y) {
        if (str[pos] != map[x][y]) return false;
        if (pos == str.size() - 1) return true;
        
        visit[x][y] = true;
        
        for (int k = 0; k < 4; k++) {
            int dx = x + move[k][0];
            int dy = y + move[k][1];
            
            if (dx < 0 || m <= dx
                || dy < 0 || n <= dy
                || visit[dx][dy]
               ) {
                continue;
            }
            
            if (dfs(pos + 1, dx, dy)) return true;
        }
        
        visit[x][y] = false;
        return false;
    }
};
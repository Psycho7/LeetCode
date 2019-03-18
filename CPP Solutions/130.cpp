class Solution {
public:
    
    int move[4][2] = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };
    
    
    int m, n;
    
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        m = board.size(), n = board[0].size();
        
        auto visit = vector(m, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++) {
            if (!visit[0][i]) dfs(board, visit, 0, i);
            if (!visit[m - 1][i]) dfs(board, visit, m - 1, i);
        }
        for (int i = 0; i < m; i++) {
            if (!visit[i][0]) dfs(board, visit, i, 0);
            if (!visit[i][n - 1]) dfs(board, visit, i, n - 1);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j]) board[i][j] = 'X';
            }
        }
    }
    
    void dfs(
        vector<vector<char>>& board,
        vector<vector<bool>>& visit, 
        int x, int y) {
        if (board[x][y] == 'X') return;
        visit[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int dx = x + move[i][0];
            int dy = y + move[i][1];
            
            if (dx < 0 || m <= dx 
                || dy < 0 || n <= dy 
                || board[dx][dy] == 'X' 
                || visit[dx][dy]) continue;
            dfs(board, visit, dx, dy);
        }
        
    }
};
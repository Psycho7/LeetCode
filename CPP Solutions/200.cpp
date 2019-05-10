class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        int num = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (this->grid[i][j] == '1') {
                    num++;
                    dfs(i,j);
                }
            }
        }
        return num;
    }
private:
    void dfs(int x, int y) {
        grid[x][y] = '0';
        for (auto& mv: move) {
            int dx = x + mv[0];
            int dy = y + mv[1];
            
            if (0 <= dx && dx < m
               && 0 <= dy && dy < n
               && grid[dx][dy] == '1') {
                dfs(dx, dy);
            }
        }
    }
    
    int m, n;
    
    int move[4][2] = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };
    
    vector<vector<char>> grid;
};
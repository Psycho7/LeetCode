class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0 ; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int aliveCount = 0;
                int deadCount = 0;
                for (int x = max(0, i-1); x <= min(m-1, i+1); x++) {
                    for (int y = max(0, j-1); y <= min(n-1, j+1); y++) {
                        aliveCount += board[x][y] & 1;
                        deadCount += (board[x][y] & 1) ^ 1;
                    }
                }
                if (board[i][j]) {  // alive
                    aliveCount--;
                    if (aliveCount == 2 || aliveCount == 3) {
                        board[i][j] = board[i][j] | 2;
                    }
                    
                } else {            // dead
                    deadCount--;
                    if (aliveCount == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }
        
        for (int i = 0 ; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
};
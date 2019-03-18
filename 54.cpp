class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int move[4][2] = {
            {1, 0}, {0, 1}, 
            {-1, 0}, {0, -1}
        };
        
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        
        int x = 0, y = 0;
        int dx, dy;
        int dir = 0;
        int m = matrix.size(), n = matrix[0].size();
        auto visit = vector<vector<bool>>(m, vector<bool>(n, false));
        
        while (1) {
            ans.push_back(matrix[y][x]);
            visit[y][x] = true;
            
            if (ans.size() == m * n) break;
            
            bool flag = false;
            do {
                if (flag) {
                    dir = (dir + 1) % 4;
                }
                dx = x + move[dir][0];
                dy = y + move[dir][1];
                
                flag = dx < 0 || n <= dx || dy < 0 || m <= dy || visit[dy][dx];
            } while (flag);
            
            x = dx;
            y = dy;
        }
        
        return ans;
    }
};
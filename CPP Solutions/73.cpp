class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        
        bool first_row = false;
        bool first_col = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                first_col = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                first_row = true;
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for (int i = 0; first_col && i < m; i++) {
            matrix[i][0] = 0;
        }
        for (int j = 0; first_row && j < n; j++) {
            matrix[0][j] = 0;
        }
        
    }
};
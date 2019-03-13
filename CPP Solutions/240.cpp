class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        return deepSearch(matrix, target, 0, matrix.size(), 0, matrix[0].size());
    }
    
    bool deepSearch(vector<vector<int>>& matrix, int target, int x0, int x1, int y0, int y1) {
        if (x0 >= x1 || y0 >= y1) return false;
        
        int xMid = (x0 + x1) >> 1;
        int yMid = (y0 + y1) >> 1;
        
        int key = matrix[xMid][yMid];
        for (int dx = x0; dx < x1; dx++) if (matrix[dx][yMid] == target) return true;
        for (int dy = y0; dy < y1; dy++) if (matrix[xMid][dy] == target) return true;
        
        
        auto leftUp = [&]() -> bool {
            return deepSearch(matrix, target, x0, xMid, y0, yMid);
        };
        auto leftDown = [&]() -> bool {
            return deepSearch(matrix, target, xMid + 1, x1, y0, yMid);
        };
        auto rightUp = [&]() -> bool {
            return deepSearch(matrix, target, 0, xMid, yMid + 1, y1);
        };
        auto rightDown = [&]() -> bool {
            return deepSearch(matrix, target, xMid + 1, x1, yMid + 1, y1);
        };
        
        if (target < key) return leftUp() || leftDown() || rightUp();
        if (target > key) return rightDown() || leftDown() || rightUp();
        
        return false;
    }
};
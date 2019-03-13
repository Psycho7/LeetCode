class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int head = matrix[0][0];
        int tail = matrix[n-1][n-1] + 1;
        
        while (head < tail) {
            int mid = head + (tail - head) / 2;
            int sum = 0;
            for (auto& row : matrix) {
                sum += 1 + upperBoundIdx(row, mid);
            }
            if (sum < k) {
                head = mid + 1;
            } else {
                tail = mid;
            }
        }
        return head;
    }
    
    int upperBoundIdx(vector<int>& f, int key) {
        int head = 0, tail = f.size();
        
        while (head < tail) {
            int mid = head + (tail - head) / 2;
            if (f[mid] <= key) {
                head = mid + 1;
            } else {
                tail = mid;
            }
        }
        return head - 1;
    }
};
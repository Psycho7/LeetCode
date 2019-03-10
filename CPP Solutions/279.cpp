class Solution {
public:
    int numSquares(int n) {
        int* f = new int[n + 1];
        memset(f, 0x3f, (n + 1) * sizeof(int));
        f[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            int max_sqrt = sqrt(i);
            for (int j = 1; j <= max_sqrt; j++) {
                int sqr = j * j;
                f[i] = min(f[i], f[i - sqr] + 1);   
            }
        
        }
        return f[n];
    }
};
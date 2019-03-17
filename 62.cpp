class Solution {
public:
    int uniquePaths(int m, int n) {
        int p = m + n - 2;
        int k = (m < n ? m : n) - 1;
        
        long ans = 1;
        for (int i = 1; i <= k; i++) {
            ans = ans * (p - k + i) / i;
        }
        return (int)ans;
    }
};
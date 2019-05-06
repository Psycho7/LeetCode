class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        auto f = vector(n + 1, vector(m + 1, 0));
        for (int i = 0; i <= n; i++) f[i][0] = i;
        for (int i = 0; i <= m; i++) f[0][i] = i;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = f[i-1][j-1] + (word1[i-1]==word2[j-1] ? 0 : 1);
                f[i][j] = min(f[i-1][j] + 1, f[i][j]);
                f[i][j] = min(f[i][j-1] + 1, f[i][j]);
            }
        }
        
        return f[n][m];
    }
};
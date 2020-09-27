#define ADD(from, to) f[next][to] = (f[next][to] + f[now][from]) % MOD

class Solution {
public:
    const static int MOD = 1e9 + 7;
    
    int countVowelPermutation(int n) {
        int f[2][5];
        int now = 0, next;
        for (int i = 0; i < 5; i++) f[now][i] = 1;
        
        while (n > 1) {
            next = now ^ 1;
            memset(f[next], 0, sizeof(int) * 5);
            
            // 0 -> a
            // 1 -> e
            // 2 -> i
            // 3 -> o
            // 4 -> u
            
            // a
            ADD(0, 1);
            
            // e
            ADD(1, 0);
            ADD(1, 2);
            
            // i
            ADD(2, 0);
            ADD(2, 1);
            ADD(2, 3);
            ADD(2, 4);
            
            // o
            ADD(3, 2);
            ADD(3, 4);
            
            // u
            ADD(4, 0);
            
            now = next;
            n--;
        }
        
        int ans = 0;
        for (int i = 0; i < 5; i++) {
            ans = (ans + f[now][i]) % MOD;
        }
        
        return ans;
    }
};
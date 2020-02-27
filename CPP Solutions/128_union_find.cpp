class Solution {
public:
    unordered_map<int, int> father;
    
    unordered_map<int, int> count;
    
    int find(int x) {
        if (father[x] == x) return x;
        father[x] = find(father[x]);
        return father[x];
    }
    
    void bind(int x, int y) {
        int x_f = find(x);
        int y_f = find(y);
        
        if (x_f != y_f) {
            int x_s = count[x_f];
            int y_s = count[y_f];
            
            if (x_s < y_s) {
                father[y_f] = x_f;
                count[x_f] = x_s + y_s;
            } else {
                father[x_f] = y_f;
                count[y_f] = x_s + y_s;
            }
        }
    }
    
    int size(int x) {
        return count[find(x)];
    }
    
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        
        for (const auto& n: nums) {
            if (father.count(n) == 0) {
                father[n] = n;
                count[n] = 1;
                
                if (father.count(n - 1)) {
                    bind(n, n - 1);
                }
                if (father.count(n + 1)) {
                    bind(n, n + 1);
                }
                
                int tmp = size(n);
                if (tmp > ans) {
                    ans = tmp;
                }
            }
        }
        
        return ans;
    }
};
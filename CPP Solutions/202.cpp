class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visit;
        visit.insert(n);
        while (n != 1) {
            int m = 0;
            while (n > 0) {
                int t = n % 10;
                n /= 10;
                m += t * t;
            }
            if (visit.count(m)) return false;
            visit.insert(m);
            n = m;
        }
        return true;
    }
};
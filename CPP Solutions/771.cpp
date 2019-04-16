class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> set;
        
        for (auto ch : J) {
            set.insert(ch);
        }
        
        int ans = 0;
        for (auto ch : S) {
            if (set.count(ch)) {
                ans++;
            }
        }
        
        return ans;
    }
};
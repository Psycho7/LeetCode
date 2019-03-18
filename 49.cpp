class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> prime;
        bool p[200];
        memset(p, 1, sizeof(bool) * 200);
        for (int i = 2; i < 200; i++) {
            if (!p[i]) continue;
            prime.push_back(i);
            if (prime.size() == 26) break;
            for (int j = 2; j < 200 / i; j++) {
                p[i * j] = false;
            }
        }
            
        unordered_map<long, vector<string>> dict;
        for (auto str : strs) {
            long key = 1;
            for (auto ch : str) {
                key = key * prime[ch - 'a'] % 1000000007;
            }
            if (dict.count(key) == 0) {
                dict[key] = vector<string>();
            }
            dict[key].push_back(str);
        }
        
        vector<vector<string>> ans;
        for (auto& kv : dict) {
            ans.push_back(kv.second);
        }
        
        return ans;
    }
};
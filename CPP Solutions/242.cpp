class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> dict;
        
        for (auto ch : s) {
            dict[ch] = dict[ch] + 1;
        }
        for (auto ch : t) {
            dict[ch] = dict[ch] - 1;
            if (dict[ch] < 0) return false;
        }
        for (auto& kv : dict) {
            if (kv.second != 0) return false;
        }
        return true;
    }
};
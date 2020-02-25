class Solution {
public:
    string minWindow(string s, string t) {
        int ans = 1 << 30;
        int pos = 0;
        
        unordered_map<char, int> needs;
        for (const auto& ch: t) {
            needs[ch]++;
        }
        
        int missing = t.size();
        int head = 0, tail = 0;
        while (missing && tail < s.size()) {
            char ch = s[tail++];
            if (needs.count(ch)) {
                if (needs[ch] > 0) {
                    missing--;
                }
                needs[ch]--;
            }
        }
        
        if (missing) return "";
        
        while (tail < s.size()) {
            /* DUPLICATED - SHRIKING */
            while (head < tail) {
                char ch = s[head];
                
                if (needs.count(ch) == 0) {
                    head++;
                } else if (needs[ch] < 0) {
                    head++;
                    needs[ch]++;
                } else {
                    break;
                }
            }
            
            if (tail - head < ans) {
                ans = tail - head;
                pos = head;
            }
            /* DUPLICATED - SHRIKING */
            
            while (tail < s.size()) {
                char ch = s[tail++];
                if (needs.count(ch)) {
                    needs[ch]--;
                    break;
                }
            }
        }
        
        /* DUPLICATED - SHRIKING */
        while (head < tail) {
            char ch = s[head];

            if (needs.count(ch) == 0) {
                head++;
            } else if (needs[ch] < 0) {
                head++;
                needs[ch]++;
            } else {
                break;
            }
        }

        if (tail - head < ans) {
            ans = tail - head;
            pos = head;
        }
        /* DUPLICATED - SHRIKING */

        
        return s.substr(pos, ans);
    }
};
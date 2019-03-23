class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto f = vector(wordList.size(), 0);
        
        queue<int> qs[2];
        for (int i = 0; i < wordList.size(); i++) {
            if (valid(wordList[i], beginWord)) {
                qs[0].push(i);
                f[i] = 2;
            }
        }
        
        int cur = 0;
        while (!qs[cur].empty()) {
            int next = cur ^ 1;
            
            while (!qs[cur].empty()) {
            
                int k = qs[cur].front();
                
                qs[cur].pop();
                if (wordList[k] == endWord) return f[k];
                
                for (int i = 0; i < wordList.size(); i++) {
                    if (f[i] == 0 && valid(wordList[i], wordList[k])) {
                        f[i] = f[k] + 1;
                        qs[next].push(i);
                    }
                }
            }
            
            cur = next;
        }
        
        return 0;
    }
    
    bool valid(string x, string y) {
        if (x.size() != y.size()) return false;
        int cnt = 0;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] != y[i]) cnt++;
        }
        return cnt == 1;
    }
};
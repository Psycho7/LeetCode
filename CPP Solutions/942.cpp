class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
        
        int n = S.size();
        
        int maxi = n;
        int mini = 0;
        
        for (auto ch : S) {
            if (ch == 'I') res.push_back(mini++);
            if (ch == 'D') res.push_back(maxi--);
        }
        
        res.push_back(mini);
        return res;
    }
};
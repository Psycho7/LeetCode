class Solution {
public:
    vector<vector<string>> partition(string s) {
        str = s;
        size = s.size();
        vector<vector<bool>> isPali(size, vector<bool>(size, false));
        
        for (int len = 1; len <= size; len++) {
            for (int i = 0; i <= size - len; i++) {
                int j = i + len - 1;
                bool flag = true;
                for (int k = 0; flag && k < len / 2; k++) {
                    flag = flag && s[i + k] == s[j - k];
                }
                isPali[i][j] = flag;
            }
        }
        
        result.clear();
        
        DFS(isPali, vector<string>(), 0);
        
        return result;
    }
private:
    int size;
    
    string str;
    
    vector<vector<string>> result;
    
    void DFS(vector<vector<bool>>& isPali, vector<string> answer, int position) {
        if (position == size) {
            result.push_back(answer);
            return;
        }
        
        for (int pos = position; pos < size; pos++) {
            if (isPali[position][pos]) {
                answer.push_back(str.substr(position, pos - position + 1));
                DFS(isPali, answer, pos + 1);
                answer.pop_back();
            }
        }
    }
};
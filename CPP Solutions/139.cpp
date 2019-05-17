class Node {
public:
    bool isLeaf;
    
    Node() {
        memset(list, 0, 26 * sizeof(Node*));    
        isLeaf = false;
    }
    
    Node* next(char ch) {
        return list[tolower(ch) - 'a'];
    }
    
    void addNode(char ch) {
        list[tolower(ch) - 'a'] = new Node();
    }
private:
    Node* list[26];
};

class Solution {
public:
    Node* root;
    
    string str;
    
    vector<vector<int>> memo;
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        memo = vector(n + 1, vector(n + 1, 0));
        root = new Node();
        root->isLeaf = true;
        str = s;
        
        for (auto& word: wordDict) {
            insert(word);
        }
        
        return dfs(0, n);
    }
    
    void insert(string& word) {
        Node* p = root;
        for (char& ch: word) {
            if (p->next(ch) == NULL) {
                p->addNode(ch);
            }
            p = p->next(ch);
        }
        p->isLeaf = true;
    }
    
#define VALID 1
#define INVALID 2
    
    bool dfs(int head, int tail) {
        if (head == tail) return true;
        if (memo[head][tail]) {
            return memo[head][tail] == VALID;
        }
        
        bool flag = false;
        Node* p = root;
        int idx = head;
        while (p && idx < tail) {
            p = p->next(str[idx]);
            idx++;
        }
        
        if (p && p->isLeaf && idx == tail) {
            flag = true;
        }
        
        if (!flag) {
            for (int k = head + 1; !flag && k < tail; k++) {
                flag = dfs(head, k) && dfs(k, tail);
            }
        }
        
        if (flag) {
            memo[head][tail] = VALID;
        } else {
            memo[head][tail] = INVALID;
        }
        
        return flag;
    }
};
class TrieNode {
public:
    vector<TrieNode*> links = vector<TrieNode*>(26);
        
    bool isEnd = false;
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for (char ch : word) {
            if (!p->links[ch - 'a']) {
                p->links[ch - 'a'] = new TrieNode();
            }
            p = p->links[ch - 'a'];
        }
        p->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = root;
        for (char ch : word) {
            if (!p->links[ch - 'a']) {
                return false;
            }
            p = p->links[ch - 'a'];
        }
        return p->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = root;
        for (char ch : prefix) {
            if (!p->links[ch - 'a']) {
                return false;
            }
            p = p->links[ch - 'a'];
        }
        return true;
    }
    

};

class Solution {
public:
    set<string> result;
    
    int move[4][2] = {
        {-1, 0}, {+1, 0}, {0, -1}, {0, +1}
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (auto word : words) {
            trie.insert(word);
        }
        
        auto visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        
        result.clear();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                visited[i][j] = true;
                string word = string() + board[i][j];
                DFS(trie, visited, board, i, j, word);
                visited[i][j] = false;
            }
        }
        
        vector<string> tmp(result.begin(), result.end());
        return tmp;
    }
    
    void DFS(
        Trie& trie,
        vector<vector<bool>>& visited,
        vector<vector<char>>& board,
        int x, int y, string word) {
        if (!trie.startsWith(word)) {
            return;
        }
        if (trie.search(word)) {
            result.insert(word);
        }
        
        for (int idx = 0; idx < 4; idx++) {
            int dx = x + move[idx][0];
            int dy = y + move[idx][1];
            if (0 <= dx && dx < board.size() &&
               0 <= dy && dy < board[0].size() &&
               !visited[dx][dy]) {
                visited[dx][dy] = true;
                DFS(trie, visited, board, dx, dy, word + board[dx][dy]);
                visited[dx][dy] = false;
            }
        }
        
    }
};
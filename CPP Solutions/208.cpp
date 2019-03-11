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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
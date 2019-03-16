class LinkNode {
public:
    int key;
    int value;
    LinkNode* prev = nullptr;
    LinkNode* next = nullptr;
    
    LinkNode(int key, int value): 
        key(key), value(value) { }
};

class LRUCache {
private:
    LinkNode* head = new LinkNode(0, 0);
    
    LinkNode* tail = new LinkNode(0, 0);
    
    int size = 0;
    
    int maxSize;
    
    unordered_map<int, LinkNode*> dict;
    
    void removeNode(LinkNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void insertBetween(LinkNode* node, LinkNode* prev, LinkNode* next) {
        prev->next = node;
        node->prev = prev;
        next->prev = node;
        node->next = next;
    }
    
public:
    LRUCache(int capacity): maxSize(capacity) {
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!dict.count(key)) return -1;
        
        auto node = dict[key];
        removeNode(node);
        insertBetween(node, tail->prev, tail);
        
        return dict[key]->value;
    }
    
    void put(int key, int value) {
        if (dict.count(key)) {
            auto node = dict[key];
            dict.erase(key);
            
            removeNode(node);
            delete node;
            size--;
        }
        if (size == maxSize) {
            auto node = head->next;
            dict.erase(node->key);
            
            removeNode(node);
            delete node;
            size--;
        }
        
        auto node = new LinkNode(key, value);
        insertBetween(node, tail->prev, tail);
        dict[key] = node;
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
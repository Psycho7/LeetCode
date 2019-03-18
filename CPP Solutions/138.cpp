/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> dict;
    
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        if (dict.count(head)) return dict[head];
        
        Node* newNode = new Node(head->val, NULL, NULL);
        dict[head] = newNode;
        newNode->next = copyRandomList(head->next);
        newNode->random = copyRandomList(head->random);
        
        return newNode;
    }
};
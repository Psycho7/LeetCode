/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> dict;
    
    Node* cloneGraph(Node* node) {
        if (dict.count(node)) {
            return dict[node];
        }
        
        Node* curr = new Node(node->val, vector<Node*>());
        dict[node] = curr;
        for (Node* adj : node->neighbors) {
            curr->neighbors.push_back(cloneGraph(adj));
        }
        
        return curr;
    }
};
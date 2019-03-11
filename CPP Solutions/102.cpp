/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> bfsQ[2];
        int curr = 0;
        bfsQ[curr].push(root);
        while (!bfsQ[curr].empty()) {
            int next = 1 ^ curr;
            vector<int> currRow;
            
            while (!bfsQ[curr].empty()) {
                auto node = bfsQ[curr].front();
                bfsQ[curr].pop();
                currRow.push_back(node->val);
                if (node->left) bfsQ[next].push(node->left);
                if (node->right) bfsQ[next].push(node->right);
            }
            
            result.push_back(currRow);
            
            curr = next;
        }
        
        return result;
    }
    
};
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> bfsQ[2];
        int curr = 0;
        int level = 0;
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
            
            if (level & 1 == 1) {
                int size = currRow.size();
                for (int i = 0; i < size / 2; ++i) {
                    swap(currRow[i], currRow[size - i - 1]);
                }
           }
            
            result.push_back(currRow);
            
            curr = next;
            level++;
        }
        
        return result;
    }
    
};
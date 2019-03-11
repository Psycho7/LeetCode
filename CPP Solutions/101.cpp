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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return checkChild(root->left, root->right);
    }
    
    bool checkChild(TreeNode* left, TreeNode* right) {
        if (!left ^ !right) return false;
        if (!left && !right) return true;
        if (left->val != right->val) return false;
        
        bool result = checkChild(left->left, right->right)
            && checkChild(left->right, right->left);
        return result;
    }
};
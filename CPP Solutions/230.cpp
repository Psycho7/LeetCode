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
    int kthSmallest(TreeNode* root, int k) {
        int leftCount = count(root->left);
        
        if (k == leftCount + 1) return root->val;
        if (k <= leftCount) return kthSmallest(root->left, k);
        return kthSmallest(root->right, k - leftCount - 1);
    }
    
    int count(TreeNode* root) {
        if (!root) return 0;
        int cnt = 1 + count(root->left) + count(root->right);
        return cnt;
    }
};
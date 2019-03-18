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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {  
        auto q = deque<int>(preorder.begin(), preorder.end());
        return build(q, inorder, 0, inorder.size());
    }
    
    TreeNode* build(deque<int>& preorder, vector<int>& inorder,
                   int left, int right) {
        if (left >= right) return NULL;
        
        auto root = new TreeNode(preorder.front());
        preorder.pop_front();
        
        int pos = left;
        while (pos < right && inorder[pos] != root->val) pos++;
        
        root->left = build(preorder, inorder, left, pos);
        root->right = build(preorder, inorder, pos + 1, right);
        
        return root;
    }
};
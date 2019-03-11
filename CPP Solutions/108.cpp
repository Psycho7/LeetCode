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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums, 0, nums.size());
    }
    
    TreeNode* constructBST(vector<int>& nums, int left, int right) {
        if (left >= right) return NULL;
        int mid = (left + right) >> 1;
        auto node = new TreeNode(nums[mid]);
        node->left = constructBST(nums, left, mid);
        node->right = constructBST(nums, mid + 1, right);
        return node;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        if (root == nullptr) return "";
        
        vector<string> f[2];
        vector<TreeNode*> queue[2];
        vector<string> candi;
        
        int now = 0;
        string rstr;
        rstr.push_back((char)('a' + root->val));
        f[now].push_back(rstr);
        queue[now].push_back(root);
        
        while (!queue[now].empty()) {
            int next = now ^ 1;
            
            f[next].clear();
            queue[next].clear();
            
            for (int i = 0; i < queue[now].size(); i++) {
                auto node = queue[now][i];
                auto str = f[now][i];
                
                // cout << node->val << ": " << str << endl;
                
                if (node->left == nullptr && node->right == nullptr) {
                    string tmp;
                    for (int j = str.size() - 1; j >= 0; j--) {
                        tmp += str[j];
                    }
                    candi.push_back(tmp);
                    
                    continue;
                }
                
                if (node->left) {
                    queue[next].push_back(node->left);
                    f[next].push_back(str + (char)('a' + node->left->val));
                }
                if (node->right) {
                    queue[next].push_back(node->right);
                    f[next].push_back(str + (char)('a' + node->right->val));
                }
                
            }
            
            now = next;
        }
        
        int ans_idx = 0;
        for (int i = 1; i < candi.size(); i++) {
            if (candi[ans_idx].compare(candi[i]) > 0) {
                ans_idx = i;
            }
        }
        
        return candi[ans_idx];
    }
};
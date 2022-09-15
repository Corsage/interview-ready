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
    
    string tree2str(TreeNode* root) {
        string res = "";
        
        if (root == nullptr) {
            return res;
        }
        
        string left = tree2str(root->left);
        string right = tree2str(root->right);
        
        res += to_string(root->val);
        
        if (!left.empty()) {
            res += "(" + left + ")";
        }
        
        if (!right.empty()) {
            if (left.empty()) {
                // Preserve one-to-one mapping.
                res += "()";
            }
            res += "(" + right + ")";
        }
        
        return res;
    }
};
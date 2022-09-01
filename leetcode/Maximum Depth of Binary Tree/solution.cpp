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
    
    int rMaxDepth(TreeNode* root, int depth) {
        // Base case.
        if (root == nullptr) {
            return depth;
        }
        
        // Recursive case.
        int left = rMaxDepth(root->left, depth + 1);
        int right = rMaxDepth(root->right, depth + 1);
        
        return (left > right) ? left : right;
    }
    
    int maxDepth(TreeNode* root) {
        return rMaxDepth(root, 0);
    }
};
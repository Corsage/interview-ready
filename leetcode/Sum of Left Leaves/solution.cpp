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
     
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        
        if (root == nullptr) {
            return sum;
        }
        
        // Make sure left child has no children, so it is a leaf.
        if (root->left && (root->left->left == root->left->right)) {
            sum += root->left->val;
        }
        
        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
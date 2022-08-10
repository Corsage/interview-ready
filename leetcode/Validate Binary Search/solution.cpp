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
    /*
     * We use in-order traversal to check if it's a valid BST.
     * We keep in mind the constraints (min, max) that a value can be.
     *
     * Time complexity - O(n) and Space complexity - O(n) due to max depth of recursion tree.
     */
    bool rIsValidBST(TreeNode* node, long min, long max)
    {
        // Base case.
        if (node == nullptr) { return true; }
        
        // Check if valid.
        if (node->val <= min || node->val >= max) { return false; }
        
        // Recursive case - In-order traversal.
        return rIsValidBST(node->left, min, node->val) && rIsValidBST(node->right, node->val, max);
    }
    
    bool isValidBST(TreeNode* root)
    {
        // Check if the tree is only one node.
        return rIsValidBST(root, numeric_limits<long>::min(), numeric_limits<long>::max()); 
    }
};
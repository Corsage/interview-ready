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
     * Inorder traversal - we start with the leftmost element and work our way up.
     * Simple recursive method.
     *
     * Time complexity - O(n) and Space complexity - O(n).
     */
    void rInorderTraversal(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr) { return; }
        
        if (node->left != nullptr)
        {
            rInorderTraversal(node->left, res);
        }
        
        res.push_back(node->val);
        
        if (node->right != nullptr)
        {
            rInorderTraversal(node->right, res);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        rInorderTraversal(root, res);
        
        return res;
    }
};
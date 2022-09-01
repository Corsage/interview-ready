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
     * To invert a binary tree we perform a depth-first search (DFS).
     * Since this is C++, we can simply swap the pointers, and that will
     * bring their associated subtree with us as well, and we recursively
     * continue to swap until we reach NULL.
     * 
     * Time complexity - O(n) and Space complexity - O(n) where n is the depth
     * of the tree.
     */
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
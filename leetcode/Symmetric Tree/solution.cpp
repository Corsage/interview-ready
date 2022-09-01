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
     * To see if a binary tree is symmetrical from the center,
     * we disgard the root node, and check the left and right
     * subtrees, checking their value. We keep two pointers, p and q
     * to compare the left and right of each left and right subtree.
     * 
     * Time complexity - O(n) and Space complexity - O(n).
     */
    bool rIsSymmetric(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }
        
        if (p->val != q->val) {
            return false;
        }
        
        return rIsSymmetric(p->left, q->right) && rIsSymmetric(p->right, q->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        TreeNode* p = root->left;
        TreeNode* q = root->right;
        
        return rIsSymmetric(p, q);
    }
};
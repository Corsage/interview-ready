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
     * To compare two trees we must simply traverse them both and check if the nodes have the same value.
     * Any traversal method works, but in-order is the simplest to implement.
     *
     * Time complexity - O(n + m) and Space complexity - O(n) due to max depth of recursion tree.
     */
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Perform in-order traversal, comparing ea node.
        if (p != nullptr && q != nullptr)
        {
            if (p->val != q->val) { return false; }
        }
        else if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
        {
            return false;
        }
        else if (p == nullptr && q == nullptr)
        {
            return true;
        }
        
        // Recursive case - check the children.
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);    
    }
};
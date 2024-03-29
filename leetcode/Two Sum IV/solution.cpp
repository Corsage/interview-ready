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
    
    bool bFindTarget(TreeNode* root, int target, unordered_set<int>& s) {
        if (root == nullptr) {
            return false;
        }
        
        int diff = target - root->val;
        
        if (s.find(diff) != s.end()) {
            return true;
        }
        
        s.insert(root->val);
        return bFindTarget(root->left, target, s) || bFindTarget(root->right, target, s);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return bFindTarget(root, k, s);
    }
};
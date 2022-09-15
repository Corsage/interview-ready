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

    bool containsOne(TreeNode* root) {
        // Depth-first search impl.
        if (root == nullptr) {
            return false;
        }
        
        // Check children.
        bool left = containsOne(root->left);
        bool right = containsOne(root->right);
        
        if  (!left) {
            root->left = nullptr;
        }
        
        if (!right) {
            root->right = nullptr;
        }
        
        return root->val == 1 || left || right;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        
        if (containsOne(root)) {
            return root;
        } else {
            return nullptr;
        }
    }
    
    bool hasOne(TreeNode* root) {
        // Depth-first search impl.
        
        if (root == nullptr) {
            return false;
        }
        
        if (root->val == 1) {
            return true;
        }
        
        return hasOne(root->left) || hasOne(root->right);
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        
        // Breadth-first search impl.
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            // cout << "node val: " << node->val << endl;
            if (node == nullptr) { continue; }
            if (!hasOne(node)) { return nullptr; }
            
            if (node->left != nullptr && !hasOne(node->left)) {
                node->left = nullptr;
            } else {
                q.push(node->left);
            }
            
            if (node->right != nullptr && !hasOne(node->right)) {
                node->right = nullptr;
            } else {
                q.push(node->right);
            }
        }
        
        return root;
    }
};
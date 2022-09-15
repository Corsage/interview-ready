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

    int dfs(TreeNode* root, vector<int> temp) {
        if (root == nullptr) {
            return 0;
        }
        
        temp[root->val]++;
        
        // Reach a leaf node.
        int count = 0;
        if (root->left == root->right) {
            for (int i = 1; i < temp.size(); i++) {
                count += temp[i] % 2;
            }
            
            count = (count < 2) ? 1 : 0;
        }
        
        return count + dfs(root->left, temp) + dfs(root->right, temp);
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        // Only has digits [1, 9].        
        return dfs(root, vector<int>(10));
    }

    bool isPseudoPalindromic(vector<int>& arr) {
        unordered_set<int> uset;
        
        for (auto& digit : arr) {
            if (uset.find(digit) != uset.end()) {
                uset.erase(digit);
            } else {
                uset.insert(digit);
            }
        }
        
        return uset.size() < 2;
    }
    
    bool isPseudoPalindromic(vector<int>& arr) {
        vector<int> permute(arr);
        
        do {
            vector<int> temp(permute.rbegin(), permute.rend());
            
            if (temp == permute) {
                return true;
            }
            
            next_permutation(permute.begin(), permute.end());
        } while(permute != arr);
        
        return false;
    }
    
    
    void dfs(TreeNode* root, vector<int> temp, int& count) {
        if (root == nullptr) {
            return;
        }
        
        temp.push_back(root->val);
        
        if (root->left == root->right && isPseudoPalindromic(temp)) {
            count++;
        }
        
        if (root->left != nullptr) {
            dfs(root->left, temp, count);
        }
        
        if (root->right != nullptr) {
            dfs(root->right, temp, count);
        }
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        
        dfs(root, vector<int> {}, count);
        
        return count;
    }
};
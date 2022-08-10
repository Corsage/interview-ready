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
     * We create two queues, a current queue (curr level) and next queue (next level).
     * Starting with the root node, we add to the curr and it's children (left, right) to next.
     * We dequeue one-by-one the curr queue, and whenever its empty, the level is done.
     * Since the level is done, we swap next level with curr as we are on the next.
     * This cycle makes it possible to level order a graph.
     *
     * Time complexity - O(n) and Space complexity - O(n).
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        // We use pointers so we can easily swap later.
        queue<TreeNode*>* curr = new queue<TreeNode*>;
        queue<TreeNode*>* next = new queue<TreeNode*>;
        
        curr->push(root);
        vector<int> level;
        
        // Perform a breadth first traversal.
        while (!curr->empty() && curr->front() != nullptr)
        {
            TreeNode* temp = curr->front();
            level.push_back(temp->val);
            curr->pop();
            
            if (temp->left != nullptr)
            {
                next->push(temp->left);
            }
            
            if (temp->right != nullptr)
            {
                next->push(temp->right);
            }
            
            if (curr->empty())
            {
                result.push_back(level);
                level.clear();

                // Perform swap.
                queue<TreeNode*>* qTemp = curr;
                curr =  next;
                next = qTemp;
            }
        }
        
        return result;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        vector<int> temp;
        
        if (root == nullptr) {
            return res;
        }
        
        queue<Node*>* q1 = new queue<Node*>;
        queue<Node*>* q2 = new queue<Node*>;
        
        q1->push(root);
        
        while (!q1->empty()) {
            auto n = q1->front();
            q1->pop();
            
            temp.push_back(n->val);
            
            for (int i = 0; i < n->children.size(); i++) {
                q2->push(n->children[i]);
            }
            
            if (q1->empty()) {
                res.push_back(temp);
                temp.clear();
                
                swap(q1, q2);
            }
        }
        
        return res;
    }
};
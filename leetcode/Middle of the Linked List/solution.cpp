/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /*
     * LOL we cache the list because less than 100 nodes.
     * Fast. Easy.
     */
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* t = head;
        
        while (t != nullptr)
        {
            nodes.push_back(t);
            t = t->next;
        }
        
        return nodes[nodes.size() / 2];
    }
};
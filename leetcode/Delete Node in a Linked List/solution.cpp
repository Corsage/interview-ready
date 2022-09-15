/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        // Don't have access to nodes before node.
        // Keep swapping until we reach the end.
        ListNode* curr = node;
        ListNode* prev = nullptr;
        
        while (curr->next) {
            ListNode* next = curr->next;
            curr->val = next->val;
            
            prev = curr;
            curr = next;
        }
        
        // Delete the last node now.
        prev->next = nullptr;
    }
};
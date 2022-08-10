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
     * Time complexity - O(n + m) where n and m is the size of the two lists.
     * Space complexity - O(1) since we return a pointer.
     */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {        
        // Empty case.
        if (list1 == nullptr) { return list2; }
        else if (list2 == nullptr) { return list1; }
        
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        
        ListNode* head = nullptr;
        
        // Find the head.
        if (h1->val <= h2->val) { head = h1; }
        else { head = h2; }
        
        ListNode* tail = head;
    
        while (h1 != nullptr && h2 != nullptr)
        {
            ListNode* temp = nullptr;
            if (h1->val <= h2->val)
            {
                temp = h1;
                h1 = h1->next;
            }
            else
            {
                temp = h2;
                h2 = h2->next;
            }
            tail->next = temp;
            tail = temp;
        }
        
        // Remainder.
        if (h1 != nullptr) { tail->next = h1; }
        else if (h2 != nullptr) { tail->next = h2; }
        
        return head;
    }
};
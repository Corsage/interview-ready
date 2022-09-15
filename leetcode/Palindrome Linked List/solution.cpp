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

    ListNode* reverse(ListNode* start) {
        ListNode* next = start;
        ListNode* prev = nullptr;
        
        while(start != nullptr) {
            next = start->next;
            start->next = prev;
            
            prev = start;
            start = next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        ListNode* mid = head;
        ListNode* tail = head;
        
        // We have a fast and slow ptr to, one to mid to end.
        while (tail->next != nullptr) {
            tail = tail->next;
            
            if (tail->next != nullptr) {
                mid = mid->next;
                tail = tail->next;
            }
        }
        
        // Reverse mid to end.
        mid->next = reverse(mid->next);
        mid = mid->next;
        
        while (mid != nullptr) {
            if (head->val != mid->val) {
                return false;
            }
            
            head = head->next;
            mid = mid->next;
        }
        
        return true;
    }
    
    
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        
        vector<int> res;
        while (head != nullptr) {
            res.push_back(head->val);
            head = head->next;
        }
        
        int i = 0;
        int j = res.size() - 1;
        
        while (i < j) {
            if (res[i] != res[j]) {
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
};
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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        
        while(true) {
            if (slow == NULL || fast == NULL || fast->next == NULL)
                return false;
            
            if (slow->val == fast->val && slow->next == fast->next) 
                return true;
            
            slow = slow->next;
            fast = fast->next->next;
        }
    }
};
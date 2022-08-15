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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        
        while(true) {
            if (slow == NULL || fast == NULL || fast->next == NULL)
                return NULL;
            
            if (slow->val == fast->val && slow->next == fast->next) 
            {
                ListNode *pt = head;
                ListNode *qt = slow;
                while (true) {
                    if (qt->val == pt->val && qt->next == pt->next) {
                        return qt;
                    }
                    qt = qt->next;
                    pt = pt->next;
                }
            }
            
            slow = slow->next;
            fast = fast->next->next;
        }
    }
};


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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;
        ListNode* prev = NULL;
        
        while (curr != NULL) {
            if (curr->val == val) {
                if (prev != NULL) {
                    prev->next = curr->next;
                    curr = curr->next;
                }
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};
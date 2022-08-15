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
    ListNode* reverseList(ListNode* head) {
   
        ListNode *curr = NULL;
        ListNode *top = NULL;
        
        if (head != NULL) {
            curr = head->next;
            top = new ListNode(head->val);
        }
        
        delete head;
        
        while(curr != NULL) {
            ListNode *node = new ListNode(curr->val);
            node->next = top;
            top = node;
            ListNode *tmp = curr->next;
            delete curr;
            curr = tmp;
        }
        return top;
    }
};
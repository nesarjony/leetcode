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
    int getPos(ListNode *head, ListNode *node)
    {
        ListNode *curr = head;
        int index = 0;
        while(true) {
            if (curr->val == node->val && curr->next == node->next) {
                return index;
            }
            index++;
        }
    }
    
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        
        ListNode *curr = head;
        map<ListNode*, bool> mp;
        
        while(curr != NULL) {
            if (mp.count(curr) > 0) {
                return curr;
            }
            mp[curr] = true;
            curr = curr->next;
        }
        return NULL;
    }
};
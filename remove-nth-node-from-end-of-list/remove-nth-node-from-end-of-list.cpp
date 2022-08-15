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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int len = 0;
        while(curr != NULL) {
            len++;
            curr = curr->next;
        }
        int target = len - n;
        if (target == 0) {
            ListNode *tmp = head->next;
            delete head;
            return tmp;
        }
        curr = head;
        ListNode *last = NULL;
        len = 0;
        while(curr != NULL) {
            if (len == target) {
                ListNode *tmp = curr->next;
                delete curr;
                last->next = tmp;
                break;
            }
            len++;
            last = curr;
            curr = curr->next;
        }
        return head;
    }
};
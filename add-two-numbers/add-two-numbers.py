# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        resultHead = None
        resultHead2 = None
        carry = 0
        while l1 or l2:
            sum = 0
            if l1:
                sum = sum + l1.val
                l1 = l1.next
            
            if l2:
                sum = sum + l2.val
                l2 = l2.next
            total = sum + carry
            carry = total // 10
            
            num = total % 10
            #print(num)
            if resultHead is None:
                resultHead = ListNode(num, None)
                resultHead2 = resultHead
            else:
                resultHead.next = ListNode(num, None)
                resultHead = resultHead.next
        if carry > 0 :
            resultHead.next = ListNode(carry, None)
            resultHead = resultHead.next
        return resultHead2
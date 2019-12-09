# Definition for singly-linked list.
 class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    def addTwoNumbers(self,l1,l2):
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        dummy=ListNode(-1)
        cur=dummy
        carry=0
        while l1 or l2 or carry:
            res=carry
            if l1:
                res=res+l1.val
                l1=l1.next
            if l2:
                res=res+l2.val
                l2=l2.next
            cur.next=ListNode(res%10)
            carry=res//10
            cur=cur.next
        return dummy.next


l1=ListNode(2)
l1.next=ListNode(4)
l1.next.next=ListNode(3)

l2=ListNode(5)
l2.next=ListNode(6)
l2.next.next=ListNode(4)

res=Solution()

l3=res.addTwoNumbers(l1,l2)

while l3:
    print(l3.val)
    l3=l3.next

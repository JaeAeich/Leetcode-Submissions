# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(head is None or head.next is None) :
            return head
        slow,fast=head,head.next.next
        
        while (fast is not None and fast.next is not None):
            if slow:
                slow =slow.next
            if fast.next:
                fast =fast.next.next
        return slow.next
        
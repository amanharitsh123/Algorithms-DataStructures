# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        slow=head
        fast=head
        while True and slow and fast:
            slow=slow.next
            if not fast.next:
                break
            fast=fast.next.next
            if slow==fast:
                return True
        return False

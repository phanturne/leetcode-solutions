# Leetcode #876: https://leetcode.com/problems/middle-of-the-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# Solution 1 (Fast & Slow Pointer) | O(n) time, O(1) space
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize 2 pointers to the start of the list
        slow, fast = head, head

        # Use a fast and slow pointer to traverse the list. 
        while fast and fast.next:
            # The fast pointer moves twice while the slow pointer moves once
            fast = fast.next.next
            slow = slow.next

        # When the fast pointer reaches the end, the slow pointer will be at the middle of the list
        return slow

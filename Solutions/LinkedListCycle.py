# Leetcode #141: https://leetcode.com/problems/linked-list-cycle/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Solution 1 (2 Pointers) | O(n) time, O(1) space
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # Create a fast and slow pointer to track position in the list
        fast, slow = head, head

        # Move the fast pointer twice and slow pointer once. If they collide, there must be a cycle
        while (fast and fast.next):
            fast = fast.next.next
            slow = slow.next

            if fast == slow:
                return True

        # Otherwise, there can't be a cycle
        return False

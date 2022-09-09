# Leetcode #141: https://leetcode.com/problems/linked-list-cycle/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Solution 1 | O(n) time, O(1) space
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # Empty linked list has no cycle
        if head is None:
            return False
        
        # Initialize a fast and slow pointer
        fast = slow = head
        
        # While the next nodes are valid:
        while fast and fast.next:
            # Move fast pointer twice and slow pointer once
            fast = fast.next.next
            slow = slow.next
            
            # If the pointers collided, there must be a cycle
            if fast == slow:
                return True
            
        return False # Otherwise there is no cycle

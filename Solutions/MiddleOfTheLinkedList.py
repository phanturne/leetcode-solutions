# Leetcode #876: https://leetcode.com/problems/middle-of-the-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# Solution 1 (Fast & Slow Pointer) | O(n) time, O(1) space
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Traverse the list with a fast and slow pointer
        slow, fast = head, head
        
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        # After exiting the loop, the slow pointer will be at the middle node
        return slow

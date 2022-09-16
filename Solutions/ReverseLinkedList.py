# Leetcode #206: https://leetcode.com/problems/reverse-linked-list/
# Source: https://leetcode.com/problems/reverse-linked-list/discuss/803955/C%2B%2B-Iterative-vs.-Recursive-Solutions-Compared-and-Explained-~99-Time-~85-Space
# Source: https://leetcode.com/problems/reverse-linked-list/discuss/58127/Python-Iterative-and-Recursive-Solution

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# Solution 1 (3 Pointers) | O(n) time, O(1) space
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Using 3 pointers, set each node's next to its previous one 
        prev = None
        while head:
            next = head.next    # Store next node
            head.next = prev    # Reverse current node
            prev = head         # Update previous node
            head = next         # Update current node
            
        return prev
      
      
# Solution 2 (Recursive) | O(n) time, O(1) space
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.reverseHelper(head)
        
    def reverseHelper(self, head, prev = None):
        if head is None:
            return prev                           # prev stores the last node in the list
        
        next = head.next                          # Store next node
        head.next = prev                          # Reverse current node
        return self.reverseHelper(next, head)     # Recursively reverse the next nodes

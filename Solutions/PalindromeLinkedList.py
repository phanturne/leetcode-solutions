# LC #234: https://leetcode.com/problems/palindrome-linked-list/
# Source: https://leetcode.com/problems/palindrome-linked-list/discuss/1137027/JS-Python-Java-C%2B%2B-or-Easy-Floyd's-%2B-Reversal-Solution-w-Explanation

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# Solution 1 (2 Pointers, Reverse Half the List) | O(n) time, O(1) space
# Can also add a step to revert the second half of the list during the comparisons
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        fast, slow = head, head
        
        # When fast reaches the end, slow will be in the middle
        while fast and fast.next:
            fast, slow = fast.next.next, slow.next
            
        # Reverse the second half of the list
        prev, curr, prev.next = slow, slow.next, None
        while curr:
            curr.next, prev, curr = prev, curr, curr.next
            
        # Compare the first half with the reversed second half
        # Stop when head2 is null. Works with odd and even length lists
        # Even: 1 -> 2 -> 2 <- 1  |  Odd: 1 -> 2 <- 1
        head1, head2 = head, prev
        while head2:
            if head1.val != head2.val:
                return False
            head1, head2 = head1.next, head2.next
        
        # After the comparisons, the list must be a palindrome
        return True

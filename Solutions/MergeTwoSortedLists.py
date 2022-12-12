#Leetcode #21: https://leetcode.com/problems/merge-two-sorted-lists/description/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# Solution 1 (While Loop) | O(n) time, O(1) space
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # Create a new list and store a pointer to its head
        list3 = dummy = ListNode()

        # Loop until a list becomes empty. Add the smaller node to the new list and advance pointer of list3 and the list w/ the smaller node
        while list1 and list2:
            if list1.val <= list2.val:
                list3.next, list1 = list1, list1.next
            else:
                list3.next, list2 = list2, list2.next

            list3 = list3.next

        # One of the lists could be nonempty. If so, add the remaining nodes to the new list
        list3.next = list1 if list1 else list2
        return dummy.next

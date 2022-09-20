# LC #101: https://leetcode.com/problems/symmetric-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Solution 1 (Recursive) | O(n) time, O(n) space
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def symmetric(n1, n2):
            if not n1 and not n2:
                # If both nodes are null, it is symmetric
                return True
            elif not n1 or not n2 or n1.val != n2.val:
                # If only one is null or if they have different values, it's not
                return False
            
            # Recursively check if n1's left subtree matches n2's righ subtree and vice versa
            return symmetric(n1.left, n2.right) and symmetric(n1.right, n2.left)
        
        return symmetric(root.left, root.right)
    

# Leetcode #543: https://leetcode.com/problems/diameter-of-binary-tree/
# Source: https://leetcode.com/problems/diameter-of-binary-tree/discuss/101145/Simple-Python

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Solution 1 (Recursive) | O(n) time, O(n) space <- if unbalanced binary tree, call stack will have n items, else O(logn)
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.diameter = 0
        
        # Inner function that returns the depth of the tree and updates the diameter along the way
        def depth(node):
            if node is None: return 0
            
            # Recursively calculate depth of left and right subtrees
            left, right = depth(node.left), depth(node.right)
            
            # Diameter is max(diameter, max depth of left + right subtrees)
            self.diameter = max(self.diameter, left + right)
            
            # Return depth of the tree
            return max(left, right) + 1
        
        
        depth(root)
        return self.diameter

# Leetcode #110: https://leetcode.com/problems/balanced-binary-tree/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Solution 1 (DFS Recursive) | O(n) time, O(
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        # Helper function that returns the depth of a tree or -1 if it is unbalanced
        def depth(root):
            # If the root is NULL, the depth is 0
            if not root:
                return 0

            # Recursively find the depth of the left and right subtrees
            leftDepth, rightDepth = depth(root.left), depth(root.right)

            # If either subtree or the current tree is not height-balanced, return -1. Else, return the depth
            if leftDepth == -1 or rightDepth == -1 or abs(leftDepth - rightDepth) > 1:
                return - 1
            else:
                return max(leftDepth, rightDepth) + 1

        return depth(root) != -1

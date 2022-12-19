# LC #104: https://leetcode.com/problems/maximum-depth-of-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Solution 1 (Recursive) | O(n) time, O(n) space
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # Depth of an empty tree is 0
        if not root: 
            return 0

        # Max depth is the greater depth of its subtrees + 1
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

# Leetcode #226: https://leetcode.com/problems/invert-binary-tree/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Solution 1 (Recursive) | O(n) time, O(h) space  <- h is height of the tree
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # Base case: root is null
        if root is None: 
            return root

        # Recursively swap the left and right halves of the tree
        root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)

        return root

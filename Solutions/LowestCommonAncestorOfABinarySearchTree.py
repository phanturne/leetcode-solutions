# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Solution 1 | O(logn) time, O(1) space
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Get the smaller and larger values of p and q
        smallerVal, biggerVal = sorted([p.val, q.val])

        # Starting from the root node, search for LCA(p, q)
        # LCA(p, q) must have a value between p and q
        while (not smallerVal <= root.val <= biggerVal):
            # If root.val is too big, both p and q are on the right side. Vice versa
            root = root.left if root.val > smallerVal else root.right

        return root

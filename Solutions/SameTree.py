# LC #100: https://leetcode.com/problems/same-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Solution 1 (Recursive) | O(n) time, O(n) space  <- Call stack can have up to n nodes if the tree is unbalanced
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q: 
            # If both nodes don't exist, they're the same (sub)tree
            return True
        elif not p or not q or p.val != q.val: 
            # If only one node DNE or they have different values, they can't be the same (sub)tree
            return False
        
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

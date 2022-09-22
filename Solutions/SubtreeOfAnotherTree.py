# LC #572: https://leetcode.com/problems/subtree-of-another-tree/
# Source: https://leetcode.com/problems/subtree-of-another-tree/discuss/102741/Python-Straightforward-with-Explanation-(O(ST)-and-O(S%2BT)-approaches)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Solution 1 (Recursive) | O(n * m) time, O(n) space  <- n nodes in tree1, m nodes in tree2
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        # Helper function that checks if 2 subtrees are the same
        def isSame(tree1, tree2):
            if not tree1 and not tree2:
                # If the roots are both null, they match.
                return True 
            elif not tree1 or not tree2 or tree1.val != tree2.val:
                # If only one node is null or they have different values, they don't match
                return False 
            
            # Recursively check if the subtrees match
            return isSame(tree1.left, tree2.left) and isSame(tree1.right, tree2.right)
        
        if not root:
            return False # Empty tree can't match the subtree
        
        # Check if the tree starting at root matches the subRoot tree
        if isSame(root, subRoot):
            return True
        
        # If the current tree doesn't match, check if the tree starting at its children match
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
      
  # Solution 2 (Merkle Hashing) | O(n + m) time, O(n + m) space?

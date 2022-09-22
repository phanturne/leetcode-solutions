# LC #108: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Solution 1 (Recursive) | O(n) time, O(logn) space
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        # Helper function to insert the correct element into the tree
        def helper(left, right):
            if left > right:
                return  # No more elements left
            
            # Set the node to the middle element so the BST will be height-balanced
            mid = (left + right) // 2
            node = TreeNode(nums[mid])
            
            # Recursively add the child nodes
            node.left = helper(left, mid - 1)
            node.right = helper(mid + 1, right)
            
            return node
        
        # Call the helper function w/ the first and last indices and return the root of the BST
        return helper(0, len(nums) - 1)

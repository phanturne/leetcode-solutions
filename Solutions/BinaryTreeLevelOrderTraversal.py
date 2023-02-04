# Leetcode #102:
# Source: https://leetcode.com/problems/binary-tree-level-order-traversal/solutions/33464/5-6-lines-fast-python-solution-48-ms/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Solution 1 (BFS | O(n) time, O(n) space
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # Edge case: if the root is None, return the empty list
        if not root:
            return []

        # Store the answer
        ans = []

        # Store the current level of nodes
        level = [root]

        # While the level is not empty
        while level:
            # Initalize lists to store the current and next level values
            currentLevel, nextLevel = [], []

            # Loop through all nodes in the current level
            for node in level:
                # Add the current node value to the current level
                currentLevel.append(node.val)

                # Add the left and right children to the next level, if they exist
                if node.left:
                    nextLevel.append(node.left)
                if node.right:
                    nextLevel.append(node.right)
            
            # Add the current level values to the result list
            ans.append(currentLevel)
            
            # Set the next level as the current level for the next iteration
            level = nextLevel

        return ans

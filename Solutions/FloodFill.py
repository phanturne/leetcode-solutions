# Leetcode #733: https://leetcode.com/problems/flood-fill/description/
# Source: https://leetcode.com/problems/flood-fill/solutions/109604/easy-python-dfs-no-need-for-visited/?orderBy=most_votes

# Solution 1 (Recursive DFS) | O(n) time, O(n) space
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        # Helper function that recursively flood fills using dfs
        def dfs(row, col):
            # Check if row and col are valid, and if its color is same as starting cell's color
            if (0 <= row < rows and 0 <= col < cols) and image[row][col] == startColor:
                # Change the current cell's color
                image[row][col] = color

                # Recursively flood fill its neighboring cells
                # [dfs(row + x, col + y) for (x, y) in ((0, 1), (1, 0), (0, -1), (-1, 0))]  # alternative to code below
                dfs(row - 1, col)
                dfs(row + 1, col)
                dfs(row, col - 1)
                dfs(row, col + 1)

        rows, cols, startColor = len(image), len(image[0]), image[sr][sc]

        # If the starting pixel's color isn't the same as target color, call the helper function
        if startColor != color:
            dfs(sr, sc)

        return image

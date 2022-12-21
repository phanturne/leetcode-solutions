# Leetcode #542: https://leetcode.com/problems/01-matrix/
# Source: https://leetcode.com/problems/01-matrix/discuss/1369741/C%2B%2BJavaPython-BFS-DP-solutions-with-Picture-Clean-and-Concise-O(1)-Space

# Solution 1 (BFS) | O(M * N) time, O(M * N) space for queue    <- M = num rows, N = num cols
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows, cols = len(mat), len(mat[0])
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # Directional matrix for neighboring cells
        queue = deque([])  # Queue for BFS

        # Traverse the matrix, adding 0-cells to the queue and setting value for 1-cells to -1
        for r in range(rows):
            for c in range(cols):
                if mat[r][c] == 0:
                    queue.append((r, c))
                else:
                    mat[r][c] = -1
        
        # While the queue is nonempty, pop from the queue and update distances of neighboring cells
        while queue:
            r, c = queue.popleft()

            # If any neighboring cells exist and haven't been updated, calculate their distance and add to queue
            for (x, y) in dirs:
                nr, nc = r + x, c + y

                if nr < 0 or nr == rows or nc < 0 or nc == cols or mat[nr][nc] != -1:
                    continue

                # The neighboring cell's distance is 1 more than the current cell's
                mat[nr][nc] = mat[r][c] + 1
                queue.append((nr, nc))

        return mat
      
# Solution 2 (DP) | O(M * N) time, O(1) space
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows, cols = len(mat), len(mat[0])
        
        # Loop through each cell from top to bottom and left to right
        # Set the cell's value to 1 + min distance of its left and top neighbors if it's not a 0-cell
        for r in range(rows):
            for c in range(cols):
                if mat[r][c] == 0: continue
                top = mat[r - 1][c] if r > 0 else math.inf
                left = mat[r][c - 1] if c > 0 else math.inf
                mat[r][c] = min(top, left) + 1
            
        # Loop through each cell from bottom to top and right to left
        # Set each cell's value to 1 + min distance of its right and bottom neighbors if it's not a 0-cell
        for r in range(rows - 1, -1, -1):
            for c in range(cols - 1, -1, -1):
                if mat[r][c] == 0: continue
                bottom = mat[r + 1][c] if r < rows -1 else math.inf
                right = mat[r][c + 1] if c < cols - 1 else math.inf
                mat[r][c] = min(mat[r][c], bottom + 1, right + 1)
                
        return mat # Return the distance matrix

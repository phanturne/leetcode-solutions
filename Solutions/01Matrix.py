# Leetcode #542: https://leetcode.com/problems/01-matrix/
# Source: https://leetcode.com/problems/01-matrix/discuss/1369741/C%2B%2BJavaPython-BFS-DP-solutions-with-Picture-Clean-and-Concise-O(1)-Space

# Solution 1 (BFS) | O(M * N) time, O(M * N) space for queue  <- M = num rows, N = nums columns
# Process the cells with smaller distances first, then expand to unprocessed neighbors of the current cell
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows, cols = len(mat), len(mat[0])
        DIR = [1, 0, -1, 0, 1] # Stores the offset of the neighbors
        
        q = deque([]) # Create a queue
        
        # Loop through each row
        for r in range(rows):
            # Loop through each column
            for c in range(cols):
                if mat[r][c] == 0:
                    # If the value of the cell is 0, add it to the queue
                    q.append((r, c))
                else:
                    # Else set its value as -1 to mark it as unvisited
                    mat[r][c] = -1
                
        # While the queue is nonempty
        while q:
            # Pop the next element and calculate the distance of its neighbors
            r, c = q.popleft()
            for i in range(4):
                nr, nc = r + DIR[i], c + DIR[i + 1]
                # Check if neighbor exists and its distance hasn't been calculated
                if nr < 0 or nr == rows or nc < 0 or nc == cols or mat[nr][nc] != -1:
                    continue
                # Else we found the shortest distance for this cell. Add it to the queue
                mat[nr][nc] = mat[r][c] + 1
                q.append((nr, nc))
            
            
        return mat # Return the distance matrix
      
# Solution 2 (DP) | O(M * N) time, O(1) space
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows, cols = len(mat), len(mat[0])
        
        # Loop through each cell from top to bottom and left to right
        for r in range(rows):
            for c in range(cols):
                # Set the cell's value to 1 + min distance of its left and top neighbors if it's not 0
                if mat[r][c] == 0: continue
                top = mat[r - 1][c] if r > 0 else math.inf
                left = mat[r][c - 1] if c > 0 else math.inf
                mat[r][c] = min(top, left) + 1
            
        # Loop through each cell from bottom to top and right to left
            # Set each cell's value to 1 + min distance of its right and bottom neighbors if it's not 0
        for r in range(rows - 1, -1, -1):
            for c in range(cols - 1, -1, -1):
                if mat[r][c] == 0: continue
                bottom = mat[r + 1][c] if r < rows -1 else math.inf
                right = mat[r][c + 1] if c < cols - 1 else math.inf
                mat[r][c] = min(mat[r][c], bottom + 1, right + 1)
                
        return mat # Return the distance matrix

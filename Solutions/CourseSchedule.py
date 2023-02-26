# Leetcode #207: https://leetcode.com/problems/course-schedule/description/
# Source: https://leetcode.com/problems/course-schedule/solutions/58586/python-20-lines-dfs-solution-sharing-with-explanation/

# Solution 1 (DFS - Topological Sort) | O(V + E) time , O(V + E) psace
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Create graph
        graph = [[] for _ in range(numCourses)]
        for x, y in prerequisites:
            graph[x].append(y)

        # Keep track of courses taken (0 = not taken, -1 = trying to take, 1 = already taken)
        visited = [0 for _ in range(numCourses)]

        # Define a recursive function to perform DFS on the graph
        def dfs(i):
            # If the ith node is being isited, there is a cycle
            if visited[i] == -1:
                return False

            # If the ith node is completed, there is no cycle there
            if visited[i] == 1:
                return True

            # Mark the node as being visited
            visited[i] = -1

            # Visit all the node's neighbors
            for neighbor in graph[i]:
                if not dfs(neighbor):
                    return False

            # After all the neighbors has been visited, mark the node as completed
            visited[i] = 1
            return True

        # Perform DFS on every course in the graph
        for i in range(numCourses):
            # Return false if there is a cycle
            if not dfs(i):
                return False

        # If no cycles are detected, return true
        return True

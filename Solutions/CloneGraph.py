# Leetcode #133: https://leetcode.com/problems/clone-graph/description/
# Source: https://leetcode.com/problems/clone-graph/solutions/1792858/python3-iterative-bfs-beats-98-explained/

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

# Solution 1 (BFS) 
# Time: O(V + E) for BFS
# Space: O(V) for hashmap
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        # Return None if the node is None
        if not node:
            return node

        # Queue to store the nodes for BFS 
        queue = deque([node])  

        # Dictionary to store the node clones
        clones = { node.val: Node(node.val, []) }

        # While the queue is nonempty
        while queue:
            # Pop the node at the front of the queue and get its clone
            currNode = queue.popleft()
            currClone = clones[currNode.val]

            # Traverse the node's neighbors
            for neighbor in currNode.neighbors:
                # Clone the nieghbor and add it to the queue if it has not been cloned yet
                if neighbor.val not in clones:
                    clones[neighbor.val] = Node(neighbor.val, [])
                    queue.append(neighbor)

                # Add the neighbor to the current node
                currClone.neighbors.append(clones[neighbor.val])

        # Return clone of the input node
        return clones[node.val]

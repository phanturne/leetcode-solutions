# Leetcode #973: https://leetcode.com/problems/k-closest-points-to-origin/description/
# Source: https://leetcode.com/problems/k-closest-points-to-origin/solutions/294389/easy-to-read-python-min-heap-solution-beat-99-python-solutions/?orderBy=most_votes

# Solution 1 (Using Python's MinHeap as MaxHeap) | O(nlogk) time, O(k) space
import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # Initialize a min heap that'll serve as a max heap by pushing negative values
        maxHeap = []

        # For each point, calculate its distance from the origin and push to the maxHeap
        for (x, y) in points:
            dist = -((x * x) + (y * y))     # Multiply by -1 so the bigger the distance, the smaller its value

            # If the heap is full, push the distance and pop the farthest point. Else, just push the distance
            if len(maxHeap) == k:
                heapq.heappushpop(maxHeap, (dist, x, y))
            else:
                heapq.heappush(maxHeap, (dist, x, y))
            
        return [(x, y) for (dist, x, y) in maxHeap]
            

# LC #57: https://leetcode.com/problems/insert-interval/
# Source: https://leetcode.com/problems/insert-interval/discuss/21602/Short-and-straight-forward-Java-solution
# Source: https://leetcode.com/problems/insert-interval/discuss/21622/7%2B-lines-3-easy-solutions

# Solution 1 | O(n) time, O(n) space <- slicing list
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        s, e = newInterval[0], newInterval[1]
        
        left = [i for i in intervals if i[1] < s] # Intervals strictly before newInterval
        right = [i for i in intervals if i[0] > e] # Intervals strictly after newInterval

        # If the combined lengths of the 2 slices != the original length, calculate the merged interval
        if len(left) + len(right) != len(intervals):
            # start is min of s and the start of the interval strictly after left slice
            s = min(s, intervals[len(left)][0])
            
            # end is max of e and the end of the interval strictly before right slice
            e = max(e, intervals[len(intervals) - len(right) - 1][1])
            
        # Return the 3 intervals combined together
        return left + [[s, e]] + right

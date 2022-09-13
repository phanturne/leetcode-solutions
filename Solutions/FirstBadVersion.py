# Leetcode #278: https://leetcode.com/problems/first-bad-version/
# Source: https://leetcode.com/problems/first-bad-version/discuss/769685/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.

# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

# Solution 1 (Binary Search) | O(logn) time, O(1) space
class Solution:
    def firstBadVersion(self, n: int) -> int:
        # Initialize the search range
        left, right = 1, n
        firstBad = -1
        
        # While there are still elements to search
        while (left < right):
            mid = (left + right) // 2
            
            if isBadVersion(mid):
                # If the middle is bad, check the left half to see if there's an earlier bad version
                firstBad = mid
                right = mid
            else:
                # Else look in the right half 
                left = mid + 1
        
        return right

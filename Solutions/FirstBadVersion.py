# Leetcode #278: https://leetcode.com/problems/first-bad-version/
# Source: https://leetcode.com/problems/first-bad-version/discuss/769685/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.

# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

# Solution 1 (Binary Search) | O(logn) time, O(1) space
class Solution:
    def firstBadVersion(self, n: int) -> int:
        # Initialize the search range
        left, right = 1, n
        
        # While the search range includes more than 1 element, use binary search 
        while (left < right):
            mid = (left + right) // 2
            
            # If mid is bad, remove right half from search range (b/c they can't be the first bad version). Else, remove left half.
            if isBadVersion(mid):
                right = mid
            else:
                left = mid + 1
        
        return right    # left and right will have same value, so we can return either

    # Solution 2 (Vanilla Binary Search w/ Boundary Index) | O(logn) time, O(1) space
    class Solution:
    def firstBadVersion(self, n: int) -> int:
        # Initialize the search range
        left, right = 1, n
        
        # Initialize the boundary index to -1, in case there are no bad versions
        boundary_index = -1
        
        # Use binary search to find the first bad version
        while (left <= right):
            # Calculate the mid-point of the search range
            mid = (left + right) // 2
            
            # If the mid-point version is bad, it means the first bad version could be either at the mid-point or to its left. 
            if isBadVersion(mid):
                boundary_index = mid
                right = mid - 1
            
            # If the mid-point version is not bad, it means the first bad version must be to the right of the mid-point. 
            else:
                left = mid + 1
        
        # Return the boundary index, which is the first bad version found during the search
        return boundary_index

# Leetcode #704: https://leetcode.com/problems/binary-search/description/

# Solution 1 | O(logn) time, O(1) space
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # Left and right pointers denote the search range
        left, right = 0, len(nums) - 1

        # While the search range is non-empty, find the middle index and check if its the target
        # If nums[mid] is too small, discard the left half. If its too big, discard the right half
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        # Target not found, return -1
        return -1

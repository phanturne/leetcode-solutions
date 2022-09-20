# LC #283: https://leetcode.com/problems/move-zeroes/
# Source: https://leetcode.com/problems/move-zeroes/solution/

# Solution 1 (Optimal) | O(n) time, O(1) space
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nextIndex = 0   # Index of the next 0, which we will swap w/ the next nonzero number
        
        # Loop through the list and swap the nonzero values with the zeroes
        # Invariant: All elements before nextIndex are nonzero. All elements between nextIndex and i are 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[nextIndex], nums[i] = nums[i], nums[nextIndex]
                nextIndex += 1
                


# Solution 2 (Space-Optimal, Operation Sub-Optimal) | O(n) time, O(1) space
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nextIndex = 0   # Index to place the next nonzero number
        
        # Loop through the list and move nonzero numbers to the 
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[nextIndex] = nums[i]
                nextIndex += 1
            
        # All the non-zero elements are at the beginning of the list. Fill the remaining elements with 0's
        for i in range(nextIndex, len(nums)):
            nums[i] = 0
                
# Solution 3 (Space & Time Sub-Optimal) | O(n) time, O(n) space
# Count number of 0's in the list
# Create new list with only the nonzero elements
# Append 0's to the end of our new list
# Copy the new list into the original list

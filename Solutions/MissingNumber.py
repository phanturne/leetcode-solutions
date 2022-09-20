# LC #268: https://leetcode.com/problems/missing-number/
# Source: https://leetcode.com/problems/missing-number/discuss/69786/3-different-ideas%3A-XOR-SUM-Binary-Search.-Java-code

# Solution 1 (XOR) | O(n) time, O(1) space
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        ans = len(nums) # Initialize w/ last number to avoid out-of-bounds error when accessing the index in the for loop
        
        # Loop through the list and XOR with all the numbers and indices
        for i in range(len(nums)):
            ans ^= i
            ans ^= nums[i]
            
        # We XOR all numbers twice, except the missing number. All other numbers cancel out
        return ans
      
# Solution 2 (Sum) | O(n) time, O(1) space
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # Sum of numbers from 0 to n is n(n + 1) // 2
        actualSum = len(nums) * (len(nums) + 1) // 2
        
        return actualSum - sum(nums)

# Solution 3 (Binary Search) | O(nlogn) time, O(1) space
# Sort the array and use binary search to find the last element where nums[mid] > mid

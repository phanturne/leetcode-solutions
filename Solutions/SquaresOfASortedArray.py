# LC #977:
# Source: https://leetcode.com/problems/squares-of-a-sorted-array/discuss/495394/C%2B%2B%3A-Simplest-one-pass-two-pointers

# Solution 1 (Two Pointers) | O(n) time, O(n) space
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        # Disregarding negatives, the array is sorted from the middle to outside on both sides
        # Use two pointers to track indices of candidates for the next largest element
        l, r = 0, len(nums) - 1
        ans = [0] * len(nums)
        
        # Fill in the new array from right to left (i.e. biggest to smallest)
        for i in range(len(nums) -1, -1, -1):
            # Choose the bigger of the abs() of the 2 values as the next element
            if abs(nums[l]) > abs(nums[r]):
                ans[i] = nums[l] * nums[l]
                l += 1
            else:
                ans[i] = nums[r] * nums[r]
                r -= 1
                
        return ans

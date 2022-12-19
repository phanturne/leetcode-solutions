# LC #53: https://leetcode.com/problems/maximum-subarray/
# Source: https://leetcode.com/problems/maximum-subarray/discuss/1595195/C%2B%2BPython-7-Simple-Solutions-w-Explanation-or-Brute-Force-%2B-DP-%2B-Kadane-%2B-Divide-and-Conquer

# Solution 1 (Kadane's Algorithm) | O(n) time, O(1) space
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # Track the currest sum and largest sum seen so far
        currSum, maxSum = 0, nums[0] 
        
        # Use the sliding window approach while traversing the list
        for num in nums:
            # Choose between adding num to currSum or starting fresh w/ only num
            currSum = max(currSum + num, num)
                
            # Update the largest sum seen so far
            maxSum = max(maxSum, currSum)
            
        return maxSum

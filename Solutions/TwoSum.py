# Leetcode #2: https://leetcode.com/problems/two-sum/description/
# Source: https://leetcode.com/problems/two-sum/solutions/127810/two-sum/

# Solution 1: Hash Map | O(n) time, O(n) space
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Create a dictionary to map elements with their indices
        hashMap = {}

        # Loop through the list and check if the complement is in the hash map
        # If yes, return the 2 indices. If no, add current number to the hash map
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashMap:
                return [hashMap[complement], i]
            hashMap[nums[i]] = i

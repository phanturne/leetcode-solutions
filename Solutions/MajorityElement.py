# Leetcode #169: https://leetcode.com/problems/majority-element/
# Source: https://leetcode.com/problems/majority-element/solution/

# Solution 1 (Boyer-Moore Voting Algorithm) | O(n) time, O(1) SPACE
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = None
        count = 0
        
        # Loop through the array
        for val in nums:
            # If count is 0, set the current val as the candidate
            if count == 0:
                candidate = val
                
            # Increment count if we see the candidate, else decrement
            count += (1 if candidate == val else -1)
                
        # Candidate will be the majority element b/c it appears > n/2 times
        return candidate

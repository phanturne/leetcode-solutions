# LC #217: https://leetcode.com/problems/contains-duplicate/

# Solution 1 (Sets) | O(n) time, O(n) space
# Note: Can also add each element to the set one by one and check if it's already in the set
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(nums) > len(set(nums))
      
# Solution 1b (collections.Counter) | O(n) time, O(n) space
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hasDup = sum((val > 1) for val in collections.Counter(nums).values())
        return hasDup
    
# Solution 2 (Brute Force - 2 Loops) | O(n^2) time, O(1) space

# Solution 3 (Sort) | O(nlogn) time, O(1) space

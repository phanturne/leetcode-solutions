# LC #136: https://leetcode.com/problems/single-number/
# Source: https://leetcode.com/problems/single-number/discuss/1771720/C%2B%2B-EASY-SOLUTIONS-(SORTING-XOR-MAPS-(OR-FREQUENCY-ARRAY))

# Solution 1 (XOR) | O(n) time, O(1) space
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        
        # XOR each number to cancel out all pairs (i.e. num1 ^ num1 = 0)
        for num in nums:
            ans ^= num
        return ans
      
# Solution 2 (Set/Hashmap/Dict) | O(n) time, O(n) space

# Solution 3 (Sort) | O(nlogn) time, O(1) space

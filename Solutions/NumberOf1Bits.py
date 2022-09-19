# LC #191: https://leetcode.com/problems/number-of-1-bits/
# Source: https://leetcode.com/problems/number-of-1-bits/discuss/55255/C%2B%2B-Solution%3A-n-and-(n-1)

# Solution 1 (n & (n-1))| O(n) time, O(1) space
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0           # Store the number of set bits
        while n > 0:        # Iterate all bits are traversed
            n &= (n - 1)    # Drop the lowest set bit (1100 & 1011 = 1000)
            count += 1      # Increment count by 1
            
        return count

# Solution 2 (Right shift + Bitwise And) | O(n) time, O(1) space
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0               # Store the number of set bits
        while n > 0:            # Iterate until all bits have been traversed
            if n & 1 == 1:      # Increment count if the bit is set
                count += 1
            n >>= 1          # Right shift by 1 so we can check the next bit
            
        return count

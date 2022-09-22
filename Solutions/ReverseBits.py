# LC #190: https://leetcode.com/problems/reverse-bits/

# Solution 1 | O(1) time, O(1) space
class Solution:
    def reverseBits(self, n: int) -> int:
        rev = 0
        
        # While there are still bits to reverse (binary string is of lenght 32)
        # Note: can't do n > 0 b/c we still need to reverse leading 0 bits
        for i in range(32):
            digit = n & 1               # Get the last bit of n
            rev = (rev << 1) | digit    # Add the bit to the end of rev and remove 
            n >>= 1                      # Remove the last bit from n
            
        return rev

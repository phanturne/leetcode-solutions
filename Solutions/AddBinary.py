# Leetcode #67: https://leetcode.com/problems/add-binary/
# Source: https://leetcode.com/problems/add-binary/discuss/1679423/Well-Detailed-Explaination-Java-C%2B%2B-Python-oror-Easy-for-mind-to-Accept-it

# Solution 1 | O(max(m, n)) time, O(1) space
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # Initialize starting indices
        i, j = len(a) - 1, len(b) - 1
        carry = 0
        result = ''
        
        # Loop through both strings backwards
        while i >= 0 or j >= 0 or carry > 0:
            # Convert the letters to int and add the bits together with the carry
            if i >= 0:
                carry += int(a[i])
                i -= 1
            if j >= 0:
                carry += int(b[j])
                j -= 1
                
            # Add the sum to our string and calculate the next carry
            result += str(carry % 2)
            carry //= 2
        
        # Reverse the string b/c its backwards
        return result[::-1]
      

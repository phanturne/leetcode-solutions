# LC #13: https://leetcode.com/problems/roman-to-integer/

# Solution 1 (Iterate Backwards) | O(n) time, O(1) space
class Solution:
    def romanToInt(self, s: str) -> int:
        dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        
        # Loop through the string backwards and add the value of each character
        # If a smaller symbol is before a bigger one, subtract its value instead
        sum = dict[s[len(s) - 1]]       # Initalize to last symbol
        for i in range(len(s) - 2, -1, -1):
            currVal = dict[s[i]]
            sum += currVal if currVal >= dict[s[i + 1]] else -1 * currVal
            
        return sum

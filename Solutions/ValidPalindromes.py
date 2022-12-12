# Leetcode #125: https://leetcode.com/problems/valid-palindrome/description/

# Solution 1 (2 Pointers) | O(n) time, O(1) space
class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Initialize left and right indices
        left, right = 0, len(s) - 1

        # Iterate through the string and compare alphanumeric chars on the 2 indices
        while left < right:
            # Find the first alphanumeric char on the left and right side
            while not s[left].isalnum() and left < right: left += 1
            while not s[right].isalnum() and left < right: right -= 1

            # If the chars don't match, it is not a palindrome
            if s[left].upper() != s[right].upper():
                return False
            
            # Move the left and right indices
            left, right = left + 1, right - 1
        
        # All alphanumeric chars on the left and right side match, so its a palindrome
        return True

# LC #9: https://leetcode.com/problems/palindrome-number/

# Solution 1 (Revert half the number) | O(n) time, O(1) space
class Solution:
    def isPalindrome(self, x: int) -> bool:
        # A negative number can't be a palindrome
        if x < 0: 
            return False
        
        # Reverse the last half of the number 
        reversedHalf = 0
        while x > reversedHalf:
            # Append the last digit from x and remove it from x
            reversedHalf = reversedHalf * 10 + (x % 10)
            x /= 10
        
        # If length of x is odd, reversedHalf will have an extra digit, so we do reversed / 10 to remove it
        # Since the middle digit doesn't matter in a palindrome, it's ok to just remove it
        return x == reversedHalf or x == reversedHalf / 10
        

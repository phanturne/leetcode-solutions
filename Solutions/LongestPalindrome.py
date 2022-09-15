# Leetcode #409: https://leetcode.com/problems/longest-palindrome/
# Source: https://leetcode.com/problems/longest-palindrome/discuss/89587/What-are-the-odds-(Python-and-C%2B%2B)

# Solution 1 (Count # of Used Letters) | O(n) time, O(1) space
class Solution:
    def longestPalindrome(self, s: str) -> int:
        # Calculate how many letters used in pairs
        used = sum((val // 2) * 2 for val in collections.Counter(s).values())
        
        # If not all letters are used up, add 1 for the single letter in the center of the palindrome
        return min(len(s), used + 1)
    
# Solution 2 (Subtract # of Unused Letters) | O(n) time, O(1) space
class Solution:
    def longestPalindrome(self, s: str) -> int:
        # Calculate how many letters that appear an odd # of times
        odds = sum((val % 2 == 1) for val in collections.Counter(s).values())

        # len(s) - odds = # of paired letters. If there are unpaired letters, use 1 as the center of the palindrome
        return len(s) - odds + bool(odds)
        

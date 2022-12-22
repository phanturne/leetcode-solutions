# Leetcode #3: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
# Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/127839/longest-substring-without-repeating-characters/

# Solution 1 (Sliding Window w/ Map) | O(n) time, O(1) space
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        map = {}    # Create a map of symbols to their most recent index
        longestLength = 0

        # Traverse the string and use a sliding window to keep track of the substring
        l = 0
        for r in range(len(s)):
            # If s[r] has a duplicate in the range, shift the window to after the 1st occurrence
            if s[r] in map:
                l = max(map[s[r]], l)

            # Calculate the longest substring length and update the map
            longestLength = max(longestLength, r - l + 1)
            map[s[r]] = r + 1

        return longestLength

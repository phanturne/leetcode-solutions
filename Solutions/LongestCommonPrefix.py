# LC #14: https://leetcode.com/problems/longest-common-prefix/
# Source: https://leetcode.com/problems/longest-common-prefix/solution/

# Solution 1 (Vertical Scanning) | O(S) time, O(1) space  <- S is sum of all chars in all strings
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # LCP is the empty string if the array is empty
        if not strs:
            return ""
        
        # Loop through chars of the first string
        for i in range(len(strs[0])):
            # Loop through each string of the array
            for word in strs:
                # If any prefix does not match, return the LCP
                if i >= len(word) or word[i] != strs[0][i]:
                    return strs[0][0:i]
        
        # If we reach here, the whole first word is a prefix for all the other words
        return strs[0]
      
# Solution 2 (Horizontal Scanning) | O(S) time, O(1) space

# Solution 3 (Divide & Conquer) | O(S) time, O(m * logn) space  <- n strings, m is maxLen(all strings)

# Solution 4 (Binary Search) | O(S * logm) time, O(1) space

# LC #844: https://leetcode.com/problems/backspace-string-compare/
# Source: https://leetcode.com/problems/backspace-string-compare/solution/

# Solution 1 (Two Pointers)
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        # Processes '#' and returns the next char of the string
        def nextChar(str: str, index: int):
            backspaceCount = 0
            char = ''
            
            # Loop until we find the next character
            while index >= 0 and not char:
                if str[index] == '#':
                    backspaceCount += 1     # Another backspace appeared
                elif backspaceCount > 0:
                    backspaceCount -= 1     # Use a backspace to skip the char
                else:
                    char = str[index]       # All backspaces processed, get next char
                index -= 1
            return index, char

        # Loop through both strings backwards and compare characters
        i, j = len(s) - 1, len(t) - 1
        while i >= 0 or j >= 0:
            i, char1 = nextChar(s, i)
            j, char2 = nextChar(t, j)
            if char1 != char2:
                return False
        
        return True

# Solution 2 (Stack) | O(m + n) time, O(m + n) space
# Use a stack to build each string (push letter if not '#' else pop). Then check if the 2 strings are equal

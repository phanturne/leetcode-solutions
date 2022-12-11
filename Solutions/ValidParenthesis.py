# Leetcode #20: https://leetcode.com/problems/valid-parentheses/description/
# Source: https://leetcode.com/problems/valid-parentheses/solutions/9203/simple-python-solution-with-stack/?orderBy=most_votes

# Solution 1 (Stack) | O(n) time, O(n) space
class Solution:
    def isValid(self, s: str) -> bool:
        # Create a stack to hold brackets in order an a dict to map matching brackets
        stack = []
        dict = {"(" : ")", "{" : "}", "[" : "]"}

        # Loop through the string. Push open brackets and pop on closed brackess.
        # When popping, if stack is empty or brackets don't match, return false
        for bracket in s:
            if bracket in dict:
                stack.append(bracket)
            elif stack == [] or dict[stack.pop()] != bracket:
                return False

        # If stack is empty at the end, all brackets were matched
        return stack == []

# Leetcode #150: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
# Source: https://leetcode.com/problems/evaluate-reverse-polish-notation/solutions/47444/python-easy-to-understand-solution/

# Solution 1 (Stack) | O(n) time, O(n) space
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # Create a stack to store the operands
        stack = []

        # Iterate through the tokens 
        for token in tokens:
            # Add numbers to the stack (they're the operands)
            if token not in ["+", "-", "*", "/"]:
                stack.append(int(token))

            # If the token is an operator, perform the corresponding operation and push the result
            else:
                num2 = stack.pop()
                num1 = stack.pop()

                if token == "+":
                    stack.append(num1 + num2)
                elif token == "-":
                    stack.append(num1 - num2)
                elif token == "*":
                    stack.append(num1 * num2)
                elif token == "/":
                    stack.append(int(num1 / num2))

        # Return the file result
        return stack[0]

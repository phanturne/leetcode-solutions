// Leetcode Problem #20:
// Source: https://leetcode.com/problems/valid-parentheses/discuss/9178/Short-java-solution

// Solution 1: Stack | O(n) time, O(n) space
class Solution {
public:
    bool isValid(string s) {
        // Stack to keep track of order of brackets
        stack<char> stack;
        
        // Loop through the string
        for (char c : s) {
            // If it is an open bracket, push it on the stack
            if (c == '(') {
                stack.push(')');
            } else if (c == '{') {
                stack.push('}');
            } else if (c == '[') {
                stack.push(']');
            } else if (stack.empty() || stack.top() != c) {
                // If it is a closing bracket, return false if there is no match or if the stack is empty
                return false;
            } else {
                // Otherwise the brackets match, so just pop from the stack
                stack.pop();
            }
        }
        
        // If the stack is empty, all the brackets have been matched
        return stack.empty(); 
    }
};

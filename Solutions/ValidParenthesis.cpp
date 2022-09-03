// Leetcode Problem #20:
// Source: https://leetcode.com/problems/valid-parentheses/discuss/9178/Short-java-solution

// Solution 1: Stack | O(n) time, O(n) space
class Solution {
public:
    bool isValid(string s) {
        // Create a stack to track the order of the brackets
        stack<char> stack;
        
        // Create a map from open to closing brackets
        unordered_map<char, char> map = { {'(', ')'}, {'{', '}'}, {'[', ']'}};
        
        // Loop through the string
        for (char c : s) {
            // If it is an open bracket, push the corresponding closing bracket onto the stack
            if (c == '(' || c == '{' || c == '[') stack.push(map[c]);
            
            // If it is a closing bracket, return false if it doesn't match or if the stack is empty
            else if (stack.empty() || stack.top() != c) return false;
                
            // Otherwise the brackets match, so just pop from the stack
            else stack.pop();
        }
        
        // If stack is empty, all the brackets were matched
        return stack.empty();
    }
};

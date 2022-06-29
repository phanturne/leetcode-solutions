// Leetcode Problem #8: https://leetcode.com/problems/string-to-integer-atoi/
 // Source: https://leetcode.com/problems/string-to-integer-atoi/solution/

// Solution 1: Follow the Rules | O(n) time, O(1) space
class Solution {
public:
    int myAtoi(string s) {
        int result = 0, index = 0, sign = 1, n = s.length();

        // Read and ignore leading whitespace
        while (index < n && s[index] == ' ') index++;

        // Check if the next char is "-" or "+" and update the sign
        if (index < n && s[index] == '-' || s[index] == '+') {
            sign = (s[index] == '-') ? -1 : 1;
            index++;
        }

        // Read in the next chars until the next non-digit char is reached.
        while (index < n && isdigit(s[index])) {
            int digit = s[index++] - '0';

            // Check for overflow and underflow. 
            if (result > INT_MAX / 10 || result == INT_MAX / 10 && digit > INT_MAX % 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            // Add the digit to the end of our int. Leading 0s are ignored because 0 * 10 + 0 = 0
            result = result * 10 + digit;
        }

        // The number did not overflow/underflow. Return it after multiplying its sign.
        return sign * result;
    }
};

// Solution 2: Deterministic Finite Automaton | O(n) time, O(1) space

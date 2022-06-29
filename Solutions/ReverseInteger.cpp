// Leetcode Problem #7: https://leetcode.com/problems/reverse-integer/
// Source: https://leetcode.com/problems/reverse-integer/solution/

// Solution 1: Pop and Push Digits & Check before Overflow | O(log(x)) time and O(1) space
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        
        // While the original int is nonzero
        while (x != 0) {
            // Get the next digit and pop it
            int nextDigit = x % 10;
            x /= 10;
            
            // Check for overflow. 2^31 - 1 = 2147483647, -2^31 = -2147483648
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && nextDigit > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && nextDigit < -8)) return 0;
            
            // Append the digit to the reversed int
            rev = rev * 10 + nextDigit;
        }
        
        return rev;
    }
};


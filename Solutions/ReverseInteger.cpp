// Leetcode Problem #7
// https://leetcode.com/problems/reverse-integer/

// Solution 1: Pop and Push Digits & Check before Overflow | O(log(x)) time and O(1) tiem
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        
        // While the original int is nonzero
        while (x != 0) {
            // Get the next digit and pop it
            int nextDigit = x % 10;
            x /= 10;
            
            // Check for overflow. Last digit of (2^31 - 1 is 7
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && nextDigit > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && nextDigit < -8)) return 0;
            
            rev = rev * 10 + nextDigit;
        }
        return rev;
    }
};


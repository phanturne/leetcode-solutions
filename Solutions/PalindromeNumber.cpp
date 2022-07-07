// Leetcode Problem #9: https://leetcode.com/problems/palindrome-number
// Source: https://leetcode.com/problems/palindrome-number/solution

// Solution 1: Revert Half the Number | O(log(n)) time, O(1) space
class Solution {
public:
    bool isPalindrome(int x) {
        // x is not a palindrome if it is negative or if the last digit is 0 but x != 0
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        
        // Loop through half the digits in x
        int reversed = 0;
        while (reversed < x) {
            // Append the last digit from x to reversed and remove it from x
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        
        // If length of x is odd, reversed / 10 will remove the middle digit and check if its a palindrome
        return (x == reversed || x == reversed / 10);
    }
};


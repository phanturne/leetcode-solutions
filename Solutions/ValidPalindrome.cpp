// Leetcode #125: https://leetcode.com/problems/valid-palindrome/
// Source: https://leetcode.com/problems/valid-palindrome/discuss/40048/Here's-a-clean-C%2B%2B-solution

// Solution 1 | O(n) time, O(1) space
class Solution {
public:
    bool isPalindrome(string s) {
        // Empty string is a palindrome
        if (s.empty()) return true;
        
        // Initialize left pointer to the 0th index and right pointer to the last index
        int l = 0, r = s.size() - 1;
        
        // Loop through the string until left and right pointers collide
        while (l < r) {
            // Skip non-alphanumeric characters
            while (isalnum(s[l]) == false && l < r) l++;
            while (isalnum(s[r]) == false && l < r) r--;
            
            // If the letters do not match, it is not a palindrome. Update left and right pointers.
            if (toupper(s[l++]) != toupper(s[r--])) return false;
        }
            
        return true; // All letters matched, so it is a palindrome
    }
};

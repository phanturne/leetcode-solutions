// Leetcode #125: https://leetcode.com/problems/valid-palindrome/
// Source: https://leetcode.com/problems/valid-palindrome/discuss/40048/Here's-a-clean-C%2B%2B-solution

// Solution 1 | O(n) time, O(n) space
class Solution {
public:
    bool isPalindrome(string s) {
        // Empty string is a palindrome
        if (s.empty()) return true;
        
        // Initialize left pointer to the 0th index and right pointer to the last index
        // Loop through the string until left and right pointers collide
        for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
            // Increment the left pointer while it is not alphanumeric
            while (isalnum(s[l]) == false && l < r) l++;
            
            // Decrement the right pointer while it is not alphanumeric
            while (isalnum(s[r]) == false && l < r) r--;
            
            // If the letters do not match, it is not a palindrome
            if (toupper(s[l]) != toupper(s[r])) return false;
        }
            
        return true; // Return true since all the letters matched
    }
};

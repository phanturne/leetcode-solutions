// Leetcode Problem #5: https://leetcode.com/problems/longest-palindromic-substring/
// Source: https://leetcode.com/problems/longest-palindromic-substring/discuss/151144/Bottom-up-DP-Two-pointers

// Solution 1: Two Pointers | O(n^2) time, O(1) space
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, maxLen = 1;
        
        // Loop through each possible palindrome center position
        for (int i = 0; i < n; i++) {
            // Find first char to right of s[i] that != s[i]
            int right = i;
            while (right < n && s[i] == s[right]) right++;
            // After the loop, s[i, right - 1] are same characters e.g.("aaa")
            
            // Extend both the left and right ends while s[left, right] is a palindrome
            int left = i - 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            
            // Palindrome is s[left + 1, right - 1]
            int currLen = right - left - 1; // (right - 1) - (left - 1) + 1 = right - left - 1;
            if (maxLen < currLen) {
                start = left + 1;
                maxLen = currLen;
            }
        }
        return s.substr(start, maxLen);
    }
};

// Solution 2: DP | O(n^2) time, O(n^2) space
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        // Stores if a substring is P[start, end] is a palindrome
        vector<vector<bool>> P(n, vector<bool> (n, false));
        
        // Set values of 1 letter palindromes i.e. start == end
        for (int i = 0; i < n; i++) P[i][i] = true;
        
        int maxStart = 0, maxLen = 1;
        
        // Loop through each column from top to down
        for (int end = 0; end < n; end++) {
            // Loop through each row from right to left
            for (int start = end - 1; start >= 0; start--) {
                // Check if the first and last letter are equal
                if (s[start] == s[end]) {
                    // Check if the substring is only 2 letters or if the smaller substring is a palindrome
                    if (end - start == 1 || P[start + 1][end - 1]) {
                        P[start][end] = true;
                        int currLen = end - start + 1;
                        
                        // Update the longest palindrome seen
                        if (maxLen < currLen) {
                            maxStart = start;
                            maxLen = currLen;
                        }
                    }
                }
            }
        }
        return s.substr(maxStart, maxLen);
    }
};

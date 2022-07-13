// Leetcode Problem #10: https://leetcode.com/problems/regular-expression-matching/
// Source: https://leetcode.com/problems/regular-expression-matching/discuss/191830/Java-DP-solution-beats-100-with-explanation
// Source: https://leetcode.com/problems/regular-expression-matching/discuss/5684/C%2B%2B-O(n)-space-DP
// Source: https://youtu.be/l3hda49XcDE

// Solution 1: Bottom-Up Dynamic Programming | O(n * m) time, O(n * m) space, n = s.length(), m = p.length()
// Note: can also be done with O(n) space
class Solution {
public:
    bool isMatch(string s, string p) {
        // Matrix to cache whether s[0:row] and p[0:col] match
        vector<vector<bool>> dp(s.length() + 1, vector<bool> (p.length() + 1, false));

        // Initialize the first row of the matrix
        // Empty string matches patterns that can represent an empty string (i.e. p = "" or "a*b*")
        dp[0][0] = true;
        for (int j = 2; j <= p.length(); j++) {
            dp[0][j] = p[j - 1] == '*' && dp[0][j - 2];
        } 

        // Loop through each column (i.e. chars of p) 
        for (int j = 1; j <= p.length(); j++) { 
            // Loop through each row (i.e. chars of s)
            for (int i = 1; i <= s.length(); i++) {
                // If chars match, dp[row][col] depends on previous state dp[row - 1][col - 1]
                // Note: p and s are 0 indexed, so we "col - 1" and "row - 1" is the current char
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // dp[row][col - 2] represents 0 occurrences of char before '*'
                    // dp [row - 1][col] represents 1+ occurrences of char before '*'
                    dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
            }
        }

        return dp[s.length()][p.length()];
    }
};

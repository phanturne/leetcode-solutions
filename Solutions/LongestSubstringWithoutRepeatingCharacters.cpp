// Leetcode Problem #3: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/1737/C%2B%2B-code-in-9-lines.

// Solution 1: O(n) time, O(1) space
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // Vector to hold the 128 ASCII characters (not 256 b/c no extended ASCII characters)
        // All elements are initialized to -1 instead of 0 so the 1st occurence of any char will set start = 0
        vector<int> dict(128, -1);
        
        // Initialize helper variables to track the start index and max substring length
        int maxLen = 0, start = 0;

        for (int end = 0; end < s.length(); ++end)
        {
            // Start pointer becomes max of current start and index of previous occurence of the character + 1
            // If it's the 1st occurence of the character, dict[s[i]] + 1 = -1 + 1 = 0
            start = max(start, dict[s[end]] + 1);

            // Update most recent index of the character
            dict[s[end]] = end;

            // Calculate max length
            maxLen = max(maxLen, end - start + 1);
        }
        
        // Return max length
        return maxLen;
    }
};

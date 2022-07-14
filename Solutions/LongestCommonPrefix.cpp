// Leetcode Problem #14:https://leetcode.com/problems/longest-common-prefix/
// Source:https://leetcode.com/problems/longest-common-prefix/solution

// Solution 1: Vertical Scanning | O(m *len(LCP)) time, O(1) space where m = number of strings and LCP is the longest common prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Loop through the indices of the first string
        // Index keeps track of the length of the LCP
        for (int index = 0; index < strs[0].length(); index++) {
            // Loop through each word.
            for (int i = 1; i < strs.size(); i++) {
                // If any prefix does not match, return the LCP
                if (strs[0][index] != strs[i][index]) return strs[0].substr(0, index);
            }
        }
            
        // If execution reaches here, the first string must be the LCP
        return strs[0];
    }
};

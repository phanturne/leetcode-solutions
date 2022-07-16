// Leetcode #28:
// Source:

// Solution 1: Brute Force | O(m * n) time, O(1) space | m = len(haystack), n = needle.length()
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length(), nLen = needle.length();
        
        // Loop through each valid index in haystack
        for (int i = 0; i + nLen <= hLen; i++) {
            // If the substring starting at i matches the needle, return i
            if (haystack.substr(i, nLen) == needle) return i;
        }
        
        return -1; // If we reach here, the needle was not found
    }
};

// Solution 2: KMP Algorithm

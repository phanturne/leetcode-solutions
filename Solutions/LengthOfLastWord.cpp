// Leetcode #58: https://leetcode.com/problems/length-of-last-word/
// Source: https://leetcode.com/problems/length-of-last-word/discuss/21892/7-lines-4ms-C%2B%2B-Solution

// Solution 1: O(n) time, O(1) space
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, index = s.length() - 1;
        
        // Starting from the end of the string, find the first non-space char
        while(index >= 0 && s[index] == ' ') index--;
        
        // From the char, move backwards and count the number of non-space chars
        while (index >= 0 && s[index] != ' ') {
            index--;
            len++;
        }
        
        return len;
    }
};

// Leetcode #171: https://leetcode.com/problems/excel-sheet-column-number/
// Source: https://leetcode.com/problems/excel-sheet-column-number/discuss/1790101/C%2B%2B-oror-4-Lines-oror-Easy-To-UnderStand-oror-0ms-oror-100

// Solution 1 | O(n) time, O(n) space
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int columnNumber = 0; // Variable to store the column number
        int len = columnTitle.length();
        
        // Loop through the string
        for (char c : columnTitle) {
            // Add the value of the letter to the sum, using a base 26 system
            columnNumber = columnNumber * 26 + (c - 'A' + 1); 
        }
        
        return columnNumber; // Return the value
    }
};

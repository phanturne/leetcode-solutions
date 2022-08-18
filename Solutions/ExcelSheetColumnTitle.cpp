// Leetcode #168: https://leetcode.com/problems/excel-sheet-column-title/
// Source: https://leetcode.com/problems/excel-sheet-column-title/discuss/441430/Detailed-Explanation-Here's-why-we-need-n-at-first-of-every-loop-(JavaPythonC%2B%2B)

// Solution 1 | O(n) time, O(logn) space? <- log base 26
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title = ""; // String to hold the column title
        
        // While columnNumber > 0:
        while (columnNumber > 0) {
            columnNumber--; // Subtract 1 b/c it is a 26-nary system that starts with 1 instead of 0
            int curr = columnNumber % 26; // Use modulo to calculate the current digit
            
            // Remove the amount from columnNumber
            columnNumber /= 26; 
            
            title += (curr + 'A'); // Add the letter to the column title
        }

        reverse(title.begin(), title.end()); // Reverse the string b/c we appended digits backwards
        return title; // Return the column title
    }
};

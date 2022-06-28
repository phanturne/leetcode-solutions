// Leetcode Problem #6
// https://leetcode.com/problems/zigzag-conversion/solution/

// Solution 1: Sort By Row | O(n) time, O(n) space
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        // Variables to store the substrings and track the current row and direction
        vector<string> rows(min(numRows, int(s.size())));
        int currRow = 0;
        bool isGoingDown = false;

        // Loop through s, adding each char to a string in the vector
        for (char c : s) {
            rows[currRow] += c;
            // Change direction if we're at the topmost or bottommost row
            if (currRow == 0 || currRow == numRows - 1) isGoingDown = !isGoingDown;
            currRow += isGoingDown ? 1 : -1; // Update the next row number
        }

        // Concatenate the strings together and return the result
        string result;
        for (string row : rows) result += row;
        return result;
    }
};

// Solution 2: 
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        // Helper variables to store string length, cycle length, and result
        string result;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;
        
        // For each row, starting from the first row
        for (int i = 0; i < numRows; i++) {
            // Loop through indices, incrementing by cycleLen, and add chars to result if they belong on the row
            for (int j = 0; j + i < n; j+= cycleLen) {
                // Chars on "vertical line" are at indices k * cycleLen + i
                result += s[j + i]; 
                
                // Chars on "diagonal" are at indices (k + 1) * cycleLen - i
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) result += s[j + cycleLen - i];
            }
        }
        return result;
    }
};

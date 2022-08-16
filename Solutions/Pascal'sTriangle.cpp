// Leetcode #118: https://leetcode.com/problems/pascals-triangle/
// Source: https://leetcode.com/problems/pascals-triangle/discuss/727318/C%2B%2B-simple-solution-0-ms-beats-100.00

// Solution 1 (Iterative) | O(n^2) time, O(n^2 space)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Create an empty 2D vector
        vector<vector<int>> vec;
        
        if (numRows == 0) return vec; // Return empty vector if there are no rows
        
        // For each row
        for (int row = 0; row < numRows; row++) {
            // Create a vector for the row w/ all values initialized to 1
            vector<int> rowVec(row + 1, 1);
            
            // For col = 1 to row number:
            for (int col = 1; col < row; col++) {
                // Value of the cell is the sum of the 2 cells above it from the previous row (ex. Cell 2 on Row 3 = Cell 1 + Cell 2 from Row 2)
                rowVec[col] = vec[row - 1][col - 1] + vec[row - 1][col];
            }
                
            vec.push_back(rowVec); // Add the row to the end of the 2D vector
        }
            
        return vec; // Return the 2D vector
    }
};

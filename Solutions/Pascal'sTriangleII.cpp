// Leetcode #119: https://leetcode.com/problems/pascals-triangle-ii/
// Source: https://leetcode.com/problems/pascals-triangle-ii/discuss/38420/Here-is-my-brief-O(k)-solution/115349

// Solution 1 | O(n^2) time, O(n) space
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Initialize a vector of size rowIndex + 1 w/ all 0's
        vector<int> vec(rowIndex + 1, 0);
        
        vec[0] = 1; // First row has 1 cell with value 1
        
        // Loop rowIndex times
        for (int row = 1; row < rowIndex + 1; row++) {
            // Overwrite values of the cells of the row BACKWARDS using previous values
            // Start from index 1 b/c index 0 is always 1
            for (int col = row; col >= 1; col--) {
                vec[col] = vec[col - 1] + vec[col];
            }  
        }
        
        return vec; // Return the vector
    }
};

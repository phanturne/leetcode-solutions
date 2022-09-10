// Leetcode #733: https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // If the starting pixel needs to be changed, call the helper function
        if (image[sr][sc] != color) helper(image, sr, sc, color, image[sr][sc]);
        
        return image; // Return the vector
    }
    
    void helper(vector<vector<int>>& image, int sr, int sc, int color, int match) {
        // If the pixel does not match the color of the starting pixel, just return
        if (image[sr][sc] != match) return;
        
        // Change the color of the current pixel
        image[sr][sc] = color;
        
        // Recursively flood fill any adjacent pixels
        if (sr - 1 >= 0) helper(image, sr - 1, sc, color, match);                   // image[sr - 1][sc]
        if (sr + 1 < image.size()) helper(image, sr + 1, sc, color, match);         // image[sr + 1][sc]
        if (sc - 1 >= 0) helper(image, sr, sc - 1, color, match);                   // image[sr][sc - 1]
        if (sc + 1 < image[sr].size()) helper(image, sr, sc + 1, color, match);     // image[sr][sc + 1]
    }
};

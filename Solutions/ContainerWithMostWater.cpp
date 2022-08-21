// Leetcode #11: https://leetcode.com/problems/container-with-most-water/
// Source: https://leetcode.com/problems/container-with-most-water/discuss/6090/Simple-and-fast-C%2B%2BC-with-explanation

// Solution 1 | O(n) time, O(1) space
class Solution {
public:
    int maxArea(vector<int>& height) {
        // Left and right pointers to track the start and end of the container
        // Start with the container with the max width. 
        int left = 0, right = height.size() - 1;
        
        // Max amount of water
        int maxWater = 0;
        
        // While there's a valid start and end for a container
        while (left < right) {
            int currHeight = min(height[left], height[right]);
            
            // Calculate the amount of water the container can store and update the max
            maxWater = max(maxWater, (right - left) * currHeight);
            
            // A container that holds more water needs to be heigher, so skip ones that don't support a greater height
            while(height[left] <= currHeight && left < right) left++;
            while(height[right] <= currHeight && left < right) right--;
        }
                
        return maxWater; // Return the max amount of water
    }
};

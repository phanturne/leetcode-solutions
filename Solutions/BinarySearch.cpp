// Leetcode #704: https://leetcode.com/problems/binary-search/

// Solution 1 | O(logn) time, O(1) space
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Search space is the whole vector
        int left = 0, right = nums.size() - 1;
        
        // While there are elements in the search space
        while (left <= right) {
            // Calculate the middle index
            int mid = left + (right - left) / 2;

            // If it's too large, discard the right half
            if (nums[mid] > target) right = mid - 1;
            
            // Else if it's too small, discard the left half
            else if (nums[mid] < target) left = mid + 1;
            
            // Else we found the target, return its index
            else return mid;
        }
        
        return -1; // If we reach here, target was not found
    }
};

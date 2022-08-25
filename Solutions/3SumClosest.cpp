// Leetcode #16: https://leetcode.com/problems/3sum-closest/
// Source: https://leetcode.com/problems/3sum-closest/discuss/7883/C%2B%2B-solution-O(n2)-using-sort

// Solution 1 | O(n^2) time, O(1) space
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // Store the closest sum
        int closestSum = nums[0] + nums[1] + nums[3];
        
        // Loop through possible values for num1
        // Use the Two-Sum algorithm to find num2 and num3
        // num1 = nums[i], num2 = nums[left], num3 = nums[right]
        for (int i = 0; i < nums.size() - 2; i++) {
            // Set starting indices for num2 and num3
            int left = i + 1, right = nums.size() - 1;
            
            // While there are valid indices for num2 and num3
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right]; // Calculate the sum
                
                // If sum == target, we've found the exact sum. Return it.
                if (sum == target) return sum;
                
                // Else if the sum is too small, increment left pointer
                if (sum < target) left++;
                
                // Else if the sum is too large, decrement right pointer
                else right--;
                
                // Update the closest sum
                if (abs(target - closestSum) > abs(target - sum)) closestSum = sum;
            }
        }
        
        return closestSum; // Return the closest sum
    }
};

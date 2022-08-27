// Leetcode #15: https://leetcode.com/problems/3sum/
// Source: https://leetcode.com/problems/3sum/discuss/7380/Concise-O(N2)-Java-solution

// Solution 1 | O(n^2) time, O(n) space?
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the vector
        sort(nums.begin(), nums.end());
        
        // Create a 2D vector to hold the answer
        vector<vector<int>> res;
        
        // Loop through the possible indices for num1
        // Fix num1 and find num2 & num3 using the Two-Sum algorithm, while removing duplicates. 
        // num1 = nums[i], num2 = num[left], num3 = num[right]
        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicates of nums1
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // If num1 > 0, there's no way to get a sum of 0 since num1 is the smallest
            if (nums[i] > 0) break;
            
            // Set starting indices to search for nums2 and nums3
            int left = i + 1;
            int right = nums.size() - 1;
            
            // While there are valid indices for num1 and num2
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                // If num1 + num2 + num3 = 0, we have found a solution
                if (sum == 0) {
                    // Add solution to our result
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates of nums2 and nums3
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Increment left and decrement right indices to check for additional solutions
                    left++;
                    right--;
                }
                
                // Else if the sum is too small, increment left pointer
                else if (sum < 0) left++;
                
                // Else the sum is too large, so decrement right pointer
                else right--;
            }      
        }
            
        return res; // Return the answer
    }
};

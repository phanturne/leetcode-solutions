// Leetcode #18: 
// Source: https://leetcode.com/problems/4sum/solution/

// Solution 1 (K Sum w/ 2 Pointers)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Sort the integers
        sort(nums.begin(), nums.end());
        
        // Call the kSum function with k = 4, target, and start = 0th index
        return kSum(nums, 4, target, 0);
    }
    
    // Helper function to calculate the kSum
    vector<vector<int>> kSum(vector<int>& nums, int k, long long target, int start) {
        vector<vector<int>> res; // 2D vector to store the result
        
        // If there are not enough elements from the starting pos, return empty vec
        if (start + k > nums.size()) return res;
        
        // If the smallest num > (target / k), any k numbers we choose will be too big
        // If the largest num < (target / k), any k numbers we choose will be too small
        long long avg = target / k;
        if (nums[start] > avg || nums.back() < avg) return res;
        
        // If k == 2, call the twoSum helper function
        if (k == 2) return twoSum(nums, target, start);
        
        // Else, loop through the vector for each possible "kth value"
        for (int i = start; i <= nums.size() - k; i++) {
            // Skip duplicates for the "kth value"
            if (i != start && nums[i] == nums[i - 1]) continue;
            
            // Recursively find the possible combinations for the other "k - 1" values
            vector<vector<int>> vecs = kSum(nums, k - 1, target - nums[i], i + 1);
            
            // For each subset of values:
            for (vector<int>& subset : vecs) {
                // Add the "kth value" + subset to result
                res.push_back({nums[i]});
                res.back().insert(end(res.back()), begin(subset), end(subset));
            }
        }
        
        return res; // Return result
    }
    
    // Helper function to calculate 2Sum
    vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
        vector<vector<int>> res; // 2D vector to store the result
        int lo = start, hi = nums.size() - 1; // Initialize starting indices
        
        // While there are valid indices
        while (lo < hi) {
            int sum = nums[lo] + nums[hi]; // Calculate the sum
            
            // If sum is too small OR if num1 is a duplicate, increment left index
            if (sum < target || (lo != start && nums[lo] == nums[lo - 1])) lo++;
            
            // Else if sum is too large OR if num2 is a duplicate, decrement right index
            else if (sum > target || (hi != nums.size() - 1 && nums[hi] == nums[hi + 1])) hi--;
            
            // Else we have found a solution. Add it to the vector and update both indices
            else res.push_back({nums[lo++], nums[hi--]});
        }
                 
        return res; // Return result
    }
};

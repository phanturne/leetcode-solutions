// Leetcode #53: https://leetcode.com/problems/maximum-subarray/
// Source: https://leetcode.com/problems/maximum-subarray/discuss/1595195/C%2B%2BPython-7-Simple-Solutions-w-Explanation-or-Brute-Force-%2B-DP-%2B-Kadane-%2B-Divide-and-Conquer

// Solution 1 (Kadane's Algorithm) | O(n) time, O(1) space
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize sum = maxSum = -INF
        int sum = 0, maxSum = nums[0];
        
        // Loop through the vector
        for (int num : nums) {
            sum = max(sum + num, num);  // Choose between adding num to sum and starting fresh w/ num
            maxSum = max(maxSum, sum);  // Update maxSum
        }
            
        return maxSum; // Return maxSum
    }
};

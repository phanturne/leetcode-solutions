// Leetcode Problem #1: https://leetcode.com/problems/two-sum/
// Source: https://leetcode.com/problems/two-sum/discuss/13/Accepted-C++-O(n)-Solution/263

// Solution 1: Map | O(n) time, O(n) space
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a map of values w/ indices of the elements "looking for it"
        unordered_map<int, int> map;
        
        // For each number in nums
        for (int i = 0; i < nums.size(); i++) {
            // If the element is in the map, return the indices
            auto it = map.find(nums[i]);
            if (it != map.end()) return {it->second, i};

            // Else store target - current element with the current index
            map[target - nums[i]] = i;
        }
        
        return {}; // Solution not found, return empty vector. SHOULD NOT HAPPEN!
    }
};

// Leetcode Problem #1
// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered map
        unordered_map<int, int> hashTable;
        
        // For each number in nums
        for (int i = 0; i < nums.size(); i++) {
            // If target - currNum is in the map:
            auto it = hashTable.find(target - nums[i]);
            if (it != hashTable.end()) {
                return vector<int> {it->second, i};
            }

            // Else add currNum and its index to the map
            hashTable[nums[i]] = i;
        }
        return {}; // Solution not found, return empty set
    }
};

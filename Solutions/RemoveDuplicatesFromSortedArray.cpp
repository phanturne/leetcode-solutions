// Leetcode Problem #26:
// Source:
// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/11782/Share-my-clean-C++-code/210808

// Solution 1: For Loop | O(n) time, O(1) space
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Holds the # of unique integers, and is also the index for the next unique integer
        int count = 1;

        // Loop through the vector, moving each unique integer to the front of the vector
        for (int n : nums)
            // nums[count - 1] is the previous unique integer and the next unique integer must be greater
            if (n > nums[count - 1]) nums[count++] = n;
        return count;
    }
};


// Solution 2: Vector Functions | O(n) time, O(1) space
class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        // unique() returns an iterator to the element that follows the last element not removed.
        nums.erase(unique(nums.begin(), nums.end()), nums.end()); 
        return nums.size();
    }
};

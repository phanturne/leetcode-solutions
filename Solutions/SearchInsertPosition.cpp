// Leetcode #35:
// Source 1: https://leetcode.com/problems/search-insert-position/discuss/15101/C%2B%2B-O(logn)-Binary-Search-that-handles-duplicate
// Source 2: https://leetcode.com/problems/search-insert-position/discuss/249092/Come-on-forget-the-binary-search-patterntemplate!-Try-understand-it!

// Solution 1: Binary Search 
// Solution is directly from Source 1
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        // Invariant: the desired index is between [low, high+1]
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }

        // (1) At this point, low > high. That is, low >= high+1
        // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
        // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
        return low;
    }
};

// Solution 1b: Binary Search | O(logn) time, O(1) space
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        
        // Using binary search, return index of target if it exists
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        // If execution reaches here, target was not found
        // r will be nums.size() if target > all integers in the vector
        return r;
    }
};

// Solution 2: Brute Force | O(n) time, O(1) space
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Loop through the vector
        for (int i = 0; i < nums.size(); i++) {
            // If current element >= target, return index b/c the element is either here or should be inserted here
            if (nums[i] >= target) return i;
        }
        
        // Element should be inserted at the end of the vector
        return nums.size();
    }
};

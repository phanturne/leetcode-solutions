// Leetcode Problem #27: https://leetcode.com/problems/remove-element/
// Source: https://leetcode.com/problems/remove-element/solution/
// Source: https://leetcode.com/problems/remove-element/discuss/639867/C%2B%2B-1-liner-simple-code

// Solution 1a: Two Pointers | O(n) time, O(1) space
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0; // Tracks index to place the next element that's not equal to val
        
        // Loop through the vector, moving the element forwards if it's not equal to val
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) nums[i++] = nums[j];
        }
        
        return i;
    }
};

// Solution 1b: Two Pointers | O(n) time, O(1) space
// Note: This version is optimized for when elements to remove are rare
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Tracks the index of the item that was mostly recently swapped forwards
        int n = nums.size();
        
        // Loop through the vector, moving the element forwards if it's not equal to val
        for (int i = 0; i < n; i++) {
            // n is pre-decremented to get index of element to swap
            // i is post-decremented b/c we still need to check the item we swapped forwards 
            if (nums[i] == val) nums[i--] = nums[--n];
        }
        
        return n;
    }
};

// Solution 2: While loop with .erase() | O(n) time, O(1) space
// Note: https://stackoverflow.com/questions/4645705/vector-erase-iterator
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Loop through the vector, erasing it from the vector if it matches val
        auto it = nums.begin();
        while (it != nums.end()) {
            if (*it == val) nums.erase(it);
            else ++it;
        }
        
        return nums.size();
    }
};

// Solution 3: Remove Element with .erase() and remove() | O(n) time, O(1) space
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

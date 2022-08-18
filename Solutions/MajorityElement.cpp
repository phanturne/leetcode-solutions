// Leetcode #169: https://leetcode.com/problems/majority-element/
// Source: https://leetcode.com/problems/excel-sheet-column-title/discuss/441430/Detailed-Explanation-Here's-why-we-need-n-at-first-of-every-loop-(JavaPythonC%2B%2B)

// Solution 1 (Brute Force) | O(n^2) time, O(1) space
// Double for loop to find the element that appears > floor(n / 2) times

// Solution 2 (Hashmap) | O(n) time, O(n) space
// Use a hashmap to store the # of occurrences of each element. Then use a for loop to find the greatest one.

// Solution 3 (Sort Array) | O(nlogn) time, O(1) space if in-place, O(n) if not
// Sort the array and return the element at index floor(n / 2)

// Solution 4 (Randomization) | O(infinity) time, but expected time is O(n), O(1) sapce
// Randomly pick an element and check if it appears > floor(n / 2) times

// Solution 5 (Divide & Conquer) | O(nlogn) time, O(logn) space
// Recursively calculate the majorities of each half of the array and the overall majority has to be one of them

// Solution 6 (Boyer-Moore Voting Algorithm) | O(n) time, O(1) space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0]; // Stores a candidate for the majority element
        int counter = 0; // Tracks the "presence" of the majority element
        
        // Loop through the vector
        for (int num : nums) {
            // If counter is 0, the current element becomes the new candidate
            if (counter == 0) candidate = num;
            
            // Increment counter if we see the majority element, else decrement it
            counter += (num == candidate) ? 1 : -1;
        } 
        
        return candidate; // The candidate appears > floor(n / 2) times, so it must be the majority
    }
};


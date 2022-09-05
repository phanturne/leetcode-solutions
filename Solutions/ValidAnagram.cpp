// Leetcode #242: https://leetcode.com/problems/valid-anagram/

// Solution 1 | O(n) time, O(n) space
class Solution {
public:
    bool isAnagram(string s, string t) {
        // Create an array to store count of each character
        int count[128] = {};
        
        // Loop through each char from the first string and increment its count
        for (char c : s) count[c]++;
        
        // Loop through each char from the second string and decrement its count
        for (char c : t) count[c]--;
        
        // Check if the 2nd string used the same chars as the first string
        for (int val : count) if (val != 0) return false;
        
        return true; // After checking all chars, 2nd string must be an anagram of the first
    }
};

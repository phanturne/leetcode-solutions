// Leetcode Problem #13: https://leetcode.com/problems/roman-to-integer/
// Source: https://leetcode.com/problems/roman-to-integer/discuss/6547/Clean-O(n)-c%2B%2B-solution

// Solution 1: Map | O(n) time, O(1) space
class Solution {
public:
    int romanToInt(string s) {
        // A map to store the values of the Roman numeral chars
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        // Initialize sum to value of last char
        int sum = romanMap[s[s.length() - 1]]; 
        
        // Loop through s, excluding the last char
        for (int i = 0; i < s.length() - 1; i++) {
            // If the next symbol is larger, subtract value of current char from sum, else add it.
            if (romanMap[s[i]] < romanMap[s[i + 1]]) {
                sum -= romanMap[s[i]];
            } else {
                sum += romanMap[s[i]];
            }
        }
        
        return sum;
    }
};

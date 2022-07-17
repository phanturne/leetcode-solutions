// Leetcode #66: https://leetcode.com/problems/plus-one/
// Source: https://leetcode.com/problems/plus-one/discuss/24084/Is-it-a-simple-code(C%2B%2B)

// Solution 1: Loop from the back | O(n) time, O(1) space
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            // If the digit < 9, we can simply add 1 and return 
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // Else the sum would be 10, so set the current digit to 0
            digits[i] = 0;
        }

        // If we reach here, then all digits were 9 and now all are 0.
        // ex. Started with [9, 9, 9]. Now have [0, 0, 0]. Want [1, 0, 0, 0]
        // We can set the first digit to 1 and add a 0 to the end.
        digits[0] = 1;
        digits.push_back(0);

        return digits;
    }
};



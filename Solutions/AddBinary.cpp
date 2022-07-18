// Leetcode #67: https://leetcode.com/problems/add-binary/
// Source: https://leetcode.com/problems/add-binary/discuss/1679423/Well-Detailed-Explaination-Java-C%2B%2B-Python-oror-Easy-for-mind-to-Accept-it

// Solution 1 | O(n) time, O(1) space
class Solution {
public:
    string addBinary(string a, string b) {
        // Initialize helper variables
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string result;
        
        // While the strings have valid indices or carry > 0
        while (i >= 0 || j >= 0 || carry > 0) {
            // Initialize temp with value of carry and add value of a[i] and b[j] if they exist. 
            //Subtract '0' gets the integer value.
            int temp = carry;
            if (i >= 0) temp += a[i--] - '0';
            if (j >= 0) temp += b[j--] - '0';
        
            // The binary digit to add is temp % 2.
            result += char(temp % 2 + '0');
        
            // Calculate the next carry
            carry = temp / 2;
        }
              
        // Reverse the string and return it
        reverse(result.begin(), result.end());
        return result;
    }
};

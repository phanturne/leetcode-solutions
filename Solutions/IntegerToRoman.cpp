// Leetcode #12: https://leetcode.com/problems/integer-to-roman/
// Source: https://leetcode.com/problems/integer-to-roman/discuss/6274/Simple-Solution
// Source: https://leetcode.com/problems/integer-to-roman/discuss/6310/My-java-solution-easy-to-understand

// Solution 1 (For Loop) | O(n) time?, O(1) space
class Solution {
public:
    string intToRoman(int num) {
        // Arrays of roman numerals and their values
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        int i = 0; // Start with the largest roman numeral
        string romanNumeral; // Holds the constructed roman numeral
        
        // While we didn't finish constructing the roman numeral:
        while (num > 0) {
            // While the number is greater than the current roman numeral:
            while (num >= vals[i]) {
                num -= vals[i]; // Subtract the value of the roman numeral from our number
                romanNumeral += roman[i]; // Add the roman numeral to our string
            }
            
            i++; // Move to the next largest roman numeral in our array
        }
            
        return romanNumeral; // Return the roman numeral
    }
};

// Solution 2 (Hardcoded & Unscalable) | O(1) time, O(1) space
class Solution {
public:
    string intToRoman(int num) {
        // Create arrays for thousandths, hundredths, tens, and ones place, for 1 <= num <= 3999
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        // Return the roman numeral constructed from each array
        return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
    }
};

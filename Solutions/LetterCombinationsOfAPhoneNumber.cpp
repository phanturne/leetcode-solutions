// Leetcode #17: https://leetcode.com/problems/letter-combinations-of-a-phone-number/ 

// Solution 1 (Iterative w/ Queue) | O(4^n) time?, O(4^n) space?
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans; // Store the possible combinations
        string numPad[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        // If the string is empty, return the empty vector
        if (digits.length() == 0) return ans;
        
        // Initialize a queue with the empty string
        queue<string> queue;
        queue.push("");
        
        // While the queue is nonempty
        while (!queue.empty()) {
            // Dequeue from the queue
            string curr = queue.front();
            queue.pop();
            
            // If we have a complete combination, add it to the vector
            if (curr.length() == digits.length()) ans.push_back(curr);
            
            // Else enqueue combinations with the letters mapped to the next digit
            else {
                int digit = digits[curr.length()] - '0'; 
                for (char c : numPad[digit]) queue.push(curr + c);
            }
        }
            
        return ans; // Return the vector
    }
};

// Solution 2 (Recursive) | O(4^n) time, O(4^n) space
class Solution {
public:
    // Map of digits to letters
    string numPad[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;                         // Stores the letter combinations
        if (digits.length() == 0) return ans;       // Return empty vector if the string is empty
        letterCombinationsHelper(digits, "", ans);  // Calls helper function to calculate the combinations
        return ans;                                 // Return the letter combinations
    }
    
    void letterCombinationsHelper(string digits, string combo, vector<string>& ans) {
        // If the combination is complete, append it to the array
        if (combo.length() == digits.length()) ans.push_back(combo);
        
        // Else recursively create a combination for each of the letters mapped to the next digit
        else {
            int digit = digits[combo.length()] - '0';
            for (char c : numPad[digit]) letterCombinationsHelper(digits, combo + c, ans);
        }
    }
};

// Leetcode #70: https://leetcode.com/problems/climbing-stairs/
// Source 1: https://leetcode.com/problems/climbing-stairs/discuss/963994/Java-from-Recursion-to-DP
// Source 2: https://leetcode.com/problems/climbing-stairs/discuss/25296/3-4-short-lines-in-every-language

// Solution 1 (DP + Optimization) | O(n) time, O(1) space
class Solution {
public:
    int climbStairs(int n) {  
        if (n <= 2) return n; // Base case
        
        int prev1 = 1, prev2 = 2; // 1 way for n = 1, 2 ways for n = 2
        
        // Loop from i = 3 to n, calculate the number of steps needed when n = i
        // M[i] = M[i - 1] + M[i - 2], and only need to track of previous 2 values
        for (int i = 3; i <= n; i++) {
            int temp = prev1;
            prev1 = prev2;
            prev2 += temp;
        }
        
        return prev2;
    }
};

// Solution 2 (Recursion + Memoization) | O(n) time, O(n) space
class Solution {
public:
    int climbStairsHelper(int n, unordered_map<int, int> &memo) {
        if (n <= 2) return n; // Base case

        // If value is in memo table, return it
        if (memo.find(n) != memo.end()) return memo[n];

        // Else calculate the value and store in memo table
        memo[n] = climbStairsHelper(n - 1, memo) + climbStairsHelper(n - 2, memo);
        return memo[n];
    }
    
    int climbStairs(int n) {  
        // Initialize an unordered map for memoization
        unordered_map<int, int> memo;
        memo[1] = 1;
        memo[2] = 2;
        
        return climbStairsHelper(n, memo);
    }
};

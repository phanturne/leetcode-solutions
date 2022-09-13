# Leetcode 70: https://leetcode.com/problems/climbing-stairs/

# Solution 1 (Fibonacci) | O(n) time, O(1) space
class Solution:
    def climbStairs(self, n: int) -> int:
        # prev1 = climbStairs(n - 2), prev2 = climbStairs(n - 1)
        prev1, prev2 = 1, 1 
        
        for i in range(n):
            prev1, prev2 = prev2, prev1 + prev2
            
        return prev1
      
# Solution 2 (DP + Recursion) | O(n) time, O(n) space
class Solution:
    # Base case: 0 ways to climb 0 steps, 1 way for 1 step, 2 ways for 2 steps
    memo = { 1: 1, 2: 2}
    
    def climbStairs(self, n: int) -> int:
        if n in self.memo:
            # If the answer is already in the memo table, just return it
            return self.memo[n]

        # Else recursively calculate it and add to the memo table
        self.memo[n] = self.climbStairs(n - 1) + self.climbStairs(n - 2)
        return self.memo[n]

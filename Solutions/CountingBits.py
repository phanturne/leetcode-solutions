# LC #338: https://leetcode.com/problems/counting-bits/
# Source: https://leetcode.com/problems/counting-bits/discuss/79539/Three-Line-Java-Solution

# Solution 1 | O(n) time, O(n) space
class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0]   # Number 0 has no 1's
        
        # Recurrence is f[i] = f[i / 2] + i % 2 
        # Even numbers have 0 as their last bit, so right shift by 1 (i.e. divide by 2) would not change the number of 1's
        # Odd numbers have 1 as their last bit, so we need to add 1 after right shift by 1
        for i in range(1, n + 1):
            ans.append(ans[i >> 1] + (i & 1))
        return ans

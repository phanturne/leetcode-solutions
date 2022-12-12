# Leetcode #121: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

# Solution 1 (One Pass) | O(n) time, O(1) space
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Track min price so far and max profit
        minPrice = prices[0]
        maxProfit = 0

        # Iterate through the list and update minPrice and maxProfit accordingly
        for price in prices:
            if price < minPrice:
                # Update minPrice if we see a lower price
                minPrice = price 
            else:
                # Otherwise, calculate the profit if we sell now. Update maxProfit accordingly
                profit = price - minPrice
                maxProfit = profit if profit > maxProfit else maxProfit
        
        return maxProfit

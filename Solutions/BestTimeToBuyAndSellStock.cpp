// Leetcode #121: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/39039/Sharing-my-simple-and-clear-C%2B%2B-solution

// Solution 1 | O(n) time, O(n) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0; // Profit is 0 if there are less than 2 elements
        
        int maxProfit = 0; // Initialize max profit to 0
        int minPrice = prices[0]; // Track lowest price
        
        // Loop through the vector
        for (int price : prices) {
            // If the current price > lowest price, calculate profit if sell now
            if (price > minPrice) maxProfit = max(maxProfit, price - minPrice);
            
            // Else update lowest price
            else minPrice = price;
        }   
        
        return maxProfit; // Return max profit
    }
};

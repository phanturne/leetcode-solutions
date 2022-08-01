// Leetcode #69: https://leetcode.com/problems/sqrtx/
// Source 1: https://leetcode.com/problems/sqrtx/discuss/25057/3-4-short-lines-Integer-Newton-Every-Language
// Source 2: https://leetcode.com/problems/sqrtx/discuss/25047/A-Binary-Search-Solution

// Solution 1
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0; // Base case
        
        int left = 1, right = x; // Bounds for binary search
        
        // Loop while the root has not been found
        // Note: Can also set condition to while (left <= right)
        while (true) {
            int mid = left + (right - left) / 2; // Calcultate mid
            
            // If mid^2 > x, we're too far right
            if (mid > (x / mid)) right = mid - 1;
            
            // Mid is <= x. If (mid + 1)^2 > x, return mid
            else if ((mid + 1) > x / (mid + 1)) return mid;
            
            // Mid is < x AND (mid + 1)^2 < x, so we're too far left
            else left = mid + 1;
        }
        
        return -1;
    }
};




// Solution 2 (Newton's Method) | O( ? ) time, O(1) space
class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
    }
};

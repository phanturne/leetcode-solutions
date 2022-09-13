// Leetcode #69: https://leetcode.com/problems/sqrtx/
// Source 1: https://leetcode.com/problems/sqrtx/discuss/25057/3-4-short-lines-Integer-Newton-Every-Language
// Source 2: https://leetcode.com/problems/sqrtx/discuss/25047/A-Binary-Search-Solution

// Solution 1 (Binary Search) | O(logn) time, O(1) space
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) return x; 
        
        int left = 1, right = x; // Bounds for binary search
        
        // Loop while the root has not been found
        while (left <= right) {
            int mid = left + (right - left) / 2; 
            
            if (mid <= x / mid) left = mid + 1; // Too small, search right half
            else right = mid - 1; // Too big, search left half
        }
        
        return left - 1; // After exiting loop, left is 1 after the ans
    }
};

// Solution 2 (Newton's Method) | O( ? ) time, O(1) space
class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        while (r * r > x)
            r = (r + x / r) / 2;
        return r;
    }
};

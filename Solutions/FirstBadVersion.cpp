// Leetcode #278: https://leetcode.com/problems/first-bad-version/
// Source: https://leetcode.com/problems/first-bad-version/discuss/769685/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.

// The isBadVersion API is already defined for you.
// def isBadVersion(version: int) -> bool:

// Solution 1 (Binary Search) | O(logn) time, O(1) space
class Solution {
public:
    int firstBadVersion(int n) {
        int pivot, left = 1, right = n;
        while (left < right) {
            pivot = left + (right - left) / 2;
            if (isBadVersion(pivot)) {
                right = pivot;
            } else {
                left = pivot + 1;
            }
        }
        return left;
    }
};

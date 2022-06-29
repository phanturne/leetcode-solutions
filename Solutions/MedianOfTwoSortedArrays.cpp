// Leetcode Problem #4
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Source: https://www.youtube.com/watch?v=LPFhl65R7ww

// Solution 1: O(log(min(n, m)) time, O(1) space
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Make sure nums1 is the shorter vector
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        // Store size of nums1 and nums2
        int N1 = nums1.size(), N2 = nums2.size();

        // Set left and right indices for nums1
        int left = 0, right = N1;

        // Using binary search, find partitions and check if we've found the median
        while (left <= right) {
            int partition1 = (left + right) / 2;
            int partition2 = (N1 + N2 + 1) / 2 - partition1;

            // If partition == 0, there's nothing on left side. If partition == len(vector), there's nothing on right side
            int left1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int right1 = (partition1 == N1) ? INT_MAX : nums1[partition1];
            int left2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int right2 = (partition2 == N2) ? INT_MAX : nums2[partition2];

            if (left1 > right2) right = partition1 - 1; // Too far on right side for partition1. Go left
            else if (left2 > right1) left = partition1 + 1; // Too far on left side for partition1. Go right
            else { // Partition is correct, calculate the median
                if ((N1 + N2) % 2 == 0) return double(max(left1, left2) + min(right1, right2)) / 2;
                else return max(left1, left2);
            }
        }

        return -1; // Return error if code reaches here
    }
};

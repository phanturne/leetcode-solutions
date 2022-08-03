// Leetcode #88: https://leetcode.com/problems/merge-sorted-array/
// Source: https://leetcode.com/problems/merge-sorted-array/discuss/29522/This-is-my-AC-code-may-help-you

// Solution 1: O(m + n) time, O(1) space
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1; // Indices for the positions
        
        // While the second list is not merged yet
        while (j >= 0) {
            // Compare from the ends of the list and insert the larger int to position at k
            // If there are no more lists from first vector, just add from the second list
            if (i < 0 || nums1[i] < nums2[j]) nums1[k--] = nums2[j--];
            else nums1[k--] = nums1[i--];
        }
    }
};

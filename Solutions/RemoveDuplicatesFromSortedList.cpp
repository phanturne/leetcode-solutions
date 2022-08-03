// Leetcode #83: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/discuss/28663/Easy-to-understand-c%2B%2B-solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
// Solution 1: Loop | O(n) time, O(1) space
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head; // Create a pointer to the head
        // Loop through the list while the current and next node exists
        while(curr) {
            // While the next node exists and has same value, remove it
            // Note: It is important to free the removed nodes
            while (curr->next && curr->val == curr->next->val) {
                curr->next = curr->next->next;
            }

            curr = curr->next; // Not duplicate of current node, move to next node
        }
            
        return head; // Return original head 
    }
};

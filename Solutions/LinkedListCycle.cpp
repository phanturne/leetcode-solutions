// Leetcode #141: https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Solution 1 (Fast & Slow Pointer) | O(n) time, O(1) space
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false; // Cycle can't exist if head is NULL
        
        // Initialize a fast and slower pointer to the head
        ListNode* fast = head;
        ListNode* slow = head;
        
        // While the fast node's next and next next exist
        while (fast->next && fast->next->next) {
            // Move fast pointer twice and slow pointer once
            fast = fast->next->next;
            slow = slow->next;
            
            // If the fast and slower pointer point to the same node, then the fast pointer "lapped" the slower one, so there must be a cycle
            if (fast == slow) return true;
        }
            
        return false; // If we exited the loop, there must not have been a cycle
    }
};

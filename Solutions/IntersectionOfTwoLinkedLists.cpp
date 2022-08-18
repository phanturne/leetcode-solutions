// Leetcode #160: https://leetcode.com/problems/intersection-of-two-linked-lists/
// Source: https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!
// Source: https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/1093014/C%2B%2B-Four-different-solutions

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Solution 1 (Traverse Twice) | O(m + n) time, O(1) space
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Lists don't intersect if one of them is NULL
        if (headA == nullptr || headB == nullptr) return nullptr;
        
        // Pointers to track position in each list
        ListNode* pointerA = headA;
        ListNode* pointerB = headB;
        
        // While the pointers don't point to the same node:
        while (pointerA != pointerB) {
            // Note: both pointers will be the same distance from the intersection node in the "second traversal" b/c they both traverse each list
            // Increment pointerA if its not NULL, else set it to head of listB
            pointerA = (pointerA == nullptr) ? headB : pointerA->next;
            
            // Increment pointerB if its not NULL, else set it to head of listA
            pointerB = (pointerB == nullptr) ? headA : pointerB->next;
        }
        
        return pointerA; // Here, both pointers point to the intersection node
    }
};

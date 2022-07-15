// Leetcode Problem #21: https://leetcode.com/problems/merge-two-sorted-lists/
// Source: https://leetcode.com/problems/merge-two-sorted-lists/discuss/9714/14-line-clean-C++-Solution/10637

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

// Solution 1: Iterative & In-place | O(n) time, O(1) space
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a new list, list3, and store a pointer to its head
        ListNode dummy = ListNode();
        ListNode *list3 = &dummy;
        
        // While list1 and list2 are not null, add the smaller node to list3 and advance list3 and the list with the smaller node
        while (list1 && list2) {
            // curr is a pointer reference that holds the address of the smaller node
            ListNode*& curr = list1->val < list2->val ? list1 : list2;
            list3 = list3->next = curr;
            curr = curr->next;
        }
        
        // Append the remaining nodes
        list3->next = list1 ? list1 : list2;
        
        return dummy.next;
    }
};


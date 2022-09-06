// Leetcode #235: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Solution 1 | O(logn) time, O(1) space
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Store the smaller and larger value of nodes p and q
        int minVal = min(p->val, q->val), maxVal = max(p->val, q->val);
        
        // LCA must be between [minVal, maxVal] inclusive
        // While the node's is NOT between p and q, we need to go lower
        TreeNode* curr = root;
        while (!(curr->val >= minVal && curr->val <= maxVal)) {
            // If the node is too big, go left. Else, go right.
            curr = (curr->val > maxVal) ? curr->left : curr->right;
        }
            
        return curr; // Return the LCA
    }
};

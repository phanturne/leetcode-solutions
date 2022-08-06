// Leetcode #100: https://leetcode.com/problems/same-tree/
// Source: https://leetcode.com/problems/same-tree/solution/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Solution 1 (Recursive) | O(n) time, O(n) space
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are NULL, return true
        if (!p && !q) return true;
        
        // If only one of the nodes are NULL, return false
        if (!p || !q) return false;
        
        // If the nodes have different values, return false
        if (p->val != q->val) return false;
        
        // Else recursively check whether or not the left and right subtrees match
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Solution 2 (Iterative with Stack) | O(n) time, O(n) space
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Stacks to hold nodes for the two trees
        stack<TreeNode*> stackP;
        stack<TreeNode*> stackQ;
        stackP.push(p);
        stackQ.push(q);
        
        // While stack is not empty
        while(!stackP.empty()) {
            // Pop one node from each stack
            p = stackP.top();
            q = stackQ.top();
            stackP.pop();
            stackQ.pop();
            
            // If both nodes exist OR they have the same value:
            if (p and q and p->val == q->val) {
                // Push their child nodes to the stack
                stackP.push(p->left);
                stackP.push(p->right);
                stackQ.push(q->left);
                stackQ.push(q->right);
            }
                
            // Else if both nodes are NULL, continue
            else if (p == NULL and q == NULL) continue;
            
            // Else either 1 node is NULL OR they have different values
            else return false;
        }
            
        return true; // Return true b/c everything matched
    }
};

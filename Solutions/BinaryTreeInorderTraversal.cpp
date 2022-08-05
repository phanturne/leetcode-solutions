// Leetcode #94: 
// Source: 

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

// Solution 1 (Recursion) | O(n) time, O(n) space
class Solution {
public:
    void inorderTraversalHelper(TreeNode* root, vector<int>& ans) {
        if (!root) return; // Return if node is NULL
        
        inorderTraversalHelper(root->left, ans);    // Recur left
        ans.push_back(root->val);                   // Add current node
        inorderTraversalHelper(root->right, ans);   // Recur right
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;                 // Vector to hold the answer
        inorderTraversalHelper(root, ans);  // Recur from root
        return ans;
    }
};

// Solution 2 (Iterate with Stack) | O(n) time, O(n) space

// Solution 3 (Morris Traversal) | O(n) time, O(1) space

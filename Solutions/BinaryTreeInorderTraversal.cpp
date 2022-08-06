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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;            // Vector to hold the answer
        stack<TreeNode*> stack;     // Stack to simulate recursion
        TreeNode* curr = root;
        
        // While the current node exists or stack is not empty
        while (curr || !stack.empty()) {
            // While the current node exists
            while (curr) {
                // Push current node to stack and set current node to its left child
                stack.push(curr);
                curr = curr->left;
            }
                
            // Pop from stack and set current node to the popped node
            curr = stack.top();
            stack.pop();
            
            // Add current node to vector
            ans.push_back(curr->val);
            
            // Set current node to its right child
            curr = curr->right;
        }
             
        return ans; // Return answer
    }
};

// Solution 3 (Morris Traversal) | O(n) time, O(1) space

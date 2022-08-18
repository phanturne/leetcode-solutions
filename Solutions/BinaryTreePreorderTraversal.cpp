// Leetcode #144: https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec; // Empty vector to store the preorder traversal
        
        preorderTraversalHelper(root, vec); // Call helper function to fill in the vector
        
        return vec; // Return the vector
    }
    
    // Helper function that recursively finds the preorder traversal of a binary tree
    void preorderTraversalHelper(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return; // Return if the root is NULL
        
        vec.push_back(root->val); // Add the root's val to the vector
        preorderTraversalHelper(root->left, vec); // Recursively traverse the left subtree
        preorderTraversalHelper(root->right, vec); // Recursively traverse the right subtree
    }
};

// Solution 2 (Iterative w/ Stack) | O(n) time, O(n) space
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // Empty vector to store the preorder traversal
        vector<int> vec;
        
        // Initialize a stack with the root to simulate recursion
        stack<TreeNode*> stack;
        if (root != nullptr) stack.push(root);
        
        // While the stack is nonempty:
        while (!stack.empty()) {
            // Pop a node from the stack
            TreeNode* curr = stack.top();
            stack.pop();
            
            vec.push_back(curr->val); // Add its value to the vector
            
            // Push its child nodes onto the stack if they exist (right child first, so left child gets popped first)
            if (curr->right) stack.push(curr->right);
            if (curr->left) stack.push(curr->left);
        }
        
        return vec; // Return the vector
    }
};

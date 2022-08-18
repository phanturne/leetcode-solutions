// Leetcode #145:

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec; // Empty vector to store the postorder traversal
        
        postorderTraversalHelper(root, vec); // Call helper function to fill in the vector
        
        return vec;// Return the vector
    }
    
    void postorderTraversalHelper(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return; // Return if the root is NULL
        
        postorderTraversalHelper(root->left, vec); // Recursively traverse the left subtree
        postorderTraversalHelper(root->right, vec); // Recursively traverse the right subtree
        vec.push_back(root->val); // Add the root's val to the vector
    }
};

// Solution 2 (Iterative w/ Stack) | O(n) time, O(n) space
// To be continued...

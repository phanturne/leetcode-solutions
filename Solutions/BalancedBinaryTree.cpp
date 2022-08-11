// Leetcode #110: https://leetcode.com/problems/balanced-binary-tree/discuss/35691/The-bottom-up-O(N)-solution-would-be-better
// Source: https://leetcode.com/problems/balanced-binary-tree/discuss/35691/The-bottom-up-O(N)-solution-would-be-better

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

// Solution 1 (Bottom Up Recursion) | O(n) time, O(n) space
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // Empty tree is balanced
        if (root == nullptr) return true;
        
        // If the depth function returns -1, it is unbalanced
        return depth(root) != - 1;
    }
    
    // Helper function that returns the depth of the tree, or -1 if its unbalanced
    int depth(TreeNode* root) {
        // Empty tree has depth 0
        if (root == nullptr) return 0;
        
        // Recursively find the depth of left and right subtrees
        int left = depth(root->left);
        int right = depth(root->right);
        
        // Return -1 if any of the subtrees are unbalanced (depth = -1) or if the current tree is unbalanced (depth of the 2 subtrees differ by > 1)
        if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
        
        // Depth of current tree is max(depth of left and right subtree) + 1
        return max(left, right) + 1;
    }
};

// Solution 2 (Top Down Recursion ) | O(nlogn) time?, O(n) space
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // Empty tree is balanced
        if (root == nullptr) return true;
        
        // Check if the depth of the left and right subtrees are unbalanced
        if (abs(depth(root->left) - depth(root->right)) > 1) return false;
        
        // Recursively check if every subtree is balanced. 
        // It is not enough to check the max depth of the left and right subtrees b/c there may be a sub-subtree that is unbalanced
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    // Helper function to check the depth of a tree
    int depth(TreeNode* root) {
        // Empty tree has depth 0
        if (root == nullptr) return 0;
        
        // Recursively find the depth by checking the greater depth of its subtrees
        return max(depth(root->left), depth(root->right)) + 1;
    }
};

// Solution 3 (Bottom Up Iterative) 
// To be continued...


// Solution 4 (Top Down Iterative) | O(nlogn) time?, O(n) space
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // Empty tree is balanced
        if (root == nullptr) return true;
        
        // Initialize a stack with the root 
        stack<TreeNode*> stack;
        stack.push(root);
        
        // While the stack is not empty
        while(!stack.empty()) {
            // Pop from the stack
            TreeNode* curr = stack.top();
            stack.pop();
            
            // Return false if the subtrees of its child nodes are unbalanced
            if (abs(depth(curr->left) - depth(curr->right)) > 1) return false;
        
            // If it's children exist, push them onto the stack
            if (curr->left) stack.push(curr->left);
            if (curr->right) stack.push(curr->right);
        }
        
        return true; // Stack must be balanced since we checked every node
    }
    
    int depth(TreeNode* root) {
        // Empty tree has depth 0
        if (root == nullptr) return 0;
        
        // Recursively find the depth by checking the greater depth of its subtrees
        return max(depth(root->left), depth(root->right)) + 1;
    }
};

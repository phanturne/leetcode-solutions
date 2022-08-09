// Leetcode #104: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Source: https://leetcode.com/problems/maximum-depth-of-binary-tree/discuss/34195/Two-Java-Iterative-solution-DFS-and-BFS

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

// Solution 1 (Recursive DFS) | O(n) time, O(n) space
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Return 0 if root is NULL
        if (root == NULL) return 0;
        
        // Else return 1 + max(left subtree depth, right subtree depth)
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// Solution 2 (Iterative DFS) | O(n) time, O(n) space
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Depth is 0 if the root is NULL
        if (root == NULL) return 0;
        
        // Stack is used to simulate recursion. Initialized with root and depth = 1.
        stack<pair<TreeNode*, int>> stack;
        stack.push({root, 1});
        
        // Integer to keep track on max depth
        int maxDepth = 0;
        
        // While the stack is not empty
        while (!stack.empty()) {
            // Pop a node from the stack
            pair<TreeNode*, int> curr = stack.top();
            stack.pop();
            TreeNode* currNode = curr.first;
            
            // Update the maxDepth
            maxDepth = max(maxDepth, curr.second);
            
            // Push its child nodes to the stack with depth + 1, if they exist
            if (currNode->left != NULL) stack.push({currNode->left, curr.second + 1});
            if (currNode->right != NULL) stack.push({currNode->right, curr.second + 1});
        }
            
        return maxDepth; // Return maxDepth
    }
};

// Solution 3 (Iterative BFS) | O(n) time, O(n) space
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Return 0 if root is NULL
        if (root == NULL) return 0;
        
        // Queue is used to track nodes in each depth. Initialized with the root
        queue<TreeNode*> queue;
        queue.push(root);
        
        int depth = 0; // Integer to track depth
        
        // While queue is not empty
        while (!queue.empty()) {
            depth++; // Increment depth counter
            
            // Loop through the number nodes on the current depth (size of queue before this loop)
            int n = queue.size(); 
            for (int i = 0; i < n; i++) {
                // Pop the next node
                TreeNode* curr = queue.front();
                queue.pop();
                
                // Push its child nodes, if they exist
                if (curr->left != NULL) queue.push(curr->left);
                if (curr->right != NULL) queue.push(curr->right);
            }
        } 
        
        return depth; // Return depth
    }
};

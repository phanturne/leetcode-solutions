// Leetcode #226: https://leetcode.com/problems/invert-binary-tree/
// Source: https://leetcode.com/problems/invert-binary-tree/discuss/62707/Straightforward-DFS-recursive-iterative-BFS-solutions

// Solution 1 (Recursive DFS) | O(n) time, O(n) space
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Return null if the root is null
        if (root == nullptr) return root;
         
        // Recursively swap the left and right subtrees
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
            
        return root; // Return root;
    }
};

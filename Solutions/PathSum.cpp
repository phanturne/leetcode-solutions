// Leetcode #112: https://leetcode.com/problems/path-sum/
// Source: https://leetcode.com/problems/path-sum/discuss/36378/AcceptedMy-recursive-solution-in-Java/34584
// Source: https://leetcode.com/problems/path-sum/discuss/36486/Python-solutions-(DFS-recursively-DFS%2Bstack-BFS%2Bqueue)

// Solution 1 (Recursion) | O(n) time, O(n) space
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Return false if there are no more nodes on this path b/c target sum can't be met
        if (root == nullptr) return false;
        
        // If the node is a leaf, return whether or not we reached the targe sum
        if (!root->left && !root->right) return root->val == targetSum;
        
        // Else, recursively check if its child nodes have a path that reaches the remaining sum
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

// Solution 2 (DFS Recursion) | O(n) time, O(n) space
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Return false if there are no more nodes on this path b/c there's no way to reach target sum
        if (root == nullptr) return false;
        
        // Initialize a stack with the root and target sum
        stack<pair<TreeNode*, int>> stack;
        stack.push({root, targetSum});
        
        // While the stack is not empty:
        while (!stack.empty()) {
            // Pop a node from the stack
            TreeNode* currNode = stack.top().first;
            int currTarget = stack.top().second;
            stack.pop();
            
            // If the node's value == remainingSum and it is a leaf node, return true
            if (currNode->val == currTarget && !currNode->left && !currNode->right) return true;
            
            // Else push the node's left and child nodes with the remaining sum
            if (currNode->left) stack.push({currNode->left, currTarget - currNode->val});
            if (currNode->right) stack.push({currNode->right, currTarget - currNode->val});
        }
            
        return false; // If execution reaches here, we did not find a root-to-leaf path for the sum
    }
};

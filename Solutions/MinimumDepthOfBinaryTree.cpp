// Leetcode #111: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Source: https://leetcode.com/problems/minimum-depth-of-binary-tree/discuss/36045/My-4-Line-java-solution
// Source: https://leetcode.com/problems/minimum-depth-of-binary-tree/discuss/36071/BFS-C%2B%2B-8ms-Beats-99.94-submissions

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

// Solution 1 (Recursive DFS) | O(n) space, O(n) time
// BFS is better b/c we can find the solution faster if one subtree has many nodes while the other doesn't
class Solution {
public:
    int minDepth(TreeNode* root) {
        // Min depth is 0 if the root is NULL
        if (root == nullptr) return 0;
        
        // Recursively return the min depth of the left and right subtrees
        // If one of the child nodes are null, then the shortest path uses the longer path (w/ the existing node). Else it uses the shorter path.
        // This prevents ending w/ a non-leaf node for the shortest path (ex. [1, null, 2, null]). It is fine if both are null b/c max(0, 0) = 0.
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return 1 + (left == 0 || right == 0 ? max(left, right) : min(left, right));
    }
};

// Solution 2 (Iterative BFS) 
class Solution {
public:
    int minDepth(TreeNode* root) {
        // Min depth is 0 if the root is null
        if (root == nullptr) return 0;
        
        // Initalize a queue with the root
        queue<TreeNode*> queue; 
        queue.push(root);
        
        int depth = 0; // Initialize depth counter with 0
        
        // While the queue is non-empty, search for the closest leaf node using BFS
        while (!queue.empty()) {
            depth++; // Increment depth counter
            
            // Loop through all the nodes of the current depth
            int numNodes = queue.size();
            for (int i = 0; i < numNodes; i++) {
                // Pop from the queue
                TreeNode* curr = queue.front();
                queue.pop();

                // If the node is a leaf node, return depth
                if (curr->left == nullptr && curr->right == nullptr) return depth;

                // Else push the child nodes on the queue, if they exist
                if (curr->left) queue.push(curr->left);
                if (curr->right) queue.push(curr->right);
            }
        }
        return -1; // Execution should never reach here b/c there has to be a leaf node
    }
};

// Solution 3 (Iterative DFS) | O(n)
class Solution {
public:
    int minDepth(TreeNode* root) {
        // Min depth is 0 if root is null
        if (root == nullptr) return 0;
        
        // Initialize a stack with the root and depth = 1
        stack<pair<TreeNode*, int>> stack;
        stack.push({root, 1});
        
        int minLeafDepth = INT_MAX; // Holds the min depth we've seen so far
        
        // While the stack is not empty:
        while (!stack.empty()) {
            // Pop from the stack
            pair<TreeNode*, int> curr = stack.top();
            TreeNode* currNode = curr.first;
            int currDepth = curr.second;
            stack.pop();
            
            // If it is a leaf node, update min depth
            if (currNode->left == nullptr && currNode->right == nullptr) minLeafDepth = min(minLeafDepth, currDepth);
            
            // If the node's depth + 1 > min depth, continue b/c it's child nodes won't have a smaller min depth
            if (currDepth + 1 > minLeafDepth) continue;
            
            // Else push the child nodes if they exist with current node's depth + 1
            if (currNode->left) stack.push({currNode->left, currDepth + 1});
            if (currNode->right) stack.push({currNode->right, currDepth + 1});
        }  
        
        return minLeafDepth; // Return the min depth
    }
};

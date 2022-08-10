// Leetcode #108: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Source: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/discuss/35220/My-Accepted-Java-Solution
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // If the array is empty, return NULL
        if (nums.size() == 0) return nullptr;
        
        // Return node from helper function with the first and last indices
        return helper(nums, 0, nums.size() - 1);
    }
    
    // Helper function that uses binary search to find the appropriate nodes for the binary tree 
    TreeNode* helper(vector<int>& nums, int left, int right) {
        // Return null if there are no valid indices
        if (left > right) return nullptr;
        
        // Create a root node with the value of nums[mid]
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively find root's child nodes
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        
        return root; // Return root
    }
};

// Solution 2 (Iterative with Stack) | O(n) time, O(n) space
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // If the array is empty, return NULL
        if (nums.size() == 0) return nullptr;
        
        // Create a stack to keep track of nodes and indices
        // Initialize head node with indices 0 and nums - 1
        stack<tuple<TreeNode*, int, int>> stack;
        TreeNode* head = new TreeNode();
        stack.push(make_tuple(head, 0, nums.size() - 1));
        
        // While the stack is not empty
        while (!stack.empty()) {
            // Pop from the stack
            tuple<TreeNode*, int, int> temp = stack.top();
            TreeNode* curr = get<0>(temp);
            int left = get<1>(temp), right = get<2>(temp);
            stack.pop();
            
            // Calculate the middle node using the indices
            int mid = left + (right - left) / 2;
            
            // Update current node's value
            curr->val = nums[mid];
            
            // If there are valid nodes for the left and right children, push them to the stack with updated indices
            if (left <= mid - 1) {
                curr->left = new TreeNode(0);
                stack.push(make_tuple(curr->left, left, mid - 1));
            }
            
            if (mid + 1 <= right) {
                curr->right = new TreeNode(0);
                stack.push(make_tuple(curr->right, mid + 1, right));
            }
        }
        
        return head; // Return head of BST
    }
};

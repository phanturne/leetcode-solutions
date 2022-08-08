// Leetcode #101:
// Source: https://leetcode.com/problems/symmetric-tree/discuss/33054/Recursive-and-non-recursive-solutions-in-Java/31849

// Solution 1 (Recursive): O(n) time, O(n) space
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root->left, root->right);
    }
  
    bool isSymmetricHelper(TreeNode* p, TreeNode* q) {
        // If both nodes are NULL, return true
        if (p == NULL && q == NULL) return true;
        
        // If only one node is NULL OR the nodes have different values, return false
        if (p == NULL || q == NULL || p->val != q->val) return false;
        
        // Recursively check if p's left subtree matches q's right subtree and vice versa
        return isSymmetricHelper(p->left, q->right) && isSymmetricHelper(p->right, q->left);
        
    }
};

// Solution 2 (Iterative w/ Stack): O(n) time, O(n) space
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // Empty tree is symmetric
        if (root == NULL) return true;
        
        // Stack is used to simulate recursion. Initialized w/ first 2 child nodes
        stack<TreeNode*> stack;
        stack.push(root->left);
        stack.push(root->right);
        
        // While the stack is not empty
        while (!stack.empty()) {
            // Pop the next two nodes from the stack
            TreeNode* p = stack.top();
            stack.pop();
            TreeNode* q = stack.top();
            stack.pop();
            
            // If both nodes are NULL, continue
            if (p == NULL && q == NULL) continue;
            
            // If only one node is NULL or the nodes have different values, return false
            if (p == NULL || q == NULL || p->val != q->val) return false;
            
            // Else, push p's left child with q's right child and vice versa
            stack.push(p->left);
            stack.push(q->right);
            stack.push(p->right);
            stack.push(q->left);
        } 
        
        return true; // Return true b/c everything matched
    }
};

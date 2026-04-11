class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
    
    bool validate(TreeNode* node, long low, long high) {
        if (!node) return true;
        
        // Current value must be strictly within bounds
        if (node->val <= low || node->val >= high)
            return false;
        
        // Left subtree: all values must be < node->val
        // Right subtree: all values must be > node->val
        return validate(node->left, low, node->val) &&
               validate(node->right, node->val, high);
    }
};

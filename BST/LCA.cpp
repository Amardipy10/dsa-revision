class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == NULL) {
            return NULL;
        }

        // If both nodes are smaller, go to left subtree
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // If both nodes are greater, go to right subtree
        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Otherwise, this is the split point (LCA)
        return root;
    }
};
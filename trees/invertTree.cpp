TreeNode* invertTree(TreeNode* root) {
    if (!root) return NULL;
    
    swap(root->left, root->right);  // Swap first
    invertTree(root->left);          // Then recurse
    invertTree(root->right);
    
    return root;
}

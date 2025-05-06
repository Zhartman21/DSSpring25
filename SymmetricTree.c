 bool isMirror(struct TreeNode* tree1, struct TreeNode* tree2){
        if(tree1 == NULL && tree2 == NULL ) return true;
        if(tree1 == NULL || tree2 == NULL ) return false;
        return (tree1->val == tree2->val) 
            && isMirror(tree1->left,tree2->right) 
            && isMirror(tree1->right, tree2->left);
}
bool isSymmetric(struct TreeNode* root) {
    if(root == NULL) return true;
    return isMirror(root->left, root->right);
    
}

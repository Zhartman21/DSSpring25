/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Function to count total nodes in the tree
int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void travel(struct TreeNode* root, int* ret, int* size) {
    if (!root) return;
    travel(root->left, ret, size); //visit left first
    ret[(*size)++] = root->val; //visit root
    travel(root->right, ret, size);//visit right last
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root); // dynamically set size of tree
    int* ret = (int*)malloc(*returnSize * sizeof(int)); //allocate

    int size = 0; // Actual tracking variable
    travel(root, ret, &size); //function call to rec fn
    return ret;
}

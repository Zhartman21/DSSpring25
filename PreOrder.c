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

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 100; // Initial preallocated space
    int* result = (int*)malloc(capacity * sizeof(int)); //allocate
    struct TreeNode** stack = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    int stackSize = 0, resultSize = 0;

    while (root || stackSize > 0) {
        while (root) {
            // Expand result array if needed
            if (resultSize >= capacity) {
                capacity *= 2;
                result = (int*)realloc(result, capacity * sizeof(int));
            }
            result[resultSize++] = root->val;

            // Push right child onto stack
            if (root->right) {
                stack[stackSize++] = root->right;
            }
            root = root->left;//push left to stack
        }

        if (stackSize > 0) {
            root = stack[--stackSize]; // Pop from stack
        }
    }

    free(stack);
    *returnSize = resultSize;
    return result;
}

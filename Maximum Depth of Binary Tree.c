/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL) {
        if (root->right == NULL) return 1;
        return maxDepth(root->right) + 1;
    }
    if (root->right == NULL) {
        return maxDepth(root->left) + 1;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    int result = 1;
    result += leftDepth>rightDepth? leftDepth:rightDepth;
    return result;
}
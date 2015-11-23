/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL) {
        if (root->right == NULL) return 1;
        return minDepth(root->right) + 1;
    }
    if (root->right == NULL) {
        return minDepth(root->left) + 1;
    }
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    int result = 1;
    result += leftDepth<rightDepth? leftDepth:rightDepth;
    return result;
}
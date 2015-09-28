/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void middleBST(struct TreeNode* root, int k, int* count, int* answer) {
    if (*count >= k) return;
    if (root == NULL) return;
    else {
        middleBST(root->left, k, count, answer);
        *count = *count + 1;
        if (*count == k) {
            *answer = root->val;
            return;
        }
        middleBST(root->right, k, count, answer);
    }
}
int kthSmallest(struct TreeNode* root, int k) {
    int* answer;
    int* count;
    *count = 0;
    *answer = 0;
    middleBST(root, k, count, answer);
    return *answer;
}
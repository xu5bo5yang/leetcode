/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool sameVal(struct TreeNode* l, struct TreeNode* r) {
    if (l == NULL) {
        if (r == NULL) return true;
        return false;
    }    
    if (r == NULL) return false;
    if (l->val != r->val) return false;
    return sameVal(l->left, r->right) && sameVal(l->right, r->left);
};

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    if (root->left == NULL) {
        if (root->right == NULL) return true;
        return false;
    }
    if (root->right == NULL) return false;
    return sameVal(root->left, root->right);
}
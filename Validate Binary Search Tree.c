/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root) {
    if (root==NULL) return true;
    struct TreeNode* bound;
    if (root->left!=NULL) {
        bound = root->left;
        while(bound->right!=NULL) {
            bound = bound->right;
        }
        if (bound->val >= root->val) return false;
    }
    if (root->right!=NULL) {
        bound = root->right;
        while(bound->left!=NULL) {
            bound = bound->left;
        }
        if (bound->val <= root->val) return false;
    }
    
    if(!isValidBST(root->left) || !isValidBST(root->right)) {
        return false;
    }
    return true;
}
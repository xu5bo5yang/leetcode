/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    if (root==NULL) return;
    struct TreeLinkNode* p;
    p = root;
    while (p!=NULL) {
        struct TreeLinkNode *q=p;
        while (q!=NULL) {
            if(q->left==NULL)   return;
            q->left->next=q->right;
            q->right->next= (q->next==NULL)? NULL:q->next->left;
            q=q->next;
        }
        p=p->left;
    }
}
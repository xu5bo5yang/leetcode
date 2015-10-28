/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* pre;
    struct ListNode* pos;
    struct ListNode* cur;
    if (head == NULL) return head;
    if (head->next == NULL) return head;
    pre = NULL;
    cur = head;
    pos = head->next;
    head = pos;
    while(cur!=NULL && cur->next!=NULL) {
        pos = cur->next;
        cur->next = pos->next;
        pos->next = cur;
        if (pre==NULL) head = pos;
        else {
            pre->next = pos;
        }
        pre = cur;
        cur = cur->next;
    }
    return head;
}
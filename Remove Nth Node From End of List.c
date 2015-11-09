/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* cur = head;
    struct ListNode* pre = head;
    struct ListNode* target = head;
    if (head == NULL) return NULL;
    if (head->next == NULL) return NULL;
    int i = 1;
    while(i < n) {
        cur = cur->next;
        i++;
    }
    while (cur->next != NULL) {
        cur = cur->next;
        pre = target;
        target = target->next;
    }
    if(target == head) {
        head = head->next;
        free(target);
        return head;
    }
    pre->next = target->next;
    free(target);
    return head;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) return NULL;
    struct ListNode* temp = NULL;
    struct ListNode home = {0, NULL};
    struct ListNode* pre = &home;
    while (head) {
        if (head->val == val) {
            temp = head;
            head = head->next;
            free(temp);
            continue;
        }
        pre->next = head;
        pre = head;
        head = head->next;
    }
    pre->next = NULL;
    return home.next;
}
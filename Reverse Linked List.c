/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* reversed = NULL;
    struct ListNode* temp = head;
    if (head == NULL || head->next == NULL) return head;
    while(head->next != NULL) {
        temp = head;
        head = head->next;
        temp->next = reversed;
        reversed = temp;
    }
    head->next = reversed;
    return head;
}
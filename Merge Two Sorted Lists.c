/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* temp;
    struct ListNode* answer;
    if (l1 == NULL) {
        return l2;
    }
    else if (l2 == NULL) {
        return l1;
    }
    else if (l1->val <= l2->val) {
        temp = l1;
        l1 = l1->next;
    }
    else {
        temp = l2;
        l2 = l2->next;
    }
    answer = temp;
    while (l1!=NULL && l2!=NULL) {
        if(l1->val <= l2->val) {
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }
        else {
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }
    }
    if (l1 != NULL) {
        temp->next = l1;
    }
    else {
        temp->next = l2;
    }
    return answer;
}
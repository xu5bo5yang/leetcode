/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
    int lenA = 0, lenB = 0;
    struct ListNode* pA = headA;
    struct ListNode* pB = headB;
    while (pA != NULL) {
        lenA++;
        pA = pA->next;
    }
    while (pB != NULL) {
        lenB++;
        pB = pB->next;
    }
    pA = headA;
    pB = headB;
    if (lenA > lenB) {
        for (int i = 0; i < lenA-lenB; i++) pA = pA->next;
    }
    else {
        for (int i = 0; i < lenB-lenA; i++) pB = pB->next;
    }
    while (pA != NULL && pB != NULL) {
        if (pA->val == pB->val) return pA;
        pA = pA->next;
        pB = pB->next;
    }
    return NULL;
}
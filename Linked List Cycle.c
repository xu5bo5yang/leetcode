/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* slow;
    struct ListNode* fast;
    
    if (head==NULL) return false;
    if (head->next==NULL) return false;
    slow = head;
    fast = head;
    
    while(slow!=NULL && fast!=NULL) {
        slow = slow->next;
        fast = fast->next;
        if (fast==NULL) break;
        fast = fast->next;
        if (fast==slow) break;
    }
    
    if (slow==NULL || fast==NULL) return false;
    return true;
}
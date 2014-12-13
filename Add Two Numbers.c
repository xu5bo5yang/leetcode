/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int flag=0;
        ListNode *current1=l1, *current2=l2;
        ListNode *temp;
        temp=new ListNode(0);
        if(l1==NULL){
            if(l2==NULL) return NULL;
            else return l2;
        }
        while(current1->next!=NULL){
            if(current2==NULL){ 
                if(flag==0) return l1;
                else{
                    while(flag==1){
                        if(current1->val+flag<10){
                            current1->val += flag;
                            flag=0;
                            return l1;
                        }
                        else{
                            current1->val += flag-10;
                            flag=1;
                            current1=current1->next;
                            if(current1->next==NULL){
                                if(current1->val+flag<10){
                                    current1->val += flag;
                                    flag=0;
                                    return l1;
                                }
                                else{
                                    current1->val += flag-10;
                                    flag=1;
                                    current1->next=new ListNode(1);
                                    return l1;
                                }
                            }
                        }
                    }
                }
            }
            if(current1->val+current2->val+flag<10) {
                current1->val += current2->val+flag;
                flag=0;
            }
            else{
                current1->val += current2->val+flag-10;
                flag=1;
            }
            current1=current1->next;
            current2=current2->next;
        }
        if(current2==NULL){
            if(flag==0) return l1;
            else{
                if(current1->val+flag<10){
                    current1->val++;
                    return l1;
                }
                else{
                    current1->val += flag-10;
                    current1->next = new ListNode(1);
                    return l1;
                }
            }
        }
        if(current1->val+current2->val+flag<10) {
                current1->val += current2->val+flag;
                flag=0;
        }
        else{
            current1->val += current2->val+flag-10;
            flag=1;
        }
        current2=current2->next;
        while(current2!=NULL){
            if(current2->val+flag<10) {
                current2->val += flag;
                flag=0;
                current1->next=current2;
            }
            else{
                current2->val += flag-10;
                flag=1;
                current1->next=current2;
            }
            current1=current1->next;
            current2=current2->next;
        }
        if(flag==1){
            current1->next=new ListNode(1);
        }
        return l1;
    }
};
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
struct hashT {
    int val;
    int count;
    struct hashT* next;
};

int* twoSum(int* nums, int numsSize, int target) {
    struct hashT hashTable[100000];
    int* answer = (int*)malloc(2*sizeof(int));
    answer[0] = 0;
    answer[1] = 0;
    if (nums == NULL || numsSize < 2) return NULL;
    int i;
    int j;
    for (i=0; i<100000; i++) {
        hashTable[i].val = -1;
        hashTable[i].count = 0;
        hashTable[i].next = NULL;
    }
    for (i=0; i<numsSize; i++) {
        if (nums[i] >= 0) {
            if (hashTable[nums[i]].val == -1) {
                hashTable[nums[i]].val = i+1;
                hashTable[nums[i]].count = 1;
            }
            else {
                hashTable[nums[i]].count++;
                struct hashT temp;
                struct hashT* head;
                temp.val = i+1;
                temp.next = NULL;
                head = hashTable[nums[i]].next;
                if (head == NULL) {
                    hashTable[nums[i]].next = &temp;
                    continue;
                }
                while (head->next != NULL) {
                    head = head->next;
                }
                head->next = &temp;
            }
        }
        else {
            if (hashTable[100000+nums[i]].val == -1) {
                hashTable[100000+nums[i]].val = i+1;
                hashTable[100000+nums[i]].count = 1;
            }
            else {
                hashTable[100000+nums[i]].count++;
                struct hashT temp;
                struct hashT* head;
                temp.val = i+1;
                temp.next = NULL;
                head = hashTable[100000+nums[i]].next;
                if (head == NULL) {
                    hashTable[100000+nums[i]].next = &temp;
                    continue;
                }
                while (head->next != NULL) {
                    head = head->next;
                }
                head->next = &temp;
            }
        }
    }
    for (i=0; i<numsSize; i++) {
        if (target-nums[i] == nums[i]) {
            if (hashTable[nums[i]].count < 2) continue;
            answer[0] = hashTable[nums[i]].val;
            answer[1] = hashTable[nums[i]].next->val;
            return answer;
        }
        else if (target-nums[i] >= 0){
            if (hashTable[target-nums[i]].val != -1){
                answer[0] = i+1;
                answer[1] = hashTable[target-nums[i]].val;
                return answer;
            }   
        }
        else {
            if (hashTable[100000+target-nums[i]].val != -1){
                answer[0] = i+1;
                answer[1] = hashTable[100000+target-nums[i]].val;
                return answer;
            }  
        }
    }
    return NULL;
}
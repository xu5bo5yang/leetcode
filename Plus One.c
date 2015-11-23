/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if (digits == NULL || digitsSize == 0) return NULL;
    int* result = (int*)malloc((digitsSize+1)*sizeof(int));
    int i;
    int flag;
    if (digits[digitsSize-1]+1 >= 10) {
        result[0] = digits[digitsSize-1] + 1 - 10;
        flag = 1;
    }
    else {
        result[0] = digits[digitsSize-1] + 1;
        flag = 0;
    }
    for (i=1; i<digitsSize; i++) {
        if (digits[digitsSize-i-1]+flag >= 10) {
            result[i] = digits[digitsSize-i-1] + flag - 10;
            flag = 1;
        }
        else {
            result[i] = digits[digitsSize-i-1] + flag;
            flag = 0;
        }
    }
    if (flag == 1) {
        result[i] = 1;
        *returnSize = digitsSize + 1;
    }
    else {
        *returnSize = digitsSize;
    }
    int* answer = (int*)malloc(*returnSize*sizeof(int));
    for (i=0; i<*returnSize; i++) {
        answer[i] = result[*returnSize-i-1];
    }
    return answer;
}
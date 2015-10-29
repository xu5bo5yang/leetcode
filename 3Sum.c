/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quickSort(int* a, int n) {
    int i, j, p, t;
    if (n < 2)
        return;
    p = a[n / 2];
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    quickSort(a, i);
    quickSort(a + i, n - i);    
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int** result;
    int total = 32;
    int number = 0;
    int i = 0;
    int j = 0;
    int start, end;
    int sum = 1;
    if (numsSize < 3) return NULL;
    quickSort(nums, numsSize);
    result = (int**)malloc(total*sizeof(int*));
    for (i=0; i<total; i++) {
        result[i] = (int*)malloc(3*sizeof(int));
    }
    for (i=0; i<numsSize-2; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        start = i + 1;
        end = numsSize - 1;
        while (start < end) {
            sum = nums[i] + nums[start] + nums[end];
            if (sum == 0) {
                if (number > 0 && nums[i] == result[number-1][0] && nums[start] == result[number-1][1] && nums[end] == result[number-1][2]) {
                    start++;
                    end--;
                    continue;
                }
                result[number][0] = nums[i];
                result[number][1] = nums[start];
                result[number][2] = nums[end];
                number++;
                if (number == total) {
                    total *= 2;
                    result = (int**)realloc(result, total*sizeof(int*));
                    for (int k=number; k<total; k++) {
                        result[k] = (int*)malloc(3*sizeof(int));
                    }
                }
                start++;
                end--;
            }
            else if (sum > 0) end--;
            else start++;
        }
    }
    *returnSize = number;
    return result;
}
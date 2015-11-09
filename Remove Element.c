int removeElement(int* nums, int numsSize, int val) {
    int i, j;
    int offset = 0;
    if (nums == NULL || numsSize == 0) return NULL;
    for (i=0; i<numsSize; i++) {
        if (nums[i] == val) {
            offset++;
            continue;
        }
        nums[i-offset] = nums[i];
    }
    numsSize -= offset;
    return numsSize;
}
void moveZeroes(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) return;
    int i, j, tmp;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            for (j = i+1; j < numsSize; j++) {
                if (nums[j] != 0) {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    break;
                }
            }
        }
    }
}
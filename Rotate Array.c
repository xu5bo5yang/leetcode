void reverse(int* nums, int n) {
    int temp = 0;
    for (int i = 0, j = n-1; i < j; i++, j--) {
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (nums == NULL) return;
    k = k % numsSize;
    reverse(nums, numsSize-k);
    reverse(nums+(numsSize-k), k);
    reverse(nums, numsSize);
}
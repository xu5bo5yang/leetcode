int removeDuplicates(int* nums, int numsSize) {
    
    if (numsSize<=1) return numsSize;
    
    int count = 1;
    int i;
    
    for (i=1; i<numsSize; i++) {
        if (nums[i] != nums[i-1]) {
            nums[count] = nums[i];
            count++;
        }
    }
    return count;
}
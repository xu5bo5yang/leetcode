int majorityElement(int* nums, int numsSize) {
    int result = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) result = nums[i];
        if (result == nums[i]) count++;
        else count--;
    }
    return result;
}
bool containsDuplicate(int* nums, int numsSize) {
    int hashmap[1000000] = {0};
    if (nums == NULL || numsSize == 0) return false;
    for (int i=0; i<numsSize; i++) {
        if (hashmap[nums[i]] > 0) return true;
        hashmap[nums[i]]++;
    }
    return false;
}
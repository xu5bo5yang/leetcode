void merge(int* nums1, int m, int* nums2, int n) {
    if (nums1 == NULL) {
        if (nums2 == NULL) return;
        nums1 = nums2;
        return;
    }
    if (nums2 == NULL) return;
    int i;
    for (i=m+n-1; i>=0; i--) {
        if (nums1[m-1]>nums2[n-1] && m>0 || n<=0) {
            nums1[i] = nums1[m-1];
            m--;
        }
        else {
            nums1[i] = nums2[n-1];
            n--;
        }
    }
}
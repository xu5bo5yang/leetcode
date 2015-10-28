double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    if (nums1Size == 0) {
        if (nums2Size == 0) return 0;
        else if (nums2Size%2==1) return nums2[nums2Size/2];
        else return (nums2[nums2Size/2-1]+nums2[nums2Size/2])/2.0;
    }
    else if (nums1Size == 1) {
        if (nums2Size == 1) return (nums1[0]+nums2[0])/2.0;
        if (nums2Size%2 == 1) {
            int mid = nums2Size / 2;
            if (nums1[0] <= nums2[mid - 1])
                return (nums2[mid - 1] + nums2[mid]) / 2.0;
            else if (nums1[0] > nums2[mid + 1])
                return (nums2[mid] + nums2[mid + 1]) / 2.0;
            else
                return (nums2[mid] + nums1[0]) / 2.0;
        }
        else {
            int leftmid = nums2Size / 2 - 1, rightmid = nums2Size / 2;
            if (nums1[0] <= nums2[leftmid])
                return nums2[leftmid];
            else if (nums1[0] > nums2[rightmid])
                return nums2[rightmid];
            else
                return nums1[0];
        }
    }
    else if (nums1Size%2 == 0) {
        if (nums2Size%2 == 1) {
            int nums2mid = nums2Size / 2;
            int nums1leftmid = nums1Size / 2 - 1;
            int nums1rightmid = nums1Size / 2;
            if (nums2[nums2mid] <= nums1[nums1leftmid])
                return findMedianSortedArrays(nums2 + nums1Size / 2, nums2Size - nums1Size / 2, nums1, nums1Size / 2);
            else if (nums2[nums2mid] > nums1[nums1rightmid])
                return findMedianSortedArrays(nums2, nums2Size - nums1Size / 2, nums1 + nums1Size / 2, nums1Size / 2);
            else
                return nums2[nums2mid];
        }
        else {
            int nums1leftmid = nums1Size / 2 - 1, nums1rightmid = nums1Size / 2;
            int nums2leftmid = nums2Size / 2 - 1, nums2rightmid = nums2Size / 2;
            if (nums1[nums1leftmid] > nums2[nums2leftmid] && nums1[nums1rightmid] > nums2[nums2rightmid])
                return findMedianSortedArrays(nums1, nums1Size / 2, nums2 + nums1Size / 2, nums2Size - nums1Size / 2);
            else if (nums1[nums1leftmid] <= nums2[nums2leftmid] && nums1[nums1rightmid] <= nums2[nums2rightmid])
                return findMedianSortedArrays(nums1 + nums1Size / 2, nums1Size / 2, nums2, nums2Size - nums1Size / 2);
            else if (nums1[nums1leftmid] > nums2[nums2leftmid] && nums1[nums1rightmid] <= nums2[nums2rightmid])
                return (nums1[nums1leftmid] + nums1[nums1rightmid]) / 2.0;
            else
                return (nums2[nums2leftmid] + nums2[nums2rightmid]) / 2.0;
        }
    }
    else {
        if (nums2Size%2 == 0) {
            int nums1mid = nums1Size / 2;
            int nums2leftmid = nums2Size / 2 - 1, nums2rightmid = nums2Size / 2;
            if (nums1[nums1mid] <= nums2[nums2leftmid])
                return findMedianSortedArrays(nums1 + nums1mid + 1, nums1Size / 2, nums2, nums2Size - nums1Size / 2 - 1);
            else if (nums1[nums1mid] > nums2[nums2rightmid])
                return findMedianSortedArrays(nums1, nums1Size / 2, nums2 + nums1Size / 2 + 1, nums2Size - nums1Size / 2 - 1);
            else
                return nums1[nums1mid];
        }
        else {
            int nums1mid = nums1Size / 2;
            int nums2mid = nums2Size / 2;
            if (nums1[nums1mid] < nums2[nums2mid])
                return findMedianSortedArrays(nums1 + nums1Size / 2, nums1Size / 2 + 1, nums2, nums2Size - nums1Size / 2);
            else 
                return findMedianSortedArrays(nums1, nums1Size / 2 + 1, nums2 + nums1Size / 2, nums2Size - nums1Size / 2);
        }
    }
}
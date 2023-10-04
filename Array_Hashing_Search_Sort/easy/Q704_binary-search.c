int search(int* nums, int numsSize, int target){
    int beg = 0;
    int end = numsSize - 1;
    int mid;
    while (beg <= end)
    {
        mid = (beg + end)/2;
        if (nums[mid] == target) return mid;

        if (target < nums[mid])
            end = mid - 1;
        else
            beg = mid + 1;
    }

    return -1;
}

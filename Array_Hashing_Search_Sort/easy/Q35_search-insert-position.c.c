int searchInsert(int* nums, int numsSize, int target){
    int beg = 0;
    int end = numsSize - 1;
    int mid = 0;
    while (beg <= end) 
    {
        mid = (beg + end)/2;

        if (nums[mid] == target) return mid;

        if (target < nums[mid]) {
            if ((mid-1 > 0) && (target > nums[mid - 1])) 
                return mid;
            else if (mid-1 < 0) return 0;
            else 
                end = mid - 1;
        }
        else { //target > nums[mid]
            if ((mid+1) < numsSize && (target < nums[mid + 1])) 
                return mid+1;
            else if ((mid+1) > numsSize)
                return mid+1;
            else 
                beg = mid+1;
        }
    }
    return mid + 1; //keeping it mid+1 is important, otherwise for case 3 it will return last index rather than index+1
}

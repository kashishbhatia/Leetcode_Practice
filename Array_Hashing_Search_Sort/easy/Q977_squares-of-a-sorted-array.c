/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    //int *res = (int *) malloc(numsSize);
    //int *res = malloc(numsSize);  //NOTE : it is failing because numsSize can range from -10^4 to +10^4. Total 20000 elems which can case heap overflow. Try out merge sort
    int res[numsSize];
    int l = 0;
    int r = numsSize - 1;
    int i;
    for(i = numsSize-1; i>=0; i--)
    {
        if (abs(nums[l]) > abs(nums[r]))
        {
            res[i] = nums[l] * nums[l];
            l++;
        }
        else {
            res[i] = nums[r] * nums[r];
            r--;
        }
    }
    *returnSize = numsSize;
    for (i =0; i<numsSize; i++) nums[i] = res[i];
    return nums;
}

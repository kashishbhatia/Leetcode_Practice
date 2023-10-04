//solution 1 : using hashmap but it would use O(n) space

int removeDuplicates(int* nums, int numsSize){

//ALgo :
//1. when ever a unique number is found, fix an index say j on that
//2. Keep traversing the sorted array until elem is not same as jth elem
//3. When found a new elem at i, shift this new elem from ith to (j+1)th index
//4. And move j to i now // j = i
//5. on finding every new unique elem, keep incrementing k

//.   0 1.  2. 3. 4. 5. 6  7. 8. 9. 10 11
//Ex: 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2
//i is just incrementing at evenry index
//ptr is 0, then its puts nums[4] to nums[ptr=1] and then nums[8] to nums[ptr=2]
// after shifting j points to 4 and then 8

    int i=0;
    int j = 0, ptr = 0;  // ptr is index of shrink array, j is index of repeated subarray
    int k=1;

    for (i = 1; i< numsSize; i++) {
        if (nums[i] != nums[j]) {

            // do the processing
            ptr++;
            nums[ptr] = nums[i];
            j=i;
            k++;
        }
    }
    return k;


}

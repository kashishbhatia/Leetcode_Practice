

int removeElement(int* nums, int numsSize, int val){
    int k = 0; //final valid nums length
    int i; //iterator
    int j; //points to index that has the 'val'
    int cntVal = 0; //cnt of val found
    int found = 0; //control movement of j
    for (i=0; i< numsSize; i++) {
        if (nums[i] == val) {
            if (found) {
                cntVal++;
                continue;   //do not move j
            } else {
                j = i;  //fixing j to val's index
                found=1;
                cntVal++;
            }
        } else if (nums[i] != val && found) {
            nums[j] = nums[i];
            j++; k++;
            //cntVal--;
            //if (cntVal == 0)
            //    found = 0;
        } else {
            k++;
        }
    }
    return k;
}


#if 0
/* Unefficient */
int removeElement(int* nums, int numsSize, int val){
    int k = 0; //final valid nums length
    int i; //iterator
    int j; //points to index that has the 'val'

    for (i=0; i< numsSize; i++) {
        if (nums[i] == val) {
            j = i+1;
            while(nums[j] != val) {
                nums[i] = nums[j];
                i++; j++; k++;
            }
        } else {
            k++;
        }
    }
    return k;
}
#endif

//Hint : use two pointer approach

//This works but in O(N^2)

#if 0
void moveZeroes(int* nums, int numsSize){
    int i, j, cntZeroes = 0;

    for (i=0; i<numsSize; i++) {
        if (nums[i] == 0) {
           for (j = i; j < numsSize; j++) {
               nums[j] = nums[j+1];
           }
           cntZeroes++; 
        }
    }

    while (cntZeroes) {
        nums[numsSize-cntZeroes] = 0;
        cntZeroes--;
    }
}
#endif


/* 
Above ALgo : 
- take 2 ptrs i and j
- i points to 0 value,
- j seraches for 1st non zero value
- then j shifts the value until i
- i resets to += 1
- j resets to i+1 // one ahead i
*/

#if 0
void moveZeroes(int* nums, int numsSize){
    int i, j, k;

    //count zeroes
    int cntZeroes = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            cntZeroes++;
            for (j = i; j < numsSize; j++) {
                if (nums[j] != 0) {
                    nums[i] = nums[j];  //some more cycles saved but still o(n^2)
                } else {
                    cntZeroes++;
                }
            } 
        }
    }

    while (cntZeroes) {
        nums[numsSize-cntZeroes] = 0;
        cntZeroes--;
    } 
}
#endif

void moveZeroes(int* nums, int numsSize){
    int i, k=0;
    int cntZeroes = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            
            cntZeroes++;
        } else {
            nums[k] = nums[i];
            k++;
        }
    }

    while (cntZeroes) {
        nums[numsSize-cntZeroes] = 0;
        cntZeroes--;
    }  

}



// Approach: Swapping 
void moveZeroes(int* nums, int numsSize) {
    int j = 0; //'j' is the index of last non-zero element 
    
for (int i = 0; i < numsSize; i++) {
        // if, any non-zero element has found swap with the previous value...
        if (nums[i] != 0) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
}
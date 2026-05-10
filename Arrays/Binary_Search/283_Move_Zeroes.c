// Approach: Swapping
void moveZeroes(int* nums, int numsSize) {
    int j = 0; //j->Last non-zero element found at 'j'th index
   
for (int i = 0; i < numsSize; i++) {
      // if, any non-zero element has found swap with the previous one --
        
         if (nums[i] != 0) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
}
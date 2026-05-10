// Slow-Fast Pointer Approach >>
int removeDuplicates(int* nums, int numsSize) {
    int i = 0, k = 0; // Here, k->Slow and i->Fast
    while (i < numsSize) {
        if (nums[k] != nums[i]) {
            k++;
            nums[k] = nums[i];
        }
        i++;
    }
    return (k + 1); //'k+1' is the no. of first unique elements 
}
// Approach: Index based Binary Search 
// Assumed that I'm at before the answer 
// Always try to find out even-odd combination 

int singleNonDuplicate(int* nums, int numsSize) {
    int start = 0, end = numsSize - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

  // Ensure mid points to first index of a pair
        if (mid % 2 == 1) mid--;

        if (nums[mid] == nums[mid + 1]) {
            start = mid + 2;
        } else {
            end = mid;
        }
    }
    return nums[start];
}
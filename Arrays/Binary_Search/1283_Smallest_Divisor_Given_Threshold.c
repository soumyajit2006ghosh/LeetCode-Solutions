//Approach: Value based Binary Search

int largest(int* nums, int numsSize) {
    int max = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max)
            max = nums[i];
    }
    return max;
}

int smallestDivisor(int* nums, int numsSize, int threshold) {
    int start = 1, end = largest(nums, numsSize);
    int sum, ans = -1;
   
    while (start <= end) {
        int mid = start + (end - start) / 2;
        sum = 0; // Resets sum for every iteration
       
        for (int i = 0; i < numsSize; i++) {
            sum += (nums[i] + mid - 1) / mid;
            if (sum > threshold)
                break;
        }
       
        // If, current mid is valid--
        if (sum <= threshold) {
            ans = mid;
            end = mid - 1; // Go to left for smaller value
        }
        // If, current mid is invalid--
        else
            start = mid + 1; // Go to right for bigger value
    }
    return ans;
}

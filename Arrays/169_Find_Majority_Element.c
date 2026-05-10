/* Approach: Traverse the whole array and track occurences of every unique element */

int majorityElement(int* nums, int numsSize) {
    int ans = nums[0], appear = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == ans)
            appear++;
        else {
            appear--;
            if (appear == 0) {
                ans = nums[i];
                appear = 1;
            }
        }
    }
    return ans;
}
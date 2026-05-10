// Approach: Index based Binary Search 
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = { -1, -1 };

        //Seraching for the 1st occurrence...
        int start = 0, end = nums.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans[0] = mid;
                end = mid - 1;
            } else if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        //if, first occurrence is not found that means the target element doesn't exist. So, skips the next operation.
        if (ans[0] == -1) 
            return ans;

        //Seraching for the 2nd occurrence...
        start = 0; 
        end = nums.length - 1; //Resetting 'start' and 'end' for 2nd operation.
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans[1] = mid;
                start = mid + 1;
            } else if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        
        return ans;
    }
}

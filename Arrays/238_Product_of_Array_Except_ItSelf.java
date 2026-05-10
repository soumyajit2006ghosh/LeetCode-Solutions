/* Approach >>
1. Calculate product for the previous elements and next elements separately
2. Combine two products */

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];

        // Calculating Prefix (Previous Product) --
        ans[0] = 1; // Prefix of 0th element = 1

        for (int i = 1; i < n; i++) {
            // Storing prefix directly in ans[i]
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Calculating Suffix (Post Product) --
        int suffix = 1;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;

            // Updating suffix for next iteration
            suffix *= nums[i];
        }

        return ans;
    }
}
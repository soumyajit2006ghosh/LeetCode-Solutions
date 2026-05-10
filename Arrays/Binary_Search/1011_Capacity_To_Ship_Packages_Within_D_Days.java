//Approach: Value based Binary Search
class Solution {
    public int largest(int[] arr) {
        int max = arr[0];
        for (int num : arr) {
            if (num > max)
                max = num;
        }
        return max;
    }

    public int sum(int[] arr) {
        int result = arr[0];
        for (int num : arr) {
            result += num;
        }
        return result;
    }

    public boolean isCapable(int[] weights, int Capacity, int given_Days) {
        int used_Days = 1, current_Load = 0;
       
        for (int i = 0; i < weights.length; i++) {
            if (current_Load + weights[i] <= Capacity)
                current_Load += weights[i];
            else {
                used_Days++;
                current_Load = weights[i];
                if (used_Days > given_Days)
                    return false;
            }
        }
        return true;
    }

    public int shipWithinDays(int[] weights, int days) {
        int start = largest(weights), end = sum(weights);
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isCapable(weights, mid, days)) {
                ans = mid;
                end = mid - 1;
            } else
                start = mid + 1;
        }
        return ans;
    }
}

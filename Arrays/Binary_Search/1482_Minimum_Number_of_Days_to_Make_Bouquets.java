//Approach: Value based Binary Search
class Solution {
    public static int smallest(int[] arr) {
        int min = arr[0];
        for (int num : arr) {
            if (num < min) {
                min = num;
            }
        }
        return min;
    }

    public static int largest(int[] arr) {
        int max = arr[0];
        for (int num : arr) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }

    public static boolean isEnough(int[] bloomDay, int current_Days, int k, int m) {

        int bouquets = 0, flowers = 0;
        for (int i = 0; i < bloomDay.length; i++) {
            if (bloomDay[i] <= current_Days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                    if (bouquets == m) {
                        return true;
                    }
                }
            } else {
                flowers = 0;
            }
        }
        return false;
    }

    public int minDays(int[] bloomDay, int m, int k) {

        int start = smallest(bloomDay), end = largest(bloomDay);
        int ans = -1;
        //If, 'n' is lesser than total no. of flowers required 
        if (m > 0 && bloomDay.length < m * k) {
            return ans;
        }

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isEnough(bloomDay, mid, k, m)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
}

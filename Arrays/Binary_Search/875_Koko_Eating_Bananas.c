// Approach: Value based Binary Search 
// TC: O(n log m)

// Finds the pile with maximum bananas--
int largest(int piles[], int size) {
    int max = piles[0];
    for (int i = 1; i < size; i++) {
        if (piles[i] > max)
            max = piles[i];
    }
    return max;
}
// Calculates total hours needed for a given eating speed k
long long calculate_Time(int piles[], int size, int k) {
    long long hours = 0;
    for (int i = 0; i < size; i++) {
        hours += (piles[i] + k - 1) / k;
        // If remainder exists, add one extra hour
    }
    return hours;
}
int minEatingSpeed(int* piles, int pilesSize, int h) {
    int start = 1, end = largest(piles, pilesSize);
    int ans = 0;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        long long required_Hours = calculate_Time(piles, pilesSize, mid);

        if (required_Hours <= h) {
            ans = mid;
            end = mid - 1; // Move to left half
        } else {
            start = mid + 1; // Move to right half
        }
    }
    return ans; // The minimum eating speed (Bananas per hour)
}

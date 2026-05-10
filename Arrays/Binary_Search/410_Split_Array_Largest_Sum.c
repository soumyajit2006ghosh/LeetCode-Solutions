//Approach: Value based Binary Search
int maxElement(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}
int total(int arr[], int size) {
    int sum = arr[0];
    for (int i = 1; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
bool isValid(int arr[], int size, int largestSum, int k) {
    int member = 1, currentSum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > largestSum)
            return false;

        if (currentSum + arr[i] <= largestSum) {
            currentSum += arr[i];
        } else {
            member++;
            currentSum = arr[i];
        }

        if (member > k)
            return false;
    }
    return true;
}

int splitArray(int* nums, int numsSize, int k) {
    int start = maxElement(nums, numsSize), end = total(nums, numsSize);
    int ans = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isValid(nums, numsSize, mid, k)) {
            ans = mid;
            end = mid - 1;
        } else
            start = mid + 1;
    }
    return ans;
}

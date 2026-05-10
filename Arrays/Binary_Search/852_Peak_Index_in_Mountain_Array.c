// Approach: Index based Binary Search

int peakIndexInMountainArray(int* arr, int arrSize) {
    int start = 1, end = arrSize - 2, peak;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid; //As, mid is the Peak.
     
    //if, the peak exists in left side--
        else if (arr[mid] < arr[mid - 1]) 
            end = mid - 1;
    //if, the peak exists in right side--
        else  
            start = mid + 1;
    }
    return -1;
}
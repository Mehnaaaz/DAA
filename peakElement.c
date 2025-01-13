#include <stdio.h>

// Function to find a peak element using binary search
int findPeakElement(int arr[], int low, int high, int n) {
    int mid = low + (high - low) / 2;

    // Check if mid is a peak element
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
        return mid;
    }

    // If the left neighbor is greater, search in the left half
    if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return findPeakElement(arr, low, mid - 1, n);
    }

    // Otherwise, search in the right half
    return findPeakElement(arr, mid + 1, high, n);
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = findPeakElement(arr, 0, n - 1, n);
    printf("A peak element is at index %d with value %d\n", peakIndex, arr[peakIndex]);

    return 0;
}

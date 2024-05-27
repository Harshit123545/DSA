#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if the element is present at mid
        if (arr[mid] == x)
            return mid;
        
        if (arr[mid] < x)
            low=mid+1;
        else
            high=mid-1;
    }
    
    // Element is not present in array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40 , 70 , 80};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int x = 70; // The element to search for
    int result = binarySearch(arr, 0, n - 1, x);
    
    if (result != -1)
        printf("Element is present at index %d\n", result);
    else
        printf("Element is not present in array\n");
    return 0;
}
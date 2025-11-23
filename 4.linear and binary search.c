#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int n = 5;
    int key = 20;

    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\nSearching for: %d\n", key);

    int linPos = linearSearch(arr, n, key);
    int binPos = binarySearch(arr, n, key);

    printf("\nLinear Search Result:\n");
    if (linPos != -1)
        printf("Element found at index %d\n", linPos);
    else
        printf("Element not found\n");

    printf("\nBinary Search Result:\n");
    if (binPos != -1)
        printf("Element found at index %d\n", binPos);
    else
        printf("Element not found\n");

    printf("\nTime Complexity Comparison:\n");
    printf("Linear Search: O(n)\n");
    printf("Binary Search: O(log n)\n");

    return 0;
}

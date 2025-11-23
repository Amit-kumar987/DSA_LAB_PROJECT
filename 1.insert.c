#include <stdio.h>

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert(int arr[], int *n, int pos, int value) {
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    (*n)++;
}

void deleteElement(int arr[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

int main() {
    int arr[100] = {10, 20, 30};
    int n = 3;

    printf("Initial List: ");
    display(arr, n);

    insert(arr, &n, 1, 50);
    printf("After Insertion: ");
    display(arr, n);

    deleteElement(arr, &n, 2);
    printf("After Deletion: ");
    display(arr, n);

    return 0;
}

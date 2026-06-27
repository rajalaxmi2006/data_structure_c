#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int low, int high) {
    int pivot = A[low];
    int start = low; 
    int end = high; 

    while(start < end) { 
        while(A[start] <= pivot) { 
            start++; 
        }
        while(A[end] > pivot) { 
            end--; 
        }
        if(start < end) { 
            swap(&A[start], &A[end]); 
        }
    }
    swap(&A[low], &A[end]); 
    return end;
}

void quick_sort(int A[], int low, int high) {
    if(low >= high) { 
        return; 
    }
    int pivot_index = partition(A, low, high); 
    quick_sort(A, low, pivot_index - 1); 
    quick_sort(A, pivot_index + 1, high); 
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n] ,i;
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
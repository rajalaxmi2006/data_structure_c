#include <stdio.h>

void conquer(int A[], int low, int mid, int high) {
    int temp[high - low + 1];
    int first = low;
    int second = mid + 1;
    int third = 0;

    while(first <= mid && second <= high) {
        if(A[first] < A[second]) {
            temp[third] = A[first];
            third++;
            first++;
        }
        else {
            temp[third] = A[second];
            third++;
            second++;
        }
    }

    while(first <= mid) {
        temp[third] = A[first];
        third++;
        first++;
    }

    while(second <= high) {
        temp[third] = A[second];
        third++;
        second++;
    }

    for(int index = 0; index <= high - low; index++) {
        A[low + index] = temp[index];
    }
}

void merge_sort(int A[], int low, int high) {
    if(low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(A, low, mid);
    merge_sort(A, mid + 1, high);
    conquer(A, low, mid, high);
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n] , i;
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int lb = 0, ub = n - 1;

    while(lb <= ub) {
        int mid = (lb + ub) / 2;

        if(key == arr[mid]) {
            return mid;
        }
        else if(key < arr[mid]) {
            ub = mid - 1;
        }
        else {
            lb = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n, key;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int pos = binarySearch(arr, n, key);

    if(pos!= -1) {
        printf("Element found at pos = %d\n", pos + 1);
    }
    else {
        printf("not found\n");
    }

    return 0;
}
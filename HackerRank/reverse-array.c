#include <stdio.h>

int main() {
    int size;
    // printf("Enter size of array:");
    scanf("%d", &size);

    int i, arr[size];
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    return 0;
}
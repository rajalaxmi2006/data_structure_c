#include <stdio.h>

void linearSearch(int arr[], int n, int key) {
    int index;
    for(index = 0; index < n; index++) {
        if(key == arr[index]) {
            printf("found\n");
            return;
        }
    }
    printf("not found\n");
}

int main() {
    int n, key;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n],i;
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    linearSearch(arr, n, key);
    return 0;
}
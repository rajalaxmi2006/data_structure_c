#include <stdio.h>

void selectionSort(int array[], int n) {
    int outer, inner, minIndex, temp;

    for(outer = 0; outer <= n - 2; outer++) {
        minIndex = outer;
        for(inner = outer + 1; inner <= n - 1; inner++) {
            if(array[inner] < array[minIndex]) {
                minIndex = inner;
            }
        }
        if(outer!= minIndex) {
            temp = array[minIndex];
            array[minIndex] = array[outer];
            array[outer] = temp;
        }
    }
}

int main() {
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);

    int array[n],i;
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    selectionSort(array, n);

    printf("Selection Sorted array: ");
    for( i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
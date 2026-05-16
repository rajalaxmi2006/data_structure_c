#include <stdio.h>

void insertionSort(int array[], int n) {
    int outer, inner, temp;

    for(outer = 1; outer <= n - 1; outer++) {
        temp = array[outer];
        inner = outer - 1;

        while(inner >= 0 && array[inner] > temp) {
            array[inner + 1] = array[inner];
            inner = inner - 1;
        }
        array[inner + 1] = temp;
    }
}

int main() {
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);

    int array[n], i;
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    insertionSort(array, n);

    printf("Insertion Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
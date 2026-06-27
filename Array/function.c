//1. No return type, no arguments
#include <stdio.h>
void linearSearch(void);
int main() {
    linearSearch();
    return 0;
}

void linearSearch() {
    int n, key;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int i = 0;
    while(i < n) {
        if(arr[i] == key) {
            printf("Key element = %d found\n", key);
            return;
        }
        i = i + 1;
    }
    printf("Not found\n");
}

/*
Output:
Enter array size: 5
Enter 5 elements:[1 ,2 ,3, 4, 5]
Enter element to search: 3
Output:Key element = 3 found
*/

//2. No return type, with arguments
#include <stdio.h>
void linearSearch(int *,int ,int);
int main() {
    int n, key;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    linearSearch(arr, n, key);
    return 0;
}
void linearSearch(int arr[], int n, int key) {
    int i = 0;
    while(i < n) {
        if(arr[i] == key) {
            printf("Key element = %d found\n", key);
            return;
        }
        i = i + 1;
    }
    printf("Not found\n");
}

/*
Output:
Enter array size: 4
Enter 4 elements:[7,8,9,10]
Enter element to search: 2
Output:Not found
*/

//3. Return type, no arguments
#include <stdio.h>
int linearSearch(void);
int main() {
    int result = linearSearch();
    if(result == 1){ 
        printf("Key element found\n");
    }else{
        printf("Not found\n");
    }
        return 0;
}
int linearSearch() {
    int n, key;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int i = 0;
    while(i < n) {
        if(arr[i] == key) {
            return 1; // found
        }
        i = i + 1;
    }
    return 0; // not found
}

/*
Output:
Enter array size: 3
Enter 3 elements:[5, 6, 7, 8, 9, 10]
Enter element to search: 6
Output:Key element found
*/

//4. Return type, with arguments
#include <stdio.h>
int linearSearch(int *, int , int);
int main() {
    int n, key;
    printf("Enter array size: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = linearSearch(arr, n, key);
    if(result == 1){
        printf("Key element found\n");
    }else{
        printf("Not found\n");
    }
    return ;
}
int linearSearch(int arr[], int n, int key) {
    int i = 0;
    while(i < n) {
        if(arr[i] == key) {
            return 1; // found
        }
        i = i + 1;
    }
    return 0; // not found
}

/*
Output:
Enter array size: 6
Enter 6 elements:[2 ,4 ,6 ,8 ,10 ,12]
Enter element to search: 5
Output:Not found
*/
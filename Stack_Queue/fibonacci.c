#include <stdio.h>
int fibonacci(int);

int main(
    int n, i;
    printf("Enter number of Terms":);
    scanf(%d,&n);

    printf("Fibonacci Series: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }
)

int fibonacci(int n){
    if(n == 1){
        return 0;
    } else 
    if(n == 2){
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
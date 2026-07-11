#include <stdio.h>
int factorial(int);
int main(){
    int n,x;
    printf("Enter any number:");
    scanf("%d",&n);
    x=factorial(n);
    printf("%d",x);   
}
int factorial(int n) {
    int f = 1;
    if (n > 0) {
        f = f * n;
        n--;
        f = f * factorial(n);
    }
    return f;
}
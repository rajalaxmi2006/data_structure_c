#include"stdio.h"
void TOH(int n, char src, char aux, char dest)
{
        if(n == 1)
        {
                printf("Move disk 1 from %c to %c\n", src,dest);
        }
        else
        {
                TOH(n-1,src,dest,aux);
                printf("Move disk %d from %c to %c\n",n,src,dest);
                TOH(n-1,aux,src,dest);
        }
}
int main()
{
        int n;
        printf("Enter the number of disks:");
        scanf("%d",&n);
        TOH(n,'src','aux','dest');
        return 0;
}
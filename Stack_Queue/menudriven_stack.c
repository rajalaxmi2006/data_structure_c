#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

// Function declarations
void push();
void pop();
void peek();
void display();

// Global variables
int stack[SIZE];
int top = -1;

int main()
{
    int choice;
    do
    {
        printf("\n\t\tSTACK MENU\n");
        printf("\t\t==========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 0:
                printf("\nExiting...!!!\n");
                break;

            default:
                printf("\nInvalid Choice...!!!\n");
        }

    }while(choice != 0);
    return 0;
}

// Function Definitions
void push()
{
    int data;
    printf("Enter the data : ");
    scanf("%d", &data);

    if(top == SIZE - 1)
    {
        printf("Stack Overflow");
        return;
    }
    else{
        top = top + 1;
        stack[top] = data;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow");
        return;
    }
    else
    {
       top = top - 1; 
    }
}

void peek()
{
    if(top == -1)
    {
        printf("Stack is Empty");
        return;
    }
    else
    {
        return stack[top];
    }
}
void display()
{
    if(top == -1)
    {
        printf("Stack is Empty");
        return;
    }
}
    printf("Stack Elements are :");
    int i;
    for(i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
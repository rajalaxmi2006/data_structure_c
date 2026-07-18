#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int Q[SIZE];
int front = -1, rear = -1;

// 1. Enqueue
void enqueue(int data) {
    if(front==(rear+1) % SIZE) {
        printf("Overflow: Queue is Full\n");
        return;
    }
    else if(front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        Q[rear] = data;
    }
    else {
        rear = (rear + 1) % SIZE ;
        Q[rear] = data;
    }
    printf("%d inserted\n", data);
}

// 2. Dequeue
void dequeue() {
    if(front == -1 && rear == -1) {
        printf("Underflow: Queue is Empty\n");
        return;
    }
    else if(front == rear) {
        printf("%d deleted\n", Q[front]);
        front = -1;
        rear = -1;
    }
    else {
        printf("%d deleted\n", Q[front]);
        front = (front + 1) % SIZE ;
    }
}

// 3. Traverse
int i;
void traverse() {
    if(front == -1 && rear == -1) {
        printf("Empty Queue\n");
        return;
    }

    printf("Queue elements: ");
    for(i = front; ; i=(i+1)SIZE) {
        printf("%d ", Q[i]);
        if (i==rear)
            break;
    }
    printf("\n");
}

int main() {
    int choice, data;

    do {
        printf("\n------ MENU ------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                traverse();
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0;
}
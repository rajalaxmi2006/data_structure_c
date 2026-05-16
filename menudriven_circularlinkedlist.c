#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *Head = NULL;

struct Node* CreateNode() {
    struct Node *newnode;
    newnode = (struct Node *) malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

int countNode(struct Node *Head) {
    int count = 0;
    struct Node *temp = Head;

    if(Head == NULL)
        return 0;

    do {
        count++;
        temp = temp->next;
    } while(temp != Head);

    return count;
}

void CreateList() {
    int ch;
    struct Node *newnode, *temp;

    Head = NULL;

    do {
        newnode = CreateNode();

        if(Head == NULL) {
            Head = temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
        newnode->next=Head;
        printf("Enter 1 to continue & 0 to stop: ");
        scanf("%d", &ch);

    } while(ch);

    printf("Circular linked list created successfully\n");
}

void Traverse() {
    struct Node *temp = Head;

    if(Head == NULL) {
        printf("The list is empty\n");
        return;
    }

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != Head);

    printf("\n");
}
void InsertAtBeginning() {
    struct Node *newnode, *temp;
    newnode = CreateNode();
    if(Head == NULL) {
        Head = newnode;
        newnode->next = Head;
    }
    else {
        temp = Head;
        while(temp->next != Head) {
            temp = temp->next;
        }
        newnode->next = Head;
        Head = newnode;
        temp->next = Head;
    }
}
void InsertAtEnd() {
    struct Node *newnode, *temp;
    newnode = CreateNode();
    if(Head == NULL) {
        Head = newnode;
        newnode->next = Head;
    }
    else {
        temp = Head;
        while(temp->next != Head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = Head;
    }
}
void InsertAtPosition() {
    int pos, count, i;
    struct Node *newnode, *temp;

    printf("Enter position: ");
    scanf("%d", &pos);

    count = countNode(*Head);
    if(pos >= 1 && pos <= count + 1) {
        newnode = CreateNode();
        if(pos == 1) {
            if(Head == NULL) {
                Head = newnode;
                newnode->next = Head;
            }
            else {
                temp = Head;
                while(temp->next != Head) {
                    temp = temp->next;
                }
                newnode->next = Head;
                Head = newnode;
                temp->next = Head;
            }
        }
        else {
            temp = Head;
            for(i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    else {
        printf("Invalid position\n");
    }
}

void DeleteAtBeginning() {
    struct Node *temp, *last;

    if(Head == NULL) {
        printf("List is empty\n");
    }
    else if(Head->next == Head) {
        free(Head);
        Head = NULL;
    }
    else {
        temp = Head;
        last = Head;

        while(last->next != Head) {
            last = last->next;
        }

        Head = Head->next;
        last->next = Head;

        free(temp);
    }
}

void DeleteAtEnd() {
    struct Node *prev, *temp;

    if(Head == NULL) {
        printf("List is empty\n");
    }
    else if(Head->next == Head) {
        free(Head);
        Head = NULL;
    }
    else {
        prev = NULL;
        temp = Head;

        while(temp->next != Head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = Head;

        free(temp);
    }
}

void DeleteAtPosition() {
    int pos, count, i;
    struct Node *temp, *ptr, *last;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(Head == NULL) {
        printf("List is empty\n");
        return;
    }

    count = countNode(Head);

    if(pos >= 1 && pos <= count) {

        if(pos == 1) {

            if(Head->next == Head) {
                free(Head);
                Head = NULL;
            }
            else {
                temp = Head;
                last = Head;

                while(last->next != Head) {
                    last = last->next;
                }

                Head = Head->next;
                last->next = Head;

                free(temp);
            }
        }
        else {
            temp = Head;

            for(i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }

            ptr = temp->next;
            temp->next = ptr->next;

            free(ptr);
        }
    }
    else {
        printf("Invalid position\n");
    }
}

int Search(int key) {
    int pos = 1;
    struct Node *temp = Head;

    if(Head == NULL) {
        printf("Empty list\n");
        return 0;
    }

    do {
        if(key == temp->data) {
            return pos;
        }

        temp = temp->next;
        pos++;

    } while(temp != Head);

    return -1;
}

void Reverse() {
    struct Node *prev, *current, *next, *last;

    if(Head == NULL || Head->next == Head) {
        return;
    }

    prev = NULL;
    current = Head;
    last = Head;

    while(last->next != Head) {
        last = last->next;
    }

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    } while(current != Head);

    Head->next = prev;
    Head = prev;
    last->next = Head;

    printf("List reversed successfully\n");
}

int main() {
    int choice, key, result;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Create a list\n");
        printf("2. Traverse from left to right\n");
        printf("3. Traverse from right to left\n");
        printf("4. Insert at beginning\n");
        printf("5. Insert at end\n");
        printf("6. Insert at any position\n");
        printf("7. Delete at beginning\n");
        printf("8. Delete at end\n");
        printf("9. Delete at any position\n");
        printf("10. Searching\n");
        printf("11. Reverse\n");
        printf("12. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                CreateList();
                break;

            case 2:
                Traverse_L2R();
                break;

            case 3:
                if(Head == NULL) {
                    printf("The list is empty\n");
                }
                else {
                    printf("Right to Left: ");
                    Traverse_R2L(Head);
                    printf("\n");
                }
                break;

            case 4:
                InsertAtBeginning();
                break;

            case 5:
                InsertAtEnd();
                break;

            case 6:
                InsertAtPosition();
                break;

            case 7:
                DeleteAtBeginning();
                break;

            case 8:
                DeleteAtEnd();
                break;

            case 9:
                DeleteAtPosition();
                break;

            case 10:
                printf("Enter element to search: ");
                scanf("%d", &key);

                result = Search(key);

                if(result == 0) {
                    printf("\n");
                }
                else if(result == -1) {
                    printf("Element not found\n");
                }
                else {
                    printf("Element found at position %d\n", result);
                }

                break;

            case 11:
                Reverse();
                break;

            case 12:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice! Try again\n");
        }

    } while(choice != 12);

    return 0;
}
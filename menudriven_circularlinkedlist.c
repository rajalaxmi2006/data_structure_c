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
    if (Head == NULL)
        return 0;
    else
        return 1 + countNode(Head->next);
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
    printf("List created successfully\n");
}

void Traverse() {
    struct Node *temp = Head;
    if(Head == NULL) {
        printf("The list is empty\n");
        return;
    }
    else {
        do{
            printf("%d ", temp->data);
            temp = temp->next;
          }while(temp != NULL) 
        printf("\n");
    }
}

void InsertAtBeginning() {
    struct Node *newnode;
    newnode = CreateNode();
    
    if(Head == NULL) {
        Head = newnode;
    }
    else {
        newnode->next = Head;
        Head = newnode;
    }
}

void InsertAtEnd() {
    struct Node *newnode, *temp;
    newnode = CreateNode();
    if(Head == NULL) {
        Head = newnode;
    }
    else {
        temp = Head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void InsertAtPosition() {
    int pos, count, i;
    struct Node *newnode, *temp;
    
    printf("Enter position: ");
    scanf("%d", &pos);
    
    count = countNode(Head);
    
    if (pos >= 1 && pos <= count + 1) {
        newnode = CreateNode();
        if (pos == 1) {
            if (Head == NULL) {
                Head = newnode;
            }
            else {
                newnode->next = Head;
                Head = newnode;
            }
        }
        else {
            temp = Head;
            for (i = 1; i < pos - 1; i++) {
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
    struct Node *temp;
    if(Head == NULL) {
        printf("List is empty\n");
    }
    else {
        temp = Head;
        Head = Head->next;
        free(temp);
    }
}

void DeleteAtEnd() {
    struct Node *prev, *temp;
    if(Head == NULL) {
        printf("List is empty\n");
    }
    else {
        prev = NULL;
        temp = Head;
        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if(prev == NULL) {
            Head = NULL;
        }
        else {
            prev->next = NULL;
        }
        free(temp);
    }
}

void DeleteAtPosition() {
    int pos, count, i;
    struct Node *temp, *ptr;
    
    printf("Enter position: ");
    scanf("%d", &pos);
    
    if(Head == NULL) {
        printf("List is empty\n");
        return;
    }
    else {
        count = countNode(Head);
        if(pos >= 1 && pos <= count) {
            if(pos == 1) {
                temp = Head;
                Head = Head->next;
                free(temp);
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
}

int Search(int key) {
    int pos = 1;
    struct Node *temp = Head;
    
    if(Head == NULL) {
        printf("Empty list");
        return 0;
    }
    
    while(temp != NULL) {
        if(key == temp->data) {
            return pos;
        }
        else {
            temp = temp->next;
            pos = pos + 1;
        }
    }
    return -1;
}

void Reverse() {
    struct Node *PrevNode = NULL, *CurrentNode, *NextNode;
    
    CurrentNode = NextNode = Head;
    
    while(NextNode != NULL) {
        NextNode = NextNode->next;
        CurrentNode->next = PrevNode;
        PrevNode = CurrentNode;
        CurrentNode = NextNode;
    }
    
    Head = PrevNode;
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
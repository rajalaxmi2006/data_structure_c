#include <stdio.h>
#define MAX_BOOKS 100

typedef struct
{
    int bookId;
    char bookTitle[50];
    char bookAuthor[60];
    int pubYear;
    int bookAvailability;
} Book;

void addBook(Book books[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\nStart adding books\n");

        printf("Enter the Book ID: ");
        scanf("%d", &books[i].bookId);

        printf("Enter the Book Title: ");
        scanf(" %49[^\n]", books[i].bookTitle);

        printf("Enter the name of the author: ");
        scanf(" %59[^\n]", books[i].bookAuthor);

        printf("Enter the publication year: ");
        scanf("%d", &books[i].pubYear);

        printf("Press ->[1]<- if the book is available else ->[0]<-: ");
        scanf("%d", &books[i].bookAvailability);
    }
}

void bookDisplay(Book books[], int n)
{
    if (n <= 0)
    {
        printf("\nNo books available!\n");
        return;
    }

    printf("\n\nBook's details showing..\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nBook %d\n", i + 1);
        printf("The Book ID is: %d\n", books[i].bookId);
        printf("The Book Title is: %s\n", books[i].bookTitle);
        printf("The name of the book author is: %s\n", books[i].bookAuthor);
        printf("The year of publication of the book is: %d\n", books[i].pubYear);

        if (books[i].bookAvailability == 1)
        {
            printf("Status: Book is available!\n\n");
        }
        else if (books[i].bookAvailability == 0)
        {
            printf("Status: Book is not available!\n\n");
        }
        else
        {
            printf("Status: Invalid entry!!\n\n");
        }
    }
}

void displayMenu()
{
    printf("\n\nStudent Library Management System\n");

    printf("\t1. Add Book\n");
    printf("\t2. Display Book\n");
    printf("\t3. Update Book\n");
    printf("\t4. Delete Book\n");
    printf("\t5. Search Book\n");
    printf("\t6. Issue Book\n");
    printf("\t7. Return Book\n");
    printf("\t8. Exit\n");
}

int main()
{
    Book books[MAX_BOOKS];
    int choice;
    int n = 0;

    do
    {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the number of books: ");
                scanf("%d", &n);

                /* Corrected condition */
                if (n > 0 && n <= MAX_BOOKS)
                {
                    addBook(books, n);
                    printf("Books have been added.\n");
                }
                else
                {
                    printf("Enter a valid number of books!\n");
                    n = 0;
                }
                break;

            case 2:
                bookDisplay(books, n);
                break;

            case 3:
                printf("Books updated\n");
                break;

            case 4:
                printf("Book deleted\n");
                break;

            case 5:
                printf("Book searched\n");
                break;

            case 6:
                printf("Book issued\n");
                break;

            case 7:
                printf("Book returned\n");
                break;

            case 8:
                printf("Exit\n");
                break;

            default:
                printf("Try again!!\n");
        }

    } while (choice != 8);

    return 0;
}
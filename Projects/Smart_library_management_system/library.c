//  Write a menudriven program to create smart library management system..
// Implement these menus
//     1. ADD Book
//     2. DISPLAY Book 
//     3. UPDATE Book
//     4. DELETE Book
//     5.SEARCH Book
//     6. ISSUE Book
//     7.RETURN Book

#include"stdio.h"
#define MAX_BOOKS 100

typedef struct 
{
    int bookId;
    char bookTitle[50];
    char bookAuthor[60];
    int pubYear;
    int bookAvailability; 
}Book;



void addBook(Book books[], int n)
{
    for(int i=0; i<n; i++){
    printf("\n\nStart adding books\n");
    printf("enter the Book ID: ");
    scanf("%d",&books[i].bookId);
    printf("enter the book title: ");
    scanf("%s[^\n]",books[i].bookTitle);
    printf("enter the name of the author: ");
    scanf("%s[^\n]", books[i].bookAuthor);
    printf("enter the publication year: ");
    scanf("%d", &books[i].pubYear);
    printf("press ->[1]<- if the book is available else ->[0]<-: ");
    scanf("%d", &books[i].bookAvailability);
    // b->bookAvailability  =  1;
    }

}


void bookDisplay(Book books[], int n)
{

    printf("\n\nBook's details showing..\n");
    for(int i=0; i<n; i++)
    {
        printf("\nBook%d\n", i+1);
        printf("The Book ID is: %d\n", books[i].bookId);
        printf("The Book Title is: %s\n", books[i].bookTitle);
        printf("The name of the book author is: %s\n", books[i].bookAuthor);
        printf("The year of publication of the book is: %d\n", books[i].pubYear);

        if(books[i].bookAvailability == 1)
        {
            printf("status: book is available!\n\n");
        }else if(books[i].bookAvailability == 0)
        {
            printf("status: book is not available!\n\n");
        }
        else{
            printf("status: invalid entry!!\n\n");
        }

    }
}

void displayMenu()
{
    printf("\n\n Student library management system\n");

    printf("\t1.Add Book\n");
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
    int choice,n;
    do{
    displayMenu();

    printf("enter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("enter the  numbers of the books: ");
            scanf("%d", &n);
            if(n>0 || n<=MAX_BOOKS)
            {
                addBook(books, n);    
            }else{
                printf("enter the number of the books in a valid number!");
            }
        
            printf("Books has been added\n");
            break;
        case 2:
            bookDisplay(books,n); 
            printf("Books has been displayed\n");
            break;
        case 3:
            printf("books updated\n");
            break;
        case 4:
            printf("Book deleted\n");
            break;
        case 5:
            printf("Book searched\n");
            break;
        case 6:
            printf("book issued\n");
            break;
        case 7:
            printf("book returned\n");
            break;
        case 8:
            printf("exit\n");
            break;
        default:
            printf("try again guysss!!\n");    
    }

    }while(choice!=8);
}
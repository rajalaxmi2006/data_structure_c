//smart library management system
/*
    1. Add Book
    2. Display Book
    3. Update Book
    4. Delete Book
    5. Search Book
    6. Issue Book
    7. Return Book
    8. Exit
*/


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
    }

}

void bookDisplay(Book books[], int n)
{

    printf("\n\nBook's details showing\n");
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
void sort(Book b[],int n)
{
	int i,j;
	Book temp;
	for(i=0;i<n;i++)
		for(j=0;j<n-1-i;j++)
			if(b[j].bookId > b[j+1].bookId)
			{
				temp=b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
			}
}
int searchBooks(Book b[],int n,int key){
	int i;
	for(i=0; i<n; i++)
		if(b[i].bookId==key)
            return i;
	return -1;
}


void displayMenu()
{
    printf("\n\n Student library management system\n");

    printf("\t1. Add Book\n");
    printf("\t2. Display Book\n");
    printf("\t3. sort Books\n");
    printf("\t4. Update Book\n");
    printf("\t5. Delete Book\n");
    printf("\t6. Search Book\n");
    printf("\t7. Issue Book\n");
    printf("\t8. Return Book\n");
    printf("\t9. Exit\n");


}



int main()
{
    Book books[MAX_BOOKS];
    int choice,n;
    do{
    displayMenu();

    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("Enter the  numbers of the books: ");
            scanf("%d", &n);
            if(n>0 || n<=MAX_BOOKS)
            {
                addBook(books, n);
            }else{
                printf("Enter the number of the books in a valid number!");
            }
            printf("Books has been added\n");

            break;
        case 2:
            bookDisplay(books,n);
            printf("Books has been displayed\n");
            break;
	case 3:
		int i;
		sort(books,n);
		for(i=0;i<n;i++)
			printf("%d %s\n",books[i].bookId,books[i].bookTitle);
		return 0;
        case 4:
            printf("books updated\n");
            break;
        case 5:
            printf("Book deleted\n");
            break;
        case 6:
            int key,pos;
		printf("enter the id of the book: ");
		scanf("%d",&key);
		pos = searchBooks(books,n,key);
		if(pos!=-1)
			printf("found: %d - %s\n",books[pos].bookId,books[pos].bookTitle);
		else			printf("book not found");
		return 0;
        case 7:
            printf("book issued\n");
            break;
        case 8:
            printf("book returned\n");
            break;
        case 9:
            printf("exit\n");
            break;
        default:
            printf("try again guysss!!\n");    
    }

    }while(choice!=8);
}

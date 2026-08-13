//  Write a menudriven program to create smart library management system..
// Implement these menus
//     1. ADD Book
//     2. DISPLAY Book 
//     3. UPDATE Book
//     4. DELETE Book
//     5.SEARCH Book
//     6. ISSUE Book
//     7.RETURN Book
//     8. EXIT

#include <stdio.h>

void displayMenu()
{
    printf("\n\t====\n");
    printf("\tMENU");
	printf("\n\t====\n");

    	printf("1. Add Book\n");
		printf("2. Display Book\n");
		printf("3. Update Book\n");
		printf("4. Delete Book\n");
		printf("5. Search Book\n");
		printf("6. Issue Book\n");
		printf("7. Return Book\n");
		printf("8. Exit\n");
}

int main()
{
    int choice;

    do{
        displayMenu();

        printf("Enter your Choice:");
        scanf("%d",  &choice);

        switch(choice)
        {
                case 1:
                    printf("Book Added Successfully\n");
                    break;
                case 2:
                    printf("Display Books\n");
                    break;
                case 3:
                    printf("Book Update Successfully\n");
                    break;
                case 4:
                    printf("Book Deleted Successsfully\n");
                    break;
                case 5:
                    printf("Book Search Successfully\n");
                    break; 
                case 6:
                    printf("Book Issued sucessfully\n");
                    break;
                case 7:
                    printf("Book returnd successfully\n");
                    break;
                case 8:
                    printf("Thank You for visiting LIT Smart Library\n");
                    break;
                default:
                    printf("Invalid Choice! Please try again.. \n"); 
            }
    }while(choice != 8);

    return 0;
}

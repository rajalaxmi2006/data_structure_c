
/*
	Write a menudriven program in C to implement
	all the following operations on an array :
		1. create an array.
		2. display.
		3. traverse from right to left.
		4. insert at beginning.
		5. insert at end.
		6. insert at any position.
		7. delete at beginning.
		8. delete at end.
		9. delete at any position.
		10.linear search.
		11.exit.
*/
#include"stdio.h"
#include"stdlib.h"
#define MAX 100

// function declarations
void init();
void display();
void traverse_right_to_left();
void insert_at_beginning();
void insert_at_end();
void insert_at_any_position();
void delete_at_beginning();
void delete_at_end();
void delete_at_any_position();
void linear_search();

// global vairables
int array[MAX];
int size = 0;

int main()
{
	init(); // create_array();
	
	int choice;
	do
	{
		printf("\n\t\tMENU\n");
		printf("\t\t====\n");
		printf("1. dispaly.\n");
		printf("2. traverse from right to left\n");
		printf("3. insert at beginning.\n");
		printf("4. insert at end.\n");
		printf("5. insert at any position.\n");
		printf("6. delete at beginning.\n");
		printf("7. delete at end.\n");
		printf("8. delete at any position.\n");
		printf("9. linear search\n");
		printf("0. exit\n");
		
		printf("\nEnter your choice :");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				display();
				break;
			case 2:
				traverse_right_to_left();
				break;
			case 3:
				insert_at_beginning();
				break;
			case 4:
				insert_at_end();
				break;
			case 5:
				insert_at_any_position();
				break;
			case 6:
				delete_at_beginning();
				break;
			case 7:
				delete_at_end();
				break;
			case 8:
				delete_at_any_position();
				break;
			case 9:
				linear_search();
				break;
			case 0:
				printf("\n\nExiting ... !!!\n");
				break;
			default :
				printf("\nInvalid Choice ... !!!\n");
		}
		
	}while(choice != 0);
}

// function definations
void init() // void create_array()
{
	printf("Enter the number of the elements :");
	scanf("%d", &size);

	if(size <= 0)
	{
		printf("\nInvalid Size.\n");
		exit(1);
	}
	printf("Enter the array elements :");
	int index;
	for(index=0; index<size; index++)
		scanf("%d", &array[index]);

	printf("\nArray Initialised Successfully.\n");
}

void display()	// traverse the array from left to right
{
	if(size == 0)
	{
		printf("\nThe array is Empty.\n");
		return ;
	}
	printf("Here is the array elements :");
	int index;
	for(index=0; index<size; index++)
		printf("%d ", array[index]);
	printf("\n\n");
}
void traverse_right_to_left()
{
	if(size == 0)
	{
		printf("\nThe array is Empty.\n");
		return ;
	}
	printf("Here is the array elements :");
	int index;
	for(index=size-1; index>=0; index--)
		printf("%d ", array[index]);
	printf("\n\n");
}
void insert_at_beginning()
{
	if(size == MAX)
	{
		printf("\nThe array is already full.\n");
		return ;
	}
	size ++;
	int shift;
	for(shift=size-2; shift>=0; shift--)
		array[shift+1] = array[shift];
	printf("Enter the data :");
	scanf("%d", &array[0]);
	printf("\nElement inserted successfully.\n");
}
void insert_at_end()
{
	if(size == MAX)
	{
		printf("\nThe array is already full.\n");
		return ;
	}
	
	size ++;
	printf("Enter the data :");
	scanf("%d", &array[size-1]);	
	printf("\nElement inserted successfully.\n");
}
void insert_at_any_position()
{
	if(size == MAX)
	{
		printf("\nThe array is already full.\n");
		return ;
	}	
	int position;
	printf("Enter the position :");
	scanf("%d", &position);

	if(position > size || position < 1)
	{
		printf("\nInvalid Position.\n");
		return ;
	}	
	else if(position == 1)
	{
		insert_at_beginning();
		return ;
	}
	else if(position == size)
	{
		insert_at_end();
		return ;
	}
	
	size ++;
	int shift;
	for(shift=size-2; shift>=position-1; shift--)
		array[shift+1] = array[shift];

	printf("Enter the data :");
	scanf("%d", &array[position-1]);

	printf("\nElement inserted successfully.\n");
}
void delete_at_beginning()
{
	if(size == 0)
	{
		printf("\nArray is already empty.\n");
		return ;
	}
	int temp = array[0];
	int shift;
	for(shift=1; shift<size; shift++)
		array[shift-1] = array[shift];
	size --;
	printf("\n%d deleted successfullly.\n", temp);
}
void delete_at_end()
{
	if(size == 0)
	{
		printf("\nArray is already empty.\n");
		return ;
	}	
	int temp = array[size-1];
	size --;
	printf("\n%d deleted successfullly.\n", temp);
}
void delete_at_any_position()
{
	if(size == 0)
	{
		printf("\nArray is already empty.\n");
		return ;
	}
	
	int position;
	printf("Enter the position :");	
	scanf("%d", &position);

	if(position < 1 || position > size)
	{
		printf("\nInvalid Position\n.");
		return ;
	}
	else if(position == 1)
	{
		delete_at_beginning();
		return ;
	}
	else if(position == size)
	{
		delete_at_end();
		return ;
	}

	int shift, temp = array[position - 1];
	for(shift=position; shift<size; shift++)
		array[shift-1] = array[shift];

	size --;
	printf("\n%d deleted successfullly.\n", temp);
}
void linear_search()
{
	int key,i;
	printf("enter the key value: \n");
	scanf("%d",&key);
	for(i=0;i<size;i++)
	{
		if(key==array[i])
		{
		printf("\n element found at index: %d",i);
		printf("\n element found at position:  %d",i+1); // i+1 for position.
		return;
		}
	}
	printf("\n element not found\n");
//	return 0;
}
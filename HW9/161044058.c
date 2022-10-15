#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 25

struct person
{
	char name[40] ;
	char surname[40];
	char musical_Work[40];
	int age;

	struct person *next;
} *top;



void addNode(char name[], char surname [], char creation [], int age);
void delete_node();
void Sort_Alphabetically();
void Sort_Increasingly();
void main_sort_function_alphabetic(struct person **head, struct person *new_node);
void main_sort_function_numeric(struct person **head, struct person *new_node);
void print_stack();
void star_function();
void dash_function();
void menu();

int main(void) 
{

	menu(top);

    return 0;
}


void addNode(char name[], char surname [], char creation [], int age)
{
	//Firstly I declare the temporary struct
	struct person *p ;
	p = (struct person *)malloc( sizeof (struct person) );

	//Fill the temporary struct
	strcpy(p->name,name);
	strcpy(p->surname,surname);
	strcpy(p->musical_Work,creation);
	p->age = age;

	//And temporary->next is equal to list and list is equal to temporary
	//Forexample list = "a-b-c" , temporary = "d-Null" | First address of list copy the temporary null element and
	// new list will be "d-a-b-c".
	
	if (top == NULL)
	{
		top = p;
		top->next = NULL;

	}
	else
	{
		p->next = top;
		top = p;	
	}
	
}

void delete_node()
{
	//Firstly I make a temp list 'p' and assigned 'list' of address to 'p'
	struct person *p = top;

	//List is empty the function is ended or first of list element is deleted
	if(top == NULL)
	{
		printf("The list is also empty !\n");
		return ;
	}

	top=top->next;

	free(p);

}

void main_sort_function_alphabetic(struct person **head, struct person *new_node)
{
	struct person *temp_node = NULL;

	//The two elements are just sorting or If top is null the function will be return new top(top = head)
	if(*head == NULL || strcmp(new_node->name,(*head)->name) < 0 )
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

   	temp_node = *head;

	//Tour the list one by one
   	while(temp_node->next != NULL && strcmp(new_node->name,(*head)->name) > 0)
    {
        temp_node = temp_node->next;
    }

	//Adds the new node by checking the last added button.
    new_node->next = temp_node->next;
    temp_node->next = new_node;   

}

void main_sort_function_numeric(struct person **head, struct person *new_node)
{
	struct person *temp_node = NULL;

	//If top is null the function will be return new top(top = head)
	if(*head == NULL || new_node->age < (*head)->age )
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }


	temp_node = *head;

	//Tour the list one by one
   	while(temp_node->next != NULL && new_node->age > (*head)->age)
    {
        temp_node = temp_node->next;
    }
	

	//Adds the new node by checking the last added button.
    new_node->next = temp_node->next;
    temp_node->next = new_node;   

}

void Sort_Alphabetically()
{

	//Firstly I make three temp list 'temp1'and 'temp2' and 'new top'
	struct person *new_top = NULL;
	struct person *temp ;
	struct person *temp1 = NULL;

	temp=top;


	if (top == NULL)
	{
		printf("The list is also empty !\n");
		return ;
	}
	//Tour the list one by one
    while(temp != NULL)
    {
        temp1 = temp;
        temp = temp->next;

		//The nodes in the list are broken. And the list is added back to the list so that it stays in order.
		//Kind of like creating a new list
        main_sort_function_alphabetic(&new_top, temp1);
    }

    top = new_top;

}

void Sort_Increasingly()
{
	//Firstly I make three temp list 'temp1'and 'temp2' and 'new top'
	struct person *new_top = NULL;
	struct person *temp ;
	struct person *temp1 = NULL;

	temp=top;


	if (top == NULL)
	{
		printf("The list is also empty !\n");
		return ;
	}
	//Tour the list one by one
    while(temp != NULL)
    {
        temp1 = temp;
        temp = temp->next;

		//The nodes in the list are broken. And the list is added back to the list so that it stays in order.        
		//Kind of like creating a new list		
		main_sort_function_numeric(&new_top, temp1);
    }

    top = new_top;

}

void print_stack(struct person *top)
{
	struct person *temp ;
	temp = top;

	for(int i = 1; temp != NULL ; ++i, temp=temp->next)
	{
		printf("%d-)",i);
		printf("%s\n",temp->name );
		printf("%s\n",temp->surname );
		printf("%s\n",temp->musical_Work );
		printf("%d\n",temp->age );
	}
}



void dash_function()
{
	for (int i = 0; i < 17; ++i)
	{
		printf("-");
	}
}

void star_function()
{
	for (int i = 0; i < 17; ++i)
	{
		printf("*");
	}
}

void menu()
{
	int select;
	char name[SIZE],surname[SIZE],musical_Work[SIZE];
	int age;

	struct person *fre;

	top = NULL;

	do
	{
		printf("**** M E N U ****\n");
		printf("    1- Add a Person to the Stack\n");
		printf("    2- Pop a Person from the Stack\n");
		printf("    3- Sort Alphabetical Order\n");
		printf("    4- Sort Age in Increasing Order\n");
		printf("    5- Exit Menu\n");
		star_function();

		printf("\n\nSelect Your Choice: ");
		scanf("%d",&select);
		printf("\n");

		switch(select)
		{
			case 1:
				printf("Name: ");
				scanf(" %[^\n]s",name);
				printf("Surname: ");
				scanf(" %[^\n]s",surname);
				printf("Creation: ");
				scanf(" %[^\n]s",musical_Work);
				printf("Age: ");
				scanf("%d",&age);
				addNode(name,surname,musical_Work,age);
				dash_function();
				printf("\n");
				print_stack(top);
				printf("\n\n");
			break;
			case 2:
				printf("Deleting the one person...\n");
				delete_node();
				dash_function();
				printf("\n");
				print_stack(top);
				printf("\n\n");
			break;
			case 3:
				printf("Alphabetic sort...\n");
				Sort_Alphabetically();
				dash_function();
				printf("\n");
				print_stack(top);
				printf("\n\n");
			break;
			case 4:
				printf("Age sort...\n");
				Sort_Increasingly();
				dash_function();
				printf("\n");
				print_stack(top);
				printf("\n\n");
			break;
			case 5:
				printf("Closing the program...\n");
			break;
			default:
				printf("This is not true choice !\n");
			break;
		}


	}while(select != 5);

	while ( top != NULL )
	{
		fre = top;
		top = top->next;
		free(fre);
	}

}



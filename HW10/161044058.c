#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define SIZE 20     // A R R A Y  S I Z E 


typedef struct stack
{
	int data;

	struct stack *next;
}stack;

typedef struct queue
{
	int data;

	struct queue *next;
}queue;

typedef struct bst
{
	int data;

	struct bst *right,*left;
}bst;

void fill_stack(stack **stack_,int data);
void fill_queue(queue **queue_,int data);
bst * fill_bst(bst *bst_,int data);
void fill_structures(stack **stack_, queue **queue_, bst **bst_,int data[]);

void print_bst(bst *bst);
void print_stack(stack *stack_);
void print_queue(queue *queue_);
void ordered_print(stack * stack_, queue * queue_, bst * bst_);

void search_stack(stack * stack_,int search);
void search_queue(queue * queue_,int search);
int search_bst(bst * bst_,int search,int counter);
void search(stack * stack_, queue * queue_, bst * bst_, int val_to_search);

void traverse_stack(stack *stack_);
void traverse_queue(queue *queue_);
int find_the_minimum_value(bst *bst_,int current_minimum_value);
int find_the_maximum_value(bst *bst_,int current_maximum_value);
void traverse_bst(bst *bst_);
void special_traverse(stack * stack_, queue * queue_, bst * bst_);

int main()
{
	int data[SIZE]={5, 2, 7, 8, 11, 3, 21, 7, 6, 15, 19, 35, 24, 1, 8, 12, 17, 8, 23, 4};	

	bst * bst_ = NULL;
	queue * queue_ = NULL;
	stack * stack_ = NULL;

	
	fill_structures(&stack_,&queue_,&bst_, data);
	ordered_print(stack_, queue_, bst_);
	search(stack_, queue_, bst_, 8);
	special_traverse(stack_, queue_, bst_);
	printf("\n");
	return 0;
}

void fill_stack(stack **stack_,int data)
{
	stack *temp;

	temp = (struct stack*)malloc(sizeof(stack));


	//Stack fill
	temp->data = data;
	temp->next = *stack_;
	*stack_ = temp;

}

void fill_queue(queue **queue_,int data)
{
	queue *temp;

	if (*queue_ == NULL)
	{
		temp = (queue *) malloc(sizeof(queue));
		temp->data = data;
		*queue_ = temp;
		(*queue_)->next = NULL;
		return;
	}
	for (temp = *queue_; temp->next != NULL; temp = temp->next);

	temp->next = (queue *) malloc(sizeof(queue));
	temp = temp->next;
	temp->data = data;
	temp->next = NULL;

}

bst * fill_bst(bst *bst_,int data)
{

	if(bst_ == NULL)
	{
		bst *temp = (struct bst*)malloc(sizeof(bst));
		temp->data = data;
		temp->left = NULL;
		temp->right =NULL;
		return temp;
	}
	//If the data is small put left
	else if(bst_->data > data)
	{
		bst_->left = fill_bst(bst_->left,data);
		return bst_;
	}
	//Return data if data is equal
	else if (bst_->data == data)
	{
		return bst_;
	}
	//If the data is large put right	
	else
	{
		bst_->right = fill_bst(bst_->right,data);
		return bst_;
	}	
}

void fill_structures(stack **stack_, queue **queue_, bst **bst_,int data[])
{
	int i;
	clock_t start,end;
	double cpu_time_used;
	int size;

	//Array elements are sent to the filling functions in sequence.

	//Stack fill
	start = clock();

	for( i=0 ; i < SIZE ; ++i)
	{
		fill_stack(&(*stack_),data[i]);
	}

	end = clock();

	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC*1000;
	printf("Stack Fill Time:%.2f\n",cpu_time_used );

	//Queue fill
	start = clock();

	for( i=0 ; i < SIZE ; ++i)
	{
		fill_queue(&(*queue_),data[i]);
	}
	
	end = clock();
	
	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC*1000;
	printf("Queue Fill Time:%.2f\n",cpu_time_used );
	
	
	//Bst fill
	start = clock();
	
	for( i=0 ; i < SIZE ; ++i)
	{
		*(bst_) = fill_bst(*bst_,data[i]);
	}
	
	end = clock();
	
	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC*1000;
	printf("BST Fill Time:%.2f\n",cpu_time_used );

	printf("\n");
}

void print_bst(bst *bst)
{

	if (bst == NULL)
	{
		return;
	}

	//Print BST inorder method
	print_bst(bst->right);
	printf("%d ",bst->data);
	print_bst(bst->left);
}


void print_stack(stack *stack_)
{
	int max,max_temp,temper,counter;
	int i;
	stack *temp;

	//Search max element
	for ( temp = stack_, max = 0; temp != NULL ; temp = temp->next)
	{
		if (max < temp->data)
		{
			max = temp->data;
		}
	}
	printf("%d ",max );

	for (i = 0; i < SIZE-1; ++i)
	{
		for(temp = stack_ ,max_temp = 0,counter = 0,temper = 0; temp != NULL ; temp = temp->next)
		{
			//if max is equal to data
			if (max == temp->data)
			{
				//Counter is a tool used to print elements with more than one element.
				counter++;
				if (counter>1)
				{
					printf("%d ",max);
				}
			}
			//I've used temper to keep small maxes from max.
			else if (temp->data < max && temper < temp->data)
			{
				temper = temp->data;
			}

		}
		if (temper == 0)
		{
			break;
		}
		max = temper;
		printf("%d ",max );
	}
}

void print_queue(queue *queue_)
{
	int max,max_temp,temper,counter;
	int i;
	queue *temp;

	for ( temp = queue_, max = 0; temp != NULL ; temp = temp->next)
	{
		if (max < temp->data)
		{
			max = temp->data;
		}
	}
	printf("%d ",max );

	for (i = 0; i < SIZE-1; ++i)
	{
		for(temp = queue_ ,max_temp = 0,counter = 0,temper = 0; temp != NULL ; temp = temp->next)
		{

			//if max is equal to data
			if (max == temp->data)
			{
				//Counter is a tool used to print elements with more than one element.
				counter++;
				if (counter>1)
				{
					max = temp->data;
					printf("%d ",max);
				}
			}
			//I've used temper to keep small maxes from max.
			else if (temp->data < max && temper < temp->data)
			{
				temper = temp->data;
			}

		}
		if (temper == 0)
		{
			break;
		}
		max = temper;
		printf("%d ",max );
	}	
}

void ordered_print(stack * stack_, queue * queue_, bst * bst_)
{
	clock_t start,end;
	double cpu_time_used;

	//STACK
	start = clock();

	printf("Stact Ordered: ");
	print_stack(stack_);

	end = clock();

	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC*1000;
	printf("\nStack Ordered Time:%.2f\n\n",cpu_time_used );

	//QUEUE
	start = clock();

	printf("Queue Ordered: ");
	print_queue(queue_);

	end = clock();

	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC*1000;
	printf("\nQueue Ordered Time:%.2f\n\n",cpu_time_used );

	//BST
	start = clock();

	printf("Binary Struct Tree Ordered: ");
	print_bst(bst_);

	end = clock();

	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC*1000;
	printf("\nBST Ordered Time:%.2f\n\n",cpu_time_used );

}

void search_stack(stack * stack_,int search)
{

	int i,j;

	printf("On ");
	for( i = 1, j = 0; stack_ != NULL ; ++i ,stack_ = stack_->next)
	{
		if (stack_->data == search)
		{
			++j;
			printf("%d. ",i);
		}
	}
	printf("step %d result founded.\n",j );

}

void search_queue(queue * queue_,int search)
{

	int i,j;

	printf("On ");
	for( i = 1, j = 0; queue_ != NULL ; ++i ,queue_ = queue_->next)
	{
		if (queue_->data == search)
		{
			++j;
			printf("%d. ",i);
		}
	}
	printf("step %d result founded.\n",j );

}

int search_bst(bst * bst_,int search,int counter)
{
	if (bst_ == NULL || bst_->data == search)
	{
		printf("Result founded on %d. Step\n",++counter );
		return counter;
	}

	if (bst_->data < search)
	{
		++counter;
		return search_bst(bst_->right,search,counter);
	}

	if (bst_->data > search)
	{
		++counter;
		return search_bst(bst_->left,search,counter);
	}

}

void search(stack * stack_, queue * queue_, bst * bst_, int val_to_search)
{
	clock_t start,end;
	double cpu_time_used;
	int counter;

	printf("Searching element in Stack...\n");
	start = clock();
	search_stack(stack_,val_to_search);
	end = clock();
	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC*1000;
	printf("Search Time For Stack: %.2f\n",cpu_time_used);
	printf("\n");

	printf("Searching element in Queue...\n");
	start = clock();
	search_queue(queue_,val_to_search);
	end = clock();
	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC*1000;
	printf("Searching Time For Queue: %.2f\n",cpu_time_used );
	printf("\n");

	printf("Searching element in BST...\n");
	start = clock();
	counter = search_bst(bst_,val_to_search,0);
	end = clock();
	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC*1000;
	printf("Searching Time For BST: %.2f\n",cpu_time_used );
	printf("\n");	
}



void traverse_stack(stack *stack_)
{
	int counter,temp_counter,i,i_temp;
	int print_counter_max, print_counter_min;
	int max,min,value,max_temp;
	stack *temper;


	//Find The Max Value
	for ( temper = stack_, max = 0 ; temper != NULL ; temper = temper->next)
	{
		if (max < temper->data)
		{
			max = temper->data;
		}
	}

	//Find The Min Value
	for ( temper = stack_, min = max ; temper != NULL ; temper = temper->next)
	{
		if (min > temper->data)
		{
			min = temper->data;
		}
	}

	//Program works for half of the list
	//This is not a ranking.
	//This is just a print.
	for ( i = 0, print_counter_max = 1, print_counter_min = 1, max_temp = max; i < SIZE/2; ++i)
	{
		for ( temper = stack_, value = 0, temp_counter = 0; temper != NULL ; temper = temper->next)
		{
			if (value < temper->data && temper->data <= max)
			{
				if (max == temper->data)
				{
					temp_counter++;
				}
				else
				{
					value = temper->data;
				}
				if (temp_counter == print_counter_max)
				{
					print_counter_max++;
					value = max;
					break;
				}
			}
		}
		if (value != max )
		{
			max = value;
			print_counter_max = 2;
		}
		printf("%d",value );

		for ( temper = stack_, value = max_temp, temp_counter = 0; temper != NULL ; temper = temper->next)
		{
			if (value > temper->data && temper->data >= min)
			{
				if (min == temper->data)
				{
					temp_counter++;
				}
				else
				{
					value = temper->data;
				}
				if (temp_counter == print_counter_min)
				{
					print_counter_min++;
					value = min;
					break;
				}
			}
		}
		if (value != min){
			min = value;
			print_counter_min = 2;
		}
		i_temp = i;
		printf(" %d ",value );
	}
}

void traverse_queue(queue *queue_)
{
	int counter,temp_counter,i,i_temp;
	int print_counter_max, print_counter_min;
	int max,min,value,max_temp;
	queue *temper;


	//Find The Max Value
	for ( temper = queue_, max = 0 ; temper != NULL ; temper = temper->next)
	{
		if (max < temper->data)
		{
			max = temper->data;
		}
	}

	//Find The Min Value
	for ( temper = queue_, min = max ; temper != NULL ; temper = temper->next)
	{
		if (min > temper->data)
		{
			min = temper->data;
		}
	}

	//Program works for half of the list
	//This is not a ranking.
	//This is just a print.	
	for ( i = 0, print_counter_max = 1, print_counter_min = 1, max_temp = max; i < SIZE/2; ++i)
	{
		for ( temper = queue_, value = 0, temp_counter = 0; temper != NULL ; temper = temper->next)
		{
			if (value < temper->data && temper->data <= max)
			{
				if (max == temper->data)
				{
					temp_counter++;
				}
				else
				{
					value = temper->data;
				}
				if (temp_counter == print_counter_max)
				{
					print_counter_max++;
					value = max;
					break;
				}
			}
		}
		if (value != max )
		{
			max = value;
			print_counter_max = 2;
		}
		printf("%d",value );

		for ( temper = queue_, value = max_temp, temp_counter = 0; temper != NULL ; temper = temper->next)
		{
			if (value > temper->data && temper->data >= min)
			{
				if (min == temper->data)
				{
					temp_counter++;
				}
				else
				{
					value = temper->data;
				}
				if (temp_counter == print_counter_min)
				{
					print_counter_min++;
					value = min;
					break;
				}
			}
		}
		if (value != min){
			min = value;
			print_counter_min = 2;
		}
		i_temp = i;
		printf(" %d ",value );
	}
}

int find_the_minimum_value(bst *bst_,int current_minimum_value)
{
	//if the bst_ is NULL ,there is no branch
    if (bst_ == NULL) 
        return -1; 
    //if equal return current_minimum_value
    if (bst_->data == current_minimum_value) 
        return current_minimum_value; 
  
    // If bst_'s value is greater tha current_minimum_value,program go to left
    else if (bst_->data > current_minimum_value) { 
        int control = find_the_minimum_value(bst_->left, current_minimum_value); 
        if (control == -1) 
            return bst_->data; 
        else
            return control; 
    } 
    // If bst's data is smaller than current_minimum_value,program go to right
    else if (bst_->data < current_minimum_value)  
        return find_the_minimum_value(bst_->right, current_minimum_value);    
}
int find_the_maximum_value(bst *bst_,int current_maximum_value)
{
	//if the bst_ is NULL ,there is no branch
    if (bst_ == NULL) 
        return -1; 
    //if equal return current_maximum_value
    if (bst_->data == current_maximum_value) 
        return current_maximum_value; 
  
    // If bst_'s value is smaller tha current_maximum_value,program go to right 
	else if (bst_->data < current_maximum_value) { 
        int control = find_the_maximum_value(bst_->right, current_maximum_value); 
        if (control == -1) 
            return bst_->data; 
        else
            return control; 
    } 
    // If bst's data is greater than current_maximum_value,program go to left
	else if (bst_->data > current_maximum_value)  
        return find_the_maximum_value(bst_->left, current_maximum_value);    
}

void traverse_bst(bst *bst_)
{
	int current_maximum_value,current_minimum_value;
	int max_counter,min_counter;

	bst *temp;
	bst *temper;

	for ( temp = bst_; temp->right != NULL; temp = temp->right);
	current_maximum_value = temp->data;

	for ( temp = bst_; temp->left != NULL; temp = temp->left);
	current_minimum_value = temp->data;

	while (1)
	{
		//Find Max-Min Data
		current_minimum_value=find_the_minimum_value(bst_,current_minimum_value);
		current_maximum_value=find_the_maximum_value(bst_,current_maximum_value);

		//If the max data exceeds min data, the function ends.
		if (current_maximum_value < current_minimum_value)
		{
			break;
		}
		//If max data equals min data, max print and then function ends.
		else if (current_maximum_value == current_minimum_value)
		{
			printf("%d ",current_maximum_value);
			break;
		}

		//Print Max-Min
		printf("%d ",current_maximum_value);
		printf("%d ",current_minimum_value);

		//Each time max-min is reduced after printing.
		current_maximum_value--;
		current_minimum_value++;
	}

}

void special_traverse(stack * stack_, queue * queue_, bst * bst_)
{
	clock_t start,end;
	double cpu_time_used;

	//STACK
	printf("Traverse Stack: ");

	start = clock();

	traverse_stack(stack_);

	end = clock();

	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC*1000;
	printf("\nTraverse Time For Stack:%.2f\n",cpu_time_used );

	//QUEUE
	printf("\nTraverse Queue: ");

	start = clock();

	traverse_queue(queue_);

	end = clock();

	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC*1000;
	printf("\nTraverse Time For Queue:%.2f\n",cpu_time_used );

	//BST
	printf("\nTraverse BST: ");

	start = clock();

	traverse_bst(bst_);

	end = clock();

	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC*1000;
	printf("\nTraverse Time For BST:%.2f\n",cpu_time_used );	
}


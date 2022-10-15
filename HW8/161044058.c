#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum{
	noone,cap,car
} player_type;

typedef enum{
	start,property,tax,punish,fortune_c
} block_type;

typedef struct 
{
	player_type type;
	int current_block_id;
	int owned_block_ids[11];
	int account;
	int turn_to_wait;
	char *name;	
} player_t;

typedef struct block_t
{
	int block_id;
	char *name;	
	int price;
	int rent;
	int rent_1;
	int rent_2;
	int rent_3;
	int house_price;
	int house_count;
	player_type owner;
	block_type type;

	struct block_t* next;

} block_t;

void init_the_board(block_t *board);
void show_board(block_t *board, player_t player_one, player_t player_two);
void show_properties_player(block_t *board,player_t *current_player);
void show_properties(block_t *board);

void buy_property(block_t *current_block,player_t *current_player,block_t *board);
void build_house(block_t* current_block,player_t* current_player,block_t *board);
void sell_property(block_t *board,player_t *current_player);

int control_block(block_t *current_block, player_t* current_player,block_t *board,player_t* other);
void gameplay(block_t *board, player_t player_one, player_t player_two);


int main()
{
	int i;

	block_t *board;
	board=malloc(sizeof(block_t));


	player_t player_one;
	player_t player_two;

	srand(time(NULL));

	init_the_board(board);


	//gameplay(board,player_one,player_two);
	player_one.type = car ;
	player_one.current_block_id = 0 ;
	player_one.account = 100000 ;
	player_one.turn_to_wait=0;
	player_one.name = "Car" ;

	player_two.type = cap ;
	player_two.current_block_id = 0 ;
	player_two.account = 100000 ;
	player_two.turn_to_wait=0;
	player_two.name = "Cap" ;

	for (int i = 0; i < 11; ++i)
	{
		player_one.owned_block_ids[i] = -1 ;
		player_two.owned_block_ids[i] = -1 ;

	}

	gameplay(board,player_one,player_two);

	return 0;
}


void init_the_board(block_t *board)
{


	board->block_id=0;
	board->name="Start";
	board->price=0;
	board->rent=0;
	board->rent_1=0;
	board->rent_2=0;
	board->rent_3=0;
	board->house_price=0;
	board->type=start;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=1;
	board->name="Esenyurt";
	board->price=16000;
	board->rent=800;
	board->rent_1=4000;
	board->rent_2=9000;
	board->rent_3=25000;
	board->house_price=10000;
	board->type=property;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=2;
	board->name="Car Park";
	board->price=0;
	board->rent=1500;
	board->rent_1=0;
	board->rent_2=0;
	board->rent_3=0;
	board->house_price=0;
	board->type=tax;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=3;
	board->name="Frotune Card";
	board->price=0;
	board->rent=0;
	board->rent_1=0;
	board->rent_2=0;
	board->rent_3=0;
	board->house_price=0;
	board->type=fortune_c;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=4;
	board->name="Tuzla";
	board->price=16500;
	board->rent=850;
	board->rent_1=4250;
	board->rent_2=9500;
	board->rent_3=26000;
	board->house_price=12000;
	board->type=property;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=5;
	board->name="Arnavutköy";
	board->price=17000;
	board->rent=875;
	board->rent_1=4500;
	board->rent_2=10000;
	board->rent_3=28000;
	board->house_price=12000;
	board->type=property;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=6;
	board->name="Wait 2 Turn";
	board->price=0;
	board->rent=2;
	board->rent_1=0;
	board->rent_2=0;
	board->rent_3=0;
	board->house_price=0;
	board->type=punish;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=23;
	board->name="Bebek";
	board->price=70000;
	board->rent=3500;
	board->rent_1=20000;
	board->rent_2=35500;
	board->rent_3=65000;
	board->house_price=35000;
	board->type=property;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=7;
	board->name="Çatalca";
	board->price=20000;
	board->rent=1000;
	board->rent_1=5000;
	board->rent_2=12000;
	board->rent_3=30000;
	board->house_price=13000;
	board->type=property;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=22;
	board->name="Vacation";
	board->price=0;
	board->rent=5000;
	board->rent_1=0;
	board->rent_2=0;
	board->rent_3=0;
	board->house_price=0;
	board->type=tax;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=8;
	board->name="Beykoz";
	board->price=23000;
	board->rent=1100;
	board->rent_1=5500;
	board->rent_2=12500;
	board->rent_3=33000;
	board->house_price=13000;
	board->type=property;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=21;
	board->name="Fortune Card";
	board->price=0;
	board->rent=0;
	board->rent_1=0;
	board->rent_2=0;
	board->rent_3=0;
	board->house_price=0;
	board->type=fortune_c;
	board->owner=noone;		
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=9;
	board->name="Fortune Card";
	board->price=0;
	board->rent=0;
	board->rent_1=0;
	board->rent_2=0;
	board->rent_3=0;
	board->house_price=0;
	board->type=fortune_c;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=20;
	board->name="Beşiktaş";
	board->price=60000;
	board->rent=2500;
	board->rent_1=15000;
	board->rent_2=28000;
	board->rent_3=60000;
	board->house_price=30000;
	board->type=property;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=10;
	board->name="Car Fix";
	board->price=0;
	board->rent=1750;
	board->rent_1=0;
	board->rent_2=0;
	board->rent_3=0;
	board->house_price=0;
	board->type=tax;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=19;
	board->name="Kadıköy";
	board->price=43000;
	board->rent=1900;
	board->rent_1=11000;
	board->rent_2=21500;
	board->rent_3=55000;
	board->house_price=23000;
	board->type=property;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=11;
	board->name="Maltepe";
	board->price=30000;
	board->rent=1350;
	board->rent_1=7000;
	board->rent_2=15000;
	board->rent_3=40000;
	board->house_price=16000;
	board->type=property;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=18;
	board->name="Wait 1 Turn";
	board->price=0;
	board->rent=1;
	board->rent_1=0;
	board->rent_2=0;
	board->rent_3=0;
	board->house_price=0;
	board->type=punish;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=17;
	board->name="Sarıyer";
	board->price=40000;
	board->rent=1750;
	board->rent_1=9500;
	board->rent_2=19000;
	board->rent_3=48000;
	board->house_price=19000;
	board->type=property;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=16;
	board->name="Ataşehir";
	board->price=35000;
	board->rent=1600;
	board->rent_1=8500;
	board->rent_2=17000;
	board->rent_3=45000;
	board->house_price=17000;
	board->type=property;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=15;
	board->name="Fortune Card";
	board->price=0;
	board->rent=0;
	board->rent_1=0;
	board->rent_2=0;
	board->rent_3=0;
	board->house_price=0;
	board->type=fortune_c;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=14;
	board->name="Oil";
	board->price=0;
	board->rent=2250;
	board->rent_1=0;
	board->rent_2=0;
	board->rent_3=0;
	board->house_price=0;
	board->type=tax;
	board->owner=noone;
	board->house_count=0;

	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=13;
	board->name="Şişli";
	board->price=33000;
	board->rent=1500;
	board->rent_1=8000;
	board->rent_2=16000;
	board->rent_3=42000;
	board->house_price=16000;
	board->type=property;
	board->owner=noone;
	board->house_count=0;
	
	board->next=malloc(sizeof(block_t));
	board=board->next;

	board->block_id=12;
	board->name="Car Fix";
	board->price=0;
	board->rent=1750;
	board->rent_1=0;
	board->rent_2=0;
	board->rent_3=0;
	board->house_price=0;
	board->type=tax;
	board->owner=noone;
	board->house_count=0;

	board=board->next;

	board=NULL;


}

void show_board(block_t *board, player_t player_one, player_t player_two)
{
	int i,j;
	block_t *temp;

	temp=board;



	//First row
	for (int i = 0; i < 7; ++i)
	{
		printf("------------------------");
	}
	printf("\n");
	//First name row
	for ( i = 0; i < 7 ; ++i )
	{
		printf("|\t%5s   \t",board->name);
		board=board->next;
	}
	printf("|\n");

	//First price row
	board=temp;
	for ( i = 0; i < 7 ; ++i )
	{
		if (board->type == property)
			printf("|\t%5d$  \t",board->price);
		else if (board->type == tax)
			printf("|\t%5d$  \t",board->rent);
		else
			printf("|\t          \t");
		board=board->next;
	}
	printf("|\n");

	//This loop control the user location and print it
	board=temp;
	for ( i = 0; i < 7 ; ++i ){
		if (player_two.current_block_id == board->block_id && player_one.current_block_id == board->block_id)
			printf("|\t %s  %s \t",player_one.name,player_two.name);
		else if (player_one.current_block_id == board->block_id)
			printf("|\t   %s    \t",player_one.name);
		else if (player_two.current_block_id == board->block_id)
			printf("|\t   %s    \t",player_two.name);	
		else
			printf("|\t          \t");
		board=board->next;
	}
	printf("|\n");

	for (int i = 0; i < 7; ++i)
	{
		printf("------------------------");
	}
	printf("\n");


// This loop print the intermediate line 1 to 4.
	temp=board;
	for (i = 0; i < 5; ++i)
	{
		//Name Row
		printf("|\t%5s   \t",board->name);
		printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
		//Name Row
		printf("|\t%s   \t|\n",board->next->name);
		//Price Row
		if (board->type == property)
			printf("|\t%5d$  \t|",board->price);
		else if (board->type == tax)
			printf("|\t%5d$  \t|",board->rent);
		else
			printf("|\t         \t|");

		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
		//Price Row
		if (board->next->type == property)
			printf("|\t%5d$  \t|\n",board->next->price);
		else if (board->next->type == tax)
			printf("|\t%5d$  \t|\n",board->next->rent);
		else
			printf("|\t          \t|\n");

		//This loop control the user location and print it
		if (player_two.current_block_id == board->block_id && player_one.current_block_id == board->block_id)
			printf("|\t %s  %s \t",player_one.name,player_two.name);
		else if (player_one.current_block_id == board->block_id)
			printf("|\t   %s    \t",player_one.name);
		else if (player_two.current_block_id == board->block_id)
			printf("|\t   %s    \t",player_two.name);	
		else
			printf("|\t          \t");

			printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");


		//This loop control the user location and print it
		if (player_two.current_block_id == board->next->block_id && player_one.current_block_id == board->next->block_id)
			printf("|\t %s  %s \t",player_one.name,player_two.name);
		else if (player_one.current_block_id == board->next->block_id)
			printf("|\t   %s    \t",player_one.name);
		else if (player_two.current_block_id == board->next->block_id)
			printf("|\t   %s    \t",player_two.name);	
		else
			printf("|\t          \t");


		if (i==4)
		{
			printf("|\n");
			for (j = 0; j < 7; ++j)
			{
				printf("------------------------");
			}		
		}
		else{
			printf("|\n------------------------");
			printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
			printf("------------------------");
		}

		printf("\n");

		board=board->next->next;
	}
	
	//End name row
	temp=board;
	for ( i = 0; i < 7 ; ++i )
	{
		printf("|\t%5s   \t",board->name);
		board=board->next;
	}
	printf("|\n");

	//End price row
	board=temp;
	for ( i = 0; i < 7 ; ++i )
	{
		if (board->type == property)
			printf("|\t%5d$  \t",board->price);
		else if (board->type == tax)
			printf("|\t%5d$  \t",board->rent);
		else
			printf("|\t          \t");
		board=board->next;
	}
	printf("|\n");

	//This loop control the user location and print it
	board=temp;
	for ( i = 0; i < 7 ; ++i )
	{
		if (player_two.current_block_id == board->block_id && player_one.current_block_id == board->block_id)
			printf("|\t %s  %s \t",player_one.name,player_two.name);
		else if (player_one.current_block_id == board->block_id)
			printf("|\t   %s    \t",player_one.name);
		else if (player_two.current_block_id == board->block_id)
			printf("|\t   %s    \t",player_two.name);	
		else
			printf("|\t          \t");
		board=board->next;
	}
	printf("|\n");

	for ( i = 0; i < 7; ++i)
	{
		printf("------------------------");
	}
	printf("\n");

}

void show_properties_player(block_t *board,player_t *current_player)
{
	int i;
	block_t *temp;
	temp=board;

	printf("Your properties : \n");

	for (i = 0; current_player->owned_block_ids[i] != -1 ; ++i)
	{

		board=temp;
		while (board != NULL)
		{
			if (board->block_id == current_player->owned_block_ids[i])
			{
				printf("-%d - %s \n", current_player->owned_block_ids[i],board->name);
				break;
			}
			board=board->next;
		}
	}

}

void show_properties(block_t *board)
{
	int i,select;
	block_t *temp;
	temp=board;

	//This loop continue until the user enter zero
	do{

		printf("Please select a property to see details or Enter the '0':\n");
		//Propert List with block_id
		for (i = 0; i < 24; ++i)
		{
			if (board->type == property)
			{
				printf("-#- %d -%s\n",board->block_id,board->name );
			}
			board=board->next;
		}
		board=temp;

		printf("Select : ");
		scanf("%d",&select);
		printf("\n");

		for (i = 0; i < 24; ++i)
		{
			if (board->block_id == select && board->type == property)
			{
				printf("---------------------------------\n");
				printf("|\t%10s\t\t|\n",board->name);
				printf("---------------------------------\n");
				printf("|\tRent\t\t%d$\t|\n",board->rent);
				printf("|\tRent 1 H    \t%d$\t|\n",board->rent_1);
				printf("|\tRent 2 H    \t%d$\t|\n",board->rent_2);
				printf("|\tRent 3 H    \t%d$\t|\n",board->rent_3);
				printf("---------------------------------\n");
				printf("|\tHouse Price \t%d$\t|\n",board->price);
				printf("---------------------------------\n");
				break;
			}
			board=board->next;
		}
		board=temp;
		printf("\n\n");

	}while(select != 0);
}

void buy_property(block_t* current_block,player_t* current_player,block_t *board)
{
	int select,i=0,all_price=0,dice;

	block_t *temp;
	temp=board;

	// I first set up the house buying rules

	if ( current_block->type != property)
		printf("This is not property.\n");
	
	
	else if ( !(current_block->block_id ==  current_player->current_block_id) )
		printf("You are not on this block.\n");
	
	else if (  !( current_player->account >= current_block->price ) )
		printf("You have not enough money for this property %s.\n",current_block->name);
	
	//If you do not have any obstacles to take property comes here.
	else if (current_player->type == car)
	{	
		do
		{
			printf("Do you want to buy %s ? (1-Yes , 2-No) -",current_block->name);
			scanf("%d",&select);
			printf("\n");

			if (select == 1)
			{
				//It takes the fee.And the property type varies.
				current_player->account -= current_block->price;
				current_block->owner = current_player->type;

				//House adds the first blank place in the list.
				for ( i = 0; current_player->owned_block_ids[i] != -1 ; ++i);
				current_player->owned_block_ids[i] = current_block->block_id;			
				
				printf("The property(%s) was purchased successfully.\n",current_block->name);
				printf("New Account: %d\n",current_player->account );
				break;
			}
		}while(select != 2);

		//If the user doesn't get the property,he mustn't take the house anyway.
		while(select != 2)
		{
			printf("Do you want to build house ? (1-Yes , 2-No) -");
			scanf("%d",&select);
			printf("\n");
			if (select == 1)
			{
				build_house(current_block,current_player,board);
				break;
			}
		}
		
	}

	else if (current_player->type == cap)
	{
		//All prices are collected.
		while(board!=NULL)
		{
			if (board->type == property)
			{
				i++;
				all_price+=board->price;
			}
			board=board->next;
		}
		all_price/=i;

		if (current_block->price < all_price)
		{
			
			//It takes the fee.And the property type varies.			
			current_player->account -= current_block->price;
			current_block->owner = current_player->type;

			//House adds the first blank place in the list.
			for ( i = 0; current_player->owned_block_ids[i] != -1 ; ++i);
			current_player->owned_block_ids[i] = current_block->block_id;	

			printf("The property(%s) was purchased successfully.\n",current_block->name);
			printf("New Account: %d\n",current_player->account );
		}
		else{

			dice=1+rand()%6;

			if (dice>=1 && dice<=3)
			{
				
				//It takes the fee.And the property type varies.			
				current_player->account -= current_block->price;
				current_block->owner = current_player->type;
				
				//House adds the first blank place in the list.
				for ( i = 0; current_player->owned_block_ids[i] != -1 ; ++i);
				current_player->owned_block_ids[i] = current_block->block_id;	
				
				printf("The property(%s) was purchased successfully.\n",current_block->name);
				printf("New Account: %d\n",current_player->account );
			}
		}
	}
}



void build_house(block_t* current_block,player_t* current_player,block_t *board)
{
	int select,i=0,dice,j;

	block_t *temp;
	temp=board;
	
	// I first set up the house buying rules
	if ( current_block->type != property)
		printf("This is not property.\n");

	else if ( !(current_block->block_id ==  current_player->current_block_id) )
		printf("You are not on this block.\n");

	else if ( !(current_block->owner ==  current_player->type) )
		printf("This block is not your's.\n");
	
	else if ( current_block->house_count == 3)
		printf("Also you have three house ! ! !\n");

	else if ( current_player->account < current_block->house_price )
		printf("You don't have enough money ! ! !\n");

	//If you do not have any obstacles to take home comes here.
	//Player type
	else if (current_player->type == car)
	{

		do
		{
			if (select != 0)
			{
				printf("How many house do you want to build on %s? House Price %d - 1,2,3. If you want to exit enter '0'. -",current_block->name,current_block->house_price);
				scanf("%d",&select);
				printf("\n");
			}

			if (current_block->house_count + select > 3)
			{
				printf("You have %d house. You can not buy %d houses.\n",current_block->house_count,select );
			}

			else if ( current_block->house_price * select > current_player->account)
			{
				printf("YOu don't have enough money for %d house ! ! !\n",select );
			}

			else if (current_block->house_count+select <4)
			{
				current_player->account -= (select*current_block->house_price) ;
				current_block->house_count+=select;
				printf("The %d houses was built on %s.\n",select,current_block->name );
				printf("New Account: %d\n",current_player->account );
			}

			if (current_block->house_count ==3)
			{
				printf("You have %d house. You can not buy anymore.\n",current_block->house_count);
				break;
			}

		}while(select != 0);		
	}
	//Player type
	else if (current_player->type == cap)
	{
		//Count The Property
		while(board!=NULL)
		{
			if (board->type == property)
			{
				i++;
			}
			board=board->next;
		}
		for (j = 0; current_player->owned_block_ids[j] != -1 ; ++j);
		
		if (j >= (i/3))
		{
			dice=1+rand()%6;
			if (dice>=1 && dice<=3)
			{
				current_player->account -= current_block->house_price ;
				current_block->house_count+=1;	
				printf("The house was built on %s.\n",current_block->name );
				printf("New Account: %d\n",current_player->account );
			}
		}
	}

}

void sell_property(block_t *board,player_t* current_player)
{
	int select,i,j,temp,temp_two,number_of_house;
	
	block_t *temporary;
	block_t *bigger;
	temporary=board;

	//Control the your property,If you don't have property program will be end. Property number will be i.
	for (i = 0; current_player->owned_block_ids[i] != -1 ; ++i);

	if (i == 0)
		printf("\nYou don't have property ! ! !\n");

	else if (current_player->type==car){

		do{

			//Print the property ID
			printf("Your properties ID's : ");
			for (i = 0; current_player->owned_block_ids[i] != -1 ; ++i)
				printf("%d ", current_player->owned_block_ids[i]);

			//Choice property
			printf("\n\nChoice property ID's that you want to sell or Enter the number '-1' If you want to exit.\nSelect: ");
			scanf("%d",&select);
			if (select == -1)
			{
				break;
			}
			//Control the select is true or false
			for (i = 0; current_player->owned_block_ids[i] != select && current_player->owned_block_ids[i] != -1; ++i);

			//It is true , It will go if statemant
			if (current_player->owned_block_ids[i] == select)
			{
				board=temporary;
				//Detect the block of list number, it will be i.
				for (i = 0; board->block_id != select ; ++i)
				{
					board=board->next;
				}


					current_player->account = current_player->account + board->price/2 + (board->house_count*board->house_price)/2;
					board->owner = noone;	
					board->house_count=0;

					//Detect the list number of end elemnent.
					for (j = 0; current_player->owned_block_ids[j] != -1 ; ++j);
					//And copy the temp
					temp=j-1;
					//Detect the list number of block_id
					for (j = 0; current_player->owned_block_ids[j] != board->block_id ; ++j);
					//List number of block_id equal to end element.Deleted this block_id
					if (temp == j)
					{
						current_player->owned_block_ids[j]=-1;
						//the list number of end elemnent is zero this mean is no more elements left
						if (temp==0)
						{
							select=-1;
						}
					}
					//List number of block_id smaller than end element,the whole list moves one by one to the deleted element
					else if (temp > j){

						current_player->owned_block_ids[j]=-1;

						for (; j < temp ; ++j)
						{

							temp_two = current_player->owned_block_ids[j];

							current_player->owned_block_ids[j]=current_player->owned_block_ids[j+1];

							current_player->owned_block_ids[j+1] = temp_two;
						}
					}
				
			}	

			//Exit control
			else
				printf("NOT TRUE Choice\n");


		}while(select != -1);

	}
	else if (current_player->type == cap)
	{
		temp=0;

			//Print the property ID
			printf("Your properties ID's : ");
			for (i = 0; current_player->owned_block_ids[i] != -1 ; ++i)
				printf("%d ", current_player->owned_block_ids[i]);

			for (i = 0; current_player->owned_block_ids[i] != -1 ; ++i)
			{
				while(board!=NULL)
				{
					if(board->block_id == current_player->owned_block_ids[i] && board->price > temp)
					{
						temp=board->price;
						bigger=board;
					}
					board=board->next;
				}
				board=temporary;
			}	

		board=bigger;

		current_player->account = current_player->account + (board->price)/2 + (board->house_count*board->house_price)/2;
		board->owner = noone;	
		board->house_count=0;
		printf("\nSelled the property %s-%d\n",board->name,board->block_id);
		printf("Nex Account: %d\n",current_player->account);

		//Detect the list number of end elemnent.
		for (j = 0; current_player->owned_block_ids[j] != -1 ; ++j);
		//And copy the temp
		temp=j-1;
		//Detect the list number of block_id
		for (j = 0; current_player->owned_block_ids[j] != board->block_id ; ++j);
		//List number of block_id equal to end element.Deleted this block_id
		if (temp == j)
		{
			current_player->owned_block_ids[j]=-1;
			//the list number of end elemnent is zero this mean is no more elements left
			if (temp==0)
			{
				select=-1;
			}
		}
		//List number of block_id smaller than end element,the whole list moves one by one to the deleted element
		else if (temp > j){

			current_player->owned_block_ids[j]=-1;

			for (; j < temp ; ++j)
			{

				temp_two = current_player->owned_block_ids[j];

				current_player->owned_block_ids[j]=current_player->owned_block_ids[j+1];

				current_player->owned_block_ids[j+1] = temp_two;
			}
		}
	}
}	




int control_block(block_t *current_block, player_t* current_player,block_t *board ,player_t *other)
{
	int select,i,dice;
	
	/*
	-After the dice are thrown, 4 possibilities will be checked.
		
		1(if)-Property
			1-Is the property unattended
				1-buy_property(current_block,current_player)
			2-Property owner own
				1-"Do you want to build house? 1-Yes 2-No -"
			3-The structure does not belong to him
				1-Does he have the money to pay rent_3 or sell property or becomes bankrupt
				2-Does he have the money to pay rent_2 or sell property or becomes bankrupt
				3-Does he have the money to pay rent_1 or sell property or becomes bankrupt
				4-Does he have the money to pay rent or sell property or becomes bankrupt
		2(else if)-Punish
			1-You are punished from monopoly
		3(else if)-Tax
			1-Does he have the money to pay taxes
			2-If there is no money to pay tax sells the property or becomes bankrupt
		4(else if)-Start
		5Fortune
			1-Free House
			2-Time Travel
			3-Garnishment
			4-Generosity
			5-Treasure Hunter
	*/


	if (current_player->type == car)
	{

		if (current_block->type == property)
		{

			if (current_block->owner == noone)
			{
				buy_property(current_block,current_player,board);
				return 0;
			}

			if (current_block->owner == current_player->type)
			{
				do
				{ 
					printf("Do you want to build house in %s? 1-Yes 2-No -",current_block->name);
					scanf("%d",&select);
					printf("\n");
					if (select == 1)
					{
						build_house(current_block,current_player,board);
						return 0;
					}
					else if (select == 2)
						return 0;

				}while(1);
			}

			else {
				if (current_block->house_count == 3)
				{
					if (current_player->account >= current_block->rent_3)
					{
						current_player->account -= current_block->rent_3;
						printf("You payed the rent for %s, %d\n",current_block->name,current_block->rent_3);
						printf("New Account: %d\n",current_player->account );
						return 0;
					}
					else
					{
						printf("You have not enough money that you pay this rent %d-%s.\n",current_block->rent_3,current_block->name);
						printf("Your money %d\n",current_player->account);
						do
						{
							for (i = 0; current_player->owned_block_ids[i] != -1; ++i);

							if (i == 0)
							{
								return -1;
							}

							sell_property(board,current_player);

							if (current_player->account >= current_block->rent_3){
								current_player->account -= current_block->rent_3;
								return 0;			
							}
							else
								printf("Alread you have not enough money ! ! !\n");


						}while(1);
					}
				}

				if (current_block->house_count == 2)
				{
					if (current_player->account >= current_block->rent_2)
					{
						current_player->account -= current_block->rent_2;
						printf("You payed the rent for %s, %d\n",current_block->name,current_block->rent_2);
						printf("New Account: %d\n",current_player->account );
						return 0;
					}	
					else
					{
						printf("You have not enough money that you pay this rent %d-%s.\n",current_block->rent_2,current_block->name);
						printf("Your money %d\n",current_player->account);					
						do
						{

							for (i = 0; current_player->owned_block_ids[i] != -1; ++i);

							if (i == 0)
							{
								return -1;
							}
							sell_property(board,current_player);

							if (current_player->account >= current_block->rent_2){
								current_player->account -= current_block->rent_2;
								return 0;			
							}
							else
								printf("Alread you have not enough money ! ! !\n");
						}while(1);
					}
				}

				if (current_block->house_count == 1)
				{
					if (current_player->account >= current_block->rent_1)
					{
						current_player->account -= current_block->rent_1;
						printf("You payed the rent for %s, %d\n",current_block->name,current_block->rent_1);
						printf("New Account: %d\n",current_player->account );
						return 0;
					}	
					else
					{
						printf("You have not enough money that you pay this rent %d-%s.\n",current_block->rent_1,current_block->name);
						printf("Your money %d\n",current_player->account);					
						do
						{
							for (i = 0; current_player->owned_block_ids[i] != -1; ++i);

							if (i == 0)
							{
								return -1;
							}
							sell_property(board,current_player);

							if (current_player->account >= current_block->rent_1){
								current_player->account -= current_block->rent_1;
								return 0;			
							}
							else
								printf("Alread you have not enough money ! ! !\n");


						}while(1);
					}
				}
				if (current_block->house_count == 0)
				{
					if (current_player->account >= current_block->rent)
					{
						current_player->account -= current_block->rent;
						printf("You payed the rent for %s, %d\n",current_block->name,current_block->rent);
						printf("New Account: %d\n",current_player->account );
						return 0;
					}	
					else
					{
						printf("You have not enough money that you pay this rent %d-%s.\n",current_block->rent,current_block->name);
						printf("Your money %d\n",current_player->account);					
						do
						{
							for (i = 0; current_player->owned_block_ids[i] != -1; ++i);

							if (i == 0)
							{
								return -1;
							}
							sell_property(board,current_player);

							if (current_player->account >= current_block->rent){
								current_player->account -= current_block->rent;
								return 0;			
							}
							else
								printf("Alread you have not enough money ! ! !\n");


						}while(1);
					}
				}
			}

		}

		else if (current_block->type == punish)
		{
			printf("You are punished from monopoly ,%d tour \n",current_block->rent);
			current_player->turn_to_wait=current_block->rent;
			return 0;
		}

		else if (current_block->type == tax)
		{
		
			if (current_player->account >= current_block->rent)
			{
				current_player->account -= current_block->rent;
				printf("You payed the rent for %s, %d\n",current_block->name,current_block->rent);
				printf("New Account: %d\n",current_player->account );
				return 0;
			}
			else{
				printf("You have not enough money that you pay this rent. Sell The Your Properties.\n");
				do
				{
					for (i = 0; current_player->owned_block_ids[i] != -1; ++i);

					if (i == 0)
					{
						return -1;
					}
					sell_property(board,current_player);

					if (current_player->account >= current_block->rent){
						current_player->account -= current_block->rent;
						return 0;			
					}


				}while(1);
			}
		}
		else if (current_block->type == start)
		{
			return 0;
		}
		else if (current_block->type == fortune_c)
		{
			dice=1+rand()%5;

			if (dice == 1)
			{
				printf("I couldn't do this part.\n");
				return 0;
			}

			if (dice == 2)
			{
				printf("Card No:%d -Time Travel\n",dice );

				dice=1+rand()%6;
				if (dice>=1 && dice<=3)
					current_player->current_block_id+=2;
				else
					current_player->current_block_id-=2;
			}

			if (dice == 3)
			{
				printf("Card No:%d -Garnishment\n",dice );

				if (current_player->account >= 5000)
				{
					current_player->account -= 5000;
					printf("You payed the 5000$ %s, %d\n",current_block->name,current_block->rent);
					printf("New Account: %d\n",current_player->account );
					return 0;
				}
				else{
					printf("You have not enough money that you pay this 5000$. Sell The Properties.\n");
					do
					{
						for (i = 0; current_player->owned_block_ids[i] != -1; ++i);

						if (i == 0)
						{
							return -1;
						}

						sell_property(board,current_player);

						if (current_player->account >= current_block->rent){
							current_player->account -= current_block->rent;
							return 0;			
						}
						else
							printf("Already you have not enough money ! ! !\n");

					}while(1);
				}
			}

			if (dice == 4)
			{
				printf("Card No:%d -Generosity\n",dice );

				if (current_player->account >= 10000)
				{
					current_player->account -= 10000;
					other->account += 10000;
					printf("You payed the 10000$ for rival %s, %d\n",current_block->name,current_block->rent);
					printf("New Account: %d\n",current_player->account );
					return 0;
				}
				else{
					printf("You have not enough money that you pay this 10000$ for rival. Sell The Properties.\n");
					do
					{
						for (i = 0; current_player->owned_block_ids[i] != -1; ++i);

						if (i == 0)
						{
							return -1;
						}

						sell_property(board,current_player);

						if (current_player->account >= 10000){
							other->account +=10000;
							current_player->account -= 10000;
							return 0;			
						}
						else
							printf("Already you have not enough money ! ! !\n");

					}while(1);
				}			
			}

			if (dice == 5)
			{
				printf("Card No:%d -Treasure Hunter\n",dice );
				current_player->account+=20000;				
				printf("New Account: %d\n",current_player->account );

			}

			return 0;
		}
	}

	else if (current_player->type == cap)
	{

		if (current_block->type == property)
		{
			if (current_block->owner == noone)
			{
				buy_property(current_block,current_player,board);
				return 0;
			}

			if (current_block->owner == current_player->type)
			{
				build_house(current_block,current_player,board);
			}

			else {
				if (current_block->house_count == 3)
				{
					if (current_player->account >= current_block->rent_3)
					{
						current_player->account -= current_block->rent_3;
						printf("You payed the rent for %s, %d\n",current_block->name,current_block->rent_3);
						printf("New Account: %d\n",current_player->account );
						return 0;
					}
					else
					{
						printf("You have not enough money that you pay this rent %d-%s.\n",current_block->rent_3,current_block->name);
						printf("Your money %d\n",current_player->account);
						do
						{
							for (i = 0; current_player->owned_block_ids[i] != -1; ++i);

							if (i == 0)
							{
								return -1;
							}

							sell_property(board,current_player);

							if (current_player->account >= current_block->rent_3)
							{
								current_player->account -= current_block->rent_3;
								return 0;			
							}
							else
								printf("Alread You have not enough money ! ! !\n");


						}while(1);
					}
				}

				if (current_block->house_count == 2)
				{
					if (current_player->account >= current_block->rent_2)
					{
						current_player->account -= current_block->rent_2;
						printf("You payed the rent for %s, %d\n",current_block->name,current_block->rent_2);
						printf("New Account: %d\n",current_player->account );
						return 0;
					}	
					else
					{
						printf("You have not enough money that you pay this rent %d-%s.\n",current_block->rent_2,current_block->name);
						printf("Your money %d\n",current_player->account);					
						do
						{

							for (i = 0; current_player->owned_block_ids[i] != -1; ++i);

							if (i == 0)
							{
								return -1;
							}
							sell_property(board,current_player);

							if (current_player->account >= current_block->rent_2){
								current_player->account -= current_block->rent_2;
								return 0;			
							}
							else
								printf("Alread You have not enough money ! ! !\n");
						}while(1);
					}
				}

				if (current_block->house_count == 1)
				{
					if (current_player->account >= current_block->rent_1)
					{
						current_player->account -= current_block->rent_1;
						printf("You payed the rent for %s, %d\n",current_block->name,current_block->rent_1);
						printf("New Account: %d\n",current_player->account );
						return 0;
					}	
					else
					{
						printf("You have not enough money that you pay this rent %d-%s.\n",current_block->rent_1,current_block->name);
						printf("Computer money %d\n",current_player->account);					
						do
						{
							for (i = 0; current_player->owned_block_ids[i] != -1; ++i);

							if (i == 0)
							{
								return -1;
							}
							sell_property(board,current_player);

							if (current_player->account >= current_block->rent_1){
								current_player->account -= current_block->rent_1;
								return 0;			
							}
							else
								printf("Alread You have not enough money ! ! !\n");


						}while(1);
					}
				}
				if (current_block->house_count == 0)
				{
					if (current_player->account >= current_block->rent)
					{
						current_player->account -= current_block->rent;
						printf("You payed the rent for %s, %d\n",current_block->name,current_block->rent);
						printf("New Account: %d\n",current_player->account );
						return 0;
					}	
					else
					{
						printf("You have not enough money that you pay this rent %d-%s.\n",current_block->rent,current_block->name);
						printf("You money %d\n",current_player->account);					
						do
						{
							for (i = 0; current_player->owned_block_ids[i] != -1; ++i);

							if (i == 0)
							{
								return -1;
							}
							sell_property(board,current_player);

							if (current_player->account >= current_block->rent){
								current_player->account -= current_block->rent;
								return 0;			
							}
							else
								printf("Already you have not enough money ! ! !\n");


						}while(1);
					}
				}
			}

		}

		else if (current_block->type == punish)
		{
			printf("You are punished from monopoly ,%d tour \n",current_block->rent);
			current_player->turn_to_wait=current_block->rent;
			return 0;
		}

		else if (current_block->type == tax)
		{
		
			if (current_player->account >= current_block->rent)
			{
				current_player->account -= current_block->rent;
				printf("You payed the tax %s, %d\n",current_block->name,current_block->rent);
				printf("New Account: %d\n",current_player->account );
				return 0;
			}
			else{
				printf("You have not enough money that you pay this rent. Sell The Properties.\n");
				do
				{
					for (i = 0; current_player->owned_block_ids[i] != -1; ++i);

					if (i == 0)
					{
						return -1;
					}

					sell_property(board,current_player);

					if (current_player->account >= current_block->rent){
						current_player->account -= current_block->rent;
						return 0;			
					}
					else
						printf("Already you have not enough money ! ! !\n");

				}while(1);
			}
		}
		else if (current_block->type == start)
		{
			return 0;
		}
		else if (current_block->type == fortune_c)
		{
			dice=1+rand()%5;
			printf("girdi-%d\n",dice);

			if (dice == 1)
			{
				printf("I couldn't do this part.\n");
				return 0;
			}

			if (dice == 2)
			{
				printf("Card No:%d -Time Travel\n",dice );

				dice=1+rand()%6;
				if (dice>=1 && dice<=3)
					current_player->current_block_id+=2;
				else
					current_player->current_block_id-=2;
			}

			if (dice == 3)
			{
				printf("Card No:%d -Garnishment\n",dice );

				if (current_player->account >= 5000)
				{
					current_player->account -= 5000;
					printf("You payed the 5000$ %s, %d\n",current_block->name,current_block->rent);
					printf("New Account: %d\n",current_player->account );
					return 0;
				}
				else{
					printf("You have not enough money that you pay this 5000$. Sell The Properties.\n");
					do
					{
						for (i = 0; current_player->owned_block_ids[i] != -1; ++i);

						if (i == 0)
						{
							return -1;
						}

						sell_property(board,current_player);

						if (current_player->account >= current_block->rent){
							current_player->account -= current_block->rent;
							return 0;			
						}
						else
							printf("Already you have not enough money ! ! !\n");

					}while(1);
				}
			}

			if (dice == 4)
			{
				printf("Card No:%d -Generosity\n",dice );

				if (current_player->account >= 10000)
				{
					other->account += 10000;
					current_player->account -= 10000;
					printf("You payed the 10000$ for rival %s, %d\n",current_block->name,current_block->rent);
					printf("New Account: %d\n",current_player->account );
					return 0;
				}
				else{
					printf("You have not enough money that you pay this 10000$ for rival. Sell The Properties.\n");
					do
					{
						for (i = 0; current_player->owned_block_ids[i] != -1; ++i);

						if (i == 0)
						{
							return -1;
						}

						sell_property(board,current_player);

						if (current_player->account >= 10000){
							other->account += 10000;
							current_player->account -= 10000;
							return 0;			
						}
						else
							printf("Already you have not enough money ! ! !\n");

					}while(1);
				}			
			}

			if (dice == 5)
			{
				printf("Card No:%d -Treasure Hunter\n",dice );
				current_player->account+=20000;		
				printf("New Account: %d\n",current_player->account );
			}

			return 0;
		}
	}
}



void gameplay(block_t *board, player_t player_one, player_t player_two)
{	

	int i,j,select,temp,flag;
		
	block_t *temporary;
	temporary=board;


	show_board(board,player_one,player_two);
	printf("! ! ! GAME IS STARTING ! ! !\n");

	do
	{

		do
		{
			flag=1;
			if (player_one.turn_to_wait == 0)
			{
				board=temporary;
				
				printf("\nPlayer one\n\n");
				printf("1 - Roll The Dice\n");
				printf("2 - Show My Account\n");
				printf("3 - Show My Properties\n");
				printf("4 - Show Property Deeds\n");
				printf("5 - Buy Property\n");
				printf("6 - Buy House\n");
				printf("7 - Sell Property\n");
				printf("Please select one option to continue : ");
				scanf("%d",&select);
				printf("\n");

				switch(select){
					case 1:
						temp=1+rand()%19;
						printf("Dice: %d\n",temp );

						if(player_one.current_block_id+temp > 23){
							player_one.account += 10000;
							player_one.current_block_id += (temp-24);
						}
						else{
							player_one.current_block_id += temp;
						}

						while (board->block_id != player_one.current_block_id)
						{
							board=board->next;
						}

						flag=control_block(board,&player_one,temporary,&player_two);
						show_board(temporary,player_one,player_two);
						break;
					case 2:
						printf("Account: %d\n",player_one.account );
						break;
					case 3:
						board=temporary;
						show_properties_player(board,&player_one);
						break;
					case 4:
						show_properties(temporary);
						break;
					case 5:
						buy_property(board,&player_one,board);
						break;
					case 6:
						build_house(board,&player_one,board);
						break;
					case 7:
						sell_property(temporary,&player_one);
						break;

				}		

			}

			else{
				player_one.turn_to_wait--;
				break;
			}

		}while(flag != 0 && flag != -1);


		if (flag == -1)
		{
			printf("Player one is defeated ! ! !\n");	
			break;
		}


		do
		{
			flag=1;

			if (player_two.turn_to_wait == 0)
			{
				board=temporary;
				printf("\nPlayer two\n\n");
				temp=1+rand()%19;
				printf("Dice: %d\n",temp );

				if(player_two.current_block_id+temp > 23){
					player_two.account += 10000;
					player_two.current_block_id += (temp-24);
				}
				else{
					player_two.current_block_id += temp;
				}

				while (board->block_id != player_two.current_block_id)
				{
					board=board->next;
				}
				
				flag=control_block(board,&player_two,temporary,&player_one);
				show_board(temporary,player_one,player_two);
			}

			else{
				player_two.turn_to_wait--;
				break;
			}

		}while(flag != 0 && flag != -1);
		

		if (flag == -1)
		{
			printf("Player two is defeated ! ! !\n");	
			break;
		}

	}while(1);
	
}

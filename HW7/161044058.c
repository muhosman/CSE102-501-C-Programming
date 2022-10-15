#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum{
	noone,cap,car
} player_type;

typedef enum{
	start,property,tax,punish
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

typedef struct 
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
} block_t;

void init_the_board(block_t board[20]);
void show_board(block_t board[20], player_t player_one, player_t player_two);
void show_properties(block_t board[20]);
void buy_property(block_t *current_block,player_t* current_player);
void build_house(block_t* current_block,player_t* current_player);
void sell_property(block_t board[20],player_t* current_player);
int control_block(block_t* current_block, player_t* current_player,block_t board[20]);
void gameplay(block_t board[20], player_t player_one, player_t player_two);


int main()
{
	int i;
	block_t board[20];
	player_t player_one;
	player_t player_two;

	srand(time(NULL));

	init_the_board(board);

	player_one.type = cap ;
	player_one.current_block_id = 1 ;
	player_one.account = 100000 ;
	player_one.turn_to_wait=0;
	player_one.name = "Cap" ;

	player_two.type = car ;
	player_two.current_block_id = 1 ;
	player_two.account = 100000 ;
	player_two.turn_to_wait=0;
	player_two.name = "Car" ;

	for ( i = 0; i < 11; ++i)
	{
		player_one.owned_block_ids[i] = -1 ;
		player_two.owned_block_ids[i] = -1 ;


	}

	gameplay(board,player_one,player_two);


	return 0;
}


void init_the_board(block_t board[20])
{

	board[0].block_id=1;
	board[0].name="Start";
	board[0].price=0;
	board[0].rent=0;
	board[0].rent_1=0;
	board[0].rent_2=0;
	board[0].rent_3=0;
	board[0].house_price=0;
	board[0].type=start;
	board[0].owner=noone;
	board[0].house_count=0;


	board[1].block_id=2;
	board[1].name="Esenyurt";
	board[1].price=16000;
	board[1].rent=800;
	board[1].rent_1=4000;
	board[1].rent_2=9000;
	board[1].rent_3=25000;
	board[1].house_price=10000;
	board[1].type=property;
	board[1].owner=noone;
	board[1].house_count=0;

	board[2].block_id=3;
	board[2].name="Car Park";
	board[2].price=0;
	board[2].rent=1500;
	board[2].rent_1=0;
	board[2].rent_2=0;
	board[2].rent_3=0;
	board[2].house_price=0;
	board[2].type=tax;
	board[2].owner=noone;
	board[2].house_count=0;

	board[3].block_id=4;
	board[3].name="Tuzla";
	board[3].price=16500;
	board[3].rent=850;
	board[3].rent_1=4250;
	board[3].rent_2=9500;
	board[3].rent_3=26000;
	board[3].house_price=12000;
	board[3].type=property;
	board[3].owner=noone;
	board[3].house_count=0;

	board[4].block_id=5;
	board[4].name="Arnavutköy";
	board[4].price=17000;
	board[4].rent=875;
	board[4].rent_1=4500;
	board[4].rent_2=10000;
	board[4].rent_3=28000;
	board[4].house_price=12000;
	board[4].type=property;
	board[4].owner=noone;
	board[4].house_count=0;

	board[5].block_id=6;
	board[5].name="Wait 2 Turn";
	board[5].price=0;
	board[5].rent=2;
	board[5].rent_1=0;
	board[5].rent_2=0;
	board[5].rent_3=0;
	board[5].house_price=0;
	board[5].type=punish;
	board[5].owner=noone;
	board[5].house_count=0;

	board[6].block_id=20;
	board[6].name="Bebek";
	board[6].price=70000;
	board[6].rent=3500;
	board[6].rent_1=20000;
	board[6].rent_2=35500;
	board[6].rent_3=65000;
	board[6].house_price=35000;
	board[6].type=property;
	board[6].owner=noone;
	board[6].house_count=0;

	board[7].block_id=7;
	board[7].name="Çatalca";
	board[7].price=20000;
	board[7].rent=1000;
	board[7].rent_1=5000;
	board[7].rent_2=12000;
	board[7].rent_3=30000;
	board[7].house_price=13000;
	board[7].type=property;
	board[7].owner=noone;
	board[7].house_count=0;

	board[8].block_id=19;
	board[8].name="Vacation";
	board[8].price=0;
	board[8].rent=5000;
	board[8].rent_1=0;
	board[8].rent_2=0;
	board[8].rent_3=0;
	board[8].house_price=0;
	board[8].type=tax;
	board[8].owner=noone;
	board[8].house_count=0;

	board[9].block_id=8;
	board[9].name="Beykoz";
	board[9].price=23000;
	board[9].rent=1100;
	board[9].rent_1=5500;
	board[9].rent_2=12500;
	board[9].rent_3=33000;
	board[9].house_price=13000;
	board[9].type=property;
	board[9].owner=noone;
	board[9].house_count=0;

	board[10].block_id=18;
	board[10].name="Beşiktaş";
	board[10].price=60000;
	board[10].rent=2500;
	board[10].rent_1=15000;
	board[10].rent_2=28000;
	board[10].rent_3=60000;
	board[10].house_price=30000;
	board[10].type=property;
	board[10].owner=noone;		
	board[10].house_count=0;

	board[11].block_id=9;
	board[11].name="Car Fix";
	board[11].price=0;
	board[11].rent=1750;
	board[11].rent_1=0;
	board[11].rent_2=0;
	board[11].rent_3=0;
	board[11].house_price=0;
	board[11].type=tax;
	board[11].owner=noone;
	board[11].house_count=0;

	board[12].block_id=17;
	board[12].name="Kadıköy";
	board[12].price=43000;
	board[12].rent=1900;
	board[12].rent_1=11000;
	board[12].rent_2=21500;
	board[12].rent_3=55000;
	board[12].house_price=23000;
	board[12].type=property;
	board[12].owner=noone;
	board[12].house_count=0;

	board[13].block_id=10;
	board[13].name="Maltepe";
	board[13].price=30000;
	board[13].rent=1350;
	board[13].rent_1=7000;
	board[13].rent_2=15000;
	board[13].rent_3=40000;
	board[13].house_price=15000;
	board[13].type=property;
	board[13].owner=noone;
	board[13].house_count=0;

	board[14].block_id=16;
	board[14].name="Wait 1 Turn";
	board[14].price=0;
	board[14].rent=1;
	board[14].rent_1=0;
	board[14].rent_2=0;
	board[14].rent_3=0;
	board[14].house_price=0;
	board[14].type=punish;
	board[14].owner=noone;
	board[14].house_count=0;

	board[15].block_id=15;
	board[15].name="Sarıyer";
	board[15].price=40000;
	board[15].rent=1750;
	board[15].rent_1=9500;
	board[15].rent_2=19000;
	board[15].rent_3=48000;
	board[15].house_price=19000;
	board[15].type=property;
	board[15].owner=noone;
	board[15].house_count=0;

	board[16].block_id=14;
	board[16].name="Ataşehir";
	board[16].price=35000;
	board[16].rent=1600;
	board[16].rent_1=8500;
	board[16].rent_2=17000;
	board[16].rent_3=45000;
	board[16].house_price=17000;
	board[16].type=property;
	board[16].owner=noone;
	board[16].house_count=0;

	board[17].block_id=13;
	board[17].name="Oil";
	board[17].price=0;
	board[17].rent=2250;
	board[17].rent_1=0;
	board[17].rent_2=0;
	board[17].rent_3=0;
	board[17].house_price=0;
	board[17].type=tax;
	board[17].owner=noone;
	board[17].house_count=0;

	board[18].block_id=12;
	board[18].name="Şişli";
	board[18].price=33000;
	board[18].rent=1500;
	board[18].rent_1=8000;
	board[18].rent_2=16000;
	board[18].rent_3=42000;
	board[18].house_price=16000;
	board[18].type=property;
	board[18].owner=noone;
	board[18].house_count=0;

	board[19].block_id=11;
	board[19].name="Bills";
	board[19].price=0;
	board[19].rent=2000;
	board[19].rent_1=0;
	board[19].rent_2=0;
	board[19].rent_3=0;
	board[19].house_price=0;
	board[19].type=tax;
	board[19].owner=noone;
	board[19].house_count=0;

}

void show_board(block_t board[20], player_t player_one, player_t player_two)
{

	int i,j,k;
	//First row
	for (int i = 0; i < 6; ++i)
	{
		printf("------------------------");
	}
	printf("\n");
	//First name row
	for ( i = 0; i < 6 ; ++i )
	{
		printf("|\t%5s   \t",board[i].name);
	}
	printf("|\n");
	//First price row
	for ( i = 0; i < 6 ; ++i )
	{
		if (board[i].type == property)
			printf("|\t%5d$  \t",board[i].price);
		else if (board[i].type == tax)
			printf("|\t%5d$  \t",board[i].rent);
		else
			printf("|\t          \t");
	}
	printf("|\n");
	//This loop control the user location and print it
	for ( i = 0; i < 6 ; ++i ){
		if (player_two.current_block_id == board[i].block_id && player_one.current_block_id == board[i].block_id)
			printf("|\t %s  %s \t",player_one.name,player_two.name);
		else if (player_one.current_block_id == board[i].block_id)
			printf("|\t   %s    \t",player_one.name);
		else if (player_two.current_block_id == board[i].block_id)
			printf("|\t   %s    \t",player_two.name);	
		else
			printf("|\t          \t");
	}
	printf("|\n");

	for (int i = 0; i < 6; ++i)
	{
		printf("------------------------");
	}
	printf("\n");
	// This loop print the intermediate line 1 to 4.
	for (j = 0; j < 4; ++j)
	{
		//Name Row
		printf("|\t%5s   \t",board[i].name);
		printf("|\t\t\t\t\t\t\t\t\t\t\t\t");
		//Name Row
		printf("|\t%s   \t|\n",board[i+1].name);
		//Price Row
		if (board[i].type == property)
			printf("|\t%5d$  \t|",board[i].price);
		else if (board[i].type == tax)
			printf("|\t%5d$  \t|",board[i].rent);
		else
			printf("|\t         \t|");

		printf("\t\t\t\t\t\t\t\t\t\t\t\t");
		//Price Row
		if (board[i+1].type == property)
			printf("|\t%5d$  \t|\n",board[i+1].price);
		else if (board[i+1].type == tax)
			printf("|\t%5d$  \t|\n",board[i+1].rent);
		else
			printf("|\t          \t|\n");

		//This loop control the user location and print it
		if (player_two.current_block_id == board[i].block_id && player_one.current_block_id == board[i].block_id)
			printf("|\t %s  %s \t",player_one.name,player_two.name);
		else if (player_one.current_block_id == board[i].block_id)
			printf("|\t   %s    \t",player_one.name);
		else if (player_two.current_block_id == board[i].block_id)
			printf("|\t   %s    \t",player_two.name);	
		else
			printf("|\t          \t");

			printf("|\t\t\t\t\t\t\t\t\t\t\t\t");


		//This loop control the user location and print it
		if (player_two.current_block_id == board[i+1].block_id && player_one.current_block_id == board[i+1].block_id)
			printf("|\t %s  %s \t",player_one.name,player_two.name);
		else if (player_one.current_block_id == board[i+1].block_id)
			printf("|\t   %s    \t",player_one.name);
		else if (player_two.current_block_id == board[i+1].block_id)
			printf("|\t   %s    \t",player_two.name);	
		else
			printf("|\t          \t");

		i+=2;
		printf("|\n------------------------");

		if (j==3)
		{
			printf("------------------------------------------------------------------------------------------------");
		}
		else
			printf("\t\t\t\t\t\t\t\t\t\t\t\t");

		printf("------------------------");
		printf("\n");
	}
	//End name row
	for ( j = i; j < 20 ; ++j )
	{
		printf("|\t%5s    \t",board[j].name);
	}
	printf("|\n");
	//End price row
	for ( j = i; j < 20 ; ++j )
	{
		if (board[j].type == property)
			printf("|\t%5d$  \t",board[j].price);
		else if (board[j].type == tax)
			printf("|\t%5d$  \t",board[j].rent);
		else
			printf("|\t          \t");
	}
	printf("|\n");

	//This loop control the user location and print it
	for ( j = i; j < 20 ; ++j )
	{
		if (player_two.current_block_id == board[j].block_id && player_one.current_block_id == board[j].block_id)
			printf("|\t %s  %s \t",player_one.name,player_two.name);
		else if (player_one.current_block_id == board[j].block_id)
			printf("|\t   %s    \t",player_one.name);
		else if (player_two.current_block_id == board[j].block_id)
			printf("|\t   %s    \t",player_two.name);	
		else
			printf("|\t           \t");
	}
	printf("|\n");

	for ( i = 0; i < 6; ++i)
	{
		printf("------------------------");
	}
	printf("\n");

}

void show_properties(block_t board[20])
{
	int i,select;
	//This loop continue until the user enter zero
	do{

		printf("Please select a property to see details or Enter the '0':\n");
		//Propert List with block_id
		for (i = 0; i < 20; ++i)
		{
			if (board[i].type == property)
			{
				printf("-#- %d -\t%s\n",board[i].block_id,board[i].name );
			}
		}

		printf("Select : ");
		scanf("%d",&select);
		printf("\n");

		for (i = 0; i < 20; ++i)
		{
			if (board[i].block_id == select && board[i].type == property)
			{
				printf("---------------------------------\n");
				printf("|\t%10s\t\t|\n",board[i].name);
				printf("---------------------------------\n");
				printf("|\tRent\t\t%d$\t|\n",board[i].rent);
				printf("|\tRent 1 H    \t%d$\t|\n",board[i].rent_1);
				printf("|\tRent 2 H    \t%d$\t|\n",board[i].rent_2);
				printf("|\tRent 3 H    \t%d$\t|\n",board[i].rent_3);
				printf("---------------------------------\n");
				printf("|\tHouse Price \t%d$\t|\n",board[i].price);
				printf("---------------------------------\n");
			}
		}

		printf("\n\n");

	}while(select != 0);
}

void buy_property(block_t* current_block,player_t* current_player)
{
	int select,i;

	// I first set up the house buying rules

	if ( current_block->type != property)
		printf("This is not property.\n");
	
	
	else if ( !(current_block->block_id ==  current_player->current_block_id) )
		printf("You are not on this block.\n");
	
		
	else if (  !( current_player->account >= current_block->price ) )
		printf("You have not enough money for this property %s.\n",current_block->name);
	
	//If you do not have any obstacles to take property comes here.
	else
	{	
		do
		{
			printf("Do you want to buy %s ? (1-Yes , 2-No) -",current_block->name);
			scanf("%d",&select);
			printf("\n");

			if (select == 1)
			{

				current_player->account -= current_block->price;
				current_block->owner = current_player->type;

				for ( i = 0; current_player->owned_block_ids[i] != -1 ; ++i);

				current_player->owned_block_ids[i] = current_block->block_id;			

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
				build_house(current_block,current_player);
				break;
			}
		}
		
	}

}

void build_house(block_t* current_block,player_t* current_player)
{
	int select;
	
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
	else{

		do
		{
			if (select != 0)
			{
				printf("How many house do you want to build ? - 1,2,3. If you want to exit enter '0'. -");
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
			}

			if (current_block->house_count ==3)
			{
				printf("You have %d house. You can not buy anymore.\n",current_block->house_count);
				break;
			}

		}while(select != 0);
			
	}

}

void sell_property(block_t board[20],player_t* current_player)
{
	int select,i,j,temp,temp_two,number_of_house;
	
	//Control the your property,If you don't have property program will be end. Property number will be i.
	for (i = 0; current_player->owned_block_ids[i] != -1 ; ++i);

	if (i == 0)
		printf("\nYou don't have property ! ! !\n");

	else{

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
				//Detect the block of list number, it will be i.
				for (i = 0; board[i].block_id != select ; ++i);


					current_player->account = current_player->account + board[i].price/2 + (board[i].house_count*board[i].house_price)/2;
					board[i].owner = noone;	
					board[i].house_count=0;

					//Detect the list number of end elemnent.
					for (j = 0; current_player->owned_block_ids[j] != -1 ; ++j);
					//And copy the temp
					temp=j-1;
					//Detect the list number of block_id
					for (j = 0; current_player->owned_block_ids[j] != board[i].block_id ; ++j);
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

}


int control_block(block_t* current_block, player_t* current_player,block_t board[20] )
{
	int select,i;
	
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

	*/
	if (current_block->type == property)
	{
		if (current_block->owner == noone)
		{
			buy_property(current_block,current_player);
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
					build_house(current_block,current_player);
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
					printf("You payed the rent for %s, %d\n",current_block->name,current_block->rent_3);
					current_player->account -= current_block->rent_3;
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
					printf("You payed the rent for %s, %d\n",current_block->name,current_block->rent_2);
					current_player->account -= current_block->rent_2;
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
					printf("You payed the rent for %s, %d\n",current_block->name,current_block->rent_1);
					current_player->account -= current_block->rent_1;
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
					printf("You payed the rent for %s, %d\n",current_block->name,current_block->rent);
					current_player->account -= current_block->rent;
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

	if (current_block->type == punish)
	{
		printf("You are punished from monopoly ,%d tour \n",current_block->rent);
		current_player->turn_to_wait=current_block->rent;
		return 0;
	}

	else if (current_block->type == tax)
	{
	
		if (current_player->account >= current_block->rent)
		{
			printf("You payed the tax %s, %d\n",current_block->name,current_block->rent);
			current_player->account -= current_block->rent;
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



}

void gameplay(block_t board[20], player_t player_one, player_t player_two)
{	

	int i,j,select,temp,flag;
		
	show_board(board,player_one,player_two);
	printf("! ! ! GAME IS STARTING ! ! !\n");

	do
	{

		do
		{
			flag=1;
			if (player_one.turn_to_wait == 0)
			{
				for (j = 0; board[j].block_id != player_one.current_block_id; ++j);
				
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
						if(player_one.current_block_id+temp > 20){
							player_one.account += 10000;
							player_one.current_block_id += (temp-20);
						}
						else{
							player_one.current_block_id += temp;
						}

						for (i = 0; board[i].block_id != player_one.current_block_id; ++i);
						flag=control_block(&board[i],&player_one,board);
						show_board(board,player_one,player_two);
						break;
					case 2:
						printf("Account: %d\n",player_one.account );
						break;
					case 3:
						printf("Your properties : \n");
						for (i = 0; player_one.owned_block_ids[i] != -1 ; ++i)
						{
							for (j = 0; j < 20; ++j)
							{
								if (board[j].block_id == player_one.owned_block_ids[i])
								{
									printf("-%d - %s \n", player_one.owned_block_ids[i],board[j].name);
								}
							}
						}
						break;
					case 4:
						show_properties(board);
						break;
					case 5:
						buy_property(&board[j],&player_one);
						break;
					case 6:
						build_house(&board[j],&player_one);
						break;
					case 7:
						sell_property(board,&player_one);
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

				printf("\nPlayer two\n\n");
				printf("1 - Roll The Dice\n");
				printf("2 - Show My Account\n");
				printf("3 - Show My Properties\n");
				printf("4 - Show Property Deeds\n");
				printf("5 - Buy Property\n");
				printf("6 - Buy House\n");
				printf("7 - Sell Property\n");
				printf("Please select one option to continue : ");
				scanf("%d",&select);

				switch(select){
					case 1:
						temp=1+rand()%19;
						printf("Dice: %d\n",temp );
						if(player_two.current_block_id+temp > 20){
							player_two.account += 10000;
							player_two.current_block_id += (temp-20);
						}
						else{
							player_two.current_block_id += temp;
						}
						
						for (i = 0; board[i].block_id != player_two.current_block_id ; ++i);

						flag=control_block(&board[i],&player_two,board);
						show_board(board,player_one,player_two);
						break;
					case 2:
						printf("Account: %d\n",player_two.account );
						break;
					case 3:
						printf("Your properties : \n");
						for (i = 0; player_two.owned_block_ids[i] != -1 ; ++i)
						{
							for (j = 0; j < 20; ++j)
							{
								if (board[j].block_id == player_two.owned_block_ids[i])
								{
									printf("-%d - %s \n", player_two.owned_block_ids[i],board[j].name);
								}
							}
						}
						break;
					case 4:
						show_properties(board);
						break;
					case 5:
						buy_property(&board[i],&player_two);
						break;
					case 6:
						build_house(&board[i],&player_two);
						break;
					case 7:
						sell_property(board,&player_two);
						break;


				}		

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

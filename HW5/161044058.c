#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18

int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	
	return counter;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n') {
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}


int str_length(char *target);

void randomly_character(char array[DICT_SIZE][DICT_SIZE]);

void placing_the_words_on_map(char *dict[],int coord[DICT_SIZE][4],char puzzle[DICT_SIZE][DICT_SIZE]);

void print_the_puzzle(char puzzle[DICT_SIZE][DICT_SIZE]);

int str_comparison(char *input,char *target);

int control_the_map(char input[DICT_SIZE],char puzzle[DICT_SIZE][DICT_SIZE],int guess_x,int guess_y);



int main(){

	char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4];    
    char line[LINE_LEN];
    char puzzle[DICT_SIZE][DICT_SIZE];


    char input[15],length;
    char control[10]="exit";
    int x,y,temp;
    
    srand(time(NULL));

	FILE *fp = fopen("word_hunter.dat", "r");

	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	
	fclose(fp);
	print_dictionary(dict);
	print_coord(coord);
	printf("\n");

	// WRITE HERE...
	randomly_character(puzzle);
	placing_the_words_on_map(dict,coord,puzzle);
	print_the_puzzle(puzzle);
	do
	{
		temp=0;
		printf("\nEnter the word and coordinate(If you wanto to trying to get out, you must to write 'exit')\n");
		scanf("%s",input);

		if (str_comparison(input,control) == 1)
			break;


		scanf("%d %d",&x,&y);
		control_the_map(input,puzzle,x,y);
		print_the_puzzle(puzzle);	


		printf("\n");
	}
	while(1);



	return 0;
}


int str_length(char *target)
{
	int counter = 0;
	int i;
	//Go until you see new line or null char
	for(i = 0; target[i] != '\n' && target[i] != '\0' ; i++) {
		counter++; // increment counter
	}
	
	return counter;
}

void randomly_character(char array[DICT_SIZE][DICT_SIZE]){
	int i,j,n;
	//Firstly we will make a char list and we will choose the one word in the list. This will be random char map.
	char *letters = "abcdefghijklmnopqrstuvwxyz";
	int num_of_letters = str_length(letters);

	for (i = 0; i < DICT_SIZE; i++)
	{
		for(j = 0; j < DICT_SIZE; j++)
		{
			n = rand() % num_of_letters;
			array[i][j]=letters[n];
		}
		array[i][j]='\0';
	}
}



void placing_the_words_on_map(char *dict[],int coord[DICT_SIZE][4],char puzzle[DICT_SIZE][DICT_SIZE])
{

	int i,j;
	int character_counter;
	int x,y,temp_x,temp_y;


	//This cycle counts words
	for (i = 0; i < DICT_SIZE ; i++)
	{
		//The length of the word is measured
		j=str_length(dict[i])-1;

		//First and last coordinates are recorded
		temp_x=coord[i][0];
		temp_y=coord[i][1];
		x=coord[i][2];
		y=coord[i][3];
		//Repeats for the number of letters
		for (character_counter=0; character_counter < j ; character_counter++)
		{
			//Start with the first coordinate and place the letters in the puzzle until the last coordinate
			puzzle[temp_x][temp_y]=dict[i][character_counter];
			//The first coordinate is increased as long as the last coordinate is smaller.
			if(temp_x < x)
				temp_x++;
			if (temp_y < y)
				temp_y++;
			if(temp_x > x)
				temp_x--;
			if (temp_y > y)
				temp_y--;
		}
		
	}

}

//Prints the letters on each line.
void print_the_puzzle(char puzzle[DICT_SIZE][DICT_SIZE])
{

	for (int i = 0; i < DICT_SIZE; i++)
	{
		for (int j = 0; j < DICT_SIZE; j++)
		{
			printf("|%c",puzzle[i][j]);		
		}
		printf("|\n");
	}
}
//This function make a compare with two string.
int str_comparison(char *input,char *target)
{
   while (*input == *target) {
      input++;
      target++;
      if (*target == '\0' && *target == '\0')
         return 1;
   }

   return 0;
}

int control_the_map(char input[DICT_SIZE],char puzzle[DICT_SIZE][DICT_SIZE],int guess_x,int guess_y)
{
	int i=0,j,range;

	int x,y;
	int temp_x,temp_y;

	int coordinate[DICT_SIZE][2];

	// Function take the input length because the loop turn until the length of input.
	range=str_length(input);

			//This check provide to control the first later is it same or not 
			if (puzzle[guess_x][guess_y] == input[0] || puzzle[guess_x][guess_y] == input[range-1] )
			{
				coordinate[0][0]=guess_x;
				coordinate[0][1]=guess_y;
				//'i' counts input from beginning to end
				//'j' counts input from end to beginning
				for(i = 1, j=range-2; i < range ; i++, j--)
				{

					//Checks whether 'x' coordinate is the initial letter
					//Checks whether 'y' coordinate is the initial letter
					//Checks whether 'temp_x' coordinate is the last letter
					//Checks whether 'temp_y' coordinate is the last letter
					x=guess_x+i;
					y=guess_y;
					temp_x=guess_x-i;
					temp_y=guess_y;

					if ( (x < DICT_SIZE || temp_x > 0) && ( puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i] || puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j] ) )
					{
						//'coordinate[][]' array takes coordinate belong to input if this case (puzzle[temp_x][temp_y] == input[j] || puzzle[x][y] == input[i]) is true
						if (puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j])
						{
							coordinate[i][0]=temp_x;
							coordinate[i][1]=temp_y;
						}
						if (puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i])
						{
							coordinate[i][0]=x;
							coordinate[i][1]=y;
						}
						//If the word does not give any errors along the length of the letter we convert them to capitalization with the coordinate we collect.
						if ( i+1==range )
						{

							for (j = 0; j < range; j++)
							{
								if (puzzle[coordinate[j][0]][coordinate[j][1]]-32 > 64)
								{
									puzzle[coordinate[j][0]][coordinate[j][1]]-=32;
								}							}
							return 1;
						}
					}	
					else
						break;
				}

				for(i = 1, j=range-2; i < range ; i++, j--)
				{

					x=guess_x-i;
					y=guess_y;
					temp_x=guess_x+i;
					temp_y=guess_y;

					if ( (x > 0 || temp_x < DICT_SIZE) && ( y == temp_y) && ( puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i] || puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j] ) )
					{

						if (puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j])
						{
							coordinate[i][0]=temp_x;
							coordinate[i][1]=temp_y;
						}
						if (puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i])
						{
							coordinate[i][0]=x;
							coordinate[i][1]=y;
						}

						if ( i+1==range )
						{

							for (j = 0; j < range; j++)
							{
								if (puzzle[coordinate[j][0]][coordinate[j][1]]-32 > 64)
								{
									puzzle[coordinate[j][0]][coordinate[j][1]]-=32;
								}							}
							return 1;
						}
					}	
					else
						break;
				}

				for(i = 1, j=range-2; i < range ; i++, j--)
				{

					x=guess_x+i;
					y=guess_y+i;
					temp_x=guess_x-i;
					temp_y=guess_y-i;

					if ( (x < DICT_SIZE || temp_x > 0) && ( y < DICT_SIZE || temp_y > 0 ) && ( puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i] || puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j] ) )
					{

						if (puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j])
						{
							coordinate[i][0]=temp_x;
							coordinate[i][1]=temp_y;
						}
						if (puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i])
						{
							coordinate[i][0]=x;
							coordinate[i][1]=y;
						}

						if ( i+1==range )
						{

							for (j = 0; j < range; j++)
							{
								if (puzzle[coordinate[j][0]][coordinate[j][1]]-32 > 64)
								{
									puzzle[coordinate[j][0]][coordinate[j][1]]-=32;
								}							}
							return 1;
						}
					}	
					else
						break;
				}

				for(i = 1, j=range-2; i < range ; i++, j--)
				{

					x=guess_x-i;
					y=guess_y-i;
					temp_x=guess_x+i;
					temp_y=guess_y+i;

					if ( (x > 0 || temp_x < DICT_SIZE) && ( y > 0 || temp_y < DICT_SIZE) && ( puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i] || puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j] ) )
					{

						if (puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j])
						{
							coordinate[i][0]=temp_x;
							coordinate[i][1]=temp_y;
						}
						if (puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i])
						{
							coordinate[i][0]=x;
							coordinate[i][1]=y;
						}

						if ( i+1==range )
						{

							for (j = 0; j < range; j++)
							{
								if (puzzle[coordinate[j][0]][coordinate[j][1]]-32 > 64)
								{
									puzzle[coordinate[j][0]][coordinate[j][1]]-=32;
								}							}
							return 1;
						}
					}	
					else
						break;
				}

				for(i = 1, j=range-2; i < range ; i++, j--)
				{

					x=guess_x;
					y=guess_y+i;
					temp_x=guess_x;
					temp_y=guess_y-i;

					if ( ( x == temp_x ) && ( y < DICT_SIZE || temp_y > 0 ) && ( puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i] || puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j] ) )
					{

						if (puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j])
						{
							coordinate[i][0]=temp_x;
							coordinate[i][1]=temp_y;
						}
						if (puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i])
						{
							coordinate[i][0]=x;
							coordinate[i][1]=y;
						}

						if ( i+1==range )
						{

							for (j = 0; j < range; j++)
							{
								if (puzzle[coordinate[j][0]][coordinate[j][1]]-32 > 64)
								{
									puzzle[coordinate[j][0]][coordinate[j][1]]-=32;
								}							}
							return 1;
						}
					}	
					else
						break;
				}

				for(i = 1, j=range-2; i < range ; i++, j--)
				{

					x=guess_x;
					y=guess_y-i;
					temp_x=guess_x;
					temp_y=guess_y+i;

					if ( ( y > 0 || temp_y < DICT_SIZE ) && ( puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i] || puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j] ) )
					{

						if (puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j])
						{
							coordinate[i][0]=temp_x;
							coordinate[i][1]=temp_y;
						}
						if (puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i])
						{
							coordinate[i][0]=x;
							coordinate[i][1]=y;
						}

						if ( i+1==range )
						{

							for (j = 0; j < range; j++)
							{
								if (puzzle[coordinate[j][0]][coordinate[j][1]]-32 > 64)
								{
									puzzle[coordinate[j][0]][coordinate[j][1]]-=32;
								}							}
							return 1;
						}
					}	
					else
						break;
				}

				for(i = 1, j=range-2; i < range ; i++, j--)
				{

					x=guess_x+i;
					y=guess_y-i;
					temp_x=guess_x-i;
					temp_y=guess_y+i;

					if ( (x < DICT_SIZE || temp_x >0) && ( y > 0 || temp_y < DICT_SIZE ) && ( puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i] || puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j] ) )
					{

						if (puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j])
						{
							coordinate[i][0]=temp_x;
							coordinate[i][1]=temp_y;
						}
						if (puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i])
						{
							coordinate[i][0]=x;
							coordinate[i][1]=y;
						}

						if ( i+1==range )
						{

							for (j = 0; j < range; j++)
							{
								if (puzzle[coordinate[j][0]][coordinate[j][1]]-32 > 64)
								{
									puzzle[coordinate[j][0]][coordinate[j][1]]-=32;
								}							}
							return 1;
						}
					}	
					else
						break;
				}

				for(i = 1, j=range-2; i < range ; i++, j--)
				{

					x=guess_x-i;
					y=guess_y+i;
					temp_x=guess_x+i;
					temp_y=guess_y-i;

					if ( (x > 0 || temp_x < DICT_SIZE) && ( y < DICT_SIZE || temp_y > 0 ) && ( puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i] || puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j] ) )
					{

						if (puzzle[temp_x][temp_y] == input[j] || puzzle[temp_x][temp_y]+32 == input[j])
						{
							coordinate[i][0]=temp_x;
							coordinate[i][1]=temp_y;
						}
						if (puzzle[x][y] == input[i] || puzzle[x][y]+32 == input[i])
						{
							coordinate[i][0]=x;
							coordinate[i][1]=y;
						}

						if ( i+1==range )
						{

							for (j = 0; j < range; j++)
							{
								if (puzzle[coordinate[j][0]][coordinate[j][1]]-32 > 64)
								{
									puzzle[coordinate[j][0]][coordinate[j][1]]-=32;
								}
							}
							return 1;
						}
					}	
					else
						break;
				}

			}


			
}




#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
// Osman Talha Aydın - 161044058

/*
	Program's Mode of Study 

1-)Read a number from the file and send its value and location.

2-)Compare the current number from the received position with the new numbers read from the file.
When an equal number is found, number of counts added one..

3-)The number of counts in the file is kept in an array. It is then sorted by the amount of numbers. 
The last is written to the output file in order.

*/
void read_number_func();

int control_equation_func(int control_number,long int reading_state);


int main()
{
	read_number_func();
	return 0;
}


void read_number_func()
{
	// This function take a number in the file and pass its state and value to control_equation_func.
	// When the control equation function end, this function take a count of passed number. 
	// And Count of number save the counter array. And this values are sorted. After that this number 
	// and its counts save in the file.

	int number[SIZE],counter[SIZE];
	int temp_number,flag,temp;
	int i;
	int j=0;
	long int reading_state;
	FILE *fp;

	fp = fopen("input.txt","r");

	if (EOF != fscanf(fp,"%d",&temp_number))
	{
		number[j]=temp_number;
		reading_state = ftell(fp);
		counter[j] = control_equation_func(number[j],reading_state);
		j++;

		while(EOF!=fscanf(fp,"%d",&temp_number))
		{
			for (i = 0,flag=0; number[i] != '\0'; ++i)
			{
				if (temp_number == number[i])
				{
					flag = 1;
				}
			}

			if (flag == 0)
			{
				
				reading_state = ftell(fp);
				number[j]=temp_number;
				counter[j] = control_equation_func(number[j],reading_state);
				j++;
			}
		}
	}

	number[j] = '\0';

	fclose(fp);

	// S O R T 
	for (i = 0 ; number[i] != '\0' ; ++i)
	{
		for (j = i+1; number[j] != '\0' ; ++j)
		{
			if (counter[i] > counter[j])
			{
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;

				temp = counter[i];
				counter[i] = counter[j];
				counter[j] = temp;
			}
		}

	}
	// W R İ T E  NUMBERS AND ITS COUNTS
	fp = fopen("output.txt","w");

	for (i = 0; number[i] != '\0' ; ++i)
	{
		fprintf(fp,"%d:%d\n",number[i],counter[i] );
	}

	fclose(fp);

}

int control_equation_func(int control_number,long int reading_state)
{
	// This function take property of number. It starts to check the numbers after that taking 
	// its position (This position prevents the same number from being repeated). - LINE 58
	// This control aims to find the number equal to control_number. - LINE 65
	// If equal, the position and value of the number, counter will be added and return . - LINE 66

	int number,counter=1;
	FILE *fp;

	fp = fopen("input.txt","r");

	fseek(fp,reading_state,SEEK_SET);

	while( EOF != fscanf(fp,"%d",&number))
	{

		reading_state = ftell(fp);

		if (control_number == number)
			counter++;
	
	}

	fclose(fp);

	return counter;
}



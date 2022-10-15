#include <stdio.h>
#include <stdlib.h>


// Osman Talha Aydın - 161044058

/*
	Program's Mode of Study 

1-)Read a number from the file and send its value and location.

2-)Compare the current number from the received position with the new numbers read from the file.
When an equal number is found, Number of value and location send to other function.

3-)The number to be deleted is taken and the number of digits is found. 
This number of digits is subtracted from the number of position.
In this way, the position of the first digit of the number is found.
From this position, the number of spaces is printed.

*/
void read_number_func();

void control_equation_func(int control_number,long int reading_state);

void print_space_func(long int deleting_state,int deleting_number);




int main()
{
	read_number_func();
	return 0;
}


void read_number_func()
{
	// This function take a number in the file and pass its state and value to control_equation_func.- LINE 38 
	// When the control equation function end, 
	// this functiın will be read one number property and pass it again. - LINE 38

	int number;
	long int reading_state;
	FILE *fp;

	fp = fopen("file.txt","r");

	while( EOF != fscanf(fp,"%d",&number))
	{

		reading_state = ftell(fp);

		control_equation_func(number,reading_state);

	}

	fclose(fp);

}

void control_equation_func(int control_number,long int reading_state)
{
	// This function take property of number. It starts to check the numbers after that taking 
	// its position (This position prevents the same number from being repeated). - LINE 58
	// This control aims to find the number equal to control_number. - LINE 65
	// If equal, the position and value of the number found pass to the other function that is print_space_func. - LINE 66

	int number;
	FILE *fp;

	fp = fopen("file.txt","r");

	fseek(fp,reading_state,SEEK_SET);

	while( EOF != fscanf(fp,"%d",&number))
	{

		reading_state = ftell(fp);

		if (control_number == number)
			print_space_func(reading_state,number);
	
	}

	fclose(fp);

}



void print_space_func(long int deleting_state,int deleting_number)
{
	// This function subtracts the number of digits from the position in the last digit of the number 
	// it receives.It is therefore possible to delete the number from the position of the first digit.
	
	// This function has three property.
	// 1- Fix the number positive or negative - LINE 95(For negative number)/115(For positive number)
	// 2- Fix the number of digit - LINE 100,101(For negative number)/117(For positive number)
	// 3- Print space -  LINE  104-111(For negative number)/120-127(For positive number)



	int i;
	int digit = 1;
	int power_of_negative_ten = -10;
	int power_of_positive_ten = 10;
	char space = ' ';
	FILE *fp;

	if (deleting_number < 0)
	{
		// I increment the digit before the for loop because this is negative number so
		// negative number one digit more than positive therefore sign of minus.
		++digit;

		for( ; power_of_negative_ten > deleting_number ; power_of_negative_ten*=10, ++digit);
		

		fp = fopen("file.txt","r+");

		fseek(fp,deleting_state-digit,SEEK_SET);

		for(i = 0 ; i < digit ; ++i)
			fputs(" ",fp);
 	
		fclose(fp);

	}

	else if (deleting_number >= 0)
	{
		for( ; power_of_positive_ten < deleting_number ; power_of_positive_ten*=10, ++digit);


		fp = fopen("file.txt","r+");

		fseek(fp,deleting_state-digit,SEEK_SET);

		for(i = 0 ; i < digit ; ++i)
			fputs(" ",fp);

		fclose(fp);

	}





}

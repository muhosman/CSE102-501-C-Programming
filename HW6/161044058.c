#include <stdio.h>

int power(int x, unsigned n);

int common(int number1,int number2);

void merge_ranges(int A[], int TempArray[],int iBegin, int iMid, int iEnd);

void merge_sort(int A[], int TempArray[], int iBegin, int iEnd);

int F(int input);

int checking_the_input(int input,int digit_number);

char first_capital_letter(char *string);

int main(){

	int i,input;
	int number1,number2;
	int multiple = 10;
	char string[100],result;
	int number_of_list[100],temp_array[100];
	do
	{
		printf("Enter The Choice(If you want to exit you must to enter '-1')\n");
		printf("1-Common\n");
		printf("2-Merge Sort\n");
		printf("3-Function\n");
		printf("4-Checking the input\n");
		printf("5-First Capital letter\n");
		printf("(-1) Exit\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:

				printf("Enter two number: ");
				scanf("%d%d",&number1,&number2);
				printf("Common: %d\n\n",common(number1,number2));
				break;

			case 2:

				printf("Enter the length of the list: ");
				scanf("%d",&input);
				for (i = 0; i < input; ++i)
				{
					scanf("%d",&number_of_list[i]);
				}

				merge_sort(number_of_list,temp_array,0,input);

				printf("Sorted array is:");
				for (i = 0; i < input; ++i)
				{
					printf(" %d",number_of_list[i]);
				}
				printf("\n\n");
				break;

			case 3:

				printf("Input: ");
				scanf("%d",&input);
				F(input);
				printf("\n\n");
				break;

			case 4:

				printf("Input: ");
				scanf("%d",&input);

				for (i = 0,multiple=10; input % multiple!= input; i++,multiple*=10);

				if(input == checking_the_input(input,i+1))
					printf("Output: Equal\n\n");
				else
					printf("Output: Not Equal\n\n");

				break;

			case 5:
				printf("Input: ");
				scanf("%s",string);
				first_capital_letter(string);
				printf("\n\n");
				break;

			case -1:
				break;

			default:
				printf("Invalid choice ! ! !\n");
				break;

		}

	}while(i != -1);

	return 0;
}
// Naive iterative solution to calculate pow(x, n)
int power(int x, unsigned n)
{
	// initialize result by 1
	int pow = 1;

	// multiply x exactly n times
	for (int i = 0; i < n; i++)
		pow = pow*x;

	return pow;
}

int common(int number1,int number2)
{	
	if (number2 == 0)
		return number1;
	return common(number2,number1%number2);
}

void merge_ranges(int A[], int TempArray[],int iBegin, int iMid, int iEnd) 
{
    int i = iBegin;   // i will index first sub-range.
    int j = iMid;     // j will index second sub-range.
    int k = i;        // index into temporary array

    // While neither end point has been reached,
    //  Use A[i] < A[j] comparison to step through, always
    //  copying the lesser of the two indexed elements.
    while (i < iMid && j < iEnd) {
        if (A[i] < A[j])
            TempArray[k++] = A[i++];
        else
            TempArray[k++] = A[j++];
    }
    // Now, eat the "tail" remaining...
    while (i < iMid)
       TempArray[k++] = A[i++];
    while (j < iEnd)
       TempArray[k++] = A[j++];

    // Finally, copy back contents of temp. array.
    for (int i = iBegin; i < iEnd; i++)
        A[i] = TempArray[i];
}

void merge_sort(int A[], int TempArray[], int iBegin, int iEnd) 
{
    if (iEnd-iBegin < 2)  // If range is size 1, it is sorted!
        return;
    int iMid = (iBegin + iEnd) / 2;  // Calculate midpoint.
    // Recursively sort each half of range.
    merge_sort(A, TempArray, iBegin, iMid);
    merge_sort(A, TempArray, iMid, iEnd);
    // Now, merge these two sorted ranges.
    merge_ranges(A, TempArray, iBegin, iMid, iEnd);
}


int F(int input)
{
	printf("%d ",input);

	if (input == 1)
		return 0;

	else if(0 == input%2)
		return F( input/2 ) ;

	else if(1 == input%2)
		return F( (3*input)+1 ) ;


	return 0;
}

int checking_the_input(int input,int digit_number)
{
	int digit=0;

	digit=input%10;

	input/=10;

	if (input == 0)
		return power(digit,digit_number);	
	else
		return power(digit,digit_number)+checking_the_input(input,digit_number);



}
char first_capital_letter(char *string)
{
	//Until The function find the capital letter ,this code will be recursively repeat

	if (*string>='A' && *string<='Z')
	{
		printf("Output: %c",*string);
		return 0;
	}

	else if (*string== '\0')
	{
		return 0;
	}

	else
	{
		return first_capital_letter(++string);
	}

}
#include <stdio.h>



void recursive_output(char character,int dash,FILE *op)
{

	if(dash != 0)
	{
		fprintf(op, "%c",'-');
		recursive_output(character,--dash,op);
	}
	else
		fprintf(op,"%c\n",character);

}

void recursive_newick(int flag,char character,int dash,FILE *fp,FILE *op)
{
	int CONTROL=0;


	//FLag 1 Mean is that read character means not letter.
	if (flag == 1)
	{
		
		if ( EOF !=(character = fgetc(fp)) )
		{
			if(character == '(')
				dash++;
			if(character == ')')
				dash--;

			// This If means that character is letter
			if (character != '(' && character != ',' && character != ')')
				flag = 0;

			recursive_newick(flag,character,dash,fp,op);		

		}
	}

	//Flag 0 means that read character means letter
	//So this character print output.txt .
	else if (flag == 0)
	{
		recursive_output(character,dash,op);
		flag = 1;
		recursive_newick(flag,character,dash,fp,op);		
	}

}

int main()
{
	FILE *fp;
	FILE *op;

	fp = fopen("input.txt","r");
	op = fopen("output.txt","a");

	recursive_newick(1,-1,0,fp,op);

	fclose(fp);
	fclose(op);

	return 0;
}